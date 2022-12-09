//
//  tips.c
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/4.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#include "tips.h"
#include <string.h>

void print_tips() {
    printf("\t[\\h]\t打印命令提示\n");
    printf("\t[\\p]\t打印当前地图\n");
    printf("\t[\\l <filename>]\t导入地图\n");
    printf("\t[\\s <filename>]\t保存地图\n");
    printf("\t[\\d]\t进入地图设计模式\n");
    printf("\t[\\q]\t退出地图设计模式\n");
    printf("\t[\\g]\t生成下一代生命\n");
    printf("\t[\\r]\t开始生命游戏\n");
    printf("\t[\\e]\t停止生命游戏\n");
    printf("\t[end]\t退出游戏\n");
}

void print_init() {
    printf("*********************************\n");
    printf("*********************************\n");
    printf("\n");
    printf("        生   命   游   戏\n");
    printf("\n");
    printf("         欢迎来到生命游戏\n");
    printf(" 在这里您将体会到元胞自动机的乐趣\n");
    printf("\n");
    printf("            准备好了吗\n");
    printf("\n");
    printf("*********************************\n");
    printf("*********************************\n");
}
