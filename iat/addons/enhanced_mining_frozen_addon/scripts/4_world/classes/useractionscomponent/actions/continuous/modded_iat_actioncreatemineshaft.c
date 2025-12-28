modded class IAT_ActionCreateMineShaft
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.IsPlacingLocal())
			return false;

		if (!IsTargetDiggable(target))
			return false;

		if (!IsPlayerOnGround(player))
			return false;

		// check to see if the cursor is in a good spot for an entrance (center of an 8x8 grid)
		vector cursor = target.GetCursorHitPos();
		cursor[0] = Math.Round(cursor[0]);
		cursor[2] = Math.Round(cursor[2]);
		if (Math.ModFloat(cursor[0], 8) == 4 && Math.ModFloat(cursor[2], 8) == 4)
		{
			// PrintFormat("cursor is in a good spot: %1", cursor);
			return true;
		}
		// Print("cursor is not in a good position to spawn");
		return false;
	}

	bool IsTargetDiggable(ActionTarget target)
	{
		if (target)
		{
			string surface_type;
			vector position;
			position = target.GetCursorHitPos();

			g_Game.SurfaceGetType(position[0], position[2], surface_type);

			if (g_Game.IsSurfaceDigable(surface_type))
			{
				return true;
			}
		}
		return false;
	}
};