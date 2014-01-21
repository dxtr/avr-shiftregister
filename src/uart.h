#ifndef UART_H_
#define UART_H_

#include <stdio.h>

void uart_init();
void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);

extern FILE uart_output;
extern FILE uart_input;

#endif /* UART_H_ */
