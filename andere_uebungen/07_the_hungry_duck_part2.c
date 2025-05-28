//https://www.codingame.com/ide/puzzle/the-hungry-duck---part-2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int W,H;
    scanf("%d%d", &W, &H);

    int** lake = calloc(H, sizeof(int*));
    int** dp = calloc(H, sizeof(int*));
    for(int i = 0; i < H; i++){
        lake[i] = calloc(W, sizeof(int));
        dp[i] = calloc(W, sizeof(int));
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int food;
            scanf("%d", &food);
            lake[i][j] = food;
        }
    }
    dp[0][0] = lake[0][0];

    for(int j = 1; j < W; j++){
        dp[0][j] = dp[0][j-1] + lake[0][j];
    }

    for(int i = 1; i < H; i++){
        dp[i][0] = dp[i-1][0] + lake[i][0];
    }

    for(int i = 1; i < H; i++){
        for(int j = 1; j < W; j++){
            int fromTop = dp[i-1][j];
            int fromLeft = dp[i][j-1];
            dp[i][j] = (fromTop > fromLeft ? fromTop : fromLeft) + lake[i][j];
        }
    }

    printf("%d\n", dp[H-1][W-1]);

    for(int i = 0; i < H; i++){
        free(lake[i]);
        free(dp[i]);
    }
    free(lake);
    free(dp);
    return 0;
}
