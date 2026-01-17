modded class ActionUnpackGift
{
    override void OnFinishProgressServer( ActionData action_data )
    {
        super.OnFinishProgressServer(action_data);

		// if the unpacked giftbox is our treasure hunt box
		GiftBox_IAT_TreasureHunt giftBox;
		if (!Class.CastTo(giftBox, action_data.m_MainItem))
		{
			return;
		}
		// if the treasure hunt config is even present
		IAT_TreasureHuntConfig treasureConfig;
		if (!Class.CastTo(treasureConfig, GetDayZGame().GetIATTreasureHuntConfig()))
		{
			return;
		}
		// if the treasure hunts are enabled
		if (!treasureConfig.IsEnabled())
		{
			return;
		}
		// get a random treasure location
		IAT_TreasureHuntLocation treasureLocation;
		if (Class.CastTo(treasureLocation, treasureConfig.GetRandomTreasureLocation()))
		{
			vector stashLocation = treasureLocation.GetRandomUniformPointInArea();
			// get the tier of this location
			IAT_TreasureHuntTier treasureTier;
			if (!Class.CastTo(treasureTier, treasureConfig.GetTreasureTierFromLocation(treasureLocation.GetTier())))
			{
				return;
			}

			// bury the treasure in the ground at the location we care about
			if (IAT_BuryTreasure(treasureLocation, treasureTier, stashLocation))
			{
				// create a written note on the ground
				ItemBase paper;
				if (Class.CastTo(paper, g_Game.CreateObjectEx("Paper", action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY|ECE_PLACE_ON_SURFACE)))
				{
					// initialize the note info on the paper
					paper.GetWrittenNoteData().InitNoteInfo(null, paper);
					// set the note text
					paper.GetWrittenNoteData().SetNoteText(treasureLocation.GetTreasureLocationText());
					// wear down the paper a bit so it looks ruined
					paper.SetHealthLevel(GameConstants.STATE_BADLY_DAMAGED);
					// notify the player of something important happening
					NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Treasure Hunt", "A worn and torn piece of paper falls to the ground.", "set:ccgui_enforce image:Icon40Emergency");
				}
			}
			else
			{
				// notify the player something went wrong to report to their server owner
				NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Treasure Hunt", "Something has gone wrong, screenshot this for your server owner and have them check the script logs for [IAT_BuryTreasure] output.", "set:ccgui_enforce image:Icon40Emergency");
			}
		}
    }

    bool IAT_BuryTreasure(IAT_TreasureHuntLocation treasureLocation, IAT_TreasureHuntTier treasureTier, vector stashLocation)
    {
        EntityAI containerToBury;
        if (Class.CastTo(containerToBury, g_Game.CreateObjectEx(treasureTier.GetRandomBuriableContainer(), stashLocation, ECE_PLACE_ON_SURFACE)))
        {
			// make the container fairly worn
			containerToBury.SetHealthLevel(GameConstants.STATE_BADLY_DAMAGED);
			// get the loot table from the dayz game
			IAT_RollTableConfig rollConfig;
			if (Class.CastTo(rollConfig, GetDayZGame().GetIATRollTableConfig()))
			{
				// get the max number of items to spawn in the container
				int maxItems = treasureTier.GetNumItemsToSpawn();
				// hold the name of the item to spawn right now
				string potentialItem = "";
				// hold the results of any sub loot tables if exists
				TStringArray innerResults = {};
				// first set of results for this loot table
				TStringArray initialResults = rollConfig.GetResultsForItem(treasureTier.GetRollTable());

				EntityAI treasureItem;
				for (int i = 0; i < maxItems; i++)
				{
					// get some random result
					potentialItem = initialResults.GetRandomElement();
					// PrintFormat("===================================================Index: %1 Potential: %2", i, potentialItem);
					// recursively check for a loot table until we find a result that is just items
					while (rollConfig.RollTableExists(potentialItem))
					{
						// get the next level down results
						innerResults = rollConfig.GetResultsForItem(potentialItem);
						// get some random result
						potentialItem = innerResults.GetRandomElement();
						// PrintFormat("result was a roll table, new result is: %1", potentialItem);
					}
					if (Class.CastTo(treasureItem, containerToBury.GetInventory().CreateInInventory(potentialItem)))
					{
						int half = treasureItem.GetQuantityMax() / 2;
						Magazine ammo;
						ItemBase resultBase;
						// treat ammo special
						if (Class.CastTo(ammo, treasureItem))
						{
							ammo.ServerSetAmmoCount(Math.RandomIntInclusive(half, treasureItem.GetQuantityMax()));
						}
						// else normal quantity set
						else if (Class.CastTo(resultBase, treasureItem))
						{
							resultBase.SetQuantity(Math.RandomIntInclusive(half, treasureItem.GetQuantityMax()));
						}
					}
				}
			}

            InventoryLocation targetIL = new InventoryLocation();
            if (!containerToBury.GetInventory().GetCurrentInventoryLocation(targetIL))
            {
                ErrorEx("[IAT_BuryTreasure] Cannot get inventory location of entity=" + containerToBury);
                return false;
            }
            UndergroundStash stash;
			if (Class.CastTo(stash, g_Game.CreateObjectEx("UndergroundStash", stashLocation, ECE_PLACE_ON_SURFACE)))
            {
                stash.PlaceOnGround();
                if (GameInventory.LocationCanRemoveEntity(targetIL))
                {
                    containerToBury.ServerTakeEntityToTargetCargo(stash, containerToBury);
                }
                else
                {
                    Debug.Log(string.Format("[IAT_BuryTreasure] Cannot remove entity=%1 obj from current location=%2", containerToBury, InventoryLocation.DumpToStringNullSafe(targetIL)));
					return false;
                }
            }
            else
            {
                ErrorEx("[IAT_BuryTreasure] Stash not spawned!");
				return false;
            }
        }
		else
		{
			ErrorEx("[IAT_BuryTreasure] Container not spawned!");
		}
		return true;
    }
};
