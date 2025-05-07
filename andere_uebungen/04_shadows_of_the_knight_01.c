#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct Pos {
    int x;
    int y;
} Pos;

typedef enum {
    DIR_INVALID = -1,
    UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT
} Direction;

typedef struct {
    const char *name;
    Direction   dir;
} DirMap;

static const DirMap dir_map[] = {
    { "U",  UP          },
    { "UR", UP_RIGHT    },
    { "R",  RIGHT       },
    { "DR", DOWN_RIGHT  },
    { "D",  DOWN        },
    { "DL", DOWN_LEFT   },
    { "L",  LEFT        },
    { "UL", UP_LEFT     },
};

int W,H,N;
int X0,Y0;
Pos currentPos;


Direction parseDirection(const char *s){
    for (size_t i = 0; i < sizeof dir_map / sizeof dir_map[0]; ++i) {
        if (strcasecmp(s, dir_map[i].name) == 0)
            return dir_map[i].dir;
    }
    return DIR_INVALID;
}


void calcJump(Direction dir, int *xmin, int *xmax, int *ymin, int *ymax, Pos* currentPos){
    switch (dir) {
        case UP:        *ymax = currentPos->y - 1;                       break;
        case DOWN:      *ymin = currentPos->y + 1;                       break;
        case LEFT:      *xmax = currentPos->x - 1;                       break;
        case RIGHT:     *xmin = currentPos->x + 1;                       break;
        case UP_LEFT:   *ymax = currentPos->y - 1; *xmax = currentPos->x - 1;       break;
        case UP_RIGHT:  *ymax = currentPos->y - 1; *xmin = currentPos->x + 1;       break;
        case DOWN_LEFT: *ymin = currentPos->y + 1; *xmax = currentPos->x - 1;       break;
        case DOWN_RIGHT:*ymin = currentPos->y + 1; *xmin = currentPos->x + 1;       break;
        default:        return;
    }
    currentPos->x = (*xmin + *xmax) / 2;
    currentPos->y = (*ymin + *ymax) / 2;
}

int main(){
    scanf("%d%d", &W, &H);
    scanf("%d", &N);
    scanf("%d%d", &currentPos.x, &currentPos.y);

    int xmin = 0, xmax = W - 1;
    int ymin = 0, ymax = H - 1;

    while (1) {
        char bomb_dir[4];
        scanf("%s", bomb_dir);
        Direction dir = parseDirection(bomb_dir);
        calcJump(dir, &xmin, &xmax, &ymin, &ymax, &currentPos);
        printf("%d %d\n", currentPos.x, currentPos.y);
    }

    return 0;
}