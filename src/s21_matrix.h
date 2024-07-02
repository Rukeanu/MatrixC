#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define MALLOC_ERROR 3

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum result_code { OK, INCORRECT_M, MISS_CALC };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int null_ptr(matrix_t *A);
int neg_size(int rows, int columns);
int equal_size(matrix_t *A, matrix_t *B);
int inf_or_nan(matrix_t *A);
int size_mult(matrix_t *A, matrix_t *B);
void record_determ_matrix(matrix_t *determ, matrix_t *A, int minor_row,
                          int minor_col);
void alg_complements(matrix_t *A, matrix_t *result);

#endif