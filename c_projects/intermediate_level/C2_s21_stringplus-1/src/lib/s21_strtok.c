#include "../s21_string.h"

// Breaks string str into a series of tokens separated by delim

int is_delim(char symb, const char *delim) {
  int ret = 0;
  while (*delim != '\0' && !ret) {
    if (symb == *delim) {
      ret = 1;
    } else {
      delim++;
    }
  }
  return ret;
}

char *s21_strtok(char *str, const char *delim) {
  static char *backup = 0;
  char *ret = "";

  if (!str) {
    str = backup;
  }
  if (!str) {
    ret = S21_NULL;
  } else {
    while (1) {
      if (is_delim(*str, delim)) {
        str++;
        continue;
      }
      if (*str == '\0') {
        ret = S21_NULL;
      }
      break;
    }
    if (ret != S21_NULL) {
      char *tok = str;
      while (1 && (ret != tok)) {
        if (*str == '\0') {
          backup = str;
          ret = tok;
        } else {
          if (is_delim(*str, delim)) {
            *str = '\0';
            backup = str + 1;
            ret = tok;
          } else {
            str++;
          }
        }
      }
    }
  }
  return ret;
}
