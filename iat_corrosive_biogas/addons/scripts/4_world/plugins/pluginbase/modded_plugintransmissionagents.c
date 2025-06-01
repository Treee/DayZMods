modded class PluginTransmissionAgents
{
	void PluginTransmissionAgents()
	{
		RegisterAgent(new IAT_CorrosiveAgent);
	}

	float IAT_TransmitAgentsEx(EntityAI source, EntityAI target, int pathway, float probability, int dose_size = 1000, int agents = 0)
	{
		float count = 1;
		// item entering inventory
		if (pathway == AGT_INV_IN)
		{
			ItemBase invItem;
			float randomChance;
			// source item has corrosion, transfer it to target and its inventory
			if (target.HasAnyCargo())
			{
				// PrintFormat("Target: %1 has cargo", target.GetType());
				int itemCount = target.GetInventory().GetCargo().GetItemCount();
				for (int i = 0; i < itemCount; i++)
				{
					randomChance = Math.RandomFloatInclusive(0,1);
					if (Class.CastTo(invItem, target.GetInventory().GetCargo().GetItem(i)))
					{
						// PrintFormat("Item inside: %1", invItem.GetType());
						if (!invItem.HasCorrosiveAgents())
						{
							// PrintFormat("Random Chance: %1 Probability Threshold: %2", randomChance, probability);
							if (randomChance >= probability)
							{
								// Print("didnt have corrosion so add it");
								invItem.InsertAgent(IAT_CB_Agents.CORROSION, 1);
								invItem.SetCorrosiveAgents(true);
								invItem.SetSynchDirty();
							}
						}
					}
				}
			}
			// transfer it to the target as well
			if (Class.CastTo(invItem, target))
			{
				// PrintFormat("Target: %1 check to add corrosion.", target.GetType());
				if (!invItem.HasCorrosiveAgents())
				{
					randomChance = Math.RandomFloatInclusive(0,1);
					// PrintFormat("Random Chance: %1 Probability Threshold: %2", randomChance, probability);
					if (randomChance >= probability)
					{
						// Print("didnt have it but now it is added");
						invItem.InsertAgent(IAT_CB_Agents.CORROSION, 1);
						invItem.SetCorrosiveAgents(true);
						invItem.SetSynchDirty();
					}
				}
			}
		}
		return count;
	}
};