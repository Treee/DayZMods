class IAT_ReportMenu extends UIScriptedMenu
{
    protected CheckBoxWidget m_ChkBoxTerrainReport;
    protected CheckBoxWidget m_ChkBoxBugReport;
    protected CheckBoxWidget m_ChkBoxPlayerReport; // just in case (not implemented)

    protected ButtonWidget m_BtnSubmit;
    protected ButtonWidget m_BtnCancel;

    protected MultilineEditBoxWidget m_EditDescription;

    override Widget Init()
    {
        layoutRoot = g_Game.GetWorkspace().CreateWidgets("iat_report_tool/scripts/5_mission/layouts/iat_reportwindow.layout");


        m_ChkBoxTerrainReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxTerrainReport"));
        m_ChkBoxBugReport = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("chkBoxBugReport"));

        m_BtnSubmit = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnSubmit"));
        m_BtnCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnCancel"));

        m_EditDescription = MultilineEditBoxWidget.Cast(layoutRoot.FindAnyWidget("editTxtReportDescription"));


        m_ChkBoxTerrainReport.SetChecked(true);
        m_ChkBoxBugReport.SetChecked(false);
        PopulateDescriptionHint(m_ChkBoxTerrainReport);

        return layoutRoot;
    }

    override void OnShow()
    {
        super.OnShow();

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

	// cheap hook to let ESC close the widgets
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

        if (w == m_ChkBoxTerrainReport || w == m_ChkBoxBugReport)
        {
            EnsureOnlyOneCheckboxIsSelected(w);
            PopulateDescriptionHint(w);
        }

        return super.OnClick(w, x, y, button);
    }

    /*
    * HELPERS
    */
    void SubmitReportClicked()
    {
        IAT_PluginReportToolClient plugin;
		if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolClient)))
		{
            IAT_ReportType reportType = GetReportType();
            string reportDescription = GetReportDescription();
            // PrintFormat("Report Type: %1 Description: %2", reportType, reportDescription);
			plugin.SubmitReport(reportType, reportDescription);
		}
    }

    IAT_ReportType GetReportType()
    {
        if (m_ChkBoxTerrainReport.IsChecked())
            return IAT_ReportType.TERRAIN;
        if (m_ChkBoxBugReport.IsChecked())
            return IAT_ReportType.BUG;

        return IAT_ReportType.NO_SELECTION;
    }

    string GetReportDescription()
    {
        string descriptionText;
        m_EditDescription.GetText(descriptionText);
        descriptionText.Replace("\n", " ");
        descriptionText.Trim();
        return descriptionText;
    }

    void PopulateDescriptionHint(Widget w)
    {
        // If the widget clicked is the terrain box
        if (w == m_ChkBoxTerrainReport)
        {
            // if the other bug box is checked
            if (!m_ChkBoxBugReport.IsChecked())
            {
                m_EditDescription.SetText(Widget.TranslateString("#STR_IAT_ReportMenu_ReportDescriptionText_Terrain"));
            }
        }
        if (w == m_ChkBoxBugReport)
        {
            // if the other terrain box is checked
            if (!m_ChkBoxTerrainReport.IsChecked())
            {
                m_EditDescription.SetText(Widget.TranslateString("#STR_IAT_ReportMenu_ReportDescriptionText_Bug"));
            }
        }
    }

    void EnsureOnlyOneCheckboxIsSelected(Widget w)
    {
        // If the widget clicked is the terrain box
        if (w == m_ChkBoxTerrainReport)
        {
            // if the other bug box is checked
            if (m_ChkBoxBugReport.IsChecked())
            {
                // reset the checked value
                m_ChkBoxBugReport.SetChecked(false);
            }
        }
        if (w == m_ChkBoxBugReport)
        {
            // if the other terrain box is checked
            if (m_ChkBoxTerrainReport.IsChecked())
            {
                // reset the checked value
                m_ChkBoxTerrainReport.SetChecked(false);
            }
        }
    }
};