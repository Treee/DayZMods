// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Offline DayZDiag is authoritative but not dedicated. This opt-in fixture
// supplies ONLY the state normally created on a dedicated server. All medical
// decisions, bleeding sources, inventory and health calls remain production.
modded class PlayerBase
{
	bool m_IAT_EM_TestStateEnabled;
	IAT_MedicalState IAT_EM_TestOriginalState() { return super.IAT_GetMedicalState(); }
	override IAT_MedicalState IAT_GetMedicalState()
	{
		if (!m_IAT_EM_TestStateEnabled)
			return super.IAT_GetMedicalState();
		if (!m_IAT_MedicalState)
			m_IAT_MedicalState = new IAT_MedicalState;
		return m_IAT_MedicalState;
	}
}
#endif
#endif
