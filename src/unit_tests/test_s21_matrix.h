#ifndef TEST
#define TEST

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"
enum {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALC_ERROR = 2,
};
enum { FAILURE = 0, SUCCESS = 1 };
Suite *suite_s21_eq_matrix(void);
Suite *suite_s21_create_matrix(void);
Suite *suite_s21_sum_matrix(void);
Suite *suite_s21_sub_matrix(void);
Suite *suite_s21_mult_number_matrix(void);
Suite *suite_s21_mult_matrix(void);
Suite *suite_s21_transpose_matrix(void);
Suite *suite_s21_calc_complements(void);
Suite *suite_s21_determinant(void);
Suite *suite_s21_inverse_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase);

double get_rand(double min, double max);
#endif  //  TEST
