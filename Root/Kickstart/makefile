# makefile -- rules to build OSP workshop C
# to use simply type "make"
# this will build the server and client and launcher script
# note, this is a configuration file for the MAKE utility
# do not try to run it directly
# if typing up the file, the indented lines need to be indented
# with TABS not spaces.
 
all: logserver logclient
	chmod +x launch_server.sh

clean:
	rm -f *.o logserver logclient

logclient: logclient.o logservice.o

logservice.o: logservice.c logservice.h

logserver: logserver.o

logserver.o: logserver.c logservice.h
