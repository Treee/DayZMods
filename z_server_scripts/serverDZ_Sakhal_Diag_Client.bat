P:\Mods\@echo off

set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title Client batch

cd "%serverLocation%"
Y:
echo (%time%) Client started.


start "DayZ Client" /min "DayZDiag_x64.exe" -name=PhillipDiag -connect=127.0.0.1 -port=2302 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Immersive Placing;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_FacePaints;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Diving Mod Dev;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@WindstridesClothingPack;P:\Mods\@IAT_Dev;P:\Mods\@IAT_Retextures_Dev;" -forcedebugger -scriptDebug=true -dologs -newErrorsAreWarnings=1 -filePatching
