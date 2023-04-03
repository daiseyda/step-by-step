#include "../s21_string.h"

int get_status(sparams *params);

void check_is_empty_str(char *s, sparams *params);
char *format_parser(char *format, sparams *params);
void clear_params(sparams *params);
void skip_format_chars(char **f, char **s);
char *skip_whitespaces(char *s);
int is_whitespace_char(int c);

char *read_width(char *format, sparams *params);
char *read_length(char *format, sparams *params);
char *read_specificator(char *format, sparams *params);

char *write_var(sparams *params, char *s, va_list *list);
char *write_char(sparams *params, char *s, va_list *list);
char *write_int(sparams *params, char *s, va_list *list, int sys);
char *write_string(sparams *params, char *s, va_list *list);
char *write_pointer(sparams *params, char *s, va_list *list);
char *write_float(sparams *params, char *s, va_list *list);
void write_n(sparams *params, char *s, va_list *list);

int get_num_len(char *s, sparams *params);
char *process_signed_int(int num_len, char *s, sparams *params, va_list *list,
                         int sys);
char *process_unsigned_int(int num_len, char *s, sparams *params, va_list *list,
                           int sys);
long long int make_number(char **s);
int get_sign(char **s, int *counter);
// Converts a string to a signed long long interger with a given maximum string
// length
long long int s21_strtoll(char *s, int *max_len, int base);
// Converts a string to an unsigned long long interger with a given maximum
// string length
unsigned long long int s21_strtoull(char *s, int *max_len, int base);
// Converts a string to a long double with a given maximum string length
long double s21_strtold(char *num_str, int *max_len);
// Converts a string to a float with a given maximum string length
float s21_strtof(char *s, int *max_len);
// Converts a string to a double with a given maximum string length
double s21_strtod(char *s, int *max_len);

// Reads formatted input from a string
int s21_sscanf(const char *str, const char *format, ...) {
  char *s = (char *)str;
  char *f = (char *)format;
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, SSCANF_LOCALE);
  sparams params = {NO_VALUE, NO_VALUE, NO_VALUE, NO_VALUE, NO_VALUE,
                    NO_VALUE, 0,        0,        str};
  va_list args;
  va_start(args, format);
  check_is_empty_str(s, &params);
  while (*f && *s &&
         params.error ==
             0) {  // Do while format and string are not empty and no errors
    skip_format_chars(&f, &s);
    f = format_parser(f, &params);
    if (*s) s = write_var(&params, s, &args);
  }
  va_end(args);

  return get_status(&params);
}

int get_status(sparams *params) {
  int status = NO_VALUE;
  if (params->read_args >= 0 && params->error == 0)
    status = params->read_args;
  else
    status = NO_VALUE;
  return status;
}

void check_is_empty_str(char *s, sparams *params) {
  s = skip_whitespaces(s);
  if (s21_strlen(s) == 0)  // If the length of str is 0, then it's an error
    params->error = 1;
}

// Parses a format string and saves info into sparams structure
char *format_parser(char *format, sparams *params) {
  clear_params(params);
  if (*format == '%') {
    format++;
    format = read_width(format, params);
    format = read_length(format, params);
    format = read_specificator(format, params);
  }
  return format;
}

void clear_params(sparams *params) {
  params->flag = NO_VALUE;
  params->width = NO_VALUE;
  params->precision = NO_VALUE;
  params->length = NO_VALUE;
  params->specificator = NO_VALUE;
}

void skip_format_chars(char **f, char **s) {
  // Skip spaces
  while (**s == ' ' && **s) *s = *s + 1;
  while (**f == ' ' && **f) *f = *f + 1;

  // Skip identical chars in f and s
  while (**f == **s && *f && *s && **f != '%') {
    *f = *f + 1;
    *s = *s + 1;
  }

  // A directive composed of one or more white-space characters shall be
  // executed by reading input until no more valid input can be read, or up to
  // the first byte which is not a white-space character, which remains unread.
  if (is_whitespace_char(**f) && *f) *s = skip_whitespaces(*s);

  // Skip until next % or the end of the input string (skip all invalid
  // characters)
  while (**f != '%' && **f != '\0' && *f) {
    *f = *f + 1;
  }
}

