// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/037%20Verschwundene%20Socken%20beim%20Waschen%20finden.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_COLOR_LEN 21

typedef struct {
    int size;
    char color[MAX_COLOR_LEN];
    int count;
} Sock;

int compare_socks(const void* a, const void* b) {
    Sock* sa = (Sock*)a;
    Sock* sb = (Sock*)b;
    if (sa->size != sb->size)
        return sa->size - sb->size;
    return strcmp(sa->color, sb->color);
}

int main() {
    int N;
    scanf("%d", &N);

    Sock socks[MAX_ITEMS];
    int sockCount = 0;

    for (int i = 0; i < N; i++) {
        char type[16];
        int size;
        char color[MAX_COLOR_LEN];
        scanf("%s %d %s", type, &size, color);

        if (strcmp(type, "sock") != 0)
            continue;

        int found = 0;
        for (int j = 0; j < sockCount; j++) {
            if (socks[j].size == size && strcmp(socks[j].color, color) == 0) {
                socks[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            socks[sockCount].size = size;
            strcpy(socks[sockCount].color, color);
            socks[sockCount].count = 1;
            sockCount++;
        }
    }

    Sock missing[MAX_ITEMS];
    int missingCount = 0;

    for (int i = 0; i < sockCount; i++) {
        if (socks[i].count % 2 != 0) {
            missing[missingCount++] = socks[i];
        }
    }

    qsort(missing, missingCount, sizeof(Sock), compare_socks);

    printf("%d\n", missingCount);
    for (int i = 0; i < missingCount; i++) {
        printf("%d %s\n", missing[i].size, missing[i].color);
    }

    return 0;
}
