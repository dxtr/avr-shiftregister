#include "extern.h"
#include <avr/io.h>

#include "io.h"
#include "globals.h"

/*
 * This function is used to latch (send) data to a shift register
 */
void latch(const uint8_t value) {
	PORTD &= ~LATCH_PIN_MASK;

	for (uint8_t i = 1<<7; i > 0; i>>=1) {
		PORTD = (PORTD & ~DATA_PIN_MASK) | (!!(value & i) << DATA_PIN);

                PORTD |= CLOCK_PIN_MASK;
                PORTD &= ~CLOCK_PIN_MASK;
	}

	PORTD |= LATCH_PIN_MASK;
}
