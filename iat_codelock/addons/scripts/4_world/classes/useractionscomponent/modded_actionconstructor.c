modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionManageCodelock);
		actions.Insert(IAT_ActionInteractCodelock);
		actions.Insert(IAT_ActionDestroyCodelock);
		actions.Insert(IAT_ActionAttachToTent);
		actions.Insert(IAT_ActionAttachToBaseBuilding);
    }
};