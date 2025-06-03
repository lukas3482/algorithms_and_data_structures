// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/027%20Parkplatzauslastung.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Auto;

bool isCarThere(Auto a, int hour){
    return a.start <= hour && a.end > hour;
}

int main(void){
    int N;
    scanf("%d", &N);
    Auto* autos = calloc(N, sizeof(Auto));
    for(int i = 0; i < N; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        autos[i].start = start;
        autos[i].end = end;
    }

    int hours = 0;
    for(int i = 1; i <= 24; i++){
        bool car = false;
        for(int j = 0; j < N; j++){
            if(isCarThere(autos[j], i)){
                car = true;
            }
        }
        if(car)
            hours++;
    }
    printf("%d", hours);
    return 0;
}
