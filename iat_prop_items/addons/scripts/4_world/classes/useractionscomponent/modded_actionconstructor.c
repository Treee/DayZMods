modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionLegCastTarget);
		actions.Insert(IAT_ActionLegCastSelf);
    }
};