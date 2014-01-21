/* This file contains defines that change the behavior
 * of system libraries
 *
 * Because of this it sould be included before them.
 */

#ifndef EXTERN_H_
#define EXTERN_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#endif /* EXTERN_H_ */
