class IAT_COTObjectManagerModule : JMRenderableModuleBase
{
	protected ref IAT_COTObjectStore m_Store;
	protected ref array<ref IAT_COTObjectGroup> m_Groups = new array<ref IAT_COTObjectGroup>;
	protected int m_ExpectedGroups;
	protected bool m_GroupsLoaded;

	override void EnableUpdate()
	{
	}

	override bool HasAccess()
	{
		return GetPermissionsManager().HasPermission("Entity.View");
	}
	override bool ImageIsIcon()
	{
		return true;
	}

	override bool ImageHasPath()
	{
		return true;
	}

	override string GetTitle()
	{
		return "Object Manager";
	}

	override string GetIconName()
	{
		return "JM\\COT\\GUI\\textures\\modules\\Object.paa";
	}

	override string GetLayoutRoot()
	{
		return "iat_report_tool/scripts/5_mission/layouts/cot_objectmanager.layout";
	}

	override int GetRPCMin()
	{
		return IAT_COTObjectRPC.INVALID;
	}

	override int GetRPCMax()
	{
		return IAT_COTObjectRPC.COUNT;
	}

	override void OnMissionLoaded()
	{
		super.OnMissionLoaded();
		if (IsMissionHost() && !m_Store)
		{
			m_Store = new IAT_COTObjectStore;
			m_Store.Load();
			m_Groups = m_Store.GetGroups();
			m_GroupsLoaded = true;
		}
	}

	array<ref IAT_COTObjectGroup> GetGroups()
	{
		return m_Groups;
	}

	bool GroupsLoaded()
	{
		return m_GroupsLoaded;
	}

	Object GetLive(string name, int index)
	{
		if (IsMissionOffline() && m_Store)
			return m_Store.GetLive(name, index);
		return null;
	}

	void RequestCatalog()
	{
		if (IsMissionOffline())
		{
			m_Groups = m_Store.GetGroups();
			OnSettingsUpdated();
			return;
		}
		ScriptRPC rpc = new ScriptRPC;
		rpc.Send(null, IAT_COTObjectRPC.Load, true, null);
	}

	void SaveGroup(IAT_COTObjectGroup group, string originalName)
	{
		string json;
		string error;
		if (!JsonFileLoader<IAT_COTObjectGroup>.MakeData(group, json, error, false) || json.Length() > IAT_COTObjectRules.MAX_PAYLOAD_LENGTH)
		{
			ReceiveResult(false, group.m_Name, false, "Group exceeds the 48 KB save limit.");
			return;
		}
		if (IsMissionOffline())
		{
			bool ok = m_Store.Save(group, originalName, error);
			ReceiveResult(ok, group.m_Name, false, error);
			return;
		}
		ScriptRPC rpc = new ScriptRPC;
		rpc.Write(originalName);
		rpc.Write(json);
		rpc.Send(null, IAT_COTObjectRPC.Save, true, null);
	}

	void DeleteGroup(string name)
	{
		if (IsMissionOffline())
		{
			string error;
			bool ok = m_Store.DeleteGroup(name, error);
			ReceiveResult(ok, name, true, error);
			return;
		}
		ScriptRPC rpc = new ScriptRPC;
		rpc.Write(name);
		rpc.Send(null, IAT_COTObjectRPC.DeleteGroup, true, null);
	}

	protected bool MayEdit(PlayerIdentity sender)
	{
		JMPlayerInstance instance;
		return sender && GetPermissionsManager().HasPermission("Entity.Spawn.Position", sender, instance) && GetPermissionsManager().HasPermission("Entity.Delete", sender, instance);
	}

	protected void SendCatalog(PlayerIdentity recipient)
	{
		ScriptRPC header = new ScriptRPC;
		header.Write(m_Groups.Count());
		header.Send(null, IAT_COTObjectRPC.Load, true, recipient);
		foreach (IAT_COTObjectGroup group : m_Groups)
		{
			string json;
			string error;
			JsonFileLoader<IAT_COTObjectGroup>.MakeData(group, json, error, false);
			ScriptRPC rpc = new ScriptRPC;
			rpc.Write(json);
			rpc.Send(null, IAT_COTObjectRPC.Catalog, true, recipient);
		}
	}