char *skip_whitespaces(char *s) {
  while (is_whitespace_char(*s) && *s) s++;
  return s;
}

int is_whitespace_char(int c) {
  int result = 0;
  result = s21_strchr(WHITESPACE_CHARS, (char)c) != S21_NULL;
  return result;
}

char *read_width(char *format, sparams *params) {
  if (isdigit(*format)) {
    params->width = (int)make_number(&format);
  }
  if (*format == '*') {
    params->width = (int)*format;
    format++;
  }
  if (isdigit(*format)) {
    format++;
  }
  return format;
}

char *read_length(char *format, sparams *params) {
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    params->length = (int)*format;
    format++;
  }
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    params->length2 = (int)*format;
    format++;
  }
  return format;
}

char *read_specificator(char *format, sparams *params) {
  if (*format == 'c' || *format == 'd' || *format == 'i' || *format == 'e' ||
      *format == 'E' || *format == 'f' || *format == 'g' || *format == 'G' ||
      *format == 'o' || *format == 's' || *format == 'u' || *format == 'u' ||
      *format == 'x' || *format == 'X' || *format == 'p' || *format == 'n') {
    params->specificator = (int)*format;
    format++;
  }
  return format;
}

char *write_var(sparams *params, char *s, va_list *list) {
  switch (params->specificator) {
    case 'c':
      s = write_char(params, s, list);
      break;
    case 'd':
    case 'u':
    case 'i':
      s = write_int(params, s, list, 0);
      break;
    case 's':
      s = write_string(params, s, list);
      break;
    case 'p':
      s = write_pointer(params, s, list);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      s = write_float(params, s, list);
      break;
    case 'o':
      s = write_int(params, s, list, 8);
      break;
    case 'x':
    case 'X':
      s = write_int(params, s, list, 16);
      break;
    case 'n':
      write_n(params, s, list);
      break;
  }
  return s;
}

char *write_char(sparams *params, char *s, va_list *list) {
  if (params->width == '*') {
    s++;  // Reads data of the specified type, but suppresses assignment
  } else {
    if (params->length == 'l') {
      wchar_t *p = (wchar_t *)va_arg(*list, wchar_t *);
      int len = mblen(s, MB_CUR_MAX);
      int res =
          mbtowc(p, s, len * s21_strlen(s));  // Reads extended character:
                                              // PC address, string, length
      if (res != -1) params->read_args++;
      for (int i = 0; i < len; i++) s++;
    } else {
      char *p = (char *)va_arg(*list, char *);
      *p = (char)*s;
      s++;
      params->read_args++;
    }
  }
  return s;
}

char *write_int(sparams *params, char *s, va_list *list, int sys) {
  int str_num_len =
      get_num_len(s, params);  // Вычисляем максимальную длину числа
  if (params->width != '*') {
    if (params->specificator == 'u' || params->specificator == 'x' ||
        params->specificator == 'o') {
      // Обработка всех беззнаковых чисел
      s = process_unsigned_int(str_num_len, s, params, list, sys);
    } else {
      // Обработка знаковых чисел
      s = process_signed_int(str_num_len, s, params, list, sys);
    }
  }
  return s;
}

int get_num_len(char *s, sparams *params) {
  s = skip_whitespaces(s);
  size_t str_num_len =
      s21_strlen(s);  // By default, the length of the string with a number is
                      // equal to the length of the string s
  if (params->width != NO_VALUE) {
    if ((int)str_num_len >
        params->width) {  // If the whitespace position is greater than the
                          // specified number width
      str_num_len = params->width;  // then the width of the number should be
                                    // that specified in the format string
    }
  }
  return str_num_len;
}

