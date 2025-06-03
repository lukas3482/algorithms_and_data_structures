// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/023%20L%C3%A4ngster%20wiederkehrender%20Substring.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int substr_equal(const char* str, int i, int j, int len) {
    for (int k = 0; k < len; k++) {
        if (str[i + k] != str[j + k])
            return 0;
    }
    return 1;
}

int main() {
    char input[MAX_LEN];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    to_lowercase(input);
    int len = strlen(input);
    char longest[MAX_LEN] = "";
    int max_len = 0;

    for (int l = 1; l < len; l++) {
        for (int i = 0; i <= len - l; i++) {
            for (int j = i + 1; j <= len - l; j++) {
                if (substr_equal(input, i, j, l)) {
                    if (l > max_len) {
                        max_len = l;
                        strncpy(longest, input + i, l);
                        longest[l] = '\0';
                    }
                }
            }
        }
    }

    if (max_len > 0) {
        printf("%s\n", longest);
    } else {
        printf("None\n");
    }

    return 0;
}
