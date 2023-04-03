#include "s21_tests.h"

START_TEST(test_1) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_2) {
  const char *str1 = "";
  const char *str2 = "check\0pls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_3) {
  const char *str1 = "checkpls";
  const char *str2 = "check\0pls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_4) {
  const char *str1 = "checkpls";
  const char *str2 = "\0check\0pls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_5) {
  const char *str1 = "checkpls";
  const char *str2 = "checkpls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_6) {
  const char *str1 = "checkplszooergkerpowkerl;3p4o-gik5hj0-3ko[lpwe];";
  const char *str2 = "checkpls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_7) {
  const char *str1 = "";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_8) {
  const char *str1 = " ";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_9) {
  const char *str1 = "\n\0 ";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_10) {
  const char *str1 = "checkpls";
  const char *str2 = "cheCkpls";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

Suite *s21_strcmp_suite(void) {
  Suite *suite = suite_create("s21_strcmp");
  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, test_1);
  tcase_add_test(test_core, test_2);
  tcase_add_test(test_core, test_3);
  tcase_add_test(test_core, test_4);
  tcase_add_test(test_core, test_5);
  tcase_add_test(test_core, test_6);
  tcase_add_test(test_core, test_7);
  tcase_add_test(test_core, test_8);
  tcase_add_test(test_core, test_9);
  tcase_add_test(test_core, test_10);

  suite_add_tcase(suite, test_core);

  return suite;
}
