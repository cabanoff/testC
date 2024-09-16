#include <stdio.h>
#include <string.h>

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

void replace_decimals_with_hex(char *line) {
    //comment 1
    int in_string = 0, in_single_comment = 0, in_multi_comment = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"' && !in_single_comment && !in_multi_comment) {
            in_string = !in_string;
        }
        if (line[i] == '/' && line[i+1] == '/' && !in_string && !in_multi_comment) {
            in_single_comment = 1;
        }
        if (line[i] == '/' && line[i+1] == '*' && !in_string && !in_single_comment) {
            in_multi_comment = 1;
        }
        if (line[i] == '*' && line[i+1] == '/' && in_multi_comment) {
            in_multi_comment = 0;
            i++; // Пропустить '/'
        }
        if (!in_string && !in_single_comment && !in_multi_comment && is_digit(line[i])) {
            int num = 0;
            int j = i;
            while (is_digit(line[j])) {
                num = num * 10 + (line[j] - '0');
                j++;
            }
            printf("0x%X", num);
            i = j - 1;
        } else {
            putchar(line[i]);
        }
        if (line[i] == '\n') {
            in_single_comment = 0; // Завершение однострочного комментария
        }
    }
}

int main() {
    char line[256];
    printf("Введите текст программы на Си:\n");
    while (fgets(line, sizeof(line), stdin)) {
        replace_decimals_with_hex(line);
    }
    return 0;
}
