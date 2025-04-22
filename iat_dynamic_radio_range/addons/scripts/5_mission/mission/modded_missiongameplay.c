modded class MissionGameplay
{
  	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		UIScriptedMenu menu = m_UIManager.GetMenu();

		IAT_DR_RadialMenuDisplay dynamicRadioMenu = IAT_DR_RadialMenuDisplay.Cast( m_UIManager.FindMenu(MENU_NOTE) );
		if (!m_UIManager.IsDialogVisible())
		{
			if (menu)
			{
				if (menu == dynamicRadioMenu && !dynamicRadioMenu.IsMenuClosing() && !IsInputExcludeActive("menu"))
				{
					AddActiveInputExcludes({"menu"});
				}
			}
		}
  	}
};