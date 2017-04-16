#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "scrabbleDB.h"

#define CARDS 100
#define LETTER 26


char bag[LETTER] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1}; /*Maximum letter for each alpabet*/
char letter[LETTER] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


typedef struct
{
  char alphab;
  int score;
}DECK_T;

DECK_T Tile[100];

void PrintCard(DECK_T Tile[100], int i)
{
    char letter;
    int tbag;

    letter = Tile[i].alphab;
    printf ("Card Number %d:  %c \n",i+1, letter);
}


int main()
{
  int deck[CARDS];
  int i=0;
  char inputline[256]; /* string buffer */
  char command[256]; /* store command string */

  printf("Welcome to Scrabble Game!!!\n");


for(i=0;i<CARDS;i++)
  {
  PrintCard(Tile, i);
}

  memset(command, 0, sizeof(command));
  fgets(inputline, sizeof(inputline), stdin);
  sscanf(inputline, "%s", command);

/*  while(1)
  {
    if(!strcasecmp(command,"resume"))
      resume();
    else if(!strcasecmp(command,"play"))
      play();
    else if(!strcasecmp(command,"exit"))
      exit(0);
    else if(command[0] !=0);
      printError(111);
    }*/
  }
