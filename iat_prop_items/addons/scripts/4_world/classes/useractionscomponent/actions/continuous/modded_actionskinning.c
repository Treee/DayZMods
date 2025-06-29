modded class ActionSkinning
{
	override void HandlePlayerBody(ActionData action_data)
	{
		PlayerBase body;
		if (Class.CastTo(body,action_data.m_Target.GetObject()))
		{
			IAT_LegCastApplied_Colorbase attachment;
			if (Class.CastTo(attachment, body.GetItemOnSlot("Splint_Right")))
			{
				attachment.Delete();
			}
		}
		super.HandlePlayerBody(action_data);
	}
};