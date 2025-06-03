// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/028%20Roboter-Tour.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001
#define OFFSET 500

int main(void) {
    char route[501];
    scanf("%500s", route);

    int grid[SIZE][SIZE] = {0};
    int x = OFFSET, y = OFFSET;

    grid[y][x] = 1;
    int maxVisit = 1;

    for (int i = 0; route[i] != '\0'; i++) {
        switch(route[i]) {
            case '^': y++; break;
            case 'v': y--; break;
            case '>': x++; break;
            case '<': x--; break;
        }
        grid[y][x]++;
        if (grid[y][x] > maxVisit) {
            maxVisit = grid[y][x];
        }
    }

    printf("%d\n", maxVisit);
    return 0;
}
