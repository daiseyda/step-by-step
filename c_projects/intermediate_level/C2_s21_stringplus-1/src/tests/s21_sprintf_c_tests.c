#include "s21_tests.h"

START_TEST(c_test_1) {
  char sym1 = 'g';
  int sym2 = 55;
  char fstr[] = "The first symbol is %c and the second one is %c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2);
  int res2 = sprintf(str2, fstr, sym1, sym2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_2) {
  int sym1 = 1090;
  int sym2 = -55;
  int sym3 = -1090;
  char fstr[] =
      "The first symbol is %c and the second one is %c and the third %c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2, sym3);
  int res2 = sprintf(str2, fstr, sym1, sym2, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_3) {
  int sym1 = 0;
  char sym2 = ' ';
  char sym3 = '\n';
  char fstr[] =
      "The first symbol is %c and the second one is %c and the third %c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2, sym3);
  int res2 = sprintf(str2, fstr, sym1, sym2, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_4) {
  int sym1 = 55;
  int sym2 = 'g';
  char sym3 = -55;
  char fstr[] =
      "The first symbol is %-.3c and the second one is %-5c and the third %-1c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2, sym3);
  int res2 = sprintf(str2, fstr, sym1, sym2, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_5) {
  int sym1 = 55;
  int sym2 = 'g';
  char sym3 = -55;
  int w1 = 2, w2 = 5, w3 = 1;
  char fstr[] =
      "The first symbol is %*c and the second one is %*c and the third %*c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, sym1, w2, sym2, w3, sym3);
  int res2 = sprintf(str2, fstr, w1, sym1, w2, sym2, w3, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_6) {
  char sym1 = '\0';
  char sym2 = '\t';
  char sym3 = EOF;
  char fstr[] =
      "The first symbol is %c and the second one is %c and the third %c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2, sym3);
  int res2 = sprintf(str2, fstr, sym1, sym2, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_7) {
  int sym1 = 55;
  int sym2 = 'g';
  char sym3 = -55;
  char fstr[] =
      "The first symbol is %0.3c and the second one is %05c and the third %01c";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, sym1, sym2, sym3);
  int res2 = sprintf(str2, fstr, sym1, sym2, sym3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_8) {
  char str1[80];
  char str2[80];
  char *fstr = "%c, %c: %c == %c No sense %c";
  int a = -1;
  int b = -2;
  int c = -33;
  int d = -44;
  int e = -541;
  int res1 = sprintf(str1, fstr, a, b, c, d, e);
  int res2 = s21_sprintf(str2, fstr, a, b, c, d, e);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_9) {
  char *fstr = "%c School %c School %c School %c School %c";
  int a = 11;
  int b = 20;
  int c = 1234;
  int d = 321;
  int e = 234;
  char str1[80];
  char str2[80];
  int res1 = sprintf(str1, fstr, a, b, c, d, e);
  int res2 = s21_sprintf(str2, fstr, a, b, c, d, e);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *suite = suite_create("s21_sprintf_c");
  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, c_test_1);
  tcase_add_test(test_core, c_test_2);
  tcase_add_test(test_core, c_test_3);
  tcase_add_test(test_core, c_test_4);
  tcase_add_test(test_core, c_test_5);
  tcase_add_test(test_core, c_test_6);
  tcase_add_test(test_core, c_test_7);
  tcase_add_test(test_core, c_test_8);
  tcase_add_test(test_core, c_test_9);

  suite_add_tcase(suite, test_core);
  return suite;
}
