#include "s21_tests.h"

START_TEST(u_test_1) {
  unsigned int num = 5874;
  char fstr[] = "The number is %u";
  char str1[80] = "", str2[80] = "";
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_2) {
  unsigned int num = 5874;
  char fstr[] = "The number is %u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_3) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %u and another one is %u and the third is %u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_4) {
  long unsigned int num1 = 5874234567890, num2 = -4567899876543,
                    num3 = +23456789098765;
  char fstr[] = "The number is %lu and another one is %lu and the third is %lu";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_5) {
  short unsigned int num1 = 5874, num2 = -489, num3 = +8653;
  char fstr[] = "The number is %hu and another one is %hu and the third is %hu";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_6) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %7u and another one is %3u and the third is %4u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_7) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %7.u and another one is %3.5u and the third is %4.1u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_8) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %.7u and another one is %.3u and the third is %.u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_9) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7u and another one is %-3.5u and the third is %-.u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_10) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %+7u and another one is %+3.5u and the third is %+.u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_11) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %0u and another one is %0.0u and the third is %07u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_12) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is % u and another one is % -3.5u and the third is % 7u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_13) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7u and another one is %-3.u and the third is %-.u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_14) {
  unsigned int num = 0;
  char fstr[] =
      "The number is %u and another one is %-3.u and the third is %+.5u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num, num, num);
  int res2 = sprintf(str2, fstr, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(u_test_15) {
  unsigned int num1 = 5874, num2 = -456789, num3 = +8653;
  int w1 = 3, w2 = 5, w3 = 4, w4 = 2;
  char fstr[] =
      "The number is %*u and another one is %*.*u and the third is %.*u";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, num1, w2, w3, num2, w4, num3);
  int res2 = sprintf(str2, fstr, w1, num1, w2, w3, num2, w4, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_u_suite(void) {
  Suite *suite = suite_create("s21_sprintf_u");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, u_test_1);
  tcase_add_test(test_core, u_test_2);
  tcase_add_test(test_core, u_test_3);
  tcase_add_test(test_core, u_test_4);
  tcase_add_test(test_core, u_test_5);
  tcase_add_test(test_core, u_test_6);
  tcase_add_test(test_core, u_test_7);
  tcase_add_test(test_core, u_test_8);
  tcase_add_test(test_core, u_test_9);
  tcase_add_test(test_core, u_test_10);
  tcase_add_test(test_core, u_test_11);
  tcase_add_test(test_core, u_test_12);
  tcase_add_test(test_core, u_test_13);
  tcase_add_test(test_core, u_test_14);
  tcase_add_test(test_core, u_test_15);

  suite_add_tcase(suite, test_core);
  return suite;
}
