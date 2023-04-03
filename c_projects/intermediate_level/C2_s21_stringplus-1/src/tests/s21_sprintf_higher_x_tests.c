#include "s21_tests.h"

START_TEST(higher_x_test_1) {
  int num1 = 0X58A74;
  char fstr[] = "The number is %X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1);
  int res2 = sprintf(str2, fstr, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_2) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] = "The number is %X and another one is %X and the third is %X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_3) {
  long int num1 = 0X58a743456789, num2 = 0X45B678C909876543,
           num3 = 0X242223456789;
  char fstr[] = "The number is %lX and another one is %lX and the third is %lX";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_4) {
  short int num1 = 0X58a, num2 = 0X45B, num3 = 0X24;
  char fstr[] = "The number is %hX and another one is %hX and the third is %hX";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_5) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is %3X and another one is %8X and the third is %10X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_6) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is %3.2X and another one is %.8X and the third is %10.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_7) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is %-3.2X and another one is %-.8X and the third is %-10.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_8) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is %+3.2X and another one is %+.8X and the third is %+10.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_9) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is %03.2X and another one is %0.8X and the third is %010.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_10) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  char fstr[] =
      "The number is % 3.2X and another one is % .8X and the third is % 10.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(higher_x_test_11) {
  int num1 = 0X58a74, num2 = 0X45B678C9, num3 = 0X2422;
  int w1 = 3, w2 = 8, w3 = 10;
  char fstr[] =
      "The number is %*.*X and another one is %.*X and the third is %*.X";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, w2, num1, w2, num2, w3, num3);
  int res2 = sprintf(str2, fstr, w1, w2, num1, w2, num2, w3, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_higher_x_suite(void) {
  Suite *suite = suite_create("s21_sprintf_higher_x");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, higher_x_test_1);
  tcase_add_test(test_core, higher_x_test_2);
  tcase_add_test(test_core, higher_x_test_3);
  tcase_add_test(test_core, higher_x_test_4);
  tcase_add_test(test_core, higher_x_test_5);
  tcase_add_test(test_core, higher_x_test_6);
  tcase_add_test(test_core, higher_x_test_7);
  tcase_add_test(test_core, higher_x_test_8);
  tcase_add_test(test_core, higher_x_test_9);
  tcase_add_test(test_core, higher_x_test_10);
  tcase_add_test(test_core, higher_x_test_11);

  suite_add_tcase(suite, test_core);
  return suite;
}
