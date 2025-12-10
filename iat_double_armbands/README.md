# ItsATreee Double Armbands

**Double Armbands** is a small and lightweight mod meant to extend vanilla armbands. With traditional armbands, the size changes depending if your are wearing something in the "Top" slot and wanting to preserve this behavior, I felt this behavior to be desirable compared to existing double armband mods. Adding your own armbands is incredibly easy and if you have your own vanilla retextures, making them double armbands is basically copy/paste. Creating double armbands in game as a player is accessible through two single armbands combined together and a decraft recipe (with a knife) allows you to split them back into single armbands.

Another aspect of this mod is the **Event Armband**. On sometimes servers need the ability to CLEARLY distinguish event players from normal players. The bumblebee pattern of black and yellow is an excellent high visibility, high contrast color scheme to ensure players can tell if another player is part of an event. This armband is unable to be removed (unless placed on a gearstand) and will ruin the gear on the wearing player when they are killed; each piece of gear on the player has a 90% chance of being ruined on death. This behavior is in place to ensure event characters are not solely farmed for their gear.

A full readme of this mod can be found at its source. [https://github.com/Treee/DayZMods/blob/main/iat_double_armbands/README.md](Github Readme).

(https://survivalistsgaming.net/#home)[The Survivalists Role Play Server] Where I do most my development work.

# Features

## Crafting Recipes

-   Single Armband + Single Armband = Double Armband (requires same color)
-   Double Armband + Knife = 2x Single Armbands (of same color)
-   If you add your own armbands, make sure to include the `color=colorName` inside the config.cpp entry. This property ensures that mapping between Single and Double Armbands is preserved. Example shown down below.

## Event Armband

-   Bumblebee pattern to ensure always visible.
-   Unable to remove from slot once equipped. Special case for gearstands allow removal.
-   When a player dies that is wearing an event armband, each piece of gear has a 90% chance of ruining.

# ITEM CLASSNAMES

## Armbands

-   IAT_DoubleArmband_ColorBase
-   IAT_DoubleArmband_White
-   IAT_DoubleArmband_Yellow
-   IAT_DoubleArmband_Orange
-   IAT_DoubleArmband_Red
-   IAT_DoubleArmband_Green
-   IAT_DoubleArmband_Pink
-   IAT_DoubleArmband_Blue
-   IAT_DoubleArmband_Black
-   IAT_DoubleArmband_Chernarus
-   IAT_DoubleArmband_Chedaki
-   IAT_DoubleArmband_NAPA
-   IAT_DoubleArmband_CDF
-   IAT_DoubleArmband_Livonia
-   IAT_DoubleArmband_Altis
-   IAT_DoubleArmband_SSahrani
-   IAT_DoubleArmband_NSahrani
-   IAT_DoubleArmband_DayZ
-   IAT_DoubleArmband_LivoniaArmy
-   IAT_DoubleArmband_Bohemia
-   IAT_DoubleArmband_APA
-   IAT_DoubleArmband_UEC
-   IAT_DoubleArmband_Pirates
-   IAT_DoubleArmband_Cannibals
-   IAT_DoubleArmband_Bear
-   IAT_DoubleArmband_Wolf
-   IAT_DoubleArmband_BabyDeer
-   IAT_DoubleArmband_Rooster
-   IAT_DoubleArmband_LivoniaPolice
-   IAT_DoubleArmband_CMC
-   IAT_DoubleArmband_TEC
-   IAT_DoubleArmband_CHEL
-   IAT_DoubleArmband_Zenit
-   IAT_DoubleArmband_HunterZ
-   IAT_DoubleArmband_BrainZ
-   IAT_DoubleArmband_Refuge
-   IAT_DoubleArmband_RSTA
-   IAT_DoubleArmband_Snake
-   IAT_DoubleArmband_Crook
-   IAT_DoubleArmband_Rex
-   IAT_DoubleArmband_Zagorky
-   IAT_DoubleArmband_Event

# Adding Your Own Double Armbands

## RGBA (Dynamic Texture)

```cs
class IAT_DoubleArmband_White : IAT_DoubleArmband_ColorBase
{
	scope = 2;
	color = "White";
	hiddenSelectionsTextures[] =
	{
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)",
		"#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)"
	};
};
```

## PAA (Traditional Texture)

```cs
class IAT_DoubleArmband_Bear : IAT_DoubleArmband_ColorBase
{
	scope = 2;
	visibilityModifier = 0.95;
	color = "Bear";
	hiddenSelectionsTextures[] =
	{
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa",
		"\dz\gear\camping\data\Flag_bear_co.paa"
	};
};
```

# How To Use

1. Subscribe to the mod
2. Start the server with the mod loaded

# Scripting??

Unpack the mod, study the contents and override the functions needed. Ask questions in the DayZ modders discord.

# AI Disclaimer

No AI was used in the creation of this mod.

# Usage & Terms

-   You **MAY NOT** repack or publish this mod on any platform including Steam.
-   You **MAY** use this mod on monetized servers within the scope of [https://www.bohemia.net/monetization](Bohemia's Monetization Guidelines)

# **PERMISSION IS NOT GRANTED FOR THIS MOD TO BE INCLUDED IN A "SERVER PACK" OR "MOD PACK"**

Subscribe via the workshop, use a "Collection" or do not use the mod at all.
