modded class PlayerBase
{
	// handle our leg cast "splint"
	override bool IsWearingSplint()
	{
		// if we are wearing our leg cast
		IAT_LegCastApplied_Colorbase attachment;
		if (Class.CastTo(attachment, GetItemOnSlot("Splint_Right")))
		{
			return true;
		}
		// otherwise return whatever would have been called
		return super.IsWearingSplint();
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