// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/036%20Verbrecherjagd%20%E2%80%93%20Gesuchte%20Zeichen%20z%C3%A4hlen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 100

int main(){
    char* W = calloc(MAX_CHARS, sizeof(char));
    scanf("%s", W);
    int N;
    scanf("%d", &N);

    int* counter = calloc(N, sizeof(int));
    for(int i = 0; i < N; i++){
        char* area = calloc(MAX_CHARS, sizeof(char));
        scanf(" %[^\n]", area);
        int index = 0;
        int count = 0;
        while(area[index] != '\0'){
            if(strchr(W, area[index]) != NULL){
                count++;
            }
            index++;
        }
        counter[i] = count;
    }

    for(int i = 0; i < N; i++){
        printf("%d\n", counter[i]);
    }
    return 0;
}
