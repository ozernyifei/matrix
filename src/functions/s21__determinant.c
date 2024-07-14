#include "../s21_matrix.h"

double determinant(matrix_t *mat, int *res) {
  if (mat->rows != mat->columns || *res != 0) {
    *res = 2;
    return 0;
  }

  int n = mat->rows;
  double det = 0;

  if (n == 1) {
    return mat->matrix[0][0];
  }

  if (n == 2) {
    return (mat->matrix[0][0] * mat->matrix[1][1]) -
           (mat->matrix[0][1] * mat->matrix[1][0]);
  }
  matrix_t minorMat;
  s21_create_matrix(n - 1, n - 1, &minorMat);

  for (int f = 0; f < n; f++) {
    for (int i = 1; i < n; i++) {
      int colCount = 0;
      for (int j = 0; j < n; j++) {
        if (j == f) continue;
        minorMat.matrix[i - 1][colCount] = mat->matrix[i][j];
        colCount++;
      }
    }
    det +=
        (f % 2 ? -1.0 : 1.0) * mat->matrix[0][f] * determinant(&minorMat, res);
  }
  s21_remove_matrix(&minorMat);

  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (A->columns <= 0 || A->rows <= 0) {
    res = 1;
  }
  if (!res && (A->columns != A->rows)) {
    res = 2;
  }
  if (!res) {
    int inner_res = 0;
    *result = determinant(A, &inner_res);
    res = inner_res;
  }
  return res;
}
