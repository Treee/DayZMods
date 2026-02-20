modded class PlayerBase
{
	// ====================================================== VANILLA OVERRIDE
	// required override because default vanilla has hard constraints with `IsRestrained`
	override bool Save()
	{
		// if there was not a successful save (probably a captive)
		if (!super.Save())
		{
			// check to see if the target is soft surrendered
			if (GetPlayerState() == EPlayerStates.ALIVE)
			{
				// soft surrendered targets can be saved
				if (IAT_IsSoftSurrendered())
				{
					GetHive().CharacterSave(this);
					Debug.Log("Player "+this.ToString()+ " saved as alive");

					return true;
				}
			}
			// pass through vanilla false
			return false;
		}
		// pass through vanilla save
		return true;
	}
	override bool CanManipulateInventory()
    {
		// if soft surrendered, allow the inventory to be "seen"
        if (IAT_IsSoftSurrendered())
		{
            return true;
		}
        return super.CanManipulateInventory();
    }
	override bool CanReleaseAttachment (EntityAI attachment)
    {
		// now that a player can "see" the inventory, we need to restrict removing items (attachments)
		// soft surrender is a read only action (for now)
        if(IAT_IsSoftSurrendered())
		{
            return false;
		}
        return super.CanReleaseAttachment(attachment);
    }
    override bool CanReleaseCargo (EntityAI cargo)
    {
		// now that a player can "see" the inventory, we need to restrict removing items (cargo)
		// soft surrender is a read only action (for now)
        if(IAT_IsSoftSurrendered())
		{
            return false;
		}
        return super.CanReleaseCargo(cargo);
    }
	override bool IsRestrained()
    {
		// PrintFormat("check is restrained");
		// if we are already restrained
		if (super.IsRestrained())
		{
			return true;
		}
		if (IAT_IsSoftSurrendered())
		{
			// PrintFormat("soft surrendered");
			return true;
		}
        return false;
    }

	// ====================================================== HELPERS
	// nice wrapper for our class
	bool IAT_IsSoftSurrendered()
	{
		// debug!! this lets use test on AI survivor base
		// return true;

		// vanilla pass through for surrendered players since some reason emotes are wonky to print
		// i think a mod conflict is happening here.
		if (IsSurrendered())
		{
			// Print("is surrendered");
			return true;
		}

		// prod version
		return false;
	}
};