#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"
#include "validations.h"
#include "exit_functions.h"

#define OPTION "option"
#define VALUE "value"

struct arguments init_argument_struct()
{
    struct arguments s = {
        .command = (char *) NULL,
        .expense = 0,
        .options = {
            .day = 0,
            .month = 0,
            .year = 0,
            .cat = (char *) NULL,
            .tag = (char *) NULL
        }
    };

    return s;
}

void save_option(struct arguments *arg_struct, char *opt, char *val)
{
    if (strcmp(opt, "-d") == 0)
        arg_struct->options.day = atoi(val);
    else if (strcmp(opt, "-m") == 0)
        arg_struct->options.month = atoi(val);
    else if (strcmp(opt, "-y") == 0)
        arg_struct->options.year = atoi(val);
    else if (strcmp(opt, "-c") == 0)
        arg_struct->options.cat = val;
    else if (strcmp(opt, "-t") == 0)
        arg_struct->options.tag = val;
}

void populate_arg_struct(struct arguments *arg_struct, int count, char *arg_arr[]) 
{
    char *looking = OPTION;
    char *option;

    while (--count > 0)
    {
        char *next = *++arg_arr;
        if (looking == OPTION)
        {
            if (is_valid_option(next)) {
                looking = VALUE;
                option = next;
            } else if (atof(next) != 0.0 && arg_struct->expense == 0) {
                arg_struct->expense = atof(next);
            } else
                exit_invalid_opt_expense(next);
        } else if (looking == VALUE) {
            if (!is_valid_value(option, next))
                exit_invalid_value(option, next);
            
            if (is_redundant_option(arg_struct, option))
                exit_redundant_option(option);

            looking = OPTION;
            save_option(arg_struct, option, next);
        }
    }
}