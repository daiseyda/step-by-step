#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL) {
    if (trim_chars == S21_NULL) trim_chars = "";
    s21_size_t left = s21_strspn(src, trim_chars);
    char *revert_string = s21_revstr(src);
    s21_size_t right = s21_strspn(revert_string, trim_chars);
    s21_size_t len = s21_strlen(src) - (right + left);
    result = calloc(len + 1, sizeof(char));
    if (result != S21_NULL) {
      s21_memmove(result, &src[left], len);
      result[len] = '\0';
    }
    if (revert_string) free(revert_string);
  }
  return result;
}

char *s21_revstr(const char *str) {
  s21_size_t len = s21_strlen(str), i = 0;
  char *result = calloc(len + 1, sizeof(char));
  if (result != S21_NULL) {
    while (str[i]) {
      len--;
      result[i] = str[len];
      i++;
    }
    result[i] = '\0';
  }
  return result;
}
