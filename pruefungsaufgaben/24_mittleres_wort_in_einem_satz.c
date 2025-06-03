//
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char input[] = "1 4 potato 6";
    int len = strlen(input);

    int count = 1;
    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            count++;
        }
    }

    char** strings = calloc(count, sizeof(char*));
    int currentString = 0;
    int currentStringIndex = 0;
    strings[currentString] = calloc(1048, sizeof(char));

    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            strings[currentString][currentStringIndex] = '\0';
            currentString++;
            currentStringIndex = 0;
            strings[currentString] = calloc(1048, sizeof(char));
            continue;
        }
        strings[currentString][currentStringIndex++] = input[i];
    }
    strings[currentString][currentStringIndex] = '\0';

    if(count % 2 == 0){
        int mid = count / 2;
        printf("%s%s", strings[mid-1], strings[mid]);
    }else{
        printf("%s", strings[count / 2]);
    }

    for(int i = 0; i < count; i++){
        free(strings[i]);
    }
    free(strings);

    return 0;
}
