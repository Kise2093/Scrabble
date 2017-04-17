/*This function is for creating and printing out deck of card/tile for the game.
  Created by Kris Jermvivatkul
  59070503405
  TEAM BLACKGROUND*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scrabbleDB.h"


void createDeck(DECK_T Tile[100])
{
  FILE* pinputFile;

  char input[256];
  int amount;
  char alphabet;
  int score;
  int i = 0;
  int j = 0;
  int count;


    pinputFile = fopen("Tile.txt","r");

  if(pinputFile == NULL)
  {
    printf("(dbDeck.c)NULL:2");
    return;
  }



  for(i=0;i<100 && fgets(input,sizeof(input),pinputFile)!=NULL && input[0]!=' ' && input[0]!='\n';i++)
  {
    sscanf(input,"%d,%c,%d", &amount, &alphabet, &score);

    if(amount>0)
    {
      for(count=0;count<amount;count++)
      {
        Tile[j].alphab = alphabet;
        Tile[j].score = score;
        j++;

      }
    }
  }

}

void PrintCard(DECK_T Tile[100], int i)
{
    char letter;
    int score;

    letter = Tile[i].alphab;
    score = Tile[i].score;
    printf ("Card Number %d:  %c %d \n",i+1, letter,score);
}
