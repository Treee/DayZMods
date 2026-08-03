modded class PluginManager
{
	override void Init()
	{
		super.Init();
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 	    Client Server
		//----------------------------------------------------------------------
		RegisterPlugin("IAT_PluginReportToolServer", false, true);
		RegisterPlugin("IAT_PluginReportToolClient", true, false);
	}
};