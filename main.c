#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "exit_functions.h"
#include "add.h"
#include "validations.h"
#include "types.h"

void displayHelp()
{
    printf("Here's how to use expenses: \n");
    exit(0);
}
/* -------------------------------------- */

struct arguments parseArgs(int count, char *argArr[])
{
    char *command = *argArr;
    if (!isValidCommand(command)) 
        exitInvalidCommand(command);
    struct arguments argStruct;

    if (strcmp(command, "add") == 0)
        argStruct = parseAdd(count, argArr);
    
    // if (strcmp(command, "list") == 0)
    //     argStruct = parseList(count, argArr);

    // if (strcmp(command, "cat") == 0)
    //     argStruct = parseCat(count, argArr);
    
    // if (strcmp(command, "tag") == 0)
    //     argStruct = parseTag(count, argArr);

    // if (strcmp(command, "total") == 0)
    //     argStruct = parseTotal(count, argArr);
    
    return argStruct;
}

int main(int argc, char *argv[]) {
    if (argc == 1) displayHelp();
    struct arguments argStruct = parseArgs(argc - 1, argv + 1);

    printf("Here are the values: \n");
    printf("command: %s\n", argStruct.command);
    printf("expense %f: \n", argStruct.expense);
    printf("time, day: %i\n", argStruct.options.day);
    printf("time, month: %i\n", argStruct.options.month);
    printf("time, year: %i\n", argStruct.options.year);
    printf("category: %s\n", argStruct.options.cat);
    printf("tag: %s\n", argStruct.options.tag);
    return 0;
}