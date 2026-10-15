class IAT_ReplaceRadioWithNewRange : TurnItemIntoItemLambda
{
	void IAT_ReplaceRadioWithNewRange (EntityAI old_item, string new_item_type, PlayerBase player) { }

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
	}

	override void OnSuccess (EntityAI new_item)
	{
		super.OnSuccess(new_item);
		if ( new_item )
		{
			ItemTransmitter transmitter;
			if (Class.CastTo(transmitter, new_item))
			{
				if (transmitter.GetCompEM().CanWork())
					transmitter.GetCompEM().SwitchOn();
			}
		}
	}
};