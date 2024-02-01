#include "atm328p_eeprom.h"
#include "atm328p_interrupts.h"

#include "eeprom.h"


/*******************************************************************************
 * Write a single given byte to the EEPROM at the given address.
 * \param[in] address   The address to which the byte will be written.
 * \param[in] data      The byte to be written.
 ******************************************************************************/
void eeprom_write_byte(SIZE_T address, U8_T data)
{
    cli();
    /* Wait for previous write to complete */
    while (TRUE == EECR.bits.EEPE) {
    }

    /* Set erase-and-write mode */
    EECR.bits.EEPM0 = TRUE;
    EECR.bits.EEPM1 = TRUE;

    /* Set up write */
    EEAR.byte = (U8_T) address;
    EEDR.byte = data;

    /* Enable master write */
    EECR.bits.EEMPE = TRUE;
    /* Enable write */
    EECR.bits.EEPE = TRUE;
    sei();
}


/*******************************************************************************
 * Read a single byte from the EEPROM at the given address.
 * \param[in] address   The address from which the byte will be read.
 * \return The read byte.
 ******************************************************************************/
U8_T eeprom_read_byte(SIZE_T address)
{
    cli();
    /* Wait for previous write to complete */
    while (TRUE == EECR.bits.EEPE) {
    }

    /* Set up read */
    EEAR.byte = (U8_T) address;
    /* Enable read */
    EECR.bits.EERE = TRUE;

    sei();

    return EEDR.byte;
}


/*******************************************************************************
 * Erase the byte in EEPROM at the given address (setting its value to 0).
 * \param[in] address The address at which the byte will be erased.
 ******************************************************************************/
void eeprom_erase_byte(SIZE_T address)
{
    /* I don't like that erasing sets the value to 0xFF, so we write to 0
    instead. */
    eeprom_write_byte(address, (U8_T) 0);
}