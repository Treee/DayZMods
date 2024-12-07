class IAT_PopulationTests : TestFramework
{
	void IAT_PopulationTests()
	{
		// AddInitTest("GenesHaveDefaultValues");
	}

	void ~IAT_PopulationTests() {}

	TFResult ChromosomesHaveACollectionOfGenes()
	{
		// IAT_GeneBase gene = new IAT_GeneBase();
		// bool hasGeneType = Assert(gene.GetGeneType() == -1);
		// bool hasMin = Assert(gene.GetGeneMin() == -999999);
		// bool hasMax = Assert(gene.GetGeneMax() == 999999);
		// bool hasValue = Assert(gene.GetValue() == 0);

		// return BTFR(hasGeneType && hasMin && hasMax && hasValue);
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
	void LogPrint(string id, string expected, string actual)
	{
		PrintFormat("ID: %1 Expected: %2 Actual %3", id, expected, actual);
	}
};