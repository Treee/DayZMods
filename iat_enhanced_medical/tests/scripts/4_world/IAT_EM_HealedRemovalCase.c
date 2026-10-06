// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Separate once-only action from frame-driven deletion observation.
class IAT_EM_HealedRemovalCase : IAT_EM_PlayerCase
{
	bool m_Acted;
	void IAT_EM_HealedRemovalCase() { m_Suite = "Dressings"; m_Name = "HealedDressingIsDeletedWithoutDrop"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		if (!m_Acted)
		{
			if (!Dress("LeftArm")) return true;
			Check(m_Medical.HasHealedBandage(m_Player), "Fully healed dressing requests cleanup", "true", "checked");
			m_Medical.RemoveHealedBandages(m_Player);
			m_Acted = true;
			return false;
		}
		if (m_Player.FindAttachmentBySlotName("WZBandageLArm")) return false;
		EntityAI removed = m_Items[0];
		if (removed) return false;
		Check(removed == null, "Healed dressing object deleted", "null", (removed != null).ToString());
		return true;
	}
}
#endif
#endif
