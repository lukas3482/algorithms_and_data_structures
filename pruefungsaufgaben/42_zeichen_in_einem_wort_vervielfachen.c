// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/042%20Zeichen%20in%20einem%20Wort%20vervielfachen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char input[] = "bonobo";
    int* speicher = calloc('z' - 'a', sizeof(int));
    char* output = calloc(10000, sizeof(char));

    int len = strlen(input);
    int outputIndex = 0;
    for(int i = 0; i < len; i++){
        int vorkommen = speicher[input[i] - 'a'];
        vorkommen++;
        for(int j = 0; j < vorkommen; j++){
            output[outputIndex] = input[i];
            outputIndex++;
        }
        speicher[input[i] - 'a'] = vorkommen;
    }
    output[outputIndex+1] = '\0';
    printf("%s", output);
    return 0;
}