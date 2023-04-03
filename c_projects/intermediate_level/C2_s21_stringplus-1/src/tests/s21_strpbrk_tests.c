#include "s21_tests.h"

// Empty string tests

START_TEST(test_empty_string) {
  char *str1 = "\0";
  char *str2 = "abc";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_2) {
  char *str1 = "\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_3) {
  char *str1 = " \n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_4) {
  char *str1 = " \n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_5) {
  char *str1 = " \n\0";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_6) {
  char *str1 = " \0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_7) {
  char *str1 = " \0";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_8) {
  char *str1 = "\n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_9) {
  char *str1 = "\n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_10) {
  char *str1 = "   \0";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_11) {
  char *str1 = "";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_12) {
  char *str1 = "";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_13) {
  char *str1 = "";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_14) {
  char *str1 = " ";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_15) {
  char *str1 = " ";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_16) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_empty_string_17) {
  char *str1 = " ";
  char *str2 = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// Valid values tests

START_TEST(test_1) {
  char *str1 = "abcdefghijkl";
  char *str2 = "ghi";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_2) {
  char *str1 = "abcdefghijkl";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_3) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = "b";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_4) {
  char *str1 = "xxxxxxxxxxxxxxxa";
  char *str2 = "cba";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_5) {
  char *str1 = "xxxxxxxxxxxxxxxa";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_6) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_7) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz\n\0";
  char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_8) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz\n\0";
  char *str2 = "\n";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_9) {
  char *str1 = "\0abcdefghijklmnopqrstuvwxyz";
  char *str2 = "a";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_10) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = "7";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_11) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = "ccc";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_12) {
  char *str1 = "yyyyyyyyyyyyyyy";
  char *str2 = "tyr";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_13) {
  char *str1 = "yyyyyyyyyyyyyyy";
  char *str2 = "y";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_14) {
  char *str =
      "qWOdYDYIOuygZHh8BOIqx5vqI2yuhjnLPWuxXhaCZGm0kFllmSiJCwuqwrvGwQ9bAIhlToIZ"
      "eLvfMkb7TC7sF9exJb5vMoqEVmmPyGtIEguDzoQbK2a0YRZRqQ1q3sqmrAmEhghJQHWvuFLD"
      "dXnLiQaY4vIhhzV3Bv8OnzWdTtzTk325o9y0J6eirLujWCRrLzp4wRyXDg2DjsYrMLcxcywW"
      "I5y6fK4lG5yV3bgJLPkX3WjKyiFMANqUPsUFVNJ3GxfDBxskmyOYIPeI3Vt6Wo61NQJS3pcf"
      "7VQakDcVH2Wxi7nvru6zzRMTSwC2nYeb5KqlZ9J9xFcHkCPixIFbpN5CMwmEPti2C1KU01Ip"
      "1ftNv2lu7HJDNewBfse8jWBPsdrRolUWJf734YAv6nicsebsTU9NU13pZpUHdLnjval8CtYi"
      "pktpI62P54IR1qbjL0yJbuCTDszD70GPiI18yAV6N60It461SyYFtrqzy7X1PHLCxAVrAdyv"
      "6phn5tLKLaMCxon6kGJs85D4YG1nJEfxBq8Iy2KgmQMOxwqnLrvu39pDyUeQOuhZK5LqBakl"
      "gsy6tnxzHy8wA4SDZepiJIewIhQOaaMtw3dtpEHuaBy2Wxx8bKkj5gowS80G29fW7pr3ic5N"
      "3P0vf4Ef5jKEPK8e5M0D7Macn4OIpuIEK5S8XZRk5t4d2AZDcSiUAJkjoRwUsTRAXD50kVlL"
      "YaRxd9P0T7B9B1NbbQxfwKQYQKrDfWwmY5VlUfPJO8U9hqRBMdekF9f1Bt6Bb50gaIIzZcPe"
      "3YrijL9Ih0fZFuVGcP622QXp0VqlKwgRtVnszub46i1k4oYCn587mJB6P8FdnUBFAHfEsoAR"
      "jVcUxQg4OkgOfPKQZJhl48EZ9HnRalzckJ8S2uis7NlYTsusq8rP3sCO0GqSmuJxYtLbLO6D"
      "cf3yAdAcWYx3MTnXO4j749WR669WQTyYrYLWTILAC435kIjWfcrGbATfmj5DWaXbDkI4f4lK"
      "ssYW8B3o9tOjyMkG\0";
  int ch = '5';
  ck_assert_ptr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test_15) {
  char *str1 = "z";
  char *str2 = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_16) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = "z";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_17) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *suite = suite_create("s21_strpbrk");

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

  suite_add_tcase(suite, test_core);

  return suite;
}
