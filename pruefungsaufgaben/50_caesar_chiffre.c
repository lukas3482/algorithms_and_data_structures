// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/050%20Caesar-Chiffre.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char A[21], B[21];
    scanf("%s", A);
    scanf("%s", B);

    int len = strlen(A);
    if (len != strlen(B)) {
        printf("false\n");
        return 0;
    }

    int shift = (A[0] - B[0] + 26) % 26;

    for (int i = 1; i < len; i++) {
        int current_shift = (A[i] - B[i] + 26) % 26;
        if (current_shift != shift) {
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");
    return 0;
}
