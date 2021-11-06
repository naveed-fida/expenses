#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/types.h"

static char *commands[] = { "add", "list", "cat", "tag", "total" };
static char *options[] = { "-d", "-m", "-y", "-c", "-t" };

bool isValidCommand(char *cmd) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (strcmp(cmd, commands[i]) == 0)
            return true;
    }

    return false;
}

bool isValidOption(char *opt) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (strcmp(opt, options[i]) == 0)
            return true;
    }

    return false;
}

bool isATimeOption(char *opt) 
{
    return (
        strcmp(opt, "-d") == 0 ||
        strcmp(opt, "-m") == 0 ||
        strcmp(opt, "-y") == 0
    );
}

bool isValidValue(char *opt, char *value)
{
    // probably buggy. Will evaluate
    if (
        (isATimeOption(opt) && atoi(value) != 0) ||
        (!isATimeOption(opt) && atoi(value) == 0)
    ) return true;

    return false;
}

bool isRedundantOption(struct arguments *argStruct, char *opt)
{
    return (
        isATimeOption(opt) &&
        (
            argStruct->options.day   != '\0' ||
            argStruct->options.month != '\0' ||
            argStruct->options.year  != '\0'
        )
    )  ||
    (
        (strcmp(opt, "-t") == 0 && argStruct->options.tag != '\0') ||
        (strcmp(opt, "-c") == 0 && argStruct->options.tag != '\0')
    );
}