modded class TerritoryFlag
{
    protected float m_IAT_LastPhase = -1;

    // =========================================================== VANILLA OVERRIDE
    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
        ItemBase attachedItem;
        if (Class.CastTo(attachedItem, attachment))
        {
            // is this item something that can satisfy the flag tax
            if (attachedItem.IAT_IsFlagTaxItem())
            {
                return true;
            }
        }
        return super.CanReceiveAttachment(attachment, slotId);
    }

    /*
    * We need to override these 2 functions because vanilla resets the animation
    * when an item is detached from the totem (because in vanilla only a flag can be attached)
    * this intercepts those calls and checks to see if a flag is still attached
    * if so, it ignores any resetting
    */
    override void AnimateFlagEx(float delta, PlayerBase player = null)
    {
        // get the last state this flag was at
        m_IAT_LastPhase = GetAnimationPhase("flag_mast");

        // if we are being forced into the fully lowered state
        if (delta == 1 && m_IAT_LastPhase <= 0.2)
        {
            // if there is a flag attached, ignore the animation call
            if (HasFlagAttached())
                return;
        }
        // preserve the call chain
        super.AnimateFlagEx(delta, player);
    }

    override void SetRefreshTimer01(float fraction)
	{
        // if there is a flag attached, ignore any resetting
        if (HasFlagAttached())
            return;
        // otherwise, preserve the call chain
        super.SetRefreshTimer01(fraction);
    }

    // =========================================================== CUSTOM
    bool HasRequiredTaxItems()
    {
        ItemBase flagTax;
        if (Class.CastTo(flagTax, FindAttachmentBySlotName("IAT_FlagRaiseTax")))
        {
            return flagTax.IAT_HasRequiredTaxItems();
        }
        return false;
    }
    bool HasFlagAttached()
    {
        ItemBase flag;
        if (Class.CastTo(flag, FindAttachmentBySlotName("Material_FPole_Flag")))
        {
            return true;
        }
        return false;
    }
    void RemoveRequiredTaxItems()
    {
        ItemBase flagTax;
        if (Class.CastTo(flagTax, FindAttachmentBySlotName("IAT_FlagRaiseTax")))
        {
            flagTax.IAT_ConsumeFlagTaxItems();
        }
    }
};