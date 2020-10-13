#ifndef TECTONICS_H
#define TECTONICS_H

#include "quantum.h"
#include <avr/io.h>

#define LAYOUT_tectonics( \
            L00, L01, L02, L03, L04, L05, \
            L10, L11, L12, L13, L14, L15, \
            L20, L21, L22, L23, L24, L25, \
            R00, R01, R02, R03, R04, R05, \
            R10, R11, R12, R13, R14, R15, \
            R20, R21, R22, R23, R24, R25  \
        ) \
        { \
            { L00, L10, L20 }, \
            { L01, L11, L21 }, \
            { L02, L12, L22 }, \
            { L03, L13, L23 }, \
            { L04, L14, L24 }, \
            { L05, L15, L25 }, \
            { R00, R10, R20 }, \
            { R01, R11, R21 }, \
            { R02, R12, R22 }, \
            { R03, R13, R23 }, \
            { R04, R14, R24 }, \
            { R05, R15, R25 }  \
        }

#define _LED1 F5       // A2 in Pro Micro
#define _LED2 F4       // A3 in Pro Micro

#endif
