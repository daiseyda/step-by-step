#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result;
  const char *p;
  for (result = 0; *str1; str1++, result++) {
    for (p = str2; *p && *p != *str1; p++)
      ;
    if (!*p) break;
  }
  return result;
}
