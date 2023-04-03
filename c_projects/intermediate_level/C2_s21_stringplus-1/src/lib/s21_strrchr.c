#include "../s21_string.h"

// Searches for the last occurrence of the character c (an unsigned char) in the
// string pointed to by the argument str.
char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  s21_size_t len = s21_strlen(str);
  s21_size_t n = 0;
  while (n <= len) {
    if (*str == c) result = (char *)str;
    str++;
    n++;
  }
  return result;
}
