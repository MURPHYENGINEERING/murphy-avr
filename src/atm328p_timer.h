#ifndef __ATM328P_TIMER_H__
#define __ATM328P_TIMER_H__

#include "types.h"

/* Timer/Counter 0 Control Register A */
typedef union {
    struct {
        /* Waveform Generation Mode */
        VBOOL_T WGM00 : 1;
        VBOOL_T WGM01 : 1;
        VBOOL_T Reserved2 : 1;
        VBOOL_T Reserved3 : 1;
        /* Compare Match Output B Mode */ 
        VBOOL_T COM0B0 : 1;
        VBOOL_T COM0B1 : 1;
        /* Compare Match Output A Mode */ 
        VBOOL_T COM0A0 : 1;
        VBOOL_T COM0A1 : 1;
    } bits;
    VU8_T byte;
} TCCR0A_T;

extern volatile TCCR0A_T TCCR0A;

/* Timer/Counter 0 Control Register B */
typedef union {
    struct {
        /* Clock Select */
        /* 0, 0, 0 = no clock source 
         * 0, 0, 1 = clk / 1 (no prescaling)
         * 0, 1, 0 = clk / 8
         * 0, 1, 1 = clk / 64
         * 1, 0, 0 = clk / 256
         * 1, 0, 1 = clk / 1024
         * 1, 1, 0 = External clock source on T0, falling edge
         * 1, 1, 1 = External clock source on T0, rising edge */
        VBOOL_T CS00 : 1;
        VBOOL_T CS01 : 1;
        VBOOL_T CS02 : 1;
        /* Waveform Generation Mode */
        VBOOL_T WGM02 : 1;
        VBOOL_T Reserved4 : 1;
        VBOOL_T Reserved5 : 1;
        /* Force Output Compare B */
        VBOOL_T FOC0B : 1;
        /* Force Output Compare A */
        VBOOL_T FOC0A : 1;
    } bits;
    VU8_T byte;
} TCCR0B_T;

extern volatile TCCR0B_T TCCR0B;

/* Clock Select Bits */
#define TCCR0B_CS00 0
#define TCCR0B_CS01 1
#define TCCR0B_CS02 2

/* Timer/Counter 0 Register */
extern volatile REGISTER_T TCNT0;

/* Timer/Counter 0 Output Compare Register A */
extern volatile REGISTER_T OCR0A;
/* Timer/Counter 0 Output Compare Register B */
extern volatile REGISTER_T OCR0B;


/* Timer/Counter Interrupt Mask Register */
typedef union {
    struct {
        /* Timer/Counter 0 Overflow Interrupt Enable */
        VBOOL_T TOIE0 : 1;
        /* Timer/Counter 0 Output Compare Match A Interrupt Enable */
        VBOOL_T OCIE0A : 1;
        /* Timer/Counter 0 Output Compare Match B Interrupt Enable */
        VBOOL_T OCIE0B : 1;
        VBOOL_T Reserved3 : 1;
        VBOOL_T Reserved4 : 1;
        VBOOL_T Reserved5 : 1;
        VBOOL_T Reserved6 : 1;
        VBOOL_T Reserved7 : 1;
    } bits;
    VU8_T byte;
} TIMSK0_T;

extern volatile TIMSK0_T TIMSK0;

/* Timer/Counter 0 Interrupt Flag Register */
typedef union {
    struct {
        /* Timer/Counter 0 Overflow Flag */
        VBOOL_T TOV0 : 1;
        /* Timer/Counter 0 Output Compare A Match Flag */
        VBOOL_T OCF0A : 1;
        /* Timer/Counter 0 Output Compare B Match Flag */
        VBOOL_T OCF0B : 1;
        VBOOL_T Reserved3 : 1;
        VBOOL_T Reserved4 : 1;
        VBOOL_T Reserved5 : 1;
        VBOOL_T Reserved6 : 1;
        VBOOL_T Reserved7 : 1;
    } bits;
    VU8_T byte;
} TIFR0_T;

