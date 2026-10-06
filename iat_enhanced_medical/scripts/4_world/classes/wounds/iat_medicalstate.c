// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Versioned retained-bullet and dressed-wound records.
// Integration: server authority and save compatibility.
// Documentation: iat_enhanced_medical/README.md

// Server-only records. Attachments use normal inventory replication.
class IAT_MedicalState
{
	static const int STORAGE_VERSION = 1;
	int m_Bullets;
	int m_DressedWounds;
	// Diagnostic only; not written to the save stream.
	string m_LoadResult = "not_loaded";

	void Save(ParamsWriteContext ctx)
	{
		ctx.Write(STORAGE_VERSION);
		ctx.Write(m_Bullets);
		ctx.Write(m_DressedWounds);
	}

	bool Load(ParamsReadContext ctx)
	{
		int version;
		// No appended record on players saved before installing this mod.
		if (!ctx.Read(version))
		{
			m_LoadResult = "no_record_or_unreadable_header";
			return true;
		}
		if (version != STORAGE_VERSION)
		{
			m_LoadResult = "unsupported_version=" + version.ToString();
			return false;
		}
		if (!ctx.Read(m_Bullets) || !ctx.Read(m_DressedWounds))
		{
			m_LoadResult = "incomplete_record version=" + version.ToString();
			return false;
		}
		IAT_PluginMedical medical;
		if (!Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
		{
			m_LoadResult = "medical_plugin_unavailable";
			return false;
		}
		int registeredMask = medical.IAT_GetRegisteredBoneMask();
		if (registeredMask == 0)
		{
			m_LoadResult = "bleeding_definitions_unavailable";
			return false;
		}
		m_Bullets &= registeredMask;
		m_DressedWounds &= registeredMask;
		m_LoadResult = "loaded_version=" + version.ToString();
		return true;
	}
}
