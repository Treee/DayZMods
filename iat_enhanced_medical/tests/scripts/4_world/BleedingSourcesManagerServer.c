// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class BleedingSourcesManagerServer
{
	float m_IAT_EM_RetentionRoll = 0.2;
	override protected float IAT_GetRetentionRoll()
	{
		return m_IAT_EM_RetentionRoll;
	}
	void IAT_EM_TestResetClock() { m_Tick = 0; m_IAT_HealingTick = 0; m_IAT_RetainedBleedingTick = 0; m_DeleteList.Clear(); m_ProcessSourcesRemoval = false; }
}
#endif
#endif
