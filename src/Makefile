# Makefile for demo programs for Lecture 11
# Hash tables

ifeq ($(OSTYPE),WINDOWS)
	EXECEXT =.exe
	COMP	=__MINGCC__
	PLATFORM	=mingw
else
	EXECEXT =
	COMP	=__GCC__
	PLATFORM	=linux
endif

EXECUTABLES= scrabble$(EXECEXT)

all : $(EXECUTABLES)

scrabble.o :	scrabble.c scrabbleDB.h
	gcc -c scrabble.c

play.o :	play.c scrabbleDB.h
	gcc -c play.c

dbDeck.o :	dbDeck.c scrabbleDB.h
	gcc -c dbDeck.c

dbDict.o :	dbDict.c scrabbleDB.h abstractHashTable.h
	gcc -c dbDict.c

chainedHashTable.o : chainedHashTable.c abstractHashTable.h
	gcc -c chainedHashTable.c

resume.o :	resume.c scrabbleDB.h
	gcc -c resume.c


scrabble$(EXECEXT) : scrabble.o play.o dbDict.o dbDeck.o chainedHashTable.o resume.o
	gcc -o scrabble$(EXECEXT) scrabble.o play.o dbDict.o dbDeck.o chainedHashTable.o resume.o


clean :
	-rm *.o
	-rm $(EXECUTABLES)
