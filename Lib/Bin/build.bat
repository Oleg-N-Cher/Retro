@ECHO OFF
SET Lib=..\Retro.a
IF EXIST %Lib% DEL %Lib%

CALL ..\Bin\solid.bat %Lib% Retro
CALL ..\Bin\smart.bat %Lib% GrFonts
CALL ..\Bin\solid.bat %Lib% Basic
CALL ..\Bin\smart.bat %Lib% Console
CALL ..\Bin\smart.bat %Lib% GrTiles
CALL ..\Bin\solid.bat %Lib% Laser2
