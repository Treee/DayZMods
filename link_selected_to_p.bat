@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "TARGET_ROOT=C:\Users\Tree\Documents\DayZ Projects"
set "IGNORED_FOLDERS=.git .github"

rem Add more ignored folder names here by separating them with spaces.

if "%~1"=="" (
    echo Drag and drop one or more folders onto this batch file.
    echo Example: link_selected_to_p.bat "Z:\DayZ\Modding_3rdParty\Empty.Tombstone"
    exit /b 1
)

if not exist "%TARGET_ROOT%" (
    mkdir "%TARGET_ROOT%" >nul 2>&1
)

:loop
if "%~1"=="" goto :eof

set "SOURCE_PATH=%~f1"
if exist "%SOURCE_PATH%" (
    if exist "%SOURCE_PATH%\" (
        set "NAME=%~nx1"
        set "LINK_PATH=%TARGET_ROOT%\!NAME!"

        call :IsIgnoredFolder "!NAME!"
        if not errorlevel 1 (
            echo Skipping ignored folder: !NAME!
        ) else (
            if exist "!LINK_PATH!" (
                echo Skipping existing path: !LINK_PATH!
            ) else (
                echo Linking !NAME!...
                mklink /J "!LINK_PATH!" "%SOURCE_PATH%" >nul 2>&1
                if errorlevel 1 (
                    echo Failed to link !NAME!.
                ) else (
                    echo Created junction: !LINK_PATH!
                )
            )
        )
    ) else (
        echo Skipping non-folder item: %~1
    )
) else (
    echo Source not found: %~1
)

shift
goto loop

endlocal
exit /b 0

:IsIgnoredFolder
set "folderName=%~1"
for %%I in (%IGNORED_FOLDERS%) do (
    if /I "%%~I"=="!folderName!" exit /b 0
)
exit /b 1