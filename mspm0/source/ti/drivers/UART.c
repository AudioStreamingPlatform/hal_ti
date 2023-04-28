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

#include "ti/drivers/dpl/HwiP.h"
#include "ti/drivers/uart/UARTMSP.h"

extern const UART_Config UART_config[];
extern const uint_least8_t UART_count;
extern const UART_Params UART_defaultParams;

/*
 * ======== UART_buffersObject ========
 */
static inline UART_Buffers_Object *UART_buffersObject(UART_Object *object)
{
    return (UART_Buffers_Object *) (object + 1);
}

/*
 * ======== UART_eventCallbackObject ========
 */
static inline UART_EventCallback_Object *UART_eventCallbackObject(
    UART_Object *object)
{    
    return (UART_EventCallback_Object *) (UART_buffersObject(object) + 1);
    
}

/*
 * ======== UART_callbackObject ========
 */
static inline UART_Callback_Object *UART_callbackObject(UART_Object *object)
{
    return (UART_Callback_Object *) (UART_eventCallbackObject(object) + 1);    
}

/*
 * ======== UART_readBufferedMode ========
 */
static int_fast16_t UART_readBufferedMode(UART_Object *object, void *buf,
    size_t size, size_t *bytesRead, uint8_t mode)
{
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    uint8_t *data                      = (uint8_t *) (buf);
    uint_fast16_t count                = 0;
    int_fast16_t result                = UART_STATUS_SUCCESS;
    uintptr_t key;

    key                = HwiP_disable();
    object->readCancel = false;
    HwiP_restore(key);

    while (size - count) 
    {
        // todo: need to handle case where there was remaining data in RingBuf
        SemaphoreBinaryP_pendNoTimeout(&buffersObject->rxSem);
        if (object->readCancel) {
            result = UART_STATUS_ECANCELLED;
            break;
        }
        count += RingBuf_getn(&buffersObject->rxBuf, ((uint8_t *) data) + count, size - count);
        if (mode == UART_Mode_NONBLOCKING) 
        {
            if (count == 0) 
            {
                result = UART_STATUS_EAGAIN;
            }
            break;
        }
    }

    if (bytesRead) {
        *bytesRead = count;
    }

    return result;
}

/*
 * ======== UART_writeBufferedMode ========
 */
static int_fast16_t UART_writeBufferedMode(UART_Object *object,
    const void *buf, size_t size, size_t *bytesWritten, uint8_t mode)
{
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    const uint8_t *data                = (const uint8_t *) (buf);
    uint_fast16_t count                = 0;
    int_fast16_t result                = UART_STATUS_SUCCESS;
    uintptr_t key;

    key                 = HwiP_disable();
    object->writeCancel = false;
    HwiP_restore(key);

    while (size - count) {
        count += RingBuf_putn(
            &buffersObject->txBuf, ((uint8_t *) data) + count, size - count);
        if (mode == UART_Mode_NONBLOCKING) {
            if (count == 0) {
                result = UART_STATUS_EAGAIN;
            }
            break;
        }
        object->supportFxns->txChar(object);
        SemaphoreBinaryP_pendNoTimeout(&buffersObject->txSem);
        if (object->writeCancel) {
            result = UART_STATUS_ECANCELLED;
            break;
        }
    }

    if (bytesWritten) {
        *bytesWritten = count;
    }

    return result;
}

/*
 * ======== UART_readBuffered ========
 */
int_fast16_t UART_readBuffered(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = (UART_Object *) handle;

    return UART_readBufferedMode(
        object, buf, size, bytesRead, object->readMode);
}

/*
 * ======== UART_writeBuffered ========
 */
int_fast16_t UART_writeBuffered(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = (UART_Object *) handle;

    return UART_writeBufferedMode(
        object, buf, size, bytesWritten, object->writeMode);
}

/*
 * ======== UART_readCallback ========
 */
