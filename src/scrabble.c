#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scrabbleDB.h"

#define CARDS 100



void PrintCard(DECK_T Tile[100], int i)
{
    char letter;
    int score;

    letter = Tile[i].alphab;
    score = Tile[i].score;
    printf ("Card Number %d:  %c %d \n",i+1, letter,score);
}


int main()
{
  int deck[CARDS];
  int i=0;
  char inputline[256]; /* string buffer */
  char command[256]; /* store command string */

  printf("Welcome to Scrabble Game!!!\n");

  printf("");

  DECK_T Tile[100];

  createDeck(Tile);

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
