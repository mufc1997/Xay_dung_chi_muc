#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodeInt {
  int trang;
  struct nodeInt* next;
} nodeInt;

int empty(nodeInt* root);
nodeInt* initListInt(int trang);
nodeInt* searchNode(nodeInt *root, int trang);
void addListInt(nodeInt** root, int trang);
void printListInt(nodeInt *root);
