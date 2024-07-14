CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck -lpthread -lm

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
 TEST_FLAGS += -lrt -lsubunit
endif

MATRIX= ./functions/*.c
TEST= ./unit_tests/test*.c ./unit_tests/test_s21_matrix.h
OBJECTS= *.o

CLANG= clang-format

.PHONY: all clean test s21_matrix.a gcov_report

all: s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(CFLAGS) -c $(MATRIX)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(CFLAGS) $(MATRIX) $(TEST) s21_matrix.a $(TEST_FLAGS) -o s21_matrix_test
	./s21_matrix_test

gcov_report: s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(MATRIX) $(TEST) $(TEST_FLAGS) -o s21_matrix_test
	./s21_matrix_test
	lcov -t "s21_matrix_test" -o s21_matrix_test_report.info -c -d .
	genhtml -o report s21_matrix_test_report.info
	open report/index.html
	rm -rf *.o *.a *.gch *.gcno *.gcda *.info s21_matrix_test

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info report s21_matrix_test

rebuild:
	make clean
	make all

clang_n:
	$(CLANG) -style=Google -n *.[ch] */*.[ch]

clang_i:
	$(CLANG) -style=Google -i *.[ch] */*.[ch]

