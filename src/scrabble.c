#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scrabbleDB.h"

#define CARDS 100



int main()
{
  int deck[CARDS];
  int i=0;
  char inputline[256]; /* string buffer */
  char command[256]; /* store command string */

  printf("Welcome to Scrabble Game!!!\n");

  printf(">Play\n");
  printf(">View deck\n");
  printf(">Resume\n");

  DECK_T Tile[100];

  createDeck(Tile);

  memset(command, 0, sizeof(command));
  fgets(inputline, sizeof(inputline), stdin);
  sscanf(inputline, "%s", command);

  while(1)
  {
    if(!strcasecmp(command,"deck"))
    {
      for(i=0;i<CARDS;i++)
        {
        PrintCard(Tile, i);
        }
    return 0;
    }
    else if(!strcasecmp(command,"play"))
    {
      play();
      break;
    }
    else if(!strcasecmp(command,"resume"))
    {
      resume();
      return 0;
    }
    else if(!strcasecmp(command,"exit"))
      exit(0);
    /*else if(command[0] !=0);
      printError(111);*/
    }
  }
