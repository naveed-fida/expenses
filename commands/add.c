#include "types.h"
#include "common.h"
#include "exit_functions.h"

struct arguments parseAdd(int count, char *argArr[])
{
    struct arguments argStruct = initArgumentsStruct();
    argStruct.command = "add";

    populateArgStruct(&argStruct, count, argArr);

    if (argStruct.expense == 0.0)
        exitNoExpense();

    return argStruct;
}