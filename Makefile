
CFLAGS+=-O
CFLAGS+=-g
CFLAGS+=-Wall -Werror
#CFLAGS+=-Wno-unused-function

LDLIBS+=-lm

.PHONY: all clean world

all:: prog5_server prog5_client

prog5_client: prog5_client.o wrapper.o in_out.o query.o

prog5_server: prog5_server.o wrapper.o in_out.o serv.o

clean::
	rm -f *.o prog5_client prog5_server

world:: clean all

prog5_client.o:: prog5_client.c query.h wrapper.h in_out.h
in_out.c:: in_out.h
wrapper.c:: wrapper.h
query.c:: query.h wrapper.h in_out.h

prog5_server.o:: prog5_server.c serv.h wrapper.h in_out.h
serv.c:: serv.h wrapper.h
