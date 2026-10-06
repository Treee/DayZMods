#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Redirect storage to per-run data without exposing production helpers.
class IAT_RT_IsolatedObjectStore : IAT_COTObjectStore
{
	void IAT_RT_IsolatedObjectStore(string directory)
	{
		m_Directory = directory;
	}
}

class IAT_RT_ObjectStoreTest : IAT_ScenarioCase
{
	protected ref IAT_RT_IsolatedObjectStore m_Store;
	protected string m_Directory = "$profile:IAT_RT_Review/";

	void IAT_RT_ObjectStoreTest()
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ObjectManager";
		m_Name = "ObjectStoreSaveRenameDeleteReload";
	}

	override bool Prepare()
	{
		MakeDirectory(m_Directory);
		m_Store = new IAT_RT_IsolatedObjectStore(m_Directory);
		m_Store.Load();
		return true;
	}

	override bool Execute()
	{
		IAT_COTObjectGroup first = new IAT_COTObjectGroup;
		first.m_Name = "First";
		first.m_Enabled = false;
		IAT_COTObjectEntry entry = new IAT_COTObjectEntry;
		entry.m_ClassName = "Land_Misc_Well_Pump_Blue";
		entry.m_Position = "12 34 56";
		entry.m_Orientation = "90 10 -5";
		entry.m_Scale = 2.5;
		first.m_Objects.Insert(entry);
		string error;
		Check(m_Store.Save(first, "", error), "Save first disabled group", "true", error);
		IAT_COTObjectGroup second = new IAT_COTObjectGroup;
		second.m_Name = "Second";
		second.m_Enabled = false;
		Check(m_Store.Save(second, "", error), "Save another group", "true", error);
		first.m_Name = " second ";
		Check(!m_Store.Save(first, "First", error), "Rename cannot collide with a different group", "false", error);
		first.m_Name = "Renamed";
		Check(m_Store.Save(first, "First", error), "Rename existing group", "true", error);
		first.m_Name = "Caller edit";
		Check(m_Store.FindGroup("renamed") == 0 && m_Store.FindGroup("First") == -1, "Save clones input and removes old name", "0 / -1", m_Store.FindGroup("renamed").ToString() + " / " + m_Store.FindGroup("First").ToString());
		IAT_RT_IsolatedObjectStore reloaded = new IAT_RT_IsolatedObjectStore(m_Directory);
		reloaded.Load();
		Check(reloaded.GetGroups().Count() == 2 && reloaded.FindGroup("RENAMED") == 0 && reloaded.FindGroup("Second") == 1, "Reload preserves both groups and order", "2 / 0 / 1", reloaded.GetGroups().Count().ToString());
		array<ref IAT_COTObjectGroup> reloadedGroups = reloaded.GetGroups();
		if (reloadedGroups.Count() == 2)
		{
			IAT_COTObjectGroup savedGroup = reloadedGroups[0];
			Check(!savedGroup.m_Enabled, "Reload retains disabled state under the new schema", "false", savedGroup.m_Enabled.ToString());
			Check(savedGroup.m_Objects.Count() == 1, "Reload retains the serialized object entry", "1", savedGroup.m_Objects.Count().ToString());
			if (savedGroup.m_Objects.Count() == 1)
			{
				IAT_COTObjectEntry savedEntry = savedGroup.m_Objects[0];
				Check(savedEntry.m_ClassName == "Land_Misc_Well_Pump_Blue", "Reload preserves object classname", "Land_Misc_Well_Pump_Blue", savedEntry.m_ClassName);
				Check(savedEntry.m_Position == "12 34 56", "Reload preserves position", "12 34 56", savedEntry.m_Position.ToString());
				Check(savedEntry.m_Orientation == "90 10 -5", "Reload preserves orientation", "90 10 -5", savedEntry.m_Orientation.ToString());
				Check(savedEntry.m_Scale == 2.5, "Reload preserves scale", "2.5", savedEntry.m_Scale.ToString());
			}
		}
		Check(m_Store.GetLive("Renamed", -1) == null && m_Store.GetLive("Renamed", 0) == null, "Absent and invalid live indexes return null", "true", (m_Store.GetLive("Renamed", 0) == null).ToString());
		Check(m_Store.DeleteGroup("renamed", error), "Delete renamed group", "true", error);
		Check(!m_Store.DeleteGroup("renamed", error), "Deleting absent group fails", "false", error);
		IAT_RT_IsolatedObjectStore afterDelete = new IAT_RT_IsolatedObjectStore(m_Directory);
		afterDelete.Load();
		Check(afterDelete.GetGroups().Count() == 1 && afterDelete.FindGroup("Second") == 0, "Deletion persists and retains other groups", "1 / 0", afterDelete.GetGroups().Count().ToString());
		return true;
	}

	override bool Cleanup()
	{
		m_Store = null;
		string path = m_Directory + "cot_objectgroups.json";
		if (FileExist(path))
			DeleteFile(path);
		Check(!FileExist(path), "Isolated groups file removed", "true", (!FileExist(path)).ToString());
		return true;
	}
}
#endif
#endif
