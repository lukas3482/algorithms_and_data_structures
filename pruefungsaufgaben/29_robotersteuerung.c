// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/029%20Robotersteuerung%20mit%20komprimierten%20Befehlen.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <string.h>

char getSymbol(const char* cmd) {
    if (strcmp(cmd, "up") == 0) return '^';
    if (strcmp(cmd, "down") == 0) return 'v';
    if (strcmp(cmd, "left") == 0) return '<';
    if (strcmp(cmd, "right") == 0) return '>';
    return '?';
}

int main(void) {
    char input[256];
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " \n");
    char lastCmd[10] = "";
    int count = 0;

    while (token != NULL) {
        if (strcmp(token, lastCmd) == 0) {
            count++;
        } else {
            if (count > 0) {
                printf("%c", getSymbol(lastCmd));
                if (count > 1) printf("%d", count);
            }
            strcpy(lastCmd, token);
            count = 1;
        }
        token = strtok(NULL, " \n");
    }


    if (count > 0) {
        printf("%c", getSymbol(lastCmd));
        if (count > 1) printf("%d", count);
    }

    printf("\n");
    return 0;
}
