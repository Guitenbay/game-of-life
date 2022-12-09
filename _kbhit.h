//
//  _kbhit.h
//  lab2
//
//  Created by Hummel Mao on 2020/10/1.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#ifndef _kbhit_h
#define _kbhit_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/ioctl.h>

int _kbhit(void);

#endif /* _kbhit_h */
