// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Observe vanilla source registration and anatomy.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

// Observe registrations after vanilla assigns the selection and bit. The legacy
// RegisterBleedingZone wrapper also routes through this method.
modded class BleedingSourcesManagerBase
{
	override protected void RegisterBleedingZoneEx(string name, int max_time, string bone = "", vector orientation = "0 0 0", vector offset = "0 0 0", float flow_modifier = 1, string particle_name = "BleedingSourceEffect", int inv_location = 0)
	{
		int previousCount = GetRegisteredSourcesCount();
		super.RegisterBleedingZoneEx(name, max_time, bone, orientation, offset, flow_modifier, particle_name, inv_location);
		if (!g_Game.IsServer() || GetRegisteredSourcesCount() == previousCount)
			return;
		name.ToLower();
		BleedingSourceZone meta = m_BleedingSourceZone.Get(name);
		IAT_PluginMedical medical;
		if (meta && Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			medical.IAT_RegisterBleedingSelection(m_Player, meta.GetSelectionName(), meta.GetBit());
	}
}
