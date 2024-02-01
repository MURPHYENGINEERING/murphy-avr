#include "types.h"
#include "demo.h"
#include "fifo.h"
#include "can.h"
#include "memory.h"
#include "string.h"
#include "dsc.h"
#include "fai.h"
#include "usart.h"


/*******************************************************************************
 *
 ******************************************************************************/ 
void task_demo_tx(void)
{
    U8_T buf[CAN_FIFO_DATA_LEN];
    SIZE_T len;
    FIFO_STATUS_T status;
    CAN_IDENT_T identifier;

    identifier = (U16_T) 0xDEADBEEFu;

    memcpy_by_U8(buf, (U8_T*) "Hello!", (SIZE_T) 6);
    len = strnlen_by_U8((U8_T*) "Hello!", CAN_FIFO_DATA_LEN);

    status = can_tx_q_add(identifier, buf, len);

    if (FIFO_OK == status) {
        usart_tx((U8_T*) "Hello, world!\n", 14);
    } else {
        fai_pass_fail_logger(
            FAI_FAULT_ID_CAN_TX_BUFFER_OVERFLOW, 
            FAIL, 
            (U32_T) identifier
        );
    }

    /*
    len = usart_rx(buf, 14);
    if (0 < len) {
        usart_tx(buf, len);
    }
    */
}


/*******************************************************************************
 *
 ******************************************************************************/ 
void task_demo_rx(void)
{
    SIZE_T n_pending_msgs;
    SIZE_T i;
    FIFO_STATUS_T status;
    U8_T buf[CAN_FIFO_DATA_LEN];
    SIZE_T len;
    CAN_IDENT_T identifier;

    n_pending_msgs = can_rx_q_len();

    for (i = 0; i < n_pending_msgs; ++i) {
        status = can_rx_q_remove(&identifier, buf, &len);

        if (FIFO_OK == status) {
            /* TODO: What do we do with received messages? */

        } else {
            fai_pass_fail_logger(FAI_FAULT_ID_SW_ERROR, FAIL, get_pc());
        }
    }
}