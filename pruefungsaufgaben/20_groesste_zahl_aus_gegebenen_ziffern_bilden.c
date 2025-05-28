// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/020%20Gr%C3%B6%C3%9Fte%20Zahl%20aus%20gegebenen%20Ziffern%20bilden.md
// Created by lukas on 28.05.2025.
//
#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        perror("calloc failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp_desc);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
