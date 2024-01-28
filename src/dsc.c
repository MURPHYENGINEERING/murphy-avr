#include "dsc.h"


void dsc_init(void)
{
    dsc_led_mode(DSC_LED_CANBOARD_1, DSC_LED_ENABLED);
    dsc_led_mode(DSC_LED_CANBOARD_2, DSC_LED_ENABLED);
    dsc_led_set(DSC_LED_CANBOARD_1, DSC_LED_OFF);
    dsc_led_set(DSC_LED_CANBOARD_2, DSC_LED_OFF);
}


void dsc_led_mode(DSC_LED_T led, DSC_LED_MODE_T mode) {
    if (DSC_LED_ENABLED == mode) {
        switch (led) {
            case DSC_LED_BUILTIN:
                DDR_BUILTIN.bits.LED = DDR_OUTPUT;
            break;

            case DSC_LED_CANBOARD_1:
                DDR_CANBOARD.bits.LED1 = DDR_OUTPUT;
            break;

            case DSC_LED_CANBOARD_2:
                DDR_CANBOARD.bits.LED2 = DDR_OUTPUT;
            break;

            default:
            /* Software error */
            break;
        }
    } else {
        switch (led) {
            case DSC_LED_BUILTIN:
                DDR_BUILTIN.bits.LED = DDR_INPUT;
            break;

            case DSC_LED_CANBOARD_1:
                DDR_CANBOARD.bits.LED1 = DDR_INPUT;
            break;

            case DSC_LED_CANBOARD_2:
                DDR_CANBOARD.bits.LED2 = DDR_INPUT;
            break;

            default:
            /* Software error */
            break;
        }
    }
}


void dsc_led_toggle(DSC_LED_T led)
{
    if (DSC_LED_CANBOARD_1 == led) {
        PORT_CANBOARD.bits.LED1 = !PORT_CANBOARD.bits.LED1;
    } else if (DSC_LED_CANBOARD_2 == led) {
        PORT_CANBOARD.bits.LED2 = !PORT_CANBOARD.bits.LED2;
    } else if (DSC_LED_BUILTIN == led) {
        PORT_BUILTIN.bits.LED = !PORT_BUILTIN.bits.LED;
    }
}


void dsc_led_set(DSC_LED_T led, DSC_LED_STATE_T state)
{
    if (DSC_LED_OFF == state) {
        switch (led) {
            case DSC_LED_BUILTIN:
                PORT_BUILTIN.bits.LED = LOW;
            break;

            case DSC_LED_CANBOARD_1:
                PORT_CANBOARD.bits.LED1 = LOW;
            break;

            case DSC_LED_CANBOARD_2:
                PORT_CANBOARD.bits.LED2 = LOW;
            break;

            default:
            /* Software error */
            break;
        }
    } else {
        switch (led) {
            case DSC_LED_BUILTIN:
                PORT_BUILTIN.bits.LED = HIGH;
            break;

            case DSC_LED_CANBOARD_1:
                PORT_CANBOARD.bits.LED1 = HIGH;
            break;

            case DSC_LED_CANBOARD_2:
                PORT_CANBOARD.bits.LED2 = HIGH;
            break;

            default:
            /* Software error */
            break;
        }
    }
}