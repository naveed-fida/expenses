#include <stdlib.h>
#include <stdio.h>

void exit_invalid_command(char *cmd)
{
    fprintf(stderr, "Error: %s is not a valid command\n", cmd);
    exit(1);
}

void exit_invalid_opt_expense(char *token) {
    fprintf(
        stderr,
        "Error: Ivalid Syntax. "
        "%s is not an option or an invalid or redundant expense amount.\n",
        token
    );

    exit(1);
}

void exit_invalid_value(char *opt, char *val) {
    fprintf(stderr, "Error: `%s` is not a valid value for option `%s`\n", val, opt);
    exit(1);
}

void exit_redundant_option(char *opt) {
    fprintf(stderr, "Error: %s is a redundant option.\n", opt);
    exit(1);
}

void exit_no_expense() {
    fprintf(stderr, "Error: No expense amount given.\n");
    exit(1);
}