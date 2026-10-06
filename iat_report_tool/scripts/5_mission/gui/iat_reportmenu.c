class IAT_ReportMenu extends UIScriptedMenu
{
	protected CheckBoxWidget m_ChkBoxTerrainReport;
	protected CheckBoxWidget m_ChkBoxBugReport;
	protected CheckBoxWidget m_ChkBoxPlayerReport;
	protected CheckBoxWidget m_ChkBoxSuggestionReport;
	protected CheckBoxWidget m_ChkBoxExploitReport;

	protected ButtonWidget m_BtnSubmit;
	protected ButtonWidget m_BtnCancel;

	protected MultilineEditBoxWidget m_EditDescription;
	protected EditBoxWidget m_EditDiscordName;

	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("iat_report_tool/scripts/5_mission/layouts/iat_reportwindow.layout");

		m_ChkBoxTerrainReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxTerrainReport"));
		m_ChkBoxBugReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxBugReport"));
		m_ChkBoxPlayerReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxPlayerReport"));
		m_ChkBoxSuggestionReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxSuggestionReport"));
		m_ChkBoxExploitReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxExploitReport"));

		m_BtnSubmit = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnSubmit"));
		m_BtnCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnCancel"));

		m_EditDescription = MultilineEditBoxWidget.Cast(layoutRoot.FindAnyWidget("editTxtReportDescription"));
		m_EditDiscordName = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("editTxtDiscordName"));

		m_ChkBoxTerrainReport.SetChecked(true);
		m_ChkBoxBugReport.SetChecked(false);
		m_ChkBoxPlayerReport.SetChecked(false);
		m_ChkBoxSuggestionReport.SetChecked(false);
		m_ChkBoxExploitReport.SetChecked(false);

		return layoutRoot;
	}

	override void OnShow()
	{
		super.OnShow();

		// Keep the report dialog above the gameplay HUD and quickbar.
		layoutRoot.SetSort(1000, true);

		g_Game.GetInput().ChangeGameFocus(1);
		g_Game.GetUIManager().ShowUICursor(true);
		g_Game.GetMission().AddActiveInputExcludes({"menu"});
	}

	override void OnHide()
	{
		super.OnHide();

		g_Game.GetUIManager().ShowUICursor(false);
		g_Game.GetInput().ResetGameFocus();
		g_Game.GetMission().RemoveActiveInputExcludes({"menu"}, true);
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		if (!GetUApi())
			return;
		if (GetUApi().GetInputByID(UAUIBack).LocalPress())
			Close();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (w == m_BtnCancel)
		{
			Close();

			return true;
		}

		if (w == m_BtnSubmit)
		{
			SubmitReportClicked();

			Close();

			return true;
		}

		if (w == m_ChkBoxTerrainReport || w == m_ChkBoxBugReport || w == m_ChkBoxPlayerReport || w == m_ChkBoxSuggestionReport || w == m_ChkBoxExploitReport)
		{
			EnsureOnlyOneCheckboxIsSelected(w);
			return true;
		}
		return super.OnClick(w, x, y, button);
	}

	void SubmitReportClicked()
	{
		IAT_PluginReportToolClient plugin;
		if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolClient)))
		{
			IAT_ReportType reportType = GetReportType();
			string reportDescription = GetReportDescription();
			plugin.SubmitReport(reportType, reportDescription, GetDiscordName());
		}
	}

	IAT_ReportType GetReportType()
	{
		if (m_ChkBoxTerrainReport.IsChecked())
			return IAT_ReportType.TERRAIN;
		if (m_ChkBoxBugReport.IsChecked())
			return IAT_ReportType.BUG;
		if (m_ChkBoxPlayerReport.IsChecked())
			return IAT_ReportType.PLAYER;
		if (m_ChkBoxSuggestionReport.IsChecked())
			return IAT_ReportType.SUGGESTION;
		if (m_ChkBoxExploitReport.IsChecked())
			return IAT_ReportType.EXPLOIT;

		return IAT_ReportType.NO_SELECTION;
	}

	string GetReportDescription()
	{
		string descriptionText;
		m_EditDescription.GetText(descriptionText);
		descriptionText.Replace("\n", " ");
		descriptionText.TrimInPlace();
		return descriptionText;
	}

	void EnsureOnlyOneCheckboxIsSelected(Widget w)
	{
		m_ChkBoxTerrainReport.SetChecked(w == m_ChkBoxTerrainReport);
		m_ChkBoxBugReport.SetChecked(w == m_ChkBoxBugReport);
		m_ChkBoxPlayerReport.SetChecked(w == m_ChkBoxPlayerReport);
		m_ChkBoxSuggestionReport.SetChecked(w == m_ChkBoxSuggestionReport);
		m_ChkBoxExploitReport.SetChecked(w == m_ChkBoxExploitReport);
	}

	string GetDiscordName()
	{
		string discordName = m_EditDiscordName.GetText();
		discordName.TrimInPlace();
		return discordName;
	}

};
