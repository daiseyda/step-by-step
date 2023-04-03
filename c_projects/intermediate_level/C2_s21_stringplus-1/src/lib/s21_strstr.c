#include "../s21_string.h"

// Finds the first occurrence of the entire string needle
// (not including the terminating null character) which appears in the string
// haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  char *haystack_copy;
  char *needle_copy = (char *)needle;
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);
  if (*needle == 0) {
    result = (char *)haystack;
  } else {
    for (s21_size_t n = 0; n <= haystack_len && result == S21_NULL; n++) {
      if (*needle_copy == *haystack) {
        haystack_copy = (char *)haystack;
        for (s21_size_t m = 0; m <= needle_len; m++) {
          if (*haystack_copy != *needle_copy) {
            break;
          }
          haystack_copy++;
          needle_copy++;
          if (*needle_copy == '\0') {
            result = (char *)haystack;
            break;
          }
        }
        needle_copy = (char *)needle;
      }
      haystack++;
    }
  }
  return result;
}
