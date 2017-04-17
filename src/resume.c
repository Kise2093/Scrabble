/*Resume function for resuming to the last save files.
  TEAM BLACKGROUND
  59070503405*/

#include <stdio.h>
#include <string.h>
#include "scrabbleDB.h"



void resume()
{
  char command[256]; /* store command string */
  char inputline[256]; /* string buffer */

  printf("Hey, the function resume is not ready yet please come again next time.\n");
  printf("Play     |     Pass\n" );
  printf("Challenge|     END\n" );

  memset(command, 0, sizeof(command));
  fgets(inputline, sizeof(inputline), stdin);
  sscanf(inputline, "%s", command);

  if(!strcasecmp(command,"play"))
    {
      printf("Play your words\n");
    }
  else if(!strcasecmp(command,"Pass"))
  {
    printf("Pass your turn\n");
  }
  else if(!strcasecmp(command,"Challenge"))
  {
    printf("Challenge this player\n");
  }
  else if(!strcasecmp(command,"END"))
  {
    printf("End the game. Will ask if the user want to save or not\n");
  }
}
