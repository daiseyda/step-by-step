#include <check.h>
#include <math.h>
#include <unistd.h>

#include "../s21_math.h"

START_TEST(s21_pow_null) {
    long double lib_res = pow(0, 0);
    long double s21_res = s21_pow(0, 0);
    long double lib_res1 = pow(1, 0);
    long double s21_res1 = s21_pow(1, 0);
    long double lib_res2 = pow(0, 1);
    long double s21_res2 = s21_pow(0, 1);

    ck_assert_double_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_double_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_double_eq_tol(lib_res2, s21_res2, 1e-06);
}
END_TEST

START_TEST(s21_pow_one) {
    long double lib_res = pow(1, 1);
    long double s21_res = s21_pow(1, 1);

    ck_assert_double_eq_tol(lib_res, s21_res, 1e-06);
}
END_TEST

START_TEST(s21_pow_is_negative) {
    long double lib_res = pow(-1.0, 0.0);
    long double s21_res = s21_pow(-1.0, 0.0);
    long double lib_res1 = pow(1.0, -1.0);
    long double s21_res1 = s21_pow(1.0, -1.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
}
END_TEST

START_TEST(s21_pow_normal) {
    long double lib_res = pow(2.4, 5.3);
    long double s21_res = s21_pow(2.4, 5.3);
    long double lib_res1 = pow(1.6, 7.2);
    long double s21_res1 = s21_pow(1.6, 7.2);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
}
END_TEST

START_TEST(s21_pow_normal_big_mantissa) {
    long double lib_res = pow(2, 5.923747);
    long double s21_res = s21_pow(2, 5.923747);
    long double lib_res1 = pow(2, 35.923747);
    long double s21_res1 = s21_pow(2, 35.923747);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e+10);
}
END_TEST

START_TEST(s21_pow_big_exponenta) {
    long double lib_res = pow(223443.43, 5);
    long double s21_res = s21_pow(223443.43, 5);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e+26);
}
END_TEST

START_TEST(s21_pow_infinity) {
    long double lib_res = pow(s21_POSITIVE_INF, -5);
    long double s21_res = s21_pow(s21_POSITIVE_INF, -5);
    long double lib_res1 = pow(s21_NEGATIVE_INF, -5);
    long double s21_res1 = s21_pow(s21_NEGATIVE_INF, -5);
    long double lib_res2 = pow(0, -5);
    long double s21_res2 = s21_pow(0, -5);

    ck_assert_ldouble_eq(lib_res, s21_res);
    ck_assert_ldouble_eq(lib_res1, s21_res1);
    ck_assert_ldouble_eq(lib_res2, s21_res2);
}
END_TEST

START_TEST(s21_atan_first_interval) {
    long double lib_res = atan(0.0);
    long double s21_res = s21_atan(0.0);
    long double lib_res1 = atan(0.1234545);
    long double s21_res1 = s21_atan(0.1234545);
    long double lib_res2 = atan(0.2345566);
    long double s21_res2 = s21_atan(0.2345566);
    long double lib_res3 = atan(0.3446555);
    long double s21_res3 = s21_atan(0.3446555);
    long double lib_res4 = atan(0.42876546);
    long double s21_res4 = s21_atan(0.42876546);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_atan_second_interval) {
    long double lib_res = atan(0.43023223);
    long double s21_res = s21_atan(0.43023223);
    long double lib_res1 = atan(0.5);
    long double s21_res1 = s21_atan(0.5);
    long double lib_res2 = atan(0.54344773);
    long double s21_res2 = s21_atan(0.54344773);
    long double lib_res3 = atan(0.67398483);
    long double s21_res3 = s21_atan(0.67398483);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
}
END_TEST

