#include "s21_cat.h"

int main(int argc, char* argv[]) {
  int last_flag_index = 1;
  int flag_setup_mas[6] = {0, 0, 0, 0, 0, 0};
  if (argc > 1) {
    flag_check(argc, argv, &last_flag_index, flag_setup_mas);
    if (last_flag_index == -1)
      fprintf(stderr, "zsh: command not found: %s\n", argv[1]);
    else if (last_flag_index > 0)
      read_file(argc, argv, last_flag_index, flag_setup_mas);
  } else if (argc == 1)
    only_cat();
  return 0;
}

void flag_t(char* s, int flags[]) {  // для отображения непечатных символов
  if (flags[5]) {
    if (*s >= 0 && *s <= 31 && *s != '\n' && *s != '\t' && *s != ' ') {
      *s += 64;
      printf("^");
    } else if (*s == 127) {
      *s = '?';
      printf("^");
    }
  }
  if (flags[4]) {
    if (*s == '\t') {
      *s = 'I';
      printf("^");
    }
  }
}

void read_file(int arg_qty, char* commands[], int last_flag_index,
               int flags[]) {  // читаем и выводим содержимое файлом согласно
                               // конфигурации флагов
  FILE* file_ptr;
  int is_it_first_empty_str = 0;
  char symbol, prev_symbol = '\0';
  for (int i = last_flag_index; i < arg_qty; i++) {
    file_ptr = fopen(commands[i], "r");
    if (!file_ptr)
      fprintf(stderr, "cat: %s: No such file or directory\n", commands[i]);
    else {
      int k = 1;  //для нумерации строк
      while ((symbol = fgetc(file_ptr)) != EOF) {
        if (!flags[3]) is_it_first_empty_str = 0;  //сжиматель строк
        if (flags[3]) {
          if (is_it_first_empty_str > 0) {
            while (prev_symbol == '\n' && symbol == '\n' && symbol != EOF)
              symbol = fgetc(file_ptr);
          }
        }
        if (flags[0] == 1) {  // нумерация непустых строк
          if ((prev_symbol == '\0' || prev_symbol == '\n') && symbol != '\n' &&
              symbol != '\0') {
            printf("%6d\t", k);
            k++;
          }
        }
        if (flags[2] == 1 && flags[0] == 0) {  // нумерация всех строк
          if ((prev_symbol == '\0' || prev_symbol == '\n') && symbol != EOF &&
              is_it_first_empty_str < 2) {
            printf("%6d\t", k);
            k++;
          }
        }
        if (flags[5] || flags[4])
          flag_t(&symbol, flags);  // отработка непечатных символов
        if (symbol == '\n' && symbol != '\0') {
          if (prev_symbol == '\n') is_it_first_empty_str++;
          if (flags[1] && flags[3] == 0) printf("$");
          if (flags[3]) {
            if (is_it_first_empty_str < 2) {
              if (flags[1]) printf("$");
              printf("%c", symbol);
            }
          } else
            printf("%c", symbol);
        } else if (symbol != EOF) {
          printf("%c", symbol);
          is_it_first_empty_str = 0;
        }
        prev_symbol = symbol;
      }
      fclose(file_ptr);
    }
  }
}

int flag_setup_switcher(char* flag, int flag_setup_mas[],
                        char* wrong_flag) {  // проверяем буквенные флаги
  int flag_was_recognized = 1;
  for (int i = 1; i < (int)strlen(flag); i++) {
    if (flag[i] == 'b')
      flag_setup_mas[0] = 1;
    else if (flag[i] == 'E')
      flag_setup_mas[1] = 1;
    else if (flag[i] == 'e') {
      flag_setup_mas[1] = 1;
      flag_setup_mas[5] = 1;
    } else if (flag[i] == 'n')
      flag_setup_mas[2] = 1;
    else if (flag[i] == 's')
      flag_setup_mas[3] = 1;
    else if (flag[i] == 'T')
      flag_setup_mas[4] = 1;
    else if (flag[i] == 't') {
      flag_setup_mas[4] = 1;
      flag_setup_mas[5] = 1;
    } else if (flag[i] == 'v')
      flag_setup_mas[5] = 1;
    else {
      *wrong_flag = flag[i];
      flag_was_recognized = 0;
      break;
    }
  }
  return (flag_was_recognized);
}

int gnu_string_flag_checker(
    char* flag, int flag_setup_mas[]) {  // проверяем строчные флаги GNU
  int flag_was_recognized = 0;
  if (strcmp(flag, "--number-nonblank") == 0) {
    flag_was_recognized++;
    flag_setup_mas[0] = 1;
  } else if (strcmp(flag, "--number") == 0) {
    flag_was_recognized++;
    flag_setup_mas[2] = 1;
  } else if (strcmp(flag, "--squeeze-blank") == 0) {
    flag_was_recognized++;
    flag_setup_mas[3] = 1;
  }
  return (flag_was_recognized);
}

void flag_check(int arg_qty, char* commands[], int* last_flag_index,
                int flag_setup_mas[]) {  // считываем флаги, проверяем их и
                                         // считаем индекс последнего флага
  char wrong_flag = '\0';
  for (int i = 1; i < arg_qty; i++) {
    if (commands[i][0] != '-') {
      break;
    } else {
      if (!gnu_string_flag_checker(commands[i], flag_setup_mas)) {
        if (!flag_setup_switcher(commands[i], flag_setup_mas, &wrong_flag)) {
          (*last_flag_index) = -2;
          fprintf(stderr, "cat: illegal option -- %c", wrong_flag);
          break;
        } else
          (*last_flag_index)++;
      } else
        (*last_flag_index)++;
    }
  }
}

void only_cat() {  // если не были введены аргументы, бесконечный ввод
  char str[LEN];
  while (fgets(str, LEN, stdin)) printf("%s", str);
}
