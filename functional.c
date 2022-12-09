//
//  functional.c
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/3.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "functional.h"

void listen_then_until(transit_func_t func, const char *end) {
    char buff[BUFFLEN];
    while (true) {
        printf(INPUT_HEAD);
        fflush(stdin);
        fgets(buff, BUFFLEN, stdin);
        // 清屏
        system("clear");
        if (strncmp(buff, end, strlen(end)) == 0) {
            break;
        }
        func(buff);
    }
}
