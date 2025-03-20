// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Extrahiere%20W%C3%B6rter%20von%20den%20Diagonalen%20eines%20Gitters.md
// Created by lukas on 21.03.2025.
//
#include <stdio.h>

int main(){
  int n = 4;
  char input[5][5] = {"mooa",
                      "oano",
                      "otio",
                      "ioon"};
  char word1[5];
  char word2[5];
  for(int i = 0; i < n; i++){
    word1[i] = input[i][i];
  }
  word1[4] = '\0';

  for(int i = 0; i < n; i++){
    word2[i] = input[i][3 - i];
  }
  word2[4] = '\0';

  printf("%s %s\n", word1, word2);
}