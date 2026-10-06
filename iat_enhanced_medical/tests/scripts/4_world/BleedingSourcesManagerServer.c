// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class BleedingSourcesManagerServer
{
	void IAT_EM_TestResetClock() { m_Tick = 0; m_IAT_HealingTick = 0; m_DeleteList.Clear(); m_ProcessSourcesRemoval = false; }
}
#endif
#endif
