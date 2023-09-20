#include "Historico.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


stack *initializingStack() {
  stack *p = (stack *)malloc(sizeof(malloc));
  if (p != NULL) {
    *p = NULL;
  }
  return p;
}

void stackup(char *cmd, stack *p) {
  NO *ptr = (NO *)malloc(sizeof(NO));
  if (ptr == NULL) {
    printf("ERRO!");
    return;
  }

  strcpy(ptr->commands, cmd);
  ptr->prox = (*p);
  *p = ptr;
}

int unstack(stack *p) {
  if (p == NULL)
    return 0;
  if ((*p) == NULL)
    return 0;
  NO *ptr = *p;
  *p = ptr->prox;
  free(ptr);
  return 1;
}

void history_full(stack *p) {
  if (p == NULL)
    printf("ERROR");
  NO *ptr = *p;
  while (ptr != NULL) {
    printf("%s\n", ptr->commands);
    ptr = ptr->prox;
  }
}; // !!

void last_command(stack *p, char *cmd) {
  if (p == NULL)
    printf("ERRO");
  if ((*p) == NULL)
    printf("ERRO");
  strcpy(cmd, (*p)->commands);
}; // !

void save_to_file(stack *p) {
  char nome_arq[25];
  printf("history > ");
  scanf("%s", nome_arq);

  FILE *arq = fopen(nome_arq, "w");

  if (arq == NULL)
    printf("ERRO");

  NO *ptr = *p;

  while (ptr != NULL) {
    fprintf(arq, "%s", ptr->commands);
    ptr = ptr->prox;
  }
  printf("HISTORICO SALVO PARA ARUIVO\n");
  fclose(arq);
} // <

void execute(char *cmd, stack *p) {
  char files[3][10];
  char dir_atual[10];
  char dir[4][10];
  int dirq = 0;

  strcpy(files[0], "file1");
  strcpy(files[1], "file2");
  strcpy(files[2], "file3");

  if (strcmp(cmd, "ls") == 0) {
    for (int i = 0; i < 3; i++) {
      printf("%s ", files[i]);
    }
    printf("\n");
  }

  if (strcmp(cmd, "mkdr") == 0) {
    printf(": ");
    scanf("%s", dir[dirq]);
  }
  if (strcmp(cmd, "cd") == 0) {
    printf(": ");
    scanf("%s", dir_atual);
    printf("\nDiretorio atual: %s\n", dir_atual);
  }
  if (strcmp(cmd, "rmkdr") == 0) {
    printf(": ");
    scanf("%s", dir[dirq]);
  }
  if (strcmp(cmd, "!") == 0) {
    last_command(p, cmd);
    printf("\n%s", cmd);
  }
  if (strcmp(cmd, "!!") == 0) {
    history_full(p);
  }
  if (strcmp(cmd, ">") == 0) {
    save_to_file(p);
  }
} // executa o comando digitado
