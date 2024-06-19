#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

void display(int argc, char **argv);
void Flag(int argc, char **argv);
void Search_e(FILE *fp, char **argv, int argc, int file_position);
void Search_v(FILE *fp, char **argv, char *file_name, int argc, int file_position);
void Search_n(FILE *fp, char **argv, char *file_name);
void Search_i(FILE *fp, char **argv, char *file_name);
void Search_c(FILE *fp, char **argv, char *file_name);
void Search_f(FILE *fp, char **argv, FILE *pattern, char *file_name);
void Search_h(FILE *fp, char **argv);
void Search_l(FILE *fp, char **argv, int file_position);
void Search_o(FILE *fp, char **argv, char *file_name);
void Search_s(int restriction);

int main(int argc, char *argv[]) {
    if (argv[1][0] != '-') {
        display(argc, argv);
    } else {
        Flag(argc, argv);
    }

    return 0;
}

void display(int argc, char **argv) {
    FILE *fp;
    char line[1024];
    char file_name[228] = "";
    regex_t reegex;
    int value;
    int end = 0;

    if (argc < 3) {
        printf("Error: Few values\n");
    } else {
        for (int i = 2; i != argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                Search_s(0);
            } else {
                if (argc > 3) {
                    memset(file_name, 0, 228);
                    for (int n = 0; argv[i][n] != '\0'; n++) {
                        file_name[n] = argv[i][n];
                        end = n;
                    }
                    file_name[end + 1] = ':';
                }
                while ((fgets(line, 1024, fp))) {
                    if (regcomp(&reegex, argv[1], 0) == 0) {
                        value = regexec(&reegex, line, 0, NULL, 0);
                        regfree(&reegex);
                        if (value == 0) {
                            printf("%s%s", file_name, line);
                        } else {
                            continue;
                        }
                    } else {
                        Search_s(0);
                    }
                }
                fclose(fp);
            }
        }
    }
}

void Flag(int argc, char **argv) {
    FILE *fp;
    int file_position = 0;
    char file_name[228] = "";
    int end = 0;

    if (argc < 4) {
        printf("Error: Few values");
    } else {
        for (int i = 1; i != argc; i++) {
            if (argv[i][0] == '-') {
                file_position = i;
            }
        }
        file_position += 2;
        while (file_position != argc) {
            if ((fp = fopen(argv[file_position], "r")) == NULL) {
                Search_s(0);
            } else {
                if (argc > 4) {
                    memset(file_name, 0, 228);
                    for (int n = 0; argv[file_position][n] != '\0'; n++) {
                        file_name[n] = argv[file_position][n];
                        end = n;
                    }
                    file_name[end + 1] = ':';
                }
                switch (argv[1][1]) {
                    case 'e':
                        Search_e(fp, argv, argc, file_position);
                        break;
                    case 'v':
                        Search_v(fp, argv, file_name, argc, file_position);
                        break;
                    case 'n':
                        Search_n(fp, argv, file_name);
                        break;
                    case 'i':
                        Search_i(fp, argv, file_name);
                        break;
                    case 'c':
                        Search_c(fp, argv, file_name);
                        break;
                    case 'h':
                        Search_h(fp, argv);
                        break;
                    case 'l':
                        Search_l(fp, argv, file_position);
                        break;
                    case 's':
                        Search_s(1);
                        break;
                    case 'o':
                        Search_o(fp, argv, file_name);
                        break;
                    default:
                        printf("Файл закрыт");
                        fclose(fp);
                        break;
                }
            }
            file_position++;
            if (argc > 4 && file_position - 1 == argc) {
                printf("\n");
            }
        }
    }
}

