#include "s21_matrix.h"

// Создание матриц(create_matrix)

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
  } else {
    error = INCORRECT_M;
  }

  return error;
}

// Очистка матриц (remove_matrix)

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

// Сравнение матриц(eq_matrix)

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (null_ptr(A) || null_ptr(B) || equal_size(A, B)) {
    return FAILURE;
  }

  int error = SUCCESS;

  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if (fabs(A->matrix[m][n] - B->matrix[m][n]) >= 1e-7) {  // 0.0000001
        error = FAILURE;
        break;
      }
    }
  }
  return error;
}

// Сложение(sum_matrix) и вычитание матриц(sub_matrix)

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (null_ptr(A) || null_ptr(B) || null_ptr(result) ||
      neg_size(A->rows, A->columns) || neg_size(B->rows, B->columns)) {
    return INCORRECT_M;

  } else if (equal_size(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (null_ptr(A) || null_ptr(B) || null_ptr(result) ||
      neg_size(A->rows, A->columns) || neg_size(B->rows, B->columns)) {
    return INCORRECT_M;

  } else if (equal_size(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

// Умножение матрицы на число (mult_number)

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result) || neg_size(A->rows, A->columns)) {
    return INCORRECT_M;

  } else if (inf_or_nan(A) || isinf(number) || isnan(number)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}

// Умножение двух матриц (mult_matrix)

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (null_ptr(A) || null_ptr(B) || null_ptr(result) ||
      neg_size(A->rows, A->columns) || neg_size(B->rows, B->columns)) {
    return INCORRECT_M;

  } else if (!size_mult(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, B->columns, result);

  for (int row = 0; row < A->rows; row++) {
    for (int col = 0; col < B->columns; col++) {
      for (int i = 0; i < A->columns; i++) {
        result->matrix[row][col] += A->matrix[row][i] * B->matrix[i][col];
      }
    }
  }
  return OK;
}

// Транспонирование матрицы (transpose)

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result) || neg_size(A->rows, A->columns)) {
    return INCORRECT_M;
  }

  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

// Минор матрицы и матрица алгебраических дополнений (calc_complements)

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;

  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t minor;
            s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
            int l = 0;
            for (int m = 0; m < A->rows; m++) {
              if (i != m) {
                for (int n = 0; n < A->columns; n++) {
                  if (j != n) {
                    minor.matrix[l / minor.rows][l % minor.rows] =
                        A->matrix[m][n];
                    l++;
                  }
                }
              }
            }
            double determinant;
            s21_determinant(&minor, &determinant);
            result->matrix[i][j] =
                pow((double)-1, (double)(i + j)) * determinant;
            s21_remove_matrix(&minor);
          }
        }
      }
    } else {
      error = MISS_CALC;
    }
  } else {
    error = INCORRECT_M;
  }

  return error;
}

// Определитель матрицы (determinant)

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  *result = 0;

  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[1][0] * A->matrix[0][1];
      } else {
        for (int i = 0; i < A->columns; i++) {
          matrix_t minor;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          for (int m = 1; m < A->rows; m++) {
            int col_minor = 0;
            for (int n = 0; n < A->columns; n++) {
              if (n != i) {
                minor.matrix[m - 1][col_minor] = A->matrix[m][n];
                col_minor++;
              }
            }
          }
          double minor_det;
          s21_determinant(&minor, &minor_det);
          *result += pow(-1, i) * A->matrix[0][i] * minor_det;
          s21_remove_matrix(&minor);
        }
      }
    } else {
      error = MISS_CALC;
    }
  } else {
    error = INCORRECT_M;
  }

  return error;
}

// Если размер матрицы равен 1 (A->rows == 1), то определитель равен
// единственному элементу матрицы A->matrix[0][0], и мы записываем его в
// *result.

// Определитель квадратной матрицы равен сумме произведений элементов любой
// строки (столбца) на их алгебраические дополнения:

// Обратная матрица (inverse_matrix)

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        matrix_t matrix_calc = {NULL, 0, 0};
        matrix_t matrix_transpose = {NULL, 0, 0};
        s21_calc_complements(A, &matrix_calc);
        s21_transpose(&matrix_calc, &matrix_transpose);
        s21_mult_number(&matrix_transpose, 1 / determinant, result);
        s21_remove_matrix(&matrix_calc);
        s21_remove_matrix(&matrix_transpose);
      } else {
        error = MISS_CALC;
      }
    } else {
      error = MISS_CALC;
    }
  } else {
    error = INCORRECT_M;
  }
  return error;
}

// Additional functions

int null_ptr(matrix_t *A) { return A == NULL; }

int neg_size(int rows, int columns) { return rows <= 0 || columns <= 0; }

// 0 - совпадают, 1 - не совпадают
int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int inf_or_nan(matrix_t *A) {
  int error = OK;
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if (isinf(A->matrix[m][n]) || isnan(A->matrix[m][n])) {
        error = MISS_CALC;
        break;
      }
    }
  }
  return error;
}

int size_mult(matrix_t *A, matrix_t *B) { return A->columns == B->rows; }