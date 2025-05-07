#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct Pos {
    int x;
    int y;
} Pos;

typedef enum {
    STATUS_INVALID = -1,
    COLDER, WARMER, SAME, UNKNOWN
} Status;

typedef struct {
    const char *name;
    Status   dir;
} DirMap;

static const DirMap dir_map[] = {
    { "COLDER",  COLDER },
    { "WARMER", WARMER  },
    { "SAME",  SAME     },
    { "UNKNOWN", UNKNOWN},
};

Status parseStatus(const char *s){
    for (size_t i = 0; i < sizeof dir_map / sizeof dir_map[0]; ++i) {
        if (strcasecmp(s, dir_map[i].name) == 0)
            return dir_map[i].dir;
    }
    return STATUS_INVALID;
}


static void shrinkByStatus(int prev, int curr, Status st, int *min, int *max)
{
    const int mid = (prev + curr) / 2;

    if (st == SAME) { *min = *max = mid; return; }

    bool moved_positive = curr > prev;
    bool got_warmer     = (st == WARMER);

    bool keep_upper_side = (moved_positive == got_warmer);

    if (keep_upper_side)   *min = mid + 1;
    else                   *max = mid - 1;
}

int main(){
    int W,H,N;
    int X0,Y0;
    Pos currentPos;
    Pos prevPos;

    scanf("%d%d", &W, &H);
    scanf("%d", &N);
    scanf("%d%d", &currentPos.x, &currentPos.y);

    int xmin = 0, xmax = W - 1;
    int ymin = 0, ymax = H - 1;
    prevPos.x = currentPos.x;
    prevPos.y = currentPos.y;
    bool move_x_axis = true;

    while (1) {
        char bomb_dir[4];
        scanf("%s", bomb_dir);
        Status stat = parseStatus(bomb_dir);

        if (stat != UNKNOWN) {
            if (move_x_axis)
                shrinkByStatus(prevPos.x, currentPos.x, stat, &xmin, &xmax);
            else
                shrinkByStatus(prevPos.y, currentPos.y, stat, &ymin, &ymax);
        }

        move_x_axis = (xmax - xmin) >= (ymax - ymin);

        if (move_x_axis) {
            prevPos.x = currentPos.x;
            currentPos.x = (xmin + xmax) / 2;
        } else {
            prevPos.y = currentPos.y;
            currentPos.y = (ymin + ymax) / 2;
        }
        printf("%d %d\n", currentPos.x, currentPos.y);
    }

    return 0;
}