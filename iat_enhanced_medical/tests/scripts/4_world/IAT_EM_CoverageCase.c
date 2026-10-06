// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_CoverageCase : IAT_EM_PlayerCase
{
	string m_Zone, m_Slot, m_Class, m_First;
	int m_ZoneBit, m_Mask;
	void IAT_EM_CoverageCase(string zone, int bit, int mask, string slot, string itemClass, string first)
	{
		m_Suite = "Definitions"; m_Name = "Coverage_" + zone;
		m_Zone = zone; m_ZoneBit = bit; m_Mask = mask; m_Slot = slot; m_Class = itemClass; m_First = first;
	}
	override bool Execute()
	{
		if (!m_Ready) return true;
		EqualInt(m_Medical.IAT_GetDamageZoneBit(m_Zone), m_ZoneBit, "Stable damage-zone bit");
		EqualInt(m_Medical.IAT_GetZoneBoneMask(m_Zone), m_Mask, "Exact zone selection mask");
		Check(m_Medical.IAT_GetFirstBoneForZone(m_Zone) == m_First, "Hit fallback uses first registered bone", m_First, m_Medical.IAT_GetFirstBoneForZone(m_Zone));
		Check(m_Medical.IAT_GetBandageSlot(m_Zone) == m_Slot, "Dressing coverage slot", m_Slot, m_Medical.IAT_GetBandageSlot(m_Zone));
		Check(m_Medical.IAT_GetBandageClass(m_Zone) == m_Class, "Dressing class", m_Class, m_Medical.IAT_GetBandageClass(m_Zone));
		TStringArray zones = m_Medical.IAT_GetBandageZones(m_Slot);
		Check(zones.Find(m_Zone) >= 0, "Zone listed in regional coverage", "present", zones.Find(m_Zone).ToString());
		return true;
	}
}
#endif
#endif
