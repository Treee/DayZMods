modded class MiscGameplayFunctions
{
	static void IAT_RemoveSplint( PlayerBase player )
	{
		//Remove splint if target is wearing one
		IAT_LegCastApplied_Colorbase attachment;
		if (Class.CastTo(attachment, player.GetItemOnSlot("Splint_Right")))
		{
			attachment.DeleteSafe();
		}
	}
};