// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Reduce ordinary illness stomach loss and retain the existing activation condition.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class VomitSymptom
{
	static const float IAT_ILLNESS_CONTENT_LOSS_MULTIPLIER = 0.3;

	override void SetParam(Param p)
	{
		Param1<float> amount = Param1<float>.Cast(p);
		if (amount && amount.param1 >= 0 && m_Player && !IsContaminationActive())
		{
			ModifiersManager modifiers = m_Player.GetModifiersManager();
			if (modifiers.IsModifierActive(eModifiers.MDF_CHOLERA) || modifiers.IsModifierActive(eModifiers.MDF_SALMONELLA))
			{
				// Do not mutate the shared CachedObjectsParams used by the caller.
				super.SetParam(new Param1<float>(amount.param1 * IAT_ILLNESS_CONTENT_LOSS_MULTIPLIER));
				return;
			}
		}
		super.SetParam(p);
	}

	override bool CanActivate()
	{
		if (super.CanActivate())
			return true;
		// IF the player is crouched (sitting) allow the vomit
		if (m_Manager.GetCurrentCommandID() == DayZPlayerConstants.STANCEMASK_CROUCH)
			return true;

		return false;
	}
};
