#include "s21_tests.h"

START_TEST(d_test_1) {  // в скобках название теста с его номером
  int num = 5874;  // число, которое пишем на место %d
  char fstr[] = "The number is %d";  // строка с форматом
  char str1[80] = "",
       str2[80] = "";  // строки, в которые записываем результат. Первая для
                       // нашей функции, вторая для оригинальной
  int res1 =
      s21_sprintf(str1, fstr, num);  // число, которое вернула наша функция
  int res2 =
      sprintf(str2, fstr, num);  // число, которое вернула оригинальная функция
  ck_assert_str_eq(
      str1,
      str2);  // сравниваем, что записали в строку наша и оригинальная функции.
              // Если значения равны, то ничего не выводится, если не равны, то
              // тест падает и пишет, какое значение у нас и какое у оригинала
  ck_assert_int_eq(
      res1,
      res2);  // сравниваем, что вернула наша и оригинальная функция
              // (если будем сравнивать дробные числа, то будет
              // ck_assert_float_eq и тп). Если результаты разные,
              // то оба результата выводятся при падении теста
}
END_TEST

START_TEST(d_test_2) {
  int num = 5874;
  char fstr[] = "The number is %d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_3) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %d and another one is %d and the third is %d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_4) {
  long int num1 = 5874234567890, num2 = -4567899876543, num3 = +23456789098765;
  const char fstr[] =
      "The number is %ld and another one is %ld and the third is %ld";
  char str1[180], str2[180];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_5) {
  short int num1 = 5874, num2 = -489, num3 = +8653;
  char fstr[] = "The number is %hd and another one is %hd and the third is %hd";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_6) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] = "The number is %7d and another one is %3d and the third is %4d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_7) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %7.d and another one is %3.5d and the third is %4.1d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_8) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %.7d and another one is %.3d and the third is %.d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_9) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7d and another one is %-3.5d and the third is %-.d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_10) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %+7d and another one is %+3.5d and the third is %+.d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_11) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %0d and another one is %0.0d and the third is %07d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_12) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is % d and another one is % -3.5d and the third is % 7d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_13) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  char fstr[] =
      "The number is %-7d and another one is %-3.d and the third is %-.d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num1, num2, num3);
  int res2 = sprintf(str2, fstr, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_14) {
  int num = 0;
  char fstr[] =
      "The number is %d and another one is %-3.d and the third is %+.5d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num, num, num);
  int res2 = sprintf(str2, fstr, num, num, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_15) {
  int num1 = 5874, num2 = -456789, num3 = +8653;
  int w1 = 3, w2 = 5, w3 = 4, w4 = 2;
  char fstr[] =
      "The number is %*d and another one is %*.*d and the third is %.*d";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, w1, num1, w2, w3, num2, w4, num3);
  int res2 = sprintf(str2, fstr, w1, num1, w2, w3, num2, w4, num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(d_test_16) {
  long int num = LONG_MIN;
  char fstr[] = "The number is %ld\n";
  char str1[80], str2[80];
  int res1 = s21_sprintf(str1, fstr, num);
  int res2 = sprintf(str2, fstr, num);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_d_suite(void) {
  Suite *suite = suite_create("s21_sprintf_d");
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

  suite_add_tcase(suite, test_core);
  return suite;
}
