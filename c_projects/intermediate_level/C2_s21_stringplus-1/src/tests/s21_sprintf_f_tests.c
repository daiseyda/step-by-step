#include "s21_tests.h"

START_TEST(f_test_1) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %f another one is %f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_2) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %6f another one is %.6f and third %6.8f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_3) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %-6f another one is %-.6f and third %-6.8f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_4) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %+6f another one is %+.6f and third %+6.8f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_5) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is % 6f another one is % .6f and third % 6.8f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_6) {
  double num1 = 34567689., num2 = -34567689.245367;
  char fstr[] = "The number is %#f another one is %#f and third %#0.0f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_7) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %06f another one is %00.6f and third %06.8f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_9) {
  double num1 = 34567689.245367, num2 = 345.67689245367;
  char fstr[] = "The number is %20f another one is %20f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_10) {
  double num1 = 34567689.245367, num2 = .34567689245367;
  char fstr[] = "The number is %20f another one is %20f";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(f_test_11) {
  long double num1 = 34567689.245367, num2 = .34567689245367;
  char fstr[] = "The number is %20Lf another one is %20Lf";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_f_suite(void) {
  Suite *suite = suite_create("s21_sprintf_f");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, f_test_1);
  tcase_add_test(test_core, f_test_2);
  tcase_add_test(test_core, f_test_3);
  tcase_add_test(test_core, f_test_4);
  tcase_add_test(test_core, f_test_5);
  tcase_add_test(test_core, f_test_6);
  tcase_add_test(test_core, f_test_7);
  tcase_add_test(test_core, f_test_9);
  tcase_add_test(test_core, f_test_10);
  tcase_add_test(test_core, f_test_11);

  suite_add_tcase(suite, test_core);
  return suite;
}
