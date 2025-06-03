// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/026%20Pangramm-Pr%C3%BCfung.md
// Created by lukas on 03.06.2025.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(){
    char input[] = "Abcde fghij klmno pqrs tuv wxyz";
    bool check['z' - 'a'];
    int len = strlen(input);

    for(int i = 0; i < len; i++){
        check[tolower(input[i]) - 'a'] = true;
    }

    bool isPangramm = true;
    for(int i = 0; i < 'z' - 'a'; i++){
        if(!check[i])
            isPangramm = false;
    }

    printf("%s", isPangramm ? "true" : "false");
    return 0;
}
