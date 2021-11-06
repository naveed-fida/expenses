#ifndef TYPES_HEADER
#define TYPES_HEADER

struct arguments {
    char *command;
    float expense;
    struct {
        int day;
        int month;
        int year;
        char *cat;
        char *tag;
    } options;
};

#endif