/*
 * main.h
 *
 *  Created on: Aug 15, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#include "main.h"

void SystemSetup(void);
void SystemClock_Config(void);
void M_GPIO_Init(void);
void M_USART1_Init(void);
void M_LTDC_Init(void);


void Error_Handler(void);

UART_HandleTypeDef huart1;
LTDC_HandleTypeDef hltdc;

static uint8_t layer0_fb[240 * 136 * 3];

uint32_t apb2clk = 0;
float ltdcclkss = 0.00;

volatile uint32_t ltdc_bccr_addr = 0;
uint32_t LTDC_GetBCCR_Address(void)
{
    return (uint32_t)&(LTDC->BCCR);
}
int main(void)
{

	SystemSetup();

	FPU_Init();

	SystemClock_Config();

	M_GPIO_Init();

	M_USART1_Init();
	for (uint32_t i = 0; i < sizeof(layer0_fb); i += 3) {
	    layer0_fb[i + 0] = 0xFF; // B
	    layer0_fb[i + 1] = 0x00; // G
	    layer0_fb[i + 2] = 0x00; // R
	}
	M_LTDC_Init();

	ltdc_bccr_addr = LTDC_GetBCCR_Address();

	ltdcclkss = __RCC_GetLTDC_CLKFreq();

	while(1){
		printf("Hello from Retro Console :) !!");
		GPIO_TogglePin(GPIOH, GPIO_PIN_7);
		delay(1000);

	}
}

void SystemSetup(void){
	__RCC_SYSCFG_CLK_ENABLE();
	TimeBase_Init(SYS_DEF_CORE_CLOCK);
}

void SystemClock_Config(void){
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	if(PWR_ConfigSupply(PWR_LDO_SUPPLY) != ARM_OK){
		Error_Handler();
	}

	__PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

	while(!__PWR_GET_FLAG(PWR_FLAG_VOSRDY)){}

	RCC_OscInitStruct.OscillatorType = RCC_OSC_TYPE_HSE;
	RCC_OscInitStruct.HSEState = HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLL_HSE_SRC;
	RCC_OscInitStruct.PLL.PLLM = 5;
	RCC_OscInitStruct.PLL.PLLN = 192;
	RCC_OscInitStruct.PLL.PLLP = 2;
	RCC_OscInitStruct.PLL.PLLQ = 2;
	RCC_OscInitStruct.PLL.PLLR = 2;
	RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
	RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
	RCC_OscInitStruct.PLL.PLLFRACN = 0;

	if(RCC_OscConfig(&RCC_OscInitStruct) != ARM_OK){
		Error_Handler();
	}

	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLOCKSOURCE_PLLCLK;
	RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
	RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

	if(RCC_ClkConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != ARM_OK){
		Error_Handler();
	}
}

void M_GPIO_Init(void){

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__RCC_GPIOH_CLK_ENABLE();


	GPIO_InitStruct.Pin       = GPIO_PIN_7;
	GPIO_InitStruct.Mode      = GPIO_OUTPUT;
	GPIO_InitStruct.OType     = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull      = GPIO_NOPULL;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;
	GPIO_Init(GPIOH, &GPIO_InitStruct);

//	GPIO_InitStruct.Pin       = GPIO_PIN_13;
//	GPIO_InitStruct.Mode      = GPIO_INPUT;
//	GPIO_InitStruct.Pull      = GPIO_NOPULL;
//	GPIO_Init(GPIOC, &GPIO_InitStruct);

// 	Debounce_Init(&user_btn, 100);

//	pc13_exti_interrupt(EXTI15_10_IRQ);
}

void M_USART1_Init(void){
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = USART_WL_8B;
	huart1.Init.StopBits = USART_STOP_BIT1;
	huart1.Init.parity = USART_PARITY_NONE;
	huart1.Init.Mode = USART_MODE_TX_RX;
	huart1.Init.HWFlowCtl = USART_HWCONTROL_NONE;
	huart1.Init.OverSampling = USART_OverSampling_16;
	huart1.Init.OneBitSampling = 0;
	huart1.Init.ClockPrescaler = 0;
	huart1.AdvancedInit.AdvFeatureInit = 0;

	if(USART_Init(&huart1) != ARM_OK){
		Error_Handler();
	}
}

void M_LTDC_Init(void){

	LTDC_LayerCfgTypeDef pLayer0cfg = {0};

	hltdc.Instance = LTDC;

	/* Need MACROS */
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IP;
	/* Need MACROS */

	hltdc.Init.HorizontalSync = 40;
	hltdc.Init.VerticalSync = 9;
	hltdc.Init.AccumulatedHBP = 42;
	hltdc.Init.AccumulatedVBP = 11;
	hltdc.Init.AccumulatedActiveW = 522;
	hltdc.Init.AccumulatedActiveH = 283;
	hltdc.Init.TotalWidth = 524;
	hltdc.Init.TotalHeight = 285;
	hltdc.Init.BackColor.Red = 0xFF;
	hltdc.Init.BackColor.Green = 0x50;
	hltdc.Init.BackColor.Blue = 150;

	if(LTDC_Init(&hltdc) != ARM_OK){
		Error_Handler();
	}


	pLayer0cfg.HorizontalStart = 240;
	pLayer0cfg.HorizontalStop = 480;
	pLayer0cfg.VerticalStart = 136;
	pLayer0cfg.VerticalStop = 272;
	pLayer0cfg.PixelFormat = LTDC_PIXELFORMAT_RGB888;
	pLayer0cfg.Alpha = 255;
	pLayer0cfg.Alpha0 = 100;
	pLayer0cfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayer0cfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayer0cfg.FrameBuffStAdd = (uint32_t)layer0_fb;
	pLayer0cfg.ImageWidth = 240;
	pLayer0cfg.ImageHeight = 136;
	pLayer0cfg.BackColor.Red = 0;
	pLayer0cfg.BackColor.Green = 0xff;
	pLayer0cfg.BackColor.Blue = 0;

	if(LTDC_ConfigLayer(&hltdc, &pLayer0cfg, 0) != ARM_OK){
		Error_Handler();
	}

}


void Error_Handler(void){
	while(1){
		GPIO_TogglePin(GPIOH, GPIO_PIN_7);
		delay(500);
	}
}
