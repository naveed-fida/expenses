#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"
#include "validations.h"
#include "exit_functions.h"

#define OPTION "option"
#define VALUE "value"

struct arguments initArgumentsStruct()
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

void saveOption(struct arguments *argStruct, char *opt, char *val)
{
    if (strcmp(opt, "-d") == 0)
        argStruct->options.day = atoi(val);
    else if (strcmp(opt, "-m") == 0)
        argStruct->options.month = atoi(val);
    else if (strcmp(opt, "-y") == 0)
        argStruct->options.year = atoi(val);
    else if (strcmp(opt, "-c") == 0)
        argStruct->options.cat = val;
    else if (strcmp(opt, "-t") == 0)
        argStruct->options.tag = val;
}

void populateArgStruct(struct arguments *argStruct, int count, char *argArr[]) 
{
    char *looking = OPTION;
    char *option;

    while (--count > 0)
    {
        char *next = *++argArr;
        if (looking == OPTION)
        {
            if (isValidOption(next)) {
                looking = VALUE;
                option = next;
            } else if (atof(next) != 0.0 && argStruct->expense == 0) {
                argStruct->expense = atof(next);
            } else
                exitInvalidOptExpense(next);
        } else if (looking == VALUE) {
            if (!isValidValue(option, next))
                exitInvalidValue(option, next);
            
            if (isRedundantOption(argStruct, option))
                exitRedundantOption(option);

            looking = OPTION;
            saveOption(argStruct, option, next);
        }
    }
}