START_TEST(s21_atan_third_interval) {
    long double lib_res = atan(0.6827646);
    long double s21_res = s21_atan(0.6827646);
    long double lib_res1 = atan(0.70348383);
    long double s21_res1 = s21_atan(.70348383);
    long double lib_res2 = atan(0.802832);
    long double s21_res2 = s21_atan(0.802832);
    long double lib_res3 = atan(0.98162716);
    long double s21_res3 = s21_atan(0.98162716);
    long double lib_res4 = atan(1.0);
    long double s21_res4 = s21_atan(1.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_atan_forth_interval) {
    long double lib_res = atan(1.18437463764);
    long double s21_res = s21_atan(1.18437463764);
    long double lib_res1 = atan(1.247374);
    long double s21_res1 = s21_atan(1.247374);
    long double lib_res2 = atan(1.393545);
    long double s21_res2 = s21_atan(1.393545);
    long double lib_res3 = atan(1.5);
    long double s21_res3 = s21_atan(1.5);
    long double lib_res4 = atan(1.6434);
    long double s21_res4 = s21_atan(1.6434);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_atan_is_negative) {
    long double lib_res = atan(-0.234);
    long double s21_res = s21_atan(-0.234);
    long double lib_res1 = atan(-0.5343);
    long double s21_res1 = s21_atan(-0.5343);
    long double lib_res2 = atan(-0.7343);
    long double s21_res2 = s21_atan(-0.7343);
    long double lib_res3 = atan(-1.5);
    long double s21_res3 = s21_atan(-1.5);
    long double lib_res4 = atan(-6);
    long double s21_res4 = s21_atan(-6);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_atan_one_neg) {
    long double lib_res = atan(-1);
    long double s21_res = s21_atan(-1);

    long double lib_res1 = atan(s21_POSITIVE_INF);
    long double s21_res1 = s21_atan(s21_POSITIVE_INF);

    long double lib_res2 = atan(s21_NEGATIVE_INF);
    long double s21_res2 = s21_atan(s21_NEGATIVE_INF);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
}
END_TEST

START_TEST(s21_fabs_is_negative) {
    long double lib_res = fabs(-0.234);
    long double s21_res = s21_fabs(-0.234);
    long double lib_res1 = fabs(-0.5343);
    long double s21_res1 = s21_fabs(-0.5343);
    long double lib_res2 = fabs(-0.7343);
    long double s21_res2 = s21_fabs(-0.7343);
    long double lib_res3 = fabs(-1.5);
    long double s21_res3 = s21_fabs(-1.5);
    long double lib_res4 = fabs(-6.0);
    long double s21_res4 = s21_fabs(-6.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_fabs_is_positive) {
    long double lib_res1 = fabs(5.0);
    long double s21_res1 = s21_fabs(5.0);
    long double lib_res2 = fabs(12324.0);
    long double s21_res2 = s21_fabs(12324.0);
    long double lib_res3 = fabs(4.232323);
    long double s21_res3 = s21_fabs(4.232323);
    long double lib_res4 = fabs(0.2323232);
    long double s21_res4 = s21_fabs(0.2323232);

    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res3, s21_res3, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res4, s21_res4, 1e-06);
}
END_TEST

START_TEST(s21_fabs_is_null) {
    long double lib_res = fabs(0.0);
    long double s21_res = s21_fabs(0.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
}
END_TEST

START_TEST(s21_exp_normal) {
    long double lib_res = exp(1.0);
    long double s21_res = s21_exp(1.0);
    long double lib_res1 = exp(2.3434);
    long double s21_res1 = s21_exp(2.3434);
    long double lib_res2 = exp(50.0);
    long double s21_res2 = s21_exp(50.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e+21);
}
END_TEST

START_TEST(s21_exp_max) {
    double max = s21_MAX_DOUBLE;
    long double lib_res = exp(max);
    long double s21_res = s21_exp(max);

    ck_assert_ldouble_eq(lib_res, s21_res);
}
END_TEST

START_TEST(s21_exp_negative) {
    long double lib_res = exp(-1.0);
    long double s21_res = s21_exp(-1.0);
    long double lib_res1 = exp(-2.3434);
    long double s21_res1 = s21_exp(-2.3434);
    long double lib_res2 = exp(-50.0);
    long double s21_res2 = s21_exp(-50.0);

    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res1, s21_res1, 1e-06);
    ck_assert_ldouble_eq_tol(lib_res2, s21_res2, 1e-06);
}
END_TEST

START_TEST(s21_exp_infinity) {
    long double lib_res = exp(s21_POSITIVE_INF);
    long double s21_res = s21_exp(s21_POSITIVE_INF);
    long double lib_res1 = exp(s21_NEGATIVE_INF);
    long double s21_res1 = s21_exp(s21_NEGATIVE_INF);

    ck_assert_ldouble_eq(lib_res, s21_res);
    ck_assert_ldouble_eq(lib_res1, s21_res1);
}
END_TEST

START_TEST(s21_abs_positive) {
    int x = 5;
    int s21_result = s21_abs(x);
    int lib_result = abs(x);

    ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_abs_negative) {
    int x = -7;
    int s21_result = s21_abs(x);
    int lib_result = abs(x);

    ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_abs_zero) {
    int x = 0;
    int s21_result = s21_abs(x);
    int lib_result = abs(x);

    ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_abs_min_int) {
    int x = -2147483648;
    int s21_result = s21_abs(x);
    int lib_result = abs(x);

    ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_ceil_positive_integer) {
    double x = 7;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_ceil_negative_integer) {
    double x = -12;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_ceil_positive_non_integer) {
    double x = 2.53;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_ceil_negative_non_integer) {
    double x = -2.476;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_ceil_nan) {
    double x = s21_NAN;
    long double s21_result = s21_ceil(x);

    ck_assert_ldouble_nan(s21_result);
}
END_TEST

START_TEST(s21_ceil_positive_infinite) {
    double x = s21_POSITIVE_INF;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_ceil_negative_infinite) {
    double x = s21_NEGATIVE_INF;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_ceil_max) {
    double x = s21_MAX_DOUBLE;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_ceil_zero) {
    double x = 0;
    long double s21_result = s21_ceil(x);
    long double lib_result = ceill(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_positive_integer) {
    double x = 7;
    long double s21_result = s21_floor(x);
    long double lib_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_negative_integer) {
    double x = -12;
    long double s21_result = s21_floor(x);
    long double lib_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_positive_non_integer) {
    double x = 2.53;
    long double s21_result = s21_floor(x);
    long double lib_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_negative_non_integer) {
    double x = -2.463;
    long double s21_result = s21_floor(x);
    long double lib_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_zero) {
    double x = 0;
    long double s21_result = s21_floor(x);
    long double lib_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_floor_nan) {
    double x = s21_NAN;
    long double s21_result = s21_floor(x);

    ck_assert_ldouble_nan(s21_result);
}
END_TEST

START_TEST(s21_floor_positive_infinite) {
    double x = s21_POSITIVE_INF;
    long double s21_result = s21_floor(x);
    long double lib_result = floorl(x);

    ck_assert_ldouble_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_floor_negative_infinite) {
    double x = s21_NEGATIVE_INF;
    long double s21_result = s21_floor(x);
    long double lib_result = floorl(x);

    ck_assert_ldouble_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_sin_zero) {
    double x = 0;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_thirty) {
    double x = 0.523598775598299;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_fourty_five) {
    double x = 0.7853981634;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_one_hundred_eighty) {
    double x = 3.14159265359;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_two_hundred_seventy) {
    double x = 4.71238898038469;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_two_thousand) {
    double x = 34.9065850398866;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_sin_ten_thousand) {
    double x = 174.532925199433;
    long double s21_result = s21_sin(x);
    long double lib_result = sin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_zero) {
    double x = 0;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_thirty) {
    double x = 0.523598775598299;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_fourty_five) {
    double x = 0.7853981634;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_one_hundred_eighty) {
    double x = 3.14159265359;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_two_hundred_seventy) {
    double x = 4.71238898038469;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_two_thousand) {
    double x = 34.9065850398866;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_ten_thousand) {
    double x = 174.532925199433;
    long double s21_result = s21_cos(x);
    long double lib_result = cos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_cos_infinity) {
    ck_assert_ldouble_nan(s21_cos(INFINITY));
    ck_assert_ldouble_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(s21_sin_inf) {
    ck_assert_ldouble_nan(s21_sin(INFINITY));
    ck_assert_ldouble_nan(s21_sin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_zero) {
    double x = 0.0;
    long double s21_result = s21_asin(x);
    long double lib_result = asin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_minus_zero) {
    double x = -0.0;
    long double s21_result = s21_asin(x);
    long double lib_result = asin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_out_of_bounds) {
    double x = -2.0;
    long double s21_result = s21_asin(x);
    ck_assert_double_nan(s21_result);

    s21_result = s21_asin(x * -1);
    ck_assert_double_nan(s21_result);
}
END_TEST

START_TEST(s21_asin_near_zero) {
    double x = -0.5;
    long double s21_result = s21_asin(x + 0.025 * _i);
    long double lib_result = asin(x + 0.025 * _i);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_neg_tail) {
    double x = -1.0;
    long double s21_result = s21_asin(x + 0.025 * _i);
    long double lib_result = asin(x + 0.025 * _i);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_tail) {
    double x = 0.5;
    long double s21_result = s21_asin(x + 0.025 * _i);
    long double lib_result = asin(x + 0.025 * _i);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_infinity) {
    ck_assert_ldouble_nan(s21_asin(INFINITY));
    ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_nan_arg) { ck_assert_ldouble_nan(s21_asin(NAN)); }
END_TEST

START_TEST(s21_asin_one) {
    double x = 1.0;
    long double lib_result = asin(x);
    long double s21_result = s21_asin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_asin_one_neg) {
    double x = -1.0;
    long double lib_result = asin(x);
    long double s21_result = s21_asin(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_acos_norm) {
    double x = -1.0;
    long double lib_result = acos(x + 0.025 * _i);
    long double s21_result = s21_acos(x + 0.025 * _i);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_acos_out_of_bounds) {
    double x = -2.0;
    long double s21_result = s21_acos(x);
    ck_assert_double_nan(s21_result);

    s21_result = s21_acos(x * -1);
    ck_assert_double_nan(s21_result);
}
END_TEST

START_TEST(s21_acos_nan_arg) { ck_assert_ldouble_nan(s21_acos(NAN)); }
END_TEST

START_TEST(s21_acos_inf) { ck_assert_ldouble_nan(s21_acos(s21_POSITIVE_INF)); }
END_TEST

START_TEST(s21_acos_inf_neg) {
    ck_assert_ldouble_nan(s21_acos(s21_NEGATIVE_INF));
}
END_TEST

START_TEST(s21_acos_one) {
    double x = 1.0;
    long double lib_result = acos(x);
    long double s21_result = s21_acos(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-6);
}
END_TEST

START_TEST(s21_log_normal_mantiss) {
    for (double i = 0.1; i <= 2.0; i += 0.00001) {
        ck_assert_ldouble_eq_tol(log(i), s21_log(i), 1e-06);
    }
}
END_TEST

START_TEST(s21_log_normal_exp) {
    for (double i = 0.1; i <= 10.0; i += 1.1) {
        ck_assert_ldouble_eq_tol(log(i), s21_log(i), 1e-06);
    }
}
END_TEST

START_TEST(s21_log_big_value) {
    long double lib_res = log(1233456.123456);
    long double s21_res = s21_log(1233456.123456);
    ck_assert_ldouble_eq_tol(lib_res, s21_res, 1e-06);
}
END_TEST

START_TEST(s21_sqrt_primitive) {
    double q = 25.00000;
    double w = 100.000000;
    double f = 10000.000000;
    double r = 1000000.000000;
    double t = 0.090000;
    double y = 0.000900;

    long double s21_result_q = s21_sqrt(q);
    long double lib_result_q = sqrt(q);
    long double s21_result_w = s21_sqrt(w);
    long double lib_result_w = sqrt(w);
    long double s21_result_e = s21_sqrt(f);
    long double lib_result_e = sqrt(f);
    long double s21_result_r = s21_sqrt(r);
    long double lib_result_r = sqrt(r);
    long double s21_result_t = s21_sqrt(t);
    long double lib_result_t = sqrt(t);
    long double s21_result_y = s21_sqrt(y);
    long double lib_result_y = sqrt(y);

    ck_assert_ldouble_eq_tol(s21_result_q, lib_result_q, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_w, lib_result_w, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_e, lib_result_e, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_r, lib_result_r, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_t, lib_result_t, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_y, lib_result_y, 1e-06);
}
END_TEST

START_TEST(s21_sqrt_infinities) {
    double q = INFINITY;
    double w = s21_NEGATIVE_INF;
    long double s21_result_q = s21_sqrt(q);
    long double lib_result_q = sqrt(q);
    long double s21_result_w = s21_sqrt(w);

    ck_assert_ldouble_eq(s21_result_q, lib_result_q);
    ck_assert_ldouble_nan(s21_result_w);
}
END_TEST

START_TEST(s21_sqrt_zero) {
    double q = 0;
    long double s21_result_q = s21_sqrt(q);
    long double lib_result_q = sqrt(q);

    ck_assert_ldouble_eq_tol(s21_result_q, lib_result_q, 1e-06);
}
END_TEST

START_TEST(s21_sqrt_negative) {
    double q = -10000.0;
    double w = -9.0;
    double f = -0.09;
    long double s21_result_q = s21_sqrt(q);
    long double s21_result_w = s21_sqrt(w);
    long double s21_result_e = s21_sqrt(f);

    ck_assert_ldouble_nan(s21_result_q);
    ck_assert_ldouble_nan(s21_result_w);
    ck_assert_ldouble_nan(s21_result_e);
}
END_TEST

START_TEST(s21_fmod_primitive) {
    double num_q = -7.25323;
    double divider_q = -3.6235;
    double num_w = 1000.43577426;
    double divider_w = 9.47437;
    double num_e = 100.2134;
    double divider_e = -4.3516;
    double num_r = -100.34;
    double divider_r = 4.3;
    long double s21_result_q = s21_fmod(num_q, divider_q);
    long double lib_result_q = fmod(num_q, divider_q);
    long double s21_result_w = s21_fmod(num_w, divider_w);
    long double lib_result_w = fmod(num_w, divider_w);
    long double s21_result_e = s21_fmod(num_e, divider_e);
    long double lib_result_e = fmod(num_e, divider_e);
    long double s21_result_r = s21_fmod(num_r, divider_r);
    long double lib_result_r = fmod(num_r, divider_r);

    ck_assert_ldouble_eq_tol(s21_result_q, lib_result_q, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_w, lib_result_w, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_e, lib_result_e, 1e-06);
    ck_assert_ldouble_eq_tol(s21_result_r, lib_result_r, 1e-06);
}
END_TEST

START_TEST(s21_fmod_crash_idea) {
    double num = 100;
    double divider = -9.5465;
    long double s21_result = s21_fmod(num, divider);
    long double lib_result = fmod(num, divider);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_fmod_infinity_war) {
    double num_q = 1.0 / 0.0;
    double divider_q = 1.0 / 0.0;
    double num_w = 1.0 / 0.0;
    double divider_w = -1.0 / 0.0;
    double num_e = -1.0 / 0.0;
    double divider_e = 1.0 / 0.0;
    double num_r = -1.0 / 0.0;
    double divider_r = -1.0 / 0.0;
    double num_t = 1.0 / 0.0;
    double divider_t = 123;
    double num_y = 123;
    double divider_y = 1.0 / 0.0;
    double num_z = 0;
    double divider_z = 0;
    long double s21_result_q = s21_fmod(num_q, divider_q);
    long double lib_result_q = fmod(num_q, divider_q);
    long double s21_result_w = s21_fmod(num_w, divider_w);
    long double lib_result_w = fmod(num_w, divider_w);
    long double s21_result_e = s21_fmod(num_e, divider_e);
    long double lib_result_e = fmod(num_e, divider_e);
    long double s21_result_r = s21_fmod(num_r, divider_r);
    long double lib_result_r = fmod(num_r, divider_r);
    long double s21_result_t = s21_fmod(num_t, divider_t);
    long double lib_result_t = fmod(num_t, divider_t);
    long double s21_result_y = s21_fmod(num_y, divider_y);
    long double lib_result_y = fmod(num_y, divider_y);
    long double s21_result_z = s21_fmod(num_z, divider_z);

    ck_assert_ldouble_nan(s21_result_q);
    ck_assert_ldouble_nan(lib_result_q);
    ck_assert_ldouble_nan(s21_result_w);
    ck_assert_ldouble_nan(lib_result_w);
    ck_assert_ldouble_nan(s21_result_e);
    ck_assert_ldouble_nan(lib_result_e);
    ck_assert_ldouble_nan(s21_result_r);
    ck_assert_ldouble_nan(lib_result_r);
    ck_assert_ldouble_nan(s21_result_t);
    ck_assert_ldouble_nan(lib_result_t);
    ck_assert_ldouble_nan(s21_result_z);
    ck_assert_ldouble_eq_tol(s21_result_y, lib_result_y, 1e-06);
}
END_TEST

START_TEST(s21_tan_zero) {
    double x = 0;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_tan_thirty) {
    double x = 0.523598775598299;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_tan_fourty_five) {
    double x = 0.7853981634;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_tan_one_hundred_eighty) {
    double x = 3.14159265359;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_tan_two_thousand) {
    double x = 34.9065850398866;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

START_TEST(s21_tan_ten_thousand) {
    double x = 174.532925199433;
    long double s21_result = s21_tan(x);
    long double lib_result = tanl(x);

    ck_assert_ldouble_eq_tol(s21_result, lib_result, 1e-06);
}
END_TEST

Suite* s21_math_suite() {
    Suite* s;
    TCase *tc_pow, *tc_atan, *tc_fabs, *tc_exp, *tc_abs, *tc_ceil, *tc_floor,
        *tc_sin, *tc_cos, *tc_asin, *tc_acos, *tc_log, *tc_fmod, *tc_sqrt,
        *tc_tan;

    s = suite_create("s21_math");

    tc_abs = tcase_create("s21_abs");
    tcase_add_test(tc_abs, s21_abs_positive);
    tcase_add_test(tc_abs, s21_abs_negative);
    tcase_add_test(tc_abs, s21_abs_zero);
    tcase_add_test(tc_abs, s21_abs_min_int);
    suite_add_tcase(s, tc_abs);

    tc_asin = tcase_create("s21_asin");
    tcase_add_test(tc_asin, s21_asin_minus_zero);
    tcase_add_test(tc_asin, s21_asin_zero);
    tcase_add_test(tc_asin, s21_asin_out_of_bounds);
    tcase_add_test(tc_asin, s21_asin_infinity);
    tcase_add_test(tc_asin, s21_asin_nan_arg);
    tcase_add_loop_test(tc_asin, s21_asin_tail, 1, 20);
    tcase_add_loop_test(tc_asin, s21_asin_neg_tail, 1, 20);
    tcase_add_loop_test(tc_asin, s21_asin_near_zero, 1, 40);
    tcase_add_test(tc_asin, s21_asin_one);
    tcase_add_test(tc_asin, s21_asin_one_neg);
    suite_add_tcase(s, tc_asin);

    tc_acos = tcase_create("s21_acos");
    tcase_add_loop_test(tc_acos, s21_acos_norm, 0, 80);
    tcase_add_test(tc_acos, s21_acos_out_of_bounds);
    tcase_add_test(tc_acos, s21_acos_nan_arg);
    tcase_add_test(tc_acos, s21_acos_inf);
    tcase_add_test(tc_acos, s21_acos_inf_neg);
    tcase_add_test(tc_acos, s21_acos_one);
    suite_add_tcase(s, tc_acos);

    tc_pow = tcase_create("s21_pow");
    tcase_add_test(tc_pow, s21_pow_null);
    tcase_add_test(tc_pow, s21_pow_one);
    tcase_add_test(tc_pow, s21_pow_is_negative);
    tcase_add_test(tc_pow, s21_pow_normal);
    tcase_add_test(tc_pow, s21_pow_big_exponenta);
    tcase_add_test(tc_pow, s21_pow_normal_big_mantissa);
    tcase_add_test(tc_pow, s21_pow_infinity);
    suite_add_tcase(s, tc_pow);

    tc_atan = tcase_create("s21_atan");
    tcase_add_test(tc_atan, s21_atan_first_interval);
    tcase_add_test(tc_atan, s21_atan_second_interval);
    tcase_add_test(tc_atan, s21_atan_third_interval);
    tcase_add_test(tc_atan, s21_atan_forth_interval);
    tcase_add_test(tc_atan, s21_atan_is_negative);
    tcase_add_test(tc_atan, s21_atan_one_neg);
    suite_add_tcase(s, tc_atan);

    tc_fabs = tcase_create("s21_fabs");
    tcase_add_test(tc_fabs, s21_fabs_is_negative);
    tcase_add_test(tc_fabs, s21_fabs_is_positive);
    tcase_add_test(tc_fabs, s21_fabs_is_null);
    suite_add_tcase(s, tc_fabs);

    tc_exp = tcase_create("s21_exp");
    tcase_add_test(tc_exp, s21_exp_normal);
    tcase_add_test(tc_exp, s21_exp_max);
    tcase_add_test(tc_exp, s21_exp_negative);
    tcase_add_test(tc_exp, s21_exp_infinity);
    suite_add_tcase(s, tc_exp);

    tc_ceil = tcase_create("s21_ceil");
    tcase_add_test(tc_ceil, s21_ceil_positive_non_integer);
    tcase_add_test(tc_ceil, s21_ceil_negative_non_integer);
    tcase_add_test(tc_ceil, s21_ceil_negative_integer);
    tcase_add_test(tc_ceil, s21_ceil_positive_integer);
    tcase_add_test(tc_ceil, s21_ceil_zero);
    tcase_add_test(tc_ceil, s21_ceil_nan);
    tcase_add_test(tc_ceil, s21_ceil_positive_infinite);
    tcase_add_test(tc_ceil, s21_ceil_negative_infinite);
    tcase_add_test(tc_ceil, s21_ceil_max);
    suite_add_tcase(s, tc_ceil);

    tc_floor = tcase_create("s21_floor");
    tcase_add_test(tc_floor, s21_floor_positive_integer);
    tcase_add_test(tc_floor, s21_floor_negative_integer);
    tcase_add_test(tc_floor, s21_floor_positive_non_integer);
    tcase_add_test(tc_floor, s21_floor_negative_non_integer);
    tcase_add_test(tc_floor, s21_floor_zero);
    tcase_add_test(tc_floor, s21_floor_nan);
    tcase_add_test(tc_ceil, s21_floor_negative_infinite);
    tcase_add_test(tc_ceil, s21_floor_positive_infinite);
    suite_add_tcase(s, tc_floor);

    tc_sin = tcase_create("s21_sin");
    tcase_add_test(tc_sin, s21_sin_zero);
    tcase_add_test(tc_sin, s21_sin_thirty);
    tcase_add_test(tc_sin, s21_sin_fourty_five);
    tcase_add_test(tc_sin, s21_sin_one_hundred_eighty);
    tcase_add_test(tc_sin, s21_sin_two_hundred_seventy);
    tcase_add_test(tc_sin, s21_sin_two_thousand);
    tcase_add_test(tc_sin, s21_sin_ten_thousand);
    tcase_add_test(tc_sin, s21_sin_inf);
    suite_add_tcase(s, tc_sin);

    tc_cos = tcase_create("s21_cos");
    tcase_add_test(tc_cos, s21_cos_zero);
    tcase_add_test(tc_cos, s21_cos_thirty);
    tcase_add_test(tc_cos, s21_cos_fourty_five);
    tcase_add_test(tc_cos, s21_cos_one_hundred_eighty);
    tcase_add_test(tc_cos, s21_cos_two_hundred_seventy);
    tcase_add_test(tc_cos, s21_cos_two_thousand);
    tcase_add_test(tc_cos, s21_cos_ten_thousand);
    tcase_add_test(tc_cos, s21_cos_infinity);
    suite_add_tcase(s, tc_cos);

    tc_log = tcase_create("s21_log");
    tcase_add_test(tc_log, s21_log_normal_mantiss);
    tcase_add_test(tc_log, s21_log_normal_exp);
    tcase_add_test(tc_log, s21_log_big_value);
    suite_add_tcase(s, tc_log);

    tc_fmod = tcase_create("s21_fmod");
    tcase_add_test(tc_fmod, s21_fmod_primitive);
    tcase_add_test(tc_fmod, s21_fmod_crash_idea);
    tcase_add_test(tc_fmod, s21_fmod_infinity_war);
    suite_add_tcase(s, tc_fmod);

    tc_sqrt = tcase_create("s21_sqrt");
    tcase_add_test(tc_sqrt, s21_sqrt_primitive);
    tcase_add_test(tc_sqrt, s21_sqrt_infinities);
    tcase_add_test(tc_sqrt, s21_sqrt_zero);
    tcase_add_test(tc_sqrt, s21_sqrt_negative);
    suite_add_tcase(s, tc_sqrt);

    tc_tan = tcase_create("s21_tan");
    tcase_add_test(tc_tan, s21_tan_zero);
    tcase_add_test(tc_tan, s21_tan_thirty);
    tcase_add_test(tc_tan, s21_tan_fourty_five);
    tcase_add_test(tc_tan, s21_tan_one_hundred_eighty);
    tcase_add_test(tc_tan, s21_tan_two_thousand);
    tcase_add_test(tc_tan, s21_tan_ten_thousand);
    suite_add_tcase(s, tc_tan);

    return s;
}

START_TEST(pow_1) {
    double num = 456.789;
    double ex = 1.1;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    ck_assert_float_eq(our_res, orig_res);
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_2) {
    double num = INFINITY;
    double ex = 1.1;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_3) {
    double num = NAN;
    double ex = 1.1;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_4) {
    double num = NAN;
    double ex = NAN;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_5) {
    double num = 0.001;
    double ex = NAN;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_6) {
    double num = INFINITY;
    double ex = INFINITY;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_7) {
    double num = INFINITY;
    double ex = INFINITY;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_8) {
    double base = -16.161435;
    double exp = 9.;
    ck_assert_float_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_9) {
    long double base = -10.1261;
    long double exp = -0.72;

    ck_assert_double_nan(pow(base, exp));
    ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
    long double base = +0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
    long double base = -0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
    long double base = -0;
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_14) {
    long double base = +0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_15) {
    long double base = -0;
    long double exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_16) {
    long double base = -0;
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_17) {
    long double base = -1;
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_18) {
    long double base = -1;
    long double exp = s21_NAN;
    ck_assert_double_nan(pow(base, exp));
    ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
    long double base = s21_NAN;
    long double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_20) {
    long double base = -123;
    long double exp = s21_NAN;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
    long double base = 0.5591951;
    long double exp = -s21_POSITIVE_INF;
    ck_assert_ldouble_infinite(pow(base, exp));
    ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
    long double base = 1.5591951;
    long double exp = -s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_23) {
    long double base = 0.5591951;
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_24) {
    long double base = 1.5591951;
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
    long double base = -s21_POSITIVE_INF;
    long double exp = -193491;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_26) {
    long double base = -s21_POSITIVE_INF;
    long double exp = -142;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_27) {
    long double base = -s21_POSITIVE_INF;
    long double exp = 141;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
    long double base = -s21_POSITIVE_INF;
    long double exp = 142;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
    long double base = s21_POSITIVE_INF;
    long double exp = -1;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_30) {
    long double base = s21_POSITIVE_INF;
    long double exp = 1;
    ck_assert_ldouble_infinite(s21_pow(base, exp));
    ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
    ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(pow_32) {
    ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
}
END_TEST

START_TEST(pow_33) {
    ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
}
END_TEST

START_TEST(pow_34) {
    ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
}
END_TEST

START_TEST(pow_35) {
    ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                             1e-6);
}
END_TEST

START_TEST(pow_36) {
    ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_38) {
    long double orig_res = pow(2.1234567e-7, -2.45e4),  // 0.000000021234567
        our_res = s21_pow(2.1234567e-7, -2.45e4);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_39) {
    ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                             pow(9.99999999e3, 9.95e-4), 1e-6);
}
END_TEST

START_TEST(pow_40) {
    long double exp = -12;
    ck_assert_ldouble_infinite(s21_pow(+0, exp));
    ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
    long double exp = -12;
    ck_assert_ldouble_infinite(s21_pow(-0, exp));
    ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
    long double exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_43) {
    long double exp = s21_NAN;
    ck_assert_double_nan(s21_pow(+0, exp));
    ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_44) {
    long double exp = 2.456;
    ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_45) {
    long double exp = -s21_POSITIVE_INF;
    ck_assert_ldouble_infinite(s21_pow(+0, exp));
    ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_46) {
    long double exp = 56;
    ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_47) {
    long double exp = 56;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_48) {
    long double exp = 56.345;
    ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_49) {
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_50) {
    long double exp = -s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_51) {
    long double exp = s21_NAN;
    ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
}
END_TEST

START_TEST(pow_52) {
    long double exp = -0;
    ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
}
END_TEST

START_TEST(pow_53) {
    long double exp = +0;
    ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
}
END_TEST

START_TEST(pow_54) {
    long double exp = -0;
    ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_55) {
    long double exp = +0;
    ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_56) {
    long double exp = s21_NAN;
    ck_assert_double_nan(s21_pow(s21_NAN, exp));
    ck_assert_double_nan(pow(s21_NAN, exp));
}
END_TEST

START_TEST(pow_57) {
    long double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_infinite(s21_pow(s21_POSITIVE_INF, exp));
    ck_assert_ldouble_infinite(pow(s21_POSITIVE_INF, exp));
}
END_TEST

START_TEST(pow_58) {
    long double exp = -s21_POSITIVE_INF;
    ck_assert_ldouble_eq_tol(s21_pow(-s21_POSITIVE_INF, exp),
                             pow(-s21_POSITIVE_INF, exp), 1e-6);
}
END_TEST

START_TEST(pow_59) {
    double exp = s21_POSITIVE_INF;
    ck_assert_ldouble_infinite(s21_pow(-s21_POSITIVE_INF, exp));
    ck_assert_ldouble_infinite(pow(-s21_POSITIVE_INF, exp));
}
END_TEST

START_TEST(pow_60) {
    double exp;
    double res1;
    long double res2;

    for (exp = 0.0; exp > -1000; exp -= 0.1) {
        res1 = pow(s21_POSITIVE_INF, exp);
        res2 = s21_pow(s21_POSITIVE_INF, exp);
    }
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_61) {
    double base;
    double res1;
    long double res2;

    for (base = 0.0; base < 10; base += 0.1) {
        res1 = pow(base, s21_POSITIVE_INF);
        res2 = s21_pow(base, s21_POSITIVE_INF);
    }
    ck_assert_ldouble_infinite(res1);
    ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
    double base;
    double res1;
    long double res2;

    for (base = 0.0; base > -10; base -= 0.1) {
        res1 = pow(base, s21_POSITIVE_INF);
        res2 = s21_pow(base, s21_POSITIVE_INF);
    }
    ck_assert_ldouble_infinite(res1);
    ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
    long double base;
    long double res1;
    long double res2;

    for (base = 0.0; base < 10; base += 0.1) {
        res1 = pow(base, -s21_POSITIVE_INF);
        res2 = s21_pow(base, -s21_POSITIVE_INF);
    }
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_64) {
    long double base;
    long double res1;
    long double res2;

    for (base = 0.0; base > -10; base -= 0.1) {
        res1 = pow(base, -s21_POSITIVE_INF);
        res2 = s21_pow(base, -s21_POSITIVE_INF);
    }
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_65) {
    double exp;
    double res1;
    long double res2;

    for (exp = 0.0; exp > -10; exp -= 0.1) {
        if (fmod(exp, 2) != 0) {
            res1 = pow(-s21_POSITIVE_INF, exp);
            res2 = s21_pow(-s21_POSITIVE_INF, exp);
        }
    }
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_66) {
    double exp;
    double res1;
    long double res2;

    for (exp = 0.0; exp > -10; exp -= 0.1) {
        if (fmod(exp, 2) == 0) {
            res1 = pow(-s21_POSITIVE_INF, exp);
            res2 = s21_pow(-s21_POSITIVE_INF, exp);
        }
    }
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_67) {
    double exp;
    double res1;
    long double res2;

    for (exp = 0.0; exp < 10; exp += 0.1) {
        if (fmod(exp, 2) != 0) {
            res1 = pow(-s21_POSITIVE_INF, exp);
            res2 = s21_pow(-s21_POSITIVE_INF, exp);
        }
    }
    ck_assert_ldouble_infinite(res1);
    ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
    double exp;
    double res1;
    long double res2;

    for (exp = 0.0; exp < 10; exp += 0.1) {
        if (fmod(exp, 2) == 0) {
            res1 = pow(-s21_POSITIVE_INF, exp);
            res2 = s21_pow(-s21_POSITIVE_INF, exp);
        }
    }
    ck_assert_ldouble_eq_tol(res2, res1, 1e-6);
}
END_TEST

START_TEST(pow_69) {
    long double exp = 3;
    ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_70) {
    long double exp = -3;
    ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_71) {
    long double exp = -3;
    ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_72) {
    long double exp = 3;
    ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_73) {
    long double base = -0;
    long double exp = s21_POSITIVE_INF;
    long double res = pow(base, exp);
    long double res1 = s21_pow(base, exp);
    ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_74) {
    long double exp;
    long double base = -0;
    long double res;
    long double res1;
    for (exp = 0.0; exp < 10; exp += 0.1) {
        if (fmod(exp, 2) != 0) {
            res = pow(base, exp);
            res1 = s21_pow(base, exp);
        }
    }
    ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_75) {
    long double base = 200;
    long double exp = 70000;
    long double res1 = s21_pow(base, exp);
    ck_assert_ldouble_infinite(res1);
}
END_TEST

START_TEST(pow_76) {
    long double base = 200;
    long double exp = -70000;
    long double res1 = s21_pow(base, exp);
    long double res = pow(base, exp);
    ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

Suite* suite_s21_pow(void) {
    Suite* s12;
    TCase* tc12;
    s12 = suite_create("s21_pow");
    tc12 = tcase_create("case_pow");

    tcase_add_test(tc12, pow_1);
    tcase_add_test(tc12, pow_2);
    tcase_add_test(tc12, pow_3);
    tcase_add_test(tc12, pow_4);
    tcase_add_test(tc12, pow_5);
    tcase_add_test(tc12, pow_6);
    tcase_add_test(tc12, pow_7);
    tcase_add_test(tc12, pow_8);
    tcase_add_test(tc12, pow_9);
    tcase_add_test(tc12, pow_10);
    tcase_add_test(tc12, pow_12);
    tcase_add_test(tc12, pow_13);
    tcase_add_test(tc12, pow_14);
    tcase_add_test(tc12, pow_15);
    tcase_add_test(tc12, pow_16);
    tcase_add_test(tc12, pow_17);
    tcase_add_test(tc12, pow_18);
    tcase_add_test(tc12, pow_19);
    tcase_add_test(tc12, pow_20);
    tcase_add_test(tc12, pow_21);
    tcase_add_test(tc12, pow_22);
    tcase_add_test(tc12, pow_23);
    tcase_add_test(tc12, pow_24);
    tcase_add_test(tc12, pow_25);
    tcase_add_test(tc12, pow_26);
    tcase_add_test(tc12, pow_27);
    tcase_add_test(tc12, pow_28);
    tcase_add_test(tc12, pow_29);
    tcase_add_test(tc12, pow_30);
    tcase_add_test(tc12, pow_31);
    tcase_add_test(tc12, pow_32);
    tcase_add_test(tc12, pow_33);
    tcase_add_test(tc12, pow_34);
    tcase_add_test(tc12, pow_35);
    tcase_add_test(tc12, pow_36);
    tcase_add_test(tc12, pow_38);
    tcase_add_test(tc12, pow_39);
    tcase_add_test(tc12, pow_40);
    tcase_add_test(tc12, pow_41);
    tcase_add_test(tc12, pow_42);
    tcase_add_test(tc12, pow_43);
    tcase_add_test(tc12, pow_44);
    tcase_add_test(tc12, pow_45);
    tcase_add_test(tc12, pow_46);
    tcase_add_test(tc12, pow_47);
    tcase_add_test(tc12, pow_48);
    tcase_add_test(tc12, pow_49);
    tcase_add_test(tc12, pow_50);
    tcase_add_test(tc12, pow_51);
    tcase_add_test(tc12, pow_52);
    tcase_add_test(tc12, pow_53);
    tcase_add_test(tc12, pow_54);
    tcase_add_test(tc12, pow_55);
    tcase_add_test(tc12, pow_56);
    tcase_add_test(tc12, pow_57);
    tcase_add_test(tc12, pow_58);
    tcase_add_test(tc12, pow_59);
    tcase_add_test(tc12, pow_60);
    tcase_add_test(tc12, pow_61);
    tcase_add_test(tc12, pow_62);
    tcase_add_test(tc12, pow_63);
    tcase_add_test(tc12, pow_64);
    tcase_add_test(tc12, pow_65);
    tcase_add_test(tc12, pow_66);
    tcase_add_test(tc12, pow_67);
    tcase_add_test(tc12, pow_68);
    tcase_add_test(tc12, pow_69);
    tcase_add_test(tc12, pow_70);
    tcase_add_test(tc12, pow_71);
    tcase_add_test(tc12, pow_72);
    tcase_add_test(tc12, pow_73);
    tcase_add_test(tc12, pow_74);
    tcase_add_test(tc12, pow_75);
    tcase_add_test(tc12, pow_76);
    suite_add_tcase(s12, tc12);
    return s12;
}

START_TEST(log_1) {
    double num = 456.789;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
    double num = NAN;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
    double num = 0.001;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
    double num = 0.4;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
    double num = -INFINITY;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
    double num = INFINITY;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));

    ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST

START_TEST(log_10) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_11) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6); }
END_TEST

START_TEST(log_12) { ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6); }
END_TEST

START_TEST(log_13) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_14) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_15) {
    ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
}
END_TEST

