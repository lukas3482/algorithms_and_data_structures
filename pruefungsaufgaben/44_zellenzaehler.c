// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/044%20Zellenz%C3%A4hler%20-%20Nachbarschaftsanalyse%20im%20Gitter.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>

int main() {
    int W, H;
    scanf("%d %d", &W, &H);

    int X, Y;
    scanf("%d %d", &X, &Y);

    char grid[100][100];

    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
    }

    int count = 0;

    int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

    for (int i = 0; i < 8; i++) {
        int nx = X + dx[i];
        int ny = Y + dy[i];

        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
            if (grid[ny][nx] == '1') {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
