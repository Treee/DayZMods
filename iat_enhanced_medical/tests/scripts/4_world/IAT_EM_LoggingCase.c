// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_LoggingCase : IAT_EM_PlayerCase
{
	void IAT_EM_LoggingCase() { m_Suite = "Diagnostics"; m_Name = "MedicalSnapshotsDoNotMutateState"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		m_State.m_Bullets = 5; m_State.m_DressedWounds = 256;
		m_Medical.m_LoggingEnabled = false;
		m_Medical.LogSnapshot(m_Player, "EM_TEST_DISABLED");
		m_Medical.m_LoggingEnabled = true;
		m_Medical.LogEvent(null, "EM_TEST_NULL");
		m_Medical.LogSnapshot(null, "EM_TEST_NULL_SNAPSHOT");
		m_Medical.LogSnapshot(m_Player, "EM_TEST_SNAPSHOT");
		EqualInt(m_State.m_Bullets, 5, "Snapshot preserves bullets");
		EqualInt(m_State.m_DressedWounds, 256, "Snapshot preserves dressed history");
		EqualInt(m_Player.GetBleedingBits(), 0, "Logging creates no active source");
		// Exact emitted fields are checked in the run evidence; no log format
		// changes are needed to make medical logic testable.
		return true;
	}
}
#endif
#endif
