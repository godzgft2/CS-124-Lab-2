CC = g++
CFLAGS = -g -Wall
all: main

main: main.o sorts.o searches.o linkedlist.o generalfx.o timing.o
	$(CC) $(CFLAGS) -o main main.o sorts.o searches.o linkedlist.o generalfx.o timing.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

sorts.o: sorts.cpp sorts.h
	$(CC) $(CFLAGS) -c sorts.cpp

searches.o: searches.cpp searches.h
	$(CC) $(CFLAGS) -c searches.cpp

timing.o: timing.cpp timing.h searches.h sorts.h linkedlist.h
	$(CC) $(CFLAGS) -c timing.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

generalfx.o: generalfx.cpp generalfx.h
	$(CC) $(CFLAGS) -c generalfx.cpp
