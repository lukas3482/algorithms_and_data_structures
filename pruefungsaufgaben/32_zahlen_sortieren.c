// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/032%20Sortiere%20Zahlen%20in%20einem%20Summenausdruck.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 100

char** split(const char* str, const char* delimiter, int* tokenCount){
    char* str_copy = strdup(str);
    char** tokens = malloc(MAX_TOKENS * sizeof(char*));
    int count = 0;
    char* token = strtok(str_copy, delimiter);
    while (token != NULL && count < MAX_TOKENS) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, delimiter);
    }

    *tokenCount = count;
    free(str_copy);
    return tokens;
}

int compare_strings(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    return strcmp(sa, sb);
}

int main(){
    char input[] = "1+3+2";

    int count;
    char** result = split(input, "+", &count);
    qsort(result, count, sizeof(char*), compare_strings);

    for(int i = 0; i < count; i++){
        if(i == count-1){
            printf("%s", result[i]);
        }else{
            printf("%s+", result[i]);
        }
    }

    return 0;
}