//
//  grid.h
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/1.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#ifndef grid_h
#define grid_h

#include <stdio.h>
#include <string.h>
#include "gol.h"

#define MAP_SRC "./maps/"
#define PATH_LEN 128

typedef struct grid {
    unsigned int row;
    unsigned int col;
    unsigned int pixels[MAXROW][MAXCOL];
} Grid;

Grid create_empty_grid(void);

int count_neighbors(Grid, const unsigned int, const unsigned int);

Grid update_grid(Grid);

void print_grid(const Grid);
//void clear_grid(Grid);
Grid read_grid(const char *);
void write_grid(Grid, const char *);

#endif /* grid_h */
