/*
 * pwr.c
 *
 *  Created on: Jun 13, 2025
 *      Author: Srivisweswara Mohan Santhi
 */


#include "pwr.h"


Status_TypeDef PWR_ConfigSupply(uint32_t SupplySource){

	uint32_t tickstart = 0;

	if((PWR->CR3 & PWR_CR3_SCUEN) == 0U){
		if((PWR->CR3 & PWR_SUPPLY_CONFIG_MASK) != SupplySource){
			return ARM_ERROR;
		}
		else{
			return ARM_OK;
		}
	}

	PWR->CR3 &= ~PWR_SUPPLY_CONFIG_MASK;
	PWR->CR3 |= SupplySource;

	tickstart = Get_Tick();
	while(!(PWR->CSR1 & PWR_CSR1_ACTVOSRDY)){
		if((Get_Tick() - tickstart) > PWR_TIMEOUT){
			return ARM_TIMEOUT;
		}
	}

	return ARM_OK;
}

void __PWR_VOLTAGESCALING_CONFIG(uint32_t RegulatorVoltageScale){

	uint32_t tmpreg = 0;

	if(RegulatorVoltageScale == PWR_REGULATOR_VOLTAGE_SCALE0){
		if((PWR->CR3 & PWR_CR3_LDOEN) == PWR_CR3_LDOEN){
			PWR->D3CR &= ~PWR_D3CR_VOS_Msk;
			PWR->D3CR |= PWR_REGULATOR_VOLTAGE_SCALE1;

			while(!(PWR->CSR1 & PWR_CSR1_ACTVOSRDY)){}

			tmpreg = PWR->D3CR & PWR_D3CR_VOS_Msk;
			(void)tmpreg;

			SYSCFG->PWRCR |= SYSCFG_PWRCR_ODEN;

			tmpreg = SYSCFG->PWRCR & SYSCFG_PWRCR_ODEN;
			(void)tmpreg;
		}
	}
	else{
		if((SYSCFG->PWRCR & SYSCFG_PWRCR_ODEN) != 0U){
			SYSCFG->PWRCR &= ~SYSCFG_PWRCR_ODEN;

			while(!(PWR->CSR1 & PWR_CSR1_ACTVOSRDY)){}

			tmpreg = SYSCFG->PWRCR & SYSCFG_PWRCR_ODEN;
			(void)tmpreg;
		}

		PWR->D3CR &= ~PWR_D3CR_VOS_Msk;
		PWR->D3CR |= RegulatorVoltageScale;

		tmpreg = PWR->D3CR & PWR_D3CR_VOS_Msk;
		(void)tmpreg;
	}
}

uint8_t __PWR_GET_FLAG(uint32_t flag){

	if(flag == PWR_FLAG_VOSRDY)
		return ((PWR->D3CR & PWR_D3CR_VOSRDY) == PWR_D3CR_VOSRDY);
	else if(flag == PWR_FLAG_ACTVOSRDY)
		return ((PWR->CSR1 & PWR_CSR1_ACTVOSRDY) == PWR_CSR1_ACTVOSRDY);

	return 0U;
}

void ExitRun0Mode(void){
	PWR->CR3 |= PWR_CR3_LDOEN;

	while(!(PWR->CSR1 & PWR_CSR1_ACTVOSRDY)){}
}
