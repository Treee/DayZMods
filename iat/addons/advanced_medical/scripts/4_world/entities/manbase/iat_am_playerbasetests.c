class IAT_AdvancedMedical_PlayerBaseTests : TestFramework
{
	string g_SteamId = "76561197985160398";
	
	void IAT_AdvancedMedical_PlayerBaseTests()
	{
		AddInitTest("PlayersHaveAChromosomeOfGenesBasedOnTheirSteamId");
	}

	void ~IAT_AdvancedMedical_PlayerBaseTests() {}

	TFResult PlayersHaveAChromosomeOfGenesBasedOnTheirSteamId()
	{
		string s = "";
		// arrange				
		array<Man> players = new array<Man>;
		GetGame().GetWorld().GetPlayerList(players);

		PlayerBase m_Player = PlayerBase.Cast(players.Get(0));
		
		// act
		// player creation (constructor) handles chromosome creation for us
		Math.Randomize(g_SteamId.ToInt());
		
		// assert				
		bool invasibilityCorrect = Assert(m_Player.GetChromosome() != null);
	//INVASIBILITY, // percentage of how fast any agents naturally grow within an organism
//	AUTOINFECT_PROBABILITY, // percentage chance of just getting infected at random (related to transferibility)
//	TRANSFERIBILITY_IN, // percentage of how susceptible something is to 'catching' an existing illness
//	TRANSFERIBILITY_OUT, // percentage of how susceptible something is to 'distributing' an existing illness
//	DIGESTIBILITY, // percentage of how digestible agents naturally are within a stomach
//	ANTIBIOTIC_EFFICACY, // percent usefullness of antibiotics for a given thing
//	GROWTH_POTENCY, // level of immune system required to grow
//	DIE_OFF_SPEED, // percen
		return BTFR(invasibilityCorrect);
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