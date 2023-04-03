#include "s21_tests.h"

START_TEST(test_1) {
  char str1[2] = "\0";
  char str2[2] = "\0";
  const char *delim = "/";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_2) {
  char str1[2] = "\0";
  char str2[2] = "\0";
  const char *delim = "/ ]";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_3) {
  char str1[2] = "\0";
  char str2[2] = "\0";
  const char *delim = "";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_4) {
  char str1[3] = "\n\0";
  char str2[3] = "\n\0";
  const char *delim = "/";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_5) {
  char str1[3] = "\n\0";
  char str2[3] = "\n\0";
  const char *delim = "/ ]";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_6) {
  char str1[3] = "\n\0";
  char str2[3] = "\n\0";
  const char *delim = "";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_7) {
  char str1[9] = "checkpls";
  char str2[9] = "checkpls";
  const char *delim = "/";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_8) {
  char str1[9] = "checkpls";
  char str2[9] = "checkpls";
  const char *delim = "";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_9) {
  char str1[11] = "che/ckp/ls";
  char str2[11] = "che/ckp/ls";
  const char *delim = "/";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_10) {
  char str1[11] = "che]ckp/ls";
  char str2[11] = "che]ckp/ls";
  const char *delim = "/";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_11) {
  char str1[11] = "che]ckp/ls";
  char str2[11] = "che]ckp/ls";
  const char *delim = "/]>";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_12) {
  char str1[11] = "che]ckp/ls";
  char str2[11] = "che]ckp/ls";
  const char *delim = "]>";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_13) {
  char str1[11] = "che]ckp/ls";
  char str2[11] = "che]ckp/ls";
  const char *delim = "\0";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_14) {
  char str1[11] = "che]ckp/ls";
  char str2[11] = "che]ckp/ls";
  const char *delim = "ck";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(test_15) {
  char str1[11] = "0";
  char str2[11] = "0";
  const char *delim = "0";
  char *tok1 = s21_strtok(str1, delim);
  char *tok2 = strtok(str2, delim);
  while (tok1 != S21_NULL) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(S21_NULL, delim);
    tok2 = strtok(S21_NULL, delim);
  }
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *suite = suite_create("s21_strtok");
  TCase *test_core = tcase_create("core");

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
  suite_add_tcase(suite, test_core);

  return suite;
}
