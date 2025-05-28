//https://github.com/TeleparioAlf/Programmieraufgaben/blob/main/008%20Defekte%20Hashmap.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* key;
    int value;
    bool occupied;
} Entry;

int main(void){
    int n;
    scanf("%d", &n);

    Entry* map = calloc(26, sizeof(Entry));

    for (int i = 0; i < n; i++) {
        char tempKey[101];
        int val;
        scanf("%s %d", tempKey, &val);

        int index = tempKey[0] - 'a';

        if (map[index].occupied) {
            free(map[index].key);
        }

        map[index].key = strdup(tempKey);
        map[index].value = val;
        map[index].occupied = true;
    }

    for (int i = 0; i < 26; i++) {
        if (map[i].occupied) {
            printf("%c: %s=%d\n", 'a' + i, map[i].key, map[i].value);
            free(map[i].key);
        }
    }

    free(map);
    return 0;
}
