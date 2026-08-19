/*
 * pin.h
 *
 *  Created on: Aug 17, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef ADDITIONAL_INC_PINS_H_
#define ADDITIONAL_INC_PINS_H_

#include "main.h"

/**LTDC GPIO Configuration
PE5     ------> LTDC_G0 --
PE6     ------> LTDC_G1 --
PI9     ------> LTDC_VSYNC --
PI10     ------> LTDC_HSYNC --
PF10     ------> LTDC_DE --
PA2     ------> LTDC_R1 --
PH8     ------> LTDC_R2 --
PH9     ------> LTDC_R3 --
PH10     ------> LTDC_R4 --
PH11     ------> LTDC_R5 --
PH12     ------> LTDC_R6 --
PG6     ------> LTDC_R7 --
PG7     ------> LTDC_CLK --
PA8     ------> LTDC_B3 --
PH13     ------> LTDC_G2 --
PH14     ------> LTDC_G3 --
PH15     ------> LTDC_G4 --
PI0     ------> LTDC_G5 --
PI1     ------> LTDC_G6 --
PI2     ------> LTDC_G7 --
PD6     ------> LTDC_B2 --
PG12     ------> LTDC_B1 --
PG13     ------> LTDC_R0 --
PG14     ------> LTDC_B0 --
PI4     ------> LTDC_B4 --
PI5     ------> LTDC_B5 --
PI6     ------> LTDC_B6 --
PI7     ------> LTDC_B7 --
*/


#define LTDC_R0_PORT			GPIOG
#define LTDC_R0_PIN				GPIO_PIN_13

#define LTDC_R1_PORT			GPIOA
#define LTDC_R1_PIN				GPIO_PIN_2

#define LTDC_R2_PORT			GPIOH
#define LTDC_R2_PIN				GPIO_PIN_8

#define LTDC_R3_PORT			GPIOH
#define LTDC_R3_PIN				GPIO_PIN_9

#define LTDC_R4_PORT			GPIOH
#define LTDC_R4_PIN				GPIO_PIN_10

#define LTDC_R5_PORT			GPIOH
#define LTDC_R5_PIN				GPIO_PIN_11

#define LTDC_R6_PORT			GPIOH
#define LTDC_R6_PIN				GPIO_PIN_12

#define LTDC_R7_PORT			GPIOG
#define LTDC_R7_PIN				GPIO_PIN_6



#define LTDC_B0_PORT			GPIOG
#define LTDC_B0_PIN				GPIO_PIN_14

#define LTDC_B1_PORT			GPIOG
#define LTDC_B1_PIN				GPIO_PIN_12

#define LTDC_B2_PORT			GPIOD
#define LTDC_B2_PIN				GPIO_PIN_6

#define LTDC_B3_PORT			GPIOA
#define LTDC_B3_PIN				GPIO_PIN_8

#define LTDC_B4_PORT			GPIOI
#define LTDC_B4_PIN				GPIO_PIN_4

#define LTDC_B5_PORT			GPIOI
#define LTDC_B5_PIN				GPIO_PIN_5

#define LTDC_B6_PORT			GPIOI
#define LTDC_B6_PIN				GPIO_PIN_6

#define LTDC_B7_PORT			GPIOI
#define LTDC_B7_PIN				GPIO_PIN_7


#define LTDC_G0_PORT			GPIOE
#define LTDC_G0_PIN				GPIO_PIN_5

#define LTDC_G1_PORT			GPIOE
#define LTDC_G1_PIN				GPIO_PIN_6

#define LTDC_G2_PORT			GPIOH
#define LTDC_G2_PIN				GPIO_PIN_13

#define LTDC_G3_PORT			GPIOH
#define LTDC_G3_PIN				GPIO_PIN_14

#define LTDC_G4_PORT			GPIOH
#define LTDC_G4_PIN				GPIO_PIN_15

#define LTDC_G5_PORT			GPIOI
#define LTDC_G5_PIN				GPIO_PIN_0

#define LTDC_G6_PORT			GPIOI
#define LTDC_G6_PIN				GPIO_PIN_1

#define LTDC_G7_PORT			GPIOI
#define LTDC_G7_PIN				GPIO_PIN_2


#define LTDC_VSYNC_PORT			GPIOI
#define LTDC_VSYNC_PIN			GPIO_PIN_9

#define LTDC_HSYNC_PORT			GPIOI
#define LTDC_HSYNC_PIN			GPIO_PIN_10

#define LTDC_DE_PORT			GPIOF
#define LTDC_DE_PIN				GPIO_PIN_10

#define LTDC_CLK_PORT			GPIOG
#define LTDC_CLK_PIN			GPIO_PIN_7

#define LED0_PORT				GPIOH
#define LED0_PIN				GPIO_PIN_7

#define USART1_RX_PORT			GPIOA
#define USART1_RX_PIN			GPIO_PIN_10

#define USART1_TX_PORT			GPIOA
#define USART1_TX_PIN			GPIO_PIN_9

#define SWCLK_PORT				GPIOA
#define SWCLK_PIN				GPIO_PIN_14

#define SWDIO_PORT				GPIOA
#define SWDIO_PIN				GPIO_PIN_13





#endif /* ADDITIONAL_INC_PINS_H_ */
