modded class ItemBase
{
	protected bool m_HasCorrosiveAgent = false;

	void ItemBase()
	{
		RegisterNetSyncVariableBool("m_HasCorrosiveAgent");
	}

	override void DeferredInit()
	{
		super.DeferredInit();

		if (GetGame().IsDedicatedServer())
		{
			if (ContainsAgent(IAT_CB_Agents.CORROSION))
			{
				// PrintFormat("Item: %1 has corrosion.", GetType());
				SetCorrosiveAgents(true);
				SetSynchDirty();
			}
		}
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
			if (HasCorrosiveAgents())
			{
				// PrintFormat("Item: %1 Moved Inside: %2", GetType(), container.GetType());
				TransmitCorrosionAgents(container);
			}
			else
			{
				ItemBase itemContainer;
				if (Class.CastTo(itemContainer, container))
				{
					if (itemContainer.HasCorrosiveAgents())
					{
						// PrintFormat("Item: %1 Moved Inside: %2", GetType(), container.GetType());
						TransmitParentCorrosionAgents(container, this);
					}
				}
			}
		}
	}

	//! Called when this item exits cargo of some container
	override void OnRemovedFromCargo(EntityAI container)
	{
		super.OnRemovedFromCargo(container);
		if (GetGame().IsDedicatedServer())
		{
			if (HasCorrosiveAgents())
			{
				// PrintFormat("Item: %1 Removed From: %2", GetType(), container.GetType());
				TransmitCorrosionAgents(container);
			}
			else
			{
				ItemBase itemContainer;
				if (Class.CastTo(itemContainer, container))
				{
					if (itemContainer.HasCorrosiveAgents())
					{
						// PrintFormat("Item: %1 Moved From: %2", GetType(), container.GetType());
						TransmitParentCorrosionAgents(container, this);
					}
				}
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
	void TransmitCorrosionAgents(EntityAI target)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		plugin.TransmitAgentsEx(this, target, AGT_INV_IN, 1, IAT_CB_Agents.CORROSION);
	}
	void TransmitParentCorrosionAgents(EntityAI source, EntityAI target)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		plugin.TransmitAgentsEx(source, target, AGT_INV_IN, 1, IAT_CB_Agents.CORROSION);
	}

	bool HasCorrosiveAgents()
	{
		return m_HasCorrosiveAgent;
	}

	// used by the server to flag the client it has agents. bandaid for now until a more advanced agent system is available
	void SetCorrosiveAgents(bool newState)
	{
		m_HasCorrosiveAgent = newState;
	}

};