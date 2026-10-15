class IAT_CodelockPassword_BaseMenu extends UIScriptedMenu
{
	protected PasswordEditBoxWidget m_PrimaryPasswordEditBox;
    protected ImageWidget m_ButtonShowPassword;
    protected ImageWidget m_ButtonHidePassword;

    protected IAT_Codelock_Colorbase m_Codelock; // codelock reference
    protected bool m_IsPasswordVisible = false; // Track password visibility state

	// =========================================================== EVENTS
    override void OnShow()
    {
        super.OnShow();
        g_Game.GetMission().AddActiveInputExcludes({"menu"});
    }

    override void OnHide()
    {
        super.OnHide();
        g_Game.GetMission().RemoveActiveInputExcludes({"menu"},true);
    }
    // cheap hook to let ESC close the widgets
    override void Update(float timeslice)
	{
        super.Update(timeslice);
        if (GetUApi().GetInputByID(UAUIBack).LocalPress())
		{
			Close();
		}
    }
	// =========================================================== CUSTOM CODE
	void ClearCodelock()
	{
        m_Codelock = null;
    }
    void SetCodelock(IAT_Codelock_Colorbase codelock)
    {
        m_Codelock = codelock;
    }
    void OnToggleLock()
    {
		// if the lock exists, toggle it
		if (m_Codelock)
        	m_Codelock.ToggleLock();
    }
	void OnTogglePasswordVisibility()
    {
        m_IsPasswordVisible = !m_IsPasswordVisible;
        if (m_IsPasswordVisible)
        {
            m_PrimaryPasswordEditBox.SetHideText(false); // Show the password text
            m_ButtonShowPassword.Show(true);
            m_ButtonHidePassword.Show(false);
        }
        else
        {
            m_PrimaryPasswordEditBox.SetHideText(true); // Hide the password text
            m_ButtonShowPassword.Show(false);
            m_ButtonHidePassword.Show(true);
        }
    }
};