char *process_signed_int(int num_len, char *s, sparams *params, va_list *list,
                         int sys) {
  int read_symbols = num_len;
  long long int num = 0;
  num = s21_strtoll(s, &read_symbols, sys);
  char *read_s = calloc(read_symbols + 1, sizeof(char));
  s21_memcpy(read_s, s, read_symbols);
  char *trimmed_str = s21_trim(read_s, S21_NULL);
  char *lowered_str = s21_to_lower(trimmed_str);
  if ((num != 0 && num_len != 0) || (s21_strcmp(trimmed_str, "0") == 0 ||
                                     s21_strcmp(lowered_str, "0x0") == 0 ||
                                     s21_strcmp(lowered_str, "+0") == 0 ||
                                     s21_strcmp(lowered_str, "-0") == 0 ||
                                     s21_strcmp(lowered_str, "+0x0") == 0 ||
                                     s21_strcmp(lowered_str, "-0x0") == 0 ||
                                     s21_strcmp(lowered_str, "+0x") == 0 ||
                                     s21_strcmp(lowered_str, "-0x") == 0)) {
    if (params->length == 'h' && params->length2 == 'h') {
      if (num == S21_LONG_LONG_MIN)
        *(va_arg(*list, char *)) = (char)(num - 1);
      else
        *(va_arg(*list, char *)) = (char)num;
    } else if (params->length == 'h' && params->length2 == NO_VALUE) {
      if (num == S21_LONG_LONG_MIN)
        *(va_arg(*list, short int *)) = (short int)(num - 1);
      else
        *(va_arg(*list, short int *)) = (short int)num;
    } else if (params->length == 'l' && params->length2 == NO_VALUE) {
      if (num == S21_LONG_LONG_MIN)
        *(va_arg(*list, long int *)) = (long int)(num - 1);
      else
        *(va_arg(*list, long int *)) = (long int)num;
    } else if (params->length == 'l' && params->length2 == 'l') {
      if (num == S21_LONG_LONG_MIN)
        *(va_arg(*list, long long int *)) = num - 1;
      else
        *(va_arg(*list, long long int *)) = num;
    } else {
      if (num == S21_LONG_LONG_MIN)
        *(va_arg(*list, int *)) = (int)(num - 1);
      else
        *(va_arg(*list, int *)) = (int)num;
    }
    params->read_args++;
  }
  if (trimmed_str) free(trimmed_str);
  if (lowered_str) free(lowered_str);
  if (read_s) free(read_s);

  return s + read_symbols;
}

char *process_unsigned_int(int num_len, char *s, sparams *params, va_list *list,
                           int sys) {
  int read_symbols = num_len;
  unsigned long long int unum = s21_strtoull(s, &read_symbols, sys);
  char *read_s = calloc(read_symbols + 1, sizeof(char));
  s21_memcpy(read_s, s, read_symbols);
  char *trimmed_str = s21_trim(s, S21_NULL);
  char *lowered_str = s21_to_lower(trimmed_str);

  if ((unum != 0 && num_len != 0) || (s21_strcmp(trimmed_str, "0") == 0 ||
                                      s21_strcmp(lowered_str, "0x0") == 0 ||
                                      s21_strcmp(lowered_str, "+0") == 0 ||
                                      s21_strcmp(lowered_str, "-0") == 0 ||
                                      s21_strcmp(lowered_str, "+0x0") == 0 ||
                                      s21_strcmp(lowered_str, "-0x0") == 0 ||
                                      s21_strcmp(lowered_str, "+0x") == 0 ||
                                      s21_strcmp(lowered_str, "-0x") == 0)) {
    if (params->length == 'h' && params->length2 == 'h') {
      *(va_arg(*list, unsigned char *)) = (unsigned char)unum;
    } else if (params->length == 'h' && params->length2 == NO_VALUE) {
      *(va_arg(*list, unsigned short int *)) = (unsigned short int)unum;
    } else if (params->length == 'l' && params->length2 == NO_VALUE) {
      if (unum > ULONG_MAX)
        *(va_arg(*list, unsigned long int *)) = ULONG_MAX;
      else
        *(va_arg(*list, unsigned long int *)) = (unsigned long int)unum;
    } else if (params->length == 'l' && params->length2 == 'l') {
      *(va_arg(*list, unsigned long long int *)) = unum;
    } else {
      *(va_arg(*list, unsigned int *)) = (unsigned int)unum;
    }
    params->read_args++;
  }
  if (trimmed_str) free(trimmed_str);
  if (lowered_str) free(lowered_str);
  if (read_s) free(read_s);

  return s + read_symbols;
}

