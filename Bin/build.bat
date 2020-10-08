@ECHO OFF
SET App=GUI
SET Libraries=..\Lib\Retro.a
SET Include=-I..\Lib\Mod -I..\Lib\Obj
SET Start=TRUE

%XDev%\WinDev\Bin\Build.bat %1
