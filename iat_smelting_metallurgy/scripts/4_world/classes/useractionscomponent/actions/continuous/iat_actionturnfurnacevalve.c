class IAT_ActionTurnFurnaceValveCB : ActionTurnValveCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
}

class IAT_ActionTurnFurnaceValve : ActionTurnValve
{

	void IAT_ActionTurnFurnaceValve()
	{
		m_CallbackClass = IAT_ActionTurnFurnaceValveCB;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if vanilla passes, make sure we have accelerant and ore attached
		if (super.ActionCondition(player, target, item))
		{
			IAT_SmeltingFurnace_ColorBase furnace;
			if (Class.CastTo(furnace, target.GetObject()))
			{
				return true;
			}
		}
		// vanilla didnt pass so do not return true
		return false;
	}

	override void OnStartAnimationLoopServer(ActionData action_data)
	{
		super.OnStartAnimationLoopServer(action_data);

		IAT_SmeltingFurnace_BasicStone furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			furnace.OnValveManipulationStart(furnace.GetTurnableValveIndex(action_data.m_Target.GetComponentIndex()));
		}
	}

	override void OnEndAnimationLoop(ActionData action_data)
	{
		super.OnEndAnimationLoop(action_data);

		IAT_SmeltingFurnace_BasicStone furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			furnace.OnValveManipulationCanceled(furnace.GetTurnableValveIndex(action_data.m_Target.GetComponentIndex()));
		}
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		IAT_SmeltingFurnace_BasicStone furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			furnace.OnValveManipulationEnd(furnace.GetTurnableValveIndex(action_data.m_Target.GetComponentIndex()));
		}
	}
	override void OnFinishProgressClient(ActionData action_data)
	{
		super.OnFinishProgressClient(action_data);

		IAT_SmeltingFurnace_BasicStone furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			if (furnace.IAT_CanOpenMiniGameMenu())
			{
				furnace.IAT_OpenMiniGameMenu();
			}
		}
	}
};