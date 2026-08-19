/*
 * rcc.h
 *
 *  Created on: May 30, 2025
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef RCC_H_
#define RCC_H_

#include "main.h"

typedef struct
{
    __IO uint32_t CR;              /* 0x000 */

    union
    {
        __IO uint32_t ICSCR;       /* 0x004 */
        __IO uint32_t HSICFGR;     /* 0x004 */
    };

    __IO uint32_t CRRCR;           /* 0x008 */
    __IO uint32_t CSICFGR;         /* 0x00C */

    __IO uint32_t CFGR;            /* 0x010 */
    uint32_t RESERVED0;            /* 0x014 */

    __IO uint32_t D1CFGR;          /* 0x018 */
    __IO uint32_t D2CFGR;          /* 0x01C */
    __IO uint32_t D3CFGR;          /* 0x020 */

    uint32_t RESERVED1;            /* 0x024 */

    __IO uint32_t PLLCKSELR;       /* 0x028 */
    __IO uint32_t PLLCFGR;         /* 0x02C */

    __IO uint32_t PLL1DIVR;        /* 0x030 */
    __IO uint32_t PLL1FRACR;       /* 0x034 */
    __IO uint32_t PLL2DIVR;        /* 0x038 */
    __IO uint32_t PLL2FRACR;       /* 0x03C */
    __IO uint32_t PLL3DIVR;        /* 0x040 */
    __IO uint32_t PLL3FRACR;       /* 0x044 */

    uint32_t RESERVED2;            /* 0x048 */

    __IO uint32_t D1CCIPR;         /* 0x04C */
    __IO uint32_t D2CCIP1R;        /* 0x050 */
    __IO uint32_t D2CCIP2R;        /* 0x054 */
    __IO uint32_t D3CCIPR;         /* 0x058 */

    uint32_t RESERVED3;            /* 0x05C */

    __IO uint32_t CIER;            /* 0x060 */
    __IO uint32_t CIFR;            /* 0x064 */
    __IO uint32_t CICR;            /* 0x068 */

    uint32_t RESERVED4;            /* 0x06C */

    __IO uint32_t BDCR;            /* 0x070 */
    __IO uint32_t CSR;             /* 0x074 */

    uint32_t RESERVED5;            /* 0x078 */

    __IO uint32_t AHB3RSTR;        /* 0x07C */
    __IO uint32_t AHB1RSTR;        /* 0x080 */
    __IO uint32_t AHB2RSTR;        /* 0x084 */
    __IO uint32_t AHB4RSTR;        /* 0x088 */

    __IO uint32_t APB3RSTR;        /* 0x08C */
    __IO uint32_t APB1LRSTR;       /* 0x090 */
    __IO uint32_t APB1HRSTR;       /* 0x094 */
    __IO uint32_t APB2RSTR;        /* 0x098 */
    __IO uint32_t APB4RSTR;        /* 0x09C */

    __IO uint32_t GCR;             /* 0x0A0 */

    uint32_t RESERVED6;            /* 0x0A4 */

    __IO uint32_t D3AMR;           /* 0x0A8 */

    uint32_t RESERVED7[9];         /* 0x0AC - 0x0CC */

    __IO uint32_t RSR;             /* 0x0D0 */

    __IO uint32_t AHB3ENR;         /* 0x0D4 */
    __IO uint32_t AHB1ENR;         /* 0x0D8 */
    __IO uint32_t AHB2ENR;         /* 0x0DC */
    __IO uint32_t AHB4ENR;         /* 0x0E0 */

    __IO uint32_t APB3ENR;         /* 0x0E4 */
    __IO uint32_t APB1LENR;        /* 0x0E8 */
    __IO uint32_t APB1HENR;        /* 0x0EC */
    __IO uint32_t APB2ENR;         /* 0x0F0 */
    __IO uint32_t APB4ENR;         /* 0x0F4 */

    uint32_t RESERVED8;            /* 0x0F8 */

    __IO uint32_t AHB3LPENR;       /* 0x0FC */
    __IO uint32_t AHB1LPENR;       /* 0x100 */
    __IO uint32_t AHB2LPENR;       /* 0x104 */
    __IO uint32_t AHB4LPENR;       /* 0x108 */

    __IO uint32_t APB3LPENR;       /* 0x10C */
    __IO uint32_t APB1LLPENR;      /* 0x110 */
    __IO uint32_t APB1HLPENR;      /* 0x114 */
    __IO uint32_t APB2LPENR;       /* 0x118 */
    __IO uint32_t APB4LPENR;       /* 0x11C */

    uint32_t RESERVED9[5];         /* 0x120 - 0x130 */

    __IO uint32_t C1_AHB3ENR;      /* 0x134 */
    __IO uint32_t C1_AHB1ENR;      /* 0x138 */
    __IO uint32_t C1_AHB2ENR;      /* 0x13C */
    __IO uint32_t C1_AHB4ENR;      /* 0x140 */

    __IO uint32_t C1_APB3ENR;      /* 0x144 */
    __IO uint32_t C1_APB1LENR;     /* 0x148 */
    __IO uint32_t C1_APB1HENR;     /* 0x14C */
    __IO uint32_t C1_APB2ENR;      /* 0x150 */
    __IO uint32_t C1_APB4ENR;      /* 0x154 */

    uint32_t RESERVED10;           /* 0x158 */

    __IO uint32_t C1_AHB3LPENR;    /* 0x15C */
    __IO uint32_t C1_AHB1LPENR;    /* 0x160 */
    __IO uint32_t C1_AHB2LPENR;    /* 0x164 */
    __IO uint32_t C1_AHB4LPENR;    /* 0x168 */

    __IO uint32_t C1_APB3LPENR;    /* 0x16C */
    __IO uint32_t C1_APB1LLPENR;   /* 0x170 */
    __IO uint32_t C1_APB1HLPENR;   /* 0x174 */
    __IO uint32_t C1_APB2LPENR;    /* 0x178 */
    __IO uint32_t C1_APB4LPENR;    /* 0x17C */

} RCC_TypeDef;

