/*
 * pwr.h
 *
 *  Created on: Jun 13, 2025
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef PWR_H_
#define PWR_H_

#include "main.h"


typedef struct{
	__IO uint32_t CR1;		/*Power control register 1*/
	__IO uint32_t CSR1;		/*Power control/status register 1*/
	__IO uint32_t CR2;		/*Power control register 2*/
	__IO uint32_t CR3;		/*Power control register 3*/
	__IO uint32_t CPUCR;	/*CPU power control register*/
	uint32_t RESERVED0;
	__IO uint32_t D3CR;		/*D3 domain control register*/
	uint32_t RESERVED1;
	__IO uint32_t WKUPCR;	/*Wakeup clear register*/
	__IO uint32_t WKUPFR;	/*Wakeup flag register*/
	__IO uint32_t WKUPEPR;	/*Wakeup enable and polarity register*/
}PWR_TypeDef;

typedef struct{
	uint32_t RESERVED0;
	__IO uint32_t PMCR;
	__IO uint32_t EXTICR1;
	__IO uint32_t EXTICR2;
	__IO uint32_t EXTICR3;
	__IO uint32_t EXTICR4;
	__IO uint32_t CFGR;
	uint32_t RESERVED1;
	__IO uint32_t CCCSR;
	__IO uint32_t CCVR;
	__IO uint32_t CCCR;
	__IO uint32_t PWRCR;
}SYSCFG_TypeDef;

#define PWR			   	((PWR_TypeDef*) PWR_BASE)
#define SYSCFG			((SYSCFG_TypeDef*) SYSCFG_BASE)

#define PWR_CR3_BYPASS				(1U << 0U)
#define PWR_CR3_LDOEN				(1U << 1U)
#define PWR_CR3_SCUEN				(1U << 2U)

#define PWR_CSR1_ACTVOSRDY			(1U << 13U)

#define PWR_D3CR_VOSRDY				(1U << 13U)
#define PWR_D3CR_VOS_0				(1U << 14U)
#define PWR_D3CR_VOS_1				(1U << 15U)
#define PWR_D3CR_VOS_Msk			(0x03U << 14U)

#define SYSCFG_PWRCR_ODEN			(1U << 0U)

#define PWR_LDO_SUPPLY				PWR_CR3_LDOEN
#define PWR_EXTERNAL_SOURCE_SUPPLY	PWR_CR3_BYPASS
#define PWR_SUPPLY_CONFIG_MASK		(PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS)

#define PWR_REGULATOR_VOLTAGE_SCALE0	(0x00U)
#define PWR_REGULATOR_VOLTAGE_SCALE1	(PWR_D3CR_VOS_1 | PWR_D3CR_VOS_0)
#define PWR_REGULATOR_VOLTAGE_SCALE2	(PWR_D3CR_VOS_1)
#define PWR_REGULATOR_VOLTAGE_SCALE3	(PWR_D3CR_VOS_0)

#define PWR_FLAG_ACTVOSRDY			(0x0DU)
#define PWR_FLAG_VOSRDY				(0x10U)

#define PWR_TIMEOUT					1000U

Status_TypeDef PWR_ConfigSupply(uint32_t SupplySource);
void __PWR_VOLTAGESCALING_CONFIG(uint32_t RegulatorVoltageScale);
uint8_t __PWR_GET_FLAG(uint32_t flag);
void ExitRun0Mode(void);

#endif /* PWR_H_ */
