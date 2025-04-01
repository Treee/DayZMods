class CfgPatches
{
	class IAT_Molotov_Grenades_Sounds
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};

class CfgSoundShaders
{
	class IAT_Incendiary_Sounds_Base
	{
		samples[] = {};
		frequency = 1;
		range = 50;
		volume = 2;
		rangeCurve[] = { {0, 2}, {50, 1.5} };
	};

	class IAT_Incendiary_SoundShaders_LargeFire : IAT_Incendiary_Sounds_Base
	{
		samples[] = { {"iat_molotov_firegrenades\sounds\data\large-fire.ogg", 1} };
	};
};

class CfgSoundSets
{
	class IAT_Incendiary_SoundSet_LargeFire
	{
		soundShaders[] = { "IAT_Incendiary_SoundShaders_LargeFire" };
	};
};