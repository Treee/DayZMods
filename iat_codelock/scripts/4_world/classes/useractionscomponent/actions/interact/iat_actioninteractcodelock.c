class IAT_ActionInteractCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionInteractCodelock()
	{
		m_Text = "Interact with Codelock";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone();
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// this action path goes from most specific to most generic (reverse funnel)
		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
			{
				return IAT_CanPlayerInteractWithCodelockedObject(iat_codelock, player);
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, target.GetParent()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
			{
				return IAT_CanPlayerInteractWithCodelockedObject(iat_codelock, player);
			}
		}
		return false;
	};

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
			{
				iat_codelock.OpenPasscodeEntryMenu();
				return; // short circuit
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, action_data.m_Target.GetParent()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
			{
				iat_codelock.OpenPasscodeEntryMenu();
				return; // short circuit
			}
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " interact with code lock ";
	}

};