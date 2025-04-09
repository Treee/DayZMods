modded class PlayerBase
{
	// ====================================================== VANILLA OVERRIDE
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

	// FOR AI TESTING
	// override bool CanBeRestrained()
	// {
	// 	return true;
	// }

	// ====================================================== HELPERS
	// nice wrapper for our class JUST in case
	bool IAT_IsSoftSurrendered()
	{
		// FOR AI testing
		// if (IsRestrained())
		// {
		// 	return true;
		// }

		// prod version
		return IsSurrendered();
	}
};