#include <msp430.h>
#include "leds.h"

static const unsigned bit0 =  0x0001;
static const unsigned bit7 =  0x0080;

void initialize_leds() {
    P1DIR = bit0; //red led   P1.0
    P9DIR = bit7; //green led P9.7
}

void toggle_led(enum Color color) {
    switch(color) {
        case red:
            P1OUT ^= bit0;
            break;

        case green:
            P9OUT ^= bit7;
            break;
    }
}
