/*
 * rcc.c
 *
 *  Created on: Jun 13, 2025
 *      Author: Srivisweswara Mohan Santhi
 */


#include "rcc.h"

static Status_TypeDef RCC_WaitForFlag(volatile uint32_t *reg, uint32_t mask, uint8_t state, uint32_t timeout){

	uint32_t tickstart = Get_Tick();

	if(state){
		while(!(*reg & mask)){
			if((Get_Tick() - tickstart) > timeout)	return ARM_TIMEOUT;
		}
	}
	else{
		while(*reg & mask){
			if((Get_Tick() - tickstart) > timeout)	return ARM_TIMEOUT;
		}
	}

	return ARM_OK;
}

static uint32_t RCC_APBPrescTable(uint32_t prescaler){
	if(prescaler < 4U)
		return 1U;
	else
		return (1U << (prescaler - 3U));
}

void RCC_Enable(uint32_t pheripheral, uint8_t bus){
	if(bus == AHB1_EN)
		RCC->AHB1ENR |= pheripheral;
	else if (bus == AHB2_EN)
		RCC->AHB2ENR |= pheripheral;
	else if (bus == AHB3_EN)
		RCC->AHB3ENR |= pheripheral;
	else if (bus == AHB4_EN)
		RCC->AHB4ENR |= pheripheral;
	else if (bus == APB1L_EN)
		RCC->APB1LENR |= pheripheral;
	else if (bus == APB1H_EN)
		RCC->APB1HENR |= pheripheral;
	else if (bus == APB2_EN)
		RCC->APB2ENR |= pheripheral;
	else if (bus == APB3_EN)
		RCC->APB3ENR |= pheripheral;
	else if (bus == APB4_EN)
		RCC->APB4ENR |= pheripheral;
}

void RCC_Disable(uint32_t pheripheral, uint8_t bus){
	if(bus == AHB1_EN)
		RCC->AHB1ENR &= ~pheripheral;
	else if (bus == AHB2_EN)
		RCC->AHB2ENR &= ~pheripheral;
	else if (bus == AHB3_EN)
		RCC->AHB3ENR &= ~pheripheral;
	else if (bus == AHB4_EN)
		RCC->AHB4ENR &= ~pheripheral;
	else if (bus == APB1L_EN)
		RCC->APB1LENR &= ~pheripheral;
	else if (bus == APB1H_EN)
		RCC->APB1HENR &= ~pheripheral;
	else if (bus == APB2_EN)
		RCC->APB2ENR &= ~pheripheral;
	else if (bus == APB3_EN)
		RCC->APB3ENR &= ~pheripheral;
	else if (bus == APB4_EN)
		RCC->APB4ENR &= ~pheripheral;
}

Status_TypeDef RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct){

	/*Configure HSE*/
	if((RCC_OscInitStruct->OscillatorType & RCC_OSC_TYPE_HSE) == RCC_OSC_TYPE_HSE){
		if(RCC_OscInitStruct->HSEState == HSE_ON){
			RCC->CR &= ~RCC_CR_HSEBYP;
			RCC->CR |= RCC_CR_HSEON;
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_HSERDY, 1U, HSE_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else if(RCC_OscInitStruct->HSEState == HSE_BYP){
			RCC->CR |= (RCC_CR_HSEBYP | RCC_CR_HSEON);
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_HSERDY, 1U, HSE_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else{
			RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP);
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_HSERDY, 0U, HSE_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
	}

	/*Configure HSI*/
	if((RCC_OscInitStruct->OscillatorType & RCC_OSC_TYPE_HSI) == RCC_OSC_TYPE_HSI){
		if(RCC_OscInitStruct->HSIState == HSI_ON){
			RCC->CR |= RCC_CR_HSION;
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_HSIRDY, 1U, HSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else{
			RCC->CR &= ~RCC_CR_HSION;
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_HSIRDY, 0U, HSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
	}

	/*Configure CSI*/
	if((RCC_OscInitStruct->OscillatorType & RCC_OSC_TYPE_CSI) == RCC_OSC_TYPE_CSI){
		if(RCC_OscInitStruct->CSIState == CSI_ON){
			RCC->CR |= RCC_CR_CSION;
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_CSIRDY, 1U, CSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else{
			RCC->CR &= ~RCC_CR_CSION;
			if(RCC_WaitForFlag(&RCC->CR, RCC_CR_CSIRDY, 0U, CSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
	}

	/*Configure LSE*/
	if((RCC_OscInitStruct->OscillatorType & RCC_OSC_TYPE_LSE) == RCC_OSC_TYPE_LSE){
		if(RCC_OscInitStruct->LSEState == LSE_ON){
			RCC->BDCR |= RCC_BDCR_LSEON;
			if(RCC_WaitForFlag(&RCC->BDCR, RCC_BDCR_LSERDY, 1U, LSE_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else{
			RCC->BDCR &= ~RCC_BDCR_LSEON;
			if(RCC_WaitForFlag(&RCC->BDCR, RCC_BDCR_LSERDY, 0U, LSE_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
	}

	/*Configure LSI*/
	if((RCC_OscInitStruct->OscillatorType & RCC_OSC_TYPE_LSI) == RCC_OSC_TYPE_LSI){
		if(RCC_OscInitStruct->LSIState == LSI_ON){
			RCC->CSR |= RCC_CSR_LSION;
			if(RCC_WaitForFlag(&RCC->CSR, RCC_CSR_LSIRDY, 1U, LSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
		else{
			RCC->CSR &= ~RCC_CSR_LSION;
			if(RCC_WaitForFlag(&RCC->CSR, RCC_CSR_LSIRDY, 0U, LSI_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
		}
	}

	/*Configure PLL1*/
	if(RCC_OscInitStruct->PLL.PLLState != PLL_NONE){
		RCC->CR &= ~RCC_CR_PLL1ON;
		if(RCC_WaitForFlag(&RCC->CR, RCC_CR_PLL1RDY, 0U, PLL_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;

		RCC->PLLCKSELR &= ~(RCC_PLLCKSELR_PLLSRC | RCC_PLLCKSELR_DIVM1);
		RCC->PLLCKSELR |= (RCC_OscInitStruct->PLL.PLLSource |
						  (RCC_OscInitStruct->PLL.PLLM << 4U));

		RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLL1RGE | RCC_PLLCFGR_PLL1VCOSEL);
		RCC->PLLCFGR |= (RCC_OscInitStruct->PLL.PLLRGE |
						RCC_OscInitStruct->PLL.PLLVCOSEL |
						RCC_PLLCFGR_DIVP1EN |
						RCC_PLLCFGR_DIVQ1EN |
						RCC_PLLCFGR_DIVR1EN);

		RCC->PLL1DIVR = (((RCC_OscInitStruct->PLL.PLLN - 1U) << 0U) |
						 ((RCC_OscInitStruct->PLL.PLLP - 1U) << 9U) |
						 ((RCC_OscInitStruct->PLL.PLLQ - 1U) << 16U) |
						 ((RCC_OscInitStruct->PLL.PLLR - 1U) << 24U));

		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLL1FRACEN;
		RCC->PLL1FRACR = (RCC_OscInitStruct->PLL.PLLFRACN << 3U);

		RCC->CR |= RCC_CR_PLL1ON;
		if(RCC_WaitForFlag(&RCC->CR, RCC_CR_PLL1RDY, 1U, PLL_TIMEOUT) != ARM_OK) return ARM_TIMEOUT;
	}

	return ARM_OK;
}

Status_TypeDef RCC_ClkConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t Flash_Latency){

	uint32_t tickstart;

	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |= Flash_Latency;

	while((FLASH->ACR & FLASH_ACR_LATENCY) != Flash_Latency);

	RCC->D1CFGR &= ~(RCC_D1CFGR_D1CPRE_Msk |
					 RCC_D1CFGR_HPRE_Msk |
					 RCC_D1CFGR_D1PPRE_Msk);

	RCC->D2CFGR &= ~(RCC_D2CFGR_D2PPRE1_Msk |
					 RCC_D2CFGR_D2PPRE2_Msk);

	RCC->D3CFGR &= ~(RCC_D3CFGR_D3PPRE_Msk);

	RCC->D1CFGR |= (RCC_ClkInitStruct->SYSCLKDivider |
					RCC_ClkInitStruct->AHBCLKDivider |
					RCC_ClkInitStruct->APB3CLKDivider);

	RCC->D2CFGR |= (RCC_ClkInitStruct->APB1CLKDivider |
					RCC_ClkInitStruct->APB2CLKDivider);

	RCC->D3CFGR |= RCC_ClkInitStruct->APB4CLKDivider;

	RCC->CFGR &= ~RCC_CFGR_SW_Msk;
	RCC->CFGR |= RCC_ClkInitStruct->SYSCLKSource;

	tickstart = Get_Tick();

	while((RCC->CFGR & RCC_CFGR_SWS_Msk) != (RCC_ClkInitStruct->SYSCLKSource << 3U)){
		if((Get_Tick() - tickstart) > CLOCKSWITCH_TIMEOUT) return ARM_TIMEOUT;
	}

	TimeBase_Init(RCC_GetSYSCLK_Freq());

	return ARM_OK;
}

Status_TypeDef RCCEx_PeripheralCLKConfig(RCC_PeripgCLKInitTypeDef *PeriphClkInit){

	uint32_t status = ARM_OK;

	if(PeriphClkInit->PeripheralClockSel == RCC_PERIPHCLK_LTDC){

		if(RCC_PLL3_Config(&(PeriphClkInit->PLL3), DIVIDER_R_UPDATE) != ARM_OK){
			status = ARM_ERROR;
		}

	}

	if(status == ARM_OK){
		return ARM_OK;
	}

	return ARM_ERROR;

}
Status_TypeDef RCC_PLL3_Config(RCC_PLL3InitTypeDef *pll3, uint32_t divider){

	uint32_t tickstart = 0;

	if(__RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_NONE){
		return ARM_ERROR;
	}

	else{
		__RCC_PLL3_DISABLE();

		tickstart = Get_Tick();

		while(RCC->CR & (1UL << 29U)){
			if((Get_Tick() - tickstart) > 2){
				return ARM_TIMEOUT;
			}
		}

		__RCC_PLL3_CONFIG(pll3->PLL3M,
						  pll3->PLL3N,
						  pll3->PLL3P,
						  pll3->PLL3Q,
						  pll3->PLL3R);

		RCC->PLLCFGR &= ~(0x3U << 10U);
		RCC->PLLCFGR |= pll3->PLL3RGE;

		RCC->PLLCFGR &= ~(0x1U << 9U);
		RCC->PLLCFGR |= pll3->PLL3VCOSEL;

		RCC->PLLCFGR &= ~(0x1UL << 8U);

		RCC->PLL3FRACR &= ~(0x1FFFUL << 3U);
		RCC->PLL3FRACR |= (pll3->PLL3FRACN << 3U);

		RCC->PLLCFGR |= (0x1UL << 8U);

		RCC->PLLCFGR &= ~((1UL << 22U) | (1UL << 23U) | (1UL << 24U));

		if(divider == DIVIDER_P_UPDATE){
			RCC->PLLCFGR |= (0x1UL << 22U);
		}
		else if(divider == DIVIDER_Q_UPDATE){
			RCC->PLLCFGR |= (0x1UL << 23U);
		}
		else{
			RCC->PLLCFGR |= (0x1UL << 24U);
		}

		__RCC_PLL3_ENABLE();

		tickstart = Get_Tick();

		while((RCC->CR & (1UL << 29U)) == 0){
			if((Get_Tick() - tickstart) > 2){
				return ARM_TIMEOUT;
			}
		}

	}

	return ARM_OK;

}

void __RCC_PLL3_CONFIG(uint32_t pll3m, uint32_t pll3n,uint32_t pll3p,uint32_t pll3q,uint32_t pll3r){

	RCC->PLLCKSELR &= ~(0x3FU << 20U);
	RCC->PLLCKSELR |= (pll3m << 20U);

	RCC->PLL3DIVR =  ((pll3n - 1) << 0)
				  	| ((pll3p - 1) << 9)
				  	| ((pll3q - 1) << 16)
				  	| ((pll3r - 1) << 24);

}

uint32_t RCC_GetSYSCLK_Freq(void){
	uint32_t sysclk_src = (RCC->CFGR >> 3U) & 0x03U;
	uint32_t pll_src, pllm, plln, pllp;
	uint32_t sysclk_freq;

	switch(sysclk_src){
		case 0x00U: //HSI
			sysclk_freq = HSI_FREQ;
			break;
		case 0x01U: //CSI
			sysclk_freq = CSI_FREQ;
			break;
		case 0x02U: //HSE
			sysclk_freq = HSE_FREQ;
			break;
		case 0x03U: //PLL1_P
			pll_src = RCC->PLLCKSELR & RCC_PLLCKSELR_PLLSRC;
			pllm = (RCC->PLLCKSELR & RCC_PLLCKSELR_DIVM1) >> 4U;
			plln = ((RCC->PLL1DIVR >> 0U) & 0x1FFU) + 1U;
			pllp = ((RCC->PLL1DIVR >> 9U) & 0x7FU) + 1U;

			if(pll_src == RCC_PLL_HSE_SRC)
				sysclk_freq = (HSE_FREQ / pllm) * plln / pllp;
			else if(pll_src == RCC_PLL_HSI_SRC)
				sysclk_freq = (HSI_FREQ / pllm) * plln / pllp;
			else if(pll_src == RCC_PLL_CSI_SRC)
				sysclk_freq = (CSI_FREQ / pllm) * plln / pllp;
			else
				sysclk_freq = 0U;
			break;
		default:
			sysclk_freq = 0U;
			break;
	}
	return sysclk_freq;
}

uint32_t RCC_GetHCLK_Freq(void){
	static const uint16_t AHBPrescalerTable[16] = {1U,1U,1U,1U,1U,1U,1U,1U,2U,4U,8U,16U,64U,128U,256U,512U};
	uint32_t hpre = (RCC->D1CFGR & RCC_D1CFGR_HPRE_Msk) >> 0U;
	uint32_t d1cpre = (RCC->D1CFGR & RCC_D1CFGR_D1CPRE_Msk) >> 8U;
	uint32_t sysclk_freq = RCC_GetSYSCLK_Freq();

	return (sysclk_freq / AHBPrescalerTable[d1cpre]) / AHBPrescalerTable[hpre];
}

uint32_t RCC_GetP1CLK_Freq(void){
	uint32_t apb1_Prescaler = (RCC->D2CFGR & RCC_D2CFGR_D2PPRE1_Msk) >> 4U;

	return RCC_GetHCLK_Freq()/RCC_APBPrescTable(apb1_Prescaler);
}

uint32_t RCC_GetP2CLK_Freq(void){
	uint32_t apb2_Prescaler = (RCC->D2CFGR & RCC_D2CFGR_D2PPRE2_Msk) >> 8U;

	return RCC_GetHCLK_Freq()/RCC_APBPrescTable(apb2_Prescaler);
}

uint32_t RCC_GetP3CLK_Freq(void){
	uint32_t apb3_Prescaler = (RCC->D1CFGR & RCC_D1CFGR_D1PPRE_Msk) >> 4U;

	return RCC_GetHCLK_Freq()/RCC_APBPrescTable(apb3_Prescaler);
}

uint32_t RCC_GetP4CLK_Freq(void){
	uint32_t apb4_Prescaler = (RCC->D3CFGR & RCC_D3CFGR_D3PPRE_Msk) >> 4U;

	return RCC_GetHCLK_Freq()/RCC_APBPrescTable(apb4_Prescaler);
}

float __RCC_GetLTDC_CLKFreq(void){
	uint32_t pll_src   = RCC->PLLCKSELR & RCC_PLLCKSELR_PLLSRC;
	uint32_t pll3m     = (RCC->PLLCKSELR >> 20U) & 0x3FU;
	uint32_t pll3n     = ((RCC->PLL3DIVR >> 0U)  & 0x1FFU) + 1U;
	uint32_t pll3r     = ((RCC->PLL3DIVR >> 24U) & 0x7FU)  + 1U;
	uint32_t pll3fracn = (RCC->PLL3FRACR >> 3U) & 0x1FFFU;

	float pll_src_clk = 0.0f;
	float plln        = (float)pll3n;

	if((RCC->CR & (1UL << 29U)) == 0U){
		return 0.0f;
	}

	if((RCC->PLLCFGR & (1UL << 24U)) == 0U){
		return 0.0f;
	}

	if(pll3m == 0U){
		return 0.0f;
	}

	if(RCC->PLLCFGR & (1UL << 8U)){
		plln += ((float)pll3fracn / 8192.0f);
	}

	if(pll_src == RCC_PLL_HSE_SRC){
		pll_src_clk = (float)HSE_FREQ;
	}
	else if(pll_src == RCC_PLL_HSI_SRC){
		pll_src_clk = (float)HSI_FREQ;
	}
	else if(pll_src == RCC_PLL_CSI_SRC){
		pll_src_clk = (float)CSI_FREQ;
	}
	else{
		return 0.0f;
	}

	return ((pll_src_clk / (float)pll3m) * plln) / (float)pll3r;
}

void __RCC_GPIOA_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOAEN;
}
void __RCC_GPIOB_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOBEN;
}
void __RCC_GPIOC_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOCEN;
}
void __RCC_GPIOD_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIODEN;
}
void __RCC_GPIOE_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOEEN;
}
void __RCC_GPIOF_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOFEN;
}
void __RCC_GPIOG_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOGEN;
}
void __RCC_GPIOH_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOHEN;
}
void __RCC_GPIOI_CLK_ENABLE(void){
	RCC->AHB4ENR |= GPIOIEN;
}

void __RCC_SYSCFG_CLK_ENABLE(void){
	RCC->APB4ENR |= SYSCFG_EN;
}
void __RCC_USART1_CLK_ENABLE(void){
	RCC->APB2ENR |= USART1_EN;
}
void __RCC_LTDC_CLK_ENABLE(void){
	RCC->APB3ENR |= LTDC_EN;
}


uint32_t __RCC_GET_PLL_OSCSOURCE(void){
	return RCC->PLLCKSELR & RCC_PLLCKSELR_PLLSRC;
}

void __RCC_PLL3_DISABLE(void){

	RCC->CR &= ~RCC_PLL3_ON;

}
void __RCC_PLL3_ENABLE(void){

	RCC->CR |= RCC_PLL3_ON;

}
