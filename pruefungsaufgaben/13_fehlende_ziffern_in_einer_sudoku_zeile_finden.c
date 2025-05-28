// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Fehlende%20Ziffer%20in%20einer%20Sudoku-Zeile%20finden.md
// Created by lukas on 25.03.2025.
//
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

int8_t chartoInt(char c){
  return c - '0';
}

int main(void){
  bool checked[9] = {false, false, false, false, false, false, false, false, false};
  char input[] = "8372?9514";
  int8_t index = 0;
  while(input[index] != '\0'){
    printf("%c", input[index]);
    if(input[index] == '?'){
      index++;
      continue;
    }
    checked[chartoInt(input[index])] = true;
    index++;
  }

  for(int i = 0; i < 9; i++){
    if(!checked[i]){
      printf("%d\n", i);
    }
  }
}
