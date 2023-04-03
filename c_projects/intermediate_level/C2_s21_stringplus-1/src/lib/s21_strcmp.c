#include "../s21_string.h"

// Compares the string pointed to, by str1 to the string pointed to by str2

int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return *str1 - *str2;
}
