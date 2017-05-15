/*This is main file for our entire program.
  scrabble.c is created by Kris Jermvivatkul
  Student id 59070503405*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scrabbleDB.h"

#define CARDS 100
#define FILENAME "oldwordlist.txt"

_board field [16][16] ; //Use only 15*15

void createBoard ()
{

    int i = 0;
    int j = 0;

    for (i = 0 ; i < 15 ;i++)
        {

        for (j = 0 ;j <15 ; j++)
            {
            field[i][j].tile = ' ' ;
            field[i][j].letterX = 1 ;
            field[i][j].wordX = 1;

            if ( (i == 0 || i == 7 || i == 14 ) && ( j== 0 || j==7 || j== 14  )  )
                field[i][j].wordX = 3 ;

        else if ( (i == 5 || i == 9) && (j==1 || j==5 || j==9 || j==13) )
                field[i][j].letterX = 3 ;
        else if ( (i==1 || i==13 ) && ( j==5 || j==9 ) )
                field[i][j].letterX = 3 ;
        else if ( (i == 3 || i== 11) && ( j== 0 ||j==7 || j == 14) )
                field[i][j].letterX = 2 ;
        else if ( (i == 0 || i== 7  || i==14 ) && (j==3 || j == 11) )
                field[i][j].letterX = 2 ;
        else if ((i==2|| i==6 || i==8 || i==12) && (j==2 || j== 6 || j==8 || j==12) )
                field[i][j].letterX = 2 ;
        else if ((i== 1 || i== 13 ) && (j== 1|| j== 13 ))
                field[i][j].wordX = 2;
        else if ((i == 2 || i== 12 ) && (j== 2|| j==12 ))
                field[i][j].wordX = 2;
        else if ((i == 3 || i== 11 ) && (j==3 || j==11 ))
                field[i][j].wordX = 2;
        else if ((i == 4 || i== 10 ) && (j==4 || j==10 ))
                field[i][j].wordX = 2;
            }


        }

}

void drawnBoard()
{

int i,j ;

printf("\t\t\t\t\t");
for (j = 0 ; j <15 ; j++)
    {
    printf("  %c  ",65+j);
    }



printf("\n");
printf("\t\t\t\t\t");
i = 0 ; j = 0 ;
for (i= 0 ; i < 15 ; i++)
    {
    //Open Line at the top
    for (j=0; j <15 ;j++ )
        {

        if(field[i][j].wordX == 3)
            {
            if (i == 7 && j ==7)
                {
                 printf("+++++");
                }
            else printf("+++++");
            }
        else if (field[i][j].wordX == 2)
            {
            printf("+++++");
            }

        else if (field[i][j].letterX == 3)
                printf("-----");

        else if (field[i][j].letterX == 2)
                printf("-----");

        else
        printf(".....");
        }
        printf("\n");
        printf("\t\t\t\t\t");

    //Line 1 for each position
    for (j=0 ; j<15 ; j++)
        {

        if (field[i][j].tile == ' ')
        {

        if(field[i][j].wordX == 3)
            {
            if (i == 7 && j ==7)
                {
                printf("|   |");
                }
            else printf("+ W +");
            }
        else if (field[i][j].wordX == 2)
            {
            printf("+ W +");
            }

        else if (field[i][j].letterX == 3)
                printf("- L -");

        else if (field[i][j].letterX == 2)
                printf("- L -");

        else
        printf("|   |");

        }

        else if (field[i][j].tile != '\0')
        printf("|   |");

        else
        printf("|   |");
        }

    printf("\n");
    printf("\t\t\t\t\t");

    //Line 2 for each position
    for (j=0 ; j < 15 ; j++)
        {

        if (field[i][j].tile == ' ')
        {

            if(field[i][j].wordX == 3)
            {
            if (i == 7 && j ==7)
                {
                printf(". X .");
                }
           else printf(". X .");
            }

        else if (field[i][j].wordX == 2)
            {
            printf(". X .");
            }
        else if (field[i][j].letterX == 3)
                printf(". X .");

        else if (field[i][j].letterX == 2)
                printf(". X .");

        else
        printf("|   |");

        }

        else if (field[i][j].tile != ' ')
            {
            printf("|%3c|",field[i][j].tile);
            }



        }
        printf(" %d",i+1);
        printf("\n");
        printf("\t\t\t\t\t");

        for (j=0 ; j<15 ; j++)
        {

        if (field[i][j].tile == ' ')
        {

        if(field[i][j].wordX == 3)
            {
            if ( i == 7 && j ==7 )
                {
                printf("|   |");
                }
            else printf("+ 3 +");
            }
        else if (field[i][j].wordX == 2)
            {
            printf("- 2 -");
            }

        else if (field[i][j].letterX == 3)
                printf("+ 3 +");

        else if (field[i][j].letterX == 2)
                printf("- 2 -");

        else if (field[i][j].tile != '\0')
        printf("|   |");
        else
        printf("|   |");
        }

        else if (field[i][j].tile != ' ')
            printf("|   |");

        }

    printf("\n");
    printf("\t\t\t\t\t");


    for (j = 0 ; j<15 ; j++)
        {
        if(field[i][j].wordX == 3)
            {
            if (i == 7 && j ==7)
                {
                printf("+++++");
                }
            else printf("+++++");
            }
        else if (field[i][j].wordX == 2)
            {
            printf("+++++");
            }

        else if (field[i][j].letterX == 3)
                printf("-----");

        else if (field[i][j].letterX == 2)
                printf("-----");

        else
        printf(".....");
        }
    printf("\n");
    printf("\t\t\t\t\t");

    }

}


int main()
{
  int deck[CARDS];
  int i=0;
  char inputline[256]; /* string buffer */
  char command[256]; /* store command string */
  FILE* pInputFile=NULL;

  printf("Welcome to Scrabble Game!!!\n");

  printf(">Play\n");
  printf(">Deck\n");
  printf(">Resume\n");
  printf(">Deck\n");

  createBoard();

  DECK_T Tile[100];

  createDeck(Tile);

  pInputFile = fopen(FILENAME,"r");


if(pInputFile == NULL)
{
  printf("(dbDeck.c)NULL:2");
  return 0;
}
  buildDictionary(pInputFile);
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
