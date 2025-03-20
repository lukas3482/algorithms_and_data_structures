//https://www.codingame.com/ide/puzzle/credit-card-verifier-luhns-algorithm
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

int32_t convertCharToInt(char c){
    return c - '0';
}

char *removeSpaces(char *card) {
    char* newCard = calloc(17, sizeof(char));
    int newIndex = 0;
    for (int i = 0; card[i] != '\0'; ++i) {
        if (card[i] != ' ') {
            newCard[newIndex++] = card[i];
        }
    }
    newCard[16] = '\0';
    return newCard;
}

bool verify(char *card) {
    int32_t sum = 0;
    for (int i = 0; i < 16; i++) {
        int digit = convertCharToInt(card[15 - i]);
        if (i % 2 == 1) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
    }
    return sum % 10 == 0;
}

int main(){
    int n;
    scanf("%d", &n); fgetc(stdin);
    for (int i = 0; i < n; i++) {
        char card[21];
        scanf("%[^\n]", card); fgetc(stdin);
        printf("%s\n", verify(removeSpaces(card)) ? "YES" : "NO");
    }
    return 0;
}