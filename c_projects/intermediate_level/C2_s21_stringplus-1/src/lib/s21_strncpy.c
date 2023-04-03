#include "../s21_string.h"
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *address = dest;
  for (s21_size_t i = 0; i < n; i++) {
    *dest++ = *src++;
  }
  return address;
}
