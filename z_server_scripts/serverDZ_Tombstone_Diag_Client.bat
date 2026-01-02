P:\Mods\@echo off

set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title Client batch

cd "%serverLocation%"
Y:
echo (%time%) Client started.


start "DayZ Client" /min "DayZDiag_x64.exe" -name=PhillipDiag -connect=127.0.0.1 -port=2302 "-serverMod=P:\Mods\SRP_Server_Scripts;" "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\Ambient Animals Pack;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Core_Scripts;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_WesternZ_Scripts;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Metallurgy;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Mining;P:\Mods\@ALV_UN_Core;P:\Mods\@ALV_UN_Clothing;P:\Mods\@ALV_UN_Gear;P:\Mods\@ALV_UN_NPC;P:\Mods\@ALV_UN_Props;P:\Mods\@ALV_UN_Scripts;P:\Mods\@ALV_UN_Structures;P:\Mods\@ALV_UN_Structures_Camp;P:\Mods\@ALV_UN_Structures_Commercial;P:\Mods\@ALV_UN_Structures_Industrial;P:\Mods\@ALV_UN_Structures_Misc;P:\Mods\@ALV_UN_Structures_Residential;P:\Mods\@ALV_UN_Structures_SignsDecals;P:\Mods\@ALV_UN_Structures_Walls;P:\Mods\@ALV_UN_Weapons;P:\Mods\@Tombstone;P:\Mods\@WesternZ_World_assets;" -forcedebugger -scriptDebug=true -dologs -newErrorsAreWarnings=1 -filePatching
