#ifdef placeable_items_fixed

// this doesnt seem to be called at all
// modded class ActionQuickPlaceItemToggle {};

modded class ActionQuickPlaceItem
{
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);
        Paper paper;
		if (Class.CastTo(paper, action_data.m_MainItem))
		{
			// Set lifetime to 1 week anytime a note is placed
			paper.SetLifetimeMax(604800);
		}
	}
}

// not needed since ActionQuickPlaceItem is also called when placing an item
// modded class ActionQuickDropItem {};

#endif