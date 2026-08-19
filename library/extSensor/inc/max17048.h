/*
 * max17048.h
 *
 *  Created on: Aug 19, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef EXTSENSOR_INC_MAX17048_H_
#define EXTSENSOR_INC_MAX17048_H_

#include "main.h"

#define MAX17048_ADDR		(0x36UL << 1U)

#define MAX17048_VCELL		(0x02U)
#define MAX17048_SOC		(0x04U)
#define MAX17048_MODE		(0x06U)
#define MAX17048_VERSION	(0x08U)
#define MAX17048_HIBRT		(0x0AU)
#define MAX17048_CONFIG		(0x0CU)
#define MAX17048_VALRT		(0x14U)
#define MAX17048_CRATE		(0x16U)
#define MAX17048_VID		(0x18U)
#define MAX17048_STATUS		(0x1AU)
#define MAX17048_TABLE		(0x40U) // 0x40 - 0x7F
#define MAX17048_CMD		(0xFEU)

Status_TypeDef MAX17048_Read16(uint8_t reg, uint16_t *value);
float MAX17048_Get_Voltage(void);
float MAX17048_Get_SOC(void);
float MAX17048_Get_CRATE(void);

#endif /* EXTSENSOR_INC_MAX17048_H_ */
