#ifndef GLOBALS_H_
#define GLOBALS_H_

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
#define CLOCK_TICKS_PER_MS 14

extern uint16_t delay_time;

#endif /* GLOBALS_H_ */
