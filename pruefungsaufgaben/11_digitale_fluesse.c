// https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/011%20Digitale%20Fl%C3%BCsse.md
#include <stdio.h>

int quersumme(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int r1, r2;
    scanf("%d", &r1);
    scanf("%d", &r2);

    int f1 = r1;
    int f2 = r2;

    while (f1 != f2) {
        if (f1 < f2) {
            f1 += quersumme(f1);
        } else {
            f2 += quersumme(f2);
        }
    }

    printf("%d\n", f1);
    return 0;
}
