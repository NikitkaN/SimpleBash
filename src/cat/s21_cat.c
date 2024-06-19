#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
void Flag(FILE *fp, char flag, char **argv, int position);
void display(FILE *fp);
void Edit_b(FILE *fp);
void Edit_n(FILE *fp);
void Edit_e(FILE *fp);
void Edit_s(FILE *fp);
void Edit_T(FILE *fp);
void Edit_tv(FILE *fp);
void Edit_ev(FILE *fp);
void Edit_v(FILE *fp);

int main(int argc, char *argv[]) {
    FILE *fp;
    int toggle = 0;
    for (int i = 1; i != argc; i++) {
        switch (argv[i][0]) {
            case '-':
                if ((fp = fopen(argv[i + 1], "r")) == NULL) {
                    printf("Error: Failed to open file");
                } else {
                    Flag(fp, argv[i][1], argv, i);
                }
                toggle = 1;
                break;
            default:
                if ((fp = fopen(argv[i], "r")) == NULL) {
                    printf("Error: Failed to open file");
                } else {
                    display(fp);
                }
                break;
        }
        if (toggle) {
            break;
        }
    }
    return 0;
}

void display(FILE *fp) {
    int ch, pre = EOF;

    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;
        printf("%c", ch);
    }

    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Flag(FILE *fp, char flag,  char **argv, int position) {
    switch (flag) {
        case 'b':
            Edit_b(fp);
            break;
        case 'e':
            Edit_ev(fp);
            break;
        case 'E':
            Edit_e(fp);
            break;
        case 'n':
            Edit_n(fp);
            break;
        case 's':
            Edit_s(fp);
            break;
        case 'T':
            Edit_T(fp);
            break;
        case 't':
            Edit_tv(fp);
            break;
        case 'v':
            Edit_v(fp);
            break;
        case '-':
            if (s21_strcmp(argv[position], "--number-nonblank") == 0) {
                Edit_b(fp);
                break;
            } else if (s21_strcmp(argv[position], "--number") == 0) {
                Edit_n(fp);
                break;
            } else if (s21_strcmp(argv[position], "--squeeze-blank") == 0) {
                Edit_s(fp);
                break;
            } else {
                printf("s21_cat: illegal option -- %s", argv[position]);
                break;
            }
        default:
            fclose(fp);
            break;
    }
}

void Edit_n(FILE *fp) {
    size_t count = 1;
    int ch, pre = EOF;
    printf("%6ld\t", count);

    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;

        printf("%c", ch);
        if (ch == '\n') {
            ++count;
            printf("%6ld\t", count);
        }
    }

    if ( pre == EOF ) {
        printf("Файл пустой!");
    } else if (pre != '\n') {
        ++count;
    }

    fclose(fp);
}

void Edit_b(FILE *fp) {
    size_t count = 0;
    char line[255];
    char *estr;

    while (1) {
        estr = fgets (line, sizeof(line), fp);

        if (estr == NULL) {
            if (feof(fp) != 0) {
                break;
            } else {
                printf("\nError\n");
                break;
            }
        }

        if (s21_strlen(line) > 1 && line[0] != '\n') {
            ++count;
            printf("%6ld\t%s", count, line);
        } else {
            printf("%s", line);
        }
    }

    fclose(fp);
}

void Edit_e(FILE *fp) {
    int ch, pre = EOF;
    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;

        if (ch == '\n') {
            printf("$");
        }
        printf("%c", ch);
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Edit_ev(FILE *fp) {
    int ch, pre = EOF;
    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;
        if (ch == 127 || (ch < 32 && ch != 10 && ch != 9)) {
            if (ch == 127) {
                printf("^?");
            } else {
                printf("^%c", ch + 64);
            }
        } else if (ch == '\n') {
            printf("$\n");
            continue;
        } else {
            printf("%c", ch);
        }
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Edit_s(FILE *fp) {
    int ch, pre, pre_pre = EOF;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n' && pre == '\n' && pre_pre == '\n') {
            pre_pre = pre;
            pre = ch;
            continue;
        }
        printf("%c", ch);

        pre_pre = pre;
        pre = ch;
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Edit_T(FILE *fp) {
    int ch, pre = EOF;
    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;

        if (ch == '\t') {
            printf("^I");
            continue;
        }
        printf("%c", ch);
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Edit_tv(FILE *fp) {
    int ch, pre = EOF;
    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;

        if (ch == 127 || (ch < 32 && ch != 10 && ch != 9)) {
            if (ch == 127) {
                printf("^?");
            } else {
                printf("^%c", ch + 64);
            }
        } else if (ch == '\t') {
            printf("^I");
            continue;
        } else {
            printf("%c", ch);
        }
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

void Edit_v(FILE *fp) {
    int ch, pre = EOF;
    while ((ch = fgetc(fp)) != EOF) {
        pre = ch;

        if (ch == 127 || (ch < 32 && ch != 10 && ch != 9)) {
            if (ch == 127) {
                printf("^?");
            } else {
                printf("^%c", ch + 64);
            }
            continue;
        }
        printf("%c", ch);
    }
    if ( pre == EOF ) {
        printf("Файл пустой!");
    }

    fclose(fp);
}

int s21_strlen(const char *str) {
    int lenght = 0;
    for (; *(str + lenght); lenght++) {}

    return lenght;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}

    return *str1 - *str2;
}
