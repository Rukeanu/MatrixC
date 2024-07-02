#include "unit_tests.h"

START_TEST(s21_transpose_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = -2.2;
  B.matrix[0][2] = 4.4;
  B.matrix[1][0] = 1.1;
  B.matrix[1][1] = 3.3;
  B.matrix[1][2] = -5.5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1.1;
  B.matrix[0][2] = -2.2;
  B.matrix[1][0] = 3.3;
  B.matrix[1][1] = 4.4;
  B.matrix[1][2] = -5.5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(0, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.columns = 0;
  ck_assert_int_eq(1, s21_transpose(&A, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  B.matrix[0][0] = 1;
  B.matrix[1][0] = 2;
  B.matrix[2][0] = 3;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);

  A.matrix[0][0] = 123;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 5;

  B.matrix[0][0] = 123;
  B.matrix[1][0] = 12;
  B.matrix[2][0] = 5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("8) s21_transpose");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_transpose_test_1);
  tcase_add_test(test_core, s21_transpose_test_2);
  tcase_add_test(test_core, s21_transpose_test_3);
  tcase_add_test(test_core, s21_transpose_test_4);
  tcase_add_test(test_core, s21_transpose_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}