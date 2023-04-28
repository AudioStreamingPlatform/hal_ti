/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ti_drivers_uart_UART__include
#define ti_drivers_uart_UART__include

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_uart_main.h"

/** @addtogroup UART_STATUS
 *  @{
 */
/*!
 * @brief   Successful status code returned by UART APIs.
 */
#define UART_STATUS_SUCCESS (0)

/*!
 * @brief  A  read timeout occurred (not an error).
 */
#define UART_STATUS_SREADTIMEOUT (1)

/*!
 * @brief  A framing error occurred.
 */
#define UART_STATUS_EFRAMING (-1)

/*!
 * @brief  A parity error occurred.
 */
#define UART_STATUS_EPARITY (-2)

/*!
 * @brief  A break error occurred.
 */
#define UART_STATUS_EBREAK (-4)

/*!
 * @brief  A FIFO overrun occurred.
 */
#define UART_STATUS_EOVERRUN (-8)

/*!
 * @brief  The UART is currently in use.
 */
#define UART_STATUS_EINUSE (-9)

/*!
 * @brief  An invalid argument or UART_Params field was passed to UART API.
 */
#define UART_STATUS_EINVALID (-10)

/*!
 * @brief  General failure status returned by UART API.
 */
#define UART_STATUS_EFAIL (-11)

/*!
 * @brief  A memory allocation failure occurred.
 */
#define UART_STATUS_EMEMORY (-12)

/*!
 * @brief  A timeout occurred for a blocking UART_read or UART_write call.
 */
#define UART_STATUS_ETIMEOUT (-13)

/*!
 * @brief  A UART_write() or UART_read() operation was cancelled.
 */
#define UART_STATUS_ECANCELLED (-14)

/*!
 * @brief  A UART_write() or UART_read() called on a device not opened.
 */
#define UART_STATUS_ENOTOPEN (-15)

/*!
 * @brief  A UART_write() or UART_read() in UART_Mode_NONBLOCKING would
 *         have blocked.
 */
#define UART_STATUS_EAGAIN (-16)

/** @}*/

/*!
 *  @brief      A handle that is returned from a UART_open() call.
 */
typedef void *UART_Handle;

/*!
 *  @brief      The definition of a callback function used by the UART driver
 *              when used in #UART_Mode_CALLBACK
 *              The callback can occur in task or interrupt context.
 *
 *  @param[in]  UART_Handle             UART_Handle
 *
 *  @param[in]  buf                     Pointer to read/write buffer
 *
 *  @param[in]  count                   Number of elements read/written
 *
 *  @param[in]  userArg                 A user supplied argument specified
 *                                      in UART_Params.
 *
 *  @param[in]  status                  A UART_STATUS code indicating
 *                                      success or failure of the transfer.
 */
typedef void (*UART_Callback)(UART_Handle handle, void *buf, size_t count,
    void *userArg, int_fast16_t status);

/*!
 *  @brief      The definition of a callback function used by the UART driver.
 *              The callback can occur in task or interrupt context.
 *
 *  @param[in]  UART_Handle             UART_Handle
 *
 *  @param[in]  event                   UART_EVENT that has occurred.
 *
 *  @param[in]  data                    - UART_EVENT_OVERRUN: accumulated count
 *                                      - UART_EVENT_BREAK: unused
 *                                      - UART_EVENT_PARITY: unused
 *                                      - UART_EVENT_FRAMING: unused
 *                                      - UART_EVENT_TX_BEGIN: unused
 *                                      - UART_EVENT_TX_FINISHED: unused
 *
 *  @param[in]  userArg                 A user supplied argument specified
 *                                      in UART_Params.
 *
 *  @param[in]  status                  A UART_STATUS code indicating
 *                                      success or failure of the transfer.
 */
typedef void (*UART_EventCallback)(
    UART_Handle handle, uint32_t event, uint32_t data, void *userArg);

/*!
 *  @brief      UART mode settings
 *
 *  This enum defines the read and write modes for the configured UART.
 */
typedef enum {
    /*!
      *  UART_write() will block the calling task until all of the data can be
      *  accepted by the device driver. UART_read() will block until some data
      *  becomes available.
      */
    UART_Mode_BLOCKING = 0,

    /*!
      *  Non-blocking, UART_write() or UART_read() will return immediately.
      *  When the transfer has finished, the callback function is called
      *  from either the caller's context or from an interrupt context.
      */
    UART_Mode_CALLBACK,

    /*!
      *  Non-blocking, UART_write() or UART_read() will return immediately.
      *  UART_write() will copy as much data into the transmit buffer as space
      *  allows. UART_read() will copy as much data from the receive buffer
      *  as is immediately available.
      */
    UART_Mode_NONBLOCKING,
} UART_Mode;

