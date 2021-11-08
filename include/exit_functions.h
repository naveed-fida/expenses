#ifndef EXIT_FUNCS_HEADER
#define EXIT_FUNCS_HEADER

void exit_invalid_command(char *cmd);
void exit_invalid_opt_expense(char *token);
void exit_invalid_value(char *opt, char *val);
void exit_redundant_option(char *opt);
void exit_no_expense();
void exit_invalid_time_options(char *cmd);
void exit_value_too_long(char *opt, int max_len);
void exit_no_value(char *opt);
void exit_cant_open_data_file();
void exit_env_variable_not_set();

#endif