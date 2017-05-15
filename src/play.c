/*Function for playing the game
  TEAM BLACKGROUND
  59070503405*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scrabbleDB.h"



typedef struct _player
{
  DECK_T card[7];
  struct _player *pNext;

}PLAYER_T;

int insertWord(char *word,int row,int col,int dir)
{
  char onechar;
	char buffer[256];

    size_t length;
    printf("enter word, or <ENTER> to restart: ");

	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", word);
  char *temp=word;

    if (word[0] == '\n')  // \newline indicates user requests restart
        return -1;
        // otherwise remove newline char
    word[strcspn(word,"\n")]='\0';
        // and check that only alpha characters are permitted
    /*while(*temp)
    {
        onechar = *temp++ &= 0x5F; //converts alpha to UPPERCASE
        if (onechar < 'A' || onechar > 'Z')
        {
            printf("not valid, try again.\n");
            return 0;
        }
    }*/
  return 1;
}

int getAxis(int *dir)
{
	char buffer[256];
    char input[16];


    printf("enter direction 'H'(0) or 'V'(1), or <ENTER> to restart: ");
    fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", input);

    input[0] &= 0x5F; //converts alpha to UPPERCASE
    if (input[0]=='H' || input[0] == '0')
    {
        *dir = 0;
        return 1;
    }
    if (input[0]=='V' || input[0] == '1')
    {
        *dir = 1;
        return 1;
    }
    if (input[0]=='\n')
        return -1;
    printf("not valid, try again.\n");
    return 0;
}


int getCoordinate(int *row,int *col)
{
	char buffer[256];
    char *temp;
	char input[16];


    printf("enter row/col to start (ex: H 8) or 'Q' to quit: ");
    fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", input);

    input[0] &= 0x5F; //converts alpha to UPPERCASE
    if (input[0]=='Q')
        return -1;
    *row = input[0]-0x41; // zero-based index
    if (*row<0 || *row>14)
    {
        printf("not valid, try again.\n");
        return 0;
    }
    *col = strtol(&input[1],&temp,10);
    if (temp==&input[1] || *col<1 || *col>15)
    {
        printf("not valid, try again.\n");
        return 0;
    }
    *col = *col - 1; // make column zero-based index
    return 1;
}




void play()
{
int row, col, result, direction;
char word[17];
char command[256]; /* store command string */
char inputline[256]; /* string buffer */
int amountPeople=0;
int i = 0;
PLAYER_T* pHead = NULL;
PLAYER_T* pTail = NULL;
PLAYER_T* player=NULL;


do
{
  printf("How many player are there? (1-4)");
  fgets(inputline, sizeof(inputline),stdin);
  sscanf(inputline,"%d",&amountPeople);
}while(amountPeople<1 && amountPeople>4);

for(i=0;i<amountPeople;i++)
{
player =(PLAYER_T*)calloc(1,sizeof(PLAYER_T));

if(pHead==NULL)
{
  pHead=pTail=player;
}
else
{
  pTail->pNext = player;
}
pTail=player;
}


do{
printf("Do you want to play or pass this turn? (play or pass)\n" );

memset(command, 0, sizeof(command));
fgets(inputline, sizeof(inputline), stdin);
sscanf(inputline, "%s", command);

if(!strcasecmp(command,"play"))
  {
    memset(command, 0, sizeof(command));

    do result = getCoordinate(&row, &col);
    while (result == 0);
    if (result == -1)
        break;

    do result = getAxis(&direction);
    while (result == 0);
    if (result == -1)
        continue;

    do result = insertWord(word, row, col, direction);
    while (result == 0);
    if (result == -1)
        continue;

    printf("Do other player want to challenge this word? (Yes or No)\n");
    fgets(inputline,sizeof(inputline),stdin);
    sscanf(inputline,"%s",command);

    if(!strcasecmp(command,"yes"))
    {
      findWord(word);
      if(result==0)
      {
        /*The challenger will lose this turn*/
        if(player->pNext==pTail)
        {
          pHead = player->pNext;
          continue;
        }
        else
        {
          player= player->pNext;
          continue;
        }
      }
      else /*Else if there is no word match to the dictionary.*/
      {
        /*They will lose this turn*/
        if(player->pNext==pTail)
        {
          pHead = player->pNext;
          continue;
        }
        else
        {
          player= player->pNext;
          continue;
        }
      }
    }
    else
    {
      if(player->pNext==pTail)
      {
        pHead = player->pNext;
        continue;
      }
      else
      {
        player= player->pNext;
        continue;
      }
    }

  }
else if(!strcasecmp(command,"END")&& (!strcasecmp(command,"pass")))
  {
    if(player->pNext==pTail)
    {
      pHead = player->pNext;
      continue;
    }
    else
    {
      player= player->pNext;
      continue;
    }
  }
  else
  {
    printf("There is no such command\n");
    continue;
  }
}while(1);
}
