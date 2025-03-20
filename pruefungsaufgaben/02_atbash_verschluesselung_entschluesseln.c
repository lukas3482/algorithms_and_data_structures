// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Atbash-Verschl%C3%BCsselung%20entschl%C3%BCsseln.md
// Created by lukas on 20.03.2025.
#include <stdio.h>
#include <strings.h>

char findMirrorChar(char c) {
  char abc[] = "abcdefghijklmnopqrstuvwxyz";
  char zyx[] = "zyxwvutsrqponmlkjighfedcba";
  int index = 0;
  while(abc[index] != '\0') {
    if (abc[index] == c)
      return zyx[index];
    index++;
  }
  return -1;
}

int main(){
  char input[] = "zyxabc";
  int length = strlen(input);

  char output[length];
  for(int i = 0; i < length; i++){
    output[i] = findMirrorChar(input[i]);
  }
  printf("%s\n", output);
}