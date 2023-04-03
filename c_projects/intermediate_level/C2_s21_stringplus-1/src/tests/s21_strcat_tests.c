#include "s21_tests.h"

START_TEST(test_1) {
  char dest1[1] = "";
  char dest2[1] = "";
  const char *str = "";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_2) {
  char dest1[50] = "checkpls";
  char dest2[50] = "checkpls";
  const char *str = "smth else mb";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_3) {
  char dest1[50] = "checkpls";
  char dest2[50] = "checkpls";
  const char *str = "smth\0else mb";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_4) {
  char dest1[50] = "checkpls";
  char dest2[50] = "checkpls";
  const char *str = "\0";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_5) {
  char dest1[10] = "checkpls";
  char dest2[10] = "checkpls";
  const char *str = "\n\0";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_6) {
  char dest1[10] = "checkpls";
  char dest2[10] = "checkpls";
  const char *str = "";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_7) {
  char dest1[20] = "";
  char dest2[20] = "";
  const char *str = "apples";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_8) {
  char dest1[200] = "checkpls";
  char dest2[200] = "checkpls";
  const char *str =
      "applesrxdfcghjkl;[;lk;jlkfyjtdrsezexr7ct8vyuohipo'pylfdtucv";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_9) {
  char dest1[50] = "\0";
  char dest2[50] = "\0";
  const char *str = "smth else mb";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_10) {
  char dest1[50] = "check\0pls";
  char dest2[50] = "check\0pls";
  const char *str = "smth else mb";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_11) {
  char dest1[50] = "";
  char dest2[50] = "";
  const char *str = "\0";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_12) {
  char dest1[50] = "\0";
  char dest2[50] = "\0";
  const char *str = "";
  s21_strcat(dest1, str);
  strcat(dest2, str);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_strcat_suite(void) {
  Suite *suite = suite_create("s21_strcat");
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
  tcase_add_test(test_core, test_11);
  tcase_add_test(test_core, test_12);

  suite_add_tcase(suite, test_core);

  return suite;
}
