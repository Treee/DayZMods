@echo off
Y:
cd Y:\Steam\steamapps\common\DayZServer\profile_survivalists

dir /o-d /b "script_*.log" >tmp
<tmp set /p "latest="
del tmp
@REM echo the latest file is %latest%

start notepad++ -r %latest%

exit 0