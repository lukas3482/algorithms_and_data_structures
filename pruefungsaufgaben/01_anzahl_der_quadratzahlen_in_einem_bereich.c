//https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Anzahl%20der%20Quadratzahlen%20in%20einem%20Bereich.md
#include <stdio.h>
#include <math.h>

int main(void){
    int a = 1;
    int b = 9;

    int count = 0;
    for(int i = a; i <= b; i++){
        int resultSqrt = sqrt(i);
        if(pow(resultSqrt, 2) == i){
            count++;
        }
    }

    printf("%d", count);
}