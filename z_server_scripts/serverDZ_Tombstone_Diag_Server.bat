P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title %serverName% batch
Y:
cd %serverLocation%

echo (%time%) %serverName% started.

dir

start "DayZ Server Diag" /min "DayZDiag_x64.exe" -config=serverDZ_Tombstone.cfg -port=2302 "-profiles=profile_tombstonediag" -limitfps=120 "-serverMod=P:\Mods\SRP_Server_Scripts;" "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\Ambient Animals Pack;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Core_Scripts;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_WesternZ_Scripts;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Metallurgy;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Mining;P:\Mods\@ALV_UN_Core;P:\Mods\@ALV_UN_Clothing;P:\Mods\@ALV_UN_Gear;P:\Mods\@ALV_UN_NPC;P:\Mods\@ALV_UN_Props;P:\Mods\@ALV_UN_Scripts;P:\Mods\@ALV_UN_Structures;P:\Mods\@ALV_UN_Structures_Camp;P:\Mods\@ALV_UN_Structures_Commercial;P:\Mods\@ALV_UN_Structures_Industrial;P:\Mods\@ALV_UN_Structures_Misc;P:\Mods\@ALV_UN_Structures_Residential;P:\Mods\@ALV_UN_Structures_SignsDecals;P:\Mods\@ALV_UN_Structures_Walls;P:\Mods\@ALV_UN_Weapons;P:\Mods\@Tombstone;P:\Mods\@WesternZ_World_assets;" -noPause -forcedebugger -scriptDebug=true -dologs -adminlogs -server -newErrorsAreWarnings=1 -scrAllowFileWrite -filePatching





@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Slot Mod;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\Ambient Animals Pack;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Core_Scripts;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_WesternZ_Scripts;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Metallurgy;
@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivalists_Mining;
@REM P:\Mods\@ALV_UN_Core;
@REM P:\Mods\@ALV_UN_Clothing;
@REM P:\Mods\@ALV_UN_Gear;
@REM P:\Mods\@ALV_UN_NPC;
@REM P:\Mods\@ALV_UN_Props;
@REM P:\Mods\@ALV_UN_Scripts;
@REM P:\Mods\@ALV_UN_Structures;
@REM P:\Mods\@ALV_UN_Structures_Camp;
@REM P:\Mods\@ALV_UN_Structures_Commercial;
@REM P:\Mods\@ALV_UN_Structures_Industrial;
@REM P:\Mods\@ALV_UN_Structures_Misc;
@REM P:\Mods\@ALV_UN_Structures_Residential;
@REM P:\Mods\@ALV_UN_Structures_SignsDecals;
@REM P:\Mods\@ALV_UN_Structures_Walls;
@REM P:\Mods\@ALV_UN_Weapons;
@REM P:\Mods\@Tombstone;
@REM P:\Mods\@WesternZ_World_assets;






@REM C:\Program Files (x86)\Steam\steamapps\common\DayZ\!Workshop\@Dabs Framework;
@REM C:\Program Files (x86)\Steam\steamapps\common\DayZ\!Workshop\@Admirals Chat Filter;
