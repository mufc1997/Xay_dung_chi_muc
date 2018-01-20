#include "../header/linkListInt.h"

int empty(nodeInt* root) {
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
  if(empty(*root)) {
    *root = initNode(trang);
  } else {
    nodeInt *node = initNode(trang), *cur = *root, *prev = cur;;
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
        if(cur != (*root)) {
          prev -> next = node;
          node -> next = cur;
        } else {
          node -> next = *root;
          *root = node;
        }
        return;
      }
      cur = cur -> next;
    }
  }
}

void printListInt(nodeInt *root) {
  nodeInt *cur = root;
  while(cur != NULL) {
    printf("%d ", cur -> trang);
    if(cur -> next == NULL) {
      printf(" \n");
    }
    cur = cur -> next;
  }
}
