// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/034%20Syracuse-%20(Collatz-)%20Folge.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>

int main(){
    int N = 5;
    while(N != 1){
        printf("%d ", N);
        if(N % 2 == 0){
            N /= 2;
        }else{
            N = N*3+1;
        }
    }
    printf("%d", N);

    return 0;
}
