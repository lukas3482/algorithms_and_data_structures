// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/040%20Zahlenraten-Spiel.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int r = rand() % 100 + 1;
    printf("Versuche die Zahl zwischen 1 und 100 zu erraten!\n");
    int zahl;
    while(1){
        scanf("%d", &zahl);
        if(zahl == r){
            printf("Herzlichen Glückwunsch! Sie haben die Zahl erraten.");
            break;
        }

        if(zahl > r){
            printf("Zu hoch!\n");
        }

        if(zahl < r){
            printf("Zu niedrig!\n");
        }
    }

    return 0;
}
