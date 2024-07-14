#include "../s21_matrix.h"
#include "math.h"
#include "stdlib.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (rows <= 0 || columns <= 0) {
    res = 1;
  }
  if (!res) {
    result->rows = rows;
    result->columns = columns;
    (result->matrix) = (double **)malloc(sizeof(double) * rows * columns +
                                         rows * sizeof(double *));
    if (result->matrix != NULL) {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + columns * i;
      }
    } else {
      res = 2;
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  A->columns = 0;
  A->rows = 0;
  free(A->matrix);
}

int compare_floats(double a, double b) { return fabs(a - b) < 0.0000001; }