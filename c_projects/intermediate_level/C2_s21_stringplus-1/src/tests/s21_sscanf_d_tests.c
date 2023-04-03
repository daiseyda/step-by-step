#include "s21_tests.h"

START_TEST(d_test_1) {
  char str[] = "5874";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_2) {
  char str[] = "-5874";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_3) {
  char str[] = "+5874";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_4) {
  char str[] = "-5874";
  char fstr[] = "%4d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_5) {
  char str[] = "5874";
  char fstr[] = "%4d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_6) {
  char str[] = "-5874";
  char fstr[] = "%5d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_7) {
  char str[] = "+5874";
  char fstr[] = "%5d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_8) {
  char str[] = "-5874";
  char fstr[] = "%12d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_9) {
  char str[] = "5874";
  char fstr[] = "%12d";
  int num1 = 0, num2 = 0;
  int16_t res1 = s21_sscanf(str, fstr, &num1);
  int16_t res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_10) {
  char str[] = "-5874";
  char fstr[] = "%1d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_11) {
  char str[] = "+5874";
  char fstr[] = "%1d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_12) {
  char str[] = "-5874";
  char fstr[] = "%*2d";
  int d = 0, num1 = 0;
  int res1 = s21_sscanf(str, fstr, &d);
  int res2 = sscanf(str, fstr, &num1);
  ck_assert_int_eq(d, num1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_13) {
  char str[] = "5874";
  char fstr[] = "%*d";
  int d = 0, num1 = 0;
  int res1 = s21_sscanf(str, fstr, &d);
  int res2 = sscanf(str, fstr, &num1);
  ck_assert_int_eq(d, num1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_14) {
  char str[] = "876554567";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_15) {
  char str[] = "2147483647";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_16) {
  char str[] = "-2147483647";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_17) {
  char str[] = "-1234567898765432";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_18) {
  char str[] = "46592567862856989743245859";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_19) {
  char str[] = "-46592567862856989743245859";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_20) {
  char str[] = "-46592567862856989743245859";
  char fstr[] = "%16d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_21) {
  char str[] = "-46592567862856989743245859";
  char fstr[] = "%*5d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_22) {
  char str[] = "it's a test";
  char fstr[] = "%d";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_d_suite(void) {
  Suite *suite = suite_create("s21_sscanf_d");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, d_test_1);
  tcase_add_test(test_core, d_test_2);
  tcase_add_test(test_core, d_test_3);
  tcase_add_test(test_core, d_test_4);
  tcase_add_test(test_core, d_test_5);
  tcase_add_test(test_core, d_test_6);
  tcase_add_test(test_core, d_test_7);
  tcase_add_test(test_core, d_test_8);
  tcase_add_test(test_core, d_test_9);
  tcase_add_test(test_core, d_test_10);
  tcase_add_test(test_core, d_test_11);
  tcase_add_test(test_core, d_test_12);
  tcase_add_test(test_core, d_test_13);
  tcase_add_test(test_core, d_test_14);
  tcase_add_test(test_core, d_test_15);
  tcase_add_test(test_core, d_test_16);
  tcase_add_test(test_core, d_test_17);
  tcase_add_test(test_core, d_test_18);
  tcase_add_test(test_core, d_test_19);
  tcase_add_test(test_core, d_test_20);
  tcase_add_test(test_core, d_test_21);
  tcase_add_test(test_core, d_test_22);

  suite_add_tcase(suite, test_core);
  return suite;
}