/*!
 *  @brief      UART return mode settings
 *
 *  This enumeration defines the return modes for UART_read().
 *
 *  #UART_ReadReturnMode_FULL unblocks or performs a callback when the read
 *  buffer has been filled with the number of bytes passed to #UART_read().
 *  #UART_ReadReturnMode_PARTIAL unblocks or performs a callback whenever a
 *  read timeout error occurs on the UART peripheral.  This timeout
 *  error is not the same as the blocking read timeout in the UART_Params;
 *  the read timeout occurs if the read FIFO is non-empty and no new
 *  data has been received for a device/baudrate dependent number of
 *  clock cycles.  This mode can be used when the exact number of bytes to
 *  be read is not known.
 */
typedef enum {
    /*! Unblock/callback when buffer is full. */
    UART_ReadReturnMode_FULL = 0,

    /*! Unblock/callback when no new data comes in. */
    UART_ReadReturnMode_PARTIAL
} UART_ReadReturnMode;

/*!
 *  @brief    UART data length settings
 *
 *  This enumeration defines the UART data lengths.
 */
typedef enum {
    UART_DataLen_5 = DL_UART_WORD_LENGTH_5_BITS, /*!< Data length is 5 bits */
    UART_DataLen_6 = DL_UART_WORD_LENGTH_6_BITS, /*!< Data length is 6 bits */
    UART_DataLen_7 = DL_UART_WORD_LENGTH_7_BITS, /*!< Data length is 7 bits */
    UART_DataLen_8 = DL_UART_WORD_LENGTH_8_BITS  /*!< Data length is 8 bits */
} UART_DataLen;

/*!
 *  @brief    UART stop bit settings
 *
 *  This enumeration defines the UART stop bits.
 */
typedef enum {
    UART_StopBits_1 = DL_UART_STOP_BITS_ONE, /*!< One stop bit */
    UART_StopBits_2 = DL_UART_STOP_BITS_TWO  /*!< Two stop bits */
} UART_StopBits;

/*!
 *  @brief    UART parity type settings
 *
 *  This enumeration defines the UART parity types.
 */
typedef enum {
    UART_Parity_NONE = DL_UART_PARITY_NONE, /*!< No parity */
    UART_Parity_EVEN = DL_UART_PARITY_EVEN, /*!< Parity bit is even */
    UART_Parity_ODD  = DL_UART_PARITY_ODD,  /*!< Parity bit is odd */
    UART_Parity_ZERO =
        DL_UART_PARITY_STICK_ZERO, /*!< Parity bit is always zero */
    UART_Parity_ONE = DL_UART_PARITY_STICK_ONE /*!< Parity bit is always one */
} UART_Parity;

/*!
 *  @brief    UART Parameters
 *
 *  UART parameters are used with the UART_open() call. Default values for
 *  these parameters are set using UART_Params_init().
 *
 *  @sa       UART_Params_init()
 */
typedef struct {
    UART_Mode readMode;  /*!< Mode for all read calls */
    UART_Mode writeMode; /*!< Mode for all write calls */
    /*! Pointer to read callback function for callback mode. */
    UART_Callback readCallback;
    /*! Pointer to write callback function for callback mode. */
    UART_Callback writeCallback;
    /*! Pointer to event callback function. */
    UART_EventCallback eventCallback;
    /*! mask of events that the application is interested in */
    uint32_t eventMask;
    UART_ReadReturnMode readReturnMode; /*!< Receive return mode */
    uint32_t baudRate;                  /*!< Baud rate for UART */
    UART_DataLen dataLength;            /*!< Data length for UART */
    UART_StopBits stopBits;             /*!< Stop bits for UART */
    UART_Parity parityType;             /*!< Parity bit type for UART */
    void *userArg; /*!< User supplied argument for callback functions */
} UART_Params;

void UART_Params_init(UART_Params *params);
UART_Handle UART_open(uint_least8_t index, UART_Params *params);
void UART_close(UART_Handle);
int_fast16_t UART_read(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead);
int_fast16_t UART_write(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);
int_fast16_t UART_readTimeout(UART_Handle handle, void *buf, size_t size,
    size_t *bytesRead, uint32_t timeout);
int_fast16_t UART_writeTimeout(UART_Handle handle, const void *buf,
    size_t size, size_t *bytesWritten, uint32_t timeout);
void UART_readCancel(UART_Handle handle);
void UART_writeCancel(UART_Handle handle);
void UART_rxDisable(UART_Handle handle);
void UART_rxEnable(UART_Handle handle);
void UART_flushRx(UART_Handle handle);
void UART_getRxCount(UART_Handle handle);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ti_drivers_uart_UART__include */
