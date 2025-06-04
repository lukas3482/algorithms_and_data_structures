// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/049%20%C3%9Cberpr%C3%BCfung%20einer%20Zeichenketten-Rotation.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char)str[i]);
}

int main() {
    char s1[101], s2[101];
    scanf("%s", s1);
    scanf("%s", s2);

    to_lowercase(s1);
    to_lowercase(s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        printf("false\n");
        return 0;
    }

    char double_s1[202];
    strcpy(double_s1, s1);
    strcat(double_s1, s1);

    if (strstr(double_s1, s2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
