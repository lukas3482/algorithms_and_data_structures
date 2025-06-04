// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/046%20Z%C3%A4hle%20Kreuzungen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>

int main() {
    int width, height;
    scanf("%d %d", &width, &height);

    char grid[100][100];

    for (int i = 0; i < height; i++) {
        scanf("%s", grid[i]);
    }

    int count = 0;

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            if (grid[y][x] == 'X' &&
                grid[y - 1][x] == 'X' &&
                grid[y + 1][x] == 'X' &&
                grid[y][x - 1] == 'X' &&
                grid[y][x + 1] == 'X') {
                count++;
                }
        }
    }

    printf("%d\n", count);
    return 0;
}
