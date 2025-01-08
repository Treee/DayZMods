modded class ActionWaterPlant
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();

		if ( targetObject != NULL && targetObject.IsInherited(PlantBase) && item != NULL && !item.IsDamageDestroyed() )
		{
			PlantBase plant = PlantBase.Cast( targetObject );

			// if ( plant.NeedsWater() && item.GetQuantity() > 0 )
			if (item.GetQuantity() > 0 )
			{
				return true;
			}
		}
		return false;
	}
};