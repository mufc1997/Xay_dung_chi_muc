#include "linkListInt.h"

typedef struct nodeChar {
  char *tungu;
  int solanlap;
  nodeInt *danhsachlap;
  struct nodeChar* next;
} nodeChar;

int emptyChar(nodeInt* root);
nodeChar* initNodeChar(char *tungu, int sodong);
nodeChar* searchNodeChar(nodeChar *root, char *tungu);
void addListChar(nodeChar** root, char *tungu, int sodong);
void printListChar(nodeChar *root);
