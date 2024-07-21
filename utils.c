#include "s21_matrix.h"

int is_size_eq(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns);
}

int is_square(matrix_t *A) { return (A->rows == A->columns); }

int size(matrix_t *A) {
  int ret = 0;
  if (!is_square(A))
    ret = -1;
  else
    ret = A->rows;
  return ret;
}

void print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%lf ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

matrix_t minor(matrix_t *A, int i, int j) {
  matrix_t result;
  s21_create_matrix(A->rows - 1, A->columns - 1, &result);
  for (int li = 0; li < A->rows; li++) {
    if (li == i) continue;
    for (int lj = 0; lj < A->columns; lj++) {
      if (lj == j) continue;
      result.matrix[li - (li > i)][lj - (lj > j)] = A->matrix[li][lj];
    }
  }
  return result;
}