char *write_string(sparams *params, char *s, va_list *list) {
  s = skip_whitespaces(s);
  if (params->width == '*') {
    // Skip assignment
    while (!is_whitespace_char(*s)) s++;
  } else {
    char *s_copy = s;
    s21_strtok(s_copy, WHITESPACE_CHARS);
    s21_strcpy(va_arg(*list, char *), s_copy);
    params->read_args++;
    s += s21_strlen(s);
  }
  return s;
}

char *write_pointer(sparams *params, char *s, va_list *list) {
  long long int address = 0;
  if (params->width != NO_VALUE) {
    char *address_str = calloc(params->width + 1, sizeof(char));
    s21_strncpy(address_str, s, params->width);
    char *end = S21_NULL;
    address = strtol(address_str, &end, 16);
    if (address != 0 && s != end) *(va_arg(*list, int *)) = (int)address;
    if (address_str) free(address_str);
  } else {
    char *end = S21_NULL;
    address = strtol(s, &end, 16);
    if (address != 0 && s != end) *(va_arg(*list, int *)) = (int)address;
  }
  params->read_args++;
  return s;
}

char *write_float(sparams *params, char *s, va_list *list) {
  int str_num_len = get_num_len(s, params);
  if (params->width != '*') {
    if (params->length == 'l') {
      double number = s21_strtod(s, &str_num_len);
      if (str_num_len > 0 && number != 0) {
        *(va_arg(*list, double *)) = (double)number;
        params->read_args++;
      }
    } else if (params->length == 'L') {
      long double number = s21_strtold(s, &str_num_len);
      if (str_num_len > 0 && number != 0) {
        *(va_arg(*list, long double *)) = (long double)number;
        params->read_args++;
      }
    } else {
      float number = s21_strtof(s, &str_num_len);
      if (str_num_len > 0 && number != 0) {
        *(va_arg(*list, float *)) = (float)number;
        params->read_args++;
      }
    }
  } else {
    s21_strtold(s, &str_num_len);
  }
  if (*s) s += str_num_len;
  return s;
}

void write_n(sparams *params, char *s, va_list *list) {
  int diff = s - params->start;
  if (params->length == 'h') {
    *(va_arg(*list, unsigned char *)) = (unsigned char)diff;
  } else {
    *(va_arg(*list, int *)) = diff;
  }
}

long long int make_number(char **s) {
  long long int num = 0;
  int len = 0;
  long long int sign = 0;
  int counter = 0;
  sign = get_sign(s, &counter);

  while (isdigit(**s)) {
    if (len == 0) {
      num = (int)(**s - '0');
    } else {
      num = num * 10 + (int)(**s - '0');
    }
    len++;
    *s = *s + 1;
  }
  return num * sign;
}

int get_sign(char **s, int *counter) {
  int result = 0;
  if (**s == '-') {
    result = -1;
    *s = *s + 1;
    *counter = *counter + 1;
  } else if (**s == '+') {
    result = 1;
    *s = *s + 1;
    *counter = *counter + 1;
  } else {
    result = 1;
  }
  return result;
}

