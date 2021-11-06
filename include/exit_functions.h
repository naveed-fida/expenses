#ifndef EXIT_FUNCS_HEADER
#define EXIT_FUNCS_HEADER

void exitInvalidCommand(char *cmd);
void exitInvalidOptExpense(char *token);
void exitInvalidValue(char *opt, char *val);
void exitRedundantOption(char *opt);
void exitNoExpense();

#endif