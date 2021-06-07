  
CC=gcc
CFLAGS=-I.

all: lib server client

lib: libmult.c
	$(CC) -o libmult.o -c libmult.c $(CFLAGS)
	ar rcs libmult.a libmult.o

server: server.c libmult.a
	$(CC) -o server.o -c server.c $(CFLAGS)
	$(CC) -o server server.o libmult.c -pthread $(CFLAGS)

client: client.c
	$(CC) -o client.o -c client.c $(CFLAGS)
	$(CC) -o client client.o -pthread $(CFLAGS)

clean:
	rm client server client.o
