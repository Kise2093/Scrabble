#include <stdio.h>
#include <stdlib.h>


int createDeck(int argc, char* argv[])
{
  FILE* pinputFile;
  int amount;
  char alpabet;
  int score;
  int i;
  int j = 0;

  if(argc<3)
  {
    printf("(dbDeck.c)Error: 1");
    return 0;
  }

    pinputFile = fopen(argv[1],"r");

  if(pinputFile == NULL)
  {
    printf("(dbDeck.c)NULL:2");
    return 0;
  }

  DECK_T Tile[100];

  for(i=0;i<100 && fgets(input,sizeof(input),pIn)!=NULL && input[0]!=' ' && input[0]!='\n';i++)
  {
    sscanf(input,"%d,%c,%d", &amount, &alphabet, &score);


    if(amount>0)
    {
      for(j=0+j;j<amount;j++)
      {
        Tile[j].alphab=alphabet;
        Tile[j].score=score;
      }
    }
  }

}
