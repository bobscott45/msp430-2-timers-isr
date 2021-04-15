#include <msp430.h>
#include "timers.h"
#include "leds.h"

void setup(unsigned red_interval, unsigned green_interval);

static const unsigned red_interval =  50000;
static const unsigned green_interval = 5000;

int main(void)
{
	setup(red_interval, green_interval);
	
	while(1);
}

void setup(unsigned red_interval, unsigned green_interval) {
        WDTCTL = WDTPW | WDTHOLD;   // disable watchdog timer
        PM5CTL0 = 0xFFFE;  //enable pin io
        initialize_leds();
        initialize_timer(red, red_interval);
        initialize_timer(green, green_interval);
        _BIS_SR(GIE); // enable interrupts
}

void on_red_timer_interrupt(void) {
    toggle_led(red);
}

void on_green_timer_interrupt(void) {
    toggle_led(green);
}
