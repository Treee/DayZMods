modded class CraftCharcoalTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};

modded class CraftCholeraTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};

modded class CraftHealingTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};

modded class CraftPoisonTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};

modded class CraftTetraTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};

modded class CraftVitaminTea
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ALV_MetalCup Mug = ALV_MetalCup.Cast(ingredients[1]);
		if(Mug.GetLiquidType() == LIQUID_GROUP_DRINKWATER )
			return false;
		if (Mug.GetTemperature() < 100)
			return false;
		return true;
	}
};