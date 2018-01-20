#include "./header/readFile.h"

int main() {
  nodeChar *root = NULL; //node vanban.txt
  nodeChar *check = NULL; //node stop.txt
  nodeChar *nullNode = NULL;
  readFile(&check, &nullNode, "./public/stop.txt", "r");
  readFile(&root, &check, "./public/vanban.txt", "r");
  printf("***************************************************************\n");
  printf("Danh sach cac tu trong file stop.txt\n");
  printf("***************************************************************\n");
  printListChar(check);
  printf("***************************************************************\n");
  printf("Index cac tu trong file vanban.txt\n");
  printf("***************************************************************\n");
  printListChar(root);
  return 1;
}
