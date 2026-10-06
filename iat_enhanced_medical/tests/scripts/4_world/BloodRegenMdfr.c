// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class BloodRegenMdfr
{
	float IAT_EM_TestRate(PlayerBase player) { return IAT_GetBloodRegenRate(player); }
}
#endif
#endif
