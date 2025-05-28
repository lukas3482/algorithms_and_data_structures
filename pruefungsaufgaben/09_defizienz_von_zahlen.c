// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Defizienz%20von%20Zahlen.md
// Created by lukas on 20.03.2025.
//
#include <stdio.h>

int getDefizients(int number){
  int sum = 0;
  for (int i = 1; i <= number; i++) {
    if(number % i == 0){
      sum += i;
    }
  }

  if(sum > number*2)
    return 0;
  return number*2 - sum;
}

int getIntFromChar(char ch) {
  return ch - '0';
}

int main(){
  int n = 4;

  for(int i = 0; i < n; i++){
    int a, b = 0;
    scanf("%d %d", &a, &b);

    int sum = 0;
    for(int j = a; j <= b; j++) {
      sum += getDefizients(j);
    }
    printf("%d\n", sum);
  }
}
