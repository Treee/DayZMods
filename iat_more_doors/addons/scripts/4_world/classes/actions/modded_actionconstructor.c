modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
    	actions.Insert(IAT_ActionSelectDoorOption);
    	actions.Insert(IAT_ActionOpenConstructionDoor);
    	actions.Insert(IAT_ActionCloseConstructionDoor);
	}
};