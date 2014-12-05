CC = gcc
CFLAGS = -g
CFILES = malloc.c test.c

HFILES = headers.h
all: malloc

malloc : $(CFILES)
	$(CC) $(CFLAGS) -o run $(CFILES)
