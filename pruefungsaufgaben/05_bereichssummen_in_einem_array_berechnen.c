// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Bereichssummen%20in%20einem%20Array%20berechnen.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>
#include <stdlib.h>

int charToInt(char ch){
  return ch - '0';
}

int main(){
  // Keine Ahnung ob der Input so richtig ist...
  int n = 4;
  char liste[] = "4 2 5 8";
  int m = 3;
  char bereichsStr[3][3] = {"0 3", "1 2", "3 3"};

  int* nArray = calloc(n, sizeof(int));

  int index = 0;
  int newIndex = 0;
  while (liste[index] != '\0') {
    if (liste[index] != ' ') {
      nArray[newIndex] = charToInt(liste[index]);
      newIndex++;
    }
    index++;
  }

  for (int i = 0; i < m; i++) {
    int a = charToInt(bereichsStr[i][0]);
    int b = charToInt(bereichsStr[i][2]);
    int sum = 0;
    for (int j = a; j <= b; j++) {
      sum += nArray[j];
    }
    printf("%d\n", sum);
  }
}
