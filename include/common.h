#ifndef COMMON_HEADER
#define COMMON_HEADER

#include "types.h"

#define MAX_CAT_LEN 50
#define MAX_TAG_LEN 50
#define MAX_OUTPUT_BUFFER_LEN 2000
#define EXPENSES_DATA_DIR "EXPENSES_DATA_DIR"

void populate_arg_struct(struct arguments *arg_struct, int count, char *arg_arr[]);
struct arguments init_argument_struct();
void guard_cat_tag_length(struct arguments *arg_struct, int max_cat, int max_tag);

#endif