//
//  event.h
//  game-of-life
//
//  Created by Hummel Mao on 2020/10/4.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#ifndef event_h
#define event_h

#include <stdio.h>
#include "gol.h"
#include "grid.h"
#include "tips.h"

Grid on_load(char *);

void on_save(Grid, char *);

Grid on_design(void);

Grid on_gerenate(Grid);

Grid on_run(Grid);

void on_exit(void);

#endif /* event_h */
