modded class MissionServer
{
	void MissionServer()
	{
		IAT_MiningConfig miningConfig = GetDayZGame().GetIATMiningConfig();
		GetDayZGame().SetIATMiningConfig(miningConfig);
		InitializeMiningTunnelSystem(miningConfig);
	}

	void InitializeMiningTunnelSystem(IAT_MiningConfig miningConfig)
	{
		IAT_MiningSegment_Colorbase m_MiningSegment;
		string segmentClassName = "";
		vector teleportDestination = vector.Zero;

		array<ref IAT_MiningSegmentConfig> miningSegments = miningConfig.GetMiningSegments();
		foreach(IAT_MiningSegmentConfig miningSegmentConfig : miningSegments)
		{
			if (miningSegmentConfig.IsEntrance())
				segmentClassName = "land_iat_miningsegment_entrance";
			else
				segmentClassName = "land_iat_miningsegment_junction";

			// create a junction at the location underneath the action target
			if (Class.CastTo(m_MiningSegment, GetGame().CreateObjectEx(segmentClassName, miningSegmentConfig.GetSegmentPosition(), ECE_SETUP|ECE_CREATEPHYSICS|ECE_KEEPHEIGHT)))
			{
				string selectionName = "";
				TIntArray doorStates = miningSegmentConfig.GetMineableComponentDoorStates();
				// foreach door (includes wall supports)
				foreach (int doorIndex, int doorState : doorStates)
				{
					// open
					if (doorState == 1)
					{
						m_MiningSegment.OpenDoor(doorIndex);
					}
					// locked
					else if (doorState == 2)
					{
						m_MiningSegment.LockDoor(doorIndex, true);
					}
					else
					{
						// by default close the door
						m_MiningSegment.CloseDoor(doorIndex);
					}
				}
				// set the id so the object can find itself in the config json
				m_MiningSegment.SetFormattedPersistentID(miningSegmentConfig.GetID());
				// set the exit junctions (entrances are always enterable)
				m_MiningSegment.SetIsExit(miningSegmentConfig.IsExit());
				// sync the exits to the client side
				m_MiningSegment.SetSynchDirty();
			}

		}
	}
	override void OnMissionFinish()
	{
		GetDayZGame().GetIATMiningConfig().SaveConfig();
		super.OnMissionFinish();
	}

	// no current need to send to client atm
	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	auto configParams = new Param1<IAT_MiningConfig>(GetDayZGame().GetIATMiningConfig());
	// 	PrintFormat("Sending IAT_Codelock Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG);
	// 	GetGame().RPCSingleParam(player, IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG, configParams, true, identity);
	// }
};