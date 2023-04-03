CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11 -g #-fsanitize=address -pedantic -Wno-gnu-zero-variadic-macro-arguments
TEST_FLAGS := -lcheck
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	# CFLAGS += -D MACOS
	TEST_FLAGS += $(shell pkg-config --cflags --libs check)
else
	TEST_FLAGS += -lsubunit -lrt -lm -lpthread
endif

LIB_DIR := lib/
TEST_DIR := tests/
OBJ_DIR := obj/
COV_DIR := coverage_info/
LIB_NAME = s21_string.a

VPATH := $(LIB_DIR)

.PHONY: all test gcov_report clean

all: clean test gcov_report

#Compile a static library
s21_string.a: $(patsubst %.c, %.o, $(wildcard lib/s21_*.c))
	@ar -rc $(LIB_NAME) $^
	@ranlib $(LIB_NAME)

#Compile object files for the static library
$(OBJ_DIR)$(LIB_DIR)%.o: $(LIB_DIR)%.c s21_string.h
	@mkdir -p $(OBJ_DIR)$(LIB_DIR)
	@$(CC) $(CFLAGS) I. -c $< -o $@

#Compile a test executable file
test: $(wildcard tests/*.c) s21_string.a
	@$(CC) $(CFLAGS) $^ $(TEST_FLAGS) -o test_main
	./test_main

# Generate coverage report
gcov_report: $(wildcard tests/*.c) $(patsubst lib/%.c, $(COV_DIR)$(OBJ_DIR)%.o, $(wildcard lib/s21_*.c))
	@$(CC) $(CFLAGS) -I. --coverage $^ $(TEST_FLAGS) -o $(COV_DIR)test_cov
	@-./$(COV_DIR)test_cov
	@lcov -q -c -d $(COV_DIR) -o $(COV_DIR)s21_string.info --exclude "$(TEST_DIR)*"
	@genhtml $(COV_DIR)s21_string.info -o $(COV_DIR)
	@open $(COV_DIR)lib/index.html

# Compile object files for coverage report
$(COV_DIR)$(OBJ_DIR)%.o: %.c s21_string.h
	@mkdir -p $(COV_DIR)$(OBJ_DIR)$(LIB_DIR)
	@$(CC) $(CFLAGS) --coverage -c $< -o $@

clean:
	@-rm -rf $(OBJ_DIR) s21_string.a test_main $(COV_DIR)\
		     *.dSYM *.gcda *.gcno *.gcov
	@rm -rf ./lib/*.o

rebuild: clean all

style:
	clang-format -n --style=Google *.[ch]
	clang-format -n --style=Google lib/*.[ch]
	clang-format -n --style=Google tests/*.[ch]
	cppcheck *.[ch]
	cppcheck lib/*.[ch]
	cppcheck tests/*.[ch]

leaks:
	leaks --atExit -- ./test_main

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--verbose --log-file=valgrind_result.txt ./test_main
