#include "unit_tests.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 5;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 4;

  check.matrix[0][0] = 11;
  check.matrix[0][1] = 25;
  check.matrix[1][0] = 16;
  check.matrix[1][1] = 38;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(2, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_mult_matrix(&A, &B, &result));
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = -45.5;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 64.46;
  A.matrix[1][1] = 7.7;
  A.matrix[2][0] = 31.87;
  A.matrix[2][1] = -44.454;

  B.matrix[0][0] = 78.16;
  B.matrix[0][1] = -14.11;
  B.matrix[0][2] = 44.11;
  B.matrix[1][0] = 118.23;
  B.matrix[1][1] = 58.36;
  B.matrix[1][2] = 6.97;

  check.matrix[0][0] = -3556.28;
  check.matrix[0][1] = 642.005;
  check.matrix[0][2] = -2007.005;
  check.matrix[1][0] = 5948.5646;
  check.matrix[1][1] = -460.1586;
  check.matrix[1][2] = 2896.9996;
  check.matrix[2][0] = -2764.83722;
  check.matrix[2][1] = -3044.02114;
  check.matrix[2][2] = 1095.94132;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;

  check.matrix[0][0] = 9.0;
  check.matrix[0][1] = 11.0;
  check.matrix[0][2] = 17.0;
  check.matrix[1][0] = 12.0;
  check.matrix[1][1] = 13.0;
  check.matrix[1][2] = 22.0;
  check.matrix[2][0] = 15.0;
  check.matrix[2][1] = 15.0;
  check.matrix[2][2] = 27.0;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  A.matrix[0][0] = 123.124;

  B.matrix[0][0] = 1.12;

  check.matrix[0][0] = 137.89888;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 123;
  A.matrix[0][1] = 123;
  A.matrix[1][0] = 123;
  A.matrix[1][1] = 123;

  B.matrix[0][0] = 1.3;
  B.matrix[0][1] = 1.4;
  B.matrix[1][0] = 1.5;
  B.matrix[1][1] = -1.6;

  check.matrix[0][0] = 344.4;
  check.matrix[0][1] = -24.6;
  check.matrix[1][0] = 344.4;
  check.matrix[1][1] = -24.6;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("7) s21_mult_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_matrix_test_1);
  tcase_add_test(test_core, s21_mult_matrix_test_2);
  tcase_add_test(test_core, s21_mult_matrix_test_3);
  tcase_add_test(test_core, s21_mult_matrix_test_4);
  tcase_add_test(test_core, s21_mult_matrix_test_5);
  tcase_add_test(test_core, s21_mult_matrix_test_6);
  tcase_add_test(test_core, s21_mult_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}