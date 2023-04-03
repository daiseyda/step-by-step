#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  s21_size_t src_len = (src == S21_NULL) ? 0 : s21_strlen(src);
  s21_size_t str_len = (str == S21_NULL) ? 0 : s21_strlen(str);
  s21_size_t total_len = src_len + str_len;

  if (src != S21_NULL && str != S21_NULL && start_index <= src_len) {
    result = calloc(total_len + 1, sizeof(char));
    if (result) {
      s21_size_t i = 0;
      while (i < total_len) {
        if (i < start_index) {
          result[i] = src[i];
        } else if (i < str_len + start_index) {
          result[i] = str[i - start_index];
        } else {
          result[i] = src[i - str_len];
        }
        i++;
      }
    }
  }
  return result;
}
