//https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Anzahl%20der%20Quadratzahlen%20in%20einem%20Bereich.md
#include <stdio.h>
#include <math.h>

int main(void){
    int a = 26;
    int b = 35;

    int count = 0;
    for(int i = a; i <= b; i++){
        int resultSqrt = sqrt(i);
        if(pow(resultSqrt, 2) == i){
            count++;
        }
    }

    printf("%d", count);
}