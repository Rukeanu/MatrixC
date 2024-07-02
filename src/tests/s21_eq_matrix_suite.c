#include "unit_tests.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000001;
  A.matrix[1][0] = 3.0000001;
  A.matrix[1][1] = 4.0000001;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[1][0] = 3.12345673;
  A.matrix[1][1] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[0][2] = 3.12345673;
  A.matrix[1][0] = 4.12345674;
  A.matrix[1][1] = 4.12345674;
  A.matrix[1][2] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 3454.213;
  A.matrix[0][1] = 32413.324;
  A.matrix[0][2] = 234.25;
  A.matrix[0][3] = 3124.3215;
  A.matrix[0][4] = 12.1;
  A.matrix[1][0] = 123.23;
  A.matrix[1][1] = 3456.46;
  A.matrix[1][2] = 32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = 32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = -3454.213;
  A.matrix[0][1] = -32413.324;
  A.matrix[0][2] = -234.25;
  A.matrix[0][3] = -3124.3215;
  A.matrix[0][4] = -12.1;
  A.matrix[1][0] = -123.23;
  A.matrix[1][1] = -3456.46;
  A.matrix[1][2] = -32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = -32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1234567123;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1134567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = -234.1234567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_9) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2435;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_11) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_12) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = -123.2121;
  B.matrix[0][1] = -123;
  B.matrix[0][2] = -1243235;
  B.matrix[1][0] = -123.324;
  B.matrix[1][1] = -543.123;
  B.matrix[1][2] = -354.123;
  B.matrix[2][0] = -54.123;
  B.matrix[2][1] = -34.213;
  B.matrix[2][2] = -123.5;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_13) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[1][0] = 123.324;
  B.matrix[1][1] = 543.123;
  B.matrix[1][2] = 354.123;
  B.matrix[2][0] = 54.123;
  B.matrix[2][1] = 34.213;
  B.matrix[2][2] = 123.5;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_14) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.columns = -100;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_15) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.rows = 0;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  B.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("3) s21_eq_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_eq_matrix_test_1);
  tcase_add_test(test_core, s21_eq_matrix_test_2);
  tcase_add_test(test_core, s21_eq_matrix_test_3);
  tcase_add_test(test_core, s21_eq_matrix_test_4);
  tcase_add_test(test_core, s21_eq_matrix_test_5);
  tcase_add_test(test_core, s21_eq_matrix_test_6);
  tcase_add_test(test_core, s21_eq_matrix_test_7);
  tcase_add_test(test_core, s21_eq_matrix_test_8);
  tcase_add_test(test_core, s21_eq_matrix_test_9);
  tcase_add_test(test_core, s21_eq_matrix_test_10);
  tcase_add_test(test_core, s21_eq_matrix_test_11);
  tcase_add_test(test_core, s21_eq_matrix_test_12);
  tcase_add_test(test_core, s21_eq_matrix_test_13);
  tcase_add_test(test_core, s21_eq_matrix_test_14);
  tcase_add_test(test_core, s21_eq_matrix_test_15);
  suite_add_tcase(selection, test_core);
  return selection;
}