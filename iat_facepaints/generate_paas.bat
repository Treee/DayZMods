set SOURCE_FILEPATH=Z:\DayZ\SourceImages\characters\heads\
set DESTINATION_FILEPATH=Z:\DayZ\Modding\iat_facepaints\addons\facepaints\
SET IMAGE_TO_PAA_PATH="D:\Steam\steamapps\common\DayZ Tools\Bin\ImageToPAA"

cd D:
cd /d %IMAGE_TO_PAA_PATH%

@echo off
setlocal enabledelayedexpansion
for /R %SOURCE_FILEPATH% %%f in (*.tga) do (
	@REM Source File
	set currentSourceFile=%%f
	@REM echo From: !currentSourceFile!

	@REM Remove everything from the file path up to heads\
	set destinationFile=!currentSourceFile:*heads\=!
	@REM echo !destinationFile!

	@REM Remove the file for folder existence checks
	set destinationFolder=!destinationFile:\iat_shaved_mc.tga=!
	set destinationFolder=!destinationFolder:\iat_unshaved_mc.tga=!
	@REM echo Destination !destinationFolder!

	@REM Construct the destination path
	set newFolder=%DESTINATION_FILEPATH%!destinationFolder!
	@REM echo New !newFolder!

	@REM Folder existence check, make if null
	if not exist "!newFolder!\" mkdir !newFolder!

	@REM Replace the filepath from tga to paa
	set destinationFile=!destinationFile:.tga=.paa!
	@REM echo !destinationFile!

	@REM Construct final destination path
	set newPath=%DESTINATION_FILEPATH%!destinationFile!
	@REM echo To: !newPath!

	@REM Call ImageToPaa to convert tga's
	ImageToPAA.exe "%%f" "!newPath!"

	@REM echo/
)