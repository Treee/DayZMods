#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Independent reader for the agreed external JSON keys.
class IAT_RT_ObjectEntrySnapshot
{
	string m_ClassName;
	vector m_Position;
	vector m_Orientation;
	float m_Scale;
}

class IAT_RT_ObjectGroupSnapshot
{
	string m_Name;
	bool m_Enabled = true;
	ref array<ref IAT_RT_ObjectEntrySnapshot> m_Objects = new array<ref IAT_RT_ObjectEntrySnapshot>;
}

class IAT_RT_ObjectPayloadTest : IAT_ScenarioCase
{
	void IAT_RT_ObjectPayloadTest()
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ObjectManager";
		m_Name = "ObjectPayloadUsesMemberNames";
	}

	override bool Execute()
	{
		string input = "{\"m_Name\":\"Review group\",\"m_Enabled\":false,\"m_Objects\":[{\"m_ClassName\":\"Land_Misc_Well_Pump_Blue\",\"m_Position\":[12,34,56],\"m_Orientation\":[90,10,-5],\"m_Scale\":2.5}]}";
		IAT_COTObjectGroup group;
		string error;
		bool loaded = JsonFileLoader<IAT_COTObjectGroup>.LoadData(input, group, error);
		Check(loaded && group != null, "Production group loads the agreed JSON shape", "true", loaded.ToString());
		if (!group)
			return true;

		string output;
		bool written = JsonFileLoader<IAT_COTObjectGroup>.MakeData(group, output, error, false);
		Check(written, "Production group serializes", "true", written.ToString());
		IAT_RT_ObjectGroupSnapshot snapshot;
		bool decoded = JsonFileLoader<IAT_RT_ObjectGroupSnapshot>.LoadData(output, snapshot, error);
		Check(decoded && snapshot != null, "Independent reader decodes the emitted payload", "true", decoded.ToString());
		if (!snapshot)
			return true;
		Check(snapshot.m_Name == "Review group", "Group name round-trips under m_Name", "Review group", snapshot.m_Name);
		Check(!snapshot.m_Enabled, "Disabled state round-trips under m_Enabled", "false", snapshot.m_Enabled.ToString());
		Check(snapshot.m_Objects.Count() == 1, "Object list round-trips under m_Objects", "1", snapshot.m_Objects.Count().ToString());
		if (snapshot.m_Objects.Count() == 1)
		{
			IAT_RT_ObjectEntrySnapshot entry = snapshot.m_Objects[0];
			Check(entry.m_ClassName == "Land_Misc_Well_Pump_Blue", "Class name round-trips under m_ClassName", "Land_Misc_Well_Pump_Blue", entry.m_ClassName);
			Check(entry.m_Position == "12 34 56", "Position round-trips under m_Position", "12 34 56", entry.m_Position.ToString());
			Check(entry.m_Orientation == "90 10 -5", "Orientation round-trips under m_Orientation", "90 10 -5", entry.m_Orientation.ToString());
			Check(entry.m_Scale == 2.5, "Scale round-trips under m_Scale", "2.5", entry.m_Scale.ToString());
		}
		TStringArray oldKeys = {"Name", "Enabled", "Objects", "ClassName", "Position", "Orientation", "Scale"};
		foreach (string oldKey : oldKeys)
		{
			bool oldKeyPresent = output.Contains("\"" + oldKey + "\"");
			Check(!oldKeyPresent, "Payload omits former key " + oldKey, "false", oldKeyPresent.ToString());
		}
		return true;
	}
}
#endif
#endif
