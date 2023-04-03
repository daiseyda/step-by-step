#ifndef SRC_S21_TESTS_H_
#define SRC_S21_TESTS_H_
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_memcmp_suite(void);
Suite *s21_strcmp_suite(void);
Suite *s21_strcat_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memmove_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strcpy_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strspn_suite(void);
Suite *s21_memchr_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_sscanf_text_suite(void);
Suite *s21_sscanf_d_suite(void);
Suite *s21_sscanf_ld_suite(void);
Suite *s21_sscanf_lld_suite(void);
Suite *s21_sscanf_hd_suite(void);
Suite *s21_sscanf_hhd_suite(void);
Suite *s21_sscanf_u_suite(void);
Suite *s21_sscanf_x_suite(void);
Suite *s21_sscanf_i_suite(void);
Suite *s21_sscanf_o_suite(void);
Suite *s21_sscanf_f_suite(void);
Suite *s21_sscanf_n_suite(void);
Suite *s21_sprintf_d_suite(void);
Suite *s21_sprintf_i_suite(void);
Suite *s21_sprintf_lower_x_suite(void);
Suite *s21_sprintf_higher_x_suite(void);
Suite *s21_sprintf_o_suite(void);
Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_n_suite(void);
Suite *s21_sprintf_percent_suite(void);
Suite *s21_sprintf_lower_e_suite(void);
Suite *s21_sprintf_higher_e_suite(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_lower_g_suite(void);
Suite *s21_sprintf_higher_g_suite(void);
Suite *s21_sprintf_p_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_to_upper_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

#endif  //  SRC_S21_TESTS_H_
