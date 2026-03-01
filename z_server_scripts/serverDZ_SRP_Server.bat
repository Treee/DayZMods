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
start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_Cherno.cfg -port=2302 "-profiles=profile_cherno" -limitFPS=120 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;P:\Mods\@IAT_Codelock_Release;P:\Mods\@IAT_Collectibles_Release;P:\Mods\@IAT_CorrosiveBioGas_Release;P:\Mods\@IAT_CraftingPlus_Release;P:\Mods\@IAT_DayZCodex_Release;P:\Mods\@IAT_DisplayCase_Release;P:\Mods\@IAT_DoubleArmbands_Release;P:\Mods\@IAT_DynamicRadioRange_Release;P:\Mods\@IAT_DynamicTraps_Release;P:\Mods\@IAT_EnhancedBioProtection_Release;P:\Mods\@IAT_FacePaints_Release;P:\Mods\@IAT_InfinityGauntlet_Release;P:\Mods\@IAT_ItemBlacklist_Release;P:\Mods\@IAT_LiteraryDevices_Release;P:\Mods\@IAT_MapBorderTeleport_Release;P:\Mods\@IAT_MeleeWeapons_Release;P:\Mods\@IAT_MiningEnhanced_Release;P:\Mods\@IAT_MolotovGrenades_Release;P:\Mods\@IAT_MoreDoors_Release;P:\Mods\@IAT_NotesEnhanced_Release;P:\Mods\@IAT_PoweredRadioTowers_Release;P:\Mods\@IAT_PropItems_Release;P:\Mods\@IAT_RadioMute_Release;P:\Mods\@IAT_Retextures_Release;P:\Mods\@IAT_RollTables_Release;P:\Mods\@IAT_SimpleBuilding_Release;P:\Mods\@IAT_SimpleCarpentry_Release;P:\Mods\@IAT_SimpleTerritories_Release;P:\Mods\@IAT_SingleItemSplit_Release;P:\Mods\@IAT_SmeltingMetallurgy_Release;P:\Mods\@IAT_SmokeSignals_Release;P:\Mods\@IAT_SoftSurrender_Release;P:\Mods\@IAT_Structures_Release;P:\Mods\@IAT_TeleportLinker_Release;P:\Mods\@IAT_TreasureHunts_Release;P:\Mods\@IAT_UniversalDye_Release;P:\Mods\@IAT_UniversalRepair_Release;P:\Mods\@IAT_WeaponQuickbar_Release;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -doLogs -adminlog
