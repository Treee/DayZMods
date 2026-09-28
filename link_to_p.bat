@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "SOURCE_ROOT=%~dp0"
set "TARGET_ROOT=C:\Users\Tree\Documents\DayZ Projects"
set "IGNORED_FOLDERS=.git .github"

rem Add more ignored folder names here by separating them with spaces.

if not exist "%TARGET_ROOT%" (
    mkdir "%TARGET_ROOT%" >nul 2>&1
)

echo Linking folders from %SOURCE_ROOT% to %TARGET_ROOT%...

for /d %%D in ("%SOURCE_ROOT%*") do (
    if exist "%%~fD" (
        set "folderName=%%~nxD"
        set "linkPath=%TARGET_ROOT%\!folderName!"

        call :IsIgnoredFolder "!folderName!"
        if not errorlevel 1 (
            echo Skipping ignored folder: !folderName!
        ) else (
            if exist "!linkPath!" (
                echo Skipping existing path: !linkPath!
            ) else (
                echo Linking !folderName!...
                mklink /J "!linkPath!" "%%~fD" >nul 2>&1
                if errorlevel 1 (
                    echo Failed to link !folderName!.
                ) else (
                    echo Created junction: !linkPath!
                )
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