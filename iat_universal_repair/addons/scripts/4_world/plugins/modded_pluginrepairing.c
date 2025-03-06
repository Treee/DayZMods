modded class PluginRepairing
{
	override bool CanRepair( ItemBase repair_kit, Object item, string damage_zone = "" )
	{
        // short circuit vanilla behavior
        if (super.CanRepair(repair_kit, item, damage_zone))
        {
            // get the vanilla value
            int repair_kit_type = repair_kit.ConfigGetInt("repairKitType");
            // outside of regular repair kit logic for some reason, bypass check
            // vanilla logic needs to be handled here because it allows "bad kits" to repair
			if (repair_kit_type)
			{
				return true;
			}
        }

        // Print("normal repair fails on this condition");
		int state = item.GetHealthLevel(damage_zone);
		if ( state != GameConstants.STATE_RUINED && (item.CanBeRepairedToPristine() && state >= GameConstants.STATE_WORN) || (!item.CanBeRepairedToPristine() && state >= GameConstants.STATE_DAMAGED ) )
		{
            // Print("item not ruined and can be repaired");
            // pull the list of ints from config
            array<int> repair_kit_types = new array<int>;
			repair_kit.ConfigGetIntArray( "repairKitType", repair_kit_types );

			array<int> repairable_with_types = new array<int>;
			item.ConfigGetIntArray( "repairableWithKits", repairable_with_types );

			for ( int i = 0; i < repairable_with_types.Count(); i++ )
			{
				int repairable_with_type = repairable_with_types.Get(i);
                // try to find this repair kit type from the list
                int repair_kit_types_index = repair_kit_types.Find(repairable_with_type);
                // PrintFormat("item repaired by: %1, was it found? : %2", repairable_with_type, repair_kit_types_index);
                // if we did find a valid repair kit
                if (repair_kit_types_index > -1)
                {
                    // Print("valid repair kit type");
                    // check the repair given the found index for the repair kit
                    if ( IsRepairValid( repair_kit_types.Get(repair_kit_types_index), repairable_with_type ) )
                    {
                        // PrintFormat("IsRepairValid: %1, was it found? : %2", repair_kit_types.Get(repair_kit_types_index), repairable_with_type);
                        return true;
                    }
                }
			}
		}
		return false;
	}

    override private float GetKitRepairCost(ItemBase repair_kit, Object item)
	{
        // store vanilla checked repair cost
        float originalRepairCost = super.GetKitRepairCost(repair_kit, item);
        if (originalRepairCost < 1)
        {
            // check our special repair kits for viability
            array<int> repair_kit_types = new array<int>;
            repair_kit.ConfigGetIntArray( "repairKitType", repair_kit_types );

            array<int> allowedRepairKitTypes = new array<int>;
            item.ConfigGetIntArray( "repairableWithKits", allowedRepairKitTypes );

            array<float> repairKitCosts = new array<float>;
            item.ConfigGetFloatArray("repairCosts", repairKitCosts);

            foreach (int i, int allowedKitType : allowedRepairKitTypes)
            {
                // try to find this repair kit type from the list
                int repair_kit_types_index = repair_kit_types.Find(allowedKitType);
                if (repair_kit_types_index > -1)
                {
                    return repairKitCosts.Get(i);
                }
            }
        }
        // return whatever vanilla or other mods would have.
        return originalRepairCost;
	}
};