extern volatile TIFR0_T TIFR0;


/* Timer/Counter 1 Control Register A */
typedef union {
    struct {
        VBOOL_T Reserved0 : 1;
        VBOOL_T Reserved1 : 1;
        VBOOL_T Reserved2 : 1;
        VBOOL_T Reserved3 : 1;
        /* Compare Output Mode for Channel B */
        VBOOL_T COM1B0 : 1;
        VBOOL_T COM1B1 : 1;
        /* Compare Output Mode for Channel A */
        VBOOL_T COM1A0 : 1;
        VBOOL_T COM1A1 : 1;
    } bits;
    VU8_T byte;
} TCCR1A_T;

extern volatile TCCR1A_T TCCR1A;

#define TCCR1A_NORMAL_MODE (U8_T) 0


/* Timer/Counter 1 Control Register B */
typedef union {
    struct {
        /* Clock Select */
        /* 0, 0, 0 = no clock source 
         * 0, 0, 1 = clk/1 
         * 0, 1, 0 = clk/8
         * 0, 1, 1 = clk/64
         * 1, 0, 0 = clk/256
         * 1, 0, 1 = clk/1024 */
        VBOOL_T CS10 : 1;
        VBOOL_T CS11 : 1;
        VBOOL_T CS12 : 1;
        /* Waveform Generation Mode */
        VBOOL_T WGM12 : 1;
        VBOOL_T WGM13 : 1;
        VBOOL_T Reserved5 : 1;
        /* Input Capture Edge Select */
        VBOOL_T ICES1 : 1;
        /* Input Capture Noise Canceler */
        VBOOL_T ICNC1 : 1;
    } bits;
    VU8_T byte;
} TCCR1B_T;

extern volatile TCCR1B_T TCCR1B;

/* Clock select bit 2 */
#define TCCR1B_CS12 2
/* Set the Timer/Counter 1 Prescaler to clk/256 */
#define TCCR1B_PRESCALE_OVER_256 (U8_T) ( (1 << TCCR1B_CS12) )


/* Timer/Counter 1 */
extern volatile HALFWORD_T TCNT1;

/* Output Compare Register 1 A */
extern volatile HALFWORD_T OCR1A;

/* Output Compare Register 1 B */
extern volatile HALFWORD_T OCR1B;


/* Timer/Counter 1 Interrupt Mask Register */
typedef union {
    struct {
        /* Timer/Counter 1, Overflow Interrupt Enable */
        VBOOL_T TOIE1  : 1;
        /* Timer/Counter 1, Output Compare A Match Interrupt Enable */
        VBOOL_T OCIE1A : 1;
        /* Timer/Counter 1, Output Compare B Match Interrupt Enable */
        VBOOL_T OCIE1B : 1;
        VBOOL_T Reserved3 : 1;
        VBOOL_T Reserved4 : 1;
        VBOOL_T Reserved5 : 1;
        VBOOL_T Reserved6 : 1;
        VBOOL_T Reserved7 : 1;
    } bits;
    VU8_T byte;
} TIMSK1_T;

extern volatile TIMSK1_T TIMSK1;

#define TOIE1_ENABLE_INTERRUPT 1
#define OCIE1A_ENABLE_INTERRUPT 1


/* Timer/Counter 1 Interrupt Flag Register */
typedef union {
    struct {
        /* Timer/Counter 1, Overflow Flag */
        VBOOL_T TOV1 : 1;
        /* Timer/Counter 1, Output Compare A Match Flag */
        VBOOL_T OCF1A : 1;
        /* Timer/Counter 1, Output Compare B Match Flag */
        VBOOL_T OCF1B : 1;
        VBOOL_T Reserved3 : 1;
        VBOOL_T Reserved4 : 1;
        VBOOL_T Reserved5 : 1;
        VBOOL_T Reserved6 : 1;
        VBOOL_T Reserved7 : 1;
    } bits;
    VU8_T byte;
} TIFR1_T;

extern volatile TIFR1_T TIFR1;


#endif