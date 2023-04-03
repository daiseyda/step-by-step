#include "s21_tests.h"

START_TEST(o_test_1) {
  int num1 = 05374;
  char fstr[] = "The number is %o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1);
  int res2 = sprintf(str2, fstr, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_2) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] = "The number is %o and another one is %o and the third is %o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_3) {
  long int num1 = 053743456743, num2 = 0456724103676543, num3 = 24222345;
  char fstr[] = "The number is %lo and another one is %lo and the third is %lo";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_4) {
  short int num1 = 0535, num2 = 04546, num3 = 24;
  char fstr[] = "The number is %ho and another one is %ho and the third is %ho";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_5) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is %3o and another one is %8o and the third is %10o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_6) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is %3.2o and another one is %.8o and the third is %10.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_7) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is %-3.2o and another one is %-.8o and the third is %-10.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_8) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is %+3.2o and another one is %+.8o and the third is %+10.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_9) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is %03.2o and another one is %0.8o and the third is %010.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_10) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  char fstr[] =
      "The number is % 3.2o and another one is % .8o and the third is % 10.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(o_test_11) {
  int num1 = 05374, num2 = 04567241, num3 = 2422;
  int w1 = 3, w2 = 8, w3 = 10;
  char fstr[] =
      "The number is %*.*o and another one is %.*o and the third is %*.o";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, w2, num1, w2, num2, w3, num3);
  int res2 = sprintf(str2, fstr, w1, w2, num1, w2, num2, w3, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_o_suite(void) {
  Suite *suite = suite_create("s21_sprintf_o");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, o_test_1);
  tcase_add_test(test_core, o_test_2);
  tcase_add_test(test_core, o_test_3);
  tcase_add_test(test_core, o_test_4);
  tcase_add_test(test_core, o_test_5);
  tcase_add_test(test_core, o_test_6);
  tcase_add_test(test_core, o_test_7);
  tcase_add_test(test_core, o_test_8);
  tcase_add_test(test_core, o_test_9);
  tcase_add_test(test_core, o_test_10);
  tcase_add_test(test_core, o_test_11);

  suite_add_tcase(suite, test_core);
  return suite;
}
