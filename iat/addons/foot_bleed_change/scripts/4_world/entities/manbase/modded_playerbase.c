modded class PlayerBase
{
	override float GetFeetDamageMoveModifier()
	{
		float modifier;
		switch(m_MovementState.m_iMovement)
		{
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				modifier = 0.5;
				break
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				modifier = 0.125;
				break
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				modifier = 0;
				break
		}
		return modifier;
	}
};