// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Buchstaben%20durch%20Ziffern%20teilen.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>
#include <stdbool.h>

bool isNumber(char ch){
  return ch >= '0' && ch <= '9';
}

bool isLetter(char ch){
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main(){
  char input[] = "Hel10 W0r1d!";

  int countNumber = 0;
  int countLetter = 0;
  int index = 0;
  while(input[index] != '\0'){
    if(isNumber(input[index])){
      countNumber++;
    }
    if(isLetter(input[index])){
      countLetter++;
    }
    index++;
  }
  printf("%d\n", countLetter/countNumber);
}