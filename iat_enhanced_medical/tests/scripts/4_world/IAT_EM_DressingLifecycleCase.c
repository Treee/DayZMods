// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_DressingLifecycleCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_DressingLifecycleCase(string caseName, int mode) { m_Suite = "Dressings"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int armBit = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int handBit = m_Medical.IAT_GetBulletBoneBit("leftforearmroll");
		int otherBit = m_Medical.IAT_GetBulletBoneBit("rightleg");
		string slot = "WZBandageLArm";
		if (m_Mode == 0)
		{
			// Attaching a dressing never treats an active source by itself.
			bool added = m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
			Check(added, "Create active arm bleed", "true", added.ToString());
			if (!Dress("LeftArm")) return true;
			Check((m_Player.GetBleedingBits() & armBit) != 0, "Manual attachment preserves active bleed", "nonzero arm bit", m_Player.GetBleedingBits().ToString());
			EqualInt(m_State.m_DressedWounds, 0, "Manual attachment does not invent treated history");
			return true;
		}
		EntityAI dressing;
		if (m_Mode != 1) dressing = Dress("LeftArm");
		if (m_Mode != 1 && !dressing) return true;
		Blood("LeftArm", 0.75); Blood("LeftHand", 0.75); Blood("RightLeg", 0.75);
		m_State.m_DressedWounds = armBit | handBit | otherBit;
		if (m_Mode == 1 || m_Mode == 2)
		{
			if (dressing) dressing.SetHealth("", "Health", 0);
			m_Medical.ReopenDressedWounds(m_Player, slot);
			Check((m_Player.GetBleedingBits() & (armBit | handBit)) == (armBit | handBit), "Missing or ruined dressing reopens both original locations", (armBit | handBit).ToString(), m_Player.GetBleedingBits().ToString());
			EqualInt(m_State.m_DressedWounds, otherBit, "Reopening clears only successfully reopened region");
			Check((m_Player.GetBleedingBits() & otherBit) == 0, "Reopening stays within dressing coverage", "0", (m_Player.GetBleedingBits() & otherBit).ToString());
			return true;
		}
		if (m_Mode == 3)
		{
			m_Medical.ReopenDressedWounds(m_Player, slot);
			EqualInt(m_Player.GetBleedingBits(), 0, "Usable dressing prevents reopening");
			EqualInt(m_State.m_DressedWounds, armBit | handBit | otherBit, "Covered wound history preserved");
			return true;
		}
		if (m_Mode == 4)
		{
			Blood("LeftArm", 1);
			m_Medical.UpdateHealing(m_Player);
			Check((m_State.m_DressedWounds & armBit) == 0, "Healing clears completed bone", "0", (m_State.m_DressedWounds & armBit).ToString());
			Check((m_State.m_DressedWounds & handBit) != 0, "Shared hand history survives arm healing", "true", (m_State.m_DressedWounds & handBit).ToString());
			Check(!m_Medical.IAT_EM_TestCanRemove(m_Player, slot), "Shared dressing waits for hand", "false", "checked");
			return true;
		}
		Blood("LeftArm", 1); Blood("LeftHand", 1);
		if (m_Mode == 5) m_Medical.RecordBullet(m_Player, "leftarm");
		if (m_Mode == 6) m_Manager.AttemptAddBleedingSourceBySelection("leftforearmroll");
		bool removable = m_Medical.IAT_EM_TestCanRemove(m_Player, slot);
		Check(removable == false, "Deletion requires full region, no bullets, no active bleed", "false", removable.ToString());
		Check(m_Medical.HasHealedBandage(m_Player) == false, "Blocked dressing does not schedule cleanup", "false", m_Medical.HasHealedBandage(m_Player).ToString());
		m_Medical.RemoveHealedBandages(m_Player);
		Check(m_Player.FindAttachmentBySlotName(slot) == dressing, "Blocked dressing retained", "same attachment", "checked");
		return true;
	}
}
#endif
#endif
