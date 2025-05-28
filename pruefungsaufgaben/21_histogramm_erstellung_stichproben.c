// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/021%20Histogramm-Erstellung%20aus%20Stichproben.md
// Created by lukas on 28.05.2025.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d",&n);
    int* arr = calloc(10,sizeof(int));

    for(int i=0;i<n;i++) {
        int zahl;
        scanf("%d", &zahl);
        arr[zahl] = arr[zahl] + 1;
    }

    for (int i = 1; i <= 9;i++) {
        printf("%d:",i);
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}