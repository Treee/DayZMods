modded class InspectMenuNew
{
	static void UpdateItemInfoCorrosion(Widget root_widget, EntityAI item)
	{
		if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;

		float temperature;
		ObjectTemperatureState temperatureState;
		ItemBase item_base = ItemBase.Cast(item);

		if (item_base && item.CanHaveTemperature())
		{
			temperature = item_base.GetTemperature();
			temperatureState = ObjectTemperatureState.GetStateData(temperature);
		}

		if (!temperatureState || temperatureState.m_State == EObjectTemperatureState.NEUTRAL)
			WidgetTrySetText(root_widget, "ItemTemperatureWidget", "");
		else
			WidgetTrySetText(root_widget, "ItemTemperatureWidget", temperatureState.m_LocalizedName, temperatureState.m_Color);
	}
};