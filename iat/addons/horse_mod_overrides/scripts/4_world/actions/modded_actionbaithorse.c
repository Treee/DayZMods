modded class ActionBaitHorse
{
	protected ref TStringArray iat_Horsebait = {"Apple", "Pumpkin", "Zucchini"};
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if (item.IsDamageDestroyed())
			return false;

		if ( player.GetItemInHands() != item || player.GetHorseObject() )
        {
            return false;
        }

        if ( !player.GetHumanInventory().CanRemoveEntityInHands() )
        {
            return false;
        }
		if (iat_Horsebait.Find(player.GetItemInHands().GetType()) > -1)
		{
			Edible_Base food;
			if (Class.CastTo(food, item))
			{
				// rotten food is not allowed
				if (food.IsFoodRotten() || food.IsFoodBurned())
				{
					return false;
				}
			}
			if (item.HasQuantity() && item.GetQuantity() < 20)
			{
				return false;
			}
			return true;
		}
        return false;
    }

    override void OnEndServer( ActionData action_data )
    {
        super.OnEndServer(action_data);

		action_data.m_Player.SetOfferingBait(false);
		// consume 20 quantity
		if (action_data.m_MainItem.HasQuantity())
		{
			action_data.m_MainItem.AddQuantity(-20);
		}
		else // or 20 hp
		{
			action_data.m_MainItem.AddHealth(-20);
		}
    }
}