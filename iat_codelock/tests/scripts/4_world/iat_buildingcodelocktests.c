#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// The offline harness has no Steam identity. This fixture supplies an access
// decision while retaining the real lock, building, door and inventory behavior.
class IAT_TestCodelock_Authorized extends IAT_Codelock_Basic
{
	override bool HasAccess(PlayerIdentity playerIdentity)
	{
		return true;
	}
}

class IAT_BuildingCodelockTest extends IAT_ScenarioCase
{
	protected BuildingBase m_House;
	protected PlayerBase m_Player;
	protected vector m_OriginalPosition;
	protected IAT_Codelock_Colorbase m_AuthorizedLock;
	protected IAT_Codelock_Colorbase m_DebugLock;
	protected bool m_PlayerMoved;
	protected int m_PrepareStage;
	protected int m_CleanupStarted;

	void IAT_BuildingCodelockTest()
	{
		m_Mod = "IAT_Codelock";
		m_Suite = "NasdaraBuildings";
		m_Name = "DoorTargetingAndAccess";
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

		if (m_PrepareStage == 1)
		{
			for (int closeIndex = 0; closeIndex < m_House.GetDoorCount(); closeIndex++)
				m_House.CloseDoor(closeIndex);
			m_PrepareStage = 2;
			return false;
		}
		if (m_PrepareStage == 2)
		{
			m_AuthorizedLock = IAT_Codelock_Colorbase.Cast(m_House.GetInventory().CreateAttachmentEx("IAT_TestCodelock_Authorized", InventorySlots.GetSlotIdFromString("Att_CodeLock1_Wood")));
			m_DebugLock = IAT_Codelock_Colorbase.Cast(m_House.GetInventory().CreateAttachmentEx("IAT_Codelock_DebugNoOwner", InventorySlots.GetSlotIdFromString("Att_CodeLock2_Wood")));
			IAT_Check(m_AuthorizedLock != null, "Authorized lock attached to first door");
			IAT_Check(m_DebugLock != null, "Debug lock attached to second door");
			if (m_AuthorizedLock)
			{
				m_AuthorizedLock.AssignLockTo("fixture-owner");
				m_AuthorizedLock.SetIsLocked(true);
			}
			if (m_DebugLock)
			{
				m_DebugLock.AssignLockTo("fixture-owner");
				m_DebugLock.SetIsLocked(true);
			}
			return true;
		}

		m_OriginalPosition = m_Player.GetPosition();
		m_House = BuildingBase.Cast(g_Game.CreateObjectEx("Land_House_1M2", m_OriginalPosition + "10 0 0", ECE_PLACE_ON_SURFACE));
		IAT_Check(m_House != null, "Nasdara house created");
		if (!m_House)
			return true;

		ConstructionBase construction = ConstructionBase.Cast(m_House.GetConstructionBasic());
		IAT_Check(construction != null, "House has rebuilding component");
		if (!construction)
			return true;

		construction.BuildPartServerEx(null, "door1_wood", -1);
		construction.BuildPartServerEx(null, "door2_wood", -1);
		m_PrepareStage = 1;
		return false;
	}

	protected int IAT_FindDoor(string slotName)
	{
		for (int doorIndex = 0; doorIndex < m_House.GetDoorCount(); doorIndex++)
		{
			AdditionalDoorInfo info = m_House.GetDoorInfo(doorIndex);
			if (info && info.m_RelatedInventorySlotNames && info.m_RelatedInventorySlotNames.Find(slotName) >= 0)
				return doorIndex;
		}
		return -1;
	}

	protected int IAT_FindComponent(int doorIndex)
	{
		for (int componentIndex = 0; componentIndex < 2048; componentIndex++)
		{
			if (m_House.GetDoorIndex(componentIndex) == doorIndex)
				return componentIndex;
		}
		return -1;
	}

