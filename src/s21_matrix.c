#include "s21_matrix.h"

// Создание матриц(create_matrix)

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (null_ptr(result) || neg_size(rows, columns)) {
    return INCORRECT_M;
  }

  int res = OK;
  int ptr = 0;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  //   if (result->matrix == NULL) {
  //     res = INCORRECT_M;
  //   }

  for (; ptr < rows && !res; ptr++) {
    result->matrix[ptr] = (double *)calloc(columns, sizeof(double));
    // if (result->matrix == NULL) {
    //   res = INCORRECT_M;
    // }
  }

  //   if (!res) {
  //     result->rows = rows;
  //     result->columns = columns;
  //   } else {
  //   }

  return res;
}

// Очистка матриц (remove_matrix)

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
  }
  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

// Сравнение матриц(eq_matrix)

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (null_ptr(A) || null_ptr(B) || equal_size(A, B)) {
    return FAILURE;
  }

  int res = SUCCESS;

  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; m < A->columns; n++) {
      if (fabs(A->matrix[m][n] - B->matrix[m][n]) >= 1e-7) {  // 0.0000001
        res = FAILURE;
        m = A->rows;
        n = A->columns;
      }
    }
  }
  return res;
}

// Сложение(sum_matrix) и вычитание матриц(sub_matrix)

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (null_ptr(A) || null_ptr(B) || null_ptr(result)) {
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
  if (null_ptr(A) || null_ptr(B) || null_ptr(result)) {
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

// Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result)) {
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

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (null_ptr(A) || null_ptr(B) || null_ptr(result)) {
    return INCORRECT_M;

  } else if (equal_size(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, B->columns, result);

  for (int r1 = 0, r = 0; r1 < A->rows; r1++, r++) {
    for (int c2 = 0, c = 0; c2 < A->columns; c2++, c++) {
      for (int c1 = 0, r2 = 0; c1 < A->columns; c1++, r2++) {
        result->matrix[r][c] += A->matrix[r1][c1] * B->matrix[r2][c2];
      }
    }
  }
  return OK;
}

// Транспонирование матрицы (transpose)

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result)) {
    return INCORRECT_M;
  }

  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}

// Минор матрицы и матрица алгебраических дополнений (calc_complements)

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result)) {
    return INCORRECT_M;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return MISS_CALC;
  }

  s21_create_matrix(A->rows, A->columns, result);
  matrix_t determ;

  if (A->rows > 1) {
    s21_create_matrix(A->rows, A->columns, &determ);
  } else {
    result->matrix[0][0] = 1.;
  }

  for (int minor_row = 0; minor_row < A->rows && A->rows > 1; minor_row++) {
    for (int minor_col = 0; minor_col < A->columns; minor_col++) {
      record_determ_matrix(&determ, A, minor_row, minor_col);
      s21_determinant(&determ, &result->matrix[minor_row][minor_col]);
    }
  }

  if (A->rows > 1) {
    s21_remove_matrix(&determ);
    alg_complements(A, result);
  }

  return OK;
}

// Определитель матрицы (determinant)

int s21_determinant(matrix_t *A, double *result) {
  if (null_ptr(A) || result == NULL) {
    return INCORRECT_M;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return MISS_CALC;
  }

  matrix_t copy;
  s21_create_matrix(A->rows, A->columns, &copy);

  for (int i = 0; i < copy.rows; i++) {
    for (int k = 0; k < copy.columns; k++) {
      copy.matrix[i][k] = A->matrix[i][k];
    }
  }

  int not_zero = 0, all_zero = 1, sign = 1;
  double *tmp = NULL;
  *result = 1.;

  // поиск первого ненулевого элемента в каждой строке матрицы copy
  for (int rows = 0; rows < copy.rows - 1 && *result; rows++) {
    for (not_zero = rows, all_zero = 1; not_zero < copy.rows; not_zero++) {
      if (copy.matrix[not_zero][rows]) {
        tmp = copy.matrix[not_zero];
        all_zero = 0;  // есть ненулевые элем
        break;
      }
    }

    if (copy.matrix[rows][rows] == 0. && tmp) {  // эл диаг рав 0 и есть не 0 эл
      copy.matrix[not_zero] = copy.matrix[rows];
      copy.matrix[rows] = tmp;
      sign = -sign;  // при смене мест строк/столбцов меняется знак определителя
    }

    if (all_zero) {  // если все нули - то определитель равен нулю
      *result = 0.;
    } else {
      for (int m = rows; m < copy.rows; m++) {
        double tmp = copy.matrix[m][rows] / copy.matrix[rows][rows];
        for (int n = rows; n < copy.columns; n++) {
          copy.matrix[m][n] -= copy.matrix[rows][n] = tmp;
        }
      }
    }
  }
  for (int k = 0; k < A->rows; k++) {
    *result *= copy.matrix[k][k];
  }

  *result *= sign;
  s21_remove_matrix(&copy);

  return OK;
}

// Обратная матрица (inverse_matrix)

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (null_ptr(A) || null_ptr(result)) {
    return INCORRECT_M;
  } else if (A->rows != A->columns || inf_or_nan(A)) {
    return MISS_CALC;
  }

  int res = OK;
  double det = 0.;
  s21_determinant(A, &det);

  if (det) {
    matrix_t complements, transpose;

    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);

    det = 1 / det;
    s21_mult_number(&transpose, det, result);

    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  } else {
    res = MISS_CALC;
  }

  return res;
}

// Additional functions

int null_ptr(matrix_t *A) { return A == NULL; }

int neg_size(int rows, int columns) { return rows <= 0 || columns <= 0; }

int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int inf_or_nan(matrix_t *A) {
  int res = OK;
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; m++) {
      if (isinf(A->matrix[m][n]) || isnan(A->matrix[m][n])) {
        res = MISS_CALC;
        n = A->columns;
        m = A->rows;
      }
    }
  }
  return res;
}

int size_mult(matrix_t *A, matrix_t *B) { return A->columns == B->rows; }

void alg_complements(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((i + j) % 2) {
        result->matrix[i][j] *= -1;
      }
    }
  }
}

void record_determ_matrix(matrix_t *determ, matrix_t *A, int minor_row,
                          int minor_col) {
  for (int src_row = 0, det_rows = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      if (src_row != minor_row && src_col != minor_col) {
        determ->matrix[det_rows][det_col] = A->matrix[src_row][src_col];
        det_col++;

        if (det_col == determ->columns) {
          det_rows++;
          det_col = 0;
        }
      }
    }
  }
}