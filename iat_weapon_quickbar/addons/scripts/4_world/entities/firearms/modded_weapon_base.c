modded class Weapon_Base
{
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
    {
        super.OnItemLocationChanged(old_owner, new_owner);
        // Print("weaponbase OnItemLocationChanged: " + GetType() + " : " + old_owner + " new: " + new_owner);
        if (new_owner && !CanAssignToQuickbar())
        {
            PlayerBase rootPlayer;
            if (Class.CastTo(rootPlayer, new_owner.GetHierarchyRootPlayer()))
                rootPlayer.RemoveQuickBarEntityShortcut(this);
        }
    }
    override bool CanAssignToQuickbar()
    {
        if (super.CanAssignToQuickbar()) // if vanilla says we can add to quickbar, run our logic
        {
            // PrintFormat("CanAssignToQuickbar Checking slots for %1", GetType());
            PlayerBase playerParent;
            // main shoulder slots on player
            if (Class.CastTo(playerParent, GetHierarchyParent()))
                return true;
            // no guns in cargo can go on quickbar
            if (GetInventory() && GetInventory().IsInCargo())
                return false;

            EntityAI itemParent;
            // attached to some item
            if (Class.CastTo(itemParent, GetHierarchyParent()))
            {
                // item attached to player
                if (Class.CastTo(playerParent, itemParent.GetHierarchyParent()))
                    return true;
                // item in cargo
                if (itemParent.GetInventory() && itemParent.GetInventory().IsInCargo())
                    return false;
            }
            return true;
        }
        return false;
    }
};