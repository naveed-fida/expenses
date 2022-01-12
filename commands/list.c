#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "types.h"
#include "common.h"
#include "exit_functions.h"

#define _GNU_SOURCE
#include <string.h>

bool file_exists(char *path)
{
    return access(path, F_OK) == 0;
}

bool cat_matches(char *row_cat, char *opt_cat)
{
    return opt_cat == NULL || strcasestr(row_cat, opt_cat) != NULL;
}

bool tag_matches(char *row_tag, char *opt_tag)
{
    return opt_tag == NULL || strcasestr(row_tag, opt_tag) != NULL;
}

int days_in_month(int month)
{

}

int secs_in_month(int month)
{
    
}

int cutoff_time_stamp(time_t ts, char *time_unit, int count)
{
    time_t now = time(NULL);
    struct tm tm_now = localtime(&now);
    int secs_today = tm_now.tm_sec + (tm_now.tm_min * 60) + (tm_now.tm_hour * 60 * 60);
    int secs_rest_days;
    int total_secs;

    if (strcmp(time_unit, "days" == 0)) {
        secs_rest_days = (count - 1) * 24 * 60 * 60;
        total_secs = secs_today + secs_rest_days;
        return now - total_secs;
    }
        
    if (strcmp(time_unit, "months" == 0))
}

bool within_cutoff_time(struct tm *time_created, time_t timestamp)
{
    int days = arg_struct->options.day;
    int months = arg_struct->options.month;
    int years = arg_struct->options.year;

    if (!days && !months && !years)
        return true;

    if (days)
        return timestamp >= cutoff_time_stamp(timestamp, "days", days);
    if (months)
        return timestamp >= cutoff_time_stamp(timestamp, "months", months);
    if (years)
        return timestamp >= cutoff_time_stamp(timestamp, "years", years);
}

void format_and_print_row(char *line, struct arguments *arg_struct)
{
    char category[MAX_CAT_LEN + 5], tag[MAX_TAG_LEN + 5], date_string[18];
    float expense_amount;
    struct tm *time_struct;
    time_t timestamp;

    sscanf(line, "%li %f \"%[^\"]\" \"%[^\"]\"", &timestamp, &expense_amount, category, tag);
    time_struct = localtime(&timestamp);
    strftime(date_string, (size_t) 30, "%a, %d/%m/%y", time_struct);

    if (
        !cat_matches(category, arg_struct->options.cat) ||
        !tag_matches(tag, arg_struct->options.tag)
    )
        return;
    
    printf("%-25s%-15.2f%-30s%-30s\n", date_string, expense_amount, category, tag);
}

void retrieve_list(struct arguments *arg_struct)
{
    char *expenses_data_path = getenv(EXPENSES_DATA_DIR);
    strcat(expenses_data_path, "/data");

    if (!file_exists(expenses_data_path))
        exit_no_data_file();

    FILE *fp;
    if ((fp = fopen(expenses_data_path, "r")) == NULL)
        exit_cant_open_data_file();

    char *row           = (char *) malloc(MAX_TAG_LEN + MAX_CAT_LEN + 80);
    size_t size;

    printf("%-25s%-15s%-30s%-30s\n", "Date", "Amount", "Category", "Tag");
    while(getline(&row, &size, fp) != -1)
        format_and_print_row(row, arg_struct);

    free(row);
}

void parse_and_run_list(int count, char *arg_arr[])
{
    struct arguments arg_struct = init_argument_struct();
    arg_struct.command = "list";
    populate_arg_struct(&arg_struct, count, arg_arr);
    retrieve_list(&arg_struct);
}