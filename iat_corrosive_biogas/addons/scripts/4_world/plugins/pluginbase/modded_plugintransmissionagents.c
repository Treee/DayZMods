modded class PluginTransmissionAgents
{
	void PluginTransmissionAgents()
	{
		RegisterAgent(new IAT_CorrosiveAgent);
	}

	override float TransmitAgentsEx(EntityAI source, EntityAI target, int pathway, int dose_size = 1000, int agents = 0)
	{
		float count = super.TransmitAgentsEx(source, target, pathway, dose_size, agents);
		// item entering inventory
		if (pathway == AGT_INV_IN)
		{
			ItemBase invItem;
			// source item has corrosion, transfer it to target and its inventory
			if (target.HasAnyCargo())
			{
				int itemCount = target.GetInventory().GetCargo().GetItemCount();
				for (int i = 0; i < itemCount; i++)
				{
					if (Class.CastTo(invItem, target.GetInventory().GetCargo().GetItem(i)))
					{
						if (!invItem.HasCorrosiveAgents())
						{
							invItem.SetCorrosiveAgents(true);
							invItem.SetSynchDirty();
						}
					}
				}
			}
			// transfer it to the target as well
			if (Class.CastTo(invItem, target))
			{
				if (!invItem.HasCorrosiveAgents())
				{
					invItem.SetCorrosiveAgents(true);
					invItem.SetSynchDirty();
				}
			}
			count = 1;
		}
		return count;
	}
};