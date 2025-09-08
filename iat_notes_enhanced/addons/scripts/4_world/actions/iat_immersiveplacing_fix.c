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

			// note placement
			if (m_AdminLog)
			{
				m_AdminLog.OnPlacementComplete(action_data.m_Player, paper);
				string noteNext = string.Format("Note Text: %1", paper.GetWrittenNoteData().GetNoteText());
				m_AdminLog.DirectAdminLogPrint(noteNext);
			}
		}
	}
}

// not needed since ActionQuickPlaceItem is also called when placing an item
// modded class ActionQuickDropItem {};

#endif