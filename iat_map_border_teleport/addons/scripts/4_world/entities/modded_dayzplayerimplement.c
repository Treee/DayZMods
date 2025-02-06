modded class DayZPlayerImplement
{
	override void OnStepEvent(string pEventType, string pUserString, int pUserInt)
	{
		super.OnStepEvent(pEventType, pUserString, pUserInt);

		if (GetGame().IsDedicatedServer())
		{
			TryTeleportOutOfBoundsPlayer(m_StepCounter);
		}
	}

	void TryTeleportOutOfBoundsPlayer(int stepCounter);
};