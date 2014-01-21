#include "extern.h"

//#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/setbaud.h>

//#include "uart.h"
#include "globals.h"
#include "pattern.h"

/*
#define LATCH_PIN PD2
#define CLOCK_PIN PD3
#define DATA_PIN PD4
#define BUTTON_PIN PD5
#define LED_PIN PB5
#define LATCH_PIN_MASK (1<<LATCH_PIN)
#define CLOCK_PIN_MASK (1<<CLOCK_PIN)
#define DATA_PIN_MASK (1<<DATA_PIN)
#define BUTTON_PIN_MASK (1<<BUTTON_PIN)
#define LED_PIN_MASK (1<<LED_PIN)
#define DEFAULT_DELAY_TIME 75
#define LED_COUNT 8

#define CLOCK_TICKS_PER_MS 14 // (1/1000)/(1/(16000000/1024))-1=14.625
*/

uint16_t delay_time = DEFAULT_DELAY_TIME;

/*
 * delays for a certain time
 * Doesn't currently work for delay > 4600
 */
static void delay_ms(uint16_t delay) {
	TCNT1 = 0;
	while (TCNT1/CLOCK_TICKS_PER_MS < delay);
}

/*
 * Main
 */
int main(void) {
	//uart_init();
	//stdout = &uart_output;
	//stdin = &uart_input;

	// Set up timer
	TCCR1B |= (1 << CS12) | (1 << CS10);

	// Enable analog stuff
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) | (1 << ADIF)
	    | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	// Set up interrupts
	PCICR |= (1 << PCIE2);
	sei();

	// Enable outputs
	DDRD |= (LATCH_PIN_MASK | CLOCK_PIN_MASK | DATA_PIN_MASK);
	DDRB |= (LED_PIN_MASK);

	pattern_nightrider();

	latch(0xFF);
	delay_ms(500);
	latch(0x00);
	delay_ms(500);


	while (1) {
		pattern_nightrider();
	}
}

ISR(ADC_vect) {
	delay_time = ADCL | (ADCH << 8);
}
