modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATReportToolConfig(GetDayZGame().GetIATReportToolConfig());

		GetDayZGame().Event_OnRPC.Insert(IAT_RT_OnRPC);
	}

	void ~MissionServer()
    {
        GetDayZGame().Event_OnRPC.Remove(IAT_RT_OnRPC);
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
};