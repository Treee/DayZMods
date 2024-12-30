modded class MissionGameplay
{
  	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		UIScriptedMenu menu = m_UIManager.GetMenu();

		IAT_FP_RadialMenuDisplay facePaintMenu = IAT_FP_RadialMenuDisplay.Cast( m_UIManager.FindMenu(MENU_NOTE) );
		if (!m_UIManager.IsDialogVisible())
		{
			if (menu)
			{
				if (menu == facePaintMenu && !facePaintMenu.IsMenuClosing() && !IsInputExcludeActive("radialmenu"))
				{
					AddActiveInputExcludes({"radialmenu"});
					GetUApi().GetInputByID(UAUIGesturesOpen).Unlock();
				}
			}
		}
  	}
};