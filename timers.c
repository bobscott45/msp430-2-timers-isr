#include <msp430.h>
#include "timers.h"
#include "leds.h"

void on_red_timer_interrupt(void);
void on_green_timer_interrupt(void);

static const unsigned aux_clock =            0x0100;
static const unsigned up_mode =              0x0010;

void initialize_timer(enum Color color, unsigned interval) {
    switch(color) {
        case red:
            TA0CCR0 = interval;
            TA0CTL = aux_clock | up_mode;
            TA0CCTL0 = CCIE; //Enable timer0 interrupt
            break;
        case green:
            TA1CCR0 = interval;
            TA1CTL = aux_clock | up_mode;
            TA1CCTL0 = CCIE; //Enable timer1 interrupt
            break;
    }
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_ISR(void) {
    on_red_timer_interrupt();
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void Time1_ISR(void) {
   on_green_timer_interrupt();
}
