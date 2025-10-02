modded class PlayerBase
{
	override float GetFeetDamageMoveModifier()
	{
		#ifdef AdmiralsCyberneticMod
		// i would use WearingCyberneticLegs from admirals mod but given it is defined
		// within playerbase i do not have access to it in my mods
		ADM_Cybernetic_Base cybernetic;
		// cyborgs get no feet damage
		if(Class.CastTo(cybernetic,GetItemOnSlot("PlayerSlot1")) && cybernetic.IsCyberLegs())
		{
			return 0;
		}
		else if(Class.CastTo(cybernetic,GetItemOnSlot("PlayerSlot2")) && cybernetic.IsCyberLegs())
		{
			return 0;
		}
		#endif

		// eventually look at the surface and modify how bleeds should be applied
		// string surface;	int liquid;
		// GetGame().SurfaceUnderObject(this, surface, liquid);


		float modifier;
		switch(m_MovementState.m_iMovement)
		{
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				modifier = 0.75;
				break
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				modifier = 0.40;
				break
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				modifier = 0;
				break
		}
		return modifier;
	}
};