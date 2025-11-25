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
	// ======================================================= AI SLOP
	class IAT_PI_Vinyl_SoundShader_ABetterDay : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\a_better_day.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_ChantsOfTheWild : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\chants_of_the_wild.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_ForgedInTheFire : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\forged_in_the_fire.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_HerosFight : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\heros_fight.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_HerosRest : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\heros_rest.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_IntoTheMaw : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\into_the_maw.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_RustAndReverie : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\rust_and_reverie.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_SlowRoll : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\slow_roll.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_Subterfuge : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\subterfuge.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VelvetNights : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\velvet_nights.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VictoryDance : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\victory_dance.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_VortexOfTheDamned : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\vinyls\aislop\vortex_of_the_damned.ogg",1} }; };

	// ======================================================= RUBYS
	class IAT_PI_Vinyl_SoundShader_BlackLagoonLove : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\black_lagoon_love.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_DaggerInTheDark : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\dagger_in_the_dark.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_DownByTheGraveyardRiver : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\down_by_the_graveyard_river.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_GraveyardStrut : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\graveyard_strut.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_GraveyardTwist : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\graveyard_twist.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_LeatherDollsAndSwitchBlades : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\leatherdolls_and_switchblades.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_MidnightHowl : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\midnight_howl.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_BlackTopVoodooQueen : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\my_blacktop_voodooqueen.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_MySwampThingBaby : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\my_swamp_thing_baby.ogg",1} }; };
	class IAT_PI_Vinyl_SoundShader_ShesMyPoison : IAT_PI_Vinyl_SoundShader_Base { samples[] = { {"iat_prop_items\sounds\rubys\shes_my_poison.ogg",1} }; };

};
class CfgSoundSets
{
	// ======================================================= AI SLOP
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

	// ======================================================= RUBYS
	class IAT_PI_Vinyl_SoundSet_BlackLagoonLove { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_BlackLagoonLove" }; };
	class IAT_PI_Vinyl_SoundSet_DaggerInTheDark { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_DaggerInTheDark" }; };
	class IAT_PI_Vinyl_SoundSet_DownByTheGraveyardRiver { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_DownByTheGraveyardRiver" }; };
	class IAT_PI_Vinyl_SoundSet_GraveyardStrut { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_GraveyardStrut" }; };
	class IAT_PI_Vinyl_SoundSet_GraveyardTwist { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_GraveyardTwist" }; };
	class IAT_PI_Vinyl_SoundSet_LeatherDollsAndSwitchBlades { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_LeatherDollsAndSwitchBlades" }; };
	class IAT_PI_Vinyl_SoundSet_MidnightHowl { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_MidnightHowl" }; };
	class IAT_PI_Vinyl_SoundSet_BlackTopVoodooQueen { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_BlackTopVoodooQueen" }; };
	class IAT_PI_Vinyl_SoundSet_MySwampThingBaby { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_MySwampThingBaby" }; };
	class IAT_PI_Vinyl_SoundSet_ShesMyPoison { soundShaders[] = { "IAT_PI_Vinyl_SoundShader_ShesMyPoison" }; };

};
