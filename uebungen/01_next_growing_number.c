//https://www.codingame.com/training/easy/next-growing-number
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

void calcGrowingNumber(char* numberStr, uint8_t length);

int main(){
    char n[33];
    scanf("%[^\n]", n);
    sprintf(n, "%lld", atoll(n) + 1);
    calcGrowingNumber(n, strlen(n));
    printf("%s\n", n);
    return 0;
}

uint8_t convertCharToInt(char c){
    return c - '0';
}

char convertIntToChar(uint8_t i){
    return i + '0';
}

void calcGrowingNumber(char* numberStr, uint8_t length){
    bool digitsLocked = false;
    uint8_t last = convertCharToInt(numberStr[0]);
    for(uint8_t i = 0; i < length; i++){
        uint8_t current = convertCharToInt(numberStr[i]);
        if(current < last || digitsLocked){
            numberStr[i] = convertIntToChar(last);
            digitsLocked = true;
        }
        last = convertCharToInt(numberStr[i]);
    }
}