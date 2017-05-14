/**
 * hashDictionary.c
 *
 * Implements a dictionary using an external hash table
 *
 * This program was created by Aj. Sally.
 * Will be modify by TEAM BLACKGROUND for project purposes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstractHashTable.h"
#include "scrabbleDB.h"

#define BUCKET_COUNT 53

/* Structure to store one word with its definition */
/* This will be the data we store in the hash table */
typedef struct
{
    char word[64];      /* word we want to store */
    int defcount;       /* how many definitions are there? */
    char definition[3][256];  /* space for up to three definitions */
} DICT_ENTRY_T;


/* Robust hash function that uses bitwise operations to
 * modify string values. Adapted from Kyle Loudon,
 * "Mastering Algorithms with C"
 */
unsigned int bitwiseOpHash(char* key)
{
    unsigned int result = 0;
    unsigned int tmp = 0;
    int size = hashTableSize();
    int i = 0;
    for (i = 0; i < strlen(key); i++)
        {
	/* shift up four bits then add in next char */
	result = (result << 4) + key[i];
        if ((tmp = (result & 0xf0000000)))  /* if high bit is set */
	    {
	    /* XOR result with down shifted tmp */
	    result = result ^ (tmp >> 24);
            /* then XOR with tmp itself */
	    result = result ^ tmp;
	    }
        }
    result = result % size;   /* make it fit in the table size */
    return result;
}



/* Read word file and construct the dictionary.
 * Arguments
 *  pFile      -  file pointer for reading, assumed open and checked.
 * Returns 1 if successful, 0 for allocation failure or read error.
 */
int buildDictionary(FILE* pFile)
{
    char input[512];      /* buffer to store word and definition from file */
    char* pDelim = NULL;  /* used to find position of '|' */
    DICT_ENTRY_T * pEntry = NULL;
    int returnVal = 1;
    int collision = 0;    /* collision variable - set to 1 or 0 by insert */
    char tempword[64];    /* hold the word while we are figuring out
                           * if it already exists
			   */
    int insertcount = 0;   /* count the total number of insertions */
    int collisioncount = 0; /* count the number of insertions that cause collisions */
    int bFound = 0;
    while ((fgets(input,sizeof(input),pFile) != NULL) &&
           (returnVal == 1))
       {
       int len = strlen(input);
       if (input[len-1] == '\n')
          {
	  input[len-1] = '\0';    /* get rid of newline */
          }
       pDelim = strpbrk(input,"|");  /* find the vertical bar */
       if (pDelim != NULL)           /* if no delim, just skip the line */
          {
	  *pDelim = '\0';              /* replace ':' with 0 */
          strcpy(tempword,input);      /* copy the word */
          pEntry = hashTableLookup(tempword);
          /* see if it's already there */
          if (pEntry == NULL)  /* not there, so we need to allocate */
	     {
	     bFound = 0;
             /* allocate new dictionary entry */
             pEntry = (DICT_ENTRY_T*) calloc(1,sizeof(DICT_ENTRY_T));
             if (pEntry == NULL) /* allocation error */
	        {
	        returnVal = 0;
                break; /* this is not a recoverable error so exit */
	        }
             }
	  else
	     {
	     bFound = 1;
             }
	  strcpy(pEntry->word,tempword);  /* copy the word */
	  if (pEntry->defcount < 3)
	     {
	     strcpy(pEntry->definition[pEntry->defcount],(pDelim+1));
	     pEntry->defcount++;
	     }
          else
	     {
	     printf("Word '%s' already has maximum number of definitions - not saved\n",
                          tempword);
             }
          if (!bFound) /* if it is not already in the hashtable */
	     {
	     /* Put the entry into the dictionary */
	     returnVal = hashTableInsert(pEntry->word,pEntry,&collision);
             if (returnVal)  /* success */
	        {
		insertcount++;
                if (collision)
		  collisioncount++;
                }
	     }
          }  /* if no delimiter, just skip the line */
       }
    //printf("With bucket count %d, we got %5.2f%% collisions\n",
	   //BUCKET_COUNT, ((double) collisioncount / insertcount) * 100.0);

    return returnVal;
}

/* print the definitions for a word, or print 'Not Found'
 * if not in the dictionary. Note that a single word could
 * have more than one definition
 * Arguments
 *   word          -   Word to look up
 */
void findWord(char* word)
{
    DICT_ENTRY_T* pWord = NULL;
    printf("\n");


    pWord = (DICT_ENTRY_T*) hashTableLookup(word);

    if (pWord == NULL)
       {
       printf("Word '%s' not found in the dictionary\n",word);
       }
    else
       {
       int i;
       printf("Word: %s \n",pWord->word);
       for (i=0; i < pWord->defcount; i++)
  	  printf("\tDefinition %d: %s\n",i+1,pWord->definition[i]);
       }
    printf("\n");

}
