#include "../s21_string.h"

void* s21_to_upper(const char* str) {
  char* address = S21_NULL;
  if (str != S21_NULL) {
    address = malloc(s21_strlen(str) + 1 * sizeof(char));
    int i = 0;
    while (str[i] != '\0') {
      address[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
      i++;
    }
    address[i] = '\0';
  }
  return address;
}
