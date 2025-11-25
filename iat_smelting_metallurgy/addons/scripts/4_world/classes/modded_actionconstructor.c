modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
    	actions.Insert(IAT_ActionTurnFurnaceValve);
    	actions.Insert(IAT_ActionOpenSmeltingMenu);
    	actions.Insert(IAT_ActionToggleFurnaceLock);
	}
};