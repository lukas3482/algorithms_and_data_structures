// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/Die%20mittlere%20Zahl%20aus%20einem%20Tripel%20finden.md
// Created by lukas on 21.03.2025.
//
#include <stdio.h>

void bubbleSort(int* arr){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(){
  int n = 5;
  for(int i = 0; i < n; i++){
    int a,b,c = 0;
    scanf("%d %d %d",&a,&b,&c);
    int arr[3] = {a, b, c};
    bubbleSort(arr);
    printf("%d\n",arr[1]);
  }
}
