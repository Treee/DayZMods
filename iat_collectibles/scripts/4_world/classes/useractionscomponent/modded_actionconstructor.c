modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionOpenBoosterPack);
		actions.Insert(IAT_ActionFlipCard);
    }
};