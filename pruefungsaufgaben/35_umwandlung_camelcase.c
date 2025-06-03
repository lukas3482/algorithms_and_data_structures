// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/035%20Umwandlung%20in%20camelCase.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 1000

char** split(char* str, char* splitChar, int* counter){
    char* strCopy = strdup(str);
    char** tokens = calloc(MAX_TOKENS, sizeof(char*));
    int count = 0;

    char* token = strtok(strCopy, splitChar);
    while(token != NULL && count < MAX_TOKENS){
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, splitChar);
    }
    *counter = count;
    free(strCopy);
    return tokens;
}

int main(){
    char input[] = "Hello World";
    int count;
    char** result = split(input, " ", &count);
    for(int i = 0; i < count; i++){
        if(i == 0){
            result[i][0] = tolower(result[i][0]);
            printf("%s", result[i]);
            continue;
        }
        result[i][0] = toupper(result[i][0]);
        printf("%s", result[i]);
    }

    return 0;
}
