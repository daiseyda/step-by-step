#include "s21_tests.h"

START_TEST(s_test_1) {
  char thestr1[] = "I'm a string";
  char fstr[] = "The string is %s";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, thestr1);
  int res2 = sprintf(str2, fstr, thestr1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_2) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char fstr[] = "The string is %s and another is %s";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, thestr1, thestr2);
  int res2 = sprintf(str2, fstr, thestr1, thestr2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_3) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char thestr3[] = "string";
  char fstr[] = "The string is %5s, another is %14s and other is %20s";
  char str1[100], str2[100];
  int res1 = s21_sprintf(str1, fstr, thestr1, thestr2, thestr3);
  int res2 = sprintf(str2, fstr, thestr1, thestr2, thestr3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_4) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char thestr3[] = "string";
  char fstr[] = "The string is %5.5s, another is %.14s and other is %20.1s";
  char str1[100], str2[100];
  int res1 = s21_sprintf(str1, fstr, thestr1, thestr2, thestr3);
  int res2 = sprintf(str2, fstr, thestr1, thestr2, thestr3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_5) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char thestr3[] = "string";
  char fstr[] = "The string is %-5s, another is %-14s and other is %-20s";
  char str1[100], str2[100];
  int res1 = s21_sprintf(str1, fstr, thestr1, thestr2, thestr3);
  int res2 = sprintf(str2, fstr, thestr1, thestr2, thestr3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_6) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char thestr3[] = "string";
  char fstr[] = "The string is %05s, another is %014s and other is %020s";
  char str1[100], str2[100];
  int res1 = s21_sprintf(str1, fstr, thestr1, thestr2, thestr3);
  int res2 = sprintf(str2, fstr, thestr1, thestr2, thestr3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_7) {
  char thestr1[] = "I'm a string";
  char thestr2[] = "also a string";
  char thestr3[] = "string";
  int w1 = 5, w2 = 14, w3 = 20;
  char fstr[] = "The string is %*s, another is %.*s and other is %*.*s";
  char str1[100], str2[100];
  int res1 = s21_sprintf(str1, fstr, w1, thestr1, w2, thestr2, w1, w3, thestr3);
  int res2 = sprintf(str2, fstr, w1, thestr1, w2, thestr2, w1, w3, thestr3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_s_suite(void) {
  Suite *suite = suite_create("s21_sprintf_s");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, s_test_1);
  tcase_add_test(test_core, s_test_2);
  tcase_add_test(test_core, s_test_3);
  tcase_add_test(test_core, s_test_4);
  tcase_add_test(test_core, s_test_5);
  tcase_add_test(test_core, s_test_6);
  tcase_add_test(test_core, s_test_7);

  suite_add_tcase(suite, test_core);
  return suite;
}
