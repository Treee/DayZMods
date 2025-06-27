class IAT_CodelockPasswordEntryMenu extends IAT_CodelockPassword_BaseMenu
{
    protected ButtonWidget m_ButtonOk;
    protected ButtonWidget m_ButtonCancel;
    protected ButtonWidget m_ButtonPasswordIcons;
    protected ButtonWidget m_ButtonCancel1;

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("iat_codelock/scripts/5_mission/layouts/iat_codelock_password_entry.layout");

        m_ButtonCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonCancel"));
        m_PrimaryPasswordEditBox = PasswordEditBoxWidget.Cast(layoutRoot.FindAnyWidget("PrimaryPasswordEditBox"));
        m_ButtonPasswordIcons = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonPasswordIcons"));
        m_ButtonShowPassword = ImageWidget.Cast(layoutRoot.FindAnyWidget("ButtonShowPassword"));
        m_ButtonHidePassword = ImageWidget.Cast(layoutRoot.FindAnyWidget("ButtonHidePassword"));
        m_ButtonOk = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonOk"));
        m_ButtonCancel1 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonCancel1"));

        m_ButtonHidePassword.Show(true); // Initially show the hide button
        m_ButtonShowPassword.Show(false);
        return layoutRoot;
    }

	// =========================================================== EVENTS
    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_ButtonCancel || w == m_ButtonCancel1)
        {
            Close();
            return true;
        }
        else if (w == m_ButtonOk)
        {
            OnConfirmPasscode();
            return true;
        }
        else if (w == m_ButtonPasswordIcons)
        {
            OnTogglePasswordVisibility();
            return true;
        }
        return false;
    }

    void OnConfirmPasscode()
    {
        m_Codelock.ClientRPC_EnterPassword(m_PrimaryPasswordEditBox.GetText());
        m_PrimaryPasswordEditBox.SetText(""); // Clear the text after changing
        m_IsPasswordVisible = false; // Reset visibility state
        ClearCodelock(); // clear the codelock reference
        Close();
    }
}