#include "../s21_matrix.h"

int main() {
  matrix_t A;
  int size = 8;
  s21_create_matrix(size, size, &A);
  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      A.matrix[i][j] = arr[(rand()) % 9];
    }
  }
  print_matrix(&A);
  double d = 0;
  s21_determinant(&A, &d);
  printf("%lf", d);
  printf("\n");
  s21_remove_matrix(&A);
  return 0;
}