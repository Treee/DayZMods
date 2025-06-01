modded class ItemBase
{
	protected bool m_HasCorrosiveAgent = false;
	protected bool m_HasCorrosionCargoProtection = false;

	void ItemBase()
	{
		RegisterNetSyncVariableBool("m_HasCorrosiveAgent");
	}

	override void AfterStoreLoad()
	{
		// do vanilla
		super.AfterStoreLoad();
		// check the server
		if (GetGame().IsDedicatedServer())
		{
			// if this item contains corrosion
			if (ContainsAgent(IAT_CB_Agents.CORROSION))
			{
				// toggle bool for client, sync dirty
				// PrintFormat("Item: %1 has corrosion.", GetType());
				SetCorrosiveAgents(true);
				SetSynchDirty();
			}
		}
	}
	override void InitItemVariables()
	{
		super.InitItemVariables();

		string entry = string.Format("CfgVehicles %1 Protection corrosion", GetType());
		m_HasCorrosionCargoProtection = (GetGame().ConfigGetInt(entry) == 1);
	}
	// ============================================ EVENTS
	// ensure it still happens
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnMovedInsideCargo(EntityAI container)
	{
		super.OnMovedInsideCargo(container);
		if (GetGame().IsDedicatedServer())
		{
			// short circuit for protected cargo containers
			if (m_HasCorrosionCargoProtection)
				return;

			ItemBase invItem;
			ItemBase containerItem;
			if (!Class.CastTo(containerItem, container))
				return;

			int containerCorrosionItemCount = 0;
			int itemCount = container.GetInventory().GetCargo().GetItemCount();
			for (int i = 0; i < itemCount; i++)
			{
				if (Class.CastTo(invItem, container.GetInventory().GetCargo().GetItem(i)))
				{
					// PrintFormat("Item inside: %1", invItem.GetType());
					if (invItem.HasCorrosiveAgents())
					{
						containerCorrosionItemCount++;
					}
				}
			}
			bool hasSourceCorrosion = (HasCorrosiveAgents() || containerItem.HasCorrosiveAgents());
			float corrosionProbability = CalculateCorrosionProbability(itemCount, containerCorrosionItemCount, hasSourceCorrosion);

			// if this item has corrosion, do some logic to see the probability of transferring it to items
			if (HasCorrosiveAgents())
			{
				// PrintFormat("Item: %1 Moved Inside: %2", GetType(), container.GetType());
				TransmitCorrosionAgents(container, corrosionProbability);
			}
			// the item does not have corrosion, do some logic to see the probability of the container giving this item corrosion
			else if (containerItem.HasCorrosiveAgents())
			{
				// PrintFormat("Item: %1 Moved Inside: %2", GetType(), container.GetType());
				TransmitParentCorrosionAgents(container, this, corrosionProbability);
			}
		}
	}

	// when an item gets drenched, remove corrosion
	override void OnWetChanged(float newVal, float oldVal)
	{
		super.OnWetChanged(newVal, oldVal);

		if (newVal >= GameConstants.STATE_WET)
		{
			if (GetGame().IsDedicatedServer())
			{
				if (HasCorrosiveAgents())
				{
					RemoveAgent(IAT_CB_Agents.CORROSION);
					SetCorrosiveAgents(false);
					SetSynchDirty();
				}
			}
		}
	}
	// when containers empty and are not deleted, re-add agents
	override bool SetQuantity(float value, bool destroy_config = true, bool destroy_forced = false, bool allow_client = false, bool clamp_to_stack_max = true)
	{
		// get if this item has corrosion
		int existingAgents = GetAgents();
		// run vanilla logic and store the result for later use
		bool superBool = super.SetQuantity(value, destroy_config, destroy_forced, allow_client, clamp_to_stack_max);
		// short circuit items that do not have agents
		if (existingAgents < 1)
			return superBool;

		// only touch agents on the server
		if (GetGame().IsDedicatedServer())
		{
			// get the min quantity for this item
			float min = GetQuantityMin();
			if (value <= (min + 0.001))
				value = min;

			// if the item is really at 0
			if (value == min)
			{
				TransferAgents(existingAgents);
				if (ContainsAgent(IAT_CB_Agents.CORROSION))
				{
					// sync client stuff
					SetCorrosiveAgents(true);
					SetSynchDirty();
				}
			}
		}
		return superBool;
	}
	// ============================================ CUSTOM
	void TransmitCorrosionAgents(EntityAI target, float corrosionProbability)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		plugin.IAT_TransmitAgentsEx(this, target, AGT_INV_IN, corrosionProbability, 1, IAT_CB_Agents.CORROSION);
	}
	void TransmitParentCorrosionAgents(EntityAI source, EntityAI target, float corrosionProbability)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		plugin.IAT_TransmitAgentsEx(source, target, AGT_INV_IN, corrosionProbability, 1, IAT_CB_Agents.CORROSION);
	}
	bool HasCorrosiveAgents()
	{
		return m_HasCorrosiveAgent;
	}
	float CalculateCorrosionProbability(int totalItems, int corrodedItems, bool targetSourceCorroded)
	{
		// PrintFormat("Calculate probability. CorrodedItems: %1 TotalItems: %2 TargetSourceCorroded: %3", corrodedItems, totalItems, targetSourceCorroded);
		// how probable is this item to be corroded or corrode a container full of items
		float corrosionProbability = corrodedItems / totalItems;

		// handle some edge cases
		// if either item or container are corroded
		if (targetSourceCorroded)
		{
			// no corroded items inside
			if (corrodedItems == 0)
			{	// baseline 15% chance
				corrosionProbability += 0.15;
			}// no items at all
			else if (totalItems == 0)
			{	// higher baseline chance
				corrosionProbability += 0.35;
			}
		}
		// 100%
		corrosionProbability = 1 - corrosionProbability;
		// PrintFormat("Probability: %1", corrosionProbability);
		return corrosionProbability;
	}

	// used by the server to flag the client it has agents. bandaid for now until a more advanced agent system is available
	void SetCorrosiveAgents(bool newState)
	{
		m_HasCorrosiveAgent = newState;
	}

	bool HasCorrosionCargoProtection()
	{
		string entry = string.Format("CfgVehicles %1 Protection corrosion", GetType());
		return GetGame().ConfigGetInt(entry) == 1;
		// return m_HasCorrosionCargoProtection;
	}
};