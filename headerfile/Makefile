CC = gcc
CPP = g++
CFLAGS = -g -Wall

all: testmain

testmain: testmain.c util.o
	$(CC) $(CFLAGS) -o $@ $^
%.o: *.c
	$(CC) $(CFLAGS) -c $@ -o $^
