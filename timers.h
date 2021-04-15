#ifndef TIMERS_H_
#define TIMERS_H_

#include <msp430.h>
#include "colors.h"

void initialize_timer(enum Color, unsigned interval);
unsigned is_timer_expired(enum Color);
void reset_timer(enum Color);

#endif /* TIMERS_H_ */
