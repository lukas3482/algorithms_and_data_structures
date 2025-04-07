// https://www.codingame.com/training/easy/cosmic-love
// Created by lukas on 03.04.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct Planet{
    char name[101];
    double radius;
    double mass;
    double distance;
    double density;
 };

double calcVol(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double calcDensity(double mass, double volume) {
    return mass / volume;
}

double calcRochLimit(double radiusAlice, double densityAlice, double densityPlanet) {
    return radiusAlice * cbrt((2.0 * densityAlice) / densityPlanet);
}

int main(){
    int N;
    scanf("%d", &N);

    struct Planet alice = {0};
    struct Planet *planets = calloc(N, sizeof(struct Planet));
    for (int i = 0; i < N; i++) {
        struct Planet planet;

        scanf("%100s %lf %lf %lf", planet.name, &planet.radius, &planet.mass, &planet.distance);
        planet.density = calcDensity(planet.mass, calcVol(planet.radius));
        if(strcmp(planet.name, "Alice") == 0){
            alice = planet;
        }

        planets[i] = planet;
    }

    int closestIndex = -1;
    for(int i = 0; i < N; i++){
        struct Planet planet = planets[i];

        if(planet.distance == 0){
            continue;
        }

        double rocheLimit = calcRochLimit(alice.radius, alice.density, planet.density);

        if (planet.distance > rocheLimit) {
            if (closestIndex == -1 || planet.distance < planets[closestIndex].distance) {
                closestIndex = i;
            }
        }
    }

    if (closestIndex != -1) {
        printf("%s\n", planets[closestIndex].name);
    } else {
        printf("Keinen passenden Planeten gefunden.\n");
    }

    free(planets);
    return 0;
}