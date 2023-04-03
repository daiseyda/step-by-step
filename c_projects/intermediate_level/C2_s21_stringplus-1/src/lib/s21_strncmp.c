#include "../s21_string.h"

// Compares at most the first n bytes of str1 and str2

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int ret = 0;
  for (; n && *str1 && *str1 == *str2; str1++, str2++, n--) {
  }
  if (n != 0) {
    ret = *str1 - *str2;
  }
  return ret;
}
