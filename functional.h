//
//  functional.h
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/3.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#ifndef functional_h
#define functional_h

#include <stdio.h>
#include "gol.h"
#include "grid.h"

typedef void (*transit_func_t)(const char *);

void listen_then_until(transit_func_t, const char *);

//void listen_coordinates_then(const char *buff);

#endif /* functional_h */
