#include "s21_tests.h"

START_TEST(higher_g_test_1) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %G another one is %G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_2) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %6G another one is %.6G and third %6.8G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_3) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %-6G another one is %-.6G and third %-6.8G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_4) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %+6G another one is %+.6G and third %+6.8G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_5) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is % 6G another one is % .6G and third % 6.8G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_6) {
  double num1 = 34567689., num2 = -34567689.245367;
  char fstr[] = "The number is %#G another one is %#G and third %#0.0G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_7) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %06G another one is %00.6G and third %06.8G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_g_test_9) {
  double num1 = 34567689.245367, num2 = 345.67689245367;
  char fstr[] = "The number is %20G another one is %20G";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_higher_g_suite(void) {
  Suite *suite = suite_create("s21_sprintf_higher_g");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, higher_g_test_1);
  tcase_add_test(test_core, higher_g_test_2);
  tcase_add_test(test_core, higher_g_test_3);
  tcase_add_test(test_core, higher_g_test_4);
  tcase_add_test(test_core, higher_g_test_5);
  tcase_add_test(test_core, higher_g_test_6);
  tcase_add_test(test_core, higher_g_test_7);
  tcase_add_test(test_core, higher_g_test_9);

  suite_add_tcase(suite, test_core);
  return suite;
}
