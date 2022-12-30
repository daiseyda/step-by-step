#ifndef _S21_MATH_H_
#define _S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define s21_HALF 0.500000
#define EPS 0.000000001
#define s21_POSITIVE_INF 1.0 / 0.0
#define s21_MAX_DOUBLE 1.7E+308
#define s21_NAN 0.0 / 0.0
#define s21_NEGATIVE_INF -1.0 / 0.0
#define s21_M_PI 3.1415926535897932384626433832795
#define s21_LN_2 0.693147180559945309417232121458

long double s21_sqrt(double number);
long double s21_arifm(long double x, long double y);
long double s21_geomrtic(long double x, long double y);
long double s21_arifm_geomrtic(long double x, long double y);
long double s21_fabs(double x);
int s21_abs(int x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
int s21_binare_system(int num, char *binare_power);
long double s21_ipow(double x, int n);
long double s21_log(double x);
long double s21_Nth_root(double number, int power);
void fraction_reduction(int *numerator, int *denominator);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_pow(double base, double exp);
void fractions(double fractional_part, int *numerator, int *denominator);
int s21_round(double num);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double radian_contraction(double value);

#endif  // _S21_MATH_H_
