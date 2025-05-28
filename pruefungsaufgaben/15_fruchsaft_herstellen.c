// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Fruchtsaft%20herstellen.md
// Created by lukas on 25.03.2025.
//
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

struct Fruchtsaft {
  char art;
  int needed;
};

int main(void){
  uint8_t n = 2;
  scanf("%d", &n);
  fgetc(stdin);

  struct Fruchtsaft saefte[n];
  for(uint8_t i = 0; i < n; i++) {
    char c;
    int g;
    scanf("%c %d", &c, &g);
    fgetc(stdin);

    saefte[i].art = c;
    saefte[i].needed = g;
  }

  char fruits[] = "FFFAFAFAFAFAFAFAAA";

  uint8_t sum = 0;
  for (uint8_t i = 0; i < n; i++) {
    struct Fruchtsaft saft = saefte[i];
    uint8_t length = strlen(fruits);
    uint8_t count = 0;
    for (uint8_t j = 0; j < length; j++) {
      if(saft.art == fruits[j]) {
        count++;
        if(saft.needed == count) {
          sum++;
          count = 0;
        }
      }
    }
  }
  printf("%d\n", sum);
}
