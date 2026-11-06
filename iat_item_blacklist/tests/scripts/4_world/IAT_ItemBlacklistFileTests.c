#ifdef DIAG_DEVELOPER
class IAT_ItemBlacklistFiles : TestSuite
{
	[Step(EStage.Setup)]
	void Prepare()
	{
		Print("[IAT_AUTOTEST] Item Blacklist profile-file checks");
	}

	[Step(EStage.TearDown)]
	void Finish()
	{
		Print("[IAT_AUTOTEST] Item Blacklist profile-file checks finished");
	}
}

// Redirect only this fixture's storage; production visibility and paths stay unchanged.
class IAT_IB_FileFixture : IAT_ItemBlacklistConfig
{
	void IAT_IB_FileFixture(string filename)
	{
		m_RootConfigFolder = "IAT_Autotest_ItemBlacklist";
		m_JsonFile = filename;
	}

	string Path()
	{
		return m_DayZFolder + "\\" + m_RootConfigFolder + "\\" + m_JsonFile;
	}

	bool RemoveFile()
	{
		if (!FileExist(Path()))
			return true;
		return DeleteFile(Path());
	}
}

[Test("IAT_ItemBlacklistFiles")]
TestResultBase IAT_IB_MissingFileCreatesEmptyConfiguration()
{
	IAT_IB_FileFixture fixture = new IAT_IB_FileFixture("defaults.json");
	if (!fixture.RemoveFile())
		return new CustomResult(false, "Cannot clear the defaults fixture.");

	IAT_ItemBlacklistConfig created = fixture.TryGetItemBlacklistConfig();
	bool passed = created && FileExist(fixture.Path());
	if (passed)
		passed = !created.IsItemBlacklisted("Apple") && !created.IsItemBlacklisted("Pear");

	bool cleaned = fixture.RemoveFile();
	return new CustomResult(passed && cleaned, "A missing config must create an empty blacklist; its fixture file must be removed.");
}

[Test("IAT_ItemBlacklistFiles")]
TestResultBase IAT_IB_ExistingFileLoadsConfiguredItems()
{
	IAT_IB_FileFixture fixture = new IAT_IB_FileFixture("configured.json");
	if (!fixture.RemoveFile())
		return new CustomResult(false, "Cannot clear the configured fixture.");

	// Create the fixture directory through the real first-run path.
	IAT_ItemBlacklistConfig initial = fixture.TryGetItemBlacklistConfig();
	FileHandle file = OpenFile(fixture.Path(), FileMode.WRITE);
	if (!file)
	{
		fixture.RemoveFile();
		return new CustomResult(false, "Cannot write the configured fixture.");
	}
	FPrint(file, "{\"m_DebugLogEnabled\":false,\"m_BlacklistedItems\":[\"Apple\",\"Pear\"]}");
	CloseFile(file);

	IAT_ItemBlacklistConfig loaded = fixture.TryGetItemBlacklistConfig();
	bool passed = loaded != null;
	if (passed)
		passed = loaded.IsItemBlacklisted("Apple") && loaded.IsItemBlacklisted("Pear") && !loaded.IsItemBlacklisted("Plum");

	bool cleaned = fixture.RemoveFile();
	return new CustomResult(passed && cleaned, "An existing config must load its items; its fixture file must be removed.");
}
#endif
