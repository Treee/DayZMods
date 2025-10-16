modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionLegCastTarget);
		actions.Insert(IAT_ActionLegCastSelf);

		actions.Insert(IAT_ActionTurnOnGramophone);
		actions.Insert(IAT_ActionTurnOffGramophone);

		actions.Insert(IAT_ActionOpenVinylBoosterPack);
    }
};