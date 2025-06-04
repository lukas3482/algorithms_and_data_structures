// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/045%20Zykluserkennung.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int N;
    scanf("%d" , &N);
    int* zeichenFolge = calloc(N, sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d" , &zeichenFolge[i]);
    }

    bool erfolgreich = false;
    int versuche = 0;
    int currentIndex = 0;
    while(versuche < N){
        currentIndex = zeichenFolge[currentIndex];
        if(currentIndex == 0){
            erfolgreich = true;
            break;
        }
        versuche++;
    }
    printf("%s", erfolgreich ? "true" : "false");
    return 0;
}