typedef struct{
	uint32_t PLLState; /*New state of PLL*/
	uint32_t PLLSource; /*PLL entry Clock Source*/
	uint32_t PLLM; /*PLLM Division factor for PLL VCO*/
	uint32_t PLLN; /*PLLN Multiplication factor for PLL VCO*/
	uint32_t PLLP; /*PLLP Division factor for main system clock*/
	uint32_t PLLQ; /*PLLQ Division factor for peripheral clocks*/
	uint32_t PLLR; /*PLLR Division factor for peripheral clocks*/
	uint32_t PLLRGE;
	uint32_t PLLVCOSEL;
	uint32_t PLLFRACN;

}RCC_PLLInitTypeDef;

typedef struct{
	uint32_t OscillatorType; /*Which Oscillator to be configured*/
	uint32_t HSEState; /*The new state of HSE*/
	uint32_t HSIState; /*The new state of HSI*/
	uint32_t CSIState; /*The new state of CSI*/
	uint32_t LSEState; /*The new state of LSE*/
	uint32_t LSIState; /*The new state of LSI*/
	RCC_PLLInitTypeDef PLL; /*PLL Parameters*/
}RCC_OscInitTypeDef;

typedef struct{
	uint32_t ClockType;	/*Clock to be Configured*/
	uint32_t SYSCLKSource;	/*The Clock source used as system clock*/
	uint32_t SYSCLKDivider;	/*D1CPRE Divider*/
	uint32_t AHBCLKDivider;	/*AHB Clock Divider (HCLK)*/
	uint32_t APB3CLKDivider;	/*APB3 Clock Divider (PCLK3)*/
	uint32_t APB1CLKDivider;	/*APB1 Clock Divider (PCLK1)*/
	uint32_t APB2CLKDivider;	/*APB2 Clock Divider (PCLK2)*/
	uint32_t APB4CLKDivider;	/*APB4 Clock Divider (PCLK4)*/
}RCC_ClkInitTypeDef;

typedef struct{

	uint32_t PLL2M;

	uint32_t PLL2N;

	uint32_t PLL2P;

	uint32_t PLL2Q;

	uint32_t PLL2R;

	uint32_t PLL2RGE;

	uint32_t PLL2VCOSEL;

	uint32_t PLL2FRACN;

}RCC_PLL2InitTypeDef;

typedef struct{

	uint32_t PLL3M;

	uint32_t PLL3N;

	uint32_t PLL3P;

	uint32_t PLL3Q;

	uint32_t PLL3R;

	uint32_t PLL3RGE;

	uint32_t PLL3VCOSEL;

	uint32_t PLL3FRACN;

}RCC_PLL3InitTypeDef;

