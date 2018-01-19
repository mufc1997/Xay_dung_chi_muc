#include <stdio.h>
#include "../header/linkListInt.h"
#include<stdlib.h>


int emptyChar(nodeInt* root) {
  if(root == NULL)
    return 1;
  return 0;
}

nodeInt* initNode(int trang) {
  nodeInt *root = malloc(sizeof(nodeInt));
  root -> trang = trang;
  root -> next = NULL;
  return root;
}

nodeInt* searchNode(nodeInt *root, int trang) {
  nodeInt *node = NULL, *cur = root;
  while(cur != NULL) {
    if(cur -> trang == trang) {
      node = cur;
      break;
    }
    cur = cur -> next;
  }
  return node;
}
void addListInt(nodeInt** root, int trang) {
  if(emptyChar(*root)) {
    *root = initNode(trang);
  } else {
    nodeInt *node = initNode(trang), *prev, *cur = *root;
    if(searchNode(*root, trang) != NULL)
      return;
    if((*root) -> next == NULL) {
      if((*root) -> trang < trang) {
        (*root) -> next = node;
      } else if((*root) -> trang > trang){
        node -> next = *root;
        *root = node;
      }
      return;
    }
    while(cur != NULL) {
      if(cur -> trang < trang) {
        prev = cur;
        if(cur -> next == NULL) {
          prev -> next = node;
        }
      } else if(cur -> trang > trang){
        prev -> next = node;
        node -> next = cur;
      }
      cur = cur -> next;
    }
  }
}

void printListInt(nodeInt *root) {
  nodeInt *cur = root;
  while(cur != NULL) {
    printf("%d\n", cur -> trang);
    cur = cur -> next;
  }
}
