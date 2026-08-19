/*
 * i2c.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef MCU_INC_I2C_H_
#define MCU_INC_I2C_H_

#include "main.h"

typedef struct{
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t OAR1;
	__IO uint32_t OAR2;
	__IO uint32_t TIMR;
	__IO uint32_t TIMOUTR;
	__IO uint32_t ISR;
	__IO uint32_t ICR;
	__IO uint32_t PECR;
	__IO uint32_t RXDR;
	__IO uint32_t TXDR;
}I2c_TypeDef;

typedef struct{
	uint32_t Timing;
	uint32_t OwnAddr1;
	uint32_t AddressingMode;
	uint32_t DualAddressingMode;
	uint32_t OwnAddr2;
	uint32_t OwnAddr2Mask;
	uint32_t GeneralCallMode;
	uint32_t NoStrechMode;
}I2c_InitTypeDef;

typedef struct{
	I2c_TypeDef *Instance;
	I2c_InitTypeDef Init;
}I2C_HandleTypeDef;

#define I2C1	((I2c_TypeDef*) I2C1_BASE)
#define I2C2	((I2c_TypeDef*) I2C2_BASE)
#define I2C3	((I2c_TypeDef*) I2C3_BASE)
#define I2C4	((I2c_TypeDef*) I2C4_BASE)

#define	I2C_ADDMODE_7BIT		(0x0001U)
#define	I2C_ADDMODE_10BIT		(0x0002U)

#define I2C_DUALADDRESS_DISABLE	(0x0000U)
#define I2C_DUALADDRESS_ENABLE	(0x01UL << 15U)

#define I2C_OA2_NOMASK			((uint8_t) 0x00U)
#define I2C_OA2_MASK1			((uint8_t) 0x01U)
#define I2C_OA2_MASK2			((uint8_t) 0x02U)
#define I2C_OA2_MASK3			((uint8_t) 0x03U)
#define I2C_OA2_MASK4			((uint8_t) 0x04U)
#define I2C_OA2_MASK5			((uint8_t) 0x05U)
#define I2C_OA2_MASK6			((uint8_t) 0x06U)
#define I2C_OA2_MASK7			((uint8_t) 0x07U)

#define I2C_GENERALCALL_DISABLE	(0x0000UL)
#define I2C_GENERALCALL_ENABLE	(0x01UL << 19U)

#define I2C_NOSTRECH_DISABLE	(0x0000UL)
#define I2C_NOSTRECH_ENABLE	(0x01UL << 17U)

#define I2C_MEMADD_SIZE_8BIT   1U
#define I2C_MEMADD_SIZE_16BIT  2U

Status_TypeDef I2C_Init(I2C_HandleTypeDef* hi2c);
Status_TypeDef I2C_MEM_Read(I2C_HandleTypeDef* hi2c, uint16_t DevAddress, uint16_t MemAddress,
							uint16_t MemAddSize, uint8_t* pData, uint16_t Size, uint32_t timeout);

void __I2C_ENABLE(I2c_TypeDef* Insatance);
void __I2C_DISABLE(I2c_TypeDef* Insatance);

void I2C_MspInit(I2C_HandleTypeDef* hi2c);
#endif /* MCU_INC_I2C_H_ */
