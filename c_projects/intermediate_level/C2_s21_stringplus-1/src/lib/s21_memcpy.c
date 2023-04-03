#include "../s21_string.h"

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  void* address = dest;
  char* _src = (char*)src;
  char* _dest = (char*)dest;
  for (s21_size_t i = 0; i < n; i++) {
    *_dest++ = *_src++;
  }
  return address;
}
