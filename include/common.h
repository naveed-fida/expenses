#ifndef COMMON_HEADER
#define COMMON_HEADER

#include "types.h"

void populate_arg_struct(struct arguments *arg_struct, int count, char *arg_arr[]);
struct arguments init_argument_struct();

#endif