// https://www.codingame.com/ide/puzzle/1--ngr---basic-radar
// Created by lukas on 11.04.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int DISTANCE = 13;
#define MAX_CARS 1000

struct Car {
    char *plate;
    long long timestamp1;
    long long timestamp2;
} Car;

struct Car cars[MAX_CARS];
int currentCar = 0;

int getCarIndexByPlate(char* plate){
    for(int i = 0; i < currentCar; i++){
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

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char plate[101];
        char radarname[7];
        long long timestamp;
        scanf("%s%s%lld", plate, radarname, &timestamp);
        if(strcmp(radarname, "A21-42") == 0){
            cars[currentCar].plate = strdup(plate);
            cars[currentCar].timestamp1 = timestamp;
            currentCar++;
        }else {
            int index = getCarIndexByPlate(plate);
            cars[index].timestamp2 = timestamp;
        }
    }

    qsort(cars, currentCar, sizeof(struct Car), compareCarsByPlate);
    for(int i = 0; i < currentCar; i++){
        struct Car car = cars[i];
        int  speed = calcSpeed(car);
        if(speed > 130){
            printf("%s %d\n", car.plate, speed);
        }

    }

    for (int i = 0; i < currentCar; i++) {
        free(cars[i].plate);
    }
    return 0;
}