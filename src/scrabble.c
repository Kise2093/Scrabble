#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scrabbleDB.h"

char bag[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1}; /*Maximum letter for each alpabet*/
char letter[26] = {'a',}

int main()
{
  printf("Welcome to Scrabble Game!!!\n");

  memset(command, 0, sizeof(command));
  fgets(inputline, sizeof(inputline), stdin);
  sscanf(inputline, "%s", command);

  while(1)
  {
    if(!strcasecmp(command,"resume"));
      resume();
    else if(!strcasecmp(command,"play"));
      play();
    else if(!strcasecmp(command,"exit"));
      exit(0);
    else if(command[0] !=0);
      printError(111)
    }
  }

}
