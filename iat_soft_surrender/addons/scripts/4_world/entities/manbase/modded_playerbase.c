modded class PlayerBase
{
	protected bool m_IAT_IsSoftSurrendered = false;

	// ====================================================== VANILLA OVERRIDE
	override void Init()
    {
        super.Init();
        IAT_SetSoftSurrendered(false);
        RegisterNetSyncVariableBool("m_IAT_IsSoftSurrendered");
    }

	override bool CanManipulateInventory()
    {
		// if soft surrendered, allow the inventory to be "seen"
        if (IAT_IsSoftSurrendered())
            return true;
        return super.CanManipulateInventory();
    }
	override bool CanReleaseAttachment (EntityAI attachment)
    {
		// now that a player can "see" the inventory, we need to restrict removing items (attachments)
		// soft surrender is a read only action (for now)
        if(IAT_IsSoftSurrendered())
            return false;
        return super.CanReleaseAttachment(attachment);
    }
    override bool CanReleaseCargo (EntityAI cargo)
    {
		// now that a player can "see" the inventory, we need to restrict removing items (cargo)
		// soft surrender is a read only action (for now)
        if(IAT_IsSoftSurrendered())
            return false;
        return super.CanReleaseCargo(cargo);
    }

	// override bool IsRestrained()
    // {
    //     return m_IsRestrained || IAT_IsSoftSurrendered();
    // }
	// FOR AI TESTING
	// override bool CanBeRestrained()
	// {
	// 	return true;
	// }

	// ====================================================== HELPERS
	void IAT_SetSoftSurrendered(bool state)
	{
		// PrintFormat("player is soft surrendered: %1", state);
		m_IAT_IsSoftSurrendered = state;
	}
	// nice wrapper for our class JUST in case
	bool IAT_IsSoftSurrendered()
	{
		// vanilla pass through for surrendered players since some reason emotes are wonky to print
		// i think a mod conflict is happening here.
		if (IsSurrendered())
			return true;

		// prod version
		return m_IAT_IsSoftSurrendered;
	}
	void AutoCloseSoftSurrender()
    {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(IAT_SetSoftSurrendered, 15000, false, false);
    }
};