typedef struct{
	uint64_t PeripheralClockSel;

	RCC_PLL2InitTypeDef PLL2;

	RCC_PLL3InitTypeDef PLL3;

	uint32_t I2c123ClockSelection;

}RCC_PeripgCLKInitTypeDef;


#define RCC     ((RCC_TypeDef*) RCC_BASE)

#define GPIOAEN				(1U << 0)
#define GPIOBEN				(1U << 1)
#define GPIOCEN				(1U << 2)
#define GPIODEN				(1U << 3)
#define GPIOEEN				(1U << 4)
#define GPIOFEN				(1U << 5)
#define GPIOGEN				(1U << 6)
#define GPIOHEN				(1U << 7)
#define GPIOIEN				(1U << 8)

#define SYSCFG_EN  			(1UL << 1U)
#define USART1_EN  			(1UL << 4U)
#define LTDC_EN  			(1UL << 3U)
#define I2C1_EN  			(1UL << 21U)
#define I2C2_EN  			(1UL << 22U)
#define I2C3_EN  			(1UL << 23U)
#define I2C4_EN  			(1UL << 7U)

#define RCC_CR_HSION			(1U << 0U)
#define RCC_CR_HSIRDY			(1U << 2U)
#define RCC_CR_CSION			(1U << 7U)
#define RCC_CR_CSIRDY			(1U << 8U)
#define RCC_CR_HSEON			(1U << 16U)
#define RCC_CR_HSERDY			(1U << 17U)
#define RCC_CR_HSEBYP			(1U << 18U)
#define RCC_CR_PLL1ON			(1U << 24U)
#define RCC_CR_PLL1RDY			(1U << 25U)

#define RCC_BDCR_LSEON			(1U << 0U)
#define RCC_BDCR_LSERDY			(1U << 1U)

#define RCC_CSR_LSION			(1U << 0U)
#define RCC_CSR_LSIRDY			(1U << 1U)

#define RCC_PLLCKSELR_PLLSRC	(0x03U)
#define RCC_PLLCKSELR_DIVM1		(0x3FU << 4U)

#define RCC_PLLCFGR_PLL1VCOSEL	(1U << 1U)
#define RCC_PLLCFGR_PLL1RGE		(0x03U << 2U)
#define RCC_PLLCFGR_DIVP1EN		(1U << 16U)
#define RCC_PLLCFGR_DIVQ1EN		(1U << 17U)
#define RCC_PLLCFGR_DIVR1EN		(1U << 18U)
#define RCC_PLLCFGR_PLL1FRACEN	(1U << 24U)

#define FLASH_ACR_LATENCY		(0x07U << 0U)
#define FLASH_LATENCY_4			(0x04U << 0U)

#define RCC_CFGR_SW_Msk			(0x03U)
#define RCC_CFGR_SWS_Msk		(0x03U << 3U)

#define RCC_D1CFGR_HPRE_Msk		(0x0FU)
#define RCC_D1CFGR_D1PPRE_Msk	(0x07U << 4U)
#define RCC_D1CFGR_D1CPRE_Msk	(0x0FU << 8U)

#define RCC_D2CFGR_D2PPRE1_Msk	(0x07U << 4U)
#define RCC_D2CFGR_D2PPRE2_Msk	(0x07U << 8U)

#define RCC_D3CFGR_D3PPRE_Msk	(0x07U << 4U)

#define AHB1_EN					(0x00U)
#define AHB2_EN					(0x01U)
#define AHB3_EN					(0x02U)
#define AHB4_EN					(0x03U)
#define APB1L_EN				(0x04U)
#define APB1H_EN				(0x05U)
#define APB2_EN					(0x06U)
#define APB3_EN					(0x07U)
#define APB4_EN					(0x08U)

#define	HSE_OFF					(0x00U)
#define	HSE_ON					(0x01U)
#define	HSE_BYP					(0x02U)

#define	HSI_OFF					(0x00U)
#define	HSI_ON					(0x01U)

#define	CSI_OFF					(0x00U)
#define	CSI_ON					(0x01U)

#define	LSE_OFF					(0x00U)
#define	LSE_ON					(0x01U)

