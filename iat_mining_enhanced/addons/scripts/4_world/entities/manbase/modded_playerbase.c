modded class PlayerBase
{
	// by default you cannot immediately interact with the teleport because it causes sync issues
	protected bool m_CanInteractWithExit = false;

	void PlayerBase()
	{
		RegisterNetSyncVariableBool("m_CanInteractWithExit");
	}
	override void InitItemVariables()
	{
		super.InitItemVariables();
	}
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_ActionDescendIntoMine, InputActionMap);
		AddAction(IAT_ActionAscendOutOfMine, InputActionMap);
	}

	bool IAT_CanInteractWithMineExit()
	{
		return m_CanInteractWithExit;
	}
	void AllowPlayerToInteractWithExit()
	{
		int time = 1000 * 10; // 1000ms x 10 seconds
		bool repeat = false;
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SetInteractMineTrue, time, repeat);
	}

	void SetInteractMineTrue()
	{
		m_CanInteractWithExit = true;
		SetSynchDirty();
	}
	void SetInteractMineFalse()
	{
		m_CanInteractWithExit = false;
		SetSynchDirty();
	}
};