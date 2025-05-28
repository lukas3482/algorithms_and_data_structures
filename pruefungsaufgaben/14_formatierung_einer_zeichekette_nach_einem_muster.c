// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Formatierung%20einer%20Zeichenkette%20nach%20einem%20Muster.md
// Created by lukas on 25.03.2025.
//
#include <ctype.h>
#include <stdio.h>
#include <inttypes.h>

int main(void){
    char S[] = "sAmMyJr";
    char F[] = "Xxxxx, Xx.";

    int8_t index = 0;
    int8_t index2 = 0;
    while(F[index] != '\0') {
        switch (F[index]) {
            case 'X':
                printf("%c", toupper(S[index2]));
                index2++;
                break;
            case 'x':
                printf("%c", tolower(S[index2]));
                index2++;
                break;
            default:
                printf("%c", F[index]);
                break;
        }
        index++;
    }
    printf("\n");
}