long long int s21_strtoll(char *s, int *max_len, int base) {
  char *temp = skip_whitespaces(s);
  long long int result = 0LL;
  int sign = 0;
  int counter = temp - s;
  sign = get_sign(&temp, &counter);

  // Fix the base if the number format is different from the one from argument
  if ((base == 0 || base == 16) && *temp == '0' &&
      (*(temp + 1) == 'x' || *(temp + 1) == 'X')) {
    base = 16;
    temp = temp + 2;
    counter += 2;
  } else if (base == 0 && *temp == '0') {
    base = 8;
    counter += 1;
    temp = temp + 1;
  } else if (base == 0) {
    base = 10;
  }

  // Decimal and octal numbers
  if (base == 10 || base == 8) {
    while (((base == 10 && isdigit(*temp)) ||
            (base == 8 && *temp >= '0' && *temp <= '7')) &&
           counter < *max_len && *temp) {
      int number = (*temp - '0');
      counter++;
      temp = temp + 1;
      if ((result + number) < 0) {
        result = S21_LONG_LONG_MAX;
        break;
      } else {
        result = result + number;
      }
      if ((result * base) < 0) {
        result = S21_LONG_LONG_MAX;
        break;
      } else {
        result *= base;
      }
    }
    if (result != S21_LONG_LONG_MAX) result /= base;
  } else if (base == 16) {  // Hexadecimal numbers
    while ((isdigit(*temp) || (*temp >= 'A' && *temp <= 'F') ||
            (*temp >= 'a' && *temp <= 'f')) &&
           counter < *max_len && *temp) {
      int number;
      if (isdigit(*temp)) {
        number = *temp - '0';
      } else if (*temp >= 'A' && *temp <= 'F') {
        number = *temp - '7';
      } else {
        number = *temp - 'W';
      }
      temp = temp + 1;
      counter++;
      if ((result + number) < 0) {
        result = S21_LONG_LONG_MAX;
        break;
      } else {
        result += number;
      }
      if ((result * 16) < 0) {
        result = S21_LONG_LONG_MAX;
        break;
      } else {
        result *= 16;
      }
    }
    if (result != S21_LONG_LONG_MAX) result /= 16;
  }

  result *= sign;
  *max_len = (temp - s) > counter ? (temp - s) : counter;
  return result;
}

unsigned long long int s21_strtoull(char *s, int *max_len, int base) {
  return (unsigned long long int)s21_strtoll(s, max_len, base);
}

long double s21_strtold(char *s, int *max_len) {
  char *temp = skip_whitespaces(s);
  long double result = 0;
  int counter = temp - s;
  int sign = get_sign(&temp, &counter);
  int int_part = 0;
  long double num = 0.0, frac_part = 0.0, e_degree = 0.0;

  // Integer part of the number
  while (*temp && isdigit(*temp) && counter < *max_len) {
    int_part = int_part * 10 + (*temp - '0');
    temp++;
    counter++;
    num++;
  }
  num = (long double)int_part;

  // If . found, skip it
  if (*temp == '.' && counter < *max_len) {
    temp++;
    counter++;
  }

  // Fractional part of the number
  int precision = 10;
  for (frac_part = 1.;
       *temp && isdigit(*temp) && counter < *max_len && precision > 0;
       temp++, frac_part *= 10., counter++, precision--) {
    num = num * 10. + (*temp - '0');
  }
  // Adjust number precision to e-08
  while (precision > 0) {
    num = num * 10.;
    frac_part *= 10.;
    precision--;
  }

  // Scientific notation
  if ((*temp == 'e' || *temp == 'E') &&
      (isdigit(*(temp + 1)) || *(temp + 1) == '-' || *(temp + 1) == '+')) {
    int esign = 1;
    if (num <= 1e-6) num = 1;
    temp++;
    counter++;
    // Skip signs
    if (*temp == '-') esign = -1, temp++, counter++;
    if (*temp == '+') temp++, counter++;
    // Find power of e
    for (e_degree = 0; *temp && isdigit(*temp) && counter < *max_len;
         temp++, counter++) {
      e_degree = e_degree * 10 + (*temp - '0');
    }
    e_degree *= esign;
  } else {
    e_degree = 0;
  }

  // Check if NAN
  if ((*temp == 'n' || *temp == 'N') && (temp[1] == 'a' || temp[1] == 'A') &&
      (temp[2] == 'n' || temp[2] == 'N')) {
    temp += 3;
    counter += 3;
    num = NAN * sign;
  }
  // Check if INFINITY
  if ((*temp == 'i' || *temp == 'I') && (temp[1] == 'n' || temp[1] == 'N') &&
      (temp[2] == 'f' || temp[2] == 'F')) {
    temp += 3;
    counter += 3;
    num = INFINITY * sign;
  }

  // Get a final number
  if (isnan(num) || isinf(num))
    result = num;
  else
    result = (num * sign / frac_part) * powl(10, e_degree);
  // Get a maximum number of scanned symbols
  *max_len = (temp - s) > counter ? (temp - s) : counter;
  return result;
}

float s21_strtof(char *s, int *max_len) {
  return (float)s21_strtold(s, max_len);
}

double s21_strtod(char *s, int *max_len) {
  return (double)s21_strtold(s, max_len);
}
