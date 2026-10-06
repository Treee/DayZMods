#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_NoLegacyConfigTest : IAT_ScenarioCase
{
	void IAT_RT_NoLegacyConfigTest()
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ConfigRemoval";
		m_Name = "LegacyConfigTypeRemoved";
	}

	override bool Execute()
	{
		string legacyConfigName = "IAT_ReportToolConfig";
		typename legacyConfigType = legacyConfigName.ToType();
		bool absent = !legacyConfigType;
		Check(absent, "Legacy Report Tool config type is absent", "true", absent.ToString());
		return true;
	}
}
#endif
#endif
