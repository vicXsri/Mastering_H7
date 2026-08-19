/*
 * core_m4.c
 *
 *  Created on: Jun 1, 2025
 *      Author: Srivisweswara Mohan Santhi
 */


#include "core_m7.h"

void NVIC_Enable(uint32_t IRQn){
	__asm volatile("":::"memory");
	NVIC_R->ISER[(((uint32_t)IRQn) >> 5UL)] |= (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
	__asm volatile("":::"memory");
}
