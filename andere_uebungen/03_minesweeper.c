#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20

// Inputs
int w, h, nb;

char grid[MAX][MAX + 2];
// true, wenn Feld als Mine markiert ist
bool mine[MAX][MAX];
// true, wenn Feld sicher KEINE Mine ist
bool safe[MAX][MAX];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

typedef struct { int x, y; } Pos;

static inline bool inBounds(int y, int x, int h, int w) {
    return y >= 0 && y < h && x >= 0 && x < w;
}

static int cmpPos(const void *a, const void *b) {
    const Pos *pa = a, *pb = b;
    if (pa->x != pb->x) return pa->x - pb->x;
    return pa->y - pb->y;
}

// Minen suchen
int searchMines(){
    int found = 0;
    bool changed = true;

    // Schleife wiederholt sich so lange bis kein Feld mehr zu einem sicheren Feld oder zu einer Mine wird
    while (changed) {
        changed = false;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                char c = grid[y][x];
                // keine Informationen
                if (c == '?')
                    continue;

                // '.' bedeutet 0, Ziffer gibt Zahl der Minen an
                int need = (c == '.') ? 0 : (c >= '1' && c <= '8' ? c - '0' : 0);

                int mines = 0, unknown = 0;
                int ux[8], uy[8];

                // Nachbarn zählen
                for (int d = 0; d < 8; ++d) {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (!inBounds(ny, nx, h, w)) continue;
                    if (mine[ny][nx]) {
                        ++mines;
                    } else if (!safe[ny][nx] && grid[ny][nx] == '?') {
                        ux[unknown] = nx;
                        uy[unknown] = ny;
                        ++unknown;
                    }
                }

                if (!unknown) continue;

                // Noch benötigte Minen == unbekannte Felder --> alle Minen
                if (need - mines == unknown) {
                    for (int i = 0; i < unknown; ++i) {
                        int nx = ux[i], ny = uy[i];
                        if (!mine[ny][nx]) {
                            mine[ny][nx] = true;
                            ++found;
                            changed = true;
                        }
                    }
                }
                // bereits markierte Minen == Zahl --> alle anderen Felder sicher
                else if (mines == need) {
                    for (int i = 0; i < unknown; ++i) {
                        safe[uy[i]][ux[i]] = true;
                        changed = true;
                    }
                }
            }
        }
    }
    return found;
}

// Falls noch Minen fehlen, steckt jede verbleibende '?'‑Zelle eine
static void fillRemaining(int found){
    for (int x = 0; x < w && found < nb; ++x) {
        for (int y = 0; y < h && found < nb; ++y) {
            if (grid[y][x] == '?' && !mine[y][x] && !safe[y][x]) {
                mine[y][x] = true;
                ++found;
            }
        }
    }
}

// Ergebnis sammeln, sortieren und ausgeben
static void printOutput(){
    Pos *list = malloc(nb * sizeof(Pos));
    int idx = 0;
    for (int x = 0; x < w; ++x){
        for (int y = 0; y < h; ++y){
            if (mine[y][x]){
                list[idx++] = (Pos){x, y};
            }
        }
    }

    // Sortieren
    qsort(list, idx, sizeof(Pos), cmpPos);

    for (int i = 0; i < idx; ++i){
        printf("%d %d\n", list[i].x, list[i].y);
    }

    free(list);
}

static void readInputs(){
    scanf("%d%d", &h, &w);
    scanf("%d", &nb); getchar();
    for (int y = 0; y < h; ++y){
        fgets(grid[y], sizeof(grid[y]), stdin);
    }
}

int main(void) {
    readInputs();
    int found = searchMines();
    fillRemaining(found);
    printOutput();
    return 0;
}