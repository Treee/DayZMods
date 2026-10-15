modded class PluginAdminLog
{
	override void PlayerKilled( PlayerBase player, Object source )
	{
		super.PlayerKilled(player, source);
		LogEquippedItems(player);
	}

	void LogEquippedItems(PlayerBase player)
    {
		int attachmentsCount = player.GetInventory().AttachmentCount();

        EntityAI attachedEntity;
		// for each attached player slot
		for (int i = 0; i < attachmentsCount; ++i)
		{
			if (Class.CastTo(attachedEntity, player.GetInventory().GetAttachmentFromIndex(i)))
			{
				LogEquippedGearContents(attachedEntity);
			}
		}
    }

	void LogEquippedGearContents(EntityAI attachment)
	{
		string itemContents = string.Format("%1[%2]", attachment.GetType(), IAT_ConvertDamageStateToString(attachment.GetHealthLevel()));

		array<EntityAI> itemsArray = new array<EntityAI>;
        attachment.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);

		ItemBase fullItem;
		Edible_Base edibleItem;
		Magazine magazineItem;
		// stupid backwards loops for optimization. ignore last index because its just the parent
		for (int i = itemsArray.Count(); i > 0; i--)
		{
			if (Class.CastTo(fullItem, itemsArray.Get(i)))
			{
				// magazines
				if (Class.CastTo(magazineItem, fullItem))
				{
					itemContents = string.Format("%1, %2[%3](%4)", itemContents, magazineItem.GetType(), IAT_ConvertDamageStateToString(magazineItem.GetHealthLevel()), magazineItem.GetAmmoCount());
				}
				else if (fullItem.HasQuantity()) // other things with quantity
				{
					itemContents = string.Format("%1, %2[%3](%4)", itemContents, fullItem.GetType(), IAT_ConvertDamageStateToString(fullItem.GetHealthLevel()), fullItem.GetQuantity());
				}
				else // single items
				{
					itemContents = string.Format("%1, %2[%3]", itemContents, fullItem.GetType(), IAT_ConvertDamageStateToString(fullItem.GetHealthLevel()));
				}
				// cookable items
				if (Class.CastTo(edibleItem, fullItem))
				{
					if (edibleItem.CanBeCooked())
					{
						itemContents = string.Format("%1{%2}", itemContents, IAT_ConvertFoodStageToString(edibleItem));
					}
				}
			}
		}
		LogPrint(itemContents);
	}

	string IAT_ConvertDamageStateToString(int damageState)
	{
		string text = "unknown";
		switch(damageState)
		{
			case GameConstants.STATE_RUINED:
				text = "ruined";
			break;

			case GameConstants.STATE_BADLY_DAMAGED:
				text = "badly damaged";
			break;

			case GameConstants.STATE_DAMAGED:
				text = "damaged";
			break;

			case GameConstants.STATE_WORN:
				text = "worn";
			break;

			case GameConstants.STATE_PRISTINE:
				text = "pristine";
			break;
		}
		return text;
	}

	string IAT_ConvertFoodStageToString(Edible_Base edibleItem)
	{
		return edibleItem.GetFoodStageName(edibleItem.GetFoodStageType());
	}
};