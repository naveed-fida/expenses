#include "types.h"
#include "common.h"
#include "exit_functions.h"

struct arguments parse_add(int count, char *arg_arr[])
{
    struct arguments arg_struct = init_argument_struct();
    arg_struct.command = "add";

    populate_arg_struct(&arg_struct, count, arg_arr);

    if (arg_struct.expense == 0.0)
        exit_no_expense();

    return arg_struct;
}