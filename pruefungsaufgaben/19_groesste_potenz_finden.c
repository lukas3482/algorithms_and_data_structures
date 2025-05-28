// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/019%20Gr%C3%B6%C3%9Fte%20Potenz%20finden.md
// Created by lukas on 28.05.2025.
//
#include <stdio.h>
#include <math.h>

int findBiggest(int n, int p, int m) {
    int potenz = pow(p, m+1);
    if (potenz < n) {
        return findBiggest(n, p, m+1);
    }
    return m;
}

int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d\n", findBiggest(n, p, 0));
}