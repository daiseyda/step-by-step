#include "../s21_string.h"

// Appends the string pointed to, by src to the end of the string pointed to by
// dest

char *s21_strcat(char *dest, const char *src) {
  s21_strcpy(dest + s21_strlen(dest), src);
  return dest;
}
