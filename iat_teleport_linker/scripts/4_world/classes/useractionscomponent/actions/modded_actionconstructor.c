modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionSetAnchorTeleporter);
		actions.Insert(IAT_ActionSetTeleportDestination);
		actions.Insert(IAT_ActionClearTeleportDestination);
		actions.Insert(IAT_ActionTeleportToDestination);
		actions.Insert(IAT_ActionTeleportToPreviousLocation);
	}
};