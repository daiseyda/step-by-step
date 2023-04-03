#include "s21_strerror.h"

#include "../s21_string.h"

// Searches an internal array for the error number errnum and returns a pointer
// to an error message string. You need to declare macros containing arrays of
// error messages for mac and linux operating systems. Error descriptions are
// available in the original library. Checking the current OS is carried out
// using directives.

char *s21_strerror(int errnum) {
  char message[100] = {0};
  char *the_message = message;
  char num[40] = {0};
  char *nums = num;
  const char numbers[11] = "0123456789";
  unsigned int err_num = errnum;

  if (err_num < ERRNUMB && errnum >= 0) {
    the_message = (char *)errlist[errnum];
  } else {
    if (errnum < 0) {
      err_num = errnum * (-1);
    }
    do {
      *nums++ = numbers[err_num % 10];
    } while (err_num /= 10);
    the_message = unkn_err + sizeof(UNKNOWN) - 1;
    if (errnum < 0) {
      *the_message++ = '-';
    }
    for (;;) {
      *the_message++ = *--nums;
      if (nums <= num) {
        break;
      }
    }
    the_message = unkn_err;
  }
  return the_message;
}
