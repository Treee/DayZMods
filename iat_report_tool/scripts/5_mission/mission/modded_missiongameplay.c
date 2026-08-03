modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		IAT_TryOpenReportMenu();
	}

	protected void IAT_TryOpenReportMenu()
	{
		PlayerBase player;
		if (!Class.CastTo(player, g_Game.GetPlayer()))
			return;

		if (!GetUApi())
			return;

		IAT_PluginReportToolClient plugin;
		if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolClient)))
		{
			UAInput input = GetUApi().GetInputByName("IAT_UA_ToggleReportMenu");
			plugin.OpenReportMenu(input);
		}
	}
};