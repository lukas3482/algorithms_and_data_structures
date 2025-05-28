// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/018%20Gl%C3%BCcksticket-%C3%9Cberpr%C3%BCfung.md
// Created by lukas on 28.05.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int charToInt(char c) {
    return c - '0';
}

bool checkTicket(char* ticket) {
    int sum1 = charToInt(ticket[0]) + charToInt(ticket[1]) + charToInt(ticket[2]);
    int sum2 = charToInt(ticket[3]) + charToInt(ticket[4]) + charToInt(ticket[5]);
    return sum1 == sum2;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char* ticket = calloc(7, sizeof(char));
        scanf("%s", ticket);
        printf("%s\n", checkTicket(ticket) ? "true" : "false");
    }
}