// IAT Enhanced Medical | Owner: ItsATreee | Layer: 5_Mission
//! Client retained-bullet badge, sharing vanilla HUD visibility and badge layout.
modded class IngameHud
{
	// A mod-owned key outside the positive vanilla notifier keys.
	protected static const int IAT_RETAINED_BULLET_BADGE = -17401;

	override void InitBadgesAndNotifiers()
	{
		super.InitBadgesAndNotifiers();
		ImageWidget bullet = ImageWidget.Cast(m_Badges.FindAnyWidget("IAT_RetainedBullet"));
		if (!bullet)
			bullet = ImageWidget.Cast(g_Game.GetWorkspace().CreateWidgets("iat_enhanced_medical/scripts/gui/layouts/IAT_RetainedBullet.layout", m_Badges));
		if (!bullet)
			return;
		bullet.Show(false);
		m_BadgesWidgetNames.Set(IAT_RETAINED_BULLET_BADGE, "IAT_RetainedBullet");
		m_BadgesWidgets.Set(IAT_RETAINED_BULLET_BADGE, bullet);
		m_BadgesWidgetDisplay.Set(IAT_RETAINED_BULLET_BADGE, 0);
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		if (!m_BadgesWidgets.Contains(IAT_RETAINED_BULLET_BADGE))
			return;
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		int visible;
		if (player && player.IAT_HasRetainedBullet())
			visible = 1;
		if (m_BadgesWidgetDisplay.Get(IAT_RETAINED_BULLET_BADGE) != visible)
			DisplayBadge(IAT_RETAINED_BULLET_BADGE, visible);
	}
}
