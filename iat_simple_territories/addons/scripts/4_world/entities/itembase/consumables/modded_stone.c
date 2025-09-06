modded class Stone
{
	override bool IAT_IsFlagTaxItem()
	{
		return true;
	}
	override int IAT_GetFlagTaxConsumptionCount()
	{
		return 1;
	}
};