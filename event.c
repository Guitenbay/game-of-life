//
//  event.c
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/4.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "_kbhit.h"
#include "event.h"

bool is_num(const char *str) {
    for (unsigned int i = 0, len = (unsigned int) strlen(str); i < len; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

Grid on_load(char *line) {
    // 第一个子串
    strtok(line, " ");
    // 第二个子串
    const char *filename = strtok(NULL, " ");
    Grid grid = read_grid(filename);
    print_grid(grid);
    return grid;
}

void on_save(Grid grid, char *line) {
    // 第一个子串
    strtok(line, " ");
    // 第二个子串
    const char *filename = strtok(NULL, " ");
    write_grid(grid, filename);
}

Grid on_design() {
    Grid grid = create_empty_grid();
    printf("> 进入自定义地图模式 <\n");
    printf("设置长宽(输入格式如：'5 4')\n");
    printf("design%s", INPUT_HEAD);
    scanf("%d %d", &grid.row, &grid.col);
    system("clear");
    if (grid.row > MAXROW || grid.col > MAXCOL) {
        printf("Error: 长度应小于 %d，宽度应小于 %d", MAXROW, MAXCOL);
        grid.row = grid.col = 0;
        return grid;
    }
    
    char buff[BUFFLEN];
    while (true) {
        print_grid(grid);
        printf("设置存活细胞(输入格式如：'0 0')\n");
        printf("design('%s' 退出该模式)%s", QUIT, INPUT_HEAD);
        fflush(stdin);
        fgets(buff, BUFFLEN, stdin);
        // 清屏
        system("clear");
        if (strncmp(buff, QUIT, strlen(QUIT)) == 0) {
            break;
        }
        char *line = strtok(buff, "\n");    // 去掉 \n
        const char *row = strtok(line, " ");
        const char *col = strtok(NULL, " ");
        if (row != NULL && col != NULL
            && is_num(row) && is_num(col)) {
            // 设置细胞存活
            if (IN_RANGE(atoi(row), 0, grid.row)
                && IN_RANGE(atoi(col), 0, grid.col)) {
                grid.pixels[atoi(row)][atoi(col)] = 1;
            } else {
                printf("输入数字超出范围！\n");
            }
        } else {
            printf("输入格式错误！\n");
        }
        
    }
    printf("> 已退出自定义地图模式，请及时保存 <\n");
    print_grid(grid);
    printf("(使用 '\\s <filename>' 命令将自定义地图保存到本地)\n");
    return grid;
}

Grid on_gerenate(Grid grid) {
    Grid next = update_grid(grid);
    print_grid(next);
    return next;
}

Grid on_run(Grid grid) {
    Grid current = grid;
    char buff[BUFFLEN];
    while (true) {
        usleep(200000);
        system("clear");
        printf("输入回车键暂停游戏\n");
        current = on_gerenate(current);
        if (_kbhit()) {
            // 获取回车键返回的值（无效值，需要舍弃）
            fgets(buff, BUFFLEN, stdin);
            printf("输入 '%s' 停止生命游戏\nrun%s", EXIT, INPUT_HEAD);
            // 清空缓冲区
            fflush(stdin);
            fgets(buff, BUFFLEN, stdin);
            system("clear");
            if (strncmp(buff, EXIT, strlen(EXIT)) == 0) {
                break;
            }
        }
    }
    return current;
}

void on_exit(void);
