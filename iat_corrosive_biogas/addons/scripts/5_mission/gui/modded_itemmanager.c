modded class ItemManager
{
	void ItemManager(Widget root)
	{
		Widget element = Widget.Cast( GetGame().GetWorkspace().CreateWidgets( "iat_corrosive_biogas/scripts/5_mission/layouts/inventory_new/day_z_inventory_new_tooltip_corrosion.layout", root ) );
		m_TooltipWidget.AddChild(element);
	}

	override void PrepareTooltip(EntityAI item, int x = 0, int y = 0)
	{
		super.PrepareTooltip(item, x, y);

		// vanilla short circuit
		if( IsDragging() || !item )
		{
			return;
		}
		// our custom logic
		if ( item.IsInherited( InventoryItem ) )
		{
			InspectMenuNew.UpdateItemInfoCorrosion(m_TooltipWidget, item);
		}
	}
};