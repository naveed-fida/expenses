#ifndef EXIT_FUNCS_HEADER
#define EXIT_FUNCS_HEADER

void exit_invalid_command(char *cmd);
void exit_invalid_opt_expense(char *token);
void exit_invalid_value(char *opt, char *val);
void exit_redundant_option(char *opt);
void exit_no_expense();

#endif