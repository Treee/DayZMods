class IAT_GeneTests : TestFramework
{
	void IAT_GeneTests()
	{
		AddInitTest("InvasibilityGeneHasDefaultProperties");
		AddInitTest("AutoInfectProbabilityGeneHasDefaultProperties");
		AddInitTest("TransferabilityInGeneHasDefaultProperties");
		AddInitTest("TransferabilityOutGeneHasDefaultProperties");
		AddInitTest("DigestibilityGeneHasDefaultProperties");
		AddInitTest("AntibioticEfficacyGeneHasDefaultProperties");
		AddInitTest("GrowthPotencyGeneHasDefaultProperties");
		AddInitTest("DieOffSpeedGeneHasDefaultProperties");
	}

	void ~IAT_GeneTests() {}

	TFResult InvasibilityGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_InvasibilityGene();

		bool hasGeneType = Assert(IAT_GeneTypes.INVASIBILITY == gene.GetGeneType());
		bool hasMin = Assert(-100 == gene.GetGeneMin());
		bool hasMax = Assert(100 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult AutoInfectProbabilityGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_AutoInfectProbabilityGene();

		bool hasGeneType = Assert(IAT_GeneTypes.AUTOINFECT_PROBABILITY == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(100 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult TransferabilityInGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_TransferabilityInGene();

		bool hasGeneType = Assert(IAT_GeneTypes.TRANSFERIBILITY_IN == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(50 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult TransferabilityOutGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_TransferabilityOutGene();

		bool hasGeneType = Assert(IAT_GeneTypes.TRANSFERIBILITY_OUT == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(100 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult DigestibilityGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_DigestibilityGene();

		bool hasGeneType = Assert(IAT_GeneTypes.DIGESTIBILITY == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(100 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult AntibioticEfficacyGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_AntibioticEfficacyGene();

		bool hasGeneType = Assert(IAT_GeneTypes.ANTIBIOTIC_EFFICACY == gene.GetGeneType());
		bool hasMin = Assert(10 == gene.GetGeneMin());
		bool hasMax = Assert(200 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult GrowthPotencyGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_GrowthPotencyGene();

		bool hasGeneType = Assert(IAT_GeneTypes.GROWTH_POTENCY == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(5 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult DieOffSpeedGeneHasDefaultProperties()
	{
		IAT_GeneBase gene = new IAT_DieOffSpeedGene();

		bool hasGeneType = Assert(IAT_GeneTypes.DIE_OFF_SPEED == gene.GetGeneType());
		bool hasMin = Assert(0 == gene.GetGeneMin());
		bool hasMax = Assert(200 == gene.GetGeneMax());
		bool hasValue = Assert(0 == gene.GetValue());
		bool hasNumbBytes = Assert(1 == gene.GetNumBytes());
		bool hasBinary = Assert("00000000" == gene.GetBinaryString());

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
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