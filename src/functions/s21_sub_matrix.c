#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (A->columns <= 0 || A->rows <= 0 || B->columns <= 0 || B->rows <= 0) {
    res = 1;
  }
  if (!res && (A->columns != B->columns || A->rows != B->rows)) {
    res = 2;
  }
  if (!res) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return res;
}