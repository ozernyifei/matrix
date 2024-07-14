#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = 1;
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    res = 0;
  }
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    res = 0;
  }
  if (res) {
    for (int i = 0; (i < A->rows) && res; i++) {
      for (int j = 0; (j < A->columns) && res; j++) {
        if (!compare_floats(A->matrix[i][j], B->matrix[i][j])) {
          res = 0;
        }
      }
    }
  }
  return res;
}