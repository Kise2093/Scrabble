#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Note field[i][j]
// i = Vertical Line = column
// j = Horizontal Line = row



//Define each of position in board
typedef struct
{
char tile[3] ;
int letterX ;
int wordX ;

}_board ;


//Define players
typedef struct
{

int score ;
int turn ;
int player ;
char word [12];

}_playerN ;

_board field [16][16] ; //Use only 15*15

void createBoard ()
{

    int i = 0;
    int j = 0;

    for (i = 0 ; i < 15 ;i++)
        {

        for (j = 0 ;j <15 ; j++)
            {
            field[i][j].tile[0] = ' ' ;
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


int getStart (int *row , int *column)
{
char input [64];
int i = 0,j = 0 ;
char direction [10];

    memset(input,0,sizeof(input));

    printf("\n Enter Row/Column to place a word: ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%d/%d",i,j);
    *row    = j ;
    *column = i ;

}

int getDirec (char direction[])
{

    char input [10];
    printf("\n Enter Horizontal or Vertical (H / R):  ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%c",&direction);

    if (direction[0] == 'H' )
        return(1);

}

/* Draft Board

-----   -----   -----  -----
| w |   | L |   |   |  |   |
| x |   | x |   | X |  |___|
| 3 |   | 3 |   |   |  |   |
-----   -----   -----  -----


*/
void drawnBoard (void)
{

int i,j ;

printf("\t\t\t\t\t");
for (j = 0 ; j <9 ; j++)
    {
    printf("  %d  ",j+1);
    }

    printf(" 10   11   12   13   14   15");

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

        if (field[i][j].tile[0] == ' ')
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

        if (field[i][j].tile[0] == ' ')
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

        else if (field[i][j].tile[0] != ' ')
            {
            printf("|%3c|",field[i][j].tile);
            }



        }
        printf(" %d",i+1);
        printf("\n");
        printf("\t\t\t\t\t");

        for (j=0 ; j<15 ; j++)
        {

        if (field[i][j].tile[0] == ' ')
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

        else if (field[i][j].tile[0] != ' ')
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


void save ()
{
FILE * outpt = NULL ;
char saveLett [300];
int i = 0 ,j = 0;

outpt = fopen("/savegame/save.txt","w");

//Save board
for(i = 0;i<15;i++)
    {
    for(j=0;j<15;j++)
        {
        if(field[i][j].tile[0] != ' ' )
            {
            fprintf(outpt,"%d %d %c\n",i,j,field[i][j].tile);
            }
        }
    }
fprintf(outpt,"-1 -1 l\n");

//Save Score

fprintf(outpt,"EndS\n");
//Save Deck

fprintf(outpt,"EndD\n");
fclose(outpt);

}

/**  Testing Zone **/

void resume()
{
FILE* op = NULL ;
char input [230];
op = fopen("/savegame/save.txt","r");
int i = 0 , j = 0 ;
char letter[2] ;

while(fgets(input,sizeof(input),op) != NULL )
    {

    sscanf(input,"%d %d %c",&i,&j,&letter);

    strcpy(field[i][j].tile,letter);

    if( i == -1 && j == -1 && letter[0] == 'l')
    break;


    memset(letter,0,sizeof(letter));
    }
//Set board same as last game

//Set Score

//Set Deck
fclose(op);
}




/*****/


int main ()
{
char input [64];
int i,j,row,column;
createBoard();
char word [64];
char direction [10];



drawnBoard();


/*
while(1)
    {

    i = -1 ; j = -1 ; row = -1; column = -1 ;

    getStart(&row,&column);

    getDirec(direction);

    memset(input,0,sizeof(input));
    printf("\n Enter Word");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%s",word);



    }
    */

}