	protected void SendResult(PlayerIdentity recipient, bool success, string name, bool deleted, string message)
	{
		ScriptRPC rpc = new ScriptRPC;
		rpc.Write(success);
		rpc.Write(name);
		rpc.Write(deleted);
		rpc.Write(message);
		rpc.Send(null, IAT_COTObjectRPC.Result, true, recipient);
	}

	protected void ReceiveResult(bool success, string name, bool deleted, string message)
	{
		IAT_COTObjectManagerForm form;
		if (Class.CastTo(form, GetForm()))
			form.Saved(success, name, deleted, message);
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		string json;
		string error;
		string name;
		if (IsMissionHost())
		{
			if (!m_Store || !sender)
				return;
			JMPlayerInstance instance;
			switch (rpc_type)
			{
				case IAT_COTObjectRPC.Load:
					if (GetPermissionsManager().HasPermission("Entity.View", sender, instance))
						SendCatalog(sender);
					break;
				case IAT_COTObjectRPC.Save:
					if (!MayEdit(sender))
					{
						SendResult(sender, false, "", false, "Existing COT spawn and delete access is required.");
						return;
					}
					string originalName;
					if (!ctx.Read(originalName) || !ctx.Read(json) || json.Length() > IAT_COTObjectRules.MAX_PAYLOAD_LENGTH)
					{
						SendResult(sender, false, "", false, "Invalid or oversized save request.");
						return;
					}
					IAT_COTObjectGroup group;
					if (!JsonFileLoader<IAT_COTObjectGroup>.LoadData(json, group, error) || !group)
					{
						SendResult(sender, false, "", false, "Invalid group JSON.");
						return;
					}
					bool saved = m_Store.Save(group, originalName, error);
					if (saved)
					{
						GetCommunityOnlineToolsBase().Log(sender, "Saved object group " + group.m_Name);
						SendCatalog(sender);
					}
					SendResult(sender, saved, group.m_Name, false, error);
					break;
				case IAT_COTObjectRPC.DeleteGroup:
					if (!MayEdit(sender))
					{
						SendResult(sender, false, "", true, "Existing COT spawn and delete access is required.");
						return;
					}
					if (!ctx.Read(name))
						return;
					bool deleted = m_Store.DeleteGroup(name, error);
					if (deleted)
					{
						GetCommunityOnlineToolsBase().Log(sender, "Deleted object group " + name);
						SendCatalog(sender);
					}
					SendResult(sender, deleted, name, true, error);
					break;
			}
			return;
		}
		switch (rpc_type)
		{
			case IAT_COTObjectRPC.Load:
				if (!ctx.Read(m_ExpectedGroups) || m_ExpectedGroups < 0)
					return;
				m_Groups = new array<ref IAT_COTObjectGroup>;
				m_GroupsLoaded = m_ExpectedGroups == 0;
				if (m_GroupsLoaded)
					OnSettingsUpdated();
				break;
			case IAT_COTObjectRPC.Catalog:
				if (!ctx.Read(json))
					return;
				IAT_COTObjectGroup received;
				if (!JsonFileLoader<IAT_COTObjectGroup>.LoadData(json, received, error) || !received)
					return;
				m_Groups.Insert(received);
				if (m_Groups.Count() == m_ExpectedGroups)
				{
					m_GroupsLoaded = true;
					OnSettingsUpdated();
				}
				break;
			case IAT_COTObjectRPC.Result:
				bool success;
				bool removed;
				string message;
				if (ctx.Read(success) && ctx.Read(name) && ctx.Read(removed) && ctx.Read(message))
					ReceiveResult(success, name, removed, message);
				break;
		}
	}
}
