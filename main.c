#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "exit_functions.h"
#include "add.h"
#include "validations.h"
#include "types.h"

void display_help()
{
    printf("Here's how to use expenses: \n");
    exit(0);
}
/* -------------------------------------- */

struct arguments parse_args_and_run_command(int count, char *arg_arr[])
{
    char *command = *arg_arr;
    if (!is_valid_command(command)) 
        exit_invalid_command(command);
    struct arguments arg_struct;

    if (strcmp(command, "add") == 0)
        arg_struct = parse_add(count, arg_arr);
    
    // if (strcmp(command, "list") == 0)
    //     arg_struct = parseList(count, arg_arr);

    // if (strcmp(command, "cat") == 0)
    //     arg_struct = parseCat(count, arg_arr);
    
    // if (strcmp(command, "tag") == 0)
    //     arg_struct = parseTag(count, arg_arr);

    // if (strcmp(command, "total") == 0)
    //     arg_struct = parseTotal(count, arg_arr);
    
    return arg_struct;
}

int main(int argc, char *argv[]) {
    if (argc == 1) display_help();
    struct arguments arg_struct = parse_args_and_run_command(argc - 1, argv + 1);

    printf("Here are the values: \n");
    printf("command: %s\n", arg_struct.command);
    printf("expense %f: \n", arg_struct.expense);
    printf("time, day: %i\n", arg_struct.options.day);
    printf("time, month: %i\n", arg_struct.options.month);
    printf("time, year: %i\n", arg_struct.options.year);
    printf("category: %s\n", arg_struct.options.cat);
    printf("tag: %s\n", arg_struct.options.tag);
    return 0;
}