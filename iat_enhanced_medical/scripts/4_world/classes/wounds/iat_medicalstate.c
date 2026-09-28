// Server-only records. Attachments use normal inventory replication.
class IAT_MedicalState
{
	static const int STORAGE_VERSION = 1;
	int Wounds;
	int Bullets;
	int DressedWounds;
	// Diagnostic only; not written to the save stream.
	string LoadResult = "not_loaded";

	void Save(ParamsWriteContext ctx)
	{
		ctx.Write(STORAGE_VERSION);
		ctx.Write(Wounds);
		ctx.Write(Bullets);
		ctx.Write(DressedWounds);
	}

	bool Load(ParamsReadContext ctx)
	{
		int version;
		// No appended record on players saved before installing this mod.
		if (!ctx.Read(version))
		{
			LoadResult = "no_record_or_unreadable_header";
			return true;
		}
		if (version != STORAGE_VERSION)
		{
			LoadResult = "unsupported_version=" + version.ToString();
			return false;
		}
		if (!ctx.Read(Wounds) || !ctx.Read(Bullets) || !ctx.Read(DressedWounds))
		{
			LoadResult = "incomplete_record version=" + version.ToString();
			return false;
		}
		Wounds &= PluginIATMedical.IAT_BULLET_BONE_MASK_ALL;
		Bullets &= PluginIATMedical.IAT_BULLET_BONE_MASK_ALL;
		DressedWounds &= Wounds;
		LoadResult = "loaded_version=" + version.ToString();
		return true;
	}
}
