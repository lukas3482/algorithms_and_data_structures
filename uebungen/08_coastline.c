#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double left;
    double right;
} Interval;

int cmpRight(const void *a, const void *b){
    double diff = ((const Interval *)a)->right - ((const Interval *)b)->right;
    return (diff < 0) ? -1 : (diff > 0);
}

int main(void){
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int t = 0; t < n; ++t) {
        int p, r;
        if (scanf("%d %d", &p, &r) != 2) break;

        Interval ivals[110];
        bool possible = true;

        for (int i = 0; i < p; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);

            // Punkt liegt außerhalb des Radius
            if (y > r) {
                possible = false;
            }

            if (possible) {
                double horiz = sqrt((double)r * r - (double)y * y);
                ivals[i].left  = x - horiz;
                ivals[i].right = x + horiz;
            }
        }

        if (!possible) {
            printf("-1\n");
            continue;
        }

        qsort(ivals, p, sizeof(Interval), cmpRight);

        int count = 0;
        double pos = -1e100;

        for (int i = 0; i < p; ++i) {
            if (count == 0 || ivals[i].left > pos) {
                pos = ivals[i].right;
                ++count;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
