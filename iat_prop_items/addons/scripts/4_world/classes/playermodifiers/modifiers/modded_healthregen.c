modded class HealthRegenMdfr
{
	override void OnTick(PlayerBase player, float deltaT)
	{
		// do vanilla logic
		super.OnTick(player, deltaT);

		//get our special splint
		IAT_LegCastApplied_Colorbase attachment;
		if (Class.CastTo(attachment, player.GetItemOnSlot("Splint_Right")))
		{
			// if its a permanenet fixture, reapply the damage to legs
			if (attachment.IsPermanentFixture())
			{
				player.AddHealth("RightLeg","Health", -PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("RightFoot","Health",-PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftLeg","Health", -PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftFoot","Health", -PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
			}
			else // otherwise double healing speed
			{
				player.AddHealth("RightLeg","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("RightFoot","Health",PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftLeg","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftFoot","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
			}
		}
	}
};