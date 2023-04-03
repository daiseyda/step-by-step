#include "s21_tests.h"

START_TEST(test_empty_string) {
  char src[10] = "\0";
  char dest[10] = "";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_2) {
  char src[10] = "";
  char dest[10] = "";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_3) {
  char src[10] = "\n\n\n\0";
  char dest[10] = "";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_4) {
  char src[10] = "";
  char dest[10] = "\n\n\0";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_5) {
  char src[10] = "\0123";
  char dest[10] = " ";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_6) {
  char src[10] = " ";
  char dest[10] = " ";
  s21_size_t n = 1;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_7) {
  char src[10] = "\0";
  char dest[10] = "\0";
  s21_size_t n = 8;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_empty_string_8) {
  char src[10] = "12";
  char dest[10] = "";
  s21_size_t n = 0;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_1) {
  char src[11] = "1234567890";
  s21_size_t n = 3;
  char *s21_result = s21_memmove(&src[4], &src[3], n);
  char *lib_result = memmove(&src[4], &src[3], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_2) {
  char src[11] = "1234\067890";
  s21_size_t n = 3;
  char *s21_result = s21_memmove(&src[4], &src[3], n);
  char *lib_result = memmove(&src[4], &src[3], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_3) {
  char src[10] = "123\0456";
  char dest[10] = "";
  s21_size_t n = 6;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_4) {
  char src[] =
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
      "ssYW8B3o9tOjyMkG";
  s21_size_t n = 50;
  char *s21_result = s21_memmove(&src[23], &src[1], n);
  char *lib_result = memmove(&src[23], &src[1], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_5) {
  char src[50] = "sdfsfsdfsdfsdf\0";
  char dest[50] = "";
  s21_size_t n = 6;
  char *s21_result = s21_memmove(dest, src, n);
  char *lib_result = memmove(dest, src, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_6) {
  char src[20] = "as\t\t\n2\0";
  s21_size_t n = 3;
  char *s21_result = s21_memmove(&src[3], &src[3], n);
  char *lib_result = memmove(&src[3], &src[3], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_7) {
  char src[20] = "()()()";
  s21_size_t n = 5;
  char *s21_result = s21_memmove(&src[2], &src[1], n);
  char *lib_result = memmove(&src[2], &src[1], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(test_8) {
  char src[20] = "\t1\t2\t3\t4\t5\t6";
  s21_size_t n = 5;
  char *s21_result = s21_memmove(&src[2], &src[1], n);
  char *lib_result = memmove(&src[2], &src[1], n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

Suite *s21_memmove_suite(void) {
  Suite *suite = suite_create("s21_memmove");

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

  // Valid values tests
  tcase_add_test(test_core, test_1);
  tcase_add_test(test_core, test_2);
  tcase_add_test(test_core, test_3);
  tcase_add_test(test_core, test_4);
  tcase_add_test(test_core, test_5);
  tcase_add_test(test_core, test_6);
  tcase_add_test(test_core, test_7);
  tcase_add_test(test_core, test_8);

  suite_add_tcase(suite, test_core);

  return suite;
}
