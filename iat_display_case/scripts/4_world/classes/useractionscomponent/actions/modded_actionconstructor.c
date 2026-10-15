modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionLockDisplayCase);
		actions.Insert(IAT_ActionUnLockDisplayCase);
    }
};