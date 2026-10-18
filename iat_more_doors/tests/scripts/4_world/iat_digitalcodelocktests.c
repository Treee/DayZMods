#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_MoreDoorsDigitalLockTest : IAT_ScenarioCase
{
	protected string m_DoorType;
	protected bool m_BatteryFirst;
	protected IAT_ConstructionDoor_Colorbase m_Door;
	protected DigitalCodeLock m_Lock;
	protected PlayerBase m_Player;
	protected vector m_OriginalPosition;
	protected bool m_PlayerMoved;

	void IAT_MoreDoorsDigitalLockTest(string doorType, bool batteryFirst, string testName)
	{
		m_Mod = "IAT_MoreDoors";
		m_Suite = "DigitalCodeLock";
		m_Name = testName;
		m_DoorType = doorType;
		m_BatteryFirst = batteryFirst;
	}

	protected void IAT_Check(bool passed, string description)
	{
		Check(passed, description, "true", passed.ToString());
	}

	override bool Prepare()
	{
		m_Player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!m_Player)
			return false;

		m_OriginalPosition = m_Player.GetPosition();
		m_Door = IAT_ConstructionDoor_Colorbase.Cast(g_Game.CreateObjectEx(m_DoorType, m_OriginalPosition + "2 0 0", ECE_PLACE_ON_SURFACE));
		IAT_Check(m_Door != null, "Door created");
		if (!m_Door)
			return true;

		if (m_BatteryFirst)
		{
			m_Lock = DigitalCodeLock.Cast(g_Game.CreateObjectEx("DigitalCodeLock", m_Door.GetPosition(), ECE_PLACE_ON_SURFACE));
			if (m_Lock)
			{
				m_Lock.GetInventory().CreateAttachment("Battery9V");
				m_Door.GetInventory().TakeEntityAsTargetAttachment(InventoryMode.LOCAL, m_Door, m_Lock);
			}
		}
		else
		{
			m_Lock = DigitalCodeLock.Cast(m_Door.GetInventory().CreateAttachment("DigitalCodeLock"));
			if (m_Lock)
				m_Lock.GetInventory().CreateAttachment("Battery9V");
		}
		IAT_Check(m_Lock != null, "Digital lock created");
		if (m_Lock)
			IAT_Check(m_Door.IAT_GetDigitalCodeLock() == m_Lock, "Lock attached to door");
		return true;
	}

	override bool Execute()
	{
		IAT_Check(m_Lock.HasValidParent(), "Custom door recognized as lock parent");
		IAT_Check(m_Lock.HasEnergy(), "Battery powers attached lock");
		IAT_Check(!m_Door.IsLocked(null), "Unconfigured lock allows opening");
		IAT_Check(!m_Door.CanDismantleDoor(), "Attached digital lock prevents dismantling");

		vector center = m_Lock.ModelToWorld(m_Lock.GetMemoryPointPos(DigitalCodeLock.MEMPOINT_CENTER));
		vector inside = m_Lock.ModelToWorld(m_Lock.GetMemoryPointPos(DigitalCodeLock.MEMPOINT_INSIDE));
		vector direction = vector.Direction(center, inside);
		vector front = center - direction;
		front[1] = m_OriginalPosition[1];
		vector back = center + direction;
		back[1] = m_OriginalPosition[1];
		m_Player.SetPosition(front);
		m_PlayerMoved = true;
		IAT_Check(!m_Lock.IsPlayerOnBackside(m_Player), "Player faces keypad side");

		ActionTarget lockTarget = new ActionTarget(m_Lock, m_Door, -1, center, 1.0);
		ActionTarget doorTarget = new ActionTarget(m_Door, null, -1, center, 1.0);
		ActionBase vanillaInteract = ActionManagerBase.GetAction(ActionInteractCodeLockItem);
		ActionBase vanillaReset = ActionManagerBase.GetAction(ActionResetCodeOnCodeLock);
		ActionBase interact = ActionManagerBase.GetAction(IAT_ActionInteractDoorCodeLock);
		ActionBase reset = ActionManagerBase.GetAction(IAT_ActionResetDoorCodeLock);
		IAT_Check(interact && reset, "IAT door actions registered globally");
		if (!interact || !reset)
			return true;

		array<ActionBase_Basic> doorActions;
		m_Door.GetActions(InteractActionInput, doorActions);
		IAT_Check(doorActions && doorActions.Find(interact) >= 0, "Door explicitly registers its lock interaction");
		IAT_Check(doorActions && doorActions.Find(reset) >= 0, "Door explicitly registers its PIN reset");
		IAT_Check(vanillaInteract.Can(m_Player, lockTarget, null), "Vanilla action still handles direct lock targeting");
		IAT_Check(!vanillaInteract.Can(m_Player, doorTarget, null), "Vanilla interaction does not accept the door");
		IAT_Check(!vanillaReset.Can(m_Player, doorTarget, null), "Vanilla reset does not accept the door");
		IAT_Check(!interact.Can(m_Player, lockTarget, null), "IAT door action does not duplicate a direct lock prompt");
		IAT_Check(interact.Can(m_Player, doorTarget, null), "Looking at the door offers set PIN");
		IAT_SetupDoorAction(interact, doorTarget, IAT_DoorCodeLockOperation.SET_CODE);
		IAT_Check(!reset.Can(m_Player, doorTarget, null), "No reset before a PIN exists");

		m_Player.SetPosition(back);
		IAT_Check(m_Lock.IsPlayerOnBackside(m_Player), "Player faces physical release side");
		IAT_Check(!interact.Can(m_Player, doorTarget, null), "Initial PIN cannot be set from the back side");
		m_Player.SetPosition(front);
		m_Lock.GetCodeLockComponent().SetLockCode("1234");
		IAT_Check(m_Door.IsLocked(null), "Configured digital lock secures door");
		IAT_Check(!m_Door.CanOpenDoor(null, "door1"), "Locked first leaf cannot open");
		if (m_Door.IsDoubleDoor())
			IAT_Check(!m_Door.CanOpenDoor(null, "door2"), "Locked second leaf cannot open");
		IAT_Check(interact.Can(m_Player, doorTarget, null), "Looking at the locked door offers enter PIN");
		IAT_SetupDoorAction(interact, doorTarget, IAT_DoorCodeLockOperation.ENTER_CODE);
		IAT_Check(!reset.Can(m_Player, doorTarget, null), "Door action cannot reset a locked PIN");

		// Public animation dispatch exercises the callbacks without a test-only production API.
		m_Player.SetPosition(back);
		IAT_DoorCodeLockActionData rejectedRelease = IAT_SetupDoorAction(interact, doorTarget, IAT_DoorCodeLockOperation.UNLOCK);
		m_Player.SetPosition(front);
		IAT_DispatchAction(interact, rejectedRelease);
		IAT_Check(m_Lock.IsLocked(), "Server rejects rear release after player moves to the front");
		m_Player.SetPosition(back);
		IAT_DoorCodeLockActionData release = IAT_SetupDoorAction(interact, doorTarget, IAT_DoorCodeLockOperation.UNLOCK);
		IAT_DispatchAction(interact, release);
		IAT_Check(!m_Lock.IsLocked(), "Physical rear release unlocks the attached lock");
		IAT_Check(!reset.Can(m_Player, doorTarget, null), "PIN reset remains unavailable from the rear");

		m_Player.SetPosition(front);
		IAT_Check(m_Door.CanOpenDoor(null, "door1"), "Unlocked door can open");
		IAT_Check(reset.Can(m_Player, doorTarget, null), "Looking at the unlocked door offers reset PIN");
		IAT_SetupDoorAction(reset, doorTarget, IAT_DoorCodeLockOperation.RESET_CODE);
		IAT_DoorCodeLockActionData lock = IAT_SetupDoorAction(interact, doorTarget, IAT_DoorCodeLockOperation.LOCK);
		IAT_DispatchAction(interact, lock);
		IAT_Check(m_Lock.IsLocked(), "Door action locks the attached lock on the server");
		m_Lock.SetLockState(false);
		m_Lock.ResetPIN();
		IAT_Check(interact.Can(m_Player, doorTarget, null), "Replacement PIN condition available");
		m_Lock.GetCompEM().SwitchOff();
		IAT_Check(!interact.Can(m_Player, doorTarget, null), "Unpowered lock rejects door interaction");
		IAT_Check(!reset.Can(m_Player, doorTarget, null), "Unpowered lock rejects door PIN reset");
		g_Game.ObjectDelete(m_Lock);
		IAT_Check(!interact.Can(m_Player, doorTarget, null), "Door without a lock has no lock interaction");
		IAT_Check(!reset.Can(m_Player, doorTarget, null), "Door without a lock has no PIN reset");
		return true;
	}

	protected IAT_DoorCodeLockActionData IAT_SetupDoorAction(ActionBase action, ActionTarget target, int expectedOperation)
	{
		ActionData data;
		bool setup = action.SetupAction(m_Player, target, null, data);
		IAT_Check(setup, "Door action setup succeeds");
		if (!data)
			return null;

		IAT_DoorCodeLockActionData lockData = IAT_DoorCodeLockActionData.Cast(data);
		IAT_Check(data.m_Target == target && data.m_Target.GetObject() == m_Door, "Setup keeps the door as the action target");
		IAT_Check(lockData && lockData.m_IAT_Lock == m_Lock, "Setup captures the attached lock");
		IAT_Check(lockData && lockData.m_IAT_Operation == expectedOperation, "Setup captures the expected operation");
		action.ClearInventoryReservationEx(data);
		if (!setup)
			return null;

		return lockData;
	}

	protected void IAT_DispatchAction(ActionBase action, IAT_DoorCodeLockActionData data)
	{
		if (!data)
			return;

		AnimatedActionBase animated = AnimatedActionBase.Cast(action);
		data.m_DelayedAnimationEventID = UA_ANIM_EVENT;
		animated.OnAnimationEvent(data);
	}
	override bool Cleanup()
	{
		if (m_PlayerMoved && m_Player)
			m_Player.SetPosition(m_OriginalPosition);
		if (m_Lock)
			g_Game.ObjectDelete(m_Lock);
		if (m_Door)
			g_Game.ObjectDelete(m_Door);
		IAT_Check(!m_Lock && !m_Door, "Door and lock fixtures removed");
		return true;
	}
}

modded class IAT_ScenarioRegistry
{
	void IAT_ScenarioRegistry()
	{
		m_Cases.Insert(new IAT_MoreDoorsDigitalLockTest("IAT_ConstructionDoor_Single_Left_Wooden", false, "SingleDoorBatteryAfterAttachment"));
		m_Cases.Insert(new IAT_MoreDoorsDigitalLockTest("IAT_ConstructionDoor_Single_Left_Wooden", true, "SingleDoorBatteryBeforeAttachment"));
		m_Cases.Insert(new IAT_MoreDoorsDigitalLockTest("IAT_ConstructionDoor_Double_Wooden", false, "DoubleDoorBatteryAfterAttachment"));
		m_Cases.Insert(new IAT_MoreDoorsDigitalLockTest("IAT_ConstructionDoor_Double_Wooden", true, "DoubleDoorBatteryBeforeAttachment"));
	}
}
#endif
#endif