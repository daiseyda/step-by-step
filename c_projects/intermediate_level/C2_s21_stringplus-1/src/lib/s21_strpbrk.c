#include "../s21_string.h"

// Finds the first character in the string str1 that matches any character
// specified in str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  char *str2_copy;
  while (*str1 != '\0' && result == S21_NULL) {
    str2_copy = (char *)str2;
    while (*str2_copy != '\0' && result == S21_NULL) {
      if (*str1 == *str2_copy) result = (char *)(str1);
      str2_copy++;
    }
    str1++;
  }
  return result;
}
