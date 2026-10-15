modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionTurnOnPortalSteampunk);
		actions.Insert(IAT_ActionRingBellTower);
	}
};