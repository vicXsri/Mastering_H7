/*
 * stm32_f446xx.h
 *
 *  Created on: May 31, 2025
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef STM32_H743XX_H_
#define STM32_H743XX_H_

#include "main.h"


#define AHB1_BASE        	   	(0x40020000UL) /* Starting Address of AHB1 */
#define AHB2_BASE        	   	(0x48020000UL) /* Starting Address of AHB2 */
#define AHB3_BASE        	   	(0x51000000UL) /* Starting Address of AHB3 */
#define AHB4_BASE        	   	(0x58020000UL) /* Starting Address of AHB4 */

#define APB1_BASE        	   	(0x40000000UL) /* Starting Address of APB1 */
#define APB2_BASE        	   	(0x40010000UL) /* Starting Address of APB2 */
#define APB3_BASE        	   	(0x50000000UL) /* Starting Address of APB3 */
#define APB4_BASE        	   	(0x58000000UL) /* Starting Address of APB4 */


#define FLASH_BASE			   	(AHB3_BASE + 0x01002000UL)

#define GPIOA_BASE				(AHB4_BASE + 0x0000UL)
#define GPIOB_BASE				(AHB4_BASE + 0x0400UL)
#define GPIOC_BASE				(AHB4_BASE + 0x0800UL)
#define GPIOD_BASE				(AHB4_BASE + 0x0C00UL)
#define GPIOE_BASE				(AHB4_BASE + 0x1000UL)
#define GPIOF_BASE				(AHB4_BASE + 0x1400UL)
#define GPIOG_BASE				(AHB4_BASE + 0x1800UL)
#define GPIOH_BASE				(AHB4_BASE + 0x1C00UL)
#define GPIOI_BASE				(AHB4_BASE + 0x2000UL)
#define GPIOJ_BASE				(AHB4_BASE + 0x2400UL)
#define GPIOK_BASE				(AHB4_BASE + 0x2800UL)
#define RCC_BASE			   	(AHB4_BASE + 0x4400UL)
#define PWR_BASE			   	(AHB4_BASE + 0x4800UL)

#define USART2_BASE			   	(APB1_BASE + 0x4400UL)
#define USART3_BASE			   	(APB1_BASE + 0x4800UL)
#define UART4_BASE			   	(APB1_BASE + 0x4C00UL)
#define UART5_BASE			   	(APB1_BASE + 0x5000UL)
#define UART7_BASE			   	(APB1_BASE + 0x7800UL)
#define UART8_BASE			   	(APB1_BASE + 0x7C00UL)

#define USART1_BASE			   	(APB2_BASE + 0x1000UL)
#define USART6_BASE			   	(APB2_BASE + 0x1400UL)

#define EXTI_BASE			   	(APB4_BASE			 )
#define SYSCFG_BASE			   	(APB4_BASE + 0x0400UL)
#define LPUART1_BASE			(APB4_BASE + 0x0C00UL)

#define LTDC_BASE			   	(APB3_BASE + 0x1000UL)
#define WWDG1_BASE			   	(APB3_BASE + 0x3000UL)


#endif /* STM32_H743XX_H_ */
