// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! R-005: extraction opens a treatable wound and delays dressing cleanup.
// Integration: diagnostic engine fixture; restores player state.
// Documentation: iat_enhanced_medical/tests/VERIFICATION.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ExtractionBleedCase : IAT_EM_PlayerCase
{
	protected int m_Mode;

	void IAT_EM_ExtractionBleedCase(string caseName, int mode)
	{
		m_Suite = "Extraction";
		m_Name = caseName;
		m_Mode = mode;
	}

	override bool Execute()
	{
		if (!m_Ready) return true;
		EntityAI dressing = Dress("LeftArm");
		if (!dressing) return true;
		int bit = m_Medical.IAT_GetBulletBoneBit("leftarm");
		if (m_Mode != 1) m_Medical.RecordBullet(m_Player, "leftarm");
		string zone;
		bool extracted = m_Medical.ExtractBullet(m_Player, zone);
		if (m_Mode == 1)
		{
			Check(!extracted, "Empty extraction fails", "false", extracted.ToString());
			EqualInt(m_Player.GetBleedingBits(), 0, "Empty extraction opens no bleed");
			Near(m_Player.GetHealth("LeftArm", "Blood"), 100, "Empty extraction causes no regional damage");
			return true;
		}
		Check(extracted && zone == "LeftArm", "Extraction succeeds at retained bone", "true/LeftArm", extracted.ToString() + "/" + zone);
		EqualInt(m_State.m_Bullets, 0, "Retained bullet cleared");
		Check((m_Player.GetBleedingBits() & bit) != 0, "Extraction opens bleed despite attached dressing", "nonzero bone bit", m_Player.GetBleedingBits().ToString());
		Check(!m_Medical.IAT_EM_TestCanRemove(m_Player, m_Medical.IAT_GetBandageSlot("LeftArm")), "Active extraction wound prevents healed cleanup", "false", "checked");
		if (m_Mode == 0) return true;

		// Let the real source lose regional Blood before treating it.
		m_Manager.OnTick(4);
		Check(m_Player.GetHealth("LeftArm", "Blood") < 100, "Extraction bleed produces regional injury", "below 100", m_Player.GetHealth("LeftArm", "Blood").ToString());
		ItemBase material = Item("BandageDressing");
		if (!material) return true;
		m_Manager.RemoveMostSignificantBleedingSourceEx(material);
		EqualInt(m_Player.GetBleedingBits(), 0, "Bandaging closes extraction bleed");
		Check((m_State.m_DressedWounds & bit) != 0, "Extraction wound is recorded after treatment", "nonzero", m_State.m_DressedWounds.ToString());
		m_Medical.RemoveHealedBandages(m_Player);
		Check(m_Player.FindAttachmentBySlotName(m_Medical.IAT_GetBandageSlot("LeftArm")) == dressing, "Dressing remains until full zone recovery", "same dressing", "checked");
		if (m_Mode == 2)
		{
			ItemBase knife = Item("HuntingKnife");
			if (!knife) return true;
			ActionData data = new ActionData;
			data.m_Player = m_Player;
			data.m_MainItem = knife;
			IAT_ActionRemoveBandageSelf action = new IAT_ActionRemoveBandageSelf;
			action.IAT_Remove(data, m_Player);
			// DeleteSafe may queue inventory removal; diagnostic deletion delivers detach now.
			if (dressing) g_Game.ObjectDelete(dressing);
			m_Medical.UpdateHealing(m_Player);
			Check((m_Player.GetBleedingBits() & bit) != 0, "Manual removal before recovery reopens extraction wound", "nonzero bone bit", m_Player.GetBleedingBits().ToString());
		}
		else
		{
			Blood("LeftArm", 1);
			m_Medical.UpdateHealing(m_Player);
			Check(m_Medical.IAT_EM_TestCanRemove(m_Player, m_Medical.IAT_GetBandageSlot("LeftArm")), "Fully recovered zone permits automatic removal", "true", "checked");
		}
		return true;
	}
}
#endif
#endif
