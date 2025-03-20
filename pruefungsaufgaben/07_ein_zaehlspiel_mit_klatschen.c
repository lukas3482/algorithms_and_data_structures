// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Clap%407%20%E2%80%93%20Ein%20Z%C3%A4hlspiel%20mit%20Klatschen.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>
#include <stdbool.h>

bool isDivisible(int number){
  return number % 7 == 0;
}

bool contains(int number){
  while(number){
    if(number % 10 == 7){
      return true;
    }
    number = number / 10;
  }
  return false;
}

bool isCrossSumDivisible(int number) {
  int sum = 0;
  while(number){
    sum += number % 10;
    number = number / 10;
  }
  return isDivisible(sum);
}


int main(){
  int n = 17;
  int claps = 0;
  for (int i = 0; i < n; i++) {
    claps += isCrossSumDivisible(i) || isDivisible(i) || contains(i);
  }
  printf("%d\n", claps);
}