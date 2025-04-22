@REM turn off echoing (printing to console) for this filepath
P:\Mods\@echo off

@REM set is a keyword to create a variable so below in the command it reads more cleanly and easier to change
set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZServer"
set serverPort=2302
set serverConfig=serverDZ.cfg
set serverCPU=2

@REM set the title of the window (cosmetic)
title %serverName% batch
Y:
@REM cd is a keyword to change directory. move the console to our server folder
cd "%serverLocation%"

@REM print out to the console when the server has started (include the name for funsies)
echo (%time%) %serverName% started.

@REM start is a special console command to invoke a start process (like an exe)
start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_SRP.cfg -port=2302 "-profiles=profile_survivalists" -limitFPS=120 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Bitterroot;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Crocodile;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Dark Sight Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals NVG Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals World Radio Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cannibal Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Underwear Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Hunting Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Terminals Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Mutant Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals GearStand Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cybernetic Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Custom Weapons;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ambient Animals Pack;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_ReadableBooks_And_LiteraryDevices;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Enhanced_BioProtection;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Weapon_Quickbar_Realism;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_NotesEnhanced;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Structures;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Simple_Territories;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Roleplay_Emotes;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Universal_Repair;P:\Mods\@Survivalists RP Server Modpack;P:\Mods\@IAT_MolotovGrenades_Release;P:\Mods\@IAT_MeleeWeapons_Release;P:\Mods\@IAT_RadioMute_Release;P:\Mods\@IAT_Dev_Release;P:\Mods\@IAT_SoftSurrender_Release;P:\Mods\@IAT_Retextures_Release;P:\Mods\@IAT_CorrosiveBioGas_Release;P:\Mods\@IAT_TeleportLinker_Release;P:\Mods\@IAT_FacePaints_Release;P:\Mods\@IAT_DynamicRadioRange_Release;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -filePatching -doLogs -adminlog

@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Bitterroot;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Crocodile;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@InventorySlotsHotfix;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Dark Sight Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals NVG Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals World Radio Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cannibal Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Underwear Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Hunting Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Terminals Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Mutant Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals GearStand Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cybernetic Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Custom Weapons;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ambient Animals Pack;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_ReadableBooks_And_LiteraryDevices;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_FacePaints;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Enhanced_BioProtection;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Corrosive_BioGas;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Weapon_Quickbar_Realism;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_NotesEnhanced;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Structures;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Simple_Territories;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Roleplay_Emotes;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Radio_Mute;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Universal_Repair;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists RP Server Modpack;
@REM P:\Mods\@Survivalists RP Server Modpack;
@REM P:\Mods\@SRP_Tree_Mods;