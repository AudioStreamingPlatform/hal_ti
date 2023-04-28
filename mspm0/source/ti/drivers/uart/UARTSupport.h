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
/** ============================================================================
 *  @file       UART2Support.h
 *
 *  @brief      Holder of common helper functions for the UART driver
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTSupport__include
#define ti_drivers_uart_UARTSupport__include

#include <ti/drivers/UART.h>
#include <ti/drivers/dpl/SemaphoreBinaryP.h>
#include <ti/drivers/utils/RingBuf.h>

/*!
 *  @brief      Function pointers to implementation/hardware specific logic.
 */
typedef struct {
    /*!
     *  @brief      Enable the hardware, typically called during UART_open().
     *
     *  @param[in]  handle    UART_Handle instance from UART_open().
     *  @param[in]  params    Reference to the UART_Params struct passed in by
     *                        the user.
     *  @return Returns true on success, else false.
     */
    bool (*enable)(UART_Handle handle, UART_Params *params);

    /*!
     *  @brief      Disable the hardware, typically called during UART_close().
     *
     *  @param[in]  handle    UART_Handle instance from UART_open().
     */
    void (*disable)(UART_Handle handle);

    /*!
     *  @brief      Kick the transmitter in the hardware.
     *
     *  @param[in]  handle    UART_Handle instance from UART_open().
     */
    void (*txChar)(UART_Handle handle);

    /*!
     *  @brief      Read method to use.
     *
     *  @param[in]  handle    UART_Handle instance from UART_open().
     *  @param[out] buf       location to read data into.
     *  @param[in]  size      amount of data to read in bytes.
     *  @param[out] bytesRead If non-NULL, the location to store the number
     *                        of bytes actually read into the buffer. If NULL,
     *                        this parameter will be ignored. In callback mode,
     *                        NULL could be passed in for this parameter, since
     *                        the callback function will be passed the number of
     *                        bytes read.
     */
    int_fast16_t (*read)(
        UART_Handle, void *buf, size_t size, size_t *bytesRead);

    /*!
     *  @brief      Write method to use.
     *
     *  @param[in]  handle    UART_Handle instance from UART_open().
     *  @param[in]  buf       location to write data from.
     *  @param[in]  size      amount of data to write in bytes.
     *  @param[out] bytesWritten If non-NULL, the location to store the number
     *                        of bytes actually written into the buffer. If
     *                        NULL, this parameter will be ignored. In callback
     *                        mode, NULL could be passed in for this parameter,
     *                        since the callback function will be passed the
     *                        number of bytes written.
     */
    int_fast16_t (*write)(
        UART_Handle, const void *buf, size_t size, size_t *bytesWritten);
} UARTSupport_Fxns;

/*!
 *  @brief      Private Metadata structure for a UART instance.
 */
typedef struct {
    const UARTSupport_Fxns *supportFxns; /*!< implementation specific */
    void *userArg;                  /*!< User supplied argument for callback */
    uint8_t buffersSupported : 1;   /*!< RX/TX buffers supported */
    uint8_t eventsSupported : 1;    /*!< true if events are supported */
    uint8_t callbacksSupported : 1; /*!< true if callbacks are supported */
    uint8_t returnMode : 1;         /*!< @ref UART_ReadReturnMode */
    uint8_t inUse : 1;              /*!< true if driver already open */
    uint8_t readCancel : 1;         /*!< true if a read has been canceled */
    uint8_t writeCancel : 1;        /*!< true if a write has been canceled */
    uint8_t readMode : 2;           /*!< read @ref UART_Mode */
    uint8_t writeMode : 2;          /*!< write @ref UART_Mode */
} UART_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              buffers.
 */
typedef struct {
    uint8_t *rxBufPtr;             /*!< RX buffer memory address */
    uint8_t *txBufPtr;             /*!< TX buffer memory address */
    uint16_t rxBufSize;            /*!< RX buffer size in bytes */
    uint16_t txBufSize;            /*!< TX buffer size in bytes */
    RingBuf_Object rxBuf;          /*!< receive data buffer */
    RingBuf_Object txBuf;          /*!< transmit data buffer */
    SemaphoreBinaryP_Struct rxSem; /*!< receive semaphore */
    SemaphoreBinaryP_Struct txSem; /*!< transmit semaphore */
} UART_Buffers_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              events.
 */
typedef struct {
    UART_EventCallback eventCallback;
    uint32_t eventMask;
} UART_EventCallback_Object;

/*!
 *  @brief      Private Metadata structure for a UART instance supporting
 *              callbacks.
 */
typedef struct {
    UART_Callback readCallback;
    UART_Callback writeCallback;
    uint8_t *readBuf;
    const uint8_t *writeBuf;
    uint16_t readSize;
    uint16_t writeSize;
    uint16_t bytesRead;
    uint16_t bytesWritten;
    uint8_t readInUse : 1; /*!< @todo can this be combined with readCancel? */
    uint8_t writeInUse : 1;
} UART_Callback_Object;

typedef UART_Object *UART_Config;

/*!
 *  @brief      Initialization helper for buffer support.
 *
 *  @param[in]  object    reference to the buffer related metadata.
 */
static inline void UARTSupport_initBuffers(UART_Buffers_Object *object)
{
    RingBuf_construct(&object->rxBuf, object->rxBufPtr, object->rxBufSize);
    RingBuf_construct(&object->txBuf, object->txBufPtr, object->txBufSize);
    SemaphoreBinaryP_construct(&object->rxSem, 0);
    SemaphoreBinaryP_construct(&object->txSem, 0);
}

/*!
 *  @brief      Read method that only supports buffered mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored.
 */
int_fast16_t UART_readBuffered(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      Write that only supports buffered mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored.
 */
int_fast16_t UART_writeBuffered(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

/*!
 *  @brief      Read method that only supports callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored. In callback mode,
 *                        NULL could be passed in for this parameter, since
 *                        the callback function will be passed the number of
 *                        bytes read.
 */
int_fast16_t UART_readCallback(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      Write that only supports callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored. In callback
 *                        mode, NULL could be passed in for this parameter,
 *                        since the callback function will be passed the
 *                        number of bytes written.
 */
int_fast16_t UART_writeCallback(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

/*!
 *  @brief      Read method that only supports buffered and callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[out] buf       location to read data into.
 *  @param[in]  size      amount of data to read in bytes.
 *  @param[out] bytesRead If non-NULL, the location to store the number
 *                        of bytes actually read into the buffer. If NULL,
 *                        this parameter will be ignored. In callback mode,
 *                        NULL could be passed in for this parameter, since
 *                        the callback function will be passed the number of
 *                        bytes read.
 */
int_fast16_t UART_readFullFeatured(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead);

/*!
 *  @brief      Write that only supports buffered and callback mode.
 *
 *  @param[in]  handle    UART_Handle instance from UART_open().
 *  @param[in]  buf       location to write data from.
 *  @param[in]  size      amount of data to write in bytes.
 *  @param[out] bytesWritten If non-NULL, the location to store the number
 *                        of bytes actually written into the buffer. If
 *                        NULL, this parameter will be ignored. In callback
 *                        mode, NULL could be passed in for this parameter,
 *                        since the callback function will be passed the
 *                        number of bytes written.
 */
int_fast16_t UART_writeFullFeatured(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten);

#endif /* ti_drivers_uart_UARTSupport__include */
