class IAT_FurnaceKit_ColorBase extends ItemBase
{
	override bool IsBasebuildingKit()
	{
		return true;
	}
	override bool IsDeployable()
	{
		return true;
	}
	override bool DoPlacingHeightCheck()
	{
		return true;
	}
	override float HeightCheckOverride()
	{
		return 2.54;
	}
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		if ( GetGame().IsDedicatedServer() )
		{
			IAT_SmeltingFurnace_ColorBase newFurnace;
			if (Class.CastTo(newFurnace, GetGame().CreateObjectEx(GetSmeltingKitName(), GetPosition(), ECE_PLACE_ON_SURFACE)))
			{
				newFurnace.SetPosition( position );
				newFurnace.SetOrientation( orientation );
				// remove the object
				DeleteSafe();
			}
		}
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}

	string GetSmeltingKitName()
	{
		string furnaceClass = GetType();
		furnaceClass.Replace("IAT_FurnaceKit_", "IAT_SmeltingFurnace_");
		return furnaceClass;
	}
};


class IAT_FurnaceKit_BasicStone extends IAT_FurnaceKit_ColorBase{};
class IAT_FurnaceKit_BasicBrick extends IAT_FurnaceKit_ColorBase{};
class IAT_FurnaceKit_Advancedstone extends IAT_FurnaceKit_ColorBase{};
class IAT_FurnaceKit_Industrial extends IAT_FurnaceKit_ColorBase{};