// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/041%20Zeichen%20in%20bestimmter%20Reihenfolge%20ausgeben.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[10];
    scanf("%s", s);

    int pos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos);
        printf("%c", s[pos - 1]);
    }

    printf("\n");
    return 0;
}
