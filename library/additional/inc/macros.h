/*
 * macros.h
 *
 *  Created on: Aug 15, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef ADDITIONAL_INC_MACROS_H_
#define ADDITIONAL_INC_MACROS_H_

static inline void __disable_IRQ(void){
	__asm volatile ("cpsid i" : : : "memory"); // global interrupt disable
}

static inline void __enable_IRQ(void){
	__asm volatile ("cpsie i" : : : "memory"); // global interrupt enable
}

#endif /* ADDITIONAL_INC_MACROS_H_ */
