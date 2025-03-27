//https://www.codingame.com/ide/puzzle/longest-increasing-subsequence
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

int main(){
    int n;
    scanf("%d", &n);
    int32_t* arr = calloc(n, sizeof(int32_t));
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        arr[i] = p;
    }

    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    printf("%d\n", max);

    return 0;
}