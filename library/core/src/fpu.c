/*
 * fpu.c
 *
 *  Created on: Mar 27, 2026
 *      Author: Srivisweswara Mohan Santhi
 */


#include "fpu.h"


void FPU_Init(void){

	SCB->CPACR |= (0xF << 20UL);

}
