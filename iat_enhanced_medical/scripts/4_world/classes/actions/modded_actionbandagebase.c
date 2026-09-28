modded class ActionBandageBase
{
	override void ApplyBandage(ItemBase item, PlayerBase player)
	{
		if (!Rag.Cast(item) && !BandageDressing.Cast(item))
		{
			super.ApplyBandage(item, player);
			return;
		}
		PluginIATMedical medical = PluginIATMedical.Get();
		// Do not consume supplies or close bleeding if attachment creation failed.
		if (!medical || !medical.ApplyDressing(player, item))
			return;
		PluginTransmissionAgents transmission = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		transmission.TransmitAgents(item, player, AGT_ITEM_TO_FLESH);
		if (item.HasQuantity())
			item.AddQuantity(-1, true);
		else
			item.DeleteSafe();
	}
}
