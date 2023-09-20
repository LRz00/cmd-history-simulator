#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Historico.h"

int main(void) {
  int option;
  char cmd[10], dir[10];
  stack *p = initializingStack();
  printf("COMANDOS: \nls\nmkdr\ncd\nrmkdir\n!\n!!\n> "
         "\nEXIT\n\n");

  while (strcmp(cmd, "exit") != 0) {
    printf("$ ");
    scanf("%s", cmd);
    printf("\n");
    execute(cmd, p);
    stackup(cmd, p);
  }
};
