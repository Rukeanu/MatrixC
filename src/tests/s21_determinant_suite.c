#include "unit_tests.h"

START_TEST(s21_determinant_test_1) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 13;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 0;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 9323182115255.62662111846136;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = -1.11;
  A.matrix[0][1] = 434.464;
  A.matrix[0][2] = -3611.4;
  A.matrix[0][3] = 99.3;
  A.matrix[0][4] = 8.7;
  A.matrix[1][0] = 2.89;
  A.matrix[1][1] = -63.23;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 87.11;
  A.matrix[1][4] = -12.8;
  A.matrix[2][0] = 994.6;
  A.matrix[2][1] = -134.15;
  A.matrix[2][2] = 58.461;
  A.matrix[2][3] = 115.466;
  A.matrix[2][4] = -161.21;
  A.matrix[3][0] = 251.1;
  A.matrix[3][1] = 356.14;
  A.matrix[3][2] = 365.44;
  A.matrix[3][3] = 34.411;
  A.matrix[3][4] = 124.416;
  A.matrix[4][0] = 15.2;
  A.matrix[4][1] = -31.8;
  A.matrix[4][2] = 8.1;
  A.matrix[4][3] = 611.61;
  A.matrix[4][4] = 0;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  ck_assert_int_eq(1, s21_determinant(&A, &result));
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = -2;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("9) s21_determinant");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_determinant_test_1);
  tcase_add_test(test_core, s21_determinant_test_2);
  tcase_add_test(test_core, s21_determinant_test_3);
  tcase_add_test(test_core, s21_determinant_test_4);
  tcase_add_test(test_core, s21_determinant_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}