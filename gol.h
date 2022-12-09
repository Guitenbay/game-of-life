//
//  gol.h
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/1.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#ifndef gol_h
#define gol_h

#define MAXROW 128
#define MAXCOL 128

#define BUFFLEN 256

#define INPUT_HEAD "$ "

#define IN_RANGE(x, low, high) ((low <= x) && (x < high))

typedef struct coordinates {
    int x;
    int y;
} Coordinates;

static Coordinates NEIGHBOUR_DIRECTIONS[] = {
    {1, 0},    // U
    {1, 1},    // UR
    {0, 1},    // R
    {-1, 1},   // DR
    {-1, 0},   // D
    {-1, -1},  // DL
    {0, -1},   // L
    {1, -1}    // UL
};

#endif /* gol_h */
