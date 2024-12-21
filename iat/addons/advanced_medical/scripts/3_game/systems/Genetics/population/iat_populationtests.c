class IAT_PopulationTests : TestFramework
{
	void IAT_PopulationTests()
	{
		// AddInitTest("CanAddAgentsIntoABreedingPopulation");
		// AddInitTest("CanPerformASingleBreedingEvent");
		// AddInitTest("CanPerformMultipleBreedingEvents");
		// AddInitTest("CanGenerateAStartingPopulation");
	}

	void ~IAT_PopulationTests() {}

	TFResult CanAddAgentsIntoABreedingPopulation()
	{
		
		return BTFR(false);
	}
	
	TFResult CanPerformASingleBreedingEvent()
	{
		return BTFR(false);
	}
	
	TFResult CanPerformMultipleBreedingEvents()
	{
		return BTFR(false);
	}
	
	TFResult CanGenerateAStartingPopulation()
	{
		return BTFR(false);
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
	void LogPrint(string id, string expected, string actual)
	{
		PrintFormat("ID: %1 Expected: %2 Actual %3", id, expected, actual);
	}
	void LogPrint(string id, int expected, int actual)
	{
		PrintFormat("ID: %1 Expected: %2 Actual %3", id, expected, actual);
	}
};