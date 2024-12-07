modded class AgentBase
{
	// convert attributes to a dna strand
	// min/max each attribute to create a reasonable range
	// breed agents to make new strains



	// float	m_Invasibility;					//how fast the agent grows when potent enough to grow (0-1) can be higher than 1 but be careful
	// float 	m_TransferabilityIn;			//to the player (0-1) can be higher than 1 but be careful
	// float	m_TransferabilityOut;			//from the player (0-1) can be higher than 1 but be careful
	// float	m_Digestibility = 0.1;			//multiplier for agents digested in the player stomach from an infected item(agents_transfered = digested_amount(in grams or mls) * m_Digestibility)
	// int		m_MaxCount = 1;					(min 0, max)
	// int		m_AutoinfectCount = 1;			//! number of agents injected during the autoinfection (low numbers)
	// float 	m_AutoinfectProbability = CalculateAutoinfectProbability(0);	// [0..1], 0 = zero chance, 1 = 100% chance of getting this agent once per hour
	// float 	m_TransferabilityAirOut; 		// transferibility airborne out (0-1)
	// float 	m_AntibioticsResistance = 1;	//[0..1], 0 means antibiotics have full effect, 1 means no effect (0-1)

	// EStatLevels m_Potency = EStatLevels.MEDIUM;		//grow when player's immune system is at this level or lower (0-4)
	// float m_DieOffSpeed = 1;						//how fast the agent dies off when not potent enough to grow(per sec) (low numbers)

};