class IAT_GeneBaseTests : TestFramework
{
	void IAT_GeneBaseTests()
	{
		AddInitTest("GenesHaveDefaultValues");
		AddInitTest("GenesNumBytesDeterminedByMaxBoundaryValue");
		AddInitTest("GeneValuesCanBeRepresentedAsBinaryStrings");
		AddInitTest("GeneBinaryStringsAreAlwaysByteLengths");
		AddInitTest("HelperReturnsZeroStrings");
		AddInitTest("HelperReturnsPrettyStrings");
		AddInitTest("GenesCanCrossOverWithAnotherGene");
		AddInitTest("GenesCanCrossOverWithAnotherGeneLargeDelta");
		AddInitTest("GenesCannotCrossOverWithDifferentGeneTypes");
		AddInitTest("GenesCannotCrossOverWithDifferentByteLengths");
		AddInitTest("GenesCanHaveNegativeValues");
	}

	void ~IAT_GeneBaseTests() {}

	TFResult GenesHaveDefaultValues()
	{
		IAT_GeneBase gene = new IAT_GeneBase();
		bool hasGeneType = Assert(gene.GetGeneType() == -1);
		bool hasMin = Assert(gene.GetGeneMin() == -65536);
		bool hasMax = Assert(gene.GetGeneMax() == 65536);
		bool hasValue = Assert(gene.GetValue() == 0);
		bool hasNumbBytes = Assert(gene.GetNumBytes() == 2);
		bool hasBinary = Assert(gene.GetBinaryString() == "0000000000000000");

		return BTFR(hasGeneType && hasMin && hasMax && hasValue && hasNumbBytes && hasBinary);
	}

	TFResult GenesNumBytesDeterminedByMaxBoundaryValue()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		gene.SetGeneMax(64536);
		gene.InitializeGene();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneMax(15);
		gene1.SetGeneMin(-64536);
		gene1.InitializeGene();

		// assert
		LogPrint("GenesNumBytesDeterminedByMaxBoundaryValue 1", 2, gene.GetNumBytes());
		bool hasCorrectBytes = Assert(gene.GetNumBytes() == 2);
		LogPrint("GenesNumBytesDeterminedByMaxBoundaryValue 2", 2, gene1.GetNumBytes());
		bool hasCorrectBytes1 = Assert(gene1.GetNumBytes() == 2);

