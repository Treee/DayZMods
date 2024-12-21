enum IAT_GeneTypes
{
	TESTGENE1 = 0,
	TESTGENE2,
	TESTGENE3,
	TESTGENE4,
	TESTGENE5,
	INVASIBILITY, // percentage of how fast any agents naturally grow within an organism
	AUTOINFECT_PROBABILITY, // percentage chance of just getting infected at random (related to transferibility)
	TRANSFERIBILITY_IN, // percentage of how susceptible something is to 'catching' an existing illness
	TRANSFERIBILITY_OUT, // percentage of how susceptible something is to 'distributing' an existing illness
	DIGESTIBILITY, // percentage of how digestible agents naturally are within a stomach
	ANTIBIOTIC_EFFICACY, // percent usefullness of antibiotics for a given thing
	GROWTH_POTENCY, // level of immune system required to grow
	DIE_OFF_SPEED, // percentage of how fast any agents naturally die within an organism
}