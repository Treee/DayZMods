class IAT_GeneBaseTests : TestFramework
{
	void IAT_GeneBaseTests()
	{
		AddInitTest("GenesHaveDefaultValues");
		AddInitTest("GeneValuesCanBeRepresentedAsBinaryStrings");
		AddInitTest("GeneBinaryStringsAreAlwaysByteLengths");
		AddInitTest("HelperReturnsZeroStrings");
		AddInitTest("HelperReturnsPrettyStrings");
		AddInitTest("GenesCanCrossOverWithAnotherGene");
	}

	void ~IAT_GeneBaseTests() {}

	TFResult GenesHaveDefaultValues()
	{
		IAT_GeneBase gene = new IAT_GeneBase();
		bool hasGeneType = Assert(gene.GetGeneType() == -1);
		bool hasMin = Assert(gene.GetGeneMin() == -999999);
		bool hasMax = Assert(gene.GetGeneMax() == 999999);
		bool hasValue = Assert(gene.GetValue() == 0);

		return BTFR(hasGeneType && hasMin && hasMax && hasValue);
	}

	TFResult GeneValuesCanBeRepresentedAsBinaryStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		gene.SetGeneValue(255);
		string expectedBinary = "11111111"; // this is 255 as a binary string
		// act
		string actualBinary = gene.GetValueAsBinary();
		PrintFormat("Expected: %1 Actual: %2", expectedBinary, actualBinary);
		// assert
		bool isBinaryCorrect = Assert(expectedBinary == actualBinary);
		return BTFR(isBinaryCorrect);
	}

	TFResult HelperReturnsZeroStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		string expectedZeros = "00";
		string expectedZeros1 = "00000";

		int numZeros = 7;

		// act
		string actualZeros = gene.GetNZeros(2);
		string actualZeros1 = gene.GetNZeros(5);
		string actualZeros2 = gene.GetNZeros(numZeros);

		// assert
		PrintFormat("Expected: %1 Actual: %2", expectedZeros, actualZeros);
		bool isZerosCorrect = Assert(expectedZeros == actualZeros);

		PrintFormat("Expected: %1 Actual: %2", expectedZeros1, actualZeros1);
		bool isZerosCorrect2 = Assert(expectedZeros1 == actualZeros1);

		PrintFormat("Expected: %1 Actual: %2", numZeros, actualZeros2.Length());
		bool isZerosCorrect3 = Assert(numZeros == actualZeros2.Length());

		return BTFR(isZerosCorrect && isZerosCorrect2 && isZerosCorrect3);
	}
	
	TFResult HelperReturnsPrettyStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		gene.SetGeneType(IAT_GeneTypes.Gene1);
		gene.SetGeneValue(99);
		gene.SetGeneMin(0);
		gene.SetGeneMax(255);
		string expectedString = "Type: 0, Min: 0, Value: 99, Max: 255";
		// act
		string actualFormattedString = gene.ToPrettyString();
		
		// assert
		bool isEqual = Assert(actualFormattedString == expectedString);
		return BTFR(true);
	}

	TFResult GeneBinaryStringsAreAlwaysByteLengths()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		string expectedBinary = "00000010"; // this is 2 as a binary string

		IAT_GeneBase gene2 = new IAT_GeneBase();
		string expectedBinary2 = "11111111"; // this is 255 as a binary string

		IAT_GeneBase gene3 = new IAT_GeneBase();
		string expectedBinary3 = "0000000100000000"; // this is 256 as a binary string

		// act
		gene.SetGeneValue(2);
		gene2.SetGeneValue(255);
		gene3.SetGeneValue(256);

		string actualBinary = gene.GetValueAsBinary();
		string actualBinary2 = gene2.GetValueAsBinary();
		string actualBinary3 = gene3.GetValueAsBinary();
		// assert
		PrintFormat("Expected: %1 Actual: %2", expectedBinary, actualBinary);
		bool isBinaryCorrect = Assert(expectedBinary == actualBinary);

		PrintFormat("Expected2: %1 Actual: %2", expectedBinary2, expectedBinary2);
		bool isBinaryCorrect2 = Assert(expectedBinary2 == actualBinary2);

		PrintFormat("Expected3: %1 Actual: %2", expectedBinary3, actualBinary3);
		bool isBinaryCorrect3 = Assert(expectedBinary3 == actualBinary3);

		return BTFR(isBinaryCorrect && isBinaryCorrect2 && isBinaryCorrect3);
	}

	TFResult GenesCanCrossOverWithAnotherGene()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneValue(170); // "1010 1010"

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneValue(41); // 0010 1001

		string expectedBinaryGene1 = "00101010"; // 42
		string expectedBinaryGene2 = "10101001"; // 169
		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);
		string actualBinaryGene1 = geneCrossover1.GetValueAsBinary();

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);
		string actualBinaryGene2 = geneCrossover2.GetValueAsBinary();

		// assert
		LogPrint("1", expectedBinaryGene1, actualBinaryGene1);
		bool isBinaryCorrectGene1 = Assert(expectedBinaryGene1 == actualBinaryGene1);
		LogPrint("2", expectedBinaryGene2, actualBinaryGene2);
		bool isBinaryCorrectGene2 = Assert(expectedBinaryGene2 == actualBinaryGene2);

		return BTFR(isBinaryCorrectGene1 && isBinaryCorrectGene2);
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
	void LogPrint(string id, string expected, string actual)
	{
		PrintFormat("ID: %1 Expected: %2 Actual %3", id, expected, actual);
	}
};