#ifndef COMMON_HEADER
#define COMMON_HEADER

#include "types.h"

void saveOption(struct arguments *argStruct, char *opt, char *val);
void populateArgStruct(struct arguments *argStruct, int count, char *argArr[]);
struct arguments initArgumentsStruct();

#endif