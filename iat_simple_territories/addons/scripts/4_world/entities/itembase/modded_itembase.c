modded class ItemBase
{
	bool IAT_IsFlagTaxItem()
	{
		return false;
	}
	bool IAT_HasRequiredTaxItems()
	{
		return GetQuantity() >= IAT_GetFlagTaxConsumptionCount();
	}
	int IAT_GetFlagTaxConsumptionCount()
	{
		return 0;
	}
	void IAT_ConsumeFlagTaxItems()
	{
		AddQuantity(-IAT_GetFlagTaxConsumptionCount());
	}
};