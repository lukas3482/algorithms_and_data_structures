// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Berechnung%20der%20Ackermann-Funktion.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>

int A(int m, int n) {
    if(m == 0)
      return n + 1;

    if(m > 0 && n == 0)
      return A(m - 1, 1);

    if(m > 0 && n > 0)
      return A(m - 1, A(m, n -1));

    return -1;
}

int main(){
    int m = 2;
    int n = 3;

    printf("%d\n", A(m, n));
}