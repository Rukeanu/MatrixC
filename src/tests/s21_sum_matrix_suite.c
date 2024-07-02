#include "unit_tests.h"

START_TEST(s21_sum_matrix_test_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 2.9;
  matrix1.matrix[0][1] = 1.2;
  matrix1.matrix[1][0] = -4.5;
  matrix1.matrix[1][1] = 7.1;

  matrix2.matrix[0][0] = 1.1;
  matrix2.matrix[0][1] = 2.3;
  matrix2.matrix[1][0] = 3.5;
  matrix2.matrix[1][1] = -2.1;

  check.matrix[0][0] = 4.0;
  check.matrix[0][1] = 3.5;
  check.matrix[1][0] = -1.0;
  check.matrix[1][1] = 5.0;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 1;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 1;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 1;
  matrix2.matrix[1][0] = 1;
  matrix2.matrix[1][1] = 1;

  check.matrix[0][0] = 2;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 2;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = -2;
  matrix1.matrix[0][1] = -2;
  matrix1.matrix[1][0] = -2;
  matrix1.matrix[1][1] = -2;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 2;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 0;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 0;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.columns = -100;
  ck_assert_int_eq(1, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 3, &B);
  ck_assert_int_eq(2, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sum_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("4) s21_sum_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sum_matrix_test_1);
  tcase_add_test(test_core, s21_sum_matrix_test_2);
  tcase_add_test(test_core, s21_sum_matrix_test_3);
  tcase_add_test(test_core, s21_sum_matrix_test_4);
  tcase_add_test(test_core, s21_sum_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}