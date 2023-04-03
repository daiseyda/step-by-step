#include "s21_tests.h"

// ============ float numbers tests ========================

START_TEST(sscanf_spec_real_1) {
  char fstr[] = "%f %f %f";
  char str[] = "5874 +198 -87";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

// START_TEST(sscanf_spec_real_2) {
//   char fstr[] = "%fg %f w%fx";
//   char str[] = "75g +19.8w -87.x";
//   float num1 = 0.0;
//   float num2 = 0.0;
//   float q1 = 0.0;
//   float q2 = 0.0;
//   float z1 = 0.0;
//   float z2 = 0.0;

//   int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1);
//   int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_float_eq(num1, num2);
//   ck_assert_float_eq(q1, q2);
//   ck_assert_float_eq(z1, z2);
// }
// END_TEST

START_TEST(sscanf_spec_real_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_4) {
  char fstr[] = "%f";
  char str[] = "Nap";
  float num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1);
  int16_t res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  char fstr[] = "%f";
  char str[] = "Np";
  float num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1);
  int16_t res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_spec_real_6) {
  char fstr[] = "%f";
  char str[] = "iNd";
  float num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1);
  int16_t res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_spec_real_7) {
  char fstr[] = "%f";
  char str[] = "id";
  float num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1);
  int16_t res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_spec_real_8) {
  char fstr[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);

  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_9) {
  char fstr[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_10) {
  char fstr[] = "%*f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_11) {
  char fstr[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_12) {
  char fstr[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_13) {
  char fstr[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float num1 = 0, num2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_14) {
  char fstr[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float num1, num2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);

  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_15) {
  char fstr[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float num1, num2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_18) {
  char fstr[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float num1, num2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &num1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, fstr, &num2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(num1, num2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_19) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_20) {
  char format[] = "%Lf";
  char str[] = "123456789.123456789";
  long double a1 = 0, a2 = 0;
  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_f_suite(void) {
  Suite *suite = suite_create("s21_sscanf_f");
  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, sscanf_spec_real_1);
  // tcase_add_test(test_core, sscanf_spec_real_2);
  tcase_add_test(test_core, sscanf_spec_real_3);
  tcase_add_test(test_core, sscanf_spec_real_4);
  tcase_add_test(test_core, sscanf_spec_real_5);
  tcase_add_test(test_core, sscanf_spec_real_6);
  tcase_add_test(test_core, sscanf_spec_real_7);
  tcase_add_test(test_core, sscanf_spec_real_8);
  tcase_add_test(test_core, sscanf_spec_real_9);
  tcase_add_test(test_core, sscanf_spec_real_10);
  tcase_add_test(test_core, sscanf_spec_real_11);
  tcase_add_test(test_core, sscanf_spec_real_12);
  tcase_add_test(test_core, sscanf_spec_real_13);
  tcase_add_test(test_core, sscanf_spec_real_14);
  tcase_add_test(test_core, sscanf_spec_real_15);
  tcase_add_test(test_core, sscanf_spec_real_18);
  tcase_add_test(test_core, sscanf_spec_real_19);
  tcase_add_test(test_core, sscanf_spec_real_20);

  suite_add_tcase(suite, test_core);
  return suite;
}
