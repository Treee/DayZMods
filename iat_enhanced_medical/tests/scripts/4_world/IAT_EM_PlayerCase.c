// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_PlayerCase : IAT_ScenarioCase
{
	protected PlayerBase m_Player;
	protected IAT_PluginMedical m_Medical;
	protected IAT_MedicalState m_State;
	protected BleedingSourcesManagerServer m_Manager;
	protected ref array<EntityAI> m_Items = {};
	protected ref map<string, float> m_ZoneBlood = new map<string, float>;
	protected int m_OldBullets;
	protected int m_OldDressed;
	protected float m_Health;
	protected float m_Blood;
	protected float m_Water;
	protected float m_Energy;
	protected bool m_Logging;
	protected bool m_AllowDamage;
	protected bool m_OldEnabled;
	protected bool m_Ready;
	protected int m_WoundAgents;

	void IAT_EM_PlayerCase()
	{
		m_Mod = "IAT_Enhanced_Medical";
	}
	override bool Prepare()
	{
		m_Player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!m_Player || !m_Player.GetModifiersManager() || !m_Player.GetBleedingManagerServer())
			return false;
		m_Medical = IAT_PluginMedical.Cast(GetPlugin(IAT_PluginMedical));
		Check(m_Medical != null, "Production medical plugin registered", "true", (m_Medical != null).ToString());
		if (!m_Medical)
			return true;
		m_Result.Role = "offline authoritative component; dedicated-state getter supplied by test addon";
		m_Manager = m_Player.GetBleedingManagerServer();
		Check(m_Player.GetBleedingBits() == 0, "Fixture starts without bleeding", "0", m_Player.GetBleedingBits().ToString());
		if (m_Player.GetBleedingBits() != 0)
			return true;
		m_OldEnabled = m_Player.m_IAT_EM_TestStateEnabled;
		m_Player.m_IAT_EM_TestStateEnabled = true;
		m_State = m_Player.IAT_GetMedicalState();
		m_OldBullets = m_State.m_Bullets;
		m_OldDressed = m_State.m_DressedWounds;
		m_State.m_Bullets = 0;
		m_State.m_DressedWounds = 0;
		m_Logging = m_Medical.m_LoggingEnabled;
		m_Medical.m_LoggingEnabled = false;
		m_Health = m_Player.GetHealth("", "Health");
		m_Blood = m_Player.GetHealth("", "Blood");
		m_Water = m_Player.GetStatWater().Get();
		m_Energy = m_Player.GetStatEnergy().Get();
		m_AllowDamage = m_Player.GetAllowDamage();
		m_WoundAgents = m_Player.GetSingleAgentCount(eAgents.WOUND_AGENT);
		m_Player.SetAllowDamage(true);
		m_Ready = true;
		map<string, ref IAT_MedicalZoneDefinition> zones = m_Medical.IAT_GetDamageZones();
		Check(zones != null, "Medical zone definitions initialized", "true", (zones != null).ToString());
		if (!zones) return true;
		foreach (string zone, IAT_MedicalZoneDefinition definition : zones)
		{
			m_ZoneBlood.Insert(zone, m_Player.GetHealth(zone, "Blood"));
			m_Player.SetHealth(zone, "Blood", m_Player.GetMaxHealth(zone, "Blood"));
		}
		m_Manager.IAT_EM_TestResetClock();
		m_Ready = true;
		return true;
	}
	ItemBase Item(string type)
	{
		ItemBase item = ItemBase.Cast(g_Game.CreateObjectEx(type, m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		Check(item != null, "Create fixture " + type, "true", (item != null).ToString());
		if (item)
			m_Items.Insert(item);
		return item;
	}
	EntityAI Dress(string zone)
	{
		string slot = m_Medical.IAT_GetBandageSlot(zone);
		EntityAI item = m_Player.GetInventory().CreateAttachmentEx(m_Medical.IAT_GetBandageClass(zone), InventorySlots.GetSlotIdFromString(slot));
		Check(item != null, "Attach covering dressing for " + zone, "true", (item != null).ToString());
		if (item)
			m_Items.Insert(item);
		return item;
	}
	void Blood(string zone, float fraction)
	{
		m_Player.SetHealth(zone, "Blood", m_Player.GetMaxHealth(zone, "Blood") * fraction);
	}
	void EqualInt(int actual, int expected, string label)
	{
		Check(actual == expected, label, expected.ToString(), actual.ToString());
	}
	void Near(float actual, float expected, string label, float tolerance = 0.001)
	{
		Check(Math.AbsFloat(actual - expected) <= tolerance, label, expected.ToString(), actual.ToString());
	}
	override bool Cleanup()
	{
		if (!m_Ready)
			return true;
		m_State.m_DressedWounds = 0;
		m_State.m_Bullets = 0;
		m_Manager.RemoveAllSources();
		m_Manager.IAT_EM_TestResetClock();
		foreach (EntityAI item : m_Items)
		{
			if (item)
				g_Game.ObjectDelete(item);
		}
		m_Items.Clear();
		foreach (string zone, float value : m_ZoneBlood)
			m_Player.SetHealth(zone, "Blood", value);
		m_Player.SetHealth("", "Health", m_Health);
		m_Player.SetHealth("", "Blood", m_Blood);
		m_Player.GetStatWater().Set(m_Water);
		m_Player.GetStatEnergy().Set(m_Energy);
		// Restore only the infection agent touched by vanilla source removal.
		m_Player.RemoveAgent(eAgents.WOUND_AGENT);
		if (m_WoundAgents > 0) m_Player.InsertAgent(eAgents.WOUND_AGENT, m_WoundAgents);
		m_Player.SetAllowDamage(m_AllowDamage);
		m_State.m_Bullets = m_OldBullets;
		m_State.m_DressedWounds = m_OldDressed;
		m_Medical.m_LoggingEnabled = m_Logging;
		m_Player.m_IAT_EM_TestStateEnabled = m_OldEnabled;
		EqualInt(m_Player.GetBleedingBits(), 0, "Cleanup removes all fixture bleeds");
		// Release borrowed systems while the mission still owns them. Cases
		// remain in the registry until engine shutdown.
		m_State = null;
		m_Manager = null;
		m_Medical = null;
		m_Player = null;
		m_Ready = false;
		return true;
	}
}
#endif
#endif
