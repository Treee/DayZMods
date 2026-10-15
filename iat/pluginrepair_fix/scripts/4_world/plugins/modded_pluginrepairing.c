modded class PluginRepairing
{
	// override this function to check if the kit has actual quantity.
	// vanilla doesnt check quantity until repair on the server so 1% items can be abused to repair a full level
	override bool CanRepair(ItemBase repair_kit, Object item, string damage_zone = "")
	{
		// if the item CAN REPAIR
		if (super.CanRepair(repair_kit, item, damage_zone))
		{
			// check if it has quantity
			if (repair_kit.HasQuantity())
			{
				float cur_kit_quantity = repair_kit.GetQuantity();
				float kit_repair_cost_per_level = GetKitRepairCost(repair_kit, item);
				// if the kit has quantity above the cost
				return cur_kit_quantity >= kit_repair_cost_per_level;
			}
			else
			{
				// these are hammers and such that cannot be split so pass through
				return true;
			}
		}
		return false;
	}
};