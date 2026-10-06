// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical lookup definition and coverage data.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

class IAT_MedicalBoneDefinition
{
	protected int m_Bit;
	protected string m_Zone;

	void IAT_MedicalBoneDefinition(int bit, string zone)
	{
		m_Bit = bit;
		m_Zone = zone;
	}

	int GetBit()
	{
		return m_Bit;
	}

	string GetZone()
	{
		return m_Zone;
	}
}
