//
//  _kbhit.c
//  lab2
//
//  Created by Hummel Mao on 2020/10/1.
//  Copyright © 2020 Hummel Mao. All rights reserved.
//

#include "_kbhit.h"

typedef struct termios Termios;

int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;
    if (!initialized) {
        // Use termios to turn off line buffering
        Termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }
    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
