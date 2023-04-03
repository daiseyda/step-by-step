#include "s21_tests.h"

START_TEST(test_1) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_2) {
  int errnum = 5;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_3) {
  int errnum = 200;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_4) {
  int errnum = -15;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_5) {
  int errnum = -3000;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

// START_TEST(test_6) {
//   int errnum = -1;
//   ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
// }
// END_TEST

START_TEST(test_7) {
  int errnum = 'h';
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *suite = suite_create("s21_strerror");
  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, test_1);
  tcase_add_test(test_core, test_2);
  tcase_add_test(test_core, test_3);
  tcase_add_test(test_core, test_4);
  tcase_add_test(test_core, test_5);
  // tcase_add_test(test_core, test_6);
  tcase_add_test(test_core, test_7);

  suite_add_tcase(suite, test_core);

  return suite;
}
