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