//
// Created by lukas on 25.05.2025.
//
#include <stdlib.h>
#include <stdio.h>

// Kleinsten Zeitwert unter R Räubern finden
static int findMinRobber(unsigned long long *robbers, int R){
    int idx = 0;
    for (int i = 1; i < R; ++i)
        if (robbers[i] < robbers[idx])
            idx = i;
    return idx;
}

int main(void){
    int R, V;
    if (scanf("%d", &R) != 1) return 0;
    if (scanf("%d", &V) != 1) return 0;

    unsigned long long *robbers = calloc(R, sizeof(unsigned long long));
    if (!robbers) return 0;

    for (int i = 0; i < V; ++i) {
        int C, N;
        scanf("%d %d", &C, &N);

        unsigned long long t = 1ULL;
        for (int j = 0; j < N;     ++j) t *= 10ULL;
        for (int j = 0; j < C - N; ++j) t *= 5ULL;

        // Räuber mit aktuell geringster Belastung wählen
        int r = findMinRobber(robbers, R);
        robbers[r] += t;
    }

    // Gesamtdauer = längste belegte Zeit eines Räubers
    unsigned long long total = 0ULL;
    for (int i = 0; i < R; ++i)
        if (robbers[i] > total) total = robbers[i];

    printf("%llu\n", total);

    free(robbers);
    return 0;
}
