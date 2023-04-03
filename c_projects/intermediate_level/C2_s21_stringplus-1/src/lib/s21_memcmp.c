#include "../s21_string.h"

// Compares the first n bytes of str1 and str2

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char s1 = 0, s2 = 0;
  char *the_str1 = (char *)str1;
  char *the_str2 = (char *)str2;
  int ret = 0;
  for (; n; the_str1++, the_str2++, n--) {
    s1 = *(unsigned char *)the_str1;
    s2 = *(unsigned char *)the_str2;
    if (s1 != s2) {
      ret = s1 - s2;
      break;
    }
  }
  return ret;
}