START_TEST(log_16) {
    ck_assert_ldouble_eq_tol(s21_log(s21_M_PI / 3), log(s21_M_PI / 3), 1e-6);
}
END_TEST

START_TEST(log_17) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                             1e-6);
}
END_TEST

START_TEST(log_18) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                             1e-6);
}
END_TEST

START_TEST(log_19) {
    ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                             1e-6);
}
END_TEST

START_TEST(log_24) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-6);
}
END_TEST

START_TEST(log_25) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-6);
}
END_TEST

START_TEST(log_26) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-6);
}
END_TEST

START_TEST(log_21) {
    ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                             log(987654321123.123e-30), 1e-6);
}
END_TEST

START_TEST(log_22) {
    ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-6);
}
END_TEST

START_TEST(log_23) {
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_infinite(log(0));
}
END_TEST

START_TEST(log_28) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-6);
}
END_TEST

START_TEST(log_30) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-6);
}
END_TEST

START_TEST(log_31) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-6);
}
END_TEST

START_TEST(log_32) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-6);
}
END_TEST

START_TEST(log_33) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-6);
}
END_TEST

Suite* suite_s21_log(void) {
    Suite* s11;
    TCase* tc11;
    s11 = suite_create("s21_log");

    tc11 = tcase_create("case_log");

    tcase_add_test(tc11, log_1);
    tcase_add_test(tc11, log_2);
    tcase_add_test(tc11, log_3);
    tcase_add_test(tc11, log_4);
    tcase_add_test(tc11, log_5);
    tcase_add_test(tc11, log_6);
    tcase_add_test(tc11, log_7);
    tcase_add_test(tc11, log_8);
    tcase_add_test(tc11, log_9);
    tcase_add_test(tc11, log_10);
    tcase_add_test(tc11, log_11);
    tcase_add_test(tc11, log_12);
    tcase_add_test(tc11, log_13);
    tcase_add_test(tc11, log_14);
    tcase_add_test(tc11, log_15);
    tcase_add_test(tc11, log_16);
    tcase_add_test(tc11, log_17);
    tcase_add_test(tc11, log_18);
    tcase_add_test(tc11, log_19);
    tcase_add_test(tc11, log_21);
    tcase_add_test(tc11, log_22);
    tcase_add_test(tc11, log_23);
    tcase_add_test(tc11, log_24);
    tcase_add_test(tc11, log_25);
    tcase_add_test(tc11, log_26);
    tcase_add_test(tc11, log_28);
    tcase_add_test(tc11, log_30);
    tcase_add_test(tc11, log_31);
    tcase_add_test(tc11, log_32);
    tcase_add_test(tc11, log_33);
    suite_add_tcase(s11, tc11);
    return s11;
}

int main() {
    int no_failed = 0;

    Suite* s = s21_math_suite();
    Suite* p = suite_s21_pow();
    Suite* l = suite_s21_log();
    SRunner* runners = srunner_create(s);
    SRunner* runnerp = srunner_create(p);
    SRunner* runnerl = srunner_create(l);
    srunner_run_all(runners, CK_NORMAL);
    srunner_run_all(runnerp, CK_NORMAL);
    srunner_run_all(runnerl, CK_NORMAL);
    no_failed = srunner_ntests_failed(runners);
    no_failed = srunner_ntests_failed(runnerp);
    no_failed = srunner_ntests_failed(runnerl);
    srunner_free(runners);
    srunner_free(runnerp);
    srunner_free(runnerl);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
