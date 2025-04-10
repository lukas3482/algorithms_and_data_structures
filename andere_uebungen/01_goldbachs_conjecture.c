//
// Created by lukas on 09.04.2025.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <inttypes.h>

int32_t mMax = 1000000;

void calcNonPrimeNumbers(bool* isNotPrime, int32_t to);
int32_t checkForSums(bool* noPrimes, int32_t number);

int main(){
    int n;
    scanf("%d", &n);

    bool* noPrimes = calloc(mMax + 1, sizeof(bool));
    calcNonPrimeNumbers(noPrimes, mMax + 1);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        printf("%d\n", checkForSums(noPrimes, m));
    }

    free(noPrimes);
    return 0;
}

void calcNonPrimeNumbers(bool* isNotPrime, int32_t to){
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    int32_t max = sqrt(to);
    for(int i = 2; i < max; i++){
        if(!isNotPrime[i]){
            for(int j = i*i; j < to; j += i){
                isNotPrime[j] = true;
            }
        }
    }
}

int32_t checkForSums(bool* noPrimes, int32_t number){
    int32_t sums = 0;
    for(int32_t i = 2; i < number; i++){
        if(!noPrimes[i]){
            int32_t b = number - i;
            if(i > b) break;
            if(!noPrimes[b]){
                sums++;
            }
        }
    }
    return sums;
}