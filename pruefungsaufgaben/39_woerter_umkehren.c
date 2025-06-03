// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/039%20W%C3%B6rter%20in%20einem%20Satz%20umkehren.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1000

char** split(char* str, char* splitter, int* counter){
    char* strCopy = strdup(str);
    char** tokens = calloc(MAX_TOKENS, sizeof(char*));

    int count = 0;
    char* token = strtok(strCopy, splitter);
    while(token != NULL){
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL , splitter);
    }
    *counter = count;
    free(strCopy);
    return tokens;
}

int main(){
    char input[] = "Hello World";
    int count;
    char** result = split(input, " ", &count);
    for(int i = count-1; i >= 0; i--){
        printf("%s ", result[i]);
    }
    return 0;
}
