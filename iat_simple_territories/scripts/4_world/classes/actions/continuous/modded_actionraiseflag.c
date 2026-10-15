modded class ActionRaiseFlag
{
    override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
    {
		// default text
        m_Text = "#raise_flag";

        TerritoryFlag totem;
        if (Class.CastTo(totem, target.GetObject()))
        {
			// if we do not have the required tax items
            if (!totem.HasRequiredTaxItems())
                m_Text = "Raise Flag - Requires More Flag Tax Items"; // set the text
        }
    }

    override void OnFinishProgressServer( ActionData action_data )
    {
		// if the target object is a flag
        TerritoryFlag totem;
        if (Class.CastTo(totem, action_data.m_Target.GetObject()))
        {
            // if we do have the required items
            if (totem.HasRequiredTaxItems())
            {
                // preserve call chain
                super.OnFinishProgressServer(action_data);

                // remove the required tax items on a successful flag raise
                totem.RemoveRequiredTaxItems();
            }
        }
    }
};