// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/031%20Sicherer%20Spurwechsel.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char top[3], mid[3], bot[3];
    scanf("%2s", top);
    scanf("%2s", mid);
    scanf("%2s", bot);

    bool unsafe = false;

    if (mid[1] >= '1' && mid[1] <= '9' && mid[1] == mid[0]) {
        unsafe = true;
    }

    if (top[1] >= '1' && top[1] <= '9' && top[1] < mid[0]) {
        unsafe = true;
    }

    if (bot[1] >= '1' && bot[1] <= '9' && bot[1] > mid[0]) {
        unsafe = true;
    }

    printf(unsafe ? "false\n" : "true\n");
    return 0;
}
