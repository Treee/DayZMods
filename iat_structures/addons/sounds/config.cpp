class CfgPatches
{
	class IAT_Structures_Sounds_Ambience
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
	class IAT_Mods_Ambience_SoundShader_Base
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
	class IAT_Mods_Ambience_ElectricalSounds_SoundShader : IAT_Mods_Ambience_SoundShader_Base
	{
		samples[] =
		{
			{"iat_structures\sounds\electrical\electricity1.ogg",0.25},
			{"iat_structures\sounds\electrical\electricity2.ogg",0.25},
			{"iat_structures\sounds\electrical\electricity3.ogg",0.25},
			{"iat_structures\sounds\electrical\electricity4.ogg",0.25},
		};
	};

	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerUp_SoundShader : IAT_Mods_Ambience_SoundShader_Base
	{
		samples[] = { {"iat_structures\sounds\portal\portal_powerup.ogg",1} };
	};
	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerDown_SoundShader : IAT_Mods_Ambience_SoundShader_Base
	{
		samples[] = { {"iat_structures\sounds\portal\portal_powerdown.ogg",1} };
	};
	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerMax_SoundShader : IAT_Mods_Ambience_SoundShader_Base
	{
		samples[] = { {"iat_structures\sounds\portal\portal_maxpower.ogg",1} };
	};
};
class CfgSoundSets
{
	class IAT_Mods_Ambience_ElectricalSounds_SoundSet
	{
		soundShaders[] = { "IAT_Mods_Ambience_ElectricalSounds_SoundShader" };
	};

	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerUp_SoundSet
	{
		soundShaders[] = { "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerUp_SoundShader" };
	};
	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerDown_SoundSet
	{
		soundShaders[] = { "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerDown_SoundShader" };
	};
	class IAT_Mods_Ambience_PortalSounds_Steampunk_PowerMax_SoundSet
	{
		soundShaders[] = { "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerMax_SoundShader" };
	};
};
