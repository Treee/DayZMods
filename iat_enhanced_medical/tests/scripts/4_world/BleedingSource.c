// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// The offline mission does not initialize the full bleeding HUD/particle
// lifecycle. Those vanilla rendering effects are outside this mod's contract.
// Keep real bleeding-source simulation, but suppress rendering for opted-in
// fixtures so renderer shutdown cannot invalidate medical assertions.
modded class BleedingSource
{
	override void CreateParticle()
	{
		if (m_Player && m_Player.m_IAT_EM_TestStateEnabled) return;
		super.CreateParticle();
	}
	override void StartSourceBleedingIndication()
	{
		if (m_Player && m_Player.m_IAT_EM_TestStateEnabled) return;
		super.StartSourceBleedingIndication();
	}
	override void StopSourceBleedingIndication(bool instant = false)
	{
		if (m_Player && m_Player.m_IAT_EM_TestStateEnabled) return;
		super.StopSourceBleedingIndication(instant);
	}
}
#endif
#endif
