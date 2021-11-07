#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "common.h"
#include "exit_functions.h"

void validate_expense_amount(struct arguments *arg_struct)
{
    if (arg_struct->expense == 0.0)
        exit_no_expense();
}

void validate_no_time_option(struct arguments *arg_struct)
{
    if (
        !(arg_struct->options.day   == 0 &&
        arg_struct->options.month == 0 &&
        arg_struct->options.year  == 0)
    )
        exit_invalid_time_options(arg_struct->command);
}

void validate_cat_tag_length(struct arguments *arg_struct)
{
    char *cat = arg_struct->options.cat;
    char *tag = arg_struct->options.tag;
    if (cat != '\0' && strlen(cat) > 50)
        exit_value_too_long("category", MAX_CAT_LEN);
    else if (tag != '\0' && strlen(tag) > 50)
        exit_value_too_long("tag", MAX_TAG_LEN);
}

char *run_add(struct arguments *arg_struct) {
    char *output_buffer = (char *) malloc(sizeof(char) * MAX_OUTPUT_BUFFER_LEN);
    char str[80];

    // FILE *fp = fopen("~/")

    sprintf(str, "command: %s\n", arg_struct->command);
    strcat(output_buffer, str);
    sprintf(str, "expense: %.2f\n", arg_struct->expense);
    strcat(output_buffer, str);
    sprintf(str, "time, day: %i\n", arg_struct->options.day);
    strcat(output_buffer, str); 
    sprintf(str, "time, month: %i\n", arg_struct->options.month);
    strcat(output_buffer, str);
    sprintf(str, "time, year: %i\n", arg_struct->options.year);
    strcat(output_buffer, str);
    sprintf(str, "category: %s\n", arg_struct->options.cat);
    strcat(output_buffer, str);
    sprintf(str, "tag: %s\n", arg_struct->options.tag);
    strcat(output_buffer, str);

    return output_buffer;
}

char *parse_and_run_add(int count, char *arg_arr[])
{
    struct arguments arg_struct = init_argument_struct();
    arg_struct.command = "add";
    populate_arg_struct(&arg_struct, count, arg_arr);
    validate_expense_amount(&arg_struct);
    validate_no_time_option(&arg_struct);
    validate_cat_tag_length(&arg_struct);

    return run_add(&arg_struct);
}