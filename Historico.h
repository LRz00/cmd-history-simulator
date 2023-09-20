typedef struct NO {
  char commands[10];
  struct NO *prox;

} NO;
typedef struct NO *stack;

stack *initializingStack();
void stackup(char *cmd, stack *p);
int unstack(stack *p);
void history_full(stack *p);
void last_command(stack *p, char *cmd);
void save_to_file(stack *p);
void execute(char *cmd, stack *p);
