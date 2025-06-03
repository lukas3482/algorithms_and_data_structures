// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/022%20Hohles%20Quadrat%20aus%20%60%23%60-Symbolen.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>

void print(int count){
    for(int i = 0; i < count; i++){
        printf("#");
    }
    printf("\n");
}

int main(void){
    int N = 5;

    for(int i = 0; i < N; i++){
        if(i == 0 || i == N-1){
            print(N);
        }else{
            printf("#");
            for(int j = 0; j < N-2; j++){
                printf(" ");
            }
            printf("#\n");
        }

    }
    return 0;
}