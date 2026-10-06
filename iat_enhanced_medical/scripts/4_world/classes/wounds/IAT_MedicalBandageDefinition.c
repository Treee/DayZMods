// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical lookup definition and coverage data.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

class IAT_MedicalBandageDefinition
{
	protected string m_ItemClass;
	protected ref TStringArray m_Zones = new TStringArray;
	protected ref TStringArray m_BandageBones = new TStringArray;

	void IAT_MedicalBandageDefinition(string itemClass)
	{
		m_ItemClass = itemClass;
	}

	void AddZone(string zone)
	{
		m_Zones.Insert(zone);
	}

	void AddBone(string bone)
	{
		m_BandageBones.Insert(bone);
	}

	string GetItemClass()
	{
		return m_ItemClass;
	}

	TStringArray GetZones()
	{
		return m_Zones;
	}

	TStringArray GetBones()
	{
		return m_BandageBones;
	}
}
