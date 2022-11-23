#include <stdio.h>
#include <string.h>
#define LEN 500

void flag_t(char* s, int flags[]);
void read_file(int arg_qty, char* commands[], int last_flag_index, int flags[]);
int flag_setup_switcher(char* flag, int flag_setup_mas[], char* wrong_flag);
int gnu_string_flag_checker(char* flag, int flag_setup_mas[]);
void flag_check(int arg_qty, char* commands[], int* last_flag_index,
                int flag_setup_mas[]);
void only_cat();
