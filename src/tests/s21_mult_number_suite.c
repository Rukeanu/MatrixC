#include "unit_tests.h"

START_TEST(s21_mult_number_test_1) {
  matrix_t A = {NULL, 0, 0};
  double number = 9.234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  check.matrix[0][0] = 9.234;
  check.matrix[0][1] = 9.234;
  check.matrix[1][0] = 9.234;
  check.matrix[1][1] = 9.234;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {NULL, 0, 0};
  double number = 5.3;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = -2.23;
  A.matrix[1][0] = 3.23;
  A.matrix[1][1] = 5.123;

  check.matrix[0][0] = 5.83;
  check.matrix[0][1] = -11.819;
  check.matrix[1][0] = 17.119;
  check.matrix[1][1] = 27.1519;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {NULL, 0, 0};
  double number = 123.1234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);
  A.matrix[0][0] = 12.345;

  check.matrix[0][0] = 1519.958373;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A = {NULL, 0, 0};
  double number = 123.1234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);
  A.columns = -100;
  ck_assert_int_eq(1, s21_mult_number(&A, number, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  matrix_t A = {NULL, 0, 0};
  double number = -10;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = -12.3;
  A.matrix[0][1] = -2.23;
  A.matrix[1][0] = -1.3;
  A.matrix[1][1] = -12;

  check.matrix[0][0] = 123;
  check.matrix[0][1] = 22.3;
  check.matrix[1][0] = 13;
  check.matrix[1][1] = 120;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("6) s21_mult_number");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_number_test_1);
  tcase_add_test(test_core, s21_mult_number_test_2);
  tcase_add_test(test_core, s21_mult_number_test_3);
  tcase_add_test(test_core, s21_mult_number_test_4);
  tcase_add_test(test_core, s21_mult_number_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}