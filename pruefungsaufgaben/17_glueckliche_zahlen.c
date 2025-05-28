// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Gl%C3%BCckliche%20Zahlen.md
// Created by lukas on 27.03.2025.
//
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>

uint32_t getSumOfDigits(uint32_t number) {
    uint32_t sum = 0;
    while (number % 10 != 0) {
        uint8_t digit = number % 10;
        number /= 10;
        sum += pow(digit, 2);
        printf("digit: %d\n", digit);
    }
    printf("Sum: %d\n", sum);
    return sum;
}

bool isHappyNumber(uint32_t number){
    printf("bla: %d\n", (number < 10) && (number % 10 == 1));
  while (number % 10 != 0) {
      number = getSumOfDigits(number);
  }
  return getSumOfDigits(number) == 1;
}

int main(void){
   uint32_t n = 19;
    printf("%d\n", isHappyNumber(n));

}