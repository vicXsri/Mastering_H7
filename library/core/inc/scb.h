/*
 * scb.h
 *
 *  Created on: Aug 16, 2026
 *      Author: Srivisweswara Mohan Santhi
 */

#ifndef CORE_INC_SCB_H_
#define CORE_INC_SCB_H_

#include "main.h"

typedef struct
{
    __I  uint32_t CPUID;          /* 0x000: CPUID Base Register */
    __IO uint32_t ICSR;           /* 0x004: Interrupt Control and State Register */
    __IO uint32_t VTOR;           /* 0x008: Vector Table Offset Register */
    __IO uint32_t AIRCR;          /* 0x00C: Application Interrupt and Reset Control Register */
    __IO uint32_t SCR;            /* 0x010: System Control Register */
    __IO uint32_t CCR;            /* 0x014: Configuration and Control Register */

    __IO uint32_t SHPR1;          /* 0x018: System Handler Priority Register 1 */
    __IO uint32_t SHPR2;          /* 0x01C: System Handler Priority Register 2 */
    __IO uint32_t SHPR3;          /* 0x020: System Handler Priority Register 3 */

    __IO uint32_t SHCSR;          /* 0x024: System Handler Control and State Register */
    __IO uint32_t CFSR;           /* 0x028: Configurable Fault Status Register */
    __IO uint32_t HFSR;           /* 0x02C: HardFault Status Register */
    __IO uint32_t DFSR;           /* 0x030: Debug Fault Status Register */
    __IO uint32_t MMFAR;          /* 0x034: MemManage Fault Address Register */
    __IO uint32_t BFAR;           /* 0x038: BusFault Address Register */
    __IO uint32_t AFSR;           /* 0x03C: Auxiliary Fault Status Register */

         uint32_t RESERVED0[18]; /* 0x040 - 0x084 */

    __IO uint32_t CPACR;          /* 0x088: Coprocessor Access Control Register */

         uint32_t RESERVED1;     /* 0x08C */

} SCB_TypeDef;

#define	SCB					((SCB_TypeDef *) SCB_BASE)

#endif /* CORE_INC_SCB_H_ */
