#include "s21_tests.h"

START_TEST(lower_e_test_1) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %e another one is %e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_2) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %6e another one is %.6e and third %6.8e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_3) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %-6e another one is %-.6e and third %-6.8e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_4) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %+6e another one is %+.6e and third %+6.8e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_5) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is % 6e another one is % .6e and third % 6.8e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_6) {
  double num1 = 34567689., num2 = -34567689.245367;
  char fstr[] = "The number is %#e another one is %#e and third %#0.0e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_7) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %06e another one is %00.6e and third %06.8e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_9) {
  double num1 = 34567689.245367, num2 = 345.67689245367;
  char fstr[] = "The number is %20e another one is %20e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_e_test_10) {
  double num1 = 34567689.245367, num2 = .34567689245367;
  char fstr[] = "The number is %20e another one is %20e";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_lower_e_suite(void) {
  Suite *suite = suite_create("s21_sprintf_lower_e");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, lower_e_test_1);
  tcase_add_test(test_core, lower_e_test_2);
  tcase_add_test(test_core, lower_e_test_3);
  tcase_add_test(test_core, lower_e_test_4);
  tcase_add_test(test_core, lower_e_test_5);
  tcase_add_test(test_core, lower_e_test_6);
  tcase_add_test(test_core, lower_e_test_7);
  tcase_add_test(test_core, lower_e_test_9);
  tcase_add_test(test_core, lower_e_test_10);

  suite_add_tcase(suite, test_core);
  return suite;
}
