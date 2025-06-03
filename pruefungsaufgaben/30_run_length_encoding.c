// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/030%20Run-Length%20Encoding.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    char grid[N * N + 1];
    int index = 0;

    for (int i = 0; i < N; i++) {
        char row[8];
        fgets(row, sizeof(row), stdin);
        for (int j = 0; j < N; j++) {
            if (row[j] == 'A' || row[j] == 'B' || row[j] == 'C') {
                grid[index++] = row[j];
            }
        }
    }
    grid[index] = '\0';

    int count = 1;
    for (int i = 1; i <= index; i++) {
        if (grid[i] == grid[i - 1]) {
            count++;
        } else {
            if (count == 1) {
                printf("%c", grid[i - 1]);
            } else {
                printf("%d%c", count, grid[i - 1]);
            }
            count = 1;
        }
    }

    printf("\n");
    return 0;
}
