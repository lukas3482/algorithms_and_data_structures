// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/033%20Summe%20aller%20geraden%20Zahlen%20berechnen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>

int main(){
    int N = 10;
    int sum = 0;
    for(int i = 0; i <= 10; i += 2){
        sum += i;
    }
    printf("%d", sum);
    return 0;
}