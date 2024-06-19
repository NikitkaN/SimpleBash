all: s21_cat s21_cat_test

s21_cat: s21_cat.c
	gcc -Wall -Werror -Wextra -g s21_cat.c -o s21_cat

s21_cat_test: s21_cat
	@./tests/test.sh

clean:
	rm -rf s21_cat