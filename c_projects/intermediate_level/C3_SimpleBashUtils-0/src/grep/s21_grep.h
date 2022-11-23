#include <regex.h>
#include <stdio.h>
#include <string.h>
#define LEN 1000
regex_t regex;
char templates_from_files[LEN][255];

void magic_function(int flags[], char *str, char *s, int templates_qty,
                    int str_number, char *templates[]);
void error_print();
void endless_func();
void super_template_mas_creation(char *mas_1[], char *result_mas[],
                                 int *result_qty, int qty_1, int qty_2);
int templates_from_files_arhivator(char *files_names[], int files_qty);
void read_file(int flags[], char *files_names[], char *templates[],
               int files_qty, int templates_qty, int shift);
int flag_setup_switcher(char *flag, int flag_setup_mas[]);
void flag_check_and_files_recording(int *arg_qty, char *commands[],
                                    int flag_setup_mas[], char *files_names[],
                                    char *templates[], int *files_qty,
                                    int *templates_qty, int *shift,
                                    char *files_with_templates[],
                                    int *files_with_templates_qty);
