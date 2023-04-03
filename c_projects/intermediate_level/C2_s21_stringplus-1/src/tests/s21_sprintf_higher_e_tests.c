#include "s21_tests.h"

START_TEST(higher_e_test_1) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %E another one is %E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_2) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %6E another one is %.6E and third %6.8E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_3) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %-6E another one is %-.6E and third %-6.8E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_4) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %+6E another one is %+.6E and third %+6.8E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_5) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is % 6E another one is % .6E and third % 6.8E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_6) {
  double num1 = 34567689., num2 = -34567689.245367;
  char fstr[] = "The number is %#E another one is %#E and third %#0.0E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_7) {
  double num1 = 34567689.245367, num2 = -34567689.245367;
  char fstr[] = "The number is %06E another one is %00.6E and third %06.8E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num1);
  int res2 = sprintf(str2, fstr, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_9) {
  double num1 = 34567689.245367, num2 = 345.67689245367;
  char fstr[] = "The number is %20E another one is %20E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_10) {
  double num1 = 34567689.245367, num2 = .34567689245367;
  char fstr[] = "The number is %20E another one is %20E";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2);
  int res2 = sprintf(str2, fstr, num1, num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_11) {
  double num1 = -.89435776876, num2 = -.00089435776876,
         num3 = -0.000000089435774816, num4 = -0000000000000.89435776876;
  char *fstr = "One: %.E.\nAnother: %#E.\nThird: %#.E.\nFourth: %0.E.\n";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str2, fstr, num1, num2, num3, num4);
  int res2 = sprintf(str1, fstr, num1, num2, num3, num4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_e_test_12) {
  long double num = -3699999999.;
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str2, str3, num, num, num, num, num);
  int res2 = sprintf(str1, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_higher_e_suite(void) {
  Suite *suite = suite_create("s21_sprintf_higher_e");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, higher_e_test_1);
  tcase_add_test(test_core, higher_e_test_2);
  tcase_add_test(test_core, higher_e_test_3);
  tcase_add_test(test_core, higher_e_test_4);
  tcase_add_test(test_core, higher_e_test_5);
  tcase_add_test(test_core, higher_e_test_6);
  tcase_add_test(test_core, higher_e_test_7);
  tcase_add_test(test_core, higher_e_test_9);
  tcase_add_test(test_core, higher_e_test_10);
  tcase_add_test(test_core, higher_e_test_11);
  tcase_add_test(test_core, higher_e_test_12);

  suite_add_tcase(suite, test_core);
  return suite;
}
