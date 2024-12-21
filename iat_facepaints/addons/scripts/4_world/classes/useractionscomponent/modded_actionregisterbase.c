modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionPaintFace);
		actions.Insert(IAT_ActionPaintFaceTarget);

    	actions.Insert(IAT_ActionWashFace);
		actions.Insert(IAT_ActionWashFaceTarget);
	}
};