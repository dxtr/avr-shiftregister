#include "extern.h"
#include <avr/io.h>

#include "globals.h"
#include "io.h"
#include "misc.h"
#include "pattern.h"

/*
 * A pattern that simply increments an integer
 */
void pattern_increment() {
	for (uint8_t i = 0; i <= 0xFF; i++) {
		latch(i);
		delay_ms(delay_time);
	}
}

/*
 * A pattern that shifts an integer to the left
 */
void pattern_leftshift() {
	for (uint8_t i = 1; i > 0; i <<= 1) {
		delay_ms(delay_time);
		latch(i);
	}
}

/*
 * A pattern that shifts an integer to the right
 */

void pattern_rightshift() {
	for (uint8_t i = 1<<7; i > 0; i >>= 1) {
		delay_ms(delay_time);
		latch(i);
	}
}

/*
 * A pattern that shifts left then right
 */
void pattern_nightrider() {
	pattern_leftshift();
	delay_ms(delay_time);
	pattern_rightshift();
}

/*
 * The reverse of the above
 */
void pattern_nightrider_reverse() {
	pattern_rightshift();
	delay_ms(delay_time);
	pattern_leftshift();
}
