/*
 * main.h
 *
 *  Created on: Aug 15, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef MAIN_H_
#define MAIN_H_

#define __I 	volatile const 	/*Read Only Permission*/
#define __O 	volatile 		/*Write Only Permission*/
#define __IO 	volatile 		/*Read-Write Permission*/


typedef enum{
	ARM_OK			= 0x00U,
	ARM_ERROR		= 0x01U,
	ARM_BUSY		= 0x02U,
	ARM_TIMEOUT		= 0x03U
}Status_TypeDef;

typedef enum{
	ENABLE = 1,
	DISABLE = !ENABLE
}State_TypeDef;

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "bitManipulator.h"
#include "macros.h"

#include "core_m7.h"
#include "stm32_h743xx.h"


#include "scb.h"
#include "fpu.h"
#include "timbase.h"


#include "rcc.h"
#include "flash.h"
#include "pwr.h"
#include "gpio.h"
#include "uart.h"
#include "ltdc.h"

#include "pins.h"

#include "msp.h"
#include "it.h"



#endif /* MAIN_H_ */
