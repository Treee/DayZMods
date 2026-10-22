modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionBuildStage);
		// actions.Insert(IAT_ActionBuildStageNoTool);
	}
};