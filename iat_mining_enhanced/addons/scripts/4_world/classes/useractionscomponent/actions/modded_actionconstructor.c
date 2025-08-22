modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionDescendIntoMine);
		actions.Insert(IAT_ActionAscendOutOfMine);
		actions.Insert(IAT_ActionCreateMineShaft);
		actions.Insert(IAT_ActionFortifyJunction);
    }
};