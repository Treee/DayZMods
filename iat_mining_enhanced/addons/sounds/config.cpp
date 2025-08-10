class CfgPatches
{
	class IAT_Mining_Enhanced_Sounds
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};

class CfgSoundShaders
{
	class IAT_Mining_Enhanced_Sounds_Base
	{
		samples[] = {};
		frequency = 1;
		range = 50;
		volume = 1;
		rangeCurve[] = { {0, 2}, {50, 1.5} };
	};

	class IAT_Mining_Enhanced_SoundShaders_FallingRock : IAT_Mining_Enhanced_Sounds_Base
	{
		samples[] =
		{
			{"iat_mining_enhanced\sounds\data\fallingrock1.ogg", 0.3},
			{"iat_mining_enhanced\sounds\data\fallingrock2.ogg", 0.3},
			{"iat_mining_enhanced\sounds\data\fallingrock3.ogg", 0.3},
		};
	};
};

class CfgSoundSets
{
	class IAT_Mining_Enhanced_SoundSet_FallingRock
	{
		soundShaders[] = { "IAT_Mining_Enhanced_SoundShaders_FallingRock" };
	};
};

// For map baked objects and actions
// These are the actual sounds and their definitions
class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class IAT_Mining_Enhanced_FallingRock_1 : default
	{
		sound[] = { "iat_mining_enhanced\sounds\data\fallingrock1.ogg", 1.2, 1.5, 50 };
	};
	class IAT_Mining_Enhanced_FallingRock_2 : default
	{
		sound[] = { "iat_mining_enhanced\sounds\data\fallingrock2.ogg", 1.2, 1.5, 50 };
	};
	class IAT_Mining_Enhanced_FallingRock_3 : default
	{
		sound[] = { "iat_mining_enhanced\sounds\data\fallingrock3.ogg", 1.2, 1.5, 50 };
	};
};

// This is the sound set that holds the actual sounds
class CfgActionSounds
{
	class IAT_Mining_Enhanced_FallingRock
	{
		sounds[] = { "IAT_Mining_Enhanced_FallingRock_1", "IAT_Mining_Enhanced_FallingRock_2", "IAT_Mining_Enhanced_FallingRock_3" };
		distance = 100;
	};
};