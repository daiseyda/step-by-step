#include "s21_tests.h"

START_TEST(n_test_1) {
  int n1 = 0, n2 = 0;
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, "The string %n", &n1);
  int res2 = sprintf(str2, "The string %n", &n2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n_test_2) {
  int n1 = 0, n2 = 0;
  int d = 12344;
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, "The number %d the string %n", d, &n1);
  int res2 = sprintf(str2, "The number %d the string %n", d, &n2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n_test_3) {
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  int d = 12344;
  char str[] = "it's a string";
  char str1[180], str2[180];
  int res1 =
      s21_sprintf(str1, "The number %d the %n string %s %n", d, &n1, str, &n3);
  int res2 =
      sprintf(str2, "The number %d the %n string %s %n", d, &n2, str, &n4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
}
END_TEST

Suite *s21_sprintf_n_suite(void) {
  Suite *suite = suite_create("s21_sprintf_n");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, n_test_1);
  tcase_add_test(test_core, n_test_2);
  tcase_add_test(test_core, n_test_3);
  suite_add_tcase(suite, test_core);
  return suite;
}
