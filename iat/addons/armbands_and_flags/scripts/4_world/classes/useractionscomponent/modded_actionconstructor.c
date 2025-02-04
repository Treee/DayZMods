modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionCraftFlagOptions);
		actions.Insert(IAT_ActionCraftArmbandOptions);
	}
};
