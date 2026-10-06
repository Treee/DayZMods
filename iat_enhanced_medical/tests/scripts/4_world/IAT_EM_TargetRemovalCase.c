// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_TargetRemovalCase : IAT_EM_PatientCase
{
	bool m_Acted;
	void IAT_EM_TargetRemovalCase(string caseName, int mode) { m_Suite = "ManualRemoval"; m_Name = "KnifeRemovalAffectsPatientAndAllCoveredWounds"; }
	override bool Execute()
	{
		if (!m_Ready || !m_Patient) return true;
		int arm = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int forearm = m_Medical.IAT_GetBulletBoneBit("leftforearm");
		if (!m_Acted)
		{
			EntityAI dressing = m_Patient.GetInventory().CreateAttachmentEx("WZ_Bandage_LArm", InventorySlots.GetSlotIdFromString("WZBandageLArm"));
			Check(dressing != null, "Attach patient's dressing", "true", "checked");
			if (!dressing) return true;
			m_Patient.SetHealth("LeftArm", "Blood", m_Patient.GetMaxHealth("LeftArm", "Blood") * 0.25);
			m_Patient.IAT_GetMedicalState().m_DressedWounds = arm | forearm;
			ItemBase knife = Item("HuntingKnife");
			if (!knife) return true;
			ActionData data = new ActionData;
			data.m_Player = m_Player; data.m_MainItem = knife;
			data.m_Target = new ActionTarget(m_Patient, null, -1, "0 0 0", 0);
			IAT_ActionRemoveBandageTarget action = new IAT_ActionRemoveBandageTarget;
			Check(action.ActionCondition(m_Player, data.m_Target, knife), "Dressed patient offered even without actor dressing", "true", "checked");
			action.IAT_Remove(data, m_Patient);
			m_Acted = true;
			return false;
		}
		// The independent offline patient needs its queued inventory deletion advanced.
		m_Patient.UpdateDelete();
		if (m_Patient.FindAttachmentBySlotName("WZBandageLArm"))
			return false;
		m_Medical.UpdateHealing(m_Patient);
		Check(m_Patient.FindAttachmentBySlotName("WZBandageLArm") == null, "Patient dressing removed", "null", "checked");
		EqualInt(m_Patient.GetBleedingBits(), arm | forearm, "All patient's recorded zone wounds reopen");
		EqualInt(m_Player.GetBleedingBits(), 0, "Actor does not bleed");
		return true;
	}
}
#endif
#endif
