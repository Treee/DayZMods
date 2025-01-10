modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionReadBook);
		actions.Insert(IAT_ActionSelectReadBook);
    }
};