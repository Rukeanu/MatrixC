#include "unit_tests.h"

START_TEST(s21_create_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(2, 2, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(15, 15, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(30, 30, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(1, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(10, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(1, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-5, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(0, 0, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(5, -1, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-1, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-5, -5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_12) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-10, 10, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_13) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(5, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_14) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(10, 5, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_15) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-1, 4, &matrix));
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("1) s21_create_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_create_matrix_test_1);
  tcase_add_test(test_core, s21_create_matrix_test_2);
  tcase_add_test(test_core, s21_create_matrix_test_3);
  tcase_add_test(test_core, s21_create_matrix_test_4);
  tcase_add_test(test_core, s21_create_matrix_test_5);
  tcase_add_test(test_core, s21_create_matrix_test_6);
  tcase_add_test(test_core, s21_create_matrix_test_7);
  tcase_add_test(test_core, s21_create_matrix_test_8);
  tcase_add_test(test_core, s21_create_matrix_test_9);
  tcase_add_test(test_core, s21_create_matrix_test_10);
  tcase_add_test(test_core, s21_create_matrix_test_11);
  tcase_add_test(test_core, s21_create_matrix_test_12);
  tcase_add_test(test_core, s21_create_matrix_test_13);
  tcase_add_test(test_core, s21_create_matrix_test_14);
  tcase_add_test(test_core, s21_create_matrix_test_15);
  suite_add_tcase(selection, test_core);
  return selection;
}