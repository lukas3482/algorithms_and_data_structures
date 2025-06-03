// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/038%20Wechselgeld%20mit%20den%20wenigsten%20M%C3%BCnzen%20berechnen.md
// Created by lukas on 04.06.2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[16];
    int cents;

    scanf("%s", input);

    int dollars, remaining_cents;
    sscanf(input + 1, "%d.%d", &dollars, &remaining_cents);
    cents = dollars * 100 + remaining_cents;

    int coin_values[] = {100, 25, 10, 5, 1};
    int coin_counts[5] = {0};

    for (int i = 0; i < 5; i++) {
        coin_counts[i] = cents / coin_values[i];
        cents %= coin_values[i];
    }

    for (int i = 0; i < 5; i++) {
        printf("%d", coin_counts[i]);
        if (i < 4) printf(" ");
    }
    printf("\n");
    return 0;
}
