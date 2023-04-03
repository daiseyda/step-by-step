#include "s21_tests.h"

START_TEST(test_1) {
  char str[30] = "-?hello, world!";
  char trim_chars[] = "!?-";
  char res2[] = "hello, world";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_2) {
  char str[30] = "";
  char trim_chars[] = "";
  char *res2 = "";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_3) {
  char *str = S21_NULL;
  char trim_chars[] = "";
  char *res2 = S21_NULL;
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_4) {
  char str[30] = "!!!abcdefghij!?!";
  char trim_chars[] = "!?";
  char res2[] = "abcdefghij";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_5) {
  char str[30] = "abc";
  char trim_chars[] = "333";
  char *res2 = "abc";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_6) {
  char str[30] = "hello, world!";
  char trim_chars[] = "?!";
  char *res2 = "hello, world";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_7) {
  char *str = S21_NULL;
  char *trim_chars = S21_NULL;
  char *res2 = S21_NULL;
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_8) {
  char str[30] = "";
  char trim_chars[] = "";
  char res2[] = "";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_9) {
  char str[] = " wtf ";
  char *trim_chars = S21_NULL;
  char *res2 = " wtf ";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

START_TEST(test_10) {
  char str[] = " wtf ";
  char *trim_chars = "";
  char *res2 = " wtf ";
  char *res1 = s21_trim(str, trim_chars);
  ck_assert_pstr_eq(res2, res1);
  if (res1) free(res1);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite = suite_create("s21_trim");
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
