//
// Created by lukas on 09.04.2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define MAX_H 40
#define MAX_W 40
#define MAX_N 100
#define MAX_WORD_LEN 40

int32_t dx[8] = {  0,    0,    1,   -1,    1,   -1,   -1,    1 };
int32_t dy[8] = {  1,   -1,    0,    0,    1,   -1,    1,   -1 };

int32_t h, w;
char grid[MAX_H][MAX_W + 1];
bool used[MAX_H][MAX_W];

bool findWord(char* word) {
    int32_t len = strlen(word);
    for (int32_t y = 0; y < h; y++) {
        for (int32_t x = 0; x < w; x++) {
            for (int32_t d = 0; d < 8; d++) {
                int32_t i, nx = x, ny = y;
                for (i = 0; i < len; i++) {
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                        break;
                    if (grid[ny][nx] != word[i])
                        break;
                    nx += dx[d];
                    ny += dy[d];
                }
                if (i == len) {
                    nx = x;
                    ny = y;
                    for (i = 0; i < len; i++) {
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

int main()
{
    int32_t n;
    scanf("%d", &n);
    char words[MAX_N][MAX_WORD_LEN + 1];
    for (int32_t i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    scanf("%d%d", &h, &w);
    for (int32_t i = 0; i < h; i++) {
        scanf("%s", grid[i]);
    }

    memset(used, 0, sizeof(used));

    for (int32_t i = 0; i < n; i++) {
        findWord(words[i]);
    }

    char secretWord[1601];
    int pos = 0;
    for (int32_t y = 0; y < h; y++) {
        for (int32_t x = 0; x < w; x++) {
            if (!used[y][x]) {
                secretWord[pos++] = grid[y][x];
            }
        }
    }

    secretWord[pos] = '\0';
    printf("%s\n", secretWord);
    return 0;
}