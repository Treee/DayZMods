@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "SOURCE_ROOT=%~dp0"

echo Pulling latest code for all git repos in %SOURCE_ROOT%...
echo.

for /d %%D in ("%SOURCE_ROOT%*") do (
    set "REPO_PATH=%%~fD"
    set "folderName=%%~nxD"
    set "GIT_DIR="

    if exist "!REPO_PATH!\.git" (
        set "GIT_DIR=!REPO_PATH!\.git"
    ) else if exist "!REPO_PATH!\.git_disabled" (
        set "GIT_DIR=!REPO_PATH!\.git_disabled"
    )

    if not "!GIT_DIR!"=="" (
        echo ============================================
        echo Repo: !folderName!
        echo ============================================
        git --git-dir="!GIT_DIR!" --work-tree="!REPO_PATH!" pull
        if errorlevel 1 (
            echo.
            echo ^> Pull failed for !folderName!.
        )
        echo.
    )
)

endlocal
exit /b 0