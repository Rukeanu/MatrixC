CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
MATRIX = s21_matrix.a
NAME_TEST = s21_test

SRCS_TESTS = unit_tests.c \
	s21_create_matrix_suite.c \
	s21_remove_matrix_suite.c \
	s21_eq_matrix_suite.c \
	s21_sum_matrix_suite.c \
	s21_sub_matrix_suite.c \
	s21_mult_number_suite.c \
	s21_mult_matrix_suite.c \
	s21_transpose_suite.c \
	s21_calc_complements_suite.c \
	s21_determinant_suite.c \
	s21_inverse_matrix_suite.c

DIR_TESTS = tests
PATH_TESTS = $(addprefix $(DIR_TESTS)/, $(SRCS_TESTS))

OS := $(shell uname)
MAC_X86 := $(shell uname -a | grep -o _X86_64)
MAC_M1 := $(shell uname -a | grep -o _ARM64)

ifeq ($(OS), Linux)
	TEST_LIBS = -lcheck -pthread -lrt -lm -lsubunit
	MATH = -lm
	OPEN = xdg-open
endif

ifeq ($(MAC_M1), _ARM64)
	TEST_LIBS := -I/opt/homebrew/opt/check/include -L/opt/homebrew/opt/check/lib -lcheck
	OPEN = open
endif
ifeq ($(MAC_X86), _X86_64)
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
	OPEN = open
endif


all: $(MATRIX)

$(MATRIX):
	$(CC) $(FLAGS) -c *.c
	ar rcs $(MATRIX) *.o
	ranlib $(MATRIX)

test: $(MATRIX)
	gcc --coverage -g *.c $(PATH_TESTS) -I $(DIR_TESTS) $(TEST_LIBS) -o s21_test
	./s21_test

gcov_report: test
	lcov -t "gcovreport" -o gcovreport.info -c --directory .
	genhtml -o report gcovreport.info
	open report/index.html

clang:
	clang-format -n *.c *.h

leaks: clean test
	leaks -atExit -- ./s21_test

valgrind: clean test
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes ./s21_test

rebuild: clean build

clean:
	rm -rf $(NAME_TEST) *.o *.a *.gcno *.gcda *.gcov *.info report a.out *.dSYM obj
	rm -rf .clang-format

