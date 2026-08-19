/*
 * i2c.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */


#include "i2c.h"

static Status_TypeDef I2C_AbortTransfer(I2C_HandleTypeDef* hi2c, Status_TypeDef status)
{
	hi2c->Instance->CR2 |= (1UL << 14U); /* STOP */

	if(hi2c->Instance->ISR & (1UL << 5U)){ /* STOPF */
		hi2c->Instance->ICR |= (1UL << 5U);
	}

	if(hi2c->Instance->ISR & (1UL << 4U)){ /* NACKF */
		hi2c->Instance->ICR |= (1UL << 4U);
	}

	if(hi2c->Instance->ISR & (1UL << 8U)){ /* BERR */
		hi2c->Instance->ICR |= (1UL << 8U);
	}

	return status;
}

Status_TypeDef I2C_Init(I2C_HandleTypeDef* hi2c){

	if(hi2c == NULL){
		return ARM_ERROR;
	}

	I2C_MspInit(hi2c);

	__I2C_DISABLE(hi2c->Instance);


	/* set the I2C Frequency Range */
	hi2c->Instance->TIMR = hi2c->Init.Timing & 0xF0FFFFFFU;

	/* Disable own addr 1 */
	hi2c->Instance->OAR1 &= ~(0x1UL << 15U);

	/* Enable the addressing mode either in 7bit or 10bit mode */
	if(hi2c->Init.AddressingMode == I2C_ADDMODE_7BIT){
		hi2c->Instance->OAR1 = (1UL << 15U) |  (hi2c->Init.OwnAddr1 & 0x3FF);
	}else{
		hi2c->Instance->OAR1 = (1UL << 15U) | (1UL << 10U) |  (hi2c->Init.OwnAddr1 & 0x3FF);
	}

	/* Setup the CR2 Register*/
	if(hi2c->Init.AddressingMode == I2C_ADDMODE_10BIT){
		hi2c->Instance->CR2 |= (0x01UL << 11U);
	}else{
		hi2c->Instance->CR2 &= ~(0x01UL << 11U);
	}

	/* Enable the AUTOEND by default, and enable NACK */
	hi2c->Instance->CR2 |= (0x01UL << 15U) | (0x01UL << 25U);

	/* Disable Own Address2 before setting the own address2 config */
	hi2c->Instance->OAR2 &=~ (0x1UL << 15U);

	/* Setup dual mode and own address2  */
	hi2c->Instance->OAR2 =   (hi2c->Init.OwnAddr2 | hi2c->Init.DualAddressingMode
						      | ((hi2c->Init.OwnAddr2Mask & 0x07) << 8U));

	/* Configure CR1 NoStrechMode & GeneralCallMode*/
	hi2c->Instance->CR1 = hi2c->Init.NoStrechMode | hi2c->Init.GeneralCallMode;

	__I2C_ENABLE(hi2c->Instance);

	return ARM_OK;
}

