@echo off

set location = %cd%
set mingw_location = C:\MinGW\bin

del %location%\build\*.o
del %location%\bin\*.bin