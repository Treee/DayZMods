#ifdef DIAG_DEVELOPER
class IAT_ItemBlacklistMembership : TestSuite
{
	[Step(EStage.Setup)]
	void Prepare()
	{
		Print("[IAT_AUTOTEST] Item Blacklist membership checks");
	}

	[Step(EStage.TearDown)]
	void Finish()
	{
		Print("[IAT_AUTOTEST] Item Blacklist membership checks finished");
	}
}

// Ordinary annotated functions need no test registration or runner dependency.
[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_EmptyListAllowsItems()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(!config.IsItemBlacklisted("Apple") && !config.IsItemBlacklisted(""), "An empty blacklist must allow every item.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_FindsFirstAndLaterEntries()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[\"Apple\",\"Pear\",\"Plum\"]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(config.IsItemBlacklisted("Apple") && config.IsItemBlacklisted("Plum"), "Blacklist must search the whole configured list.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_UnlistedItemIsAllowed()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[\"Apple\",\"Pear\"]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(!config.IsItemBlacklisted("Plum"), "Unlisted items must remain allowed.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_MatchingIsCaseSensitive()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[\"Apple\"]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(config.IsItemBlacklisted("Apple") && !config.IsItemBlacklisted("apple") && !config.IsItemBlacklisted("APPLE"), "Configured class names match case exactly.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_MatchingUsesExactClassNames()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[\"Apple\",\"Rifle_Base\"]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(!config.IsItemBlacklisted("AppleSeed") && !config.IsItemBlacklisted("AKM") && !config.IsItemBlacklisted(""), "Blacklist entries are exact names, not prefixes or inherited types.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_DuplicateEntriesPreserveMembership()
{
	IAT_ItemBlacklistConfig config;
	string error;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_BlacklistedItems\":[\"Apple\",\"Apple\"]}", config, error))
		return new CustomResult(false, error);
	return new CustomResult(config.IsItemBlacklisted("Apple") && !config.IsItemBlacklisted("Pear"), "Duplicate entries must not change membership.");
}

[Test("IAT_ItemBlacklistMembership")]
TestResultBase IAT_IB_ConfigSerializationPreservesMembership()
{
	IAT_ItemBlacklistConfig original;
	IAT_ItemBlacklistConfig restored;
	string error;
	string serialized;
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData("{\"m_DebugLogEnabled\":false,\"m_BlacklistedItems\":[\"Apple\",\"Pear\"]}", original, error))
		return new CustomResult(false, error);
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.MakeData(original, serialized, error))
		return new CustomResult(false, error);
	if (!JsonFileLoader<IAT_ItemBlacklistConfig>.LoadData(serialized, restored, error))
		return new CustomResult(false, error);
	return new CustomResult(restored.IsItemBlacklisted("Apple") && restored.IsItemBlacklisted("Pear") && !restored.IsItemBlacklisted("Plum"), "Configuration serialization must preserve the blacklist.");
}
#endif
