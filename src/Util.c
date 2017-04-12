#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "scrabbleDB.h"



/* Display errors by type. */
void printError(int type)
{
    if(type == 0)
        printf("DB Error: Can't open database file.\n");
    else if(type == -1)
        printf("DB Error: Can't access the record properly.\n");
    else if(type == 111)
        printf("Error, can\'t recognize this command.\n");
    else if(type == 101)
        printf("This database is empty.\n\n");
}
