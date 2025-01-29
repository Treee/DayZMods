P:\Mods\@echo off

set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title Client batch

cd "%serverLocation%"
Y:
echo (%time%) Client started.


start "DayZ Client" /min "DayZDiag_x64.exe" -name=PhillipDiag -connect=127.0.0.1 -port=2302 "-mod=Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Survivor Animations;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VPPAdminTools;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Bitterroot;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Code Lock;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ViewInventoryAnimation;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ Horse;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Crocodile;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Snake;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@DayZ-Raven;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Mutant Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Cybernetic Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Custom Weapons;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Simple Snapping;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals GearStand Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Terminals Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Hunting Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Admirals Underwear Mod;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@VanillaPlusPlusMap;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@Ear-Plugs;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_LiteraryDevices;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_FacePaints;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus_Enums;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Crafting_Plus;Y:\SteamLibrary\steamapps\common\DayZ\!Workshop\@IAT_Enhanced_BioProtection;P:\Mods\@Survivalists RP Server Modpack;P:\Mods\@IAT_Dev;P:\Mods\@IAT_NotesEnhanced_Dev;" -forcedebugger -scriptDebug=true -dologs -newErrorsAreWarnings=1
