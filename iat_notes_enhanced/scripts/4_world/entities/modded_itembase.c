modded class ItemBase
{
	override string GetDisplayName()
	{
		// get the display name from the super call
		string displayName = super.GetDisplayName();
		// if the current item has an inventory
		if (GetInventory())
		{
			// if the item has a paper attached to label slot
			Paper iat_paper;
			if (Class.CastTo(iat_paper, IAT_GetAttachedPaper()))
			{
				// if the paper has written text
				if (iat_paper.GetHasWrittenText())
				{
					displayName = string.Format("%1 - %2", iat_paper.IAT_GetWrittenNoteText(), displayName);
				}
			}
		}
		return displayName;
	}

	protected Paper IAT_GetAttachedPaper()
	{
		Paper iat_paper;
		if (Class.CastTo(iat_paper, GetInventory().FindAttachmentByName("IAT_NoteLabel")))
		{
			return iat_paper;
		}
		return null;
	}
};