modded class PlayerBase
{
	protected ref IAT_Chromosome m_Chromosome;

	void PlayerBase()
	{
		InitializeChromosome();
	}
	
	void InitializeChromosome()
	{
		m_Chromosome = new IAT_Chromosome();
		
		// percentage of how fast any agents naturally grow within an organism 0 to 2.5x
		IAT_GeneBase invasibilityGene = new IAT_GeneBase();
		invasibilityGene.SetGeneType(IAT_GeneTypes.INVASIBILITY);
		invasibilityGene.SetGeneValue(42);
		invasibilityGene.SetGeneMin(0);
		invasibilityGene.SetGeneMax(255);
		invasibilityGene.InitializeGene();
		
		// percentage chance of just getting infected at random (related to transferibility) 0 to 2.5x
		IAT_GeneBase autoInfectGene = new IAT_GeneBase();
		autoInfectGene.SetGeneType(IAT_GeneTypes.AUTOINFECT_PROBABILITY);
		autoInfectGene.SetGeneValue(42);
		autoInfectGene.SetGeneMin(0);
		autoInfectGene.SetGeneMax(255);
		autoInfectGene.InitializeGene();
		
		// percentage of how susceptible the player is to 'catching' an existing illness
		IAT_GeneBase transferInGene = new IAT_GeneBase();
		transferInGene.SetGeneType(IAT_GeneTypes.TRANSFERIBILITY_IN);
		transferInGene.SetGeneValue(42);
		transferInGene.SetGeneMin(0);
		transferInGene.SetGeneMax(255);
		transferInGene.InitializeGene();
		
		// percentage of how susceptible the player is to 'distributing' an existing illness
		IAT_GeneBase transferOutGene = new IAT_GeneBase();
		transferOutGene.SetGeneType(IAT_GeneTypes.TRANSFERIBILITY_OUT);
		transferOutGene.SetGeneValue(42);
		transferOutGene.SetGeneMin(0);
		transferOutGene.SetGeneMax(255);
		transferOutGene.InitializeGene();
		
		// percentage of how digestible agents naturally are within a stomach
		IAT_GeneBase digestibilityGene = new IAT_GeneBase();
		digestibilityGene.SetGeneType(IAT_GeneTypes.DIGESTIBILITY);
		digestibilityGene.SetGeneValue(42);
		digestibilityGene.SetGeneMin(0);
		digestibilityGene.SetGeneMax(255);
		digestibilityGene.InitializeGene();
		
		// percent usefullness of antibiotics for a player
		IAT_GeneBase antibioticGene = new IAT_GeneBase();
		antibioticGene.SetGeneType(IAT_GeneTypes.ANTIBIOTIC_EFFICACY);
		antibioticGene.SetGeneValue(42);
		antibioticGene.SetGeneMin(0);
		antibioticGene.SetGeneMax(255);
		antibioticGene.InitializeGene();
		
		// the number of levels below normal illness can grow (1-3)
		IAT_GeneBase growthPotencyGene = new IAT_GeneBase();
		growthPotencyGene.SetGeneType(IAT_GeneTypes.GROWTH_POTENCY);
		growthPotencyGene.SetGeneValue(0);
		growthPotencyGene.SetGeneMin(0);
		growthPotencyGene.SetGeneMax(255);
		growthPotencyGene.InitializeGene();
		
		// percentage of how fast any agents naturally die within the player
		IAT_GeneBase dieOffSpeedGene = new IAT_GeneBase();
		dieOffSpeedGene.SetGeneType(IAT_GeneTypes.DIE_OFF_SPEED);
		dieOffSpeedGene.SetGeneValue(42);
		dieOffSpeedGene.SetGeneMin(0);
		dieOffSpeedGene.SetGeneMax(255);
		dieOffSpeedGene.InitializeGene();
				
		m_Chromosome.Insert(invasibilityGene);
		m_Chromosome.Insert(autoInfectGene);
		m_Chromosome.Insert(transferInGene);
		m_Chromosome.Insert(transferOutGene);
		m_Chromosome.Insert(digestibilityGene);
		m_Chromosome.Insert(antibioticGene);
		m_Chromosome.Insert(growthPotencyGene);
		m_Chromosome.Insert(dieOffSpeedGene);
		
	}

	IAT_Chromosome GetChromosome()
	{
		return m_Chromosome;
	}
};