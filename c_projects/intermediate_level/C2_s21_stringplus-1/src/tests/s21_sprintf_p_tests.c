#include "s21_tests.h"

START_TEST(p_test_1) {
  char* num1 = "0x58A74";
  char fstr[] = "The number address is %p. So...";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1);
  int res2 = sprintf(str2, fstr, num1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(p_test_2) {
  char *num1 = "0x58a743456789", *num2 = "0x45B678C909876543",
       *num3 = "0X242223456789";
  char fstr[] =
      "The number 1 address is %p and another one is %p and the third is %p";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(p_test_3) {
  char* value = "Two";
  char* fstr = "One %p Three";
  char str1[100] = "", str2[100] = "";
  int res1 = s21_sprintf(str2, fstr, value);
  int res2 = sprintf(str1, fstr, value);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(p_test_4) {
  char* value = "0p4156";
  char* value2 = "0p971";
  char* value3 = "0p88";
  char* fstr = "%p School %p School %p";
  char str1[100] = "", str2[100] = "";
  int res1 = s21_sprintf(str1, fstr, value, value2, value3);
  int res2 = sprintf(str2, fstr, value, value2, value3);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(p_test_5) {
  long int* val = (void*)3088675747383646;
  long long int* val2 = (void*)43030050305;
  unsigned short int* val3 = (void*)33600;
  unsigned char* val4 = (void*)110;
  char* fstr = "%p, %p, %p, %p";
  char str1[100];
  char str2[100];
  int res1 = s21_sprintf(str2, fstr, val, val2, val3, val4);
  int res2 = sprintf(str1, fstr, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite* s21_sprintf_p_suite(void) {
  Suite* suite = suite_create("s21_sprintf_p");
  TCase* test_core = tcase_create("core");
  tcase_add_test(test_core, p_test_1);
  tcase_add_test(test_core, p_test_2);
  tcase_add_test(test_core, p_test_3);
  tcase_add_test(test_core, p_test_4);
  tcase_add_test(test_core, p_test_5);

  suite_add_tcase(suite, test_core);
  return suite;
}
