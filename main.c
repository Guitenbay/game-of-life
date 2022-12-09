#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "grid.h"
#include "functional.h"
#include "tips.h"
#include "event.h"

#define compare_string(x, y) strncmp(x, y, strlen(y))

// 全局单例
Grid globalGrid;

void choose_actions(const char *buff) {
    if (compare_string(buff, HELP) == 0) {
        print_tips();
    } else if (compare_string(buff, PRINT) == 0) {
        print_grid(globalGrid);
    } else if (compare_string(buff, GENERATE) == 0) {
        globalGrid = on_gerenate(globalGrid);
    } else if (compare_string(buff, RUN) == 0) {
        globalGrid = on_run(globalGrid);
    } else if (compare_string(buff, EXIT) == 0) {
        printf("未开始生命游戏！（使用 '\\h' 命令查看有效输入）\n");
    } else if (compare_string(buff, DESIGN) == 0) {
        globalGrid = on_design();
    } else if (compare_string(buff, QUIT) == 0) {
        printf("未进入地图设计模式！（使用 '\\h' 命令查看有效输入）\n");
    } else if (compare_string(buff, LOAD) == 0) {
        char constBuff[BUFFLEN];
        strcpy(constBuff, buff);
        char *line = strtok(constBuff, "\n");
        if (strlen(line) > 3lu) {
            globalGrid = on_load(line);
        }
    } else if (compare_string(buff, SAVE) == 0) {
        char constBuff[BUFFLEN];
        strcpy(constBuff, buff);
        char *line = strtok(constBuff, "\n");
        if (strlen(line) > 3lu) {
            on_save(globalGrid, line);
        }
    } else {
        printf("未知输入！（使用 '\\h' 命令查看有效输入）\n");
    }
}

int main(){
    // 初始化
    print_init();
    print_tips();
    globalGrid = create_empty_grid();
    // 事件监听
    listen_then_until(choose_actions, END);
    // 退出游戏
    printf("Game Over\n");
    return 0;
}
