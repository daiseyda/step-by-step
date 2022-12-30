#include "s21_math.h"

int s21_abs(int x) {  // модуль для интовых
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {  // модуль для вещественных
  if (x < 0 || (1 / x < 0 && x == 0)) x *= -1;
  return x;
}

int s21_binare_system(int num,
                      char *binare_power) {  // перевод в двоичную систему
  char temp[100];
  int i = 0, j = 0;
  while (num) {
    temp[i] = (num % 2) + '0';
    num /= 2;
    i++;
  }
  i--;
  while (i > -1) {
    binare_power[j] = temp[i];
    i--;
    j++;
  }
  return (j);
}

long double s21_fmod(double x,
                     double y) {  // остаток операции деления с плавающей точкой
  long double result;
  long double n = s21_floor(s21_fabs(x) / s21_fabs(y));
  if (y == s21_POSITIVE_INF && x != s21_POSITIVE_INF && x != s21_NEGATIVE_INF)
    result = x;
  else {
    result = s21_fabs(x) - n * s21_fabs(y);
    if (x < 0)
      result *= -1; }
  return result;
}

long double s21_ipow(double x, int n) {  // взятие целой степени
  char binare_power[100];
  long double result = 1, temp = 1;
  int j = 0;
  int i = s21_binare_system(n, binare_power);
  while (j < i) {
    if (binare_power[j] - '0')
      temp = x;
    else
      temp = 1;
    result *= result * temp;
    j++;
  }
  if (n < 0) result = 1 / result;
  return result;
}

long double s21_sqrt(double number) {  // квадратный корень
  int i = 0;
  int power = 2;
  long double prev_y, next_y;
  if (number < 0)
    next_y = s21_NAN;
  else if (number == s21_POSITIVE_INF)
    next_y = s21_POSITIVE_INF;
  else if (1 / number < 0 || number == 0)
    next_y = number;
  else {
    next_y = number;
    do {
      prev_y = next_y;
      next_y =
          (prev_y * (power - 1) + number / s21_ipow(prev_y, power - 1)) / power;
      i++;
    } while (s21_fabs(next_y - prev_y) > EPS);
  }
  return next_y;
}

long double s21_Nth_root(double number, int power) {  // корень n-ой степени
  int i = 0;
  long double prev_y, next_y;
  if (number < 0 || number == s21_POSITIVE_INF)
    next_y = s21_NAN;
  else if (1 / number < 0 || number == 0)
    next_y = number;
  else {
    next_y = number;
    do {
      prev_y = next_y;
      next_y =
          (prev_y * (power - 1) + number / s21_ipow(prev_y, power - 1)) / power;
      i++;
    } while (s21_fabs(next_y - prev_y) > EPS);
  }
  return next_y;
}

void fractions(double fractional_part, int *numerator,
               int *denominator) {  // определение числителя и знаменателя дроби
  (*denominator) = s21_round(1.0 / fractional_part);
  while (1) {
    double value = (double)(*numerator) / (double)(*denominator);
    double diff = value - fractional_part;
    if (s21_fabs(diff) < EPS) break;
    int64_t dd;
    dd = s21_round(s21_fabs(1.0 / diff));
    (*numerator) = (*numerator) * dd + (diff < 0 ? 1 : -1) * (*denominator);
    (*denominator) *= dd;
  }
  fraction_reduction(numerator, denominator);
}

void fraction_reduction(int *numerator,
                        int *denominator) {  // сокращение дробей
  int i = *numerator, n_temp = *numerator, d_temp = *denominator;
  while (i != 1) {
    if (n_temp % i == 0 && d_temp % i == 0) {
      n_temp /= i;
      d_temp /= i;
      i = n_temp;
    } else
      i--;
  }
  *numerator = n_temp;
  *denominator = d_temp;
}

int s21_round(double num) {  // округление до целого
  int result = (int)num;
  if (num - result > s21_HALF) result += 1;
  return result;
}

long double s21_floor(double x) {  // возвращает ближайшее целое число, не
                                   // превышающее заданное значение
  long double result;
  if (x != x || x == s21_NEGATIVE_INF || x == s21_POSITIVE_INF)
    result = x;
  else {
    long long int integer = (int)x;
    double fractional_part = s21_fabs(x - integer);
    if (x < 0 && x != 0) {
      if (fractional_part > EPS) integer--;
    }
    result = (long double)integer;
    if (1 / x < 0 && x == 0) result *= -1; }
  return (result);
}

long double s21_ceil(double x) {  // возвращает ближайшее целое число, не
                                  // меньшее заданного значения
  long double result;
  if (x != x || x == s21_NEGATIVE_INF || x == s21_POSITIVE_INF || x == s21_MAX_DOUBLE)
    result = x;
  else {
    int integer = (int)x;
    double fractional_part = x - integer;
    if (x > 0) {
      if (fractional_part > EPS) integer++;
    }
    result = (long double)integer;
    if (x < 0 && x > -1)  // делаем -0
      result *= -1; }
  return (result);
}

long int s21_factorial(int x) {
  long int result = 1;
  for (int i = 2; i <= x; i++) result *= i;
  return (result);
}

long double s21_exp(double power) {  // не работает с отрицательными числами
  int minus_flag = 0, sign = 1, i = 1;
  long double prev = 0;
  long double result = 1;
  if (power < 0 && power != s21_NEGATIVE_INF && power > -20) {
    minus_flag = 1;
    power = s21_fabs(power); }
  if (power != power)
    result = s21_NAN;
  else if (power == 0.0)
    result = 1;
  else if (power > 709 || power == s21_POSITIVE_INF)
    result = s21_POSITIVE_INF;
  else if (power < -19.0 || power == s21_NEGATIVE_INF) {
    result = 0; }
  else {
    prev = power / i;
    i++;
    do {
      if (minus_flag && i % 2 == 0)
        sign = -1;
      else
        sign = 1;
      result += sign * prev;
      prev *= power / i;
      i++;
    } while (prev > EPS);
  }
  return (result);
}

long double s21_pow(double num, double power) {
    long double result;
    int sign = 1;
    if (num < 0 && power == s21_ceil(power)) {
      num = s21_fabs(num); 
      if ((int)s21_fabs(s21_ceil(power))%2 == 1)
        sign = -1; }
    if ((num != num && power != 0) || (power != power && num !=1)) // 
        result = s21_NAN;
    else if (num == 0 && power > 0)
        result = 0;
    else if (s21_fabs(num) == 1 || power == 0)
        result = 1;
    else if (num == 0 && power < 0 || ((num < 1 && num > 0) && power == -s21_POSITIVE_INF))
        result = s21_POSITIVE_INF;
    else if (num > 1 && power == s21_POSITIVE_INF || (num == -s21_POSITIVE_INF && power > 0)) 
        result = s21_POSITIVE_INF;
    else if (num != 1 && power == s21_NEGATIVE_INF || (num == s21_POSITIVE_INF && power < 0) || (num < 1 && power == s21_POSITIVE_INF))
        result = 0;
    else if (num == s21_NEGATIVE_INF && power < 0)
        result = -0.0;
    else {
        if (power == s21_ceil(power)) {
          result = s21_ipow(num, power); }
        else
          result = s21_exp(power*s21_log(num));
        if (sign < 0)
          result *= -1;  }
    return(result);
}

long double s21_arifm(long double x, long double y) {  // среднее арифметическое
  return ((x + y) / 2);
}

long double s21_geomrtic(long double x,
                         long double y) {  // среднее геометрическое
  return (s21_sqrt(x * y));
}

long double s21_arifm_geomrtic(
    long double x, long double y) {  // среднее арифметическо-геометрическое
  long double temp_x = x;
  for (int i = 0; i < 8; i++) {
    x = s21_arifm(x, y);
    y = s21_geomrtic(temp_x, y);
    temp_x = x;
  }
  return (x);
}

long double s21_log(double x) {  // натуральный логарифм
  long double result, b, s, a = 1;
  int m = 16;
  if (x == 0)
    result = s21_NEGATIVE_INF;
  else if (x < 0)
    result = s21_NAN;
  else if (x == s21_POSITIVE_INF)
    result = s21_POSITIVE_INF;
  else {
    s = x * s21_ipow(2, m);
    b = 4.0 / s;
    result = s21_M_PI / (2 * s21_arifm_geomrtic(a, b)) - m * s21_LN_2;
  }
  return result;
}


long double s21_sin(double x)
{
  if (x == s21_POSITIVE_INF || x != x || x == s21_NEGATIVE_INF)
  {
    return s21_NAN;
  }

  long double value = (x > 6.28319 || x < 0) ? radian_contraction(x) : x;
  long double b = value, result = b;
  int n = 1, flag = -1;
  while (s21_fabs(b) > EPS)
  {
    n++;
    b = b * value / n;
    if (n % 2 != 0)
    {
      result += (b * flag);
      flag *= -1;
    }
  }
  return result;
}

long double radian_contraction(double value)
{
  long double result = value;
  while (result > 6.28319 || result < 0)
  {
    result = result < 0 ? result + s21_M_PI * 2 : result - s21_M_PI * 2;
  }
  return result;
}

long double s21_cos(double x)
{
  if (x == s21_POSITIVE_INF || x != x || x == s21_NEGATIVE_INF)
  {
    return s21_NAN;
  }
  long double prev, result = 1;
  long double value = (x > 6.28319 || x < 0) ? radian_contraction(x) : x;
  int i = 2;
  prev = -(value * value) / 2;
  do
  {
    result += prev;
    prev *= -1 * (value * value) / ((i + 1) * (i + 2));
    i += 2;
  } while (s21_fabs(prev) > EPS);
  return (result);
}

long double s21_tan(double x)
{
  if (x == s21_POSITIVE_INF || x != x || x == s21_NEGATIVE_INF)
  {
    return s21_NAN;
  }
  long double value = (x > 6.28319 || x < 0) ? radian_contraction(x) : x;
  long double sin = s21_sin(value);
  long double cos = s21_cos(value);
  return sin / cos;
}

long double s21_atan(double x)
{
  if (x == s21_NAN)
  {
    return s21_NAN;
  }

  int sta = 0, sp = 0;
  double x2, a;
  if (x < 0)
  {
    x = -x;
    sta |= 1;
  }
  if (x > 1)
  {
    x = 1 / x;
    sta |= 2;
  }
  while (x > s21_M_PI / 12)
  {
    sp++;
    a = x + s21_sqrt(3);
    a = 1 / a;
    x *= s21_sqrt(3);
    x -= 1;
    x *= a;
  }
  x2 = x * x;
  a = x2 + 1.4087812;
  a = 0.55913709 / a;
  a += 0.60310579;
  a -= 0.05160454 * x2;
  a *= x;
  while (sp > 0)
  {
    a += s21_M_PI / 6;
    sp--;
  }
  if (sta & 2)
    a = s21_M_PI / 2 - a;
  if (sta & 1)
    a = -a;
  return a;
}

long double s21_asin(double x)
{
  if (x == s21_POSITIVE_INF || x != x || x == s21_NEGATIVE_INF)
  {
    return s21_NAN;
  }
  return s21_atan(x / s21_sqrt(1 - x * x));
}

long double s21_acos(double x)
{
  if (x == s21_POSITIVE_INF || x != x || x == s21_NEGATIVE_INF)
  {
    return s21_NAN;
  }
  return 2 * s21_asin(s21_sqrt((1 - x) / 2));
}