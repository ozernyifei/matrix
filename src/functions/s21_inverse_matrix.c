#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A->columns <= 0 || A->rows <= 0) {
    res = 1;
  }
  if (A->columns != A->rows) {
    res = 2;
  }
  if (!res && A->columns == 1) {
    if (compare_floats(A->matrix[0][0], 0)) {
      res = 2;
    } else {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  }
  if (!res && A->columns != 1) {
    double det = 0;
    res = s21_determinant(A, &det);
    if (!res && compare_floats(0, det)) {
      res = 2;
    }
    if (!res) {
      matrix_t tmp;
      res = s21_calc_complements(A, &tmp);
      if (!res) {
        matrix_t tmp2;
        s21_transpose(&tmp, &tmp2);
        s21_remove_matrix(&tmp);
        s21_mult_number(&tmp2, 1 / det, result);
        s21_remove_matrix(&tmp2);
      }
    }
  }
  return res;
}
