//
// Created by lukas on 09.04.2025.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define MAX 40

int32_t dx[8] = {  0,  0,  1, -1,  1, -1, -1,  1 };
int32_t dy[8] = {  1, -1,  0,  0,  1, -1,  1, -1 };

int32_t h, w;
char grid[MAX][MAX + 1];
bool used[MAX][MAX];

bool searchWord(const char* word) {
    int lenght = strlen(word);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int d = 0; d < 8; d++) {
                int i;
                int nx = x, ny = y;

                for (i = 0; i < lenght; i++) {
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) break;
                    if (grid[ny][nx] != word[i]) break;

                    nx += dx[d];
                    ny += dy[d];
                }

                if (i == lenght) {
                    nx = x;
                    ny = y;
                    for (i = 0; i < lenght; i++) {
                        used[ny][nx] = true;
                        nx += dx[d];
                        ny += dy[d];
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    int n;
    scanf("%d", &n);

    char words[100][MAX + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", grid[i]);
    }

    memset(used, false, sizeof(used));

    for (int i = 0; i < n; i++) {
        searchWord(words[i]);
    }

    char hiddenWord[1601];
    int pos = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!used[y][x]) {
                hiddenWord[pos++] = grid[y][x];
            }
        }
    }

    hiddenWord[pos] = '\0';
    printf("%s\n", hiddenWord);

    return 0;
}
