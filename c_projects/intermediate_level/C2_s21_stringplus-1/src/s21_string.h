#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#define S21_NULL ((void *)0)
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define S21_SCHAR_MAX 127
#define S21_SCHAR_MIN -128
#define S21_LONG_LONG_MIN -9223372036854775807L
#define S21_LONG_LONG_MAX 9223372036854775807L
#define SSCANF_LOCALE "en_US.UTF-8"
#define NO_VALUE -1
#define WHITESPACE_CHARS " \t\n\v\f\r\0"

typedef unsigned long s21_size_t;
typedef struct sscanf_params {
  int flag;
  int width;
  int precision;
  int length;
  int length2;
  int specificator;
  int read_args;
  int error;
  const char *start;
} sparams;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
int s21_sscanf(const char *str, const char *format, ...);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_revstr(const char *str1);
int s21_sprintf(char *str, const char *format, ...);

#endif  //  SRC_S21_STRING_H_
