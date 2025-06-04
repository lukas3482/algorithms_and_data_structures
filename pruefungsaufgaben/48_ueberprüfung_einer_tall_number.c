// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/048%20%C3%9Cberpr%C3%BCfung%20einer%20%22Tall%20Number%22.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdbool.h>

bool isTallNumber(int num){
    int lastZif = 10000000;
    while(num > 0){
        int zif = num % 10;
        num /= 10;
        if(zif > lastZif){
            return false;
        }
        lastZif = zif;
    }
    return true;
}

int main(){
    int N;
    scanf("%d" , &N);
    printf("%s", isTallNumber(N) ? "true" : "false");
    return 0;
}
