// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Register the server-side medical plugin.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("IAT_PluginMedical", false, true);
	}
}
