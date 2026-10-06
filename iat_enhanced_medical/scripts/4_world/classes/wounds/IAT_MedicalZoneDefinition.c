// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical lookup definition and coverage data.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

class IAT_MedicalZoneDefinition
{
	protected int m_Bit;
	protected int m_BoneMask;
	protected string m_FirstBone;
	protected string m_Slot;

	void IAT_MedicalZoneDefinition(int bit, string slot)
	{
		m_Bit = bit;
		m_Slot = slot;
	}

	void AddBone(string bone, int bit)
	{
		// Include this bone in the zone mask without changing its other bits.
		m_BoneMask |= bit;
		if (m_FirstBone == "")
			m_FirstBone = bone;
	}

	int GetBit()
	{
		return m_Bit;
	}

	int GetBoneMask()
	{
		return m_BoneMask;
	}

	string GetFirstBone()
	{
		return m_FirstBone;
	}

	string GetSlot()
	{
		return m_Slot;
	}
}