int_fast16_t UART_readCallback(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{    
    UART_Object *object                  = (UART_Object *) handle;
    UART_Callback_Object *callbackObj = UART_callbackObject(object);

    uintptr_t key;

    key = HwiP_disable();
    if (callbackObj->readInUse)
    {
        HwiP_restore(key);
        return UART_STATUS_EINUSE;
    }
    callbackObj->readInUse = true;
    callbackObj->bytesRead = 0;
    callbackObj->readBuf   = buf;
    callbackObj->readSize  = size;
    HwiP_restore(key);

    return UART_STATUS_SUCCESS;
}

/*
 * ======== UART_writeCallback ========
 */
int_fast16_t UART_writeCallback(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object                = (UART_Object *) handle;
    UART_Callback_Object *callbackObj = UART_callbackObject(object);

    uintptr_t key;

    key = HwiP_disable();
    if (callbackObj->writeInUse) {
        HwiP_restore(key);
        return UART_STATUS_EINUSE;
    }
    callbackObj->writeInUse   = true;
    callbackObj->bytesWritten = 0;
    callbackObj->writeBuf     = buf;
    callbackObj->writeSize    = size;
    object->supportFxns->txChar(object);
    HwiP_restore(key);

    return UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readFullFeatured ========
 */
int_fast16_t UART_readFullFeatured(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = (UART_Object *) handle;

    if (object->buffersSupported && object->readMode != UART_Mode_CALLBACK) {
        return UART_readBuffered(handle, buf, size, bytesRead);
    }
    if (object->callbacksSupported && object->readMode == UART_Mode_CALLBACK) {
        return UART_readCallback(handle, buf, size, bytesRead);
    }
    return UART_STATUS_EINVALID;
}

/*
 * ======== UART_writeFullFeatured ========
 */
int_fast16_t UART_writeFullFeatured(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = (UART_Object *) handle;

    if (object->buffersSupported && object->writeMode != UART_Mode_CALLBACK) {
        return UART_writeBuffered(handle, buf, size, bytesWritten);
    }
    if (object->callbacksSupported &&
        object->writeMode == UART_Mode_CALLBACK) {
        return UART_writeCallback(handle, buf, size, bytesWritten);
    }
    return UART_STATUS_EINVALID;
}

/*
 * ======== UART_Params_init ========
 */
void UART_Params_init(UART_Params *params)
{
    *params = UART_defaultParams;
}

/*
 * ======== UART_open ========
 */
UART_Handle UART_open(uint_least8_t index, UART_Params *params)
{
    /*! @todo the HwiP_disable is unnecessary for no-rtos mode. A task level
     *       lock would also be adequate here.
     */

    if (index < UART_count) 
    {
        UART_Object *object = UART_config[index];
        uintptr_t key       = HwiP_disable();
        if (!object->inUse) 
        {
            /* not already open */
            object->inUse = true;
            HwiP_restore(key);

            if (object->supportFxns->enable(object, params)) 
            {
                /* enable successful */
                object->returnMode = params->readMode;
                object->readMode   = params->readMode;
                object->writeMode  = params->writeMode;

                return UART_config[index];
            }
            key           = HwiP_disable();
            object->inUse = false;
            HwiP_restore(key);
        } 
        else 
        {
            /* already open */
            HwiP_restore(key);
        }
    }

    return NULL;
}

/*
 * ======== UART_close ========
 */
void UART_close(UART_Handle handle)
{
    UART_Object *object = (UART_Object *) handle;
    uintptr_t key;

    //    Do we need to cancel ongoing read/write?
    //    UART_readCancel(handle);
    key = HwiP_disable();

    object->inUse = false;
    HwiP_restore(key);

    object->supportFxns->disable(object);

    return;
}

/*
 * ======== UART_read ========
 */
int_fast16_t UART_read(
    UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = (UART_Object *) handle;
    int_fast16_t result;

    result = object->supportFxns->read(handle, buf, size, bytesRead);
    if (bytesRead) {
        *bytesRead = result < 0 ? 0 : *bytesRead;
    }

    return result < 0 ? result : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_write ========
 */
int_fast16_t UART_write(
    UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = (UART_Object *) handle;
    int_fast16_t result;

    result = object->supportFxns->write(handle, buf, size, bytesWritten);
    if (bytesWritten) {
        *bytesWritten = result < 0 ? 0 : *bytesWritten;
    }

    return result < 0 ? result : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readTimeout ========
 */
int_fast16_t UART_readTimeout(UART_Handle handle, void *buf, size_t size,
    size_t *bytesRead, uint32_t timeout)
{
    UART_Object *object                = (UART_Object *) handle;
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    uint8_t *data                      = (uint8_t *) (buf);
    int_fast16_t count                 = 0;
    int_fast16_t result;
    int_fast16_t needed;

    if (object->readMode == UART_Mode_CALLBACK) {
        return UART_STATUS_EINVALID;
    }

    needed = object->returnMode == UART_ReadReturnMode_FULL ? size : 1;

    while (1) {
        result = UART_readBufferedMode(
            object, data, size, bytesRead, UART_Mode_NONBLOCKING);
        if (result > 0) {
            count += result;
            size -= result;
            data += result;
        }
        if (count >= needed) {
            break;
        }
        /** @todo this results in timeout drift over time, need a more
         *        full featured clock module to resolve this
         */
        if (SemaphoreBinaryP_TIMEOUT ==
            SemaphoreBinaryP_pend(&buffersObject->rxSem, timeout)) {
            break;
        }
    }
    if (bytesRead) {
        *bytesRead = count;
    }

    return (count < size) ? UART_STATUS_ETIMEOUT : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_writeTimeout ========
 */
int_fast16_t UART_writeTimeout(UART_Handle handle, const void *buf,
    size_t size, size_t *bytesWritten, uint32_t timeout)
{
    UART_Object *object                = (UART_Object *) handle;
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    const uint8_t *data                = (const uint8_t *) (buf);
    int_fast16_t count                 = 0;
    int_fast16_t result;

    if (object->readMode == UART_Mode_CALLBACK) {
        return UART_STATUS_EINVALID;
    }

    while (1) {
        result = UART_writeBufferedMode(
            object, data, size, bytesWritten, UART_Mode_NONBLOCKING);
        if (result > 0) {
            count += result;
            size -= result;
            data += result;
        }
        if (count >= size) {
            break;
        }
        /** @todo this results in timeout drift over time, need a more
         *        full featured clock module to resolve this
         */
        if (SemaphoreBinaryP_TIMEOUT ==
            SemaphoreBinaryP_pend(&buffersObject->txSem, timeout)) {
            break;
        }
    }
    if (bytesWritten) {
        *bytesWritten = count;
    }

    return (count < size) ? UART_STATUS_ETIMEOUT : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readCancel ========
 */
void UART_readCancel(UART_Handle handle)
{
    UART_Object *object = (UART_Object *) handle;
    uintptr_t key;

    key = HwiP_disable();

    if (object->readMode == UART_Mode_CALLBACK) {
        UART_Callback_Object *callbackObject = UART_callbackObject(object);

        if (callbackObject->readInUse) {
            uint8_t *readBuf   = callbackObject->readBuf;
            uint16_t readSize  = callbackObject->readSize;
            uint16_t bytesRead = callbackObject->bytesRead;

            /* We need to clear the in use flag so that the callback can setup
             * another read transaction.
             */
            callbackObject->readInUse = false;

            callbackObject->readCallback(handle, readBuf, bytesRead,
                object->userArg,
                readSize != bytesRead ? UART_STATUS_ECANCELLED
                                      : UART_STATUS_SUCCESS);
        }
        HwiP_restore(key);
    } else {
        UART_Buffers_Object *buffersObject = UART_buffersObject(object);
        object->readCancel                 = true;

        HwiP_restore(key);
        SemaphoreBinaryP_post(&buffersObject->rxSem);
    }
}
