#include "s21_grep.h"

int main(int argc, char *argv[]) {
  int files_qty = 0, templates_qty = 0, shift = 0, files_with_templates_qty = 0,
      templates_from_files_qty = 0, super_template_mas_qty = 0;
  int flag_setup_mas[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char files_names[argc][255], templates[argc][255],
      files_with_templates[argc][255], super_template_mas[argc + LEN][255];
  if (argc > 1) {
    flag_check_and_files_recording(
        &argc, argv, flag_setup_mas, (char **)files_names, (char **)templates,
        &files_qty, &templates_qty, &shift, (char **)files_with_templates,
        &files_with_templates_qty);
    if (argc == -1) error_print();
    /* else if (templates_qty == 0 || files_qty == 0)
        endless_func(); */
    else {
      if (files_with_templates_qty)
        templates_from_files_qty = templates_from_files_arhivator(
            (char **)files_with_templates, files_with_templates_qty);
      super_template_mas_creation(
          (char **)templates, (char **)super_template_mas,
          &super_template_mas_qty, templates_qty, templates_from_files_qty);
      read_file(flag_setup_mas, (char **)files_names,
                (char **)super_template_mas, files_qty, super_template_mas_qty,
                shift);
    }
  } else
    error_print();
  return 0;
}

void magic_function(int flags[], char *str, char *s, int templates_qty,
                    int str_number, char *templates[]) {
  int reg_check = 0;
  if (!flags[3] && !flags[4]) {
    if (!flags[6]) printf("%s", s);
    if (flags[5]) printf("%d:", str_number);
    if (flags[9]) {
      regmatch_t pmatch[1];
      char *l = str;
      for (int i = 0; i < templates_qty; i++) {
        if (!flags[1])  // учитываем регистр
          reg_check = regcomp(&regex, templates[i],
                              REG_EXTENDED);  // походу можно за один цикл
                                              // запихнуть сюда все темплеты
        if (flags[1])  // игнорируем регистр
          reg_check = regcomp(&regex, templates[i], REG_EXTENDED | REG_ICASE);
        if (!reg_check && !flags[2]) {
          while (regexec(&regex, l, 1, pmatch, 0) != REG_NOMATCH) {
            for (int k = pmatch[0].rm_so; k < pmatch[0].rm_eo; k++)
              printf("%c", l[k]);
            printf("\n");
            l += pmatch[0].rm_eo;
          }
          regfree(&regex);
        }
        if (!reg_check && flags[2]) {
          printf("%s\n", str);
          break;
        }
      }
    }
    if (!flags[9]) printf("%s\n", str);
  }
}

void error_print() {  // стандартное сообщение об ошибке с инструкцией
  fprintf(stderr,
          "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] "
          "[-C[num]]\n\t[-e pattern] [-f file] [--binary-files=value] "
          "[--color=when]\n\t[--context[=num]] [--directories=action] "
          "[--label] [--line-buffered]\n\t[--null] [pattern] [file ...]\n");
}

void endless_func() {  // введен только один аргумент
  char str[LEN];
  while (fgets(str, LEN, stdin))
    ;
}

void super_template_mas_creation(char *mas_1[], char *result_mas[],
                                 int *result_qty, int qty_1, int qty_2) {
  int i = 0;
  for (int j = 0; j < qty_1; i++, j++) result_mas[i] = mas_1[j];
  for (int j = 0; j < qty_2; i++, j++) result_mas[i] = templates_from_files[j];
  *result_qty = qty_1 + qty_2;
}

int templates_from_files_arhivator(char *files_names[], int files_qty) {
  FILE *file_ptr;
  char str[LEN];
  int templates_qty = 0;
  for (int i = 0; i < files_qty; i++) {
    file_ptr = fopen(files_names[i], "r");
    if (!file_ptr) {
      fprintf(stderr, "grep: %s: No such file or directory\n", files_names[i]);
      templates_qty = -1;
      break;
    }
    fclose(file_ptr);
  }
  if (templates_qty != -1) {
    for (int i = 0; i < files_qty; i++) {
      file_ptr = fopen(files_names[i], "r");
      while (fgets(str, LEN, file_ptr)) {
        strcpy(templates_from_files[templates_qty], str);
        int l = strlen(templates_from_files[templates_qty]) - 1;
        if (templates_from_files[templates_qty][l] == '\n')
          templates_from_files[templates_qty][l] = '\0';
        templates_qty++;
      }
      fclose(file_ptr);
    }
  }
  return (templates_qty);
}

void read_file(int flags[], char *files_names[], char *templates[],
               int files_qty, int templates_qty, int shift) {
  FILE *file_ptr;
  char str[LEN];
  int reg_check = 0;
  for (int i = 0 + shift; i < files_qty; i++) {
    file_ptr = fopen(files_names[i], "r");
    if (!file_ptr) {
      if (!flags[7])
        fprintf(stderr, "grep: %s: No such file or directory\n",
                files_names[i]);
    } else {
      int qty = 0, str_number = 0;
      char s[LEN] = "";
      if (files_qty - shift > 1) {
        int l_1 = strlen(files_names[i]);
        strcpy(s, files_names[i]);
        s[l_1] = ':';
      }
      while (fgets(str, LEN, file_ptr)) {
        int counter = 0;
        int l_2 = strlen(str) - 1;
        if (str[l_2] == '\n') str[l_2] = '\0';
        str_number++;
        for (int i = 0; i < templates_qty; i++) {
          if (!flags[1])  // учитываем регистр
            reg_check = regcomp(&regex, templates[i],
                                REG_EXTENDED);  // походу можно за один цикл
                                                // запихнуть сюда все темплеты
          if (flags[1])  // игнорируем регистр
            reg_check = regcomp(&regex, templates[i], REG_EXTENDED | REG_ICASE);
          if (!reg_check) {
            reg_check = regexec(&regex, str, 0, NULL, 0);
            regfree(&regex);
            if (!reg_check) {
              break;
            } else
              counter++;
          } else
            regfree(&regex);
        }
        if (!reg_check && !flags[2]) {  // вывод без приколов (нет инвертации)
          qty++;
          magic_function(flags, str, s, templates_qty, str_number,
                         (char **)templates);
        }
        if (reg_check && flags[2]) {  // инвертирует смысл поиска
          qty++;
          magic_function(flags, str, s, templates_qty, str_number,
                         (char **)templates);
        }
      }
      if (flags[3]) {
        if (flags[4] && qty) qty = 1;
        if (files_qty - shift > 1 && !flags[6])
          printf("%s:%d\n", files_names[i], qty);
        else
          printf("%d\n", qty);
      }
      if (flags[4] && qty) printf("%s\n", files_names[i]);
      fclose(file_ptr);
    }
  }
}

int flag_setup_switcher(char *flag,
                        int flag_setup_mas[]) {  // переключатель флагов
  int error_or_flag_e_or_f = 0;
  for (int i = 1; i < (int)strlen(flag); i++) {
    if (flag[i] == 'e') {
      error_or_flag_e_or_f = 1;
      flag_setup_mas[0] = 1;
    } else if (flag[i] == 'i')
      flag_setup_mas[1] = 1;
    else if (flag[i] == 'v')
      flag_setup_mas[2] = 1;
    else if (flag[i] == 'c')
      flag_setup_mas[3] = 1;
    else if (flag[i] == 'l')
      flag_setup_mas[4] = 1;
    else if (flag[i] == 'n')
      flag_setup_mas[5] = 1;
    else if (flag[i] == 'h')
      flag_setup_mas[6] = 1;
    else if (flag[i] == 's')
      flag_setup_mas[7] = 1;
    else if (flag[i] == 'f') {
      error_or_flag_e_or_f = 2;
      flag_setup_mas[8] = 1;
    } else if (flag[i] == 'o')
      flag_setup_mas[9] = 1;
    else {
      fprintf(stderr, "grep: invalid option -- %c\n", flag[i]);
      error_or_flag_e_or_f = -1;
      break;
    }
  }
  return (error_or_flag_e_or_f);
}

void flag_check_and_files_recording(
    int *arg_qty, char *commands[], int flag_setup_mas[], char *files_names[],
    char *templates[], int *files_qty, int *templates_qty, int *shift,
    char *files_with_templates[],
    int *files_with_templates_qty) {  // проверка флагов, их запись, если все
                                      // ок, то и запись названий файлов
  int i = 1;
  while (i < *arg_qty) {
    int error_or_flag_e_or_f = 0;
    if (commands[i][0] == '-') {
      error_or_flag_e_or_f = flag_setup_switcher(commands[i], flag_setup_mas);
      if (error_or_flag_e_or_f == -1) {
        (*arg_qty) = -1;
        break;
      }
    }
    if (error_or_flag_e_or_f == 1) {
      i++;
      templates[*templates_qty] = commands[i];
      (*templates_qty)++;
    }
    if (error_or_flag_e_or_f == 2) {
      i++;
      files_with_templates[*files_with_templates_qty] = commands[i];
      (*files_with_templates_qty)++;
    }
    if (error_or_flag_e_or_f == 0 && commands[i][0] != '-') {
      files_names[*files_qty] = commands[i];
      (*files_qty)++;
    }
    i++;
  }
  if (*templates_qty == 0 && *files_qty > 1) {
    *templates_qty = 1;
    templates[0] = files_names[0];
    *shift = 1;
  }
}
