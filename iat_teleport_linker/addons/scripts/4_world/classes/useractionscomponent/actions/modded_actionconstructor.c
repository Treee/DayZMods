modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionSetAnchorTeleporter);
		actions.Insert(IAT_ActionSetTeleportDestination);
	}
};