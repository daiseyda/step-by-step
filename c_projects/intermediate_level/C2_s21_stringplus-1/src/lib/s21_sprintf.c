#include "../s21_string.h"
#define LEN 2000

void s21_gcvt(long double number, int ndigit, char *str, int *flag);
int s21_sprintf(char *str, const char *format, ...);
void s21_int_to_str_conventor(char *str, long long int num);
void s21_int_to_str_conventor_ull(char *str, unsigned long long int num);
void s21_scientific_notation(char *str, long double num, const char c,
                             int *wight, int *flag);
void s21_notation_convertor(long int num, char *new_num, const char c);
void s21_str_reverse(char *str);
void s21_pattetn_check(const char *str, int *i, int *flag, int *wight,
                       int length);
double s21_fabs(double x);
long double s21_fabs_l_d(long double x);
void s21_format_str_creator(int *wight, char *format_str, char *accur_str,
                            int *flag, int num_l, int a, char b, int f);
void s21_adding_accur(char *str_from_int, char *accur_str, int *flag, int sign);
void s21_adding_wight(char *str_from_int, char *format_str, int *flag,
                      int sign);
int s21_qty_after_dot(char *str_from_float);
void sign_checker_int(long int *d, int *sign, int *add_s, int *flag,
                      int *min_flag);
void sign_checker_float(double *f, int *sign, int *add_s, int *flag);
void sign_checker_l_d(long double *f, int *sign, int *add_s, int *flag);
void str_temp_creator(const char *str, char *str_new, int *last_symbol,
                      int *length, int *l_size);
int check_for_wrong_symbols(const char *str, int *l);
void f_creator(char *str_from_float, long double f, int *wight, int *flag,
               int *temp);
int s21_atoi(char *s);

int s21_atoi(char *s) {
  int n = 0;
  while (*s >= '0' && *s <= '9') {
    n *= 10;
    n += *s++;
    n -= '0';
  }
  return n;
}

void s21_gcvt(long double number, int ndigit, char *str, int *flag) {
  long double int_part = 0, float_part = 0;
  unsigned long long int new_int_part = 0, temp = 0;
  char float_part_str[80];
  int j = 0;
  s21_memset(float_part_str, 0, 80);
  float_part = modfl(number, &int_part);
  float_part = round(float_part * pow(10., ndigit)) / pow(10., ndigit);
  if (float_part == 1) {
    int_part += 1;
    float_part = 0;
  }
  if (ndigit && float_part) {
    temp = (unsigned long long int)(float_part * pow(10., ndigit));
    if ((float_part - temp / (pow(10., ndigit))) > 0.00000000000000001) {
      temp += 1;
    }
    if (flag[11] && !flag[3])
      while (temp % 10 == 0) temp /= 10;
    while (temp) {
      float_part_str[j] = temp % 10 + '0';
      temp /= 10;
      j++;
    }
    float_part_str[j] = '.';
    j++;
    float_part_str[j] = '\0';
    s21_str_reverse(float_part_str);
  }
  if (!ndigit && float_part) {
    if (float_part > 0.5) int_part += 1;
    float_part_str[j] = '\0';
  } else if (ndigit && !float_part && !flag[11]) {
    j = 0;
    float_part_str[j] = '.';
    j++;
    if (ndigit == 1) float_part_str[j] = '0';
    for (; j <= ndigit; j++) float_part_str[j] = '0';
    float_part_str[j] = '\0';
  }
  new_int_part = (unsigned long long int)int_part;
  s21_int_to_str_conventor_ull(str, new_int_part);
  s21_strcat(str, float_part_str);
}

double s21_fabs(double x) {  // модуль для вещественных
  if (x < 0 || (1 / x < 0 && x == 0)) x *= -1;
  return x;
}

long double s21_fabs_l_d(long double x) {  // модуль для вещественных
  if (x < 0 || (1 / x < 0 && x == 0)) x *= -1;
  return x;
}