		return BTFR(hasCorrectBytes && hasCorrectBytes1);
	}

	TFResult GeneValuesCanBeRepresentedAsBinaryStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		gene.SetGeneValue(255);
		gene.InitializeGene();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneValue(4096);
		gene1.InitializeGene();
		string expectedBinary = "0000000011111111"; // this is 255 as a binary string
		string expectedBinary1 = "0001000000000000";

		// act
		string actualBinary = gene.GetBinaryString();
		LogPrint("GeneValuesCanBeRepresentedAsBinaryStrings 1", expectedBinary, actualBinary);

		string actualBinary1 = gene1.GetBinaryString();
		LogPrint("GeneValuesCanBeRepresentedAsBinaryStrings 2", expectedBinary1, actualBinary1);

		// assert
		bool isBinaryCorrect = Assert(expectedBinary == actualBinary);
		bool isBinaryCorrect1 = Assert(expectedBinary1 == actualBinary1);

		return BTFR(isBinaryCorrect && isBinaryCorrect1);
	}

	TFResult HelperReturnsZeroStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		string expectedZeros = "00";
		string expectedZeros1 = "00000";

		int numZeros = 25;

		// act
		string actualZeros = gene.GetNZeros(2);
		string actualZeros1 = gene.GetNZeros(5);
		string actualZeros2 = gene.GetNZeros(numZeros);

		// assert
		LogPrint("HelperReturnsZeroStrings 1", expectedZeros, actualZeros);
		bool isZerosCorrect = Assert(expectedZeros == actualZeros);

		LogPrint("HelperReturnsZeroStrings 2", expectedZeros1, actualZeros1);
		bool isZerosCorrect2 = Assert(expectedZeros1 == actualZeros1);

		LogPrint("HelperReturnsZeroStrings 3", numZeros, actualZeros2.Length());
		bool isZerosCorrect3 = Assert(numZeros == actualZeros2.Length());

		return BTFR(isZerosCorrect && isZerosCorrect2 && isZerosCorrect3);
	}

	TFResult HelperReturnsPrettyStrings()
	{
		// arrange
		IAT_GeneBase gene = new IAT_GeneBase();
		gene.SetGeneType(IAT_GeneTypes.TESTGENE1);
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
		string expectedBinary = "0000000000000010"; // this is 2 as a binary string

		IAT_GeneBase gene2 = new IAT_GeneBase();
		string expectedBinary2 = "0000000011111111"; // this is 255 as a binary string

		IAT_GeneBase gene3 = new IAT_GeneBase();
		string expectedBinary3 = "0000000100000000"; // this is 256 as a binary string

		// act
		gene.SetGeneValue(2);
		gene.InitializeGene();

		gene2.SetGeneValue(255);
		gene2.InitializeGene();

		gene3.SetGeneValue(256);
		gene3.InitializeGene();

		string actualBinary = gene.GetBinaryString();
		string actualBinary2 = gene2.GetBinaryString();
		string actualBinary3 = gene3.GetBinaryString();
		// assert
		LogPrint("GeneBinaryStringsAreAlwaysByteLengths 1", expectedBinary, actualBinary);
		bool isBinaryCorrect = Assert(expectedBinary == actualBinary);

		LogPrint("GeneBinaryStringsAreAlwaysByteLengths 2", expectedBinary2, expectedBinary2);
		bool isBinaryCorrect2 = Assert(expectedBinary2 == actualBinary2);

		LogPrint("GeneBinaryStringsAreAlwaysByteLengths 3", expectedBinary3, actualBinary3);
		bool isBinaryCorrect3 = Assert(expectedBinary3 == actualBinary3);

		return BTFR(isBinaryCorrect && isBinaryCorrect2 && isBinaryCorrect3);
	}

	TFResult GenesCanCrossOverWithAnotherGene()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneValue(170); // "0000 0000 1010 1010"
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneValue(41); // 0000 0000 0010 1001
		gene2.InitializeGene();

		string expectedBinaryGene1 = "0000000010101010"; // 42
		string expectedBinaryGene2 = "0000000000101001"; // 169
		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);
		string actualBinaryGene1 = geneCrossover1.GetBinaryString();

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);
		string actualBinaryGene2 = geneCrossover2.GetBinaryString();

		// assert
		LogPrint("GenesCanCrossOverWithAnotherGene 1", expectedBinaryGene1, actualBinaryGene1);
		bool isBinaryCorrectGene1 = Assert(expectedBinaryGene1 == actualBinaryGene1);
		LogPrint("GenesCanCrossOverWithAnotherGene 2", expectedBinaryGene2, actualBinaryGene2);
		bool isBinaryCorrectGene2 = Assert(expectedBinaryGene2 == actualBinaryGene2);

		return BTFR(isBinaryCorrectGene1 && isBinaryCorrectGene2);
	}

	TFResult GenesCanCrossOverWithAnotherGeneLargeDelta()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneValue(2); // "0000 0000 0000 0010"
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneValue(64216); // 1111 1010 1101 1000
		gene2.InitializeGene();

		string expectedBinaryGene1 = "1111101000000010"; // 4138
		string expectedBinaryGene2 = "0000000011011000"; // 0
		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);
		string actualBinaryGene1 = geneCrossover1.GetBinaryString();

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);
		string actualBinaryGene2 = geneCrossover2.GetBinaryString();

		// assert
		LogPrint("GenesCanCrossOverWithAnotherGeneLargeDelta 1", expectedBinaryGene1, actualBinaryGene1);
		bool isBinaryCorrectGene1 = Assert(expectedBinaryGene1 == actualBinaryGene1);
		LogPrint("GenesCanCrossOverWithAnotherGeneLargeDelta 2", expectedBinaryGene2, actualBinaryGene2);
		bool isBinaryCorrectGene2 = Assert(expectedBinaryGene2 == actualBinaryGene2);

		return BTFR(isBinaryCorrectGene1 && isBinaryCorrectGene2);
	}

	TFResult GenesCannotCrossOverWithDifferentGeneTypes()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneType(IAT_GeneTypes.TESTGENE2);
		gene2.InitializeGene();

		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);

		bool geneIsNull = Assert(geneCrossover1 == null);
		bool geneIsNull1 = Assert(geneCrossover2 == null);

		// assert
		return BTFR(geneIsNull && geneIsNull1);
	}

	TFResult GenesCannotCrossOverWithDifferentByteLengths()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneMax(256);
		gene1.SetGeneMin(-256);
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.InitializeGene();

		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);

		bool geneIsNull = Assert(geneCrossover1 == null);
		bool geneIsNull1 = Assert(geneCrossover2 == null);

		// assert
		return BTFR(geneIsNull && geneIsNull1);
	}

	TFResult GenesCanHaveNegativeValues()
	{
		// arrange
		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneValue(-42); // 0000 0000 0010 1010
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneValue(-8765); // 0010 0010 0011 1101
		gene2.InitializeGene();

		// act
		IAT_GeneBase geneCrossover1 = gene1.CrossOver(gene2);
		string expectedCrossoverBinary1 = "0010001000101010";
		int expectedValue1 = -8746;

		IAT_GeneBase geneCrossover2 = gene2.CrossOver(gene1);
		string expectedCrossoverBinary2 = "0000000000111101";
		int expectedValue2 = -61;

		// assert
		LogPrint("GenesCanHaveNegativeValues 1", expectedCrossoverBinary1, geneCrossover1.GetBinaryString());
		bool hasCorrectBinary1 = Assert(expectedCrossoverBinary1 == geneCrossover1.GetBinaryString());
		LogPrint("GenesCanHaveNegativeValues 2", expectedCrossoverBinary2, geneCrossover2.GetBinaryString());
		bool hasCorrectBinary2 = Assert(expectedCrossoverBinary2 == geneCrossover2.GetBinaryString());

		LogPrint("GenesCanHaveNegativeValues 3", expectedValue1, geneCrossover1.GetValue());
		bool hasCorrectValue1 = Assert(expectedValue1 == geneCrossover1.GetValue());
		LogPrint("GenesCanHaveNegativeValues 4", expectedValue2, geneCrossover2.GetValue());
		bool hasCorrectValue2 = Assert(expectedValue2 == geneCrossover2.GetValue());

		return BTFR(hasCorrectBinary1 && hasCorrectBinary2 && hasCorrectValue1 && hasCorrectValue2);
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