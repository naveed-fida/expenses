#include <stdlib.h>
#include <stdio.h>

void exitInvalidCommand(char *cmd)
{
    fprintf(stderr, "Error: %s is not a valid command\n", cmd);
    exit(1);
}

void exitInvalidOptExpense(char *token) {
    fprintf(
        stderr,
        "Error: Ivalid Syntax. "
        "%s is not an option or an invalid or redundant expense amount.\n",
        token
    );

    exit(1);
}

void exitInvalidValue(char *opt, char *val) {
    fprintf(stderr, "Error: `%s` is not a valid value for option `%s`\n", val, opt);
    exit(1);
}

void exitRedundantOption(char *opt) {
    fprintf(stderr, "Error: %s is a redundant option.\n", opt);
    exit(1);
}

void exitNoExpense() {
    fprintf(stderr, "Error: No expense amount given.\n");
    exit(1);
}