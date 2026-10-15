modded class CraftBloodBagIV
{
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		BloodContainerBase bloodBagIngr = BloodContainerBase.Cast(ingredients[1]);
		BloodContainerBase bloodBagResult = BloodContainerBase.Cast(results.Get(0));

		if (bloodBagIngr && bloodBagResult)
		{
			MiscGameplayFunctions.TransferItemProperties(bloodBagIngr, bloodBagResult, true, true, false, false);
			bloodBagResult.SetBloodTypeVisible(bloodBagIngr.GetBloodTypeVisible());
		}
	}
};