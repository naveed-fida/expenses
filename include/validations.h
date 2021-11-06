#ifndef VALIDATIONS_HEADER
#define VALIDATIONS_HEADER

#include "types.h"

bool isValidCommand(char *cmd);
bool isValidOption(char *opt);
bool isATimeOption(char *opt);
bool isValidValue(char *opt, char *value);
bool isRedundantOption(struct arguments *argStruct, char *opt);

#endif