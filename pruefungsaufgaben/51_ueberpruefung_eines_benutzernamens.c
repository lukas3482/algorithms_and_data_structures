// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/051%20%C3%9Cberpr%C3%BCfung%20eines%20Benutzernamens.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char input[] = "Username123";
    int len = strlen(input);
    bool isValid = true;

    if(len < 3 || len > 20)
        isValid = false;

    for(int i = 0; i < len; i++) {
        if(!isalnum(input[i])){
            isValid = false;
            break;
        }
    }
    printf("%s", isValid ? "VALID" : "INVALID");

    return 0;
}
