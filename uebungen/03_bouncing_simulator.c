//https://www.codingame.com/ide/puzzle/bouncing-simulator
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

char** drawBox(int32_t w, int32_t h){
    char** box = calloc(h, sizeof(char*));
    for(int i = 0; i < h; i++){
        box[i] = calloc(w, sizeof(char));
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            box[i][j] = (i == 0 || i == h - 1 || j == 0 || j == w - 1) ? '#' : ' ';
        }
    }
    return box;
}

int8_t convertCharToInt(char c){
    return (c == ' ') ? 0 : c - '0';
}

char convertIntToChar(int8_t i){
    return i + '0';
}

void simulate(char** box, int32_t bounces, int32_t h, int32_t w){
    bool isBounced = false;
    int32_t x = 1, y = 1;
    int32_t dx = 1, dy = 1;
    
    int32_t bounced = 0;
    bool isFirst = true;
    box[y][x] = '1';
    do{
        if(h == 3 || w == 3){
            if(h == 3){
                if(isFirst){
                    dx = 1;
                    dy = 0;
                }

                //LEFT
                if(dx == 1 && dy == 0){
                    if(x == w-2){
                        dx = -1;
                        dy = 0;
                        continue;
                    }
                }
                
                x += dx;
                y += dy;
            }

            if(w == 3){
                if(isFirst){
                    dx = 0;
                    dy = 1;
                }

                if(y == h-2){
                    dx = 0;
                    dy = -1;
                    continue;
                }
                x += dx;
                y += dy;
            }

            if(isFirst){
                bounced++;
                isFirst = false;
            }
            isBounced = true;
        }else{
            x += dx;
            y += dy;

            if(x == 1){
                //Down left
                if(dx == -1 && dy == 1){
                    dx = 1;
                    dy = 1;
                    isBounced = true;
                //up left
                }else if(dx == -1 && dy == -1){
                    dx = 1;
                    dy = -1;
                    isBounced = true;
                }
            }else if(x == w-2){
                //Down right
                if(dx == 1 && dy == 1){
                    dx = -1;
                    dy = 1;
                    isBounced = true;
                //Up Right
                }else if(dx == 1 && dy == -1){
                    dx = -1;
                    dy = -1;      
                    isBounced = true;
                }
            }

            if(y == 1){
                //Up Left
                if(dx == -1 && dy == -1){
                    dx = -1;
                    dy = 1;
                    isBounced = true;
                //Up Right
                }else if(dx == 1 && dy == -1){
                    dx = 1;
                    dy = 1;
                    isBounced = true;
                }
            }else if(y == h-2){
                //Down Left
                if(dx == -1 && dy == 1){
                    dx = -1;
                    dy = -1;
                    isBounced = true;
                //Down Right
                }else if(dx == 1 && dy == 1){
                    dx = 1;
                    dy = -1;
                    isBounced = true;
                }
            }
        }

        char currentChar = box[y][x];
        int32_t currentInt = convertCharToInt(currentChar);
        currentInt++;
        box[y][x] = convertIntToChar(currentInt);

        if(isBounced){
            bounced++;
            isBounced = false;
        }
    }while((bounced < bounces));
}

int main(){
    int w, h, n;
    scanf("%d", &w);
    scanf("%d", &h);
    scanf("%d", &n);
    w = w+2;
    h = h+2;

    char** box = drawBox(w, h);
    simulate(box, n, h, w);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c", box[i][j]);
        }
        printf("\n");
    }
    return 0;
}