void s21_str_reverse(char *str) {  // реверс строки
  int i, j;
  char c;
  for (i = 0, j = s21_strlen(str) - 1; i < j; i++, j--) {
    c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}

void s21_notation_convertor(
    long int num, char *new_num,
    const char c) {  // перевод в заданную систему исчисления
  int base = 0, i = 0, j = 0, reg = 0;
  if (c == 'o')
    base = 8;
  else if (c == 'u')
    base = 10;
  else if (c == 'x')
    base = 16;
  else if (c == 'X') {
    base = 16;
    reg = 32;
  } else if (c == 'p') {
    base = 16;
    // reg = 32;
  }
  if (base != 16) {
    while (num) {
      new_num[j] = (unsigned long)num % base + '0';
      num = (unsigned long)num / base;
      j++;
    }
    new_num[j] = '\0';
    s21_str_reverse(new_num);
  } else {
    int t;
    while (num) {
      t = (unsigned long)num % base;
      if (t == 10)
        new_num[i] = 'a' - reg;
      else if (t == 11)
        new_num[i] = 'b' - reg;
      else if (t == 12)
        new_num[i] = 'c' - reg;
      else if (t == 13)
        new_num[i] = 'd' - reg;
      else if (t == 14)
        new_num[i] = 'e' - reg;
      else if (t == 15)
        new_num[i] = 'f' - reg;
      else
        new_num[i] = t + '0';
      num = (unsigned long)num / base;
      i++;
    }
    // if (c == 'p') {
    //     new_num[i] = 'e'; i++;
    //     new_num[i] = 'f'; i++;
    //     new_num[i] = 'f'; i++;
    //     new_num[i] = '7'; i++; }
    new_num[i] = '\0';
    s21_str_reverse(new_num);
  }
}

void s21_scientific_notation(
    char *str, long double num, const char c, int *wight,
    int *flag) {  // конвертация числа в строку ввиде научной нотации
  int i = 0, x = 0, j = 0, sign_flag = 1;
  long double temp = num;
  if (temp == 0 || temp >= 1) {
    while (temp >= 10) {
      temp = temp * 0.1;
      i++;
    }
  } else {
    sign_flag = -1;
    while (temp < 1) {
      temp *= 10;
      i++;
    }
  }
  x = 6;
  if (flag[6]) x = wight[1];
  if ((c == 'g' || c == 'G') && !flag[6]) wight[1] = 6;
  if ((c == 'g' || c == 'G') && i * sign_flag >= -4 && i < wight[1])
    flag[10] = i;
  else {
    if ((c == 'g' || c == 'G') && !(flag[6] && !wight[1])) {
      x -= 1;
    }
    s21_gcvt(temp, x, str, flag);
    if (flag[11]) {
      temp = s21_atoi(str);
      if (temp >= 10) {
        temp = temp * 0.1;
        i++;
        str[0] = '1';
        str[1] = '\0';
      }
    }
    j = s21_strlen(str);
    if (flag[3] && !s21_strchr(str, '.')) str[j++] = '.';
    if (c == 'e' || c == 'g')
      str[j++] = 'e';
    else
      str[j++] = 'E';
    if (sign_flag == -1)
      str[j++] = '-';
    else
      str[j++] = '+';
    if (i < 10) {
      str[j++] = '0';
      str[j++] = i + '0';
    } else if (i >= 10 && i < 100) {
      str[j++] = i / 10 + '0';
      str[j++] = i % 10 + '0';
    } else if (i >= 100 && i < 1000) {
      str[j++] = i / 100 + '0';
      str[j++] = i / 10 % 10 + '0';
      str[j++] = i % 10 + '0';
    }
    str[j++] = '\0';
  }
}

void s21_int_to_str_conventor_ull(char *str, unsigned long long int num) {
  int i = 0, j = 0;
  char new_num[180];
  s21_memset(new_num, 0, 180);
  if (num) {
    while (num) {
      new_num[j] = num % 10 + '0';
      num /= 10;
      j++;
    }
    new_num[j] = '\0';
    s21_str_reverse(new_num);
    for (j = 0; new_num[j] != '\0'; i++, j++) str[i] = new_num[j];
    str[i] = '\0';
  } else {
    str[0] = '0';
    str[1] = '\0';
  }
}

void s21_int_to_str_conventor(
    char *str, long long int num) {  // перевод интовых значений в строку
  int i = 0, j = 0;
  char new_num[80];
  s21_memset(new_num, 0, 80);
  if (num < 0) {
    num *= -1;
    str[i] = '-';
    i++;
  }
  if (num) {
    while (num) {
      new_num[j] = num % 10 + '0';
      num /= 10;
      j++;
    }
    new_num[j] = '\0';
    s21_str_reverse(new_num);
    for (j = 0; new_num[j] != '\0'; i++, j++) str[i] = new_num[j];
    str[i] = '\0';
  } else {
    str[0] = '0';
    str[1] = '\0';
  }
}

void s21_pattetn_check(const char *str, int *l, int *flag, int *wight,
                       int length) {  // обработка флагов
  int i = 0, j = 1;
  while (str[j] == '-' || str[j] == '+' || str[j] == ' ' || str[j] == '#' ||
         str[j] == '0') {
    if (str[j] == '-')
      flag[0] = 1;
    else if (str[j] == '+')
      flag[1] = 1;
    else if (str[j] == ' ')
      flag[2] = 1;
    else if (str[j] == '#')
      flag[3] = 1;
    else if (str[j] == '0')
      flag[4] = 1;
    j++;
  }
  if (flag[0]) flag[4] = 0;
  if (s21_strchr(str, '.') &&
      (str[*l] == 'd' || str[*l] == 'i' || str[*l] == 'o' || str[*l] == 'u' ||
       str[*l] == 'x' || str[*l] == 'X' || str[*l] == 'p' || str[*l] == 's'))
    flag[5] = 1;
  if (s21_strchr(str, '.') &&
      (str[*l] == 'e' || str[*l] == 'E' || str[*l] == 'f' || str[*l] == 'g' ||
       str[*l] == 'G'))
    flag[6] = 1;
  if (str[*l] == 'o' || str[*l] == 'x' || str[*l] == 'X' || str[*l] == 's' ||
      str[*l] == 'c' || str[*l] == 'u' || str[*l] == 'p' || str[*l] == '%' ||
      flag[9]) {
    flag[2] = 0;
    flag[1] = 0;
  }
  if (str[*l] == 'g' || str[*l] == 'G') flag[11] = 1;
  if (str[*l] == 'd') flag[3] = 0;
  if (((str[*l] == 'o' || str[*l] == 'x' || str[*l] == 'X') && flag[3]) ||
      str[*l] == 'p')
    flag[3] = 2;
  char wight_str[100];
  char accur_str[100];
  s21_memset(wight_str, 0, 100);
  s21_memset(accur_str, 0, 100);
  for (; i < *l && j < *l; i++, j++) {
    if (str[j] > 47 && str[j] < 58)
      wight_str[i] = str[j];
    else if (str[j] == '*')
      flag[7] = 1;
    else if (str[j] == '.') {
      break;
      wight_str[0] = '0';
      i = 0;
    }
  }
  wight_str[i] = '\0';
  if (flag[5] || flag[6]) {
    for (; i < *l - length && j < *l - length; i++, j++) {
      if (str[j] > 47 && str[j] < 58)
        accur_str[i] = str[j];
      else if (str[j] == '*')
        flag[8] = 1;
      else {
        accur_str[0] = '0';
        i = 0;
      }
    }
  }
  accur_str[i] = '\0';
  wight[0] = s21_atoi(wight_str);
  wight[1] = s21_atoi(accur_str);
  if (flag[5] && (str[*l] == 'x' || str[*l] == 'X' || str[*l] == 'o'))
    flag[4] = 0;
  if (wight[0] > 1976 || wight[1] > 1980) {
    wight[0] = -1;
  }
}

void s21_format_str_creator(int *wight, char *format_str, char *accur_str,
                            int *flag, int num_l, int a, char b, int f) {
  char c = ' ';
  int i = 0, k = 0, j = 0;
  if (flag[4]) c = '0';
  if (!wight[0]) format_str[0] = '\0';
  if (!wight[1]) accur_str[0] = '\0';
  if (flag[3] == 2) {
    if (b == 'x' || b == 'X') {
      accur_str[j] = '0';
      j++;
      accur_str[j] = b;
      j++;
      k = 2;
    } else {
      accur_str[j] = '0';
      j++;
      if (wight[1] > num_l)
        k = 0;
      else
        k = 1;
    }
  }

  wight[1] -= num_l - a;
  if (wight[1] < 0) wight[1] = 0;
  if (b == 'f') {
    if (!flag[6])
      wight[1] = 0;
    else
      wight[1] = f;
  }
  wight[0] -= num_l + wight[1];
  if (wight[0] || wight[1]) {
    if (wight[0]) {
      for (; i < wight[0] - k; i++)  // k - используется для o, x, X
        format_str[i] = c;
      format_str[i] = '\0';
    }
    if (wight[1]) {
      c = '0';
      for (; j < wight[1] + k; j++)  // k - используется для o, x, X
        accur_str[j] = c;
      accur_str[j] = '\0';
    }
  }
  if (flag[3] == 2) s21_str_reverse(accur_str);
}

void s21_adding_accur(char *str_from_int, char *accur_str, int *flag,
                      int sign) {
  int str_num = s21_strlen(str_from_int);
  s21_str_reverse(str_from_int);
  if (flag[5] || flag[3]) {
    for (int i = 0; accur_str[i] != '\0'; str_num++, i++)
      str_from_int[str_num] = accur_str[i];
    if (sign < 0) {
      str_from_int[str_num] = '-';
      str_num++;
    } else if (sign >= 0 && flag[1]) {
      str_from_int[str_num] = '+';
      str_num++;
    } else if (!sign && flag[2]) {
      str_from_int[str_num] = ' ';
      str_num++;
    }
    str_from_int[str_num] = '\0';
  } else {
    if (sign < 0) {
      str_from_int[str_num] = '-';
      str_num++;
    } else if (sign >= 0 && flag[1]) {
      str_from_int[str_num] = '+';
      str_num++;
    } else if (!sign && flag[2]) {
      str_from_int[str_num] = ' ';
      str_num++;
    }
    str_from_int[str_num] = '\0';
  }
  s21_str_reverse(str_from_int);
  if (flag[6]) {
    for (int i = 0; accur_str[i] != '\0'; str_num++, i++)
      str_from_int[str_num] = accur_str[i];
    str_from_int[str_num] = '\0';
  }
}

int s21_qty_after_dot(char *str_from_float) {
  int i = 0, result = 0;
  while (str_from_float[i] != '.' && str_from_float[i] != '\0') i++;
  i++;
  for (; str_from_float[i] != '\0'; i++) result++;
  return result;
}

void sign_checker_int(long int *d, int *sign, int *add_s, int *flag,
                      int *min_flag) {
  if (*d < 0) {
    if (*d == LONG_MIN) {
      *min_flag = 1;
      *sign = -1;
      *d = LONG_MAX;
      *add_s = 1;
    } else {
      *sign = -1;
      *d = (*d) * (-1);
      *add_s = 1;
    }
  } else {
    *sign = 1;
    if (flag[1]) *add_s = 1;
  }
  if (!flag[1] && flag[2] && *sign > 0) {
    *sign = 0;
    *add_s = 1;
  }
}

void sign_checker_float(double *f, int *sign, int *add_s, int *flag) {
  if (*f < 0) {
    *sign = -1;
    *f = s21_fabs(*f);
    *add_s = 1;
  } else {
    *sign = 1;
    if (flag[1]) *add_s = 1;
  }
  if (!flag[1] && flag[2] && *sign > 0) {
    *sign = 0;
    *add_s = 1;
  }
}

void sign_checker_l_d(long double *f, int *sign, int *add_s, int *flag) {
  if (*f < 0) {
    *sign = -1;
    *f = s21_fabs_l_d(*f);
    *add_s = 1;
  } else {
    *sign = 1;
    if (flag[1]) *add_s = 1;
  }
  if (!flag[1] && flag[2] && *sign > 0) {
    *sign = 0;
    *add_s = 1;
  }
}

void s21_adding_wight(char *str_from_int, char *format_str, int *flag,
                      int sign) {
  int str_num = s21_strlen(str_from_int), str_f = s21_strlen(format_str),
      temp = str_num;
  if (str_f) {
    if (!flag[0]) {
      int i = 0;
      char str_temp[2000];
      s21_memset(str_temp, 0, 2000);
      s21_strcpy(str_temp, str_from_int);
      if (sign && flag[4]) i++;
      for (int j = 0; format_str[j] != '\0'; i++, j++)
        str_from_int[i] = format_str[j];
      for (int j = 0; str_temp[j] != '\0'; i++, j++)
        str_from_int[i] = str_temp[j];
      str_from_int[i] = '\0';
    } else {
      for (int i = 0; str_num < str_f + temp; str_num++, i++)
        str_from_int[str_num] = format_str[i];
      str_from_int[str_num] = '\0';
    }
  }
}

void str_temp_creator(const char *str, char *str_new, int *last_symbol,
                      int *length, int *l_size) {
  int i = 0;
  if (str[*last_symbol] == 'h') {
    (*last_symbol)++;
    if (str[*last_symbol] == 'd' || str[*last_symbol] == 'i' ||
        str[*last_symbol] == 'o' || str[*last_symbol] == 'u' ||
        str[*last_symbol] == 'x' || str[*last_symbol] == 'X' ||
        str[*last_symbol] == 'c' || str[*last_symbol] == 's') {
      *l_size = 1;
      *length = 1;
    }
  } else if (str[*last_symbol] == 'l') {
    (*last_symbol)++;
    if (str[*last_symbol] == 'd' || str[*last_symbol] == 'i' ||
        str[*last_symbol] == 'o' || str[*last_symbol] == 'u' ||
        str[*last_symbol] == 'x' || str[*last_symbol] == 'X' ||
        str[*last_symbol] == 'c' || str[*last_symbol] == 's') {
      *l_size = 2;
      *length = 1;
    }
  } else if (str[*last_symbol] == 'L') {
    (*last_symbol)++;
    if (str[*last_symbol] == 'e' || str[*last_symbol] == 'E' ||
        str[*last_symbol] == 'f' || str[*last_symbol] == 'g' ||
        str[*last_symbol] == 'G') {
      *l_size = 2;
      *length = 1;
    }
  }
  for (; i <= *last_symbol; i++) str_new[i] = str[i];
  str_new[i] = '\0';
}

int check_for_wrong_symbols(const char *str, int *l) {
  int error = 0;
  for (int i = 1; i < *l; i++) {
    if (!s21_strchr("+-#*. lLhcdeEfgGosuxXpni0123456789", str[i])) {
      *l = i;
      error = 1;
      break;
    }
  }
  return error;
}

void f_creator(char *str_from_float, long double f, int *wight, int *flag,
               int *temp) {
  int f_p = 0;
  int x = 6;
  if (flag[6] || flag[10]) x = wight[1];
  s21_gcvt(f, x, str_from_float, flag);
  if (f == 0 && flag[6] && !wight[1]) {
    str_from_float[0] = '0';
    str_from_float[1] = '\0';
  }
  int j = s21_strlen(str_from_float);
  f_p = s21_qty_after_dot(str_from_float);
  if (f_p && wight[1] > f_p) *temp = wight[1] - f_p;
  if (!f_p) {
    if ((wight[1] || flag[3] || !flag[6]) && (!flag[10])) {
      str_from_float[j] = '.';
      j++;
    }
    for (; j < x; j++) str_from_float[j] = '0';
    str_from_float[j] = '\0';
  }
  if (f_p && f_p < 7 && f_p > wight[1]) {
    for (j = 0; str_from_float[j] != '.'; j++)
      ;
    j++;
    j += f_p;
    for (; f_p < 6; j++, f_p++) str_from_float[j] = '0';
    str_from_float[j] = '\0';
  }
}

int s21_sprintf(
    char *str, const char *format,
    ...) {  // основная ф-уия записи в строку, включает обработку спецификаторов
  int i = 0;
  va_list factor;
  va_start(factor, format);
  for (const char *c = format; *c; c++, i++) {
    if (*c != '%')
      str[i] = *c;
    else {
      char format_str[LEN], accur_str[LEN], str_temp[80];
      s21_memset(format_str, 0, LEN);
      s21_memset(accur_str, 0, LEN);
      s21_memset(str_temp, 0, 80);
      int flag[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int wight[2] = {0, 0};
      int length = 0, l_size = 0, p_check = 0;
      p_check = s21_strcspn(c, "LlhcdeEfgGosuxXpni");
      str_temp_creator(c, str_temp, &p_check, &length, &l_size);
      flag[9] = check_for_wrong_symbols(str_temp, &p_check);
      s21_pattetn_check(str_temp, &p_check, flag, wight, length);
      c += p_check;
      if (!flag[9]) {
        if (*c == 'c') {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          char str_for_c[LEN];
          s21_memset(str_for_c, 0, LEN);
          unsigned char ch = (unsigned char)va_arg(factor, int);
          s21_format_str_creator(wight, format_str, accur_str, flag, 1, 0, *c,
                                 0);
          str_for_c[0] = ch;
          str_for_c[1] = '\0';
          s21_adding_wight(str_for_c, format_str, flag, 0);
          for (int j = 0; str_for_c[j] != '\0'; j++, i++) str[i] = str_for_c[j];
          if (ch)
            i--;
          else
            str[i] = '\0';
        } else if (*c == 'd' || *c == 'i') {
          int sign = 0, add_s = 0, min_flag = 0;
          char str_from_int[LEN];
          s21_memset(str_from_int, 0, LEN);
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long int d = va_arg(factor, long int);
          if (l_size == 1)
            d = (short)d;
          else if (!l_size)
            d = (int)d;
          sign_checker_int(&d, &sign, &add_s, flag, &min_flag);
          s21_int_to_str_conventor(str_from_int, d);
          if (min_flag) str_from_int[18] = '8';
          if (flag[5] && !d && !wight[1]) str_from_int[0] = '\0';
          int num_length = s21_strlen(str_from_int) + add_s;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, 0);
          s21_adding_accur(str_from_int, accur_str, flag, sign);
          s21_adding_wight(str_from_int, format_str, flag, add_s);
          for (int j = 0; str_from_int[j] != '\0'; j++, i++) {
            if (j != 0 && flag[4] &&
                (str_from_int[j] == '-' || str_from_int[j] == '+' ||
                 str_from_int[j] == ' '))
              j++;
            str[i] = str_from_int[j];
          }
          i--;
        } else if ((*c == 'e' || *c == 'E') && !l_size) {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          double e = va_arg(factor, double);
          int sign = 0, add_s = 0, num_length = 0;
          char sci_not_str[LEN];
          s21_memset(sci_not_str, 0, LEN);
          sign_checker_float(&e, &sign, &add_s, flag);
          s21_scientific_notation(sci_not_str, e, *c, wight, flag);
          num_length = s21_strlen(sci_not_str) + add_s;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, 0);
          s21_adding_accur(sci_not_str, accur_str, flag, sign);
          s21_adding_wight(sci_not_str, format_str, flag, add_s);
          for (int j = 0; sci_not_str[j] != '\0'; j++, i++) {
            if ((j != 0 && sci_not_str[j - 1] != 'e' &&
                 sci_not_str[j - 1] != 'E' && flag[4] &&
                 (sci_not_str[j] == '-' || sci_not_str[j] == '+' ||
                  sci_not_str[j] == ' ')))
              j++;
            str[i] = sci_not_str[j];
          }
          i--;
        } else if ((*c == 'e' || *c == 'E') && l_size) {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long double e = va_arg(factor, long double);
          int sign = 0, add_s = 0, num_length = 0;
          char sci_not_str[LEN];
          s21_memset(sci_not_str, 0, LEN);
          sign_checker_l_d(&e, &sign, &add_s, flag);
          s21_scientific_notation(sci_not_str, e, *c, wight, flag);
          num_length = s21_strlen(sci_not_str) + add_s;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, 0);
          s21_adding_accur(sci_not_str, accur_str, flag, sign);
          s21_adding_wight(sci_not_str, format_str, flag, add_s);
          for (int j = 0; sci_not_str[j] != '\0'; j++, i++) {
            if ((j != 0 && sci_not_str[j - 1] != 'e' &&
                 sci_not_str[j - 1] != 'E' && flag[4] &&
                 (sci_not_str[j] == '-' || sci_not_str[j] == '+' ||
                  sci_not_str[j] == ' ')))
              j++;
            str[i] = sci_not_str[j];
          }
          i--;
        } else if (*c == 'f' && !l_size) {
          int sign = 0, num_length = 0, add_s = 0, temp = 0, j = 0;
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          double f = va_arg(factor, double);
          char str_from_float[500];
          s21_memset(str_from_float, 0, 500);
          sign_checker_float(&f, &sign, &add_s, flag);
          f_creator(str_from_float, f, wight, flag, &temp);
          num_length = s21_strlen(str_from_float) + add_s;
          if (!flag[6]) num_length = s21_strlen(str_from_float) + add_s;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, temp);
          s21_adding_accur(str_from_float, accur_str, flag, sign);
          s21_adding_wight(str_from_float, format_str, flag, add_s);
          for (; str_from_float[j] != '\0'; j++, i++) {
            if (j != 0 && flag[4] &&
                (str_from_float[j] == '-' || str_from_float[j] == '+' ||
                 str_from_float[j] == ' '))
              j++;
            str[i] = str_from_float[j];
          }
          i--;
        } else if (*c == 'f' && l_size) {
          int sign = 0, num_length = 0, add_s = 0, temp = 0, j = 0;
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long double f = va_arg(factor, long double);
          char str_from_float[500];
          s21_memset(str_from_float, 0, 500);
          sign_checker_l_d(&f, &sign, &add_s, flag);
          f_creator(str_from_float, f, wight, flag, &temp);
          num_length = s21_strlen(str_from_float) + add_s;
          if (!flag[6]) num_length = s21_strlen(str_from_float) + add_s;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, temp);
          s21_adding_accur(str_from_float, accur_str, flag, sign);
          s21_adding_wight(str_from_float, format_str, flag, add_s);
          for (; str_from_float[j] != '\0'; j++, i++) {
            if (j != 0 && flag[4] &&
                (str_from_float[j] == '-' || str_from_float[j] == '+' ||
                 str_from_float[j] == ' '))
              j++;
            str[i] = str_from_float[j];
          }
          i--;
        } else if (*c == 'o' || *c == 'x' || *c == 'X' || *c == 'u') {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long int o = va_arg(factor, unsigned long int);
          if (l_size == 1)
            o = (unsigned short)o;
          else if (l_size == 0)
            o = (unsigned int)o;
          char str_from_int[LEN];
          s21_memset(str_from_int, 0, LEN);
          if (o)
            s21_notation_convertor(o, str_from_int, *c);
          else {
            str_from_int[0] = '0';
            str_from_int[1] = '\0';
            flag[3] = 0;
          }
          if (flag[5] && !o && !wight[1]) str_from_int[0] = '\0';
          int num_length = s21_strlen(str_from_int);
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 0, *c, 0);
          s21_adding_accur(str_from_int, accur_str, flag, 1);
          s21_adding_wight(str_from_int, format_str, flag, 0);
          for (int j = 0; str_from_int[j] != '\0'; j++, i++)
            str[i] = str_from_int[j];
          i--;
        } else if ((*c == 'g' || *c == 'G') && l_size) {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long double g = va_arg(factor, long double);
          int sign = 0, num_length = 0, add_s = 0, temp = 0;
          char sci_not_str[LEN];
          s21_memset(sci_not_str, 0, LEN);
          sign_checker_l_d(&g, &sign, &add_s, flag);
          s21_scientific_notation(sci_not_str, g, *c, wight, flag);
          if (flag[10]) {
            // if (flag[10] == 1)
            //   flag[10] -= 1;
            wight[1] -= flag[10] + 1;
            f_creator(sci_not_str, g, wight, flag, &temp);
          }
          num_length = s21_strlen(sci_not_str) + add_s;
          wight[1] = 0;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, 0);
          s21_adding_accur(sci_not_str, accur_str, flag, sign);
          s21_adding_wight(sci_not_str, format_str, flag, add_s);
          if (*c == 'G') {
            char *a = s21_strchr(sci_not_str, 'e');
            if (a) a[0] = 'E';
          }
          for (int j = 0; sci_not_str[j] != '\0'; j++, i++) {
            if ((j != 0 && sci_not_str[j - 1] != 'e' &&
                 sci_not_str[j - 1] != 'E' && flag[4] &&
                 (sci_not_str[j] == '-' || sci_not_str[j] == '+' ||
                  sci_not_str[j] == ' ')))
              j++;
            str[i] = sci_not_str[j];
          }
          i--;
        } else if ((*c == 'g' || *c == 'G') && !l_size) {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          double g = va_arg(factor, double);
          int sign = 0, num_length = 0, add_s = 0, temp = 0;
          char sci_not_str[LEN];
          s21_memset(sci_not_str, 0, LEN);
          sign_checker_float(&g, &sign, &add_s, flag);
          s21_scientific_notation(sci_not_str, g, *c, wight, flag);
          if (flag[10]) {
            // if (flag[10] == 1)
            //   flag[10] -= 1;
            wight[1] -= flag[10] + 1;
            f_creator(sci_not_str, g, wight, flag, &temp);
          }
          num_length = s21_strlen(sci_not_str) + add_s;
          wight[1] = 0;
          s21_format_str_creator(wight, format_str, accur_str, flag, num_length,
                                 add_s, *c, 0);
          s21_adding_accur(sci_not_str, accur_str, flag, sign);
          s21_adding_wight(sci_not_str, format_str, flag, add_s);
          if (*c == 'G') {
            char *a = s21_strchr(sci_not_str, 'e');
            if (a) a[0] = 'E';
          }
          for (int j = 0; sci_not_str[j] != '\0'; j++, i++) {
            if ((j != 0 && sci_not_str[j - 1] != 'e' &&
                 sci_not_str[j - 1] != 'E' && flag[4] &&
                 (sci_not_str[j] == '-' || sci_not_str[j] == '+' ||
                  sci_not_str[j] == ' ')))
              j++;
            str[i] = sci_not_str[j];
          }
          i--;
        } else if (*c == 'p') {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          long long int p = va_arg(factor, long long int);
          char str_from_int[80];
          s21_memset(str_from_int, 0, 80);
          if (p)
            s21_notation_convertor(p, str_from_int, *c);
          else {
            str_from_int[0] = '0';
            str_from_int[1] = '\0';
          }
          if (flag[5] && !p && !wight[1]) str_from_int[0] = '\0';
          int str_length = s21_strlen(str_from_int);
          s21_format_str_creator(wight, format_str, accur_str, flag, str_length,
                                 0, 'x', 0);
          s21_adding_accur(str_from_int, accur_str, flag, 1);
          s21_adding_wight(str_from_int, format_str, flag, 0);
          for (int j = 0; str_from_int[j] != '\0'; j++, i++)
            str[i] = str_from_int[j];
          i--;
        } else if (*c == 's') {
          int j = 0, size = 0, str_length = 0;
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          char *s = va_arg(factor, char *);
          if (!s)
            size = 6;
          else
            size = (int)s21_strlen(s);
          char str_tempory[size + LEN];
          s21_memset(str_tempory, 0, size + LEN);
          if (!s) {
            char *null_s = "(null)";
            if (!flag[5])
              s21_strcpy(str_tempory, null_s);
            else {
              for (; j < wight[1] && null_s[j] != '\0'; j++)
                str_tempory[j] = null_s[j];
              str_tempory[j] = '\0';
            }
          } else {
            if (!flag[5])
              s21_strcpy(str_tempory, s);
            else {
              for (; j < wight[1] && s[j] != '\0'; j++) str_tempory[j] = s[j];
              str_tempory[j] = '\0';
            }
          }
          wight[1] = 0;
          str_length = s21_strlen(str_tempory);
          s21_format_str_creator(wight, format_str, accur_str, flag, str_length,
                                 0, *c, 0);
          s21_adding_wight(str_tempory, format_str, flag, 0);
          for (int j = 0; str_tempory[j] != '\0'; j++, i++)
            str[i] = str_tempory[j];
          i--;
        } else if (*c == 'n') {
          if (flag[7]) wight[0] = va_arg(factor, int);
          if (flag[8]) wight[1] = va_arg(factor, int);
          int *position = va_arg(factor, int *);
          *position = i;
          i--;
        }
      } else {
        if (flag[7]) wight[0] = va_arg(factor, int);
        if (flag[8]) wight[1] = va_arg(factor, int);
        char str_for_c[LEN];
        s21_memset(str_for_c, 0, LEN);
        s21_format_str_creator(wight, format_str, accur_str, flag, 1, 0, *c, 0);
        str_for_c[0] = *c;
        str_for_c[1] = '\0';
        s21_adding_wight(str_for_c, format_str, flag, 0);
        for (int j = 0; str_for_c[j] != '\0'; j++, i++) str[i] = str_for_c[j];
        i--;
      }
    }
  }
  str[i] = '\0';
  va_end(factor);
  return i;
}