void Search_e(FILE *fp, char **argv, int argc, int file_position) {
    regex_t reegex;
    char line[1024];
    int word_position[50];
    char file_name[228] = "";
    int pos = 1;
    int i = 0;
    int value;
    int num = 0;
    int end = 0;

    while (argv[pos][0] == '-' && argv[pos][1] == 'e') {
        word_position[i] = pos + 1;
        i++;
        pos += 2;
    }

    if (++pos != argc) {
        memset(file_name, 0, 228);
        for (int n = 0; argv[file_position][n] != '\0'; n++) {
            file_name[n] = argv[file_position][n];
            end = n;
        }
        file_name[end + 1] = ':';
    }

    while ((fgets(line, 1024, fp))) {
       for (int pattern = 0; pattern != i; pattern++) {
           num = word_position[pattern];
           if (regcomp(&reegex, argv[num], 0) == 0) {
               value = regexec(&reegex, line, 0, NULL, 0);
               regfree(&reegex);
                if (value == 0) {
                    printf("%s%s", file_name, line);
                    break;
                } else {
                    continue;
                }
           } else {
               Search_s(0);
           }
       }
    }

    fclose(fp);
}

void Search_v(FILE *fp, char **argv, char *file_name, int argc, int file_position) {
    char line[1024];
    regex_t reegex;
    int value;

    while ((fgets(line, 1024, fp))) {
        if (regcomp(&reegex, argv[2], 0) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                continue;
            } else {
                printf("%s%s", file_name, line);
            }
        } else {
            Search_s(0);
        }
    }

    if (argc > 4 && file_position == argc - 1) {
        printf("\n");
    }

    fclose(fp);
}

void Search_n(FILE *fp, char **argv, char *file_name) {
    char line[1024];
    int count = 0;
    regex_t reegex;
    int value;
    while ((fgets(line, 1024, fp))) {
        count++;
        if (regcomp(&reegex, argv[2], 0) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                printf("%s%d:%s", file_name, count, line);
            } else {
                continue;
            }
        } else {
            Search_s(0);
        }
    }

    fclose(fp);
}

void Search_i(FILE *fp, char **argv, char *file_name) {
    char line[1024];
    regex_t reegex;
    int value;

    while ((fgets(line, 1024, fp))) {
        if (regcomp(&reegex, argv[2], REG_ICASE) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                printf("%s%s", file_name, line);
            } else {
                continue;
            }
        } else {
            Search_s(0);
        }
    }

    fclose(fp);
}

void Search_c(FILE *fp, char **argv, char *file_name) {
    char line[1024];
    int count = 0;
    regex_t reegex;
    int value;

    while ((fgets(line, 1024, fp))) {
        if (regcomp(&reegex, argv[2], 0) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                count++;
            } else {
                continue;
            }
        } else {
            Search_s(0);
        }
    }

    printf("%s%d", file_name, count);

    printf("\n");

    fclose(fp);
}

void Search_h(FILE *fp, char **argv) {
    char line[1024];
    regex_t reegex;
    int value;

    while ((fgets(line, 1024, fp))) {
        if (regcomp(&reegex, argv[2], 0) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                printf("%s", line);
            } else {
                continue;
            }
        } else {
            Search_s(0);
        }
    }

    fclose(fp);
}

void Search_l(FILE *fp, char **argv, int file_position) {
    char line[1024];
    regex_t reegex;

    int value;

    while ((fgets(line, 1024, fp))) {
        if (regcomp(&reegex, argv[2], 0) == 0) {
            value = regexec(&reegex, line, 0, NULL, 0);
            regfree(&reegex);
            if (value == 0) {
                printf("%s", argv[file_position]);
                break;
            } else {
                continue;
            }
        } else {
            Search_s(0);
        }
    }

    printf("\n");
    fclose(fp);
}

void Search_o(FILE *fp, char **argv, char *file_name) {
    char line[1024];

    while ((fgets(line, 1024, fp))) {
        if (strspn(line, argv[2]) >= 1) {
            printf("%s%s\n", file_name, argv[2]);
        }
    }

    fclose(fp);
}

void Search_s(int restriction) {
    int flag = 0;
    char error[228] = "";
    char word[228] = "Error!";
    if (restriction != flag) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            error[i] = word[i];
        }
    } else {
        flag = 1;
    }
    printf("%s", error);
}
