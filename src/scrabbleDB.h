

typedef struct
{
  char alphab;
  int score;
}DECK_T;

DECK_T Tile[100];

void play();

void resume();

void createDeck(DECK_T Tile[100]);

void PrintCard(DECK_T Tile[100], int i);

char createPlayer(int amountPeople);
int buildDictionary(FILE* pFile);
int findWord(char* word);
