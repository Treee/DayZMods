modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionMeasureIllnessTarget);
		actions.Insert(IAT_ActionMeasureIllnessSelf);
	}
};