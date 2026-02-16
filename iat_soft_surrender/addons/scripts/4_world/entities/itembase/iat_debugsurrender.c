// I need an item to test the surrender state on AI so here we are
class IAT_DebugSurrender: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionForceTargetSurrender);
	}

	override void OnApply(PlayerBase player)
	{
		Print("inject player");
		if (!player)
		{
			Print("no player; early return");
			return;
		}
		if (!player.GetEmoteManager())
		{
			// ai?
			Print("no emote manager; early return");
			return
		}

		// if the player can actually do the emote
		if (player.GetEmoteManager().CanPlayEmote(EmoteConstants.ID_EMOTE_SURRENDER))
		{
			// if there is no emote already playing
			if (!player.GetEmoteManager().IsEmotePlaying())
			{
				player.GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_SURRENDER);
			}
		}
		// bool can = player.GetEmoteManager().CanPlayEmote(EmoteConstants.ID_EMOTE_SURRENDER) && !player.GetEmoteManager().IsEmotePlaying();

		// if( player.GetModifiersManager().IsModifierActive(eModifiers.MDF_MORPHINE ) )//effectively resets the timer
		// {
		// 	player.GetModifiersManager().DeactivateModifier( eModifiers.MDF_MORPHINE );
		// }
		// player.GetModifiersManager().ActivateModifier( eModifiers.MDF_MORPHINE );
	}
};