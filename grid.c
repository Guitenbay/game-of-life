//
//  grid.c
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/1.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#include "gol.h"
#include "grid.h"
#include <stdbool.h>

bool getValue(unsigned int *value, FILE *fp) {
    if (!feof(fp)) {
        fscanf(fp, "%d", value);
        return true;
    } else {
        printf("文档格式错误！\n");
        fclose(fp);
        return false;
    }
}

Grid create_empty_grid() {
    Grid grid;
    grid.row = 0;
    grid.col = 0;
    for (int i = 0; i < MAXROW; i++) {
        for (int j = 0; j < MAXCOL; j++) {
            grid.pixels[i][j] = 0;
        }
    }
    return grid;
}

int count_neighbors(Grid grid, const unsigned int y, const unsigned int x) {
    int liveNeighbours = 0;
    
    for (int i = 0; i < 8; i++) {
        Coordinates current = NEIGHBOUR_DIRECTIONS[i];
        int neighborX = x + current.x;
        int neighborY = y + current.y;
        // validate neighbor is within grid boundary
        if (IN_RANGE(neighborY, 0, MAXROW) && IN_RANGE(neighborX, 0, MAXCOL)
            && (grid.pixels[neighborY][neighborX] == 1)) {
            liveNeighbours++;
        }
    }
    
    return liveNeighbours;
}


Grid update_grid(Grid grid) {
    Grid next = create_empty_grid();
    next.row = grid.row;
    next.col = grid.col;
    for (unsigned int i = 0; i < grid.row; i++) {
        for(unsigned int j = 0; j < grid.col; j++) {
            int liveNeighbours = count_neighbors(grid, i, j);
            if (grid.pixels[i][j] == 1) {
                if (liveNeighbours > 3 || liveNeighbours < 2) {
                    // 活细胞周围有3个以上活细胞时，该细胞死亡。
                    // 活细胞周围有2个以内活细胞时，该细胞死亡。
                    // do nothing
                } else {
                    // 周围有 2 或 3 个活细胞时，该细胞状态保持存活。
                    next.pixels[i][j] = grid.pixels[i][j];
                }
            } else {
                if (liveNeighbours == 3) {
                    // 死细胞周围有3个活细胞时，该细胞复活。
                    next.pixels[i][j] = 1;
                }
            }
        }
    }
    return next;
}

Grid read_grid(const char *filename) {
    Grid grid;
    char path[PATH_LEN] = MAP_SRC;
    strcat(path, filename);
    // 打开文件，只读
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("文件打开失败！\n(%s)\n", path);
        fclose(fp);
        return create_empty_grid();
    }
    // 读取文件直到文件末尾
    if (!getValue(&grid.row, fp)) {
        return create_empty_grid();
    }
    if (!getValue(&grid.col, fp)) {
        return create_empty_grid();
    }
    for (int i = 0; i < grid.row; i++) {
        for (int j = 0; j < grid.col; j++) {
            if (!getValue(&grid.pixels[i][j], fp)) {
                return create_empty_grid();
            }
        }
    }
    fclose(fp);
    printf("读取自 (%s)\n", filename);
    return grid;
}

void write_grid(Grid grid, const char *filename) {
    char path[PATH_LEN] = MAP_SRC;
    strcat(path, filename);
    // 创建文件
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    if (fprintf(fp, "%d %d\n", grid.row, grid.col) < 0) {
        printf("文件写入错误！\n");
        fclose(fp);
        return;
    }
    for (int i = 0; i < grid.row; i++) {
        for (int j = 0; j < grid.col; j++) {
            if (j == grid.col - 1) {
                if (fprintf(fp, "%d\n", grid.pixels[i][j]) < 0) {
                    printf("文件写入错误！\n");
                    fclose(fp);
                    return;
                }
            } else {
                if (fprintf(fp, "%d ", grid.pixels[i][j]) < 0) {
                    printf("文件写入错误！\n");
                    fclose(fp);
                    return;
                }
            }
        }
    }
    fclose(fp);
    printf("保存成功！(%s)\n", filename);
}

void print_grid(const Grid grid) {
    for (int i = 0; i < grid.row; i++) {
        for (int j = 0; j < grid.col; j++) {
            int v = grid.pixels[i][j];
            if (v == 1) {
                printf("■");
            } else {
                printf("□");
            }
            printf(" ");
        }
        printf("\n");
    }
}
