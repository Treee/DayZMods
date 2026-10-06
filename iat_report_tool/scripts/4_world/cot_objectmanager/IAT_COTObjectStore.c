class IAT_COTObjectStore
{
	protected string m_Directory = "$profile:CommunityOnlineTools/ObjectManager/";
	protected string m_JsonFile = "cot_objectgroups.json";
	protected ref array<ref IAT_COTObjectGroup> m_Groups = new array<ref IAT_COTObjectGroup>;
	// Runtime references follow the saved array order; nothing here is serialized.
	protected ref map<string, ref array<Object>> m_Live = new map<string, ref array<Object>>;
	protected bool m_Loaded;

	array<ref IAT_COTObjectGroup> GetGroups()
	{
		return m_Groups;
	}

	// Stage membership changes without mutating the published array before save.
	protected array<ref IAT_COTObjectGroup> CopyGroups()
	{
		array<ref IAT_COTObjectGroup> groups = new array<ref IAT_COTObjectGroup>;
		foreach (IAT_COTObjectGroup group : m_Groups)
			groups.Insert(group);
		return groups;
	}

	// Preserve the array borrowed by the module when committing membership.
	protected void ReplaceGroups(array<ref IAT_COTObjectGroup> groups)
	{
		m_Groups.Clear();
		foreach (IAT_COTObjectGroup group : groups)
			m_Groups.Insert(group);
	}

	int FindGroup(string name)
	{
		string key = IAT_COTObjectRules.NameKey(name);
		foreach (int index, IAT_COTObjectGroup group : m_Groups)
		{
			if (IAT_COTObjectRules.NameKey(group.m_Name) == key)
				return index;
		}
		return -1;
	}

	Object GetLive(string name, int index)
	{
		array<Object> objects = m_Live.Get(IAT_COTObjectRules.NameKey(name));
		if (!objects || index < 0 || index >= objects.Count())
			return null;
		return objects[index];
	}

	void Load()
	{
		if (m_Loaded || !g_Game.IsServer())
			return;
		if (!FileExist("$profile:CommunityOnlineTools"))
			MakeDirectory("$profile:CommunityOnlineTools");
		if (!FileExist(m_Directory))
			MakeDirectory(m_Directory);
		string path = m_Directory + m_JsonFile;
		string error;
		array<ref IAT_COTObjectGroup> groups = new array<ref IAT_COTObjectGroup>;
		if (!FileExist(path))
		{
			if (!JsonFileLoader<ref array<ref IAT_COTObjectGroup>>.SaveFile(path, groups, error))
			{
				ErrorEx(error);
				return;
			}
		}
		else if (!JsonFileLoader<ref array<ref IAT_COTObjectGroup>>.LoadFile(path, groups, error))
		{
			ErrorEx(error);
			return;
		}
		if (!groups)
		{
			ErrorEx("[IAT Object Manager] Expected an array of groups in " + path);
			return;
		}
		set<string> names = new set<string>;
		foreach (IAT_COTObjectGroup group : groups)
		{
			if (!IAT_COTObjectRules.Validate(group, error, false))
			{
				ErrorEx("[IAT Object Manager] Invalid group: " + error);
				return;
			}
			string key = IAT_COTObjectRules.NameKey(group.m_Name);
			if (names.Find(key) != -1)
			{
				ErrorEx("[IAT Object Manager] Duplicate group name: " + group.m_Name);
				return;
			}
			names.Insert(key);
			string payload;
			if (!JsonFileLoader<IAT_COTObjectGroup>.MakeData(group, payload, error, false) || payload.Length() > IAT_COTObjectRules.MAX_PAYLOAD_LENGTH)
			{
				ErrorEx("[IAT Object Manager] Group exceeds the editor's 48 KB limit: " + group.m_Name);
				return;
			}
		}
		ReplaceGroups(groups);
		foreach (IAT_COTObjectGroup loadedGroup : m_Groups)
			SpawnGroup(loadedGroup);
		m_Loaded = true;
		g_Game.GetWorld().ProcessMarkedObjectsForPathgraphUpdate();
		Print("[IAT Object Manager] Loaded " + m_Groups.Count() + " groups from " + path);
	}

	protected void SpawnGroup(IAT_COTObjectGroup group)
	{
		array<Object> objects = new array<Object>;
		array<ref IAT_COTObjectEntry> entries = group.m_Objects;
		foreach (IAT_COTObjectEntry entry : entries)
		{
			Object obj = null;
			if (group.m_Enabled)
			{
				if (IAT_COTObjectRules.ValidClass(entry.m_ClassName))
					obj = Spawn(entry);
				else
					Print("[IAT Object Manager] Missing scope 1 class " + entry.m_ClassName + " in " + group.m_Name);
			}
			objects.Insert(obj);
		}
		m_Live.Insert(IAT_COTObjectRules.NameKey(group.m_Name), objects);
	}

	protected Object Spawn(IAT_COTObjectEntry entry)
	{
		int flags = ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_DYNAMIC_PERSISTENCY;
		Object obj = g_Game.CreateObjectEx(entry.m_ClassName, entry.m_Position, flags, RF_IGNORE);
		if (obj)
			Transform(obj, entry);
		return obj;
	}

	protected void Transform(Object obj, IAT_COTObjectEntry entry)
	{
		if (obj.CanAffectPathgraph())
			g_Game.UpdatePathgraphRegionByObject(obj);
		obj.SetPosition(entry.m_Position);
		obj.SetOrientation(entry.m_Orientation);
		obj.SetScale(entry.m_Scale);
		if (obj.CanAffectPathgraph())
		{
			obj.SetAffectPathgraph(true, false);
			g_Game.UpdatePathgraphRegionByObject(obj);
		}
		obj.Update();
	}

	protected void DeleteObject(Object obj)
	{
		if (!obj)
			return;
		if (obj.CanAffectPathgraph())
			g_Game.UpdatePathgraphRegionByObject(obj);
		g_Game.ObjectDelete(obj);
	}

	protected void DeleteObjects(array<Object> objects)
	{
		foreach (Object obj : objects)
			DeleteObject(obj);
	}

	bool Save(IAT_COTObjectGroup incoming, string originalName, out string error)
	{
		Load();
		if (!m_Loaded)
		{
			error = "The groups file could not be loaded. Check the server log before saving.";
			return false;
		}
		if (!IAT_COTObjectRules.Validate(incoming, error))
			return false;
		int oldIndex = -1;
		if (originalName != "")
		{
			oldIndex = FindGroup(originalName);
			if (oldIndex == -1)
			{
				error = "The original group no longer exists. Discard/reload first.";
				return false;
			}
		}
		int nameIndex = FindGroup(incoming.m_Name);
		if (nameIndex != -1 && nameIndex != oldIndex)
		{
			error = "Another group already uses this name.";
			return false;
		}
		string oldKey = IAT_COTObjectRules.NameKey(originalName);
		array<Object> oldObjects = m_Live.Get(oldKey);
		array<Object> nextObjects = new array<Object>;
		array<Object> staged = new array<Object>;
		array<ref IAT_COTObjectEntry> entries = incoming.m_Objects;
		foreach (int index, IAT_COTObjectEntry entry : entries)
		{
			Object obj = null;
			if (incoming.m_Enabled)
			{
				if (oldObjects && index < oldObjects.Count())
					obj = oldObjects[index];
				if (!obj || obj.GetType() != entry.m_ClassName)
				{
					obj = Spawn(entry);
					if (!obj)
					{
						DeleteObjects(staged);
						error = "Could not spawn " + entry.m_ClassName + ". Group was not saved.";
						return false;
					}
					staged.Insert(obj);
				}
			}
			nextObjects.Insert(obj);
		}
		array<ref IAT_COTObjectGroup> savedGroups = CopyGroups();
		if (oldIndex == -1)
			savedGroups.Insert(incoming.Clone());
		else
			savedGroups[oldIndex] = incoming.Clone();
		if (!JsonFileLoader<ref array<ref IAT_COTObjectGroup>>.SaveFile(m_Directory + m_JsonFile, savedGroups, error))
		{
			ErrorEx(error);
			DeleteObjects(staged);
			return false;
		}
		foreach (int nextIndex, Object next : nextObjects)
		{
			if (next)
				Transform(next, entries[nextIndex]);
		}
		if (oldObjects)
		{
			foreach (Object previous : oldObjects)
			{
				if (nextObjects.Find(previous) == -1)
					DeleteObject(previous);
			}
		}
		m_Live.Remove(oldKey);
		m_Live.Set(IAT_COTObjectRules.NameKey(incoming.m_Name), nextObjects);
		ReplaceGroups(savedGroups);
		g_Game.GetWorld().ProcessMarkedObjectsForPathgraphUpdate();
		return true;
	}

	bool DeleteGroup(string name, out string error)
	{
		if (!m_Loaded)
		{
			error = "The groups file could not be loaded.";
			return false;
		}
		int index = FindGroup(name);
		if (index == -1)
		{
			error = "Group no longer exists. Discard/reload first.";
			return false;
		}
		array<ref IAT_COTObjectGroup> savedGroups = CopyGroups();
		savedGroups.Remove(index);
		if (!JsonFileLoader<ref array<ref IAT_COTObjectGroup>>.SaveFile(m_Directory + m_JsonFile, savedGroups, error))
		{
			ErrorEx(error);
			return false;
		}
		string key = IAT_COTObjectRules.NameKey(name);
		array<Object> objects = m_Live.Get(key);
		if (objects)
			DeleteObjects(objects);
		m_Live.Remove(key);
		ReplaceGroups(savedGroups);
		g_Game.GetWorld().ProcessMarkedObjectsForPathgraphUpdate();
		return true;
	}
}
