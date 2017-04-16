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

for(i=0;i<=9;i++)
  {
    Tile[i].alphab ='a';
  }
for(i=9;i<=11;i++)
  {
    Tile[i].alphab ='b';
  }
for(i=11;i<=13;i++)
  {
    Tile[i].alphab ='c';
  }
for(i=13;i<=17;i++)
  {
    Tile[i].alphab ='d';
  }
for(i=17;i<=29;i++)
  {
    Tile[i].alphab ='e';
  }
for(i=29;i<=31;i++)
  {
    Tile[i].alphab ='f';
  }
for(i=31;i<=34;i++)
{
  Tile[i].alphab ='g';
}
for(i=34;i<=36;i++)
  {
    Tile[i].alphab ='h';
  }
  for(i=36;i<=45;i++)
    {
      Tile[i].alphab ='i';
    }
for(i=45;i<=46;i++)
  {
    Tile[i].alphab ='j';
  }
for(i=46;i<=47;i++)
  {
    Tile[i].alphab ='k';
  }
for(i=47;i<=51;i++)
  {
    Tile[i].alphab ='l';
  }
for(i=51;i<=53;i++)
  {
    Tile[i].alphab ='m';
  }
for(i=53;i<=59;i++)
  {
    Tile[i].alphab ='n';
  }
for(i=59;i<=67;i++)
  {
    Tile[i].alphab ='o';
  }
for(i=67;i<=69;i++)
  {
    Tile[i].alphab ='p';
  }
for(i=69;i<=70;i++)
  {
    Tile[i].alphab ='q';
  }
for(i=70;i<=76;i++)
  {
    Tile[i].alphab ='r';
  }
for(i=76;i<=80;i++)
  {
    Tile[i].alphab ='s';
  }
for(i=80;i<=86;i++)
  {
    Tile[i].alphab ='t';
  }
for(i=86;i<=90;i++)
  {
    Tile[i].alphab ='u';
  }
  for(i=90;i<=92;i++)
    {
      Tile[i].alphab ='v';
    }
for(i=92;i<=94;i++)
  {
    Tile[i].alphab ='w';
  }
for(i=94;i<=95;i++)
  {
    Tile[i].alphab ='x';
  }
for(i=95;i<=97;i++)
  {
    Tile[i].alphab ='y';
  }
for(i=97;i<98;i++)
  {
    Tile[i].alphab ='z';
  }


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