#define	LSI_OFF					(0x00U)
#define	LSI_ON					(0x01U)

#define PLL_NONE				(0x00U)
#define PLL_ON					(0x01U)

#define RCC_PLL_HSI_SRC			(0x00U)
#define RCC_PLL_CSI_SRC			(0x01U)
#define RCC_PLL_HSE_SRC			(0x02U)
#define RCC_PLL_NONE_SRC		(0x03U)

#define HSE_TIMEOUT				5000U
#define HSI_TIMEOUT				10U
#define	CSI_TIMEOUT				10U
#define	LSE_TIMEOUT				5000U
#define LSI_TIMEOUT				10U
#define PLL_TIMEOUT				1000U
#define CLOCKSWITCH_TIMEOUT		5000U

#define CSI_FREQ				4000000U

#define RCC_OSC_TYPE_NONE		(0x00U)
#define RCC_OSC_TYPE_HSE		(0x01U)
#define RCC_OSC_TYPE_HSI		(0x02U)
#define RCC_OSC_TYPE_CSI		(0x04U)
#define RCC_OSC_TYPE_LSE		(0x08U)
#define RCC_OSC_TYPE_LSI		(0x10U)

#define RCC_CLOCKTYPE_SYSCLK	(0x01U)
#define RCC_CLOCKTYPE_HCLK		(0x02U)
#define RCC_CLOCKTYPE_PCLK1		(0x04U)
#define RCC_CLOCKTYPE_PCLK2		(0x08U)
#define RCC_CLOCKTYPE_D3PCLK1	(0x10U)
#define RCC_CLOCKTYPE_D1PCLK1	(0x20U)

#define RCC_SYSCLOCKSOURCE_HSI		(0x00U)
#define RCC_SYSCLOCKSOURCE_CSI		(0x01U)
#define RCC_SYSCLOCKSOURCE_HSE		(0x02U)
#define RCC_SYSCLOCKSOURCE_PLLCLK	(0x03U)

#define RCC_PLL1VCIRANGE_0			(0x00U)
#define RCC_PLL1VCIRANGE_1			(0x01U << 2U)
#define RCC_PLL1VCIRANGE_2			(0x02U << 2U)
#define RCC_PLL1VCIRANGE_3			(0x03U << 2U)

#define RCC_PLL3VCIRANGE_0			(0x00U << 10U)
#define RCC_PLL3VCIRANGE_1			(0x01U << 10U)
#define RCC_PLL3VCIRANGE_2			(0x02U << 10U)
#define RCC_PLL3VCIRANGE_3			(0x03U << 10U)

#define RCC_PLL1VCOWIDE				(0x00U)
#define RCC_PLL1VCOMEDIUM			(0x01U << 1U)

#define RCC_PLL3VCOWIDE				(0x00U)
#define RCC_PLL3VCOMEDIUM			(0x01U << 9U)

#define RCC_SYSCLK_DIV1				(0x00U << 8U)
#define RCC_SYSCLK_DIV2				(0x08U << 8U)
#define RCC_SYSCLK_DIV4				(0x09U << 8U)
#define RCC_SYSCLK_DIV8				(0x0AU << 8U)
#define RCC_SYSCLK_DIV16			(0x0BU << 8U)
#define RCC_SYSCLK_DIV64			(0x0CU << 8U)
#define RCC_SYSCLK_DIV128			(0x0DU << 8U)
#define RCC_SYSCLK_DIV256			(0x0EU << 8U)
#define RCC_SYSCLK_DIV512			(0x0FU << 8U)

#define RCC_HCLK_DIV1				(0x00U << 0U)
#define RCC_HCLK_DIV2				(0x08U << 0U)
#define RCC_HCLK_DIV4				(0x09U << 0U)
#define RCC_HCLK_DIV8				(0x0AU << 0U)
#define RCC_HCLK_DIV16				(0x0BU << 0U)
#define RCC_HCLK_DIV64				(0x0CU << 0U)
#define RCC_HCLK_DIV128				(0x0DU << 0U)
#define RCC_HCLK_DIV256				(0x0EU << 0U)
#define RCC_HCLK_DIV512				(0x0FU << 0U)