Status_TypeDef I2C_MEM_Read(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint16_t MemAddress,
							uint16_t MemAddSize, uint8_t* pData, uint16_t Size, uint32_t timeout){

	uint32_t tickstart;

	 if((hi2c == NULL) || (pData == NULL) || (Size == 0U)) {
	        return ARM_ERROR;
	    }

	tickstart = Get_Tick();

	/* Check of the bus is busy */
	 while(hi2c->Instance->ISR & (1UL << 15U)){
		 if((Get_Tick() - tickstart) > timeout){
			 return ARM_TIMEOUT;
		 }
	 }

	 /* Clear the flags in the interrupt clear register !! */
	 hi2c->Instance->ICR |= (1UL << 5U) | (1UL << 4U) | (1UL << 3U);

	 /* Send Memory Address */
	 hi2c->Instance->CR2 = 0; //empty the reg

	 if(hi2c->Init.AddressingMode == I2C_ADDMODE_7BIT){ // set the pre-shifted 7-bit address
		 hi2c->Instance->CR2 |= ((uint32_t)DevAddress & 0xFEU);
		 hi2c->Instance->CR2 &= ~(1UL << 11U);
	 }else{
		 hi2c->Instance->CR2 |= ((uint32_t)DevAddress & 0x3FFU);
		 hi2c->Instance->CR2 |= (1UL << 11U);
	 }

	 hi2c->Instance->CR2 |= ((uint32_t)(MemAddSize  & 0xFF) << 16U); // set the mem size

	 hi2c->Instance->CR2 &= ~(1UL << 10U); // write
	 hi2c->Instance->CR2 |= (1UL << 13U); // start


	 if(MemAddSize == I2C_MEMADD_SIZE_8BIT){
		 while(!(hi2c->Instance->ISR & (0x01UL << 1U))){
			 if(hi2c->Instance->ISR & (0x01UL << 4U)){
				 return I2C_AbortTransfer(hi2c, ARM_ERROR);
			 }
			 if((Get_Tick() - tickstart) > timeout){
				 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
			 }
		 }

		 hi2c->Instance->TXDR = (uint8_t)(MemAddress & 0xFFU);

	 }else{

		 while(!(hi2c->Instance->ISR & (0x01UL << 1U))){
			 if(hi2c->Instance->ISR & (0x01UL << 4U)){
				 return I2C_AbortTransfer(hi2c, ARM_ERROR);
			 }
			 if((Get_Tick() - tickstart) > timeout){
				 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
			 }
		 }
		 hi2c->Instance->TXDR = (uint8_t)(MemAddress >> 8U);

		 while(!(hi2c->Instance->ISR & (0x01UL << 1U))){
			 if(hi2c->Instance->ISR & (0x01UL << 4U)){
				 return I2C_AbortTransfer(hi2c, ARM_ERROR);
			 }
			 if((Get_Tick() - tickstart) > timeout){
				 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
			 }
		 }
		 hi2c->Instance->TXDR = (uint8_t)(MemAddress & 0xFFU);

	 }

	 while(!(hi2c->Instance->ISR & (0x01UL << 6U))){
		 if(hi2c->Instance->ISR & (0x01UL << 4U)){
			 return I2C_AbortTransfer(hi2c, ARM_ERROR);
		 }
		 if((Get_Tick() - tickstart) > timeout){
			 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
		 }
	 }

	 /* Send Memory Address */ /* Phase 2 */
	 hi2c->Instance->CR2 = 0; //empty the reg

	 if(hi2c->Init.AddressingMode == I2C_ADDMODE_7BIT){ // set the pre-shifted 7-bit address
		 hi2c->Instance->CR2 |= ((uint32_t)DevAddress & 0xFEU);
		 hi2c->Instance->CR2 &= ~(1UL << 11U);
	 }else{
		 hi2c->Instance->CR2 |= ((uint32_t)DevAddress & 0x3FFU);
		 hi2c->Instance->CR2 |= (1UL << 11U);
	 }

	 hi2c->Instance->CR2 |= ((uint32_t)(Size  & 0xFF) << 16U); // set the mem size

	 hi2c->Instance->CR2 |= (1UL << 10U); // read
	 hi2c->Instance->CR2 |= (1UL << 25U); // AUTOEND
	 hi2c->Instance->CR2 |= (1UL << 13U); // start

	 /* Receive the data */
	 for(uint16_t i = 0; i < Size; i++){
		 while(!(hi2c->Instance->ISR & (0x01UL << 2U))){
			 if(hi2c->Instance->ISR & (0x01UL << 4U)){
				 return I2C_AbortTransfer(hi2c, ARM_ERROR);
			 }
			 if((Get_Tick() - tickstart) > timeout){
				 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
			 }
		 }
		 pData[i] = (uint8_t)hi2c->Instance->RXDR;
	 }
	 /* Check StopF */
	 while(!(hi2c->Instance->ISR & (1UL << 5U))){
		 if((Get_Tick() - tickstart) > timeout){
			 return I2C_AbortTransfer(hi2c, ARM_TIMEOUT);
		 }
	 }

	 hi2c->Instance->ICR |= (0x01UL << 5U);

	return ARM_OK;
}

void __I2C_ENABLE(I2c_TypeDef* Insatance){
	Insatance->CR1 |= (1UL << 0U);
}
void __I2C_DISABLE(I2c_TypeDef* Insatance){
	Insatance->CR1 &= ~(1UL << 0U);
}
