// ========================================================== PLAYING CARDDECK
class IAT_CardDeck_Colorbase extends ItemBase
{
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		GameInventory inventory = GetInventory();
	}
};
class IAT_CardDeck_Basic extends IAT_CardDeck_Colorbase{};

// ========================================================== TAROT CARDDECK
class IAT_TarotCardDeck_Colorbase extends ItemBase
{
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		GameInventory inventory = GetInventory();
		// inventory.CreateAttachment("IAT_TarotCard_1w");
	}
};
class IAT_TarotCardDeck_Basic extends IAT_TarotCardDeck_Colorbase{};
class IAT_TarotCardDeck_essesentiendum extends IAT_TarotCardDeck_Colorbase{};

// ========================================================== COLLECTIBLE CARDDECK
class IAT_CollectibleDeck_Colorbase extends Container_Base
{
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		GameInventory inventory = GetInventory();
		// inventory.CreateAttachment("IAT_TarotCard_1w");
	}
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (super.CanReceiveItemIntoCargo(item))
		{
			if (item.IsInherited(IAT_CollectibleCard_ColorBase))
			{
				return true;
			}
		}
		return false;
	}
	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (super.CanLoadItemIntoCargo(item))
		{
			if (item.IsInherited(IAT_CollectibleCard_ColorBase))
			{
				return true;
			}
		}
		return false;
	}
};
class IAT_CollectibleDeck_Basic extends IAT_CollectibleDeck_Colorbase{};
