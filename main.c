#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "exit_functions.h"
#include "add.h"
#include "validations.h"
#include "common.h"
#include "types.h"

void guard_environment_var_set() {
    if (getenv(EXPENSES_DATA_DIR) == '\0')
        exit_env_variable_not_set();
}

void display_help()
{
    printf("Here's how to use expenses: \n");
    exit(0);
}
/* -------------------------------------- */

char *parse_args_and_run_command(int count, char *arg_arr[])
{
    char *command = *arg_arr;
    if (!is_valid_command(command)) 
        exit_invalid_command(command);
    
    char *output_str;

    if (strcmp(command, "add") == 0)
        output_str = parse_and_run_add(count, arg_arr);
    
    // if (strcmp(command, "list") == 0)
    //     output_str = parseList(count, arg_arr);

    // if (strcmp(command, "cat") == 0)
    //     output_str = parseCat(count, arg_arr);
    
    // if (strcmp(command, "tag") == 0)
    //     output_str = parseTag(count, arg_arr);

    // if (strcmp(command, "total") == 0)
    //     output_str = parseTotal(count, arg_arr);
    
    return output_str;
}

int main(int argc, char *argv[]) {
    guard_environment_var_set();
    if (argc == 1) display_help();
    char *output = parse_args_and_run_command(argc - 1, argv + 1);

    printf("%s", output);
    return 0;
}