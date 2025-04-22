P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZServer"
set serverPort=2302
set serverConfig=serverDZ.cfg
set serverCPU=2

title %serverName% batch
Y:
cd "%serverLocation%"

echo (%time%) %serverName% started.


start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_Cherno.cfg -port=2302 "-profiles=profile_cherno" -limitFPS=120 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -filePatching -doLogs

@REM P:\Mods\@SRP_Tree_Mods;
@REM P:\Mods\IAT_FacePaints;
@REM P:\Mods\IAT_UniversalRepair;
@REM P:\Mods\IAT_LiteraryDevices;
@REM P:\Mods\IAT_CraftingPlusEnums;
@REM P:\Mods\IAT_CraftingPlus;