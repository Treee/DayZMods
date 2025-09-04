class IAT_Ladder_Closed_ColorBase extends ItemBase
{
	override bool IsDeployable()
	{
		return true;
	}
	override bool CanAssignAttachmentsToQuickbar()
	{
		return false;
	}
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete(player, position, orientation);
		if( GetGame().IsDedicatedServer() )
		{
			DeleteSafe();
		}
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
};

class IAT_Ladder_Opened_ColorBase extends ItemBase
{
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
  	override bool IsInventoryVisible()
	{
		return false;
	}
	override bool IsTakeable()
	{
		return false;
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete(player, position, orientation);
		if( GetGame().IsDedicatedServer() )
		{
			if (m_AdminLog)
			{
				m_AdminLog.OnPlacementComplete( player, this);
			}
		}
	}
};

// Kits
class IAT_Ladder_Closed_Basic extends IAT_Ladder_Closed_ColorBase{};

// Deployed
class IAT_Ladder_Opened_Basic extends IAT_Ladder_Opened_ColorBase{};
