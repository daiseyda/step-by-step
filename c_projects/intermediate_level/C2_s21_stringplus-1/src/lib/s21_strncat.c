#include "../s21_string.h"

// Appends the string pointed to, by src to the end of the string pointed to, by
// dest up to n characters long

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  unsigned int len1 = s21_strlen(dest);
  unsigned int len2 = s21_strlen(src);
  if (len2 < n) {
    s21_strcpy(&dest[len1], src);
  } else {
    s21_strncpy(&dest[len1], src, n);
  }
  return dest;
}
