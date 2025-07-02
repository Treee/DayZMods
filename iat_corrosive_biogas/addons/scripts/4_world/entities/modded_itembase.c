modded class ItemBase
{
	protected bool m_HasCorrosiveAgent = false;
	protected bool m_HasCorrosionCargoProtection = false;

	override void InitItemVariables()
	{
		super.InitItemVariables();

		string entry = string.Format("CfgVehicles %1 Protection corrosion", GetType());
		m_HasCorrosionCargoProtection = (GetGame().ConfigGetInt(entry) == 1);
	}
	// ============================================ EVENTS

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
			}
		}
		return superBool;
	}
	// ============================================ CUSTOM
};