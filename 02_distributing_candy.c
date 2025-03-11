//https://www.codingame.com/training/easy/distributing-candy
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <inttypes.h>


void bubbleSort(int32_t array[], int32_t lenght);
int32_t findMinDiff(int32_t array[], int32_t lenght, int32_t numbers);

int main(){
    int32_t n, m;
    scanf("%d%d", &n, &m);

    int32_t* amount = calloc(n, sizeof(int32_t));
    for (int32_t i = 0; i < n; i++) {
        int32_t x;
        scanf("%d", &x);
        amount[i] = x;
    }

    //Evtl. qsort() von stdlib.h verwenden
    bubbleSort(amount, n);    
    printf("%d", findMinDiff(amount, n, m-1));
    free(amount);
    return 0;
}

void bubbleSort(int32_t array[], int32_t lenght){
    bool swapped = false;
    do {
        swapped = false;
        for(int32_t i = 0; i < lenght - 1; i++){
            if(array[i] > array[i+1]){
                int32_t temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = true;
            }
        }
    }while(swapped);
}

int32_t findMinDiff(int32_t amount[], int32_t length, int32_t numbers) {
    int32_t smallest = INT_MAX;
    for (int32_t i = 0; (i + numbers) < length; i++) {
        int32_t diff = amount[i + numbers] - amount[i];
        if (diff < smallest) {
            smallest = diff;
        }
    }
    return smallest;
}