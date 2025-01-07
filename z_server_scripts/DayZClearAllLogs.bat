@echo off

echo "Change to C Drive"
C:
echo "Change to Client Logs"
cd C:\Users\Tree\AppData\Local\DayZ

echo "Deleting Client Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Client RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Client Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"

echo "Change to D Drive"
Y:
echo "Change to Diag Sakhal Server"
cd Y:\SteamLibrary\steamapps\common\DayZ\profile_sakhaldiag

echo "Deleting Diag Sakhal Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Diag Sakhal Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Diag Sakhal Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"

echo "Change to Diag Survivalists Server"
cd Y:\SteamLibrary\steamapps\common\DayZ\profile_survivalists

echo "Deleting Diag Survivalists Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Diag Survivalists Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Diag Survivalists Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"


echo "Change to Chernarus Dev Server"
cd Y:\SteamLibrary\steamapps\common\DayZServer\profile_cherno

echo "Deleting Chernarus Dev Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Chernarus Dev Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Chernarus Dev Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"

echo "Change to Sakhal Server"
cd Y:\SteamLibrary\steamapps\common\DayZServer\profile_sakhal

echo "Deleting Sakhal Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Sakhal Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Sakhal Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"
echo "Deleting Sakhal Server Admin File"
for /f %%x in ('dir /o-d /b "*.adm"') do del "*%%x*"

echo "Change to Survivalists RP Server"
cd Y:\SteamLibrary\steamapps\common\DayZServer\profile_survivalists

echo "Deleting Survivalists RP Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Survivalists RP Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Survivalists RP Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"
echo "Deleting Survivalists RP Server Admin File"
for /f %%x in ('dir /o-d /b "*.adm"') do del "*%%x*"

echo "Change to Tombstone Dev Server"
cd Y:\SteamLibrary\steamapps\common\DayZServer\profile_tombstone

echo "Deleting Tombstone Dev Server Logs"
for /f %%x in ('dir /o-d /b "*.log"') do del "*%%x*"
echo "Deleting Tombstone Dev Server RPTs"
for /f %%x in ('dir /o-d /b "*.rpt"') do del "*%%x*"
echo "Deleting Tombstone Dev Server Memory Dumps"
for /f %%x in ('dir /o-d /b "*.mdmp"') do del "*%%x*"
echo "Deleting Tombstone Dev Server Admin File"
for /f %%x in ('dir /o-d /b "*.adm"') do del "*%%x*"

pause