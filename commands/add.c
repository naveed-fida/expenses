#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "common.h"
#include "exit_functions.h"

void guard_expense_amount(struct arguments *arg_struct)
{
    if (arg_struct->expense == 0.0)
        exit_no_expense();
}

void guard_no_time_option(struct arguments *arg_struct)
{
    if (
        !(arg_struct->options.day   == 0 &&
        arg_struct->options.month == 0 &&
        arg_struct->options.year  == 0)
    )
        exit_invalid_time_options(arg_struct->command);
}

char *run_add(struct arguments *arg_struct) {
    char *expenses_data_path = getenv(EXPENSES_DATA_DIR);
    strcat(expenses_data_path, "/data");

    FILE *fp;
    if ((fp = fopen(expenses_data_path, "a+")) == NULL)
        exit_cant_open_data_file();

    /*Row format: time\tamount\tcategroy\ttag */
    fprintf(
        fp,
        "%li\t%.2f\t%s\t%s\n",
        time(NULL),
        arg_struct->expense,
        arg_struct->options.cat == '\0' ? "null" : arg_struct->options.cat,
        arg_struct->options.tag == '\0' ? "null" : arg_struct->options.tag
    );

    fclose(fp);

    return "expense added!\n";
}

char *parse_and_run_add(int count, char *arg_arr[])
{
    struct arguments arg_struct = init_argument_struct();
    arg_struct.command = "add";
    populate_arg_struct(&arg_struct, count, arg_arr);
    guard_expense_amount(&arg_struct);
    guard_no_time_option(&arg_struct);
    guard_cat_tag_length(&arg_struct, MAX_CAT_LEN, MAX_TAG_LEN);

    return run_add(&arg_struct);
}