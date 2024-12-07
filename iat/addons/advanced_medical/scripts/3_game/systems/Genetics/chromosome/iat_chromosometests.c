class IAT_ChromosomeTests : TestFramework
{
	void IAT_ChromosomeTests()
	{
		AddInitTest("ChromosomesHaveAMapOfGenes");
		AddInitTest("ChromosomesCanInsertNewGenes");
		AddInitTest("ChromosomesAddingExistingGeneOverwrites");
	}

	void ~IAT_ChromosomeTests() {}

	TFResult ChromosomesHaveAMapOfGenes()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		// act
		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();

		// assert
		bool isNotNull = Assert(genes != NULL);

		return BTFR(isNotNull);
	}

	TFResult ChromosomesCanInsertNewGenes()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.Gene1);
		gene1.SetGeneValue(42);
		gene1.SetGeneMin(0);
		gene1.SetGeneMax(255);

		// act
		chromosome.InsertGene(gene1);
		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();
		IAT_GeneBase actualGene = genes.Get(IAT_GeneTypes.Gene1);
		// assert
		LogPrint("1", "1", genes.Count().ToString());
		bool hasGenes = Assert(genes.Count() == 1);
		LogPrint("2", gene1.GetValue().ToString(), actualGene.GetValue().ToString());
		bool hasCorrectGene = Assert(actualGene.GetValue() == gene1.GetValue());

		return BTFR(hasGenes && hasCorrectGene);								
	}

	TFResult ChromosomesAddingExistingGeneOverwrites()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.Gene1);
		gene1.SetGeneValue(42);

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneType(IAT_GeneTypes.Gene1);
		gene2.SetGeneValue(99);

		// act
		chromosome.InsertGene(gene1);
		chromosome.InsertGene(gene2);
		
		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();
		IAT_GeneBase actualGene = genes.Get(IAT_GeneTypes.Gene1);
		// assert
		LogPrint("1", "1", genes.Count().ToString());
		bool hasGenes = Assert(genes.Count() == 1);
		LogPrint("2", gene2.GetValue().ToString(), actualGene.GetValue().ToString());
		bool hasCorrectGene = Assert(actualGene.GetValue() == gene2.GetValue());

		return BTFR(hasGenes && hasCorrectGene);
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
	void LogPrint(string id, string expected, string actual)
	{
		PrintFormat("ID: %1 Expected: %2 Actual %3", id, expected, actual);
	}
};