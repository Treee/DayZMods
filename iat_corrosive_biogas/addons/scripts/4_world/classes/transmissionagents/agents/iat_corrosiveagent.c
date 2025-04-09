enum IAT_CB_Agents : eAgents
{
	#ifdef AdmiralsMutantMod
	CORROSION = 4096;
	#elseif
	CORROSION = 2048;
	#endif
};

class IAT_CorrosiveAgent extends AgentBase
{
	override void Init()
	{
		m_Type 					= IAT_CB_Agents.CORROSION;
		m_Invasibility 			= 0;
		m_TransferabilityIn		= 1;
		m_TransferabilityOut	= 1;
		m_AntibioticsResistance = 1;
		m_MaxCount 				= 10;
		m_Potency 				= EStatLevels.CRITICAL;
		m_DieOffSpeed 			= 0;
	}
};