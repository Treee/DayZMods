modded class PlayerBase
{
	// helpful for bifurcating code paths for vanilla and my stuff
	bool IAT_IsWearingSplint()
	{
		IAT_LegCastApplied_Colorbase attachment;
		if (Class.CastTo(attachment, GetItemOnSlot("Splint_Right")))
		{
			return true;
		}
		return false;
	}

	// handle the broken leg forced prone for our leg cast.
	override void BrokenLegForceProne(bool forceOverride = false)
	{
		if (!IsInWater() && !IsSwimming() && !IsClimbingLadder() && !IsInVehicle() && !IsClimbing() && DayZPlayerUtils.PlayerCanChangeStance(this, DayZPlayerConstants.STANCEIDX_PRONE))
		{
			if (m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_PRONE && m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			{
				IAT_LegCastApplied_Colorbase attachment;
				if (Class.CastTo(attachment, GetItemOnSlot("Splint_Right")))
				{
					// some casts are meant to always stay on (for rp reasons)
					if (!attachment.IsPermanentFixture())
						attachment.Delete();
				}
			}
		}
		super.BrokenLegForceProne(forceOverride);
	}

	// stop leg healing if a permanenet cast is applied
	override void UpdateBrokenLegs(int stateId)
	{
		// if a permanent cast is applied, short circuit leg healing
		IAT_LegCastApplied_Colorbase attachment;
		if (Class.CastTo(attachment, GetItemOnSlot("Splint_Right")))
		{
			// some casts are meant to always stay on (for rp reasons)
			if (attachment.IsPermanentFixture())
				return;
		}

		super.UpdateBrokenLegs(stateId);
	}
};