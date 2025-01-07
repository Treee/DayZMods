@echo off
C:
cd C:\Users\Tree\AppData\Local\DayZ

dir /o-d /b "C:\Users\Tree\AppData\Local\DayZ\script_*.log" >tmp
<tmp set /p "latest="
del tmp
@REM echo the latest file is %latest%

start notepad++ -r %latest%

exit 0