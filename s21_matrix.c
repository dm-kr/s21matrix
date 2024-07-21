#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = SUCCESS;
  if (is_size_eq(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = SUCCESS;
  if (is_size_eq(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = SUCCESS;
  if (A->rows == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        for (int k = 0; k < A->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return ret;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (!is_size_eq(A, B)) ret = FAILURE;
  for (int i = 0; i < A->rows && ret == SUCCESS; i++) {
    for (int j = 0; j < A->columns && ret == SUCCESS; j++) {
      if (A->matrix[i][j] != B->matrix[i][j]) {
        ret = FAILURE;
        // TODO Comparison up to 7 decimal places
      }
    }
  }
  return ret;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ret = SUCCESS;
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    for (int i = 0; i < rows && ret == SUCCESS; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        ret = FAILURE;
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}

int s21_determinant(matrix_t *A, double *result) {
  int ret = SUCCESS;
  if (size(A) == 1) {
    *result = A->matrix[0][0];
  } else if (size(A) == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (size(A) > 2) {
    for (int i = 0; i < A->columns; i++) {
      matrix_t m = minor(A, 0, i);
      double r = 0;
      s21_determinant(&m, &r);
      *result += r * pow(-1, i) * A->matrix[0][i];
      s21_remove_matrix(&m);
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  return is_square(A) || (result);
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  return is_square(A) || (result);
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  return is_square(A) || (result);
}