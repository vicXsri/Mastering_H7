/*
 * msp.c
 *
 *  Created on: Aug 17, 2026
 *      Author: Srivisweswara Mohan Santhi
 */


#include "msp.h"

void USART1_MspInit(UART_HandleTypeDef* huart){
	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	  if(huart->Instance == USART1){

		  __RCC_USART1_CLK_ENABLE();
		  __RCC_GPIOA_CLK_ENABLE();

		/**USART1 GPIO Configuration
		PA9     ------> USART1_TX
		PA10    ------> USART1_RX
		*/

		  /*TX*/
		  GPIO_InitStruct.Pin = GPIO_PIN_9;
		  GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		  GPIO_InitStruct.Alternate = GPIO_AF7;
		  GPIO_Init(GPIOA, &GPIO_InitStruct);

		  /*RX*/
		  GPIO_InitStruct.Pin = GPIO_PIN_10;
		  GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		  GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		  GPIO_InitStruct.Alternate = GPIO_AF7;
		  GPIO_Init(GPIOA, &GPIO_InitStruct);
	  }

}

void LTDC_MSPInit(LTDC_HandleTypeDef* hltdc){

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	RCC_PeripgCLKInitTypeDef LTDCClkInit = {0};

	if(hltdc->Instance == LTDC){

		LTDCClkInit.PeripheralClockSel = RCC_PERIPHCLK_LTDC;
		LTDCClkInit.PLL3.PLL3M = 1;
		LTDCClkInit.PLL3.PLL3N = 9;
		LTDCClkInit.PLL3.PLL3P = 2;
		LTDCClkInit.PLL3.PLL3Q = 2;
		LTDCClkInit.PLL3.PLL3R = 25;
		LTDCClkInit.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_3;
		LTDCClkInit.PLL3.PLL3VCOSEL = RCC_PLL3VCOMEDIUM;
		LTDCClkInit.PLL3.PLL3FRACN = 4096;

		if(RCCEx_PeripheralCLKConfig(&LTDCClkInit)!= ARM_OK){
	//		Error_Handler();
		}

		__RCC_LTDC_CLK_ENABLE();

		__RCC_GPIOE_CLK_ENABLE();
		__RCC_GPIOI_CLK_ENABLE();
		__RCC_GPIOF_CLK_ENABLE();
		__RCC_GPIOG_CLK_ENABLE();
		__RCC_GPIOH_CLK_ENABLE();
		__RCC_GPIOD_CLK_ENABLE();
		__RCC_GPIOA_CLK_ENABLE();

		/* PE5 */
		GPIO_InitStruct.Pin = GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOE, &GPIO_InitStruct);

		/* PE6 */
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOE, &GPIO_InitStruct);

		/* PI9 */
		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI10 */
		GPIO_InitStruct.Pin = GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI0 */
		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI1 */
		GPIO_InitStruct.Pin = GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI2 */
		GPIO_InitStruct.Pin = GPIO_PIN_2;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI4 */
		GPIO_InitStruct.Pin = GPIO_PIN_4;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI5 */
		GPIO_InitStruct.Pin = GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI6 */
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PI7 */
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOI, &GPIO_InitStruct);

		/* PF10 */
		GPIO_InitStruct.Pin = GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOF, &GPIO_InitStruct);

		/* PA2 */
		GPIO_InitStruct.Pin = GPIO_PIN_2;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* PH8 */
		GPIO_InitStruct.Pin = GPIO_PIN_8;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH9 */
		GPIO_InitStruct.Pin = GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH10 */
		GPIO_InitStruct.Pin = GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH11 */
		GPIO_InitStruct.Pin = GPIO_PIN_11;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH12 */
		GPIO_InitStruct.Pin = GPIO_PIN_12;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH13 */
		GPIO_InitStruct.Pin = GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH14 */
		GPIO_InitStruct.Pin = GPIO_PIN_14;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PH15 */
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOH, &GPIO_InitStruct);

		/* PG6 */
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOG, &GPIO_InitStruct);

		/* PG7 */
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOG, &GPIO_InitStruct);

		/* PG12 */
		GPIO_InitStruct.Pin = GPIO_PIN_12;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOG, &GPIO_InitStruct);

		/* PG13 */
		GPIO_InitStruct.Pin = GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOG, &GPIO_InitStruct);

		/* PG14 */
		GPIO_InitStruct.Pin = GPIO_PIN_14;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOG, &GPIO_InitStruct);

		/* PA8 */
		GPIO_InitStruct.Pin = GPIO_PIN_8;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF13;
		GPIO_Init(GPIOA, &GPIO_InitStruct);


		/* PD6 */
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_ALTERNATE;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.OType = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Alternate = GPIO_AF14;
		GPIO_Init(GPIOD, &GPIO_InitStruct);
	}

}
