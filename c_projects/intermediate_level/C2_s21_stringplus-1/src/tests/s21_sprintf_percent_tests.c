#include "s21_tests.h"

START_TEST(percent_test_1) {
  const char fstr[] = "The string %%";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr);
  int res2 = sprintf(str2, fstr);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(percent_test_2) {
  int d = 12344;
  char fstr[] = "The number %d %%%%";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, d);
  int res2 = sprintf(str2, fstr, d);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(percent_test_3) {
  int d = 12344;
  char fstr[] = "The number %%%%%d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, d);
  int res2 = sprintf(str2, fstr, d);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_percent_suite(void) {
  Suite *suite = suite_create("s21_sprintf_percent");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, percent_test_1);
  tcase_add_test(test_core, percent_test_2);
  tcase_add_test(test_core, percent_test_3);
  suite_add_tcase(suite, test_core);
  return suite;
}
