#include "s21_tests.h"

int main(void) {
  Suite *suite = s21_memcmp_suite();
  SRunner *runner = srunner_create(suite);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_add_suite(runner, s21_strcat_suite());
  srunner_add_suite(runner, s21_strerror_suite());
  srunner_add_suite(runner, s21_strncat_suite());
  srunner_add_suite(runner, s21_strncmp_suite());
  srunner_add_suite(runner, s21_strcmp_suite());
  srunner_add_suite(runner, s21_strtok_suite());
  srunner_add_suite(runner, s21_memmove_suite());
  srunner_add_suite(runner, s21_memset_suite());
  srunner_add_suite(runner, s21_strcpy_suite());
  srunner_add_suite(runner, s21_memcpy_suite());
  srunner_add_suite(runner, s21_strcspn_suite());
  srunner_add_suite(runner, s21_strlen_suite());
  srunner_add_suite(runner, s21_strncpy_suite());
  srunner_add_suite(runner, s21_strspn_suite());
  srunner_add_suite(runner, s21_strchr_suite());
  srunner_add_suite(runner, s21_strpbrk_suite());
  srunner_add_suite(runner, s21_strrchr_suite());
  srunner_add_suite(runner, s21_strstr_suite());
  srunner_add_suite(runner, s21_memchr_suite());
  srunner_add_suite(runner, s21_sscanf_text_suite());
  srunner_add_suite(runner, s21_sscanf_d_suite());
  srunner_add_suite(runner, s21_sscanf_ld_suite());
  srunner_add_suite(runner, s21_sscanf_lld_suite());
  srunner_add_suite(runner, s21_sscanf_hd_suite());
  srunner_add_suite(runner, s21_sscanf_hhd_suite());
  srunner_add_suite(runner, s21_sscanf_u_suite());
  srunner_add_suite(runner, s21_sscanf_x_suite());
  srunner_add_suite(runner, s21_sscanf_i_suite());
  srunner_add_suite(runner, s21_sscanf_o_suite());
  srunner_add_suite(runner, s21_sscanf_f_suite());
  srunner_add_suite(runner, s21_sscanf_n_suite());
  srunner_add_suite(runner, s21_sprintf_d_suite());
  srunner_add_suite(runner, s21_sprintf_i_suite());
  srunner_add_suite(runner, s21_sprintf_lower_x_suite());
  srunner_add_suite(runner, s21_sprintf_higher_x_suite());
  srunner_add_suite(runner, s21_sprintf_o_suite());
  srunner_add_suite(runner, s21_sprintf_c_suite());
  srunner_add_suite(runner, s21_sprintf_s_suite());
  srunner_add_suite(runner, s21_sprintf_u_suite());
  srunner_add_suite(runner, s21_sprintf_n_suite());
  srunner_add_suite(runner, s21_sprintf_percent_suite());
  srunner_add_suite(runner, s21_sprintf_lower_e_suite());
  srunner_add_suite(runner, s21_sprintf_higher_e_suite());
  srunner_add_suite(runner, s21_sprintf_f_suite());
  srunner_add_suite(runner, s21_sprintf_lower_g_suite());
  srunner_add_suite(runner, s21_sprintf_higher_g_suite());
  srunner_add_suite(runner, s21_sprintf_p_suite());
  srunner_add_suite(runner, s21_to_lower_suite());
  srunner_add_suite(runner, s21_to_upper_suite());
  srunner_add_suite(runner, s21_insert_suite());
  srunner_add_suite(runner, s21_trim_suite());
  srunner_run_all(runner, CK_NORMAL);

  int failed = srunner_ntests_failed(runner);

  srunner_free(runner);
  return (failed != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
