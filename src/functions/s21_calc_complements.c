#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A->columns <= 0 || A->rows <= 0) {
    res = 1;
  }
  if (A->columns != A->rows) {
    res = 2;
  }
  if (!res) {
    matrix_t minor;
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        int minor_row = 0;
        for (int m = 0; (m < A->rows) && !res; m++) {
          if (m == i) continue;
          int minor_col = 0;
          for (int n = 0; (n < A->columns) && !res; n++) {
            if (n == j) continue;
            minor.matrix[minor_row][minor_col] = A->matrix[m][n];
            minor_col++;
          }
          minor_row++;
        }

        double minor_det;
        res = s21_determinant(&minor, &minor_det);
        if (!res) {
          result->matrix[i][j] = (i + j) % 2 == 0 ? minor_det : -minor_det;
        }
      }
    }
    s21_remove_matrix(&minor);
  }
  return res;
}