#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/types.h"

static char *commands[] = { "add", "list", "cat", "tag", "total" };
static char *options[] = { "-d", "-m", "-y", "-c", "-t" };

bool is_valid_command(char *cmd) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (strcmp(cmd, commands[i]) == 0)
            return true;
    }

    return false;
}

bool is_valid_option(char *opt) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (strcmp(opt, options[i]) == 0)
            return true;
    }

    return false;
}

bool is_time_option(char *opt) 
{
    return (
        strcmp(opt, "-d") == 0 ||
        strcmp(opt, "-m") == 0 ||
        strcmp(opt, "-y") == 0
    );
}

bool is_valid_value(char *opt, char *value)
{
    // probably buggy. Will evaluate
    if (
        (is_time_option(opt) && atoi(value) != 0) ||
        (!is_time_option(opt) && atoi(value) == 0)
    ) return true;

    return false;
}

bool is_redundant_option(struct arguments *arg_struct, char *opt)
{
    return (
        is_time_option(opt) &&
        (
            arg_struct->options.day   != NULL ||
            arg_struct->options.month != NULL ||
            arg_struct->options.year  != NULL
        )
    )  ||
    (
        (strcmp(opt, "-t") == 0 && arg_struct->options.tag != NULL) ||
        (strcmp(opt, "-c") == 0 && arg_struct->options.tag != NULL)
    );
}