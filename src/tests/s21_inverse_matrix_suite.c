#include "unit_tests.h"

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  R.matrix[0][0] = 1;
  R.matrix[0][1] = -1;
  R.matrix[0][2] = 1;
  R.matrix[1][0] = -38;
  R.matrix[1][1] = 41;
  R.matrix[1][2] = -34;
  R.matrix[2][0] = 27;
  R.matrix[2][1] = -29;
  R.matrix[2][2] = 24;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = -34.435;
  A.matrix[0][1] = 95.45;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 6.54;
  A.matrix[1][1] = 8.6;
  A.matrix[1][2] = 9.45;
  A.matrix[2][0] = -78.4;
  A.matrix[2][1] = 35.4;
  A.matrix[2][2] = 342.55;

  R.matrix[0][0] = -0.0069366937;
  R.matrix[0][1] = 0.0937005217;
  R.matrix[0][2] = -0.0025890934;
  R.matrix[1][0] = 0.0080437096;
  R.matrix[1][1] = 0.0335349236;
  R.matrix[1][2] = -0.0009266229;
  R.matrix[2][0] = -0.0024052396;
  R.matrix[2][1] = 0.0179383578;
  R.matrix[2][2] = 0.0024283115;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(0, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_inverse_matrix(NULL, &result));
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &R);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  R.matrix[0][0] = -2;
  R.matrix[0][1] = 1;
  R.matrix[1][0] = 1.5;
  R.matrix[1][1] = -0.5;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("11) s21_inverse_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_inverse_matrix_test_1);
  tcase_add_test(test_core, s21_inverse_matrix_test_2);
  tcase_add_test(test_core, s21_inverse_matrix_test_3);
  tcase_add_test(test_core, s21_inverse_matrix_test_4);
  tcase_add_test(test_core, s21_inverse_matrix_test_5);
  tcase_add_test(test_core, s21_inverse_matrix_test_6);
  tcase_add_test(test_core, s21_inverse_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}