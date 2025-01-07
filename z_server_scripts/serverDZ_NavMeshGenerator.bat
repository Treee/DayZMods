P:\Mods\@echo off

set serverName=Trees Local Test Server
set serverLocation="Y:\SteamLibrary\steamapps\common\DayZ"

title %serverName% batch
Y:
cd "%serverLocation%"

echo (%time%) %serverName% started.


start "DayZ Server Diag Nav Mesh" /min "DayZDiag_x64.exe" -server -config=serverDZ_Navmesh.cfg -port=2302 "-profiles=profile_NavMesh" "-mod=P:\Mods\Tombstone;" -startNavmeshDataServer -limitfps=120
