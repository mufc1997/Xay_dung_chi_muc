#include "../header/linkListChar.h"

int emptyChar(nodeChar* root) {
  if(root == NULL)
    return 1;
  return 0;
}

nodeChar* initNodeChar(char *tungu, int sodong) {
  nodeChar *root = malloc(sizeof(nodeChar));
  root -> tungu = malloc(sizeof(char) * 30);
  strcpy(root -> tungu, tungu);
  root -> danhsachlap = NULL;
  addListInt(&root -> danhsachlap, sodong);
  root -> solanlap = 1;
  root -> next = NULL;
  return root;
}

nodeChar* searchNodeChar(nodeChar *root, char *tungu) {
  nodeChar *node = NULL, *cur = root;
  while(cur != NULL) {
    if(strcmp(cur -> tungu, tungu) == 0) {
      node = cur;
      break;
    }
    cur = cur -> next;
  }
  return node;
}
void addListChar(nodeChar** root, char *tungu, int sodong) {
  nodeChar *searchNode;
  if(emptyChar(*root)) {
    *root = initNodeChar(tungu, sodong);
  } else {

    nodeChar *node = initNodeChar(tungu, sodong), *prev, *cur = *root;
    if((searchNode = searchNodeChar(*root, tungu)) != NULL) {
      (searchNode -> solanlap)++;
      addListInt(&(searchNode -> danhsachlap), sodong);
      return;
    }
    if((*root) -> next == NULL) {
      if(strcmp((*root) -> tungu, tungu) < 0) {
        (*root) -> next = node;
      } else if(strcmp((*root) -> tungu, tungu) > 0){
        node -> next = *root;
        *root = node;
      }
      return;
    }
    while(cur != NULL) {
      if(strcmp(cur -> tungu, tungu) < 0) {
        prev = cur;
        if(cur -> next == NULL) {
          prev -> next = node;
        }
      } else if(strcmp(cur -> tungu, tungu) > 0){
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

void printListChar(nodeChar *root) {
  nodeChar *cur = root;
  printf("%-30s | %-10s | %-10s |\n", "Tu", "So lan lap", "Danh sach lap");
  printf("===========================================================\n");
  while(cur != NULL) {
    printf("%-30s | ", cur -> tungu);
    printf("%-10d | ", cur -> solanlap);
    printListInt(cur -> danhsachlap);
    cur = cur -> next;
  }
}
