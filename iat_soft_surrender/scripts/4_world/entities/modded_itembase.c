modded class ItemBase
{
    override bool CanDetachAttachment (EntityAI parent)
    {
        if (!super.CanDetachAttachment(parent))
            return false; // short circuit items we already cannot take out

        PlayerBase itemParent;
        if (Class.CastTo(itemParent, GetHierarchyRootPlayer()))
        {
			// players that are alive AND soft surrendered cannot have items removed from attachments
            if (itemParent.IsAlive() && itemParent.IAT_IsSoftSurrendered())
                return false;
        }
        return true;
    }
    override bool CanRemoveFromCargo(EntityAI parent)
    {
        if (!super.CanRemoveFromCargo(parent))
            return false; // short circuit items we already cannot take out

        PlayerBase itemParent;
        if (Class.CastTo(itemParent, GetHierarchyRootPlayer()))
        {
			// players that are alive AND soft surrendered cannot have items removed from cargo
            if (itemParent.IsAlive() && itemParent.IAT_IsSoftSurrendered())
                return false;
        }
        return true;
    }
};