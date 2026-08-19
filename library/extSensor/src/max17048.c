/*
 * max17048.c
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */


#include "max17048.h"

extern I2C_HandleTypeDef  hi2c1;


Status_TypeDef MAX17048_Read16(uint8_t reg, uint16_t *value){

	Status_TypeDef ret;
	uint8_t buf[2];

	ret = I2C_MEM_Read(&hi2c1, MAX17048_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buf, 2, 100);

	if(ret == ARM_OK){
		*value = ((uint16_t) buf[0]<<8) | buf[1];
	}

	return ret;
}

float MAX17048_Get_Voltage(void){

	uint16_t rawData;

	if(MAX17048_Read16(MAX17048_VCELL, &rawData) != ARM_OK){
		return -1.0f;
	}

	return rawData * 0.000078125f;

}

float MAX17048_Get_SOC(void){

	uint16_t rawData;

	if(MAX17048_Read16(MAX17048_SOC, &rawData) != ARM_OK){
		return -1.0f;
	}

	return rawData * 0.00390625f;

}

float MAX17048_Get_CRATE(void){
	uint16_t rawData;
	int16_t signedRawData;

	if(MAX17048_Read16(MAX17048_CRATE, &rawData) != ARM_OK){
		return -1.0f;
	}

	signedRawData = (int16_t)rawData;

	return signedRawData * 0.208f;
}
