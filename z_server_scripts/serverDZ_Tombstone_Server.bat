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
start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_Tombstone.cfg -port=2302 -limitfps=120 "-profiles=profile_tombstone" "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;P:\Mods\Tombstone;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -filePatching -doLogs -adminlog

@REM P:\Mods\SRP_Server_Scripts;

@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Chiemsee;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Dabs Framework;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Core;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-AI;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Navigation;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Quests;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Market;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Groups;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Expansion-Book;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Cabin_Mod_RaGed;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Cabin_Mod_CodeLock_RaGed;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\Survivalists_Mining;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\Survivalists_Metallurgy;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals A3PP;
@REM P:\Mods\Survivalists_Core_Scripts;
@REM P:\Mods\@Alevaric_PVP_Test;
@REM P:\Mods\@Alevaric_PVP_Mods;