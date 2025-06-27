class IAT_CodelockPasswordDialogMenu extends IAT_CodelockPassword_BaseMenu
{
    protected TextWidget m_WindowLabel;

    protected ButtonWidget m_ButtonCancel;
    protected ButtonWidget m_ButtonPasswordIcons;
    protected ButtonWidget m_ButtonToggleLock;
    protected ButtonWidget m_ButtonChangePasscode;
    protected ButtonWidget m_ButtonConfirmPasscode;
    protected ButtonWidget m_ButtonCancelConfirm;

    void IAT_CodelockPasswordDialogMenu()
    {
        IAT_Codelock_Colorbase.SyncEvent_OnClientCodelockInfoUpdate.Insert(UpdateToggleLockText); // Subscribe to the codelock info update event
    }
    void ~IAT_CodelockPasswordDialogMenu()
    {
        ClearCodelock(); // Clear the codelock reference when the dialog is destroyed
        IAT_Codelock_Colorbase.SyncEvent_OnClientCodelockInfoUpdate.Remove(UpdateToggleLockText); // Unsubscribe from the codelock info update event
    }
	// =========================================================== EVENTS
    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("iat_codelock/scripts/5_mission/layouts/iat_codelock_password_dialog.layout");

        m_WindowLabel = TextWidget.Cast(layoutRoot.FindAnyWidget("WindowLabel"));
        m_ButtonCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonCancel"));
        m_PrimaryPasswordEditBox = PasswordEditBoxWidget.Cast(layoutRoot.FindAnyWidget("PrimaryPasswordEditBox"));
        m_ButtonPasswordIcons = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonPasswordIcons"));
        m_ButtonShowPassword = ImageWidget.Cast(layoutRoot.FindAnyWidget("ButtonShowPassword"));
        m_ButtonHidePassword = ImageWidget.Cast(layoutRoot.FindAnyWidget("ButtonHidePassword"));
        m_ButtonToggleLock = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonToggleLock"));
        m_ButtonChangePasscode = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonChangePasscode"));

        m_ButtonConfirmPasscode = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonChangeConfirmPasscode"));
        m_ButtonCancelConfirm = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonChangeCancelConfirm"));

        m_ButtonHidePassword.Show(true); // Initially show the hide button
        m_ButtonShowPassword.Show(false);
        return layoutRoot;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_ButtonCancel)
        {
            ClearCodelock();
            Close();
            return true;
        }
        else if (w == m_ButtonToggleLock)
        {
            OnToggleLock();
            return true;
        }
        else if (w == m_ButtonChangePasscode)
        {
            OnChangePasscode();
            return true;
        }
        else if (w == m_ButtonConfirmPasscode)
        {
            OnConfirmPasscode();
            return true;
        }
        else if (w == m_ButtonCancelConfirm)
        {
            OnCancelConfirmPasscode();
            return true;
        }
        else if (w == m_ButtonPasswordIcons)
        {
            OnTogglePasswordVisibility();
            return true;
        }
        return false;
    }

    override void SetCodelock(IAT_Codelock_Colorbase codelock)
    {
        super.SetCodelock(codelock); // Call the base class method to set the codelock
        UpdateToggleLockText();
    }

    // =========================================================== CUSTOM CODE
    void UpdateToggleLockText()
    {
        if (m_Codelock)
        {
            if (m_Codelock.IAT_IsLocked())
            {
                m_ButtonToggleLock.SetText("Unlock");
            }
            else
            {
                m_ButtonToggleLock.SetText("Lock");
            }
        }
    }

    void OnChangePasscode()
    {
        // player just clicked change passcode, change the window title to reflect this
        m_WindowLabel.SetText("CONFIRM PASSCODE");
        m_ButtonToggleLock.Show(false); // Hide the toggle lock button
        m_ButtonChangePasscode.Show(false); // Hide the change passcode button

        m_ButtonConfirmPasscode.Show(true); // Show the confirm passcode button
        m_ButtonCancelConfirm.Show(true); // Show the cancel confirm button
    }

    void OnConfirmPasscode()
    {
        // rpc to the client the password has changed
        m_Codelock.ClientRPC_ChangePasscode(m_PrimaryPasswordEditBox.GetText());
        m_PrimaryPasswordEditBox.SetText(""); // Clear the text after changing
        m_IsPasswordVisible = false; // Reset visibility state
        ClearCodelock(); // clear the codelock reference
        Close(); // Close the dialog after changing the passcode
    }

    void OnCancelConfirmPasscode()
    {
        // player just clicked change passcode, change the window title to reflect this
        m_WindowLabel.SetText("MANAGE CODELOCK");
        m_ButtonToggleLock.Show(true); // show the toggle lock button
        m_ButtonChangePasscode.Show(true); // show the change passcode button

        m_ButtonConfirmPasscode.Show(false); // hide the confirm passcode button
        m_ButtonCancelConfirm.Show(false); // hide the cancel confirm button
    }
};