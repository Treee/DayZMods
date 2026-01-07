modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
    	actions.Insert(IAT_ActionSelectPaintColor);
    	actions.Insert(IAT_ActionPaintCarvedSymbol);
    	actions.Insert(IAT_ActionSelectCarvedSymbolOption);
	}
};