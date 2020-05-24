@echo off
@setlocal 

set start=%time%
del /S *.exe
del /S *.o
cmd /c %*

set end=%time%