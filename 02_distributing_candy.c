//https://www.codingame.com/training/easy/distributing-candy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


void sort(int array[], int lenght);
int findMinDiff(int array[], int lenght, int numbers);

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    int* amount = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        amount[i] = x;
    }

    //Evtl. qsort() von stdlib.h verwenden
    sort(amount, n);    
    printf("%d", findMinDiff(amount, n, m-1));
    return 0;
}

//BubbleSort
void sort(int array[], int lenght){
    bool swapped = false;
    do {
        swapped = false;
        for(int i = 0; i < lenght - 1; i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swapped = true;
            }
        }
    }while(swapped);
}

int findMinDiff(int amount[], int length, int numbers) {
    int smallest = INT_MAX;
    for (int i = 0; (i + numbers) < length; i++) {
        int diff = amount[i + numbers] - amount[i];
        if (diff < smallest) {
            smallest = diff;
        }
    }
    return smallest;
}