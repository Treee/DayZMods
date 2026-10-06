// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ManualRemovalCase : IAT_EM_PlayerCase
{
	int m_Mode;
	bool m_Acted;
	int m_Expected;
	void IAT_EM_ManualRemovalCase(string name, int mode) { m_Suite = "ManualRemoval"; m_Name = name; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int arm = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int forearm = m_Medical.IAT_GetBulletBoneBit("leftforearm");
		int hand = m_Medical.IAT_GetBulletBoneBit("leftforearmroll");
		if (!m_Acted)
		{
			if (!Dress("LeftArm") || !Dress("RightLeg")) return true;
			Blood("RightLeg", 0.25);
			float fraction = 0.25;
			if (m_Mode == 1) fraction = 0.5;
			if (m_Mode == 2) fraction = 0.75;
			if (m_Mode == 3 || m_Mode == 4) fraction = 1;
			Blood("LeftArm", fraction); Blood("LeftHand", fraction);
			m_State.m_DressedWounds = arm | forearm | hand;
			if (m_Mode == 4) m_Medical.RecordBullet(m_Player, "leftarm");
			ItemBase knife = Item("HuntingKnife");
			if (!knife) return true;
			if (m_Mode == 5) knife.SetHealth("", "Health", 0);
			if (m_Mode == 6) knife = Item("Pliers");
			if (m_Mode == 7) m_Player.FindAttachmentBySlotName("WZBandageLArm").SetHealth("", "Health", 0);
			ActionData data = new ActionData;
			data.m_Player = m_Player; data.m_MainItem = knife;
			IAT_ActionRemoveBandageSelf action = new IAT_ActionRemoveBandageSelf;
			action.IAT_Remove(data, m_Player);
			m_Expected = arm | forearm | hand;
			if (m_Mode == 3 || m_Mode == 5 || m_Mode == 6) m_Expected = 0;
			if (m_Mode == 4) m_Expected = arm | forearm;
			m_Acted = true;
			return false;
		}
		bool blocked = m_Mode == 5 || m_Mode == 6;
		if (!blocked)
		{
			// Advance vanilla inventory housekeeping; queued removal is not immediate.
			m_Player.UpdateDelete();
			if (m_Player.FindAttachmentBySlotName("WZBandageLArm"))
				return false;
			// Dedicated detach hooks do this in play; also covered by the healing tick.
			m_Medical.UpdateHealing(m_Player);
		}

		Check((m_Player.FindAttachmentBySlotName("WZBandageLArm") != null) == blocked, "Completion removes dressing unless tool is invalid", blocked.ToString(), "checked");
		Check(m_Player.FindAttachmentBySlotName("WZBandageRLeg") != null, "One completion preserves another regional dressing", "true", "checked");
		EqualInt(m_Player.GetBleedingBits(), m_Expected, "All unhealed recorded sources under removed dressing reopen together");
		Near(m_Player.GetHealth("", "Health"), m_Health, "Cutting dressing causes no direct Health damage");
		return true;
	}
}
#endif
#endif
