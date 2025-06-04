// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/047%20Z%C3%A4hlen%20eines%20Substrings%20in%20W%C3%B6rtern.md
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

bool contains_substring_once(char *word, char *substr) {
    return strstr(word, substr) != NULL;
}

int main() {
    char s[16];
    char text[256];

    fgets(s, sizeof(s), stdin);
    fgets(text, sizeof(text), stdin);

    s[strcspn(s, "\n")] = '\0';
    text[strcspn(text, "\n")] = '\0';

    to_lowercase(s);
    to_lowercase(text);

    int count = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        if (contains_substring_once(token, s)) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", count);
    return 0;
}
