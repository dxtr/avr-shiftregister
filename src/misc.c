#include <avr/interrupt.h>
#include <stdint.h>

#include "globals.h"
#include "misc.h"

/*
 * delays for a certain time
 * Doesn't currently work for delay > 4600
 */
void delay_ms(uint16_t delay) {
	TCNT1 = 0;
	while (TCNT1/CLOCK_TICKS_PER_MS < delay);
}
