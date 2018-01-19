typedef struct nodeInt {
  int trang;
  struct nodeInt* next;
} nodeInt;

nodeInt* initListInt(int trang);
void addListInt(nodeInt** root, int trang);
void printListInt(nodeInt *root);
