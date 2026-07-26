modded class DayZPlayerImplement
{
	override void OnStepEvent(string pEventType, string pUserString, int pUserInt)
	{
		super.OnStepEvent(pEventType, pUserString, pUserInt);

		if (g_Game.IsDedicatedServer()) // Handle server side state
		{
			IAT_MBT_TryTeleportOutOfBoundsPlayer(m_StepCounter);
		}
		else // Handle client side stuff
		{
			IAT_MBT_TryVisualEffects();
		}
	}

	void IAT_MBT_TryTeleportOutOfBoundsPlayer(int stepCounter);
	void IAT_MBT_TryVisualEffects();
};