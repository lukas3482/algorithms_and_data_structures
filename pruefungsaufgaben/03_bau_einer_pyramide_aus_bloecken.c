// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Bau%20einer%20Pyramide%20aus%20Bl%C3%B6cken.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>

int main(){
  int n = 10;

  for(int i = n; i >= 0; i--){
    int blocks = i * (i + 1)/2;
    if(blocks <= n){
      printf("%d %d\n", i, n - blocks);
      break;
    }
  }
}