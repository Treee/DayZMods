// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Expose protected boundaries without replacing their implementations.
modded class IAT_PluginMedical
{
	string IAT_EM_TestLogBones(int mask) { return LogBones(mask); }
	string IAT_EM_TestResolve(PlayerBase player, string selection) { return IAT_ResolveBleedingSelectionZone(player, selection); }
	bool IAT_EM_TestCanRemove(PlayerBase player, string slot) { return CanRemoveBandage(player, slot); }
	int IAT_EM_TestSetRegisteredMask(int mask)
	{
		int previous = m_RegisteredBoneMask;
		m_RegisteredBoneMask = mask;
		return previous;
	}
}
#endif
#endif
