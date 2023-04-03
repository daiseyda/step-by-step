#include "../s21_string.h"

// Searches for the first occurrence of the character c (an unsigned char)
// in the string pointed to, by the argument str.
char *s21_strchr(const char *str, int c) {
  char *result = (char *)str;
  int exit = 0;
  do {
    if (result != S21_NULL) {
      if (*result == (char)c) {
        exit = 1;
      } else if (*result == '\0') {
        result = S21_NULL;
        exit = 1;
      } else {
        result++;
      }
    }
  } while (exit == 0);
  return result;
}
