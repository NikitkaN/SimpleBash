all: s21_grep s21_grep_test

s21_grep:
	gcc -Wall -Werror -Wextra -g s21_grep.c -o s21_grep

s21_grep_test: s21_grep
	@./tests/test.sh

clean:
	rm -rf s21_grep