#define RCC_APB3_DIV1				(0x00U << 4U)
#define RCC_APB3_DIV2				(0x04U << 4U)
#define RCC_APB3_DIV4				(0x05U << 4U)
#define RCC_APB3_DIV8				(0x06U << 4U)
#define RCC_APB3_DIV16				(0x07U << 4U)

#define RCC_APB1_DIV1				(0x00U << 4U)
#define RCC_APB1_DIV2				(0x04U << 4U)
#define RCC_APB1_DIV4				(0x05U << 4U)
#define RCC_APB1_DIV8				(0x06U << 4U)
#define RCC_APB1_DIV16				(0x07U << 4U)

#define RCC_APB2_DIV1				(0x00U << 8U)
#define RCC_APB2_DIV2				(0x04U << 8U)
#define RCC_APB2_DIV4				(0x05U << 8U)
#define RCC_APB2_DIV8				(0x06U << 8U)
#define RCC_APB2_DIV16				(0x07U << 8U)

#define RCC_APB4_DIV1				(0x00U << 4U)
#define RCC_APB4_DIV2				(0x04U << 4U)
#define RCC_APB4_DIV4				(0x05U << 4U)
#define RCC_APB4_DIV8				(0x06U << 4U)
#define RCC_APB4_DIV16				(0x07U << 4U)

#define APB4_SYSCFG_EN				(0x01U)

#define DIVIDER_P_UPDATE			(0x00U)
#define DIVIDER_Q_UPDATE			(0x01U)
#define DIVIDER_R_UPDATE			(0x02U)

#define RCC_PLLSOURCE_HSI			(0x00U)
#define RCC_PLLSOURCE_CSI			(0x01U)
#define RCC_PLLSOURCE_HSE			(0x02U)
#define RCC_PLLSOURCE_NONE			(0x03U)

#define RCC_PLL3_ON					(0x01UL << 28U)

#define RCC_I2C123CLKSOURCE_D2PCLK1	0x0000UL

#define RCC_PERIPHCLK_LTDC			(0x00002000UL)
#define RCC_PERIPHCLK_I2C123			(0x00000008UL)

void RCC_Enable(uint32_t pheripheral, uint8_t bus);
void RCC_Disable(uint32_t pheripheral, uint8_t bus);

Status_TypeDef RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
Status_TypeDef RCC_ClkConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t Flash_Latency);

Status_TypeDef RCCEx_PeripheralCLKConfig(RCC_PeripgCLKInitTypeDef *PeriphClkInit);

Status_TypeDef RCC_PLL3_Config(RCC_PLL3InitTypeDef *pll3, uint32_t divider);

void __RCC_PLL3_CONFIG(uint32_t pll3m, uint32_t pll3n,uint32_t pll3p,uint32_t pll3q,uint32_t pll3r);

uint32_t RCC_GetSYSCLK_Freq(void);
uint32_t RCC_GetHCLK_Freq(void);
uint32_t RCC_GetP1CLK_Freq(void);
uint32_t RCC_GetP2CLK_Freq(void);
uint32_t RCC_GetP3CLK_Freq(void);
uint32_t RCC_GetP4CLK_Freq(void);
float __RCC_GetLTDC_CLKFreq(void);

void __RCC_GPIOA_CLK_ENABLE(void);
void __RCC_GPIOB_CLK_ENABLE(void);
void __RCC_GPIOC_CLK_ENABLE(void);
void __RCC_GPIOD_CLK_ENABLE(void);
void __RCC_GPIOE_CLK_ENABLE(void);
void __RCC_GPIOF_CLK_ENABLE(void);
void __RCC_GPIOG_CLK_ENABLE(void);
void __RCC_GPIOH_CLK_ENABLE(void);
void __RCC_GPIOI_CLK_ENABLE(void);
void __RCC_SYSCFG_CLK_ENABLE(void);
void __RCC_USART1_CLK_ENABLE(void);
void __RCC_LTDC_CLK_ENABLE(void);
void __RCC_I2C1_CLK_ENABLE(void);
void __RCC_I2C2_CLK_ENABLE(void);
void __RCC_I2C3_CLK_ENABLE(void);
void __RCC_I2C4_CLK_ENABLE(void);

uint32_t __RCC_GET_PLL_OSCSOURCE(void);
void __RCC_PLL3_DISABLE(void);
void __RCC_PLL3_ENABLE(void);



#endif /* RCC_H_ */
