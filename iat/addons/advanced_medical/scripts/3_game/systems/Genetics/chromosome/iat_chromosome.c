class IAT_Chromosome
{
	ref map<IAT_GeneTypes, IAT_GeneBase> m_Genes = new map<IAT_GeneTypes, IAT_GeneBase>();

	void IAT_Chromosome()
	{
	}
	
	void InsertGene(IAT_GeneBase newGene)
	{
		if (m_Genes.Contains(newGene.GetGeneType()))
		{
			m_Genes.Set(newGene.GetGeneType(), newGene);
		}
		else
		{
			m_Genes.Insert(newGene.GetGeneType(), newGene);		
		}		
	}

	map<IAT_GeneTypes, IAT_GeneBase> GetGenes()
	{
		return m_Genes;
	}
	
	IAT_GeneBase GetGene(IAT_GeneTypes geneType)
	{
		return m_Genes.Get(geneType);
	}
};