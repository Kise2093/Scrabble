#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "scrabbleDB.h"



/* Display errors by type. */
void printError(int type)
{
    if(type == 0)
        printf("\n");
    else if(type == -1)
        printf("\n");
    else if(type == 111)
        printf("Error, can\'t recognize this command.\n");
    else if(type == 101)
        printf("\n\n");
}
