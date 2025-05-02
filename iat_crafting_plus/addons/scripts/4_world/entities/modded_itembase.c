modded class ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionCraftOnWorkbench);
	}

	// see iat_craftingbenchbase.c [OnAttachmentQuantityChanged] for why this is here
	override void OnVariablesSynchronized()
	{
		// make sure it is client side
		if (!GetGame().IsDedicatedServer())
		{
			if (m_VarQuantity != m_VarQuantityPrev)
			{
				IAT_CraftingPlus_CraftingBench_Base workbench;
				if (Class.CastTo(workbench, GetHierarchyParent()))
				{
					// PrintFormat("================================================ synicng: %1", GetType());
					workbench.TryCheckRecipes();
				}
			}
		}
		// we do our thing before super because super will set previosu to current and ignore our logic
		super.OnVariablesSynchronized();
	}
};