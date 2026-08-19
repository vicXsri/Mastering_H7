/*
 * ltdc.h
 *
 *  Created on: Aug 17, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef MCU_INC_LTDC_H_
#define MCU_INC_LTDC_H_

#include "main.h"

#define MAX_LAYER 2

typedef struct
{
    uint32_t reserved0[2];
    __IO uint32_t SSCR;
    __IO uint32_t BPCR;
    __IO uint32_t AWCR;
    __IO uint32_t TWCR;
    __IO uint32_t GCR;
    uint32_t reserved1[2];
    __IO uint32_t SRCR;
    uint32_t reserved2;
    __IO uint32_t BCCR;
    uint32_t reserved3;
    __IO uint32_t IER;
    __IO uint32_t ISR;
    __IO uint32_t ICR;
    __IO uint32_t LIPCR;
    __IO uint32_t CPSR;
    __IO uint32_t CDSR;
    uint32_t reserved4[14];

    __IO uint32_t L1CR;
    __IO uint32_t L1WHPCR;
    __IO uint32_t L1WVPCR;
    __IO uint32_t L1CKCR;
    __IO uint32_t L1PFCR;
    __IO uint32_t L1CACR;
    __IO uint32_t L1DCCR;
    __IO uint32_t L1BFCR;
    uint32_t reserved5[2];
    __IO uint32_t L1CFBAR;
    __IO uint32_t L1CFBLR;
    __IO uint32_t L1CFBLNR;
    uint32_t reserved6[3];
    __IO uint32_t L1CLUTWR;

    uint32_t reserved7[15];

    __IO uint32_t L2CR;
    __IO uint32_t L2WHPCR;
    __IO uint32_t L2WVPCR;
    __IO uint32_t L2CKCR;
    __IO uint32_t L2PFCR;
    __IO uint32_t L2CACR;
    __IO uint32_t L2DCCR;
    __IO uint32_t L2BFCR;
    uint32_t reserved8[2];
    __IO uint32_t L2CFBAR;
    __IO uint32_t L2CFBLR;
    __IO uint32_t L2CFBLNR;
    uint32_t reserved9[3];
    __IO uint32_t L2CLUTWR;
} LTDC_TypeDef;

typedef struct{
	uint8_t Blue;
	uint8_t Green;
	uint8_t Red;
	uint8_t Reserved;
}LTDC_ColorTypeDef;

typedef struct{
	uint32_t HSPolarity;
	uint32_t VSPolarity;
	uint32_t DEPolarity;
	uint32_t PCPolarity;
	uint32_t HorizontalSync;
	uint32_t VerticalSync;
	uint32_t AccumulatedHBP;
	uint32_t AccumulatedVBP;
	uint32_t AccumulatedActiveW;
	uint32_t AccumulatedActiveH;
	uint32_t TotalWidth;
	uint32_t TotalHeight;
	LTDC_ColorTypeDef BackColor;
}LTDC_InitTypeDef;

typedef struct{
	uint32_t HorizontalStart; /* Min => 0x000 & Max => 0XFFF */
	uint32_t HorizontalStop; /* Min => 0x000 & Max => 0XFFF */
	uint32_t VerticalStart; /* Min => 0x000 & Max => 0X7FF */
	uint32_t VerticalStop; /* Min => 0x000 & Max => 0X7FF */
	uint32_t PixelFormat; /* Defines the Pixel Format */
	uint32_t Alpha; /* Alpha fir Blending */
	uint32_t Alpha0; /* Default Alpha Value */
	uint32_t BlendingFactor1; /* Blending Factor 1 */
	uint32_t BlendingFactor2; /* Blending Factor 2 */
	uint32_t FrameBuffStAdd; /* Color Frame Buffer Start Address */
	uint32_t ImageWidth; /* Color Frame Buffer Line Length */
	uint32_t ImageHeight; /* Number of lines in FrameBuffer */
	LTDC_ColorTypeDef BackColor;
}LTDC_LayerCfgTypeDef;

typedef struct{
	LTDC_TypeDef			*Instance;
	LTDC_InitTypeDef		Init;
	LTDC_LayerCfgTypeDef	LayerCfg[MAX_LAYER];
}LTDC_HandleTypeDef;


#define LTDC 		((LTDC_TypeDef *) LTDC_BASE)

#define LTDC_PIXELFORMAT_ARGB8888 		0x00U
#define LTDC_PIXELFORMAT_RGB888 		0x01U
#define LTDC_PIXELFORMAT_RGB565 		0x02U
#define LTDC_PIXELFORMAT_ARGB1555 		0x03U
#define LTDC_PIXELFORMAT_ARGB4444 		0x04U
#define LTDC_PIXELFORMAT_L8 			0x05U
#define LTDC_PIXELFORMAT_AL44 			0x06U
#define LTDC_PIXELFORMAT_AL88 			0x07U

#define LTDC_BLENDING_FACTOR1_CA		0x400U	/* Cte Alpha */
#define LTDC_BLENDING_FACTOR1_PAxCA		0x600U  /* Cte Alpha x Pixel Alpha*/

#define LTDC_BLENDING_FACTOR2_CA		0x005U	/* Cte Alpha */
#define LTDC_BLENDING_FACTOR2_PAxCA		0x007U  /* Cte Alpha x Pixel Alpha*/

#define LTDC_HSPOLARITY_AL				0x00U
#define LTDC_HSPOLARITY_AH				(0x01UL << 31U)

#define LTDC_VSPOLARITY_AL				0x00U
#define LTDC_VSPOLARITY_AH				(0x01UL << 30U)

#define LTDC_DEPOLARITY_AL				0x00U
#define LTDC_DEPOLARITY_AH				(0x01UL << 29U)

#define LTDC_PCPOLARITY_IP			0x00U
#define LTDC_PCPOLARITY_IIPC			(0x01UL << 28U)

Status_TypeDef LTDC_Init(LTDC_HandleTypeDef* hltdc);
Status_TypeDef LTDC_ConfigLayer(LTDC_HandleTypeDef* hltdc, LTDC_LayerCfgTypeDef* pLayer0cfg, uint32_t LayerIdx);
Status_TypeDef LTDC_Reload(LTDC_HandleTypeDef* hltdc, uint32_t LayerIdx);

void LTDC_MSPInit(LTDC_HandleTypeDef* hltdc);

#endif /* MCU_INC_LTDC_H_ */
