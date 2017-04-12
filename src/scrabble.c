#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scrabbleDB.h"

#define CARDS 100
#define LETTER 26


char bag[LETTER] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1}; /*Maximum letter for each alpabet*/
char letter[LETTER] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'} ;


void PrintCard(int deck[CARDS], int i)
{
    int tletter;
    int tbag;

    tletter = deck[i];
    tbag = deck[i];
    printf ("Card Number %d:  %c  %c\n",i+1, letter[tletter],bag[tbag]);
}


int main()
{
  int deck[CARDS];
  int i;
  char inputline[256]; /* string buffer */
  char command[256]; /* store command string */

  printf("Welcome to Scrabble Game!!!\n");

  for(i=0;i<CARDS;i++)
  {
  PrintCard(deck, i);
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
