// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Tool variants exercise the public capability/damage contract.
class IAT_EM_TestNegativeTool : Pliers
{
	override float IAT_BulletExtractionHpDmg() { return -5; }
}
#endif
#endif
