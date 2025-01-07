@echo off
Y:
cd Y:\SteamLibrary\steamapps\common\DayZServer\profile_sakhal

dir /o-d /b "script_*.log" >tmp
<tmp set /p "latest="
del tmp
@REM echo the latest file is %latest%

start code -r %latest%

exit 0