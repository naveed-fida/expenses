#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "types.h"
#include "common.h"
#include "exit_functions.h"

bool file_exists(char *path)
{
    return access(path, F_OK) == 0;
}

void format_and_print_row(char *line)
{
    char category[MAX_CAT_LEN + 5], tag[MAX_TAG_LEN + 5], date_string[18];
    float expense_amount;
    struct tm *time_struct;
    time_t timestamp;

    sscanf(line, "%li%f%s%s", &timestamp, &expense_amount, category, tag);
    time_struct = localtime(&timestamp);
    strftime(date_string, (size_t) 30, "%a, %d/%m/%y", time_struct);
    printf("%s\t%.2f\t%s\t%s\n", date_string, expense_amount, category, tag);
}

void retrieve_list(struct arguments *arg_struct)
{
    char *expenses_data_path = getenv(EXPENSES_DATA_DIR);
    strcat(expenses_data_path, "/data");

    if (!file_exists(expenses_data_path))
        exit_no_data_file();

    printf("Date Created\tExpense Amount\tCategory\tTag\n");
    FILE *fp;
    if ((fp = fopen(expenses_data_path, "r")) == NULL)
        exit_cant_open_data_file();

    char *row           = (char *) malloc(MAX_TAG_LEN + MAX_CAT_LEN + 80);
    size_t size;

    while(getline(&row, &size, fp) != -1)
        format_and_print_row(row);

    free(row);
}

void parse_and_run_list(int count, char *arg_arr[])
{
    struct arguments arg_struct = init_argument_struct();
    arg_struct.command = "list";
    populate_arg_struct(&arg_struct, count, arg_arr);
    retrieve_list(&arg_struct);
}