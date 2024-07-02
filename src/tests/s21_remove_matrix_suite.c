#include "unit_tests.h"

START_TEST(s21_remove_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(2, 2, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 20, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(0, 0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(1, 1, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

Suite *s21_remove_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("2) s21_remove_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_remove_matrix_test_1);
  tcase_add_test(test_core, s21_remove_matrix_test_2);
  tcase_add_test(test_core, s21_remove_matrix_test_3);
  tcase_add_test(test_core, s21_remove_matrix_test_4);
  tcase_add_test(test_core, s21_remove_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}