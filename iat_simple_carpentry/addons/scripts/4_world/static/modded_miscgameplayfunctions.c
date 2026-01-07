modded class MiscGameplayFunctions
{
	// gets the individual filepath
	static string IAT_GetCarvedSymbolFilePath(int index)
	{
		if (IAT_GetCarvedSymbolFilePaths().IsValidIndex(index))
		{
			return IAT_GetCarvedSymbolFilePaths().Get(index);
		}
		return "DZ\\gear\\consumables\\data\\oak_bark_co.paa";
	}

	// holds the entire list of colors available
	static TStringArray IAT_GetCarvedSymbolFilePaths()
	{
		return {
			"DZ\\gear\\consumables\\data\\oak_bark_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_ash_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_birchy_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_blue_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_burnt_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_coal_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_green_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_lavender_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_lime_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_mossy_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_pink_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_purple_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_red_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_redwood_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_sky_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_teal_co.paa",
			"iat_simple_carpentry\\camping\\data\\oak_bark_yellow_co.paa",
		};
	}

	// gets the individual color name
	static string IAT_GetCarvedSymbolColorName(int index)
	{
		if (IAT_GetCarvedSymbolColorNames().IsValidIndex(index))
		{
			return IAT_GetCarvedSymbolColorNames().Get(index);
		}
		return "Oak Bark";
	}

	// holds the entire list of colors available
	static TStringArray IAT_GetCarvedSymbolColorNames()
	{
		return {
			"Oak Bark",
			"Ash",
			"Birchy",
			"Blue",
			"Burnt",
			"Coal",
			"Green",
			"Lavender",
			"Lime",
			"Mossy",
			"Pink",
			"Purple",
			"Red",
			"Redwood",
			"Sky",
			"Teal",
			"Yellow",
		};
	}

	// gets the individual symbol name
	static string IAT_GetCarvedSymbolName(int index)
	{
		if (IAT_GetCarvedSymbolNames().IsValidIndex(index))
		{
			return IAT_GetCarvedSymbolNames().Get(index);
		}
		return "A";
	}

	// holds the entire list of colors available
	static TStringArray IAT_GetCarvedSymbolNames()
	{
		return {
			"A",
			"B",
			"C",
			"D",
			"E",
			"F",
			"G",
			"H",
			"I",
			"J",
			"K",
			"L",
			"M",
			"N",
			"O",
			"P",
			"Q",
			"R",
			"S",
			"T",
			"U",
			"V",
			"W",
			"X",
			"Y",
			"Z",
			"0",
			"1",
			"2",
			"3",
			"4",
			"5",
			"6",
			"7",
			"8",
			"9",
			"Ampersand",
			"ArrowDown",
			"ArrowLeft",
			"ArrowRight",
			"ArrowUp",
			"Asterisk",
			"Dollar",
			"Equals",
			"Exclamation",
			"Hash",
			"Parenthesis",
			"Percent",
			"Plus",
			"Question",
			"Slash",
			"Times",
		};
	}
};