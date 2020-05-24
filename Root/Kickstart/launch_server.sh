#!/bin/bash
### This script launches the logserver process in a new window.
### Magic is needed for OSX as I can't rely on xterm being installed!
### Only works when logged in via the console, not Putty/SSH
### It is not necessary to understand this script!


if [ $(uname) == "Darwin" ]
then
	
	osascript -e 'tell application "Terminal" to do script "cd '$PWD'; \
                 ./logserver; exit; "'
else
	xterm -title "Log Server" -e './logserver; \
		echo press enter to exit; read junk;' &
fi
