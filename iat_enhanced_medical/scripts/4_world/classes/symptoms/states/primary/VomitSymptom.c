// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Preserve the existing additional symptom activation condition.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class VomitSymptom
{
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
