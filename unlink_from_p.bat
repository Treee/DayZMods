@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "SOURCE_ROOT=%~dp0"
set "TARGET_ROOT=C:\Users\Tree\Documents\DayZ Projects"
set "IGNORED_FOLDERS=.git .github"

rem Add more ignored folder names here by separating them with spaces.

if not exist "%TARGET_ROOT%" (
    echo Target root does not exist: %TARGET_ROOT%
    exit /b 0
)

echo Removing modding root junctions from %TARGET_ROOT%...

for /d %%D in ("%SOURCE_ROOT%*") do (
    set "folderName=%%~nxD"
    set "linkPath=%TARGET_ROOT%\!folderName!"

    call :IsIgnoredFolder "!folderName!"
    if not errorlevel 1 (
        echo Skipping ignored folder: !folderName!
    ) else (
        if exist "!linkPath!\" (
            fsutil reparsepoint query "!linkPath!" >nul 2>&1
            if not errorlevel 1 (
                echo Removing junction: !linkPath!
                rmdir "!linkPath!" >nul 2>&1
            )
        )
    )
)

endlocal
exit /b 0

:IsIgnoredFolder
set "folderName=%~1"
for %%I in (%IGNORED_FOLDERS%) do (
    if /I "%%~I"=="!folderName!" exit /b 0
)
exit /b 1