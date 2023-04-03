#include "s21_tests.h"

START_TEST(i_test_1) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%i %i %i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_2) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%4i %4i %4i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_3) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%12i %12i %12i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_4) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%2i %2i %2i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_5) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*i %*i %*i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_6) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*3i %*3i %*3i";
  int num1 = 0, num2 = 0;
  int mun1 = 0, mun2 = 0;
  int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(i_test_7) {
//   char str[] = "-2147C483f647 2147483647 +02147483647";
//   char fstr[] = "%i %i %i";
//   int num1 = 0, num2 = 0;
//   int mun1 = 0, mun2 = 0;
//   int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(i_test_8) {
//   char str[] = "-1234567898765432 01234567123765432 +0X1234567D898765432e";
//   char fstr[] = "%i %i %i";
//   int num1 = 0, num2 = 0;
//   int mun1 = 0, mun2 = 0;
//   int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(i_test_9) {
  char str[] = "it's a test";
  char fstr[] = "%i";
  int num1 = 0, num2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1);
  int res2 = sscanf(str, fstr, &num2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_10) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%hhi %hhi %hhi";
  char num1 = 0, num2 = 0;
  char mun1 = 0, mun2 = 0;
  char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_11) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%hi %hi %hi";
  short int num1 = 0, num2 = 0;
  short int mun1 = 0, mun2 = 0;
  short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_12) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%li %li %li";
  long int num1 = 0, num2 = 0;
  long int mun1 = 0, mun2 = 0;
  long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_13) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%lli %lli %lli";
  long long int num1 = 0, num2 = 0;
  long long int mun1 = 0, mun2 = 0;
  long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(i_test_14) {
//   char str[] = "-1234567898765432 01234567123765432 +0X1234567D898765432e";
//   char fstr[] = "%hhi %hhi %hhi";
//   char num1 = 0, num2 = 0;
//   char mun1 = 0, mun2 = 0;
//   char umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(i_test_15) {
//   char str[] = "-1234567898765432 01234567123765432 +0X1234567D898765432e";
//   char fstr[] = "%hi %hi %hi";
//   short int num1 = 0, num2 = 0;
//   short int mun1 = 0, mun2 = 0;
//   short int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(i_test_16) {
//   char str[] = "-1234567898765432 01234567123765432 +0X1234567D898765432e";
//   char fstr[] = "%li %li %li";
//   long int num1 = 0, num2 = 0;
//   long int mun1 = 0, mun2 = 0;
//   long int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

// START_TEST(i_test_17) {
//   char str[] = "-1234567898765432 01234567123765432 +0X1234567D898765432e";
//   char fstr[] = "%lli %lli %lli";
//   long long int num1 = 0, num2 = 0;
//   long long int mun1 = 0, mun2 = 0;
//   long long int umn1 = 0, umn2 = 0;
//   int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
//   int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

//   ck_assert_int_eq(num1, num2);
//   ck_assert_int_eq(mun1, mun2);
//   ck_assert_int_eq(umn1, umn2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(i_test_18) {
  char str[] = "-5374 0X14Ab 05274";
  char fstr[] = "%2hhi %2hhi %2hhi";
  char num1 = 0, num2 = 0;
  char mun1 = 0, mun2 = 0;
  char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_19) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%2hi %2hi %2hi";
  short int num1 = 0, num2 = 0;
  short int mun1 = 0, mun2 = 0;
  short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_20) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%2li %2li %2li";
  long int num1 = 0, num2 = 0;
  long int mun1 = 0, mun2 = 0;
  long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_21) {
  char str[] = "-5374 0X14Ab +5374";
  char fstr[] = "%2lli %2lli %2lli";
  long long int num1 = 0, num2 = 0;
  long long int mun1 = 0, mun2 = 0;
  long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_22) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*hhi %*hhi %*hhi";
  char num1 = 0, num2 = 0;
  char mun1 = 0, mun2 = 0;
  char umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_23) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*hi %*hi %*hi";
  short int num1 = 0, num2 = 0;
  short int mun1 = 0, mun2 = 0;
  short int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_24) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*li %*li %*li";
  long int num1 = 0, num2 = 0;
  long int mun1 = 0, mun2 = 0;
  long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(i_test_25) {
  char str[] = "-5374 0X14Ab +05274";
  char fstr[] = "%*lli %*lli %*lli";
  long long int num1 = 0, num2 = 0;
  long long int mun1 = 0, mun2 = 0;
  long long int umn1 = 0, umn2 = 0;
  int res1 = s21_sscanf(str, fstr, &num1, &mun1, &umn1);
  int res2 = sscanf(str, fstr, &num2, &mun2, &umn2);

  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(mun1, mun2);
  ck_assert_int_eq(umn1, umn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_i_suite(void) {
  Suite *suite = suite_create("s21_sscanf_i");
  TCase *test_core = tcase_create("core");
  tcase_add_test(test_core, i_test_1);
  tcase_add_test(test_core, i_test_2);
  tcase_add_test(test_core, i_test_3);
  tcase_add_test(test_core, i_test_4);
  tcase_add_test(test_core, i_test_5);
  tcase_add_test(test_core, i_test_6);
  // tcase_add_test(test_core, i_test_7);
  // tcase_add_test(test_core, i_test_8);
  tcase_add_test(test_core, i_test_9);
  tcase_add_test(test_core, i_test_10);
  tcase_add_test(test_core, i_test_11);
  tcase_add_test(test_core, i_test_12);
  tcase_add_test(test_core, i_test_13);
  // tcase_add_test(test_core, i_test_14);
  // tcase_add_test(test_core, i_test_15);
  // tcase_add_test(test_core, i_test_16);
  // tcase_add_test(test_core, i_test_17);
  tcase_add_test(test_core, i_test_18);
  tcase_add_test(test_core, i_test_19);
  tcase_add_test(test_core, i_test_20);
  tcase_add_test(test_core, i_test_21);
  tcase_add_test(test_core, i_test_22);
  tcase_add_test(test_core, i_test_23);
  tcase_add_test(test_core, i_test_24);
  tcase_add_test(test_core, i_test_25);

  suite_add_tcase(suite, test_core);
  return suite;
}
