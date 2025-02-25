modded class InspectMenuNew
{
	override Widget Init()
	{
		layoutRoot = super.Init();

		Widget element = Widget.Cast( GetGame().GetWorkspace().CreateWidgets( "iat_corrosive_biogas/scripts/5_mission/layouts/inventory_new/day_z_inventory_new_inspect_corrosion.layout", layoutRoot ) );
		Widget mainInfoPanelWidget = layoutRoot.FindAnyWidget("InventoryInfoPanelWidget");
		mainInfoPanelWidget.AddChild(element);

		return layoutRoot;
	}

	override void SetItem(EntityAI item)
	{
		super.SetItem(item);
		if (item)
		{
			InspectMenuNew.UpdateItemInfoCorrosion(layoutRoot, item);
		}
	}

	static void UpdateItemInfoCorrosion(Widget root_widget, EntityAI item)
	{
		if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;

		ItemBase item_base;
		if (Class.CastTo(item_base, item) && item_base.HasCorrosiveAgents())
		{
			// agents, show green
			WidgetTrySetText(root_widget, "ItemCorrosionWidget", "Corrosion", Colors.COLOR_LIVONIA_EMERALD_GREEN);
		}
		else
		{
			// no agents
			WidgetTrySetText(root_widget, "ItemCorrosionWidget", "");
		}
	}
};