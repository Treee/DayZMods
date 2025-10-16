class CfgPatches
{
	class IAT_Prop_Items_Sounds
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
	class IAT_PI_Vinyl_SoundShader_Base
	{
		samples[] = {};
		frequency = 1;
		range = 200;
		rangeCurve[] =
		{
			{20,0.998},
			{45,0.75},
			{75,0.50},
			{150,0.45},
			{200,0.3332}
		};
		volume = 1.2;
	};

	class IAT_PI_Vinyl_SoundShader_ABetterDay : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\a_better_day.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_ChantsOfTheWild : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\chants_of_the_wild.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_ForgedInTheFire : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\forged_in_the_fire.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_HerosFight : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\heros_fight.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_HerosRest : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\heros_rest.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_IntoTheMaw : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\into_the_maw.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_RustAndReverie : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\rust_and_reverie.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_SlowRoll : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\slow_roll.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_Subterfuge : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\subterfuge.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VelvetNights : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\velvet_nights.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VictoryDance : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\victory_dance.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VortexOfTheDamned : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\vortex_of_the_damned.ogg",1} }; };
};
class CfgSoundSets
{
	class IAT_PI_Vinyl_SoundSet_ABetterDay { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_ABetterDay" }; };
	class IAT_PI_Vinyl_SoundSet_ChantsOfTheWild { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_ChantsOfTheWild" }; };
	class IAT_PI_Vinyl_SoundSet_ForgedInTheFire { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_ForgedInTheFire" }; };
	class IAT_PI_Vinyl_SoundSet_HerosFight { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_HerosFight" }; };
	class IAT_PI_Vinyl_SoundSet_HerosRest { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_HerosRest" }; };
	class IAT_PI_Vinyl_SoundSet_IntoTheMaw { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_IntoTheMaw" }; };
	class IAT_PI_Vinyl_SoundSet_RustAndReverie { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_RustAndReverie" }; };
	class IAT_PI_Vinyl_SoundSet_SlowRoll { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_SlowRoll" }; };
	class IAT_PI_Vinyl_SoundSet_Subterfuge { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_Subterfuge" }; };
	class IAT_PI_Vinyl_SoundSet_VelvetNights { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_VelvetNights" }; };
	class IAT_PI_Vinyl_SoundSet_VictoryDance { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_VictoryDance" }; };
	class IAT_PI_Vinyl_SoundSet_VortexOfTheDamned { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_VortexOfTheDamned" }; };
};
