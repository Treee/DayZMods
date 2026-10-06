class IAT_COTObjectManagerForm : JMFormBase
{
	protected const float CURSOR_RAY_DISTANCE = 1000.0;
	protected const int DELETE_CONFIRM_WINDOW_MS = 5000;

	protected IAT_COTObjectManagerModule m_Module;
	protected TextListboxWidget m_Classes;
	protected TextListboxWidget m_Groups;
	protected TextListboxWidget m_Objects;
	protected UIActionEditableText m_Search;
	protected UIActionEditableText m_Name;
	protected TextWidget m_Status;
	protected UIActionText m_Selected;
	protected UIActionButton m_EnabledButton;
	protected ref array<UIActionEditableText> m_Fields = new array<UIActionEditableText>;
	protected ref TStringArray m_Types = new TStringArray;
	protected ref IAT_COTObjectGroup m_Draft;
	protected string m_OriginalName;
	protected ref map<IAT_COTObjectEntry, Object> m_Previews = new map<IAT_COTObjectEntry, Object>;
	protected ref map<IAT_COTObjectEntry, Object> m_DraftLive = new map<IAT_COTObjectEntry, Object>;
	protected ref map<IAT_COTObjectEntry, ref IAT_COTObjectEntry> m_Sources = new map<IAT_COTObjectEntry, ref IAT_COTObjectEntry>;
	protected ref map<Object, ref IAT_COTObjectEntry> m_Hidden = new map<Object, ref IAT_COTObjectEntry>;
	protected int m_SelectedIndex = -1;
	protected bool m_Dirty;
	protected bool m_Busy;
	protected bool m_Populating;
	protected bool m_LeftDown;
	protected int m_DeleteConfirmUntil;

	void ~IAT_COTObjectManagerForm()
	{
		if (g_Game)
			ClearPreviews();
	}

	protected override bool SetModule(JMRenderableModuleBase mdl)
	{
		return Class.CastTo(m_Module, mdl);
	}

	override void OnInit()
	{
		m_Classes = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("classes"));
		m_Groups = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("groups"));
		m_Objects = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("objects"));
		Widget search = layoutRoot.FindAnyWidget("search_actions");
		m_Search = UIActionManager.CreateEditableText(search, "Search scope 1", this, "SearchChanged");
		Widget groupActions = layoutRoot.FindAnyWidget("group_actions");
		m_Name = UIActionManager.CreateEditableText(groupActions, "Group name", this, "NameChanged");
		Widget groupButtons = UIActionManager.CreateGridSpacer(groupActions, 1, 2);
		UIActionManager.CreateButton(groupButtons, "New group", this, "NewGroup");
		UIActionManager.CreateButton(groupButtons, "Discard / reload", this, "Discard");
		m_EnabledButton = UIActionManager.CreateButton(groupActions, "Enabled", this, "ToggleEnabled");
		Widget edit = layoutRoot.FindAnyWidget("edit_actions");
		m_Selected = UIActionManager.CreateText(edit, "Select an object");
		TStringArray labels = {"X (east/west)", "Y (height)", "Z (north/south)", "Yaw", "Pitch", "Roll", "Uniform scale"};
		foreach (string label : labels)
		{
			UIActionEditableText field = UIActionManager.CreateEditableText(edit, label, this, "TransformChanged");
			field.SetOnlyNumbers(true);
			m_Fields.Insert(field);
		}
		UIActionManager.CreateText(edit, "Scroll focused field: 0.1; Shift: 1.0");
		Widget placing = UIActionManager.CreateGridSpacer(edit, 1, 2);
		UIActionManager.CreateButton(placing, "Place at crosshair", this, "Place");
		UIActionManager.CreateButton(placing, "Select at crosshair", this, "Pick");
		Widget objectButtons = UIActionManager.CreateGridSpacer(edit, 1, 3);
		UIActionManager.CreateButton(objectButtons, "Duplicate", this, "Duplicate");
		UIActionManager.CreateButton(objectButtons, "Delete", this, "DeleteObject");
		UIActionManager.CreateButton(objectButtons, "Snap", this, "Snap");
		UIActionManager.CreateButton(edit, "Save Group", this, "Save").SetColor(COLOR_GREEN);
		UIActionManager.CreateButton(edit, "Delete saved group (click twice)", this, "DeleteSavedGroup").SetColor(COLOR_RED);
		m_Status = TextWidget.Cast(layoutRoot.FindAnyWidget("status"));
		m_Status.SetText("Loading groups...");
		int count = g_Game.ConfigGetChildrenCount("CfgVehicles");
		for (int i = 0; i < count; i++)
		{
			string type;
			g_Game.ConfigGetChildName("CfgVehicles", i, type);
			if (IAT_COTObjectRules.ValidClass(type))
				m_Types.Insert(type);
		}
		m_Types.Sort();
		FilterClasses();
	}

	override void OnShow()
	{
		super.OnShow();
		m_LeftDown = true;
		m_Module.RequestCatalog();
		RebuildPreviews();
	}

	override void OnHide()
	{
		ClearPreviews();
		super.OnHide();
	}

	override void OnSettingsUpdated()
	{
		RefreshGroups();
		if (!m_Draft && m_Module.GetGroups().Count() > 0)
			OpenGroup(0);
		else
			Status();
	}

	protected void Status(string message = "")
	{
		if (!m_Status)
			return;
		if (message != "")
		{
			m_Status.SetText(message);
			return;
		}
		if (m_Busy)
			m_Status.SetText("Waiting for server...");
		else if (m_Dirty)
			m_Status.SetText("Unsaved changes - Save Group to apply");
		else
			m_Status.SetText("Ready");
	}

	protected void FilterClasses()
	{
		string search = m_Search.GetText();
		search.ToLower();
		m_Classes.ClearItems();
		foreach (string type : m_Types)
		{
			string lower = type;
			lower.ToLower();
			if (search == "" || lower.Contains(search))
				m_Classes.AddItem(type, null, 0);
		}
	}

	void SearchChanged(UIEvent eid, UIActionBase action)
	{
		if (eid == UIEvent.CHANGE)
			FilterClasses();
	}

	protected void RefreshGroups()
	{
		bool populating = m_Populating;
		m_Populating = true;
		m_Groups.ClearItems();
		array<ref IAT_COTObjectGroup> groupArray = m_Module.GetGroups();
		foreach (IAT_COTObjectGroup group : groupArray)
		{
			string label = group.m_Name;
			if (!group.m_Enabled)
				label += " [disabled]";
			int row = m_Groups.AddItem(label, null, 0);
			if (m_Draft && m_OriginalName == group.m_Name)
				m_Groups.SelectRow(row);
		}
		m_Populating = populating;
	}

	protected void RefreshObjects()
	{
		bool populating = m_Populating;
		m_Populating = true;
		m_Objects.ClearItems();
		if (m_Draft)
		{
			array<ref IAT_COTObjectEntry> entryArray = m_Draft.m_Objects;
			foreach (int index, IAT_COTObjectEntry entry : entryArray)
				m_Objects.AddItem((index + 1).ToString() + ". " + entry.m_ClassName, null, 0);
			if (m_SelectedIndex >= 0 && m_SelectedIndex < m_Draft.m_Objects.Count())
				m_Objects.SelectRow(m_SelectedIndex);
		}
		m_Populating = populating;
	}

	protected void OpenGroup(int row)
	{
		if (m_Dirty || m_Busy)
		{
			Status("Save or discard before changing groups.");
			RefreshGroups();
			return;
		}
		array<ref IAT_COTObjectGroup> groups = m_Module.GetGroups();
		if (row < 0 || row >= groups.Count())
			return;
		ClearPreviews();
		m_Draft = groups[row].Clone();
		m_OriginalName = m_Draft.m_Name;
		m_SelectedIndex = -1;
		PopulateGroup();
	}

	protected void PopulateGroup()
	{
		m_Sources.Clear();
		m_DraftLive.Clear();
		array<ref IAT_COTObjectEntry> sourceEntries = m_Draft.m_Objects;
		foreach (IAT_COTObjectEntry sourceEntry : sourceEntries)
			m_Sources.Insert(sourceEntry, sourceEntry.Clone());
		m_Populating = true;
		SetFocus(null);
		m_Name.SetText(m_Draft.m_Name);
		UpdateEnabledLabel();
		m_Populating = false;
		RefreshObjects();
		SelectObject(-1);
		Status();
	}

	protected void UpdateEnabledLabel()
	{
		if (m_Draft && m_Draft.m_Enabled)
			m_EnabledButton.SetButton("Enabled - click to disable");
		else
			m_EnabledButton.SetButton("Disabled - click to enable");
	}

	void NewGroup(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy)
			return;
		if (!CommitFields())
			return;
		if (m_Dirty)
		{
			Status("Save or discard before creating another group.");
			return;
		}
		ClearPreviews();
		m_Draft = new IAT_COTObjectGroup;
		m_OriginalName = "";
		m_Draft.m_Name = "New group";
		m_Dirty = true;
		PopulateGroup();
	}

	void NameChanged(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CHANGE || m_Populating || m_Busy || !m_Draft)
			return;
		m_Draft.m_Name = m_Name.GetText();
		m_Dirty = true;
		Status();
	}

	void ToggleEnabled(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy || !m_Draft)
			return;
		m_Draft.m_Enabled = !m_Draft.m_Enabled;
		m_Dirty = true;
		UpdateEnabledLabel();
		Status();
	}

	void Discard(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy)
			return;
		ClearPreviews();
		m_Draft = null;
		m_OriginalName = "";
		m_Sources.Clear();
		m_DraftLive.Clear();
		m_Dirty = false;
		m_SelectedIndex = -1;
		RefreshObjects();
		m_Module.RequestCatalog();
		Status("Reloading saved groups...");
	}

	protected IAT_COTObjectEntry SelectedEntry()
	{
		if (!m_Draft || m_SelectedIndex < 0 || m_SelectedIndex >= m_Draft.m_Objects.Count())
			return null;
		return m_Draft.m_Objects[m_SelectedIndex];
	}

	protected void SelectObject(int index)
	{
		m_SelectedIndex = index;
		IAT_COTObjectEntry entry = SelectedEntry();
		SetFocus(null);
		m_Populating = true;
		if (entry)
		{
			m_Selected.SetLabel(entry.m_ClassName);
			for (int axis = 0; axis < 3; axis++)
			{
				m_Fields[axis].SetText(entry.m_Position[axis]);
				m_Fields[axis + 3].SetText(entry.m_Orientation[axis]);
			}
			m_Fields[6].SetText(entry.m_Scale);
			m_Objects.SelectRow(index);
		}
		else
		{
			m_Selected.SetLabel("Select an object");
			foreach (UIActionEditableText field : m_Fields)
				field.SetText("");
		}
		m_Populating = false;
	}

	protected bool CommitFields()
	{
		if (m_Draft && m_Name.GetText() != m_Draft.m_Name)
		{
			m_Draft.m_Name = m_Name.GetText();
			m_Dirty = true;
		}
		IAT_COTObjectEntry entry = SelectedEntry();
		if (!entry)
			return true;
		for (int index = 0; index < m_Fields.Count(); index++)
		{
			string text = m_Fields[index].GetText();
			if (text == "" || text == "-" || text == "." || text == "-.")
			{
				Status("Complete every numeric field before continuing.");
				return false;
			}
		}
		vector pos;
		vector ori;
		for (int axis = 0; axis < 3; axis++)
		{
			pos[axis] = m_Fields[axis].GetText().ToFloat();
			ori[axis] = m_Fields[axis + 3].GetText().ToFloat();
		}
		float scale = m_Fields[6].GetText().ToFloat();
		if (scale < IAT_COTObjectRules.MIN_SCALE || scale > IAT_COTObjectRules.MAX_SCALE)
		{
			Status("Scale must be between 0.01 and 100.");
			return false;
		}
		if (entry.m_Position != pos || entry.m_Orientation != ori || entry.m_Scale != scale)
		{
			entry.m_Position = pos;
			entry.m_Orientation = ori;
			entry.m_Scale = scale;
			m_Dirty = true;
			Preview(entry);
			Status();
		}
		return true;
	}

	void TransformChanged(UIEvent eid, UIActionBase action)
	{
		if (m_Populating || m_Busy || (eid != UIEvent.CHANGE && eid != UIEvent.MOUSEWHEEL))
			return;
		CommitFields();
	}

	protected Object FindLive(IAT_COTObjectEntry entry)
	{
		Object cached = m_DraftLive.Get(entry);
		if (cached)
			return cached;
		IAT_COTObjectEntry source = m_Sources.Get(entry);
		if (!source || m_OriginalName == "")
			return null;
		Object live;
		if (IsMissionOffline())
			live = m_Module.GetLive(m_OriginalName, m_Draft.m_Objects.Find(entry));
		else
		{
			array<Object> nearby = new array<Object>;
			array<CargoBase> cargo = new array<CargoBase>;
			g_Game.GetObjectsAtPosition3D(source.m_Position, 0.1, nearby, cargo);
			foreach (Object candidate : nearby)
			{
				if (!candidate || candidate.GetType() != source.m_ClassName || vector.Distance(candidate.GetPosition(), source.m_Position) > 0.01)
					continue;
				bool claimed = false;
				foreach (IAT_COTObjectEntry previewEntry, Object previewObject : m_Previews)
				{
					if (previewObject == candidate)
						claimed = true;
				}
				foreach (IAT_COTObjectEntry otherEntry, Object otherObject : m_DraftLive)
				{
					if (otherObject == candidate)
						claimed = true;
				}
				if (!claimed)
				{
					live = candidate;
					break;
				}
			}
		}
		if (live)
			m_DraftLive.Set(entry, live);
		return live;
	}

	protected void HideLive(IAT_COTObjectEntry entry)
	{
		if (IsMissionOffline())
			return;
		Object live = FindLive(entry);
		if (!live || m_Hidden.Contains(live))
			return;
		IAT_COTObjectEntry original = new IAT_COTObjectEntry;
		original.m_Position = live.GetPosition();
		original.m_Orientation = live.GetOrientation();
		original.m_Scale = live.GetScale();
		m_Hidden.Insert(live, original);
		live.SetPosition("0 -10000 0");
		live.Update();
	}

	protected void Preview(IAT_COTObjectEntry entry)
	{
		if (!m_IsShown && !IsVisible())
			return;
		Object obj = m_Previews.Get(entry);
		if (!obj)
		{
			if (!IAT_COTObjectRules.ValidClass(entry.m_ClassName))
				return;
			obj = g_Game.CreateObjectEx(entry.m_ClassName, entry.m_Position, ECE_LOCAL);
			if (!obj)
			{
				Status("Preview could not be created: " + entry.m_ClassName);
				return;
			}
			m_Previews.Insert(entry, obj);
			HideLive(entry);
		}
		obj.SetPosition(entry.m_Position);
		obj.SetOrientation(entry.m_Orientation);
		obj.SetScale(entry.m_Scale);
		obj.Update();
	}

	protected void ClearPreviews()
	{
		foreach (IAT_COTObjectEntry entry, Object preview : m_Previews)
		{
			if (preview)
				g_Game.ObjectDelete(preview);
		}
		m_Previews.Clear();
		foreach (Object live, IAT_COTObjectEntry original : m_Hidden)
		{
			if (live)
			{
				live.SetPosition(original.m_Position);
				live.SetOrientation(original.m_Orientation);
				live.SetScale(original.m_Scale);
				live.Update();
			}
		}
		m_Hidden.Clear();
	}

	protected void RebuildPreviews()
	{
		if (!m_Draft || !m_Dirty)
			return;
		array<ref IAT_COTObjectEntry> entries = m_Draft.m_Objects;
		foreach (IAT_COTObjectEntry entry : entries)
			Preview(entry);
	}

	protected bool CursorPosition(bool pointer, out vector position)
	{
		vector start = g_Game.GetCurrentCameraPosition();
		vector direction = g_Game.GetCurrentCameraDirection();
		if (pointer)
			direction = g_Game.GetPointerDirection();
		bool hit;
		position = COT_PerformRayCast(start, start + direction * CURSOR_RAY_DISTANCE, g_Game.GetPlayer(), hit);
		if (!hit)
			Status("No surface found within 1000 metres.");
		return hit;
	}

	protected void PlaceClass(bool pointer)
	{
		if (m_Busy || !m_Draft || !CommitFields())
			return;
		int row = m_Classes.GetSelectedRow();
		if (row < 0)
			return;
		string type;
		m_Classes.GetItemText(row, 0, type);
		vector position;
		if (!CursorPosition(pointer, position))
			return;
		IAT_COTObjectEntry entry = new IAT_COTObjectEntry;
		entry.m_ClassName = type;
		entry.m_Position = position;
		m_Draft.m_Objects.Insert(entry);
		m_Dirty = true;
		Preview(entry);
		RefreshObjects();
		SelectObject(m_Draft.m_Objects.Count() - 1);
		Status();
	}

	void Place(UIEvent eid, UIActionBase action)
	{
		if (eid == UIEvent.CLICK)
			PlaceClass(false);
	}

	void Duplicate(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy || !CommitFields())
			return;
		IAT_COTObjectEntry selected = SelectedEntry();
		if (!selected)
			return;
		IAT_COTObjectEntry copy = selected.Clone();
		copy.m_Position = copy.m_Position + "1 0 0";
		m_Draft.m_Objects.Insert(copy);
		m_Dirty = true;
		Preview(copy);
		RefreshObjects();
		SelectObject(m_Draft.m_Objects.Count() - 1);
		Status();
	}

	void DeleteObject(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy)
			return;
		IAT_COTObjectEntry entry = SelectedEntry();
		if (!entry)
			return;
		Object preview = m_Previews.Get(entry);
		if (preview)
			g_Game.ObjectDelete(preview);
		m_Previews.Remove(entry);
		HideLive(entry);
		m_DraftLive.Remove(entry);
		m_Sources.Remove(entry);
		m_Draft.m_Objects.Remove(m_SelectedIndex);
		m_SelectedIndex = -1;
		m_Dirty = true;
		RefreshObjects();
		SelectObject(-1);
		Status();
	}

	void Snap(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy || !CommitFields())
			return;
		IAT_COTObjectEntry entry = SelectedEntry();
		if (!entry)
			return;
		Object ignore = m_Previews.Get(entry);
		if (!ignore)
			ignore = FindLive(entry);
		vector offset = "0 10 0";
		vector bottom = "0 1000 0";
		bool hit;
		vector position = COT_PerformRayCast(entry.m_Position + offset, entry.m_Position - bottom, ignore, hit);
		if (!hit)
		{
			Status("No surface below the object.");
			return;
		}
		entry.m_Position = position;
		m_Dirty = true;
		Preview(entry);
		SelectObject(m_SelectedIndex);
		Status();
	}

	protected void PickObject(bool pointer)
	{
		if (!m_Draft || m_Busy || !CommitFields())
			return;
		vector start = g_Game.GetCurrentCameraPosition();
		vector direction = g_Game.GetCurrentCameraDirection();
		if (pointer)
			direction = g_Game.GetPointerDirection();
		set<Object> hits = new set<Object>;
		vector pos;
		vector normal;
		int component;
		DayZPhysics.RaycastRV(start, start + direction * CURSOR_RAY_DISTANCE, pos, normal, component, hits, null, g_Game.GetPlayer(), false, false, ObjIntersectGeom);
		foreach (Object hit : hits)
		{
			array<ref IAT_COTObjectEntry> entryArray = m_Draft.m_Objects;
			foreach (int index, IAT_COTObjectEntry entry : entryArray)
			{
				if (hit == m_Previews.Get(entry) || hit == FindLive(entry))
				{
					SelectObject(index);
					return;
				}
			}
		}
		Status("No object from the active group at the cursor.");
	}

	void Pick(UIEvent eid, UIActionBase action)
	{
		if (eid == UIEvent.CLICK)
			PickObject(false);
	}

	override void Update()
	{
		super.Update();
		bool down = (GetMouseState(MouseState.LEFT) & 0x80000000) != 0;
		if (down && !m_LeftDown && GetCommunityOnlineToolsBase().IsActive())
		{
			Widget under = GetWidgetUnderCursor();
			bool overCOTWindow = false;
			Widget ancestor = under;
			while (ancestor)
			{
				if (ancestor == JMStatics.WINDOWS_CONTAINER || ancestor == layoutRoot)
					overCOTWindow = true;
				ancestor = ancestor.GetParent();
			}
			if (!overCOTWindow && !g_Game.GetUIManager().GetMenu())
				PickObject(true);
		}
		m_LeftDown = down;
	}

	override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
	{
		if (m_Busy || m_Populating)
			return true;
		if (w == m_Groups)
		{
			if (CommitFields())
				OpenGroup(row);
			return true;
		}
		if (w == m_Objects)
		{
			if (CommitFields())
				SelectObject(row);
			return true;
		}
		return super.OnItemSelected(w, x, y, row, column, oldRow, oldColumn);
	}

	override bool OnDoubleClick(Widget w, int x, int y, int button)
	{
		if (w == m_Classes && button == MouseState.LEFT)
		{
			PlaceClass(true);
			return true;
		}
		return super.OnDoubleClick(w, x, y, button);
	}

	void Save(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy || !m_Draft || !CommitFields())
			return;
		m_Draft.m_Name = m_Name.GetText();
		string error;
		if (!IAT_COTObjectRules.Validate(m_Draft, error))
		{
			Status(error);
			return;
		}
		// Restore server-owned visuals before the server sends its new transform.
		ClearPreviews();
		m_Busy = true;
		Status();
		m_Module.SaveGroup(m_Draft, m_OriginalName);
	}

	void DeleteSavedGroup(UIEvent eid, UIActionBase action)
	{
		if (eid != UIEvent.CLICK || m_Busy || !m_Draft)
			return;
		if (m_Dirty)
		{
			Status("Discard unsaved edits before deleting a saved group.");
			return;
		}
		if (m_OriginalName == "")
			return;
		if (m_DeleteConfirmUntil == 0 || g_Game.GetTime() > m_DeleteConfirmUntil)
		{
			m_DeleteConfirmUntil = g_Game.GetTime() + DELETE_CONFIRM_WINDOW_MS;
			Status("Click Delete saved group again within 5 seconds to confirm.");
			return;
		}
		m_DeleteConfirmUntil = 0;
		ClearPreviews();
		m_Busy = true;
		Status();
		m_Module.DeleteGroup(m_OriginalName);
	}

	void Saved(bool success, string name, bool deleted, string message)
	{
		m_Busy = false;
		if (!success)
		{
			RebuildPreviews();
			Status("Save failed: " + message);
			return;
		}
		ClearPreviews();
		m_Dirty = false;
		if (deleted)
		{
			m_Draft = null;
			m_OriginalName = "";
			m_Sources.Clear();
			m_DraftLive.Clear();
			m_SelectedIndex = -1;
			RefreshObjects();
		}
		else
		{
			array<ref IAT_COTObjectGroup> groupArray = m_Module.GetGroups();
			foreach (IAT_COTObjectGroup group : groupArray)
			{
				if (group.m_Name == name)
				{
					m_Draft = group.Clone();
					m_OriginalName = group.m_Name;
					PopulateGroup();
					break;
				}
			}
		}
		RefreshGroups();
		Status("Saved and applied");
	}
}
