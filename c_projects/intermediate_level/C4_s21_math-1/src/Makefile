FLAG_COV = -lcheck -lgcov -fprofile-arcs --coverage

all: s21_math.a

s21_math.a:
	gcc -c s21_math.c
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a
	rm -rv *.o

test: s21_math.a
	gcc s21_math.a -lcheck tests/test.c -lcheck -o test
	./test

clean: 
	rm -rf *.o *.info *.gcda *.gcno *.a *.out ./report test
	clear

gcov_report: s21_math.a
	gcc -o test s21_math.a -lcheck *.c tests/test.c $(FLAG_COV)
	./test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info;
