modded class PlayerBase
{
	// by default you cannot immediately interact with the teleport because it causes sync issues
	protected bool m_CanInteractWithExit = false;

	void PlayerBase()
	{
		RegisterNetSyncVariableBool("m_CanInteractWithExit");
	}
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();
		if (GetGame().IsDedicatedServer())
		{
			if (IAT_IsInMiningTunnel())
			{
				AllowPlayerToInteractWithExit();
			}
		}
		else
		{
			if (IsControlledPlayer())//true only on client for the controlled character
			{
				if (IAT_IsInMiningTunnel())
				{
					UpdateUndergroundVisualEffects(true);
				}
			}
		}

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
	bool IAT_IsInMiningTunnel()
	{
		vector from = GetPosition();
        vector to = GetPosition();
        set<Object> hit_object = new set<Object>;
        to[1] = to[1] - 0.5;
        vector contactPos;
        vector contactDir;
        int contactComponent;
        bool hit = DayZPhysics.RaycastRV( from, to, contactPos, contactDir, contactComponent, hit_object, NULL, this, false, false, ObjIntersectFire );
		if (hit && hit_object.Count() > 0)
        {
			// foreach object in contact
			IAT_MiningSegment_Colorbase miningSegment;
			foreach (Object contactObj : hit_object)
			{
				// if its a mining segment
				if (Class.CastTo(miningSegment, contactObj))
				{
					// if this segment is not an entrance
					if (!miningSegment.IsEntrance())
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	void UpdateUndergroundVisualEffects(bool isEntering = false)
	{
		UndergroundHandlerClient handler;
		if (Class.CastTo(handler, GetUndergroundHandler()))
		{
			if (isEntering)
			{
				handler.IAT_EnterUndergroundMines();
			}
			else
			{
				handler.IAT_ExitUndergroundMines();
			}
		}
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