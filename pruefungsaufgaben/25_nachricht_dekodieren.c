// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/025%20%20Nachricht%20dekodieren.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char input[] = "CiaonmdGe";
    int len = strlen(input);
    int raster = sqrt(len);

    int i,j = 0;
    int durchlauf = 1;
    char* decodedStr = calloc(len, sizeof(char));
    while(1){
        if(durchlauf > raster)
            break;

        if(i >= len){
            i = durchlauf;
            durchlauf++;
        }

        decodedStr[j] = input[i];
        j++;
        i = i + raster;
    }
    decodedStr[len] = '\0';
    printf("%s", decodedStr);
    return 0;
}
