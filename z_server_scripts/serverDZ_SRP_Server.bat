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
start "DayZ Server" /min "DayZServer_x64.exe" -config=serverDZ_Cherno.cfg -port=2302 "-profiles=profile_cherno" -limitFPS=120 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;P:\Mods\@IAT_FacePaints_Release;" -scrAllowFileWrite -noBenchmark -scriptDebug=true -doLogs -adminlog
