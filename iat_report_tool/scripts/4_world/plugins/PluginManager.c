modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("IAT_PluginReportToolServer", false, true);
		RegisterPlugin("IAT_PluginReportToolClient", true, false);
	}
};
