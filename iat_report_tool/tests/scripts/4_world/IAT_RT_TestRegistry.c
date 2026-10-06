#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class IAT_ScenarioRegistry
{
	void IAT_ScenarioRegistry()
	{
		m_Cases.Insert(new IAT_RT_ObjectPayloadTest());
		m_Cases.Insert(new IAT_RT_ReportAbsenceTest());
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCConsecutiveReportsWithoutCooldown", 0));
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCLegacyTwoFieldReport", 1));
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCDiscordNameLengthLimit", 2));
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCMissingDescriptionRejected", 3));
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCUnknownCategoryRejected", 4));
		m_Cases.Insert(new IAT_RT_RPCReportTest("RPCNoSelectionRejected", 5));
		m_Cases.Insert(new IAT_RT_DiscordPayloadTest("DiscordTextJSONEscaping", 0));
		m_Cases.Insert(new IAT_RT_DiscordPayloadTest("DiscordEmbedFlattening", 1));
		m_Cases.Insert(new IAT_RT_DiscordPayloadTest("DiscordExactTruncationBoundary", 2));
		m_Cases.Insert(new IAT_RT_DiscordPayloadTest("DiscordAboveTruncationBoundary", 3));
		m_Cases.Insert(new IAT_RT_ObjectRulesTest());
		m_Cases.Insert(new IAT_RT_ObjectStoreTest());
		m_Cases.Insert(new IAT_RT_NoLegacyConfigTest());
		m_Cases.Insert(new IAT_RT_ReportFieldsTest(false));
		m_Cases.Insert(new IAT_RT_ReportFieldsTest(true));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("TerrainCategory", IAT_ReportType.TERRAIN, "TERRAIN", true));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("BugCategory", IAT_ReportType.BUG, "BUG"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("SuggestionCategory", IAT_ReportType.SUGGESTION, "SUGGESTION"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("PlayerMuteCategory", IAT_ReportType.PLAYER_MUTE, "PLAYER_MUTE"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("BadWordCategory", IAT_ReportType.BAD_WORD, "BAD_WORD"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("ExploitCategory", IAT_ReportType.EXPLOIT, "EXPLOIT"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("PlayerCategory", IAT_ReportType.PLAYER, "PLAYER"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("NoSelectionCategory", IAT_ReportType.NO_SELECTION, "NO_SELECTION"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("NegativeUnknownCategory", -1, "No Report Type"));
		m_Cases.Insert(new IAT_RT_ReportTypeTest("AboveRangeUnknownCategory", 8, "No Report Type"));
		m_Cases.Insert(new IAT_RT_ReportFormattingTest("StandardLinkAndTimestamp", "River", "76561198012345678", 1791203696, "[River](https://steamcommunity.com/profiles/76561198012345678)", "<t:1791203696:F>"));
		m_Cases.Insert(new IAT_RT_ReportFormattingTest("AlternateLinkAndEpochTimestamp", "Ash Pine", "76561198087654321", 0, "[Ash Pine](https://steamcommunity.com/profiles/76561198087654321)", "<t:0:F>"));
		m_Cases.Insert(new IAT_RT_ReportFormattingTest("EmptyLinkAndNegativeTimestamp", "", "", -1, "[](https://steamcommunity.com/profiles/)", "<t:-1:F>"));
		m_Cases.Insert(new IAT_RT_SubmitReportTest("TerrainSubmissionEmitsLocation", IAT_ReportType.TERRAIN, 1));
		m_Cases.Insert(new IAT_RT_SubmitReportTest("BugSubmissionHasNoTerrainLocation", IAT_ReportType.BUG, 0));
		m_Cases.Insert(new IAT_RT_SubmitReportTest("UnknownSubmissionHasNoTerrainLocation", -1, 0));
	}
}
#endif
#endif
