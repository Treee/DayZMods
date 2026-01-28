class IAT_CollectorCodexMenu extends UIScriptedMenu
{
	protected const string LAYOUT_PATH = "iat_dayz_codex/scripts/5_mission/layouts/iat_collector_codex.layout";
	protected const string CATEGORY_ALL = "ALL";

	protected ButtonWidget m_ButtonClose;
	protected ButtonWidget m_ButtonTabBrowse;
	protected ButtonWidget m_ButtonTabSets;
	protected ButtonWidget m_ButtonTabDuplicates;
	protected ButtonWidget m_ButtonTabTrade;

	protected EditBoxWidget m_EditBoxSearch;
	protected TextListboxWidget m_ListCategories;
	protected TextListboxWidget m_ListCenterOptions;
	protected ItemPreviewWidget m_ItemPreview;
	protected TextListboxWidget m_ListVariants;

	protected EntityAI m_PreviewObject;
	protected IAT_DayZCodex_ColorBase m_Codex;

	protected ref array<ref IAT_CodexEntry> m_AllEntries;
	protected ref array<ref IAT_CodexEntry> m_FilteredEntries;
	protected string m_SearchFilter;
	protected string m_SelectedCategory;

	void IAT_CollectorCodexMenu()
	{
		m_AllEntries = new array<ref IAT_CodexEntry>;
		m_FilteredEntries = new array<ref IAT_CodexEntry>;
		m_SelectedCategory = CATEGORY_ALL;
		m_SearchFilter = string.Empty;
	}

	void ~IAT_CollectorCodexMenu()
	{
		ClearPreviewObject();
	}

	void SetCodex(IAT_DayZCodex_ColorBase codex)
	{
		m_Codex = codex;
	}
	// =========================================================== EVENTS
	override void OnShow()
	{
		super.OnShow();
		g_Game.GetMission().AddActiveInputExcludes({"menu"});
		FillBrowsePanel();
	}

	override void OnHide()
	{
		super.OnHide();
		g_Game.GetMission().RemoveActiveInputExcludes({"menu"}, true);
		ClearPreviewObject();
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		if (GetUApi().GetInputByID(UAUIBack).LocalPress())
			Close();
	}

	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("iat_dayz_codex/scripts/5_mission/layouts/iat_collector_codex.layout");

		m_ButtonClose = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonClose"));
		m_ButtonTabBrowse = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonTabBrowse"));
		m_ButtonTabSets = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonTabSets"));
		m_ButtonTabDuplicates = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonTabDuplicates"));
		m_ButtonTabTrade = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonTabTrade"));

		m_EditBoxSearch = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxSearch"));
		m_ListCategories = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("ListCategories"));
		m_ListCenterOptions = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("ListCenterOptions"));
		m_ItemPreview = ItemPreviewWidget.Cast(layoutRoot.FindAnyWidget("ItemPreviewWidget0"));
		m_ListVariants = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("ListVariants"));

		BuildDummyData();
		FillCategories();
		SelectCategory(CATEGORY_ALL);

		FillBrowsePanel();
		return layoutRoot;
	}

	protected void BuildDummyData()
	{
		m_AllEntries.Clear();

		m_AllEntries.Insert(new IAT_CodexEntry("Chemlight", "LIGHTS", {"Chemlight", "Chemlight_White", "Chemlight_Green"}, 3, 9, 12));
		m_AllEntries.Insert(new IAT_CodexEntry("TacticalHelmet", "GEAR", {"TacticalHelmet_Black", "TacticalHelmet_Green", "TacticalHelmet_Olive"}, 1, 4, 2));
		m_AllEntries.Insert(new IAT_CodexEntry("WorkingGloves", "CLOTHING", {"WorkingGloves_Beige", "WorkingGloves_Black", "WorkingGloves_Brown"}, 2, 3, 6));
		m_AllEntries.Insert(new IAT_CodexEntry("VeryLongExampleObjectName_ToProveNameColumnIsWide", "TEST", {"Chemlight"}, 7, 12, 19));
	}

	protected void FillCategories()
	{
		if (!m_ListCategories)
			return;

		m_ListCategories.ClearItems();
		m_ListCategories.AddItem(CATEGORY_ALL, null, 0);

		ref array<string> categories = new array<string>;
		foreach (IAT_CodexEntry entry : m_AllEntries)
		{
			if (!entry)
				continue;
			if (categories.Find(entry.m_Category) == -1)
				categories.Insert(entry.m_Category);
		}
		categories.Sort();
		foreach (string cat : categories)
			m_ListCategories.AddItem(cat, null, 0);
	}

	protected void SelectCategory(string category)
	{
		m_SelectedCategory = category;
		if (!m_ListCategories)
			return;

		for (int i = 0; i < m_ListCategories.GetNumItems(); i++)
		{
			string rowCat;
			m_ListCategories.GetItemText(i, 0, rowCat);
			if (rowCat == category)
			{
				m_ListCategories.SelectRow(i);
				break;
			}
		}
	}

	protected void FillBrowsePanel()
	{
		if (!m_ListCenterOptions)
			return;

		m_ListCenterOptions.ClearItems();
		m_FilteredEntries.Clear();

		string filter = m_SearchFilter;
		filter.ToLower();

		foreach (IAT_CodexEntry entry : m_AllEntries)
		{
			if (!entry)
				continue;
			if (m_SelectedCategory != CATEGORY_ALL && entry.m_Category != m_SelectedCategory)
				continue;

			string nameLower = entry.m_DisplayName;
			nameLower.ToLower();
			if (filter != string.Empty && !nameLower.Contains(filter))
				continue;

			m_FilteredEntries.Insert(entry);
			AddBrowseRow(entry);
		}

		if (m_ListCenterOptions.GetNumItems() > 0)
		{
			m_ListCenterOptions.SelectRow(0);
			UpdateRightPanelFromCenterSelection();
		}
		else
		{
			ClearPreviewObject();
			FillVariants(null);
		}
	}

	protected void AddBrowseRow(IAT_CodexEntry entry)
	{
		if (!m_ListCenterOptions)
			return;
		if (!entry)
			return;

		int row = m_ListCenterOptions.AddItem(entry.m_DisplayName, entry, 0);
		m_ListCenterOptions.SetItem(row, string.Format("%1/%2", entry.m_UniqueOwned, entry.m_TotalVariants), null, 1);
		m_ListCenterOptions.SetItem(row, string.Format("%1%2", entry.GetCompletionPercent(), "%"), null, 2);
		m_ListCenterOptions.SetItem(row, entry.m_TotalOwned.ToString(), null, 3);
	}

	protected void UpdateRightPanelFromCenterSelection()
	{
		if (!m_ListCenterOptions)
			return;

		int row = m_ListCenterOptions.GetSelectedRow();
		if (row < 0)
			return;

		IAT_CodexEntry entry;
		m_ListCenterOptions.GetItemData(row, 0, entry);
		UpdatePreview(entry);
		FillVariants(entry);
	}

	protected void FillVariants(IAT_CodexEntry entry)
	{
		if (!m_ListVariants)
			return;

		m_ListVariants.ClearItems();
		if (!entry || !entry.m_Variants)
			return;

		for (int i = 0; i < entry.m_Variants.Count(); i++)
		{
			string variant = entry.m_Variants[i];
			m_ListVariants.AddItem(variant, null, 0);
		}
		if (m_ListVariants.GetNumItems() > 0)
			m_ListVariants.SelectRow(0);
	}

	protected void UpdatePreview(IAT_CodexEntry entry)
	{
		if (!m_ItemPreview)
			return;

		string previewType;
		if (entry && entry.m_Variants && entry.m_Variants.Count() > 0)
			previewType = entry.m_Variants[0];
		else if (entry)
			previewType = entry.m_DisplayName;

		SetPreviewObject(previewType);
	}

	protected void SetPreviewObject(string typeName)
	{
		if (!m_ItemPreview)
			return;

		ClearPreviewObject();
		if (typeName == string.Empty)
			return;

		m_PreviewObject = EntityAI.Cast(g_Game.CreateObject(typeName, vector.Zero, true, false, false));
		if (m_PreviewObject)
			m_ItemPreview.SetItem(m_PreviewObject);
		else
			Print(string.Format("[IAT Codex] Preview create failed: %1", typeName));
	}

	protected void ClearPreviewObject()
	{
		if (m_PreviewObject)
		{
			g_Game.ObjectDelete(m_PreviewObject);
		}
	}

	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		if (w == m_EditBoxSearch)
		{
			m_SearchFilter = m_EditBoxSearch.GetText();
			FillBrowsePanel();
			return true;
		}
		return super.OnChange(w, x, y, finished);
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (w == m_ButtonClose)
		{
			Close();
			return true;
		}

		if (w == m_ButtonTabBrowse)
		{
			Print("[IAT Codex] Browse tab");
			FillBrowsePanel();
			return true;
		}

		if (w == m_ButtonTabSets)
		{
			Print("[IAT Codex] Sets tab (TODO)");
			return true;
		}

		if (w == m_ButtonTabDuplicates)
		{
			Print("[IAT Codex] Duplicates tab (TODO)");
			return true;
		}

		if (w == m_ButtonTabTrade)
		{
			Print("[IAT Codex] Trade tab (TODO)");
			return true;
		}

		if (w == m_ListCenterOptions)
		{
			UpdateRightPanelFromCenterSelection();
			return true;
		}

		if (w == m_ListCategories)
		{
			int rowCat = m_ListCategories.GetSelectedRow();
			if (rowCat > -1)
			{
				string cat;
				m_ListCategories.GetItemText(rowCat, 0, cat);
				m_SelectedCategory = cat;
				FillBrowsePanel();
			}
			return true;
		}

		if (w == m_ListVariants)
		{
			int rowVar = m_ListVariants.GetSelectedRow();
			if (rowVar > -1)
			{
				string variant;
				m_ListVariants.GetItemText(rowVar, 0, variant);
				SetPreviewObject(variant);
			}
			return true;
		}

		return super.OnClick(w, x, y, button);
	}
};

class IAT_CodexEntry
{
	string m_DisplayName;
	string m_Category;
	ref array<string> m_Variants;
	int m_UniqueOwned;
	int m_TotalVariants;
	int m_TotalOwned;

	void IAT_CodexEntry(string displayName, string category, array<string> variants, int uniqueOwned, int totalVariants, int totalOwned)
	{
		m_DisplayName = displayName;
		m_Category = category;
		m_Variants = new array<string>;
		if (variants)
		{
			foreach (string v : variants)
				m_Variants.Insert(v);
		}
		m_UniqueOwned = uniqueOwned;
		m_TotalVariants = totalVariants;
		m_TotalOwned = totalOwned;
	}

	int GetCompletionPercent()
	{
		if (m_TotalVariants <= 0)
			return 0;
		return Math.Floor((m_UniqueOwned * 100.0) / m_TotalVariants);
	}
};
