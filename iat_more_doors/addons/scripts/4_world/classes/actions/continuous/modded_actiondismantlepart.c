modded class ActionDismantlePart
{
	// not really ever used but i need to override to stop log spam
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// is the target our doors?
		IAT_ConstructionDoor_Colorbase targetIATDoor;
		if (Class.CastTo(targetIATDoor, target.GetObject()))
		{
			// is our door locked?
			if (targetIATDoor.CanDismantleDoor())
			{
				m_Text = string.Format("#dismantle %1", targetIATDoor.GetDisplayName());
			}
			m_Text = "Door Locked; Cannot Dismantle";
		}
		else
		{
			super.OnActionInfoUpdate(player, target, item);
		}
	}

	override string GetText()
	{
		string text = super.GetText();
		if (text == "")
		{
			return "#dismantle";
		}
		return text;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		// is the target our doors?
		IAT_ConstructionDoor_Colorbase targetIATDoor;
		if (Class.CastTo(targetIATDoor, action_data.m_Target.GetObject()))
		{
			IAT_MoreDoor_Kit iat_doorkit;
      		if (Class.CastTo(iat_doorkit, GetGame().CreateObjectEx("IAT_MoreDoor_Kit", action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
			{
				action_data.m_MainItem.DecreaseHealth( UADamageApplied.DISMANTLE, false );

				targetIATDoor.DeleteSafe();
			}
		}

		super.OnFinishProgressServer(action_data);
	}

	override protected bool DismantleCondition(PlayerBase player, ActionTarget target, ItemBase item, bool camera_check)
	{
		// let vanilla pass through without checking. our conditions are outside of this
		if (super.DismantleCondition(player, target, item, camera_check))
			return true;

		// player exists AND they are not placing anything
		if (player && !player.IsPlacingLocal() && !player.IsPlacingServer())
		{
			// is the target our doors?
			IAT_ConstructionDoor_Colorbase targetIATDoor;
			if (Class.CastTo(targetIATDoor, target.GetObject()))
			{
				// is our door locked?
				if (targetIATDoor.CanDismantleDoor())
				{
					return true;
				}
			}
		}
		return false;
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		// is the target our doors?
		IAT_ConstructionDoor_Colorbase targetIATDoor;
		if (Class.CastTo(targetIATDoor, action_data.m_Target.GetObject()))
		{
			return string.Format("Dismantled %1 (%2) with %3", targetIATDoor.GetType(), action_data.m_Target.GetObject().GetDisplayName(), action_data.m_MainItem.GetDisplayName() );
		}
		return super.GetAdminLogMessage(action_data);
	}
}