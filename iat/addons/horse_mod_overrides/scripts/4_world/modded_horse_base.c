modded class Horse_Base
{
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);

		if (GetGame().IsDedicatedServer())
		{
			PluginAdminLog m_AdminLog;
			if (Class.CastTo(m_AdminLog, GetPlugin(PluginAdminLog)))
			{
				m_AdminLog.HorseKilled(this, killer);
			}
		}
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if (GetGame().IsDedicatedServer())
		{
			PluginAdminLog m_AdminLog;
			if (Class.CastTo(m_AdminLog, GetPlugin(PluginAdminLog)))
			{
				m_AdminLog.HorseHitBy(damageResult, damageType, this, source, component, dmgZone, ammo);
			}
		}
	}
};