#include <stdlib.h>
#include <stdio.h>

void exit_invalid_command(char *cmd)
{
    fprintf(stderr, "Error: %s is not a valid command\n", cmd);
    exit(1);
}

void exit_invalid_opt_expense(char *token)
{
    fprintf(
        stderr,
        "Error: Ivalid Syntax. "
        "%s is not an option or an invalid or redundant expense amount.\n",
        token
    );

    exit(1);
}

void exit_invalid_value(char *opt, char *val)
{
    fprintf(stderr, "Error: `%s` is not a valid value for option `%s`\n", val, opt);
    exit(1);
}

void exit_redundant_option(char *opt)
{
    fprintf(stderr, "Error: %s is a redundant option.\n", opt);
    exit(1);
}

void exit_no_expense()
{
    fprintf(stderr, "Error: No expense amount given.\n");
    exit(1);
}

void exit_invalid_time_options(char *cmd)
{
    fprintf(stderr, "Error: Can't use time options (-d, -m, -y) with `%s`\n", cmd);
    exit(1);
}

void exit_value_too_long(char *opt, int max_len)
{
    fprintf(
        stderr,
        "Error: Value too long. "
        "A %s's length, can't be longer than %i\n",
        opt,
        max_len
    );
    exit(1);
}

void exit_no_value(char *opt)
{
    fprintf(stderr, "Error: No value provided for `%s`\n", opt);
    exit(1);
}