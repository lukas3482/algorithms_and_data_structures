//
// Created by lukas on 25.05.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct { int x, y; } Point;

int cmpPoints(const void *a, const void *b){
    const Point *pa = a;
    const Point *pb = b;
    if (pa->x != pb->x) return pa->x - pb->x;
    return pa->y - pb->y;
}

int main(void){
    int W, H;
    if (scanf("%d%d", &W, &H) != 2) return 0;

    int X, Y;
    scanf("%d%d", &X, &Y); fgetc(stdin);

    // Maze einlesen
    char **maze = malloc(H * sizeof *maze);
    for (int y = 0; y < H; ++y) {
        maze[y] = malloc(W + 1);
        scanf("%[^\n]", maze[y]); fgetc(stdin);
    }

    // Speicher initialisieren
    bool *vis = calloc(W * H, sizeof *vis);
    Point *queue = malloc(W * H * sizeof *queue);
    int qHead = 0, qTail = 0;

    // Ausgänge – Worst-Case W*H Stück
    Point *exits = malloc(W * H * sizeof *exits);
    int exitCount = 0;

    // Startfeld nur erkunden, wenn es betretbar ist
    if (maze[Y][X] == '.') {
        vis[Y * W + X] = true;
        queue[qTail++] = (Point){X, Y};
    }

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    // BFS
    while (qHead < qTail) {
        Point p = queue[qHead++];

        // Prüfen, ob p ein Ausgang ist (Randfeld)
        if (p.x == 0 || p.x == W - 1 || p.y == 0 || p.y == H - 1) {
            exits[exitCount++] = p;
        }

        // Nachbarn erkunden
        for (int dir = 0; dir < 4; ++dir) {
            int nx = p.x + dx[dir];
            int ny = p.y + dy[dir];

            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                continue;
            if (maze[ny][nx] != '.')
                continue;
            if (vis[ny * W + nx])
                continue;

            vis[ny * W + nx] = true;
            queue[qTail++] = (Point){nx, ny};
        }
    }

    // Ausgänge sortieren
    qsort(exits, exitCount, sizeof *exits, cmpPoints);

    // Ausgabe
    printf("%d\n", exitCount);
    for (int i = 0; i < exitCount; ++i)
        printf("%d %d\n", exits[i].x, exits[i].y);

    return 0;
}
