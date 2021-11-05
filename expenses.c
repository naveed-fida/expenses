#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define OPTION "option"
#define VALUE "value"

void exit(int);
int atoi(const char *);

static char *commands[] = { "add", "list", "cat", "tag", "total" };
static char *options[] = { "-d", "-m", "-y", "-c", "-t" };

struct arguments {
    char *command;
    struct {
        int day;
        int month;
        int year;
        char *cat;
        char *tag;
    } options;
};

bool isValidCommand(char *cmd) {
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

struct arguments initArgumentsStruct()
{
    struct arguments s = {
        .command = (char *) NULL,
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

void displayHelp()
{
    printf("Here's how to use expenses: \n");
    exit(0);
}

void validateCommand(char *cmd)
{
    if (!isValidCommand(cmd)) 
    {
        fprintf(stderr, "Error: %s is not a valid command\n", cmd);
        exit(1);
    }
}

void validateOption(char *opt)
{
    if (!isValidOption(opt)) 
    {
        fprintf(
            stderr,
            "Error: %s is not a valid option\n"
            "Valid Options: -d, -m, -y, -c, -t\n",
            opt
        );
        exit(1);
    }    
}

void validateValue(char *opt, char *val)
{
    if (!isValidValue(opt, val))
    {
        fprintf(stderr, "Error: `%s` is not a valid value for option `%s`\n", val, opt);
        exit(1);
    }
}

void validateRedundantOptions(struct arguments argStruct, char *opt) {
    if (
        (isATimeOption(opt)
        && (argStruct.options.day || argStruct.options.month || argStruct.options.year)) ||
    ) 
}

struct arguments parseArgs(int count, char *argArr[])
{
    struct arguments argStruct = initArgumentsStruct();
    if (count == 0) displayHelp();
    validateCommand(argArr[0]);
    argStruct.command = *argArr;

    char *looking = OPTION;
    char *option;
    char *value; // not needed

    while (--count > 0)
    {
        char *next = *++argArr;
        if (looking == OPTION)
        {
            validateOption(next);
            validateRedundantOptions(argStruct, next);
            if (count < 2) fprintf(stderr, "Error: No value for %s\n", next);
            option = next;
            looking = VALUE;
        } else if (looking == VALUE)
        {
            validateValue(option, next);
            looking = OPTION;
            printf("option: %s, value: %s\n", option, next);
        }
    }
    
    return argStruct;
}

int main(int argc, char *argv[]) {
    struct arguments argStruct = parseArgs(argc - 1, argv + 1);

    return 0;
}