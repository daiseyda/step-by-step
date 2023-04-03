#include "s21_tests.h"

START_TEST(x_test_1) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%x %x %x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_2) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%4x %4x %4x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_3) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%12x %12x %12x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_4) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%2x %2x %2x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_5) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%*x %*x %*x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_6) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%*3x %*3x %*3x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_7) {
  char str[] = "-2147483647 2147483647 +2147483647";
  char fstr[] = "%x %x %x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_8) {
  char str[] = "-1234567898765432 1234567898765432 +1234567898765432";
  char fstr[] = "%x %x %x";
  unsigned int num1 = 0, num2 = 0;
  unsigned int mun1 = 0, mun2 = 0;
  unsigned int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_9) {
  char str[] = "it's a test";
  char fstr[] = "%x";
  unsigned int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_10) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%hhx %hhx %hhx";
  unsigned char num1 = 0, num2 = 0;
  unsigned char mun1 = 0, mun2 = 0;
  unsigned char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_11) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%hx %hx %hx";
  unsigned short int num1 = 0, num2 = 0;
  unsigned short int mun1 = 0, mun2 = 0;
  unsigned short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_12) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%lx %lx %lx";
  unsigned long int num1 = 0, num2 = 0;
  unsigned long int mun1 = 0, mun2 = 0;
  unsigned long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_13) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%llx %llx %llx";
  unsigned long long int num1 = 0, num2 = 0;
  unsigned long long int mun1 = 0, mun2 = 0;
  unsigned long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_14) {
  char str[] = "-1234567898765432 1234567898765432 +1234567898765432";
  char fstr[] = "%hhx %hhx %hhx";
  unsigned char num1 = 0, num2 = 0;
  unsigned char mun1 = 0, mun2 = 0;
  unsigned char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_15) {
  char str[] = "-1234567898765432 1234567898765432 +1234567898765432";
  char fstr[] = "%hx %hx %hx";
  unsigned short int num1 = 0, num2 = 0;
  unsigned short int mun1 = 0, mun2 = 0;
  unsigned short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(x_test_16) {
//   char str[] = "-1234567898765432 1234567898765432 +1234567898765432";
//   char fstr[] = "%lx %lx %lx";
//   unsigned long int num1 = 0, num2 = 0;
//   unsigned long int mun1 = 0, mun2 = 0;
//   unsigned long int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(x_test_17) {
//   char str[] = "-1234567898765432 1234567898765432 +1234567898765432";
//   char fstr[] = "%llx %llx %llx";
//   unsigned long long int num1 = 0, num2 = 0;
//   unsigned long long int mun1 = 0, mun2 = 0;
//   unsigned long long int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(x_test_18) {
  char str[] = "-5374 14Ab 0x5874";
  char fstr[] = "%2hhx %2hhx %2hhx";
  unsigned char num1 = 0, num2 = 0;
  unsigned char mun1 = 0, mun2 = 0;
  unsigned char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_19) {
  char str[] = "-5374 5374 +0x5874";
  char fstr[] = "%2hx %2hx %2hx";
  unsigned short int num1 = 0, num2 = 0;
  unsigned short int mun1 = 0, mun2 = 0;
  unsigned short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_20) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%2lx %2lx %2lx";
  unsigned long int num1 = 0, num2 = 0;
  unsigned long int mun1 = 0, mun2 = 0;
  unsigned long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_21) {
  char str[] = "-5374 14Ab +5374";
  char fstr[] = "%2llx %2llx %2llx";
  unsigned long long int num1 = 0, num2 = 0;
  unsigned long long int mun1 = 0, mun2 = 0;
  unsigned long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_22) {
  char str[] = "-5374 5374 +0x5874";
  char fstr[] = "%*hhx %*hhx %*hhx";
  unsigned char num1 = 0, num2 = 0;
  unsigned char mun1 = 0, mun2 = 0;
  unsigned char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_23) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%*hx %*hx %*hx";
  unsigned short int num1 = 0, num2 = 0;
  unsigned short int mun1 = 0, mun2 = 0;
  unsigned short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_24) {
  char str[] = "-5374 14Ab +5274";
  char fstr[] = "%*lx %*lx %*lx";
  unsigned long int num1 = 0, num2 = 0;
  unsigned long int mun1 = 0, mun2 = 0;
  unsigned long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(x_test_25) {
  char str[] = "-5374 14Ab +0x5874";
  char fstr[] = "%*llx %*llx %*llx";
  unsigned long long int num1 = 0, num2 = 0;
  unsigned long long int mun1 = 0, mun2 = 0;
  unsigned long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_x_suite(void) {
  Suite *suite = suite_create("s21_sscanf_o");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, x_test_1);
  tcase_add_test(test_core, x_test_2);
  tcase_add_test(test_core, x_test_3);
  tcase_add_test(test_core, x_test_4);
  tcase_add_test(test_core, x_test_5);
  tcase_add_test(test_core, x_test_6);
  tcase_add_test(test_core, x_test_7);
  tcase_add_test(test_core, x_test_8);
  tcase_add_test(test_core, x_test_9);
  tcase_add_test(test_core, x_test_10);
  tcase_add_test(test_core, x_test_11);
  tcase_add_test(test_core, x_test_12);
  tcase_add_test(test_core, x_test_13);
  tcase_add_test(test_core, x_test_14);
  tcase_add_test(test_core, x_test_15);
  // tcase_add_test(test_core, x_test_16);
  // tcase_add_test(test_core, x_test_17);
  tcase_add_test(test_core, x_test_18);
  tcase_add_test(test_core, x_test_19);
  tcase_add_test(test_core, x_test_20);
  tcase_add_test(test_core, x_test_21);
  tcase_add_test(test_core, x_test_22);
  tcase_add_test(test_core, x_test_23);
  tcase_add_test(test_core, x_test_24);
  tcase_add_test(test_core, x_test_25);

  suite_add_tcase(suite, test_core);
  return suite;
}
