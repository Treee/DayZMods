modded class CAContinuousMineRock
{
	override bool GetMiningData(ActionData action_data )
	{
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, action_data.m_Target.GetObject()))
		{
			m_AmountOfDrops = iat_Junction.GetMiningYieldQuantity(action_data.m_MainItem);
			iat_Junction.GetMaterialAndQuantityYieldMap(action_data.m_MainItem, m_MaterialAndQuantityMap);
			m_DamageToMiningItemEachDrop = iat_Junction.GetDamageToMiningItemEachYield(action_data.m_MainItem);
			m_AdjustedDamageToMiningItemEachDrop = m_DamageToMiningItemEachDrop;
			return true;
		}
		else
			return super.GetMiningData(action_data);
	}
};

modded class ActionMineRock
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if we can mine
		if (super.ActionCondition(player, target, item))
		{
			IAT_MiningSegment_Colorbase iat_Junction;
			// check our custom walls
			if (Class.CastTo(iat_Junction, target.GetObject()))
			{
				if (iat_Junction.IsMineable())
				{
					// get the component name of the thing we are looking at
					string componentName = iat_Junction.GetActionComponentName(target.GetComponentIndex());
					if (iat_Junction.CanMineComponent(componentName))
					{
						return true;
					}
				}
			}
			// our custom conditions failed, action failed
			return false;
		}
		//super returns true, pass it through
		return true;
	}

	override string GetYieldName(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, target.GetObject()))
		{
			return iat_Junction.GetMiningYield(item);
		}
		return super.GetYieldName(player, target, item);
	}

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, action_data.m_Target.GetObject()))
		{
			// get the component name of the thing we are looking at
			string componentName = iat_Junction.GetActionComponentName(action_data.m_Target.GetComponentIndex());
			iat_Junction.IncrementComponentHitCounter(componentName);
			// PrintFormat("mining complete %1", componentName);
		}
	}
};