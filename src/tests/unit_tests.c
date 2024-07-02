#include "unit_tests.h"

int main(void) {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {
      s21_create_matrix_suite(),    s21_remove_matrix_suite(),
      s21_eq_matrix_suite(),        s21_sum_matrix_suite(),
      s21_sub_matrix_suite(),       s21_mult_number_suite(),
      s21_mult_matrix_suite(),      s21_transpose_suite(),
      s21_calc_complements_suite(), s21_determinant_suite(),
      s21_inverse_matrix_suite(),   NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
