#include "s21_tests.h"

START_TEST(test_1) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_2) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_3) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_4) {
  const char *str1 = "";
  const char *str2 = "check\0pls";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_5) {
  const char *str1 = "";
  const char *str2 = "check\0pls";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_6) {
  const char *str1 = "";
  const char *str2 = "check\0pls";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_7) {
  const char *str1 = "checkpls";
  const char *str2 = "check\0pls";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_8) {
  const char *str1 = "checkpls";
  const char *str2 = "check\0pls";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_9) {
  const char *str1 = "checkpls";
  const char *str2 = "check\0pls";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_10) {
  const char *str1 = "checkpls";
  const char *str2 = "\0check\0pls";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_11) {
  const char *str1 = "checkpls";
  const char *str2 = "\0check\0pls";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_12) {
  const char *str1 = "checkpls";
  const char *str2 = "\0check\0pls";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_13) {
  const char *str1 = "checkpls";
  const char *str2 = "checkpls";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_14) {
  const char *str1 = "checkpls";
  const char *str2 = "checkpls";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_15) {
  const char *str1 = "checkpls";
  const char *str2 = "checkpls";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_16) {
  const char *str1 = "checkpls";
  const char *str2 = "checkpls";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_17) {
  const char *str1 = "checkplszooergkerpowkerl;3p4o-gik5hj0-3ko[lpwe];";
  const char *str2 = "checkpls";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_18) {
  const char *str1 = "checkplszooergkerpowkerl;3p4o-gik5hj0-3ko[lpwe];";
  const char *str2 = "checkpls";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_19) {
  const char *str1 = "checkplszooergkerpowkerl;3p4o-gik5hj0-3ko[lpwe];";
  const char *str2 = "checkpls";
  s21_size_t n = 48;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_20) {
  const char *str1 = "checkplszooergkerpowkerl;3p4o-gik5hj0-3ko[lpwe];";
  const char *str2 = "checkpls";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_21) {
  const char *str1 = "";
  const char *str2 = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_22) {
  const char *str1 = "";
  const char *str2 = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_23) {
  const char *str1 = "";
  const char *str2 = "\0";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_24) {
  const char *str1 = " ";
  const char *str2 = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_25) {
  const char *str1 = " ";
  const char *str2 = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_26) {
  const char *str1 = " ";
  const char *str2 = "\0";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_27) {
  const char *str1 = " ";
  const char *str2 = "\0";
  s21_size_t n = 5000;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_28) {
  const char *str1 = "\n\0 ";
  const char *str2 = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_29) {
  const char *str1 = "\n\0 ";
  const char *str2 = "\0";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_30) {
  const char *str1 = "checkpls";
  const char *str2 = "cheCkpls";
  s21_size_t n = 9;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *suite = suite_create("s21_strncmp");
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
  tcase_add_test(test_core, test_13);
  tcase_add_test(test_core, test_14);
  tcase_add_test(test_core, test_15);
  tcase_add_test(test_core, test_16);
  tcase_add_test(test_core, test_17);
  tcase_add_test(test_core, test_18);
  tcase_add_test(test_core, test_19);
  tcase_add_test(test_core, test_20);
  tcase_add_test(test_core, test_21);
  tcase_add_test(test_core, test_22);
  tcase_add_test(test_core, test_23);
  tcase_add_test(test_core, test_24);
  tcase_add_test(test_core, test_25);
  tcase_add_test(test_core, test_26);
  tcase_add_test(test_core, test_27);
  tcase_add_test(test_core, test_28);
  tcase_add_test(test_core, test_29);
  tcase_add_test(test_core, test_30);

  suite_add_tcase(suite, test_core);

  return suite;
}
