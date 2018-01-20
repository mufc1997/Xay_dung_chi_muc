#include "../header/readFile.h"

void readFile(nodeChar **root, nodeChar **check, char *tenfile, char *config) { //config tuy chon w, r
  FILE *file;
  int c, i = 0, line = 1;
  if((file = fopen(tenfile, config)) == NULL) {
    printf("Khong the mo file\n");
  } else {
    char *tungu = malloc(sizeof(char) * 30);
    while((c = fgetc(file)) != EOF) {
      if(isalpha(c)) {
        tungu[i++] = (char)tolower(c);
      } else {
        tungu[i] = (char)(0);
        if((int)strlen(tungu) >= 1) {
          if((*check) != NULL) {
            if(searchNodeChar(*check, tungu) == NULL) {
              addListChar(root, tungu, line);
            }
          } else {
            addListChar(root, tungu, line);

          }
          i = 0;
        }
      }
      if(c == '\n')
        line++;
    }
    free(tungu);
    fclose(file);
  }
}
