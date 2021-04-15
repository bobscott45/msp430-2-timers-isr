/*
 * leds.h
 *
 *  Created on: 14 Apr 2021
 *      Author: robert
 */

#ifndef LEDS_H_
#define LEDS_H_

#include <msp430.h>
#include "colors.h"

void initialize_leds(void);
void toggle_led(enum Color color);

#endif /* LEDS_H_ */
