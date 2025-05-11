#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Finde das Maximum
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > max)
            max = lis[i];
    }

    printf("%d\n", max);

    return 0;
}
