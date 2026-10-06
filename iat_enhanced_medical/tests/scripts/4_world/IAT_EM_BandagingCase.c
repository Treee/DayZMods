// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_BandagingCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_BandagingCase(string caseName, int mode) { m_Suite = "Bandaging"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		ItemBase material = Item("BandageDressing");
		if (!material) return true;
		material.SetQuantity(4);
		material.SetCleanness(1);
		Blood("LeftArm", 0.25); Blood("LeftHand", 0.25);
		if (m_Mode == 0)
		{
			Check(!m_Medical.PrepareDressing(m_Player, material), "No active source has no dressing target", "false", "checked");
			Near(material.GetQuantity(), 4, "No source does not consume material");
			return true;
		}
		m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
		m_Manager.AttemptAddBleedingSourceBySelection("leftforearmroll");
		int armBit = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int handBit = m_Medical.IAT_GetBulletBoneBit("leftforearmroll");
		EqualInt(m_Player.GetBleedingBits(), armBit | handBit, "Two independent bleeding fixtures");
		ActionBandageBase action = new ActionBandageBase;
		if (m_Mode == 1)
		{
			action.ApplyBandage(material, m_Player);
			EntityAI first = m_Player.FindAttachmentBySlotName("WZBandageLArm");
			Check(first != null, "Treatment creates regional attachment", "true", (first != null).ToString());
			if (first) m_Items.Insert(first);
			EqualInt(m_Player.GetBleedingBits(), handBit, "First cycle closes exactly one highest-flow source");
			EqualInt(m_State.m_DressedWounds, armBit, "First cycle records original bone");
			Near(material.GetQuantity(), 3, "First cycle consumes one use");
			action.ApplyBandage(material, m_Player);
			EqualInt(m_Player.GetBleedingBits(), 0, "Second cycle closes remaining source");
			EqualInt(m_State.m_DressedWounds, armBit | handBit, "Shared dressing records both treated bones");
			Check(m_Player.FindAttachmentBySlotName("WZBandageLArm") == first, "Second treatment reuses attachment", "same attachment", "checked");
			Near(material.GetQuantity(), 2, "Each completed cycle consumes one use");
			return true;
		}
		if (m_Mode == 2)
		{
			EntityAI ruined = Dress("LeftArm");
			if (!ruined) return true;
			ruined.SetHealth("", "Health", 0);
			action.ApplyBandage(material, m_Player);
			EqualInt(m_Player.GetBleedingBits(), armBit | handBit, "Ruined occupied slot blocks closure");
			Near(material.GetQuantity(), 4, "Blocked treatment consumes no material");
			EqualInt(m_State.m_DressedWounds, 0, "Blocked treatment records no history");
			return true;
		}
		if (m_Mode == 3)
		{
			material.SetHealth("", "Health", 0);
			Check(!m_Medical.PrepareDressing(m_Player, material), "Ruined material rejected", "false", "checked");
			Check(!m_Medical.PrepareDressing(m_Player, null), "Absent material rejected", "false", "checked");
			EqualInt(m_Player.GetBleedingBits(), armBit | handBit, "Invalid material preserves bleeding");
			return true;
		}
		if (m_Mode == 4)
		{
			Check(m_Medical.PrepareDressing(m_Player, material), "Dressing preparation succeeds", "true", "checked");
			ItemBase dressing = ItemBase.Cast(m_Player.FindAttachmentBySlotName("WZBandageLArm"));
			if (dressing) m_Items.Insert(dressing);
			Check(dressing && dressing.GetCleanness() == 1, "Preparation transfers material cleanness", "1", "checked");
			EqualInt(m_Player.GetBleedingBits(), armBit | handBit, "Preparation alone closes no source");
			EqualInt(m_State.m_DressedWounds, 0, "Preparation alone records no history");
			Near(material.GetQuantity(), 4, "Preparation alone consumes no use");
			return true;
		}
		if (m_Mode == 5)
		{
			m_Medical.OnBleedingSourceClosed(m_Player, "leftarm", material);
			EqualInt(m_State.m_DressedWounds, 0, "Closure without covering dressing has no history");
			if (!Dress("LeftArm")) return true;
			m_Medical.OnBleedingSourceClosed(m_Player, "leftarm", null);
			EqualInt(m_State.m_DressedWounds, 0, "Natural closure creates no dressed history");
			m_State.m_DressedWounds = handBit;
			m_Medical.OnBleedingSourceClosed(m_Player, "leftarm", material);
			EqualInt(m_State.m_DressedWounds, armBit | handBit, "Treatment preserves earlier dressed history");
			m_Medical.OnBleedingSourceAdded(m_Player, "leftarm");
			EqualInt(m_State.m_DressedWounds, handBit, "Fresh source clears only its treated bone");
		}
		return true;
	}
}
#endif
#endif
