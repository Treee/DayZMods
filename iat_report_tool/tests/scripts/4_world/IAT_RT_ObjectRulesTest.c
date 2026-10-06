#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ObjectRulesTest : IAT_ScenarioCase
{
	void IAT_RT_ObjectRulesTest()
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ObjectManager";
		m_Name = "ObjectValidationAndClone";
	}

	override bool Execute()
	{
		Check(IAT_COTObjectRules.NameKey("  RiVeR  ") == "river", "Group keys trim and ignore case", "river", IAT_COTObjectRules.NameKey("  RiVeR  "));
		Check(!IAT_COTObjectRules.ValidName(" \t "), "Whitespace-only names are invalid", "false", IAT_COTObjectRules.ValidName(" \t ").ToString());
		string name;
		for (int index = 0; index < 80; index++)
			name += "a";
		Check(IAT_COTObjectRules.ValidName(name), "80-character name is accepted", "true", IAT_COTObjectRules.ValidName(name).ToString());
		string oversizedName = name + "a";
		bool oversizedAccepted = IAT_COTObjectRules.ValidName(oversizedName);
		Check(!oversizedAccepted, "81-character name is rejected", "false", oversizedAccepted.ToString());
		IAT_COTObjectGroup group = new IAT_COTObjectGroup;
		group.m_Name = "  River  ";
		IAT_COTObjectEntry entry = new IAT_COTObjectEntry;
		entry.m_ClassName = "Missing_IAT_Review_Class";
		entry.m_Position = "1000000 -1000000 0";
		entry.m_Orientation = "360000 -360000 0";
		entry.m_Scale = 0.01;
		group.m_Objects.Insert(entry);
		string error;
		Check(IAT_COTObjectRules.Validate(group, error, false), "Startup permits missing classes and exact numeric boundaries", "true", error);
		Check(group.m_Name == "River", "Validation trims stored name", "River", group.m_Name);
		Check(!IAT_COTObjectRules.Validate(group, error), "Editor rejects unavailable classes", "false", error);
		entry.m_Scale = 100;
		Check(IAT_COTObjectRules.Validate(group, error, false), "Maximum scale accepted", "true", error);
		entry.m_Scale = 100.01;
		Check(!IAT_COTObjectRules.Validate(group, error, false), "Above maximum scale rejected", "false", error);
		entry.m_Scale = 0;
		Check(!IAT_COTObjectRules.Validate(group, error, false), "Below minimum scale rejected", "false", error);
		entry.m_Scale = 1;
		entry.m_Position = "1000001 0 0";
		Check(!IAT_COTObjectRules.Validate(group, error, false), "Position outside boundary rejected", "false", error);
		entry.m_Position = "1 2 3";
		entry.m_Orientation = "360001 0 0";
		Check(!IAT_COTObjectRules.Validate(group, error, false), "Orientation outside boundary rejected", "false", error);
		entry.m_Orientation = "4 5 6";
		IAT_COTObjectGroup copy = group.Clone();
		copy.m_Name = "Copy";
		copy.m_Objects[0].m_Position = "7 8 9";
		Check(group.m_Name == "River" && entry.m_Position == "1 2 3", "Clone isolates group and entry edits", "River / 1 2 3", group.m_Name + " / " + entry.m_Position.ToString());
		Check(copy.m_Objects[0].m_ClassName == entry.m_ClassName && copy.m_Objects[0].m_Orientation == "4 5 6" && copy.m_Objects[0].m_Scale == 1, "Clone retains remaining fields", "true", (copy.m_Objects[0].m_ClassName == entry.m_ClassName).ToString());
		group.m_Objects.Insert(null);
		Check(!IAT_COTObjectRules.Validate(group, error, false), "Null entries rejected", "false", error);
		Check(!IAT_COTObjectRules.Validate(null, error), "Null groups rejected", "false", error);
		group.m_Objects.Clear();
		for (int objectIndex = 0; objectIndex < 2000; objectIndex++)
			group.m_Objects.Insert(entry);
		Check(IAT_COTObjectRules.Validate(group, error, false), "Exactly 2000 duplicate entries are allowed", "true", error);
		group.m_Objects.Insert(entry);
		Check(!IAT_COTObjectRules.Validate(group, error, false), "2001 entries are rejected", "false", error);
		return true;
	}
}
#endif
#endif
