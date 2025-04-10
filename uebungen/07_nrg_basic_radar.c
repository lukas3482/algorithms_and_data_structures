// https://www.codingame.com/ide/puzzle/1--ngr---basic-radar
// Created by lukas on 11.04.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CARS 1000
const int DISTANCE = 13;

struct Car {
    char *plate;
    long long timestamp1;
    long long timestamp2;
};

struct Car cars[MAX_CARS];
int carCount;

int getCarIndexByPlate(char* plate);
int calcSpeed(struct Car car);
int compareCarsByPlate(const void* a, const void* b);

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char plate[101];
        char radarname[7];
        long long timestamp;
        scanf("%s%s%lld", plate, radarname, &timestamp);

        if(strcmp(radarname, "A21-42") == 0){
            cars[carCount].plate = strdup(plate);
            cars[carCount].timestamp1 = timestamp;
            carCount++;
        }else {
            int index = getCarIndexByPlate(plate);
            cars[index].timestamp2 = timestamp;
        }
    }

    qsort(cars, carCount, sizeof(struct Car), compareCarsByPlate);
    for(int i = 0; i < carCount; i++){
        struct Car car = cars[i];
        int  speed = calcSpeed(car);
        if(speed > 130){
            printf("%s %d\n", car.plate, speed);
        }
    }

    for (int i = 0; i < carCount; i++) {
        free(cars[i].plate);
    }
    return 0;
}

int getCarIndexByPlate(char* plate){
    for(int i = 0; i < carCount; i++){
        if(strcmp(cars[i].plate, plate) == 0){
            return i;
        }
    }
    return -1;
}

int calcSpeed(struct Car car){
    double timeDiff = (double)(car.timestamp2 - car.timestamp1);
    double speed = DISTANCE / (timeDiff / 1000 / 60 / 60);
    return (int)(speed);
}

int compareCarsByPlate(const void* a, const void* b) {
    struct Car* carA = (struct Car*)a;
    struct Car* carB = (struct Car*)b;
    return strcmp(carA->plate, carB->plate);
}