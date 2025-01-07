P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZServer"
set serverPort=2302
set serverConfig=serverDZ_Sakhal.cfg
set serverCPU=2

title %serverName% batch
Y:
cd "%serverLocation%"

echo (%time%) %serverName% started.


start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_Sakhal.cfg -port=2302 "-profiles=profile_sakhal" -limitFPS=120 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Immersive Placing;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_FacePaints;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Diving Mod Dev;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@WindstridesClothingPack;P:\Mods\@IAT_Dev;P:\Mods\@IAT_Retextures_Dev;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -filePatching -doLogs


@REM P:\Mods\Survivalists_FacePaints;
@REM P:\Mods\IAT_UniversalRepair;
@REM P:\Mods\IAT_LiteraryDevices;
@REM P:\Mods\IAT_CraftingPlusEnums;
@REM P:\Mods\IAT_CraftingPlus;

@REM P:\Mods\SRP_Tree_Mods;


@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Immersive Placing;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_FacePaints;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Diving Mod Dev;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@WindstridesClothingPack;

@REM P:\Mods\@IAT_Dev;
@REM P:\Mods\@IAT_Retextures_Dev;
