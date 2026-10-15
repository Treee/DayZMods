modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionInteractWallConsoleSwitch);
		actions.Insert(IAT_ActionInteractWallConsoleDial);
	}
};