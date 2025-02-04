P:\Mods\@echo off

set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title Client batch

cd "%serverLocation%"
Y:
echo (%time%) Client started.


start "DayZ Client" /min "DayZDiag_x64.exe" -name=PhillipDiag -connect=127.0.0.1 -port=2302 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Bitterroot;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Crocodile;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Mutant Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cybernetic Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Custom Weapons;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals GearStand Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Terminals Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Hunting Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Underwear Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Dark Sight Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals NVG Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cannibal Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals World Radio Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ambient Animals Pack;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_LiteraryDevices;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_FacePaints;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Enhanced_BioProtection;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_NotesEnhanced;P:\Mods\@IAT_WeaponQuickbar_Release;P:\Mods\@Survivalists RP Server Modpack;P:\Mods\@IAT_Dev_Release;" -forcedebugger -scriptDebug=true -dologs -newErrorsAreWarnings=1


@REM Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Weapon_Quickbar_Realism;
@REM P:\Mods\@Survivalists RP Server Modpack;