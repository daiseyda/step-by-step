#include "s21_tests.h"

START_TEST(c_test_1) {
  char str[] = "abcdefABCDEF";
  char fstr[] = "%c %c %c";
  char a, b, c = 0;
  char a1, b1, c1 = 0;
  int res = s21_sscanf(str, fstr, &a, &b, &c);
  int res1 = sscanf(str, fstr, &a1, &b1, &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(c_test_2) {
  char str[] = "abcdefABCDEF";
  char fstr[] = "%c %*c %c %c";
  char a, b, c = 0;
  char a1, b1, c1 = 0;
  int res = s21_sscanf(str, fstr, &a, &b, &c);
  int res1 = sscanf(str, fstr, &a1, &b1, &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(res, res1);
}

START_TEST(c_test_3) {
  char str[] = "\x0e\x41\x71\x0f";
  char fstr[] = "%lc";
  wchar_t a, a1 = 0;
  int res = s21_sscanf(str, fstr, &a);
  int res1 = sscanf(str, fstr, &a1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(res, res1);
}

START_TEST(c_test_4) {
  char str[] = "abcdefABCDEF";
  char fstr[] = "%c %*c %c %c   ";
  char a, b, c = 0;
  char a1, b1, c1 = 0;
  int res = s21_sscanf(str, fstr, &a, &b, &c);
  int res1 = sscanf(str, fstr, &a1, &b1, &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(res, res1);
}

START_TEST(c_test_5) {
  char str[] = "ab";
  char fstr[] = "%c %*c %c %c";
  char a = 0, b = 0, c = 0;
  char a1 = 0, b1 = 0, c1 = 0;
  int res = s21_sscanf(str, fstr, &a, &b, &c);
  int res1 = sscanf(str, fstr, &a1, &b1, &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(res, res1);
}

START_TEST(c_test_6) {
  char fstr[] = "%c %% %c %c";
  char str[] = "a %% bc";
  char a = 0, b = 0, c = 0;
  char a1 = 0, b1 = 0, c1 = 0;
  int res = s21_sscanf(str, fstr, &a, &b, &c);
  int res1 = sscanf(str, fstr, &a1, &b1, &c1);

  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(res, res1);
}

START_TEST(c_test_7) {
  char fstr[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1 = 0, c2 = 0;
  int res1 = s21_sscanf(str, fstr, &c1);
  int res2 = sscanf(str, fstr, &c2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_8) {
  char fstr[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char a = 0, a1 = 0;
  int res1 = s21_sscanf(str, fstr, &a);
  int res2 = sscanf(str, fstr, &a1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_9) {
  char fstr[] = "%c%c%c";
  char str[] = "\t\n\n  5874 \n  \t";
  char a = 0, a1 = 0, b = 0, b1 = 0, c = 0, c1 = 0;
  int res1 = s21_sscanf(str, fstr, &a, &b, &c);
  int res2 = sscanf(str, fstr, &a1, &b1, &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_14) {
  char str[] = "abcd";
  char fstr[] = "%c%c%c%c";
  int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, num1 = 0, num2 = 5;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(c_test_15) {
  char str[] = "%";
  char fstr[] = "%%";
  int a1 = 0, a2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, num1 = 0, num2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, num1 = 0, num2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, num1 = 0, num2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &num1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &num2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sscanf_chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

// ========= s specificator tests =========

START_TEST(s_test_1) {
  char str[] = "abcdefg";
  char format[] = "%s";
  char a[8] = "\0";
  char a1[8] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_2) {
  char str[] = "abcdefg hijklmno";
  char format[] = "%s";
  char a[17] = "\0";
  char a1[17] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_3) {
  char str[] = "abcdefg\nhijklmno";
  char format[] = "%s";
  char a[17] = "\0";
  char a1[17] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_4) {
  char str[] = "\nabcdefg\nhijklmno";
  char format[] = "%s";
  char a[17] = "\0";
  char a1[17] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_5) {
  char str[] = "abcdefg hijklmno";
  char format[] = "%*s %s";
  char a[17] = "\0";
  char a1[17] = "\0";
  char b[17] = "\0";
  char b1[17] = "\0";
  int res1 = s21_sscanf(str, format, a, b);
  int res2 = sscanf(str, format, a1, b1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_str_eq((char *)b, (char *)b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_6) {
  char str[] = "abcdefg hijklmno";
  char format[] = "%*s";
  char a[17] = "\0";
  char a1[17] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_7) {
  char str[] = "abcdefg hijklmno";
  char format[] = "%*s";
  char a[17] = "\0";
  char a1[17] = "\0";
  char b[17] = "\0";
  char b1[17] = "\0";
  int res1 = s21_sscanf(str, format, a, b);
  int res2 = sscanf(str, format, a1, b1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s_test_8) {
  char str[] = "abcdefg hijklmno\n prstuvw";
  char format[] = "%*s";
  char a[17] = "\0";
  char a1[17] = "\0";
  int res1 = s21_sscanf(str, format, a);
  int res2 = sscanf(str, format, a1);
  ck_assert_str_eq((char *)a, (char *)a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// ======= p tests ===============

START_TEST(sscanf_spec_p_1) {
  char fstr[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char fstr[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char fstr[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char fstr[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char fstr[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  char fstr[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  char fstr[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  char fstr[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  char fstr[] = "%5p";
  char str[] = "0x237481";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  char fstr[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  char fstr[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  char fstr[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  char fstr[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  char fstr[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &p1);
  int16_t res2 = sscanf(str, fstr, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

// Empty values

START_TEST(sscanf_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_4) {
  char format[] = "%d";
  char str[] = "\t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_text_suite(void) {
  Suite *suite = suite_create("s21_sscanf_text");
  TCase *test_core = tcase_create("core");

  tcase_add_test(test_core, sscanf_special_symbols_as_chars1);
  tcase_add_test(test_core, sscanf_special_symbols_as_chars2);
  tcase_add_test(test_core, sscanf_special_symbols_as_chars3);

  tcase_add_test(test_core, sscanf_chars_flags1);
  tcase_add_test(test_core, sscanf_chars_flags2);
  tcase_add_test(test_core, sscanf_chars_flags3);
  tcase_add_test(test_core, sscanf_chars_flags4);
  tcase_add_test(test_core, sscanf_chars_flags5);
  tcase_add_test(test_core, sscanf_chars_aster1);
  tcase_add_test(test_core, sscanf_chars_aster2);
  tcase_add_test(test_core, c_test_1);
  tcase_add_test(test_core, c_test_2);
  tcase_add_test(test_core, c_test_3);
  tcase_add_test(test_core, c_test_4);
  tcase_add_test(test_core, c_test_5);
  tcase_add_test(test_core, c_test_6);
  tcase_add_test(test_core, c_test_7);
  tcase_add_test(test_core, c_test_8);
  tcase_add_test(test_core, c_test_9);
  tcase_add_test(test_core, c_test_14);
  tcase_add_test(test_core, c_test_15);
  tcase_add_test(test_core, sscanf_only_chars3);
  tcase_add_test(test_core, sscanf_only_chars5);
  tcase_add_test(test_core, sscanf_special_symbols_as_chars1);
  tcase_add_test(test_core, sscanf_special_symbols_as_chars2);
  tcase_add_test(test_core, sscanf_special_symbols_as_chars3);

  tcase_add_test(test_core, sscanf_chars_flags1);
  tcase_add_test(test_core, sscanf_chars_flags2);
  tcase_add_test(test_core, sscanf_chars_flags3);
  tcase_add_test(test_core, sscanf_chars_flags4);
  tcase_add_test(test_core, sscanf_chars_flags5);
  tcase_add_test(test_core, sscanf_chars_aster1);
  tcase_add_test(test_core, sscanf_chars_aster2);

  tcase_add_test(test_core, s_test_1);
  tcase_add_test(test_core, s_test_2);
  tcase_add_test(test_core, s_test_3);
  tcase_add_test(test_core, s_test_4);
  tcase_add_test(test_core, s_test_5);
  tcase_add_test(test_core, s_test_6);
  tcase_add_test(test_core, s_test_7);
  tcase_add_test(test_core, s_test_8);

  tcase_add_test(test_core, sscanf_spec_p_1);
  tcase_add_test(test_core, sscanf_spec_p_2);
  tcase_add_test(test_core, sscanf_spec_p_3);
  tcase_add_test(test_core, sscanf_spec_p_4);
  tcase_add_test(test_core, sscanf_spec_p_5);
  tcase_add_test(test_core, sscanf_spec_p_6);
  tcase_add_test(test_core, sscanf_spec_p_7);
  tcase_add_test(test_core, sscanf_spec_p_8);
  tcase_add_test(test_core, sscanf_spec_p_10);
  tcase_add_test(test_core, sscanf_spec_p_11);
  tcase_add_test(test_core, sscanf_spec_p_12);
  tcase_add_test(test_core, sscanf_spec_p_13);
  tcase_add_test(test_core, sscanf_spec_p_14);
  tcase_add_test(test_core, sscanf_spec_p_15);

  // Empty values

  tcase_add_test(test_core, sscanf_empty_1);
  tcase_add_test(test_core, sscanf_empty_2);
  tcase_add_test(test_core, sscanf_empty_3);
  tcase_add_test(test_core, sscanf_empty_4);
  tcase_add_test(test_core, sscanf_empty_5);

  suite_add_tcase(suite, test_core);
  return suite;
}
