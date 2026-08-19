/*
 * uart.c
 *
 *  Created on: Jun 13, 2025
 *      Author: Srivisweswara Mohan Santhi
 */

#include "uart.h"

extern UART_HandleTypeDef huart1;


#define uart (&huart1)
#define TIMEOUT_DEF	500

uint16_t timeout;

Status_TypeDef USART_Init(UART_HandleTypeDef* huart){

	if(huart == NULL) return ARM_ERROR;

	USART_MspInit(huart);

	huart->Instance->CR1 = 0;
	huart->Instance->CR2 = 0;
	huart->Instance->CR3 = 0;
	huart->Instance->PRESC = huart->Init.ClockPrescaler;

    /*Transfer Mode*/
    huart->Instance->CR1 = huart->Init.Mode;

    /*Set Baudrate*/
    if(huart->Instance == USART1 || huart->Instance == USART6)
		huart->Instance->BRR = USART_Compute_Baud(RCC_GetP2CLK_Freq(),huart->Init.BaudRate);
    else
    	huart->Instance->BRR = USART_Compute_Baud(RCC_GetP1CLK_Freq(),huart->Init.BaudRate);

    /*No of stop Bits*/
    huart->Instance->CR2 |= huart->Init.StopBits;

    /*Word Length*/
    huart->Instance->CR1 |= huart->Init.WordLength;

    /*parity control*/
    huart->Instance->CR1 |= huart->Init.parity;

    /*HWFlow control*/
    huart->Instance->CR3 |= huart->Init.HWFlowCtl;

    /*Over Sampling*/
    huart->Instance->CR1 |= huart->Init.OverSampling;

    /*Enable the usart Instance*/
    huart->Instance->CR1 |= USART_EN;

    if(huart->Instance == USART1){
    	NVIC_Enable(USART1_IRQ);
    }
    return ARM_OK;
}

uint16_t USART_Compute_Baud(uint32_t pclk, uint32_t baudrate){
	return ((pclk + (baudrate / 2U)) / baudrate);
}

int __io_putchar(int ch){
	debug(ch);
	return ch;
}

int __io_getchar(void){
	while(!(uart->Instance->ISR & USART_ISR_RXNE_RXFNE));
	return (int)(uart->Instance->RDR & 0xFF);
}

void debug(int ch){
	while(!(uart->Instance->ISR & USART_ISR_TXE_TXFNF));
	uart->Instance->TDR = (ch & 0xFF);
}

void __UART_ENABLE_IT_EIE(UART_HandleTypeDef* huart){
	huart->Instance->CR3 |= USART_EIE_EN;
}

void __UART_ENABLE_IT_RXNE(UART_HandleTypeDef* huart){
	huart->Instance->CR1 |= USART_RXNE_EN;
}
