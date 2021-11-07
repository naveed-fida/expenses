#ifndef VALIDATIONS_HEADER
#define VALIDATIONS_HEADER

#include "types.h"

bool is_valid_command(char *cmd);
bool is_valid_option(char *opt);
bool is_time_option(char *opt);
bool is_valid_value(char *opt, char *value);
bool is_redundant_option(struct arguments *arg_struct, char *opt);

#endif