/*
 * ltdc.c
 *
 *  Created on: Aug 17, 2026
 *      Author: Srivisweswara Mohan Santhi
 */


#include "ltdc.h"

Status_TypeDef LTDC_Init(LTDC_HandleTypeDef* hltdc){

	if(hltdc == NULL){
		return ARM_ERROR;
	}

	LTDC_MSPInit(hltdc);


	// Configure Horizontal Synchronization Width & Vertical Synchronization Height
	hltdc->Instance->SSCR = ((hltdc->Init.VerticalSync & 0x07FF) << 0U) | ((hltdc->Init.HorizontalSync & 0x0FFF) << 16U);


	// Configure Accumulated Horizontal Back Porch & Accumulated Vertical Back Porch
	hltdc->Instance->BPCR = ((hltdc->Init.AccumulatedVBP & 0x07FF) << 0U) | ((hltdc->Init.AccumulatedHBP & 0x0FFF) << 16U);

	// Configure Accumulated Active Height & Accumulated Active Width
	hltdc->Instance->AWCR = ((hltdc->Init.AccumulatedActiveH & 0x07FF) << 0U) | ((hltdc->Init.AccumulatedActiveW & 0x0FFF) << 16U);

	// Configure Accumulated Active Height & Accumulated Active Width
	hltdc->Instance->TWCR = ((hltdc->Init.TotalHeight & 0x07FF) << 0U) | ((hltdc->Init.TotalWidth & 0x0FFF) << 16U);

	// default polarity for hsync, vsync, ltdc_clk, DE
	hltdc->Instance->GCR &= ~((1U << 31) | (1U << 30) | (1U << 29) | (1U << 28));
	hltdc->Instance->GCR |= (hltdc->Init.HSPolarity) | (hltdc->Init.VSPolarity) | (hltdc->Init.DEPolarity) | (hltdc->Init.PCPolarity);


	// Configure Background Color
	hltdc->Instance->BCCR = ((hltdc->Init.BackColor.Blue & 0xFFU) << 0U) | ((hltdc->Init.BackColor.Green & 0xFFU) << 8U) | ((hltdc->Init.BackColor.Red & 0xFFU) << 16U);

	// Enable LTDC
	hltdc->Instance->GCR |= (0x01U << 0);

	return ARM_OK;
}

