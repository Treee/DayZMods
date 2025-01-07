P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title %serverName% batch
Y:
cd %serverLocation%

echo (%time%) %serverName% started.

dir

start "DayZ Server Diag" /min "DayZDiag_x64.exe" -config=serverDZ_Tombstone.cfg -port=2302 "-profiles=profile_tombstonediag" -limitfps=120 "-mod=P:\Mods\Tombstone;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Immersive Placing;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Diving Mod Dev;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;P:\Mods\@WesternZ - Server Mod;P:\Mods\@IAT_Dev;P:\Mods\@IAT_Retextures_Dev;P:\Mods\@IAT_FacePaints_Dev;P:\Mods\@IAT_NotesEnhanced_Dev;" -noPause -forcedebugger -scriptDebug=true -dologs -adminlogs -server -newErrorsAreWarnings=1 -scrAllowFileWrite -filePatching