// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ExtractionCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_ExtractionCase(string caseName, int mode) { m_Suite = "Extraction"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int arm = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int forearm = m_Medical.IAT_GetBulletBoneBit("leftforearm");
		int leg = m_Medical.IAT_GetBulletBoneBit("rightleg");
		if (m_Mode == 0)
		{
			m_State.m_Bullets = arm | forearm | leg;
			m_State.m_DressedWounds = arm | leg;
			string zone;
			bool extracted = m_Medical.ExtractBullet(m_Player, zone);
			Check(extracted && zone == "LeftArm", "Extract first registered retained location", "true/LeftArm", extracted.ToString() + "/" + zone);
			EqualInt(m_State.m_Bullets, forearm | leg, "Extract exactly one location");
			Check(m_Medical.HasBulletInZone(m_Player, "LeftArm"), "Second location still blocks same zone", "true", "checked");
			m_Medical.ExtractBullet(m_Player, zone);
			EqualInt(m_State.m_Bullets, leg, "Second extraction clears remaining arm location");
			Check(!m_Medical.HasBulletInZone(m_Player, "LeftArm"), "Cleared arm can regenerate", "false", "checked");
			m_Medical.ExtractBullet(m_Player, zone);
			Check(zone == "RightLeg", "Extraction follows registration order across zones", "RightLeg", zone);
			EqualInt(m_State.m_DressedWounds, 0, "Fresh extraction bleeds clear previous treatment at extracted bones");
			zone = "old";
			Check(!m_Medical.ExtractBullet(m_Player, zone) && zone == "", "Empty extraction resets output and fails", "false/empty", zone);
			zone = "old";
			Check(!m_Medical.ExtractBullet(null, zone) && zone == "", "Absent patient fails safely", "false/empty", zone);
			return true;
		}
		string type = "Pliers";
		if (m_Mode == 3) type = "IAT_EM_TestNegativeTool";
		if (m_Mode == 4) type = "IAT_EM_TestZeroTool";
		if (m_Mode == 6) type = "BandageDressing";
		ItemBase tool = Item(type);
		if (!tool) return true;
		if (m_Mode == 5) tool.SetHealth("", "Health", 0);
		if (m_Mode != 2) m_State.m_Bullets = arm | leg;
		m_Player.SetHealth("", "Health", 90);
		ActionData data = new ActionData;
		data.m_Player = m_Player; data.m_MainItem = tool;
		IAT_ActionExtractBulletSelf action = new IAT_ActionExtractBulletSelf;
		if (m_Mode == 7) data.m_MainItem = null;
		action.IAT_Extract(data, m_Player);
		float expectedHealth = 90;
		int expectedMask = arm | leg;
		if (m_Mode == 1) { expectedHealth = 80; expectedMask = leg; }
		if (m_Mode == 2) expectedMask = 0;
		if (m_Mode == 3 || m_Mode == 4) expectedMask = leg;
		Near(m_Player.GetHealth("", "Health"), expectedHealth, "Damage only after successful extraction; negative damage cannot heal");
		EqualInt(m_State.m_Bullets, expectedMask, "Completion extracts only with a usable capable tool");
		return true;
	}
}
#endif
#endif
