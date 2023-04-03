#include "s21_tests.h"

START_TEST(i_test_1) {
  int num = 5874;
  char fstr[] = "The number is %i";
  char str1[80] = "", str2[80] = "";
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_2) {
  int num = 5874;
  char fstr[] = "The number is %i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_3) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %i and another one is %i and the third is %i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_4) {
  long int num1 = 5874234567890, num2 = -4567899876543, num3 = +23456789098765;
  const char fstr[] =
      "The number is %li and another one is %li and the third is %li";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_5) {
  short int num1 = 5874, num2 = -489, num3 = +8653;
  char fstr[] = "The number is %hi and another one is %hi and the third is %hi";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_6) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %7i and another one is %3i and the third is %4i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_7) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %7.i and another one is %3.5i and the third is %4.1i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_8) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %.7i and another one is %.3i and the third is %.i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_9) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7i and another one is %-3.5i and the third is %-.i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_10) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %+7i and another one is %+3.5i and the third is %+.i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_11) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %0i and another one is %0.0i and the third is %07i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_12) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is % i and another one is % -3.5i and the third is % 7i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_13) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7i and another one is %-3.i and the third is %-.i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_14) {
  int num = 0;
  char fstr[] =
      "The number is %i and another one is %-3.i and the third is %+.5i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num, num, num);
  int res2 = sprintf(str2, fstr, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_15) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  int w1 = 3, w2 = 5, w3 = 4, w4 = 2;
  char fstr[] =
      "The number is %*i and another one is %*.*i and the third is %.*i";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, num1, w2, w3, num2, w4, num3);
  int res2 = sprintf(str2, fstr, w1, num1, w2, w3, num2, w4, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_i_suite(void) {
  Suite *suite = suite_create("s21_sprintf_i");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, i_test_1);
  tcase_add_test(test_core, i_test_2);
  tcase_add_test(test_core, i_test_3);
  tcase_add_test(test_core, i_test_4);
  tcase_add_test(test_core, i_test_5);
  tcase_add_test(test_core, i_test_6);
  tcase_add_test(test_core, i_test_7);
  tcase_add_test(test_core, i_test_8);
  tcase_add_test(test_core, i_test_9);
  tcase_add_test(test_core, i_test_10);
  tcase_add_test(test_core, i_test_11);
  tcase_add_test(test_core, i_test_12);
  tcase_add_test(test_core, i_test_13);
  tcase_add_test(test_core, i_test_14);
  tcase_add_test(test_core, i_test_15);

  suite_add_tcase(suite, test_core);
  return suite;
}
