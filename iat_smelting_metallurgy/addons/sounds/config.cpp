class CfgPatches
{
	class IAT_Smelting_Sounds_MiniGame
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Sounds_Effects"
		};
	};
};

class CfgSoundShaders
{
	class IAT_Smelting_MiniGame_SoundShader_Base
	{
		samples[] = {};
		frequency = 1;
		range = 100;
		rangeCurve[] =
		{
			{10,0.998},
			{25,0.75},
			{50,0.50},
			{75,0.45},
			{100,0.3332}
		};
		volume = 1.2;
	};
	class IAT_Smelting_MiniGame_CountDown_SoundShader : IAT_Smelting_MiniGame_SoundShader_Base
	{
		samples[] = { {"iat_smelting_metallurgy\sounds\minigame\countdown1.ogg",0.5},{"iat_smelting_metallurgy\sounds\minigame\countdown2.ogg",0.5} };
	};
};
class CfgSoundSets
{
	class IAT_Smelting_MiniGame_CountDown_SoundSet
	{
		soundShaders[] = { "IAT_Smelting_MiniGame_CountDown_SoundShader" };
	};
};
