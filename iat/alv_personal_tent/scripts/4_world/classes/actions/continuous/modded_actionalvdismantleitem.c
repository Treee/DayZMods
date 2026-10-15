modded class ActionALVDismantleItem
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if the existing logic fails
		if (!super.ActionCondition(player, target, item))
		{
			// try checking if this is our tent
			IAT_PersonalTent_ColorBase targetTent;
			if (Class.CastTo(targetTent, target.GetObject()))
			{
				if (targetTent.IsEmpty())
				{
					if (targetTent.IAT_CanOpenPersonalTent(player.GetIdentity()))
					{
						return true;
					}
				}
			}
			// pass through existing failure if we get here
			return false;
		}
		// pass through existing success if we get here.
		return true;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		// clear players tent reservation
		IAT_PersonalTent_ColorBase targetTent;
		if (Class.CastTo(targetTent, action_data.m_Target.GetObject()))
		{
			if (targetTent.IsEmpty())
			{
				if (targetTent.IAT_CanOpenPersonalTent(action_data.m_Player.GetIdentity()))
				{
					// clear the reservation on the server
					targetTent.IAT_UnRegisterWithTentManager();
				}
			}
		}
		// this handles deleting the item which ultimately unregisters the item
		super.OnFinishProgressServer(action_data);
		// RPC sync to client
		action_data.m_Player.TryFetchCanDeployPersonalTent(action_data.m_Player.GetIdentity());
	}
};