	override bool Execute()
	{
		if (!m_House || !m_AuthorizedLock || !m_DebugLock)
			return true;

		int ownedDoor = IAT_FindDoor("Att_CodeLock1_Wood");
		int debugDoor = IAT_FindDoor("Att_CodeLock2_Wood");
		int ownedComponent = IAT_FindComponent(ownedDoor);
		int debugComponent = IAT_FindComponent(debugDoor);
		IAT_Check(ownedDoor >= 0 && debugDoor >= 0 && ownedComponent >= 0 && debugComponent >= 0, "Real door geometry components found");
		if (ownedComponent < 0 || debugComponent < 0)
			return true;

		vector ownedHit = m_House.GetDoorSoundPos(ownedDoor);
		vector debugHit = m_House.GetDoorSoundPos(debugDoor);
		ActionTarget ownedTarget = new ActionTarget(m_House, null, ownedComponent, ownedHit, 1.0);
		ActionTarget debugTarget = new ActionTarget(m_House, null, debugComponent, debugHit, 1.0);
		ActionTarget wallTarget = new ActionTarget(m_House, null, -1, debugHit, 1.0);
		ActionTarget lockTarget = new ActionTarget(m_DebugLock, m_House, -1, debugHit, 1.0);
		IAT_Check(MiscGameplayFunctions.IAT_GetTargetCodelock(ownedTarget) == m_AuthorizedLock, "First door resolves its own lock");
		IAT_Check(MiscGameplayFunctions.IAT_GetTargetCodelock(debugTarget) == m_DebugLock, "Second door resolves debug lock instead of first lock");
		IAT_Check(MiscGameplayFunctions.IAT_GetTargetCodelock(wallTarget) == null, "House body does not resolve any door lock");
		IAT_Check(MiscGameplayFunctions.IAT_GetTargetCodelock(lockTarget) == m_DebugLock, "Direct lock target resolves that lock");

		ActionBase interact = ActionManagerBase.GetAction(IAT_ActionInteractCodelock);
		ActionBase manage = ActionManagerBase.GetAction(IAT_ActionManageCodelock);
		ActionBase claim = ActionManagerBase.GetAction(IAT_ActionClaimCodelock);
		m_Player.SetPosition(debugHit + "0 0 0.5");
		m_PlayerMoved = true;
		CCTObject originCondition = new CCTObject(UAMaxDistances.DEFAULT);
		IAT_Check(!originCondition.Can(m_Player, debugTarget), "Fixture door is outside the building-origin interaction radius");
		IAT_Check(m_DebugLock.HasOwner() && m_DebugLock.IAT_IsLocked(), "Debug lock represents a locked door owned by someone else");
		IAT_Check(!m_DebugLock.HasAccess(m_Player.GetIdentity()), "Debug lock denies access with no admin tools loaded");
		IAT_Check(interact.Can(m_Player, debugTarget, null), "Targeting debug door offers passcode entry");
		m_Player.SetPosition(ownedHit + "0 0 0.5");
		IAT_Check(!interact.Can(m_Player, ownedTarget, null), "Authorized door does not offer passcode entry");
		m_Player.SetPosition(debugHit + "0 0 0.5");
		IAT_Check(!interact.Can(m_Player, wallTarget, null), "Targeting house body offers no passcode entry");
		IAT_Check(manage.m_ConditionTarget.Can(m_Player, debugTarget), "Manage uses distance to door hit instead of building origin");
		IAT_Check(claim.m_ConditionTarget.Can(m_Player, debugTarget), "Claim uses distance to door hit instead of building origin");
		m_Player.SetPosition(debugHit + "20 0 0");
		IAT_Check(!manage.m_ConditionTarget.Can(m_Player, debugTarget), "Manage rejects distant door hit");

		DoorManipulationParams params = new DoorManipulationParams();
		params.m_CheckIfLocked = true;
		params.m_Caller = m_Player;
		params.m_DoorIndex = ownedDoor;
		IAT_Check(m_House.CanDoorBeOpened(params), "Authorized access permits opening the first door");
		params.m_DoorIndex = debugDoor;
		IAT_Check(!m_House.CanDoorBeOpened(params), "Debug lock blocks opening its door without access");
		params.m_Caller = null;
		IAT_Check(!m_House.CanDoorBeOpened(params), "Locked door denies a missing caller");
		m_DebugLock.SetIsLocked(false);
		IAT_Check(m_House.CanDoorBeOpened(params), "Unlocking permits opening the debug door");
		m_House.LockDoor(debugDoor, true);
		IAT_Check(!m_House.CanDoorBeOpened(params), "Unlocked IAT lock preserves vanilla internal door lock");
		return true;
	}

	override bool Cleanup()
	{
		if (m_CleanupStarted == 0)
		{
			if (m_PlayerMoved && m_Player)
				m_Player.SetPosition(m_OriginalPosition);
			if (m_AuthorizedLock)
				g_Game.ObjectDelete(m_AuthorizedLock);
			if (m_DebugLock)
				g_Game.ObjectDelete(m_DebugLock);
			if (m_House)
				g_Game.ObjectDelete(m_House);
			m_CleanupStarted = g_Game.GetTime();
			return false;
		}
		if (g_Game.GetTime() - m_CleanupStarted < 1000)
			return false;
		IAT_Check(!m_House && !m_AuthorizedLock && !m_DebugLock, "House and attached locks removed");
		return true;
	}
}

class IAT_BuildingLockConflictTest extends IAT_ScenarioCase
{
	protected bool m_KeypadFirst;
	protected BuildingBase m_House;
	protected IAT_Codelock_Colorbase m_First;
	protected IAT_Codelock_Colorbase m_Second;
	protected int m_PrepareStage;
	protected int m_CleanupStarted;

	void IAT_BuildingLockConflictTest(bool keypadFirst, string testName)
	{
		m_Mod = "IAT_Codelock";
		m_Suite = "NasdaraBuildings";
		m_Name = testName;
		m_KeypadFirst = keypadFirst;
	}

	protected void IAT_Check(bool passed, string description)
	{
		Check(passed, description, "true", passed.ToString());
	}

	override bool Prepare()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
			return false;
		if (m_PrepareStage == 0)
		{
			m_House = BuildingBase.Cast(g_Game.CreateObjectEx("Land_House_1M1", player.GetPosition() + "10 0 10", ECE_PLACE_ON_SURFACE));
			IAT_Check(m_House != null, "House created");
			if (!m_House)
				return true;
			ConstructionBase.Cast(m_House.GetConstructionBasic()).BuildPartServerEx(null, "door1_wood", -1);
			m_PrepareStage = 1;
			return false;
		}
		if (m_PrepareStage == 1)
		{
			for (int i = 0; i < m_House.GetDoorCount(); i++)
				m_House.CloseDoor(i);
			m_PrepareStage = 2;
			return false;
		}
		string firstType = "IAT_Codelock_Basic";
		string firstSlot = "Att_CodeLock1_Wood";
		string secondType = "IAT_Codelock_CombinationLock3";
		if (!m_KeypadFirst)
		{
			firstType = "IAT_Codelock_CombinationLock3";
			firstSlot = "Att_CombinationLock1_Wood";
			secondType = "IAT_Codelock_Basic";
		}
		m_First = IAT_Codelock_Colorbase.Cast(m_House.GetInventory().CreateAttachmentEx(firstType, InventorySlots.GetSlotIdFromString(firstSlot)));
		m_Second = IAT_Codelock_Colorbase.Cast(g_Game.CreateObjectEx(secondType, player.GetPosition(), ECE_PLACE_ON_SURFACE));
		IAT_Check(m_First && m_Second, "Lock fixtures created");
		return true;
	}

	override bool Execute()
	{
		if (!m_First || !m_Second)
			return true;
		string firstSlot = "Att_CodeLock1_Wood";
		string secondSlot = "Att_CombinationLock1_Wood";
		if (!m_KeypadFirst)
		{
			firstSlot = "Att_CombinationLock1_Wood";
			secondSlot = "Att_CodeLock1_Wood";
		}
		int firstId = InventorySlots.GetSlotIdFromString(firstSlot);
		int secondId = InventorySlots.GetSlotIdFromString(secondSlot);
		IAT_Check(m_Second.IsExternalLockType(), "IAT lock participates in external-lock rules");
		bool canAttach = m_House.GetInventory().CanAddAttachmentEx(m_Second, secondId);
		Check(!canAttach, "Second lock type rejected on the same door", "false", canAttach.ToString());
		IAT_Check(m_House.CanDisplayAttachmentSlot(firstId), "Occupied lock slot remains visible");
		bool conflictingSlotVisible = m_House.CanDisplayAttachmentSlot(secondId);
		Check(!conflictingSlotVisible, "Conflicting empty slot is hidden", "false", conflictingSlotVisible.ToString());
		EntityAI duplicate = m_House.GetInventory().CreateAttachmentEx(m_Second.GetType(), secondId);
		IAT_Check(duplicate == null, "Direct attachment creation rejects the second lock");
		if (duplicate)
			g_Game.ObjectDelete(duplicate);
		m_First.SetIsLocked(true);
		bool canDetachLocked = m_First.CanDetachAttachment(m_House);
		Check(!canDetachLocked, "Locked IAT lock cannot detach", "false", canDetachLocked.ToString());
		m_First.SetIsLocked(false);
		IAT_Check(m_First.CanDetachAttachment(m_House), "Unlocked IAT lock can detach");
		return true;
	}

	override bool Cleanup()
	{
		if (m_CleanupStarted == 0)
		{
			if (m_First)
				g_Game.ObjectDelete(m_First);
			if (m_Second)
				g_Game.ObjectDelete(m_Second);
			if (m_House)
				g_Game.ObjectDelete(m_House);
			m_CleanupStarted = g_Game.GetTime();
			return false;
		}
		if (g_Game.GetTime() - m_CleanupStarted < 1000)
			return false;
		IAT_Check(!m_House && !m_First && !m_Second, "All fixtures removed");
		return true;
	}
}

modded class IAT_ScenarioRegistry
{
	void IAT_ScenarioRegistry()
	{
		m_Cases.Insert(new IAT_BuildingCodelockTest());
		m_Cases.Insert(new IAT_BuildingLockConflictTest(true, "KeypadPreventsCombinationLock"));
		m_Cases.Insert(new IAT_BuildingLockConflictTest(false, "CombinationLockPreventsKeypad"));
	}
}
#endif
#endif
