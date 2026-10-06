modded class MissionServer
{
	protected IAT_PluginReportToolServer m_IAT_ReportPlugin;

	void MissionServer()
	{
		GetDayZGame().Event_OnRPC.Insert(IAT_RT_OnRPC);
	}

	void ~MissionServer()
	{
		GetDayZGame().Event_OnRPC.Remove(IAT_RT_OnRPC);
		if (m_IAT_ReportPlugin)
		{
			m_IAT_ReportPlugin.GetTerrainReportLocationEvent().Remove(IAT_AddTerrainReportLocation);
		}
	}

	override void OnInit()
	{
		super.OnInit();

		if (Class.CastTo(m_IAT_ReportPlugin, GetPlugin(IAT_PluginReportToolServer)))
		{
			m_IAT_ReportPlugin.GetTerrainReportLocationEvent().Insert(IAT_AddTerrainReportLocation);
		}
	}

	void IAT_RT_OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT)
		{
			IAT_PluginReportToolServer plugin;
			if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolServer)))
			{
				plugin.OnRPC(sender, rpc_type, ctx);
			}
		}
	}

	void IAT_AddTerrainReportLocation(string entryName, vector position)
	{
		JMTeleportModule teleportModule;

		if (Class.CastTo(teleportModule, GetModuleManager().GetModule(JMTeleportModule)))
		{
			teleportModule.IAT_AddReportLocation(entryName, position);
		}
	}
};
