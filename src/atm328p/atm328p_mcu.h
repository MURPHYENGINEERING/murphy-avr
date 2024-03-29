#ifndef __ATM328P_MCU_H__
#define __ATM328P_MCU_H__

#include "types.h"


typedef union {
    struct {
        VBOOL_T PORF        : 1;
        VBOOL_T EXTRF       : 1;
        VBOOL_T BORF        : 1;
        VBOOL_T WDRF        : 1;
        VBOOL_T Reserved4   : 1;
        VBOOL_T Reserved5   : 1;
        VBOOL_T Reserved6   : 1;
        VBOOL_T Reserved7   : 1;
    } bits;
    VU8_T byte;
} MCUSR_T;

extern volatile MCUSR_T MCUSR;

#define WDRF_WATCHDOG_RESET_DISABLED FALSE


/** Power Reduction Register */
typedef union {
    struct {
        /** Power Reduction ADC */
        VBOOL_T PRADC : 1;
        /** Power Reduction USART0 */
        VBOOL_T PRUSART0 : 1;
        /** Power Reduction Serial Peripheral Interface */
        VBOOL_T PRSPI : 1;
        /** Power Reduction Timer/Counter 1 */
        VBOOL_T PRTIM1 : 1;
        VBOOL_T Reserved4 : 1;
        /** Power Reduction Timer/Counter 0 */
        VBOOL_T PRTIM0 : 1;
        /** Power Reduction Timer/Counter 2 */
        VBOOL_T PRTIM2 : 1;
        VBOOL_T PRTWI : 1;
    } bits;
    VU8_T byte;
} PRR_T;
/** Power Reduction Register */
extern volatile PRR_T PRR;

/** Disable power reduction for the ADC. */
#define PRADC_ENABLE_ADC FALSE
/** Enable power reduction for the ADC. */
#define PRADC_DISABLE_ADC TRUE

/** Disable power reduction for the SPI device. */
#define PRSPI_ENABLE_SPI FALSE
/** Enable power reduction for the SPI device. */
#define PRSPI_DISABLE_SPI TRUE

/** Disable power reduction for the USART0 device. */
#define PRUSART0_ENABLE_USART FALSE
/** Enable power reduction for the USART0 device. */
#define PRUSART0_DISABLE_USART TRUE

/** Disable power reduction for the Timer/Counter 1 device. */
#define PRTIM1_ENABLE_TIMER FALSE
/** Enable power reduction for the Timer/Counter 1 device. */
#define PRTIM1_DISABLE_TIMER TRUE

/** Disable power reduction for the Timer/Counter 0 device. */
#define PRTIM0_ENABLE_TIMER FALSE
/** Enable power reduction for the Timer/Counter 0 device. */
#define PRTIM0_DISABLE_TIMER TRUE

#endif