Status_TypeDef LTDC_ConfigLayer(LTDC_HandleTypeDef* hltdc, LTDC_LayerCfgTypeDef* pLayer0cfg, uint32_t LayerIdx){

	uint32_t temp = 0;

	hltdc->LayerCfg[LayerIdx] = *pLayer0cfg;

	// Configure Horizontal Start stop position
	if(LayerIdx == 0){
		hltdc->Instance->L1WHPCR =
				((((hltdc->LayerCfg[0].HorizontalStart +
				((hltdc->Instance->BPCR >> 16U ) & 0x0FFFU)) + 1U) & 0x0FFFU) << 0U) |
				(((hltdc->LayerCfg[0].HorizontalStop +
				((hltdc->Instance->BPCR >> 16U) & 0x0FFFU)) & 0x0FFFU) << 16U);
	}
	else{
		hltdc->Instance->L2WHPCR =
				((((hltdc->LayerCfg[1].HorizontalStart +
				((hltdc->Instance->BPCR >> 16U) & 0x0FFFU)) + 1U) & 0x0FFFU) << 0U) |
				(((hltdc->LayerCfg[1].HorizontalStop +
				((hltdc->Instance->BPCR >> 16U) & 0x0FFFU)) & 0x0FFFU) << 16U);
	}


	// Configure Vertical Start stop position
	if(LayerIdx == 0){
		hltdc->Instance->L1WVPCR =
				((((hltdc->LayerCfg[0].VerticalStart +
				(hltdc->Instance->BPCR & 0x07FFU)) + 1U) & 0x07FFU) << 0U) |
				(((hltdc->LayerCfg[0].VerticalStop +
				(hltdc->Instance->BPCR & 0x07FFU)) & 0x07FFU) << 16U);
	}
	else{
		hltdc->Instance->L2WVPCR =
				((((hltdc->LayerCfg[1].VerticalStart +
				(hltdc->Instance->BPCR & 0x07FFU)) + 1U) & 0x07FFU) << 0U) |
				(((hltdc->LayerCfg[1].VerticalStop +
				(hltdc->Instance->BPCR & 0x07FFU)) & 0x07FFU) << 16U);
	}

	// Set the Pixel Format
	if(LayerIdx == 0){
		hltdc->Instance->L1PFCR = hltdc->LayerCfg[0].PixelFormat & 0x7;
	}
	else{
		hltdc->Instance->L2PFCR = hltdc->LayerCfg[1].PixelFormat & 0x7;
	}

	// Set the Default color values
	if(LayerIdx == 0){
		hltdc->Instance->L1DCCR = ((hltdc->LayerCfg[0].BackColor.Blue & 0xFFU) << 0U) | ((hltdc->LayerCfg[0].BackColor.Green & 0xFFU) << 8U) | ((hltdc->LayerCfg[0].BackColor.Red & 0xFFU) << 16U) | ((hltdc->LayerCfg[0].Alpha0 & 0xFFU) << 24U);
	}
	else{
		hltdc->Instance->L2DCCR = ((hltdc->LayerCfg[1].BackColor.Blue & 0xFFU) << 0U) | ((hltdc->LayerCfg[1].BackColor.Green & 0xFFU) << 8U) | ((hltdc->LayerCfg[1].BackColor.Red & 0xFFU) << 16U) | ((hltdc->LayerCfg[1].Alpha0 & 0xFFU) << 24U);
	}

	// Set the constant alpha value
	if(LayerIdx == 0){
		hltdc->Instance->L1CACR = (hltdc->LayerCfg[0].Alpha & 0xFFU);
	}
	else{
		hltdc->Instance->L2CACR = (hltdc->LayerCfg[1].Alpha & 0xFFU);
	}

	// Set the constant alpha value
	if(LayerIdx == 0){
		hltdc->Instance->L1BFCR = ((hltdc->LayerCfg[0].BlendingFactor1 & 0x7U) << 8U) | ((hltdc->LayerCfg[0].BlendingFactor2 & 0x7U) << 0U);
	}
	else{
		hltdc->Instance->L2BFCR = ((hltdc->LayerCfg[1].BlendingFactor1 & 0x7U) << 8U) | ((hltdc->LayerCfg[1].BlendingFactor2 & 0x7U) << 0U);
	}

	// Set the color frame buffer start address
	if(LayerIdx == 0){
		hltdc->Instance->L1CFBAR = hltdc->LayerCfg[0].FrameBuffStAdd;
	}
	else{
		hltdc->Instance->L2CFBAR = hltdc->LayerCfg[1].FrameBuffStAdd;
	}


	//
	if(hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_ARGB8888){
		temp = 4U;
	}
	else if(hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_RGB888){
		temp = 3U;
	}
	else if(hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_RGB565 ||
			hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_ARGB4444 ||
			hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_ARGB1555 ||
			hltdc->LayerCfg[LayerIdx].PixelFormat == LTDC_PIXELFORMAT_AL88){
		temp = 2U;
	}
	else{
		temp = 1U;
	}


	//Set the Image Width / pitch in byte
	if(LayerIdx == 0){
	hltdc->Instance->L1CFBLR = ((hltdc->LayerCfg[0].ImageWidth * temp) << 16U) |
								(((hltdc->LayerCfg[0].HorizontalStop - hltdc->LayerCfg[0].HorizontalStart) * temp) + 7U);
	}
	else{
	hltdc->Instance->L2CFBLR = ((hltdc->LayerCfg[1].ImageWidth * temp) << 16U) |
								(((hltdc->LayerCfg[1].HorizontalStop - hltdc->LayerCfg[1].HorizontalStart) * temp) + 7U);
	}

	//Set the Image Height / line number
	if(LayerIdx == 0){
		hltdc->Instance->L1CFBLNR = hltdc->LayerCfg[0].ImageHeight & 0x07FFU;
	}else{
		hltdc->Instance->L2CFBLNR = hltdc->LayerCfg[1].ImageHeight & 0x07FFU;
	}

	// Enable the LTDC Layer
	if(LayerIdx == 0){
		hltdc->Instance->L1CR |= (0x01UL << 0U);
	}
	else{
		hltdc->Instance->L2CR |= (0x01UL << 0U);
	}

	hltdc->Instance->SRCR = (0x01UL << 0U);

	return ARM_OK;
}


Status_TypeDef LTDC_Reload(LTDC_HandleTypeDef* hltdc, uint32_t LayerIdx){
	return ARM_OK;
}
