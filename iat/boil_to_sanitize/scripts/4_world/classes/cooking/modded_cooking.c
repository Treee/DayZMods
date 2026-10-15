modded class Cooking
{
	override void ProcessItemToCook(notnull ItemBase pItem, ItemBase cookingEquip, Param2<CookingMethodType, float> pCookingMethod, out Param2<bool, bool> pStateFlags)
	{
		// keep track of old hp for items that get damaged by fire
		float oldHp = pItem.GetHealth();
		int oldQuantity = pItem.GetQuantity();
		// do existing logic
		super.ProcessItemToCook(pItem, cookingEquip, pCookingMethod, pStateFlags);
		// if the item can be disinfected AND is not already disinfected
		if (pItem.CanBeDisinfected())
		{
			// if the item is not disinfected already
			if (pItem.GetCleanness() < 1)
			{
				// if our item can also be overheated AND is in the overheated state
				if (pItem.CanItemOverheat() && pItem.IsItemOverheated())
				{
					// remove any agent that is destroyed by heat
					pItem.RemoveAllAgentsExcept(eAgents.BRAIN | eAgents.SALMONELLA | eAgents.CHOLERA);
					// set the rag to disinfected
					pItem.SetCleanness(1);
				}
			}
			// reset to old hp if the fire is damaging our items
			if (pItem.GetHealth() < oldHp)
			{
				pItem.SetHealth(oldHp);
			}
			// reset to old qualtity if the fire is damaging our items
			if (pItem.GetQuantity() < oldQuantity)
			{
				pItem.SetQuantity(oldQuantity);
			}
		}
	}
};