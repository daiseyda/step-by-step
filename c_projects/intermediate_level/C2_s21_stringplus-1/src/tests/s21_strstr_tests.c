#include "s21_tests.h"

// Empty string tests

START_TEST(test_empty_string) {
  char *str1 = "\0";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_2) {
  char *str1 = " ";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_3) {
  char *str1 = "test";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_4) {
  char *str1 = "test";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_5) {
  char *str1 = "test";
  char *str2 = "";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_6) {
  char *str1 = "";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_7) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_8) {
  char *str1 = " ";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_9) {
  char *str1 = "\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_10) {
  char *str1 = "test\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_11) {
  char *str1 = "test\n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_12) {
  char *str1 = "test\n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_13) {
  char *str1 = "\0test\n\0";
  char *str2 = "es";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_14) {
  char *str1 = "test\n";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_15) {
  char *str1 = " \n";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_16) {
  char *str1 = " \n";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_17) {
  char *str1 = "   ";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_18) {
  char *str1 = "\n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_19) {
  char *str1 = "\n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_20) {
  char *str1 = " \n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_21) {
  char *str1 = " \n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_22) {
  char *str1 = " \n\0";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_23) {
  char *str1 = " \n\0";
  char *str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_24) {
  char *str1 = " \n\0";
  char *str2 = " \n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_empty_string_25) {
  char *str1 = "\n\0";
  char *str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

// Valid values tests

START_TEST(test_1) {
  char *str1 = "abcdefghijkl";
  char *str2 = "cde";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_2) {
  char *str1 = "abcdfghijklcderstuv";
  char *str2 = "cde";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_3) {
  char *str1 = "test";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_4) {
  char *str1 = "Test";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_5) {
  char *str1 = "Testtest";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_6) {
  char *str1 = "TesttesT";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_7) {
  char *str1 = "TEST";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_8) {
  char *str1 = "test";
  char *str2 = "TEST";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_9) {
  char *str1 = "t e s t";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_10) {
  char *str1 = "test";
  char *str2 = "t e s t";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_11) {
  char *str1 = "t e s t";
  char *str2 = "t e s t";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_12) {
  char *str1 = "0123456789";
  char *str2 = "0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_13) {
  char *str1 = "0123456789";
  char *str2 = "9";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_14) {
  char *str1 = "test ";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_15) {
  char *str1 = "test";
  char *str2 = "test ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_16) {
  char *str1 = " test";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_17) {
  char *str1 = "test";
  char *str2 = " test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_18) {
  char *str1 = " test ";
  char *str2 = " test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_19) {
  char *str1 = " test ";
  char *str2 = " test ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_20) {
  char *str1 = " test ";
  char *str2 = "test ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_21) {
  char *str1 = "test";
  char *str2 = "tset";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_22) {
  char *str1 = "testtesttesttest";
  char *str2 = "test";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_23) {
  char *str1 = "test";
  char *str2 = "testtest";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_24) {
  char *str1 = "test*test";
  char *str2 = "*";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_25) {
  char *str1 = "\0tester";
  char *str2 = "est";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *suite = suite_create("s21_strstr");

  TCase *test_core = tcase_create("core");

  // Empty string tests
  tcase_add_test(test_core, test_empty_string);
  tcase_add_test(test_core, test_empty_string_2);
  tcase_add_test(test_core, test_empty_string_3);
  tcase_add_test(test_core, test_empty_string_4);
  tcase_add_test(test_core, test_empty_string_5);
  tcase_add_test(test_core, test_empty_string_6);
  tcase_add_test(test_core, test_empty_string_7);
  tcase_add_test(test_core, test_empty_string_8);
  tcase_add_test(test_core, test_empty_string_9);
  tcase_add_test(test_core, test_empty_string_10);
  tcase_add_test(test_core, test_empty_string_11);
  tcase_add_test(test_core, test_empty_string_12);
  tcase_add_test(test_core, test_empty_string_13);
  tcase_add_test(test_core, test_empty_string_14);
  tcase_add_test(test_core, test_empty_string_15);
  tcase_add_test(test_core, test_empty_string_16);
  tcase_add_test(test_core, test_empty_string_17);
  tcase_add_test(test_core, test_empty_string_18);
  tcase_add_test(test_core, test_empty_string_19);
  tcase_add_test(test_core, test_empty_string_20);
  tcase_add_test(test_core, test_empty_string_21);
  tcase_add_test(test_core, test_empty_string_22);
  tcase_add_test(test_core, test_empty_string_23);
  tcase_add_test(test_core, test_empty_string_24);
  tcase_add_test(test_core, test_empty_string_25);

  // Valid values tests
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

  suite_add_tcase(suite, test_core);

  return suite;
}
