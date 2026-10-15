class CfgPatches
{
	class IAT_Codelock_Sounds_Ambience
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
	class IAT_Codelock_Ambience_SoundShader_Base
	{
		samples[] = {};
		frequency = 1;
		range = 1000;
		rangeCurve[] =
		{
			{100,0.998},
			{250,0.75},
			{500,0.50},
			{750,0.45},
			{1000,0.3332}
		};
		volume = 1.2;
	};
	class IAT_Codelock_Ambience_ElectricalSounds_SoundShader : IAT_Codelock_Ambience_SoundShader_Base
	{
		samples[] = { {"iat_codelock\sounds\electrical\electricity1.ogg",1} };
	};
};
class CfgSoundSets
{
	class IAT_Codelock_Ambience_ElectricalSounds_SoundSet
	{
		soundShaders[] = { "IAT_Codelock_Ambience_ElectricalSounds_SoundShader" };
	};
};
