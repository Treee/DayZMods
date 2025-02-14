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
		string itemContents = "";

		ItemBase fullItem;
		if (Class.CastTo(fullItem, attachment))
		{
			if (fullItem.HasQuantity())
			{
				itemContents = string.Format("%1, %2(%3)", itemContents, fullItem.GetType(), fullItem.GetQuantity());
			}
			else
			{
				itemContents = string.Format("%1, %2", itemContents, fullItem.GetType());
			}
		}
		LogPrint("%1 contents: %2", attachment.GetType(), itemContents);
	}
};