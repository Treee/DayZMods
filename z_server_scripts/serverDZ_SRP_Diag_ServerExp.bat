P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ Exp"

title %serverName% batch
Y:
cd "%serverLocation%"

echo (%time%) %serverName% started.

start "DayZ Server Diag" /min "DayZDiag_x64.exe" -config=serverDZ_SRP_Cherno.cfg -port=2302 -limitfps=120 "-profiles=profile_survivalists" "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;P:\Mods\@IAT_Codelock_Dev;P:\Mods\@IAT_Collectibles_Dev;P:\Mods\@IAT_CorrosiveBioGas_Dev;P:\Mods\@IAT_CraftingPlus_Dev;P:\Mods\@IAT_DayZCodex_Dev;P:\Mods\@IAT_DisplayCase_Dev;P:\Mods\@IAT_DoubleArmbands_Dev;P:\Mods\@IAT_DynamicRadioRange_Dev;P:\Mods\@IAT_DynamicTraps_Dev;P:\Mods\@IAT_EnhancedBioProtection_Dev;P:\Mods\@IAT_FacePaints_Dev;P:\Mods\@IAT_InfinityGauntlet_Dev;P:\Mods\@IAT_ItemBlacklist_Dev;P:\Mods\@IAT_LiteraryDevices_Dev;P:\Mods\@IAT_MapBorderTeleport_Dev;P:\Mods\@IAT_MeleeWeapons_Dev;P:\Mods\@IAT_MiningEnhanced_Dev;P:\Mods\@IAT_MolotovGrenades_Dev;P:\Mods\@IAT_MoreDoors_Dev;P:\Mods\@IAT_NotesEnhanced_Dev;P:\Mods\@IAT_PoweredRadioTowers_Dev;P:\Mods\@IAT_PropItems_Dev;P:\Mods\@IAT_RadioMute_Dev;P:\Mods\@IAT_Retextures_Dev;P:\Mods\@IAT_RollTables_Dev;P:\Mods\@IAT_SimpleBuilding_Dev;P:\Mods\@IAT_SimpleCarpentry_Dev;P:\Mods\@IAT_SimpleTerritories_Dev;P:\Mods\@IAT_SingleItemSplit_Dev;P:\Mods\@IAT_SmeltingMetallurgy_Dev;P:\Mods\@IAT_SmokeSignals_Dev;P:\Mods\@IAT_SoftSurrender_Dev;P:\Mods\@IAT_Structures_Dev;P:\Mods\@IAT_TeleportLinker_Dev;P:\Mods\@IAT_TreasureHunts_Dev;P:\Mods\@IAT_UniversalDye_Dev;P:\Mods\@IAT_UniversalRepair_Dev;P:\Mods\@IAT_WeaponQuickbar_Dev;P:\Mods\@IAT_RoleplayEmotes_Dev;" -noPause -forcedebugger -scriptDebug=true -dologs -adminlogs -server -newErrorsAreWarnings=1 -scrAllowFileWrite
