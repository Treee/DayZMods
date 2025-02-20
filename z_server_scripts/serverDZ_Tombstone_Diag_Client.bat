P:\Mods\@echo off

set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title Client batch

cd "%serverLocation%"
Y:
echo (%time%) Client started.


start "DayZ Client" /min "DayZDiag_x64.exe" -name=PhillipDiag -connect=127.0.0.1 -port=2302 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@WesternZ - Server Mod;P:\Mods\Tombstone;P:\Mods\@IAT_InfinityGauntlet_Release;" -forcedebugger -scriptDebug=true -dologs -newErrorsAreWarnings=1 -filePatching
