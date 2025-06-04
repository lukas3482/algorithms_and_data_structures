// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/043%20Zeichenfolgen%20durch%20ihre%20L%C3%A4nge%20ersetzen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 1000

char intToChar(int i) {
    return '0' + i;
}

char** split(char* str, char* splitChar, int* counter) {
    char* strCopy = strdup(str);
    char** tokens = calloc(MAX_TOKENS, sizeof(char*));
    int count = 0;

    char* token = strtok(strCopy, splitChar);
    while(token != NULL && count < MAX_TOKENS) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, splitChar);
    }
    *counter = count;
    free(strCopy);
    return tokens;
}

int main() {
    char C[] = "l";
    char input[] = "Hello World";
    int counter;
    char** result = split(input, " ", &counter);

    int* speicher = calloc(counter, sizeof(int));
    for(int i = 0; i < counter; i++) {
        int len = strlen(result[i]);
        for(int j = 0; j < len; j++) {
            if(result[i][j] == C[0]) {
                speicher[i] = speicher[i] + 1;
            }
        }
    }

    int inLen = strlen(input);
    char* output = calloc(inLen, sizeof(char));
    int outIndex = 0;
    bool wasC = false;
    for(int i = 0; i < counter; i++) {
        int len = strlen(result[i]);
        for(int j = 0; j < len; j++){
            if(result[i][j] == C[0]){
                if(!wasC){
                    output[outIndex] = intToChar(speicher[i]);
                    outIndex++;
                    wasC = true;
                }
            }else{
                output[outIndex] = result[i][j];
                outIndex++;
                wasC = false;
            }
        }
        output[outIndex] = ' ';
        outIndex++;
    }
    output[outIndex+1] = '\0';
    printf("%s", output);
    return 0;
}