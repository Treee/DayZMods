class IAT_DieOffSpeedGene extends IAT_GeneBase
{
	void IAT_DieOffSpeedGene()
	{
		m_GeneType = IAT_GeneTypes.DIE_OFF_SPEED;
		m_GeneMin = 0; // no modification
		m_GeneMax = 200; // 200% double the possible die off speed
		m_CurrentValue = 0; // no change to vanilla growth (at 0)
		m_NumBytes = 1; // 1 byte since max value is 200
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};