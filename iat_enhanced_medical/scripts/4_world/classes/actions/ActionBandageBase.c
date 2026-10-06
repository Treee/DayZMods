// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Knife bandage-removal capability and explicit actions.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class ActionBandageBase
{
	override void ApplyBandage(ItemBase item, PlayerBase player)
	{
		IAT_PluginMedical medical;
		if (!Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) || !medical.PrepareDressing(player, item))
			return;
		// Vanilla closes one source, handles infection, and consumes the material.
		super.ApplyBandage(item, player);
	}
};
