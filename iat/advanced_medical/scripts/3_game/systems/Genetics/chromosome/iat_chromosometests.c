class IAT_ChromosomeTests : TestFramework
{
	void IAT_ChromosomeTests()
	{
		AddInitTest("ChromosomesHaveAMapOfGenes");
		AddInitTest("ChromosomesCanInsertNewGenes");
		AddInitTest("ChromosomesAddingExistingGeneOverwrites");
		AddInitTest("ChromosomesCanHaveManyGenes");
		AddInitTest("ChromosomesCanReturnASpecificGene");
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
		gene1.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene1.SetGeneValue(42);
		gene1.SetGeneMin(0);
		gene1.SetGeneMax(255);
		gene1.InitializeGene();

		// act
		chromosome.InsertGene(gene1);
		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();
		IAT_GeneBase actualGene = genes.Get(IAT_GeneTypes.TESTGENE1);
		// assert
		LogPrint("ChromosomesCanInsertNewGenes 1", "1", genes.Count().ToString());
		bool hasGenes = Assert(genes.Count() == 1);
		LogPrint("ChromosomesCanInsertNewGenes 2", gene1.GetValue().ToString(), actualGene.GetValue().ToString());
		bool hasCorrectGene = Assert(actualGene.GetValue() == gene1.GetValue());

		return BTFR(hasGenes && hasCorrectGene);
	}

	TFResult ChromosomesAddingExistingGeneOverwrites()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene1.SetGeneValue(42);
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene2.SetGeneValue(99);
		gene2.InitializeGene();

		// act
		chromosome.InsertGene(gene1);
		chromosome.InsertGene(gene2);

		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();
		IAT_GeneBase actualGene = genes.Get(IAT_GeneTypes.TESTGENE1);
		// assert
		LogPrint("ChromosomesAddingExistingGeneOverwrites 1", "1", genes.Count().ToString());
		bool hasGenes = Assert(genes.Count() == 1);
		LogPrint("ChromosomesAddingExistingGeneOverwrites 2", gene2.GetValue().ToString(), actualGene.GetValue().ToString());
		bool hasCorrectGene = Assert(actualGene.GetValue() == gene2.GetValue());

		return BTFR(hasGenes && hasCorrectGene);
	}

	TFResult ChromosomesCanHaveManyGenes()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene1.SetGeneValue(42);
		gene1.SetGeneMin(0);
		gene1.SetGeneMax(255);
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneType(IAT_GeneTypes.TESTGENE2);
		gene2.SetGeneValue(-5721);
		gene2.InitializeGene();

		IAT_GeneBase gene3 = new IAT_GeneBase();
		gene3.SetGeneType(IAT_GeneTypes.TESTGENE3);
		gene3.SetGeneValue(4);
		gene3.InitializeGene();

		IAT_GeneBase gene4 = new IAT_GeneBase();
		gene4.SetGeneType(IAT_GeneTypes.TESTGENE4);
		gene4.SetGeneValue(51947);
		gene4.InitializeGene();

		IAT_GeneBase gene5 = new IAT_GeneBase();
		gene5.SetGeneType(IAT_GeneTypes.TESTGENE5);
		gene5.SetGeneValue(-76);
		gene5.InitializeGene();

		chromosome.InsertGene(gene1);
		chromosome.InsertGene(gene2);
		chromosome.InsertGene(gene3);
		chromosome.InsertGene(gene4);
		chromosome.InsertGene(gene5);

		// act
		map<IAT_GeneTypes, IAT_GeneBase> genes = chromosome.GetGenes();
		IAT_GeneBase actualGene = genes.Get(IAT_GeneTypes.TESTGENE2);
		// assert
		LogPrint("ChromosomesCanHaveManyGenes 1", 5, genes.Count());
		bool hasGenes = Assert(5 == genes.Count());
		LogPrint("ChromosomesCanHaveManyGenes 2", gene2.GetValue(), actualGene.GetValue());
		bool hasCorrectGene = Assert(gene2.GetValue() == actualGene.GetValue());

		return BTFR(hasGenes && hasCorrectGene);
	}
	
	TFResult ChromosomesCanReturnASpecificGene()
	{
		// arrange
		IAT_Chromosome chromosome = new IAT_Chromosome();

		IAT_GeneBase gene1 = new IAT_GeneBase();
		gene1.SetGeneType(IAT_GeneTypes.TESTGENE1);
		gene1.SetGeneValue(42);
		gene1.SetGeneMin(0);
		gene1.SetGeneMax(255);
		gene1.InitializeGene();

		IAT_GeneBase gene2 = new IAT_GeneBase();
		gene2.SetGeneType(IAT_GeneTypes.TESTGENE2);
		gene2.SetGeneValue(-5721);
		gene2.InitializeGene();

		IAT_GeneBase gene3 = new IAT_GeneBase();
		gene3.SetGeneType(IAT_GeneTypes.TESTGENE3);
		gene3.SetGeneValue(4);
		gene3.InitializeGene();

		IAT_GeneBase gene4 = new IAT_GeneBase();
		gene4.SetGeneType(IAT_GeneTypes.TESTGENE4);
		gene4.SetGeneValue(51947);
		gene4.InitializeGene();

		IAT_GeneBase gene5 = new IAT_GeneBase();
		gene5.SetGeneType(IAT_GeneTypes.TESTGENE5);
		gene5.SetGeneValue(-76);
		gene5.InitializeGene();

		chromosome.InsertGene(gene1);
		chromosome.InsertGene(gene2);
		chromosome.InsertGene(gene3);
		chromosome.InsertGene(gene4);
		chromosome.InsertGene(gene5);
		
		// act
		IAT_GeneBase actualGene = chromosome.GetGene(IAT_GeneTypes.TESTGENE4);		
		
		// assert
		bool isCorrectGeneType = Assert(gene4.GetGeneType() == actualGene.GetGeneType());
		bool isCorrectValue = Assert(gene4.GetValue() == actualGene.GetValue());
		
		return BTFR(isCorrectGeneType && isCorrectValue);
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