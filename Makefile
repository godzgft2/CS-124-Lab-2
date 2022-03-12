CC = g++
CFLAGS = -g -Wall
all: main

main: main.o sorts.o searches.o linkedlist.o generalfx.o
	$(CC) $(CFLAGS) -o main main.o sorts.o searches.o linkedlist.o generalfx.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

sorts.o: sorts.cpp sorts.h
	$(CC) $(CFLAGS) -c sorts.cpp

searches.o: searches.cpp searches.h
	$(CC) $(CFLAGS) -c searches.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

generalfx.o: generalfx.cpp generalfx.h
	$(CC) $(CFLAGS) -c generalfx.cpp
