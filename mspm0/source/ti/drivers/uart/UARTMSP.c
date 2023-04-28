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

#include "ti/drivers/uart/UARTMSP.h"
#include "ti/drivers/dpl/HwiP.h"

static bool UARTMSP_enable(UART_Handle handle, UART_Params *params);
static void UARTMSP_disable(UART_Handle handle);
static void UARTMSP_txChar(UART_Handle handle);

const UARTSupport_Fxns UARTMSPSupportFxns = {
    .enable  = UARTMSP_enable,
    .disable = UARTMSP_disable,
    .txChar  = UARTMSP_txChar,
    .read    = UART_readFullFeatured,
    .write   = UART_writeFullFeatured,
};

/* Default UART parameters structure */
const UART_Params UART_defaultParams = {
    UART_Mode_BLOCKING,
    UART_Mode_BLOCKING,
    NULL,
    NULL,
    NULL,
    0,
    UART_ReadReturnMode_PARTIAL,
    9600,
    UART_DataLen_8,
    UART_StopBits_1,
    UART_Parity_NONE,
    NULL,
};

/*
 * ======== UARTMSP_hwAttrs ========
 */
static inline UARTMSP_HWAttrs *UARTMSP_hwAttrs(UART_Handle handle)
{
    /* UART_Handle is a UART_Object typecast to a (void*). This cast is only
     * possible because the first member of UARTMSP_HWAttrs is the UART_object.
     */
    return (UARTMSP_HWAttrs *) handle;
}

/*
 * ======== UARTMSP_enable ========
 */
static bool UARTMSP_enable(UART_Handle handle, UART_Params *params)
{
    uint32_t divratio = 0;
    uint32_t uartClk  = 0;
    uint32_t clkFreq   = 0;
    UARTMSP_HWAttrs *hwAttrs           = UARTMSP_hwAttrs(handle);
    UART_Object *object                = &hwAttrs->object;
    UART_Buffers_Object *buffersObject = &hwAttrs->buffersObject;
    UART_Callback_Object *callbackObj = &hwAttrs->callbackObject;

    if ((params->readMode == UART_Mode_CALLBACK) || (params->writeMode == UART_Mode_CALLBACK))
    {        
        if(params->readMode == UART_Mode_CALLBACK)
        {
            callbackObj->readCallback = params->readCallback;
        }
        if(params->writeMode == UART_Mode_CALLBACK)
        {
            callbackObj->writeCallback = params->writeCallback;
        }
    }

    if (object->buffersSupported == true) {
        UARTSupport_initBuffers(buffersObject);
    }

    DL_GPIO_initPeripheralOutputFunction(
        hwAttrs->txPin, hwAttrs->txPinFunction);
    DL_GPIO_initPeripheralInputFunction(
        hwAttrs->rxPin, hwAttrs->rxPinFunction);

    // Reset and enable power to UART instance
    DL_UART_reset(hwAttrs->regs);
    DL_UART_enablePower(hwAttrs->regs);

    DL_UART_ClockConfig clockConfig = {
        .clockSel    = hwAttrs->clockSource,
        .divideRatio = hwAttrs->clockDivider,
    };
    DL_UART_setClockConfig(hwAttrs->regs, &clockConfig);

    switch (clockConfig.clockSel)
    {
        case DL_UART_CLOCK_BUSCLK:
            uartClk = 32000000;  //32Mhz
            break;
        case DL_UART_CLOCK_MFCLK:
            uartClk = 4000000;  //4Mhz
            break;
        case DL_UART_CLOCK_LFCLK:
            uartClk = 32000;  //32Khz
            break;
    }

    divratio = clockConfig.divideRatio + 1;
    //roundup the integer division using the equation x/y = (x+(y-1))/y
    clkFreq = (uint32_t)((uartClk + (divratio - 1)) / divratio);

    DL_UART_Main_Config config = 
    {
        .mode        = hwAttrs->mode,
        .direction   = hwAttrs->direction,
        .flowControl = hwAttrs->flowControl,
        .parity      = (DL_UART_PARITY) params->parityType,
        .wordLength  = (DL_UART_WORD_LENGTH) params->dataLength,
        .stopBits    = (DL_UART_STOP_BITS) params->stopBits,
    };
    DL_UART_init(hwAttrs->regs, &config);
    DL_UART_configBaudRate(hwAttrs->regs, clkFreq , params->baudRate);
    DL_UART_enableFIFOs(hwAttrs->regs);
    DL_UART_setRXFIFOThreshold(hwAttrs->regs, hwAttrs->rxIntFifoThr);
    DL_UART_setTXFIFOThreshold(hwAttrs->regs, hwAttrs->txIntFifoThr);
    DL_UART_enableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_RX);
    HwiP_enableInterrupt(hwAttrs->irq);  // NVIC_EnableIRQ
    DL_UART_enable(hwAttrs->regs);

    return true;
}

/*
 * ======== UARTMSP_disable ========
 */
static void UARTMSP_disable(UART_Handle handle)
{
    UARTMSP_HWAttrs *hwAttrs = UARTMSP_hwAttrs(handle);

    HwiP_disableInterrupt(hwAttrs->irq);
    DL_UART_disableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_RX |
                                                DL_UART_INTERRUPT_TX |
                                                DL_UART_INTERRUPT_EOT_DONE);
    DL_UART_disable(hwAttrs->regs);
    return;
}

/*
 * ======== UARTMSP_txChar ========
 */
static void UARTMSP_txChar(UART_Handle handle)
{
    UARTMSP_HWAttrs *hwAttrs           = UARTMSP_hwAttrs(handle);
    
    /* enable transmit interrupts */
    DL_UART_enableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_TX);
}
/*
* =============UARTMSP_TxCallback============
* This function should be called from ISR
*/
void UARTMSP_TxCallback(UARTMSP_HWAttrs *hwAttrs)
{
    UART_Buffers_Object *buffersObject = &hwAttrs->buffersObject;
    UART_Callback_Object *callbackObj = &hwAttrs->callbackObject;

    do 
    {
        uint8_t txData;
        txData = *(callbackObj->writeBuf + callbackObj->bytesWritten);
        if (callbackObj->writeSize == callbackObj->bytesWritten) 
        {
            /* no more data left to transmit, disable TX interrupt, enable
                * end of transmission interrupt for low power support.
                */
            DL_UART_disableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_TX);
            DL_UART_enableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_EOT_DONE);
            SemaphoreBinaryP_postFromISR(&buffersObject->txSem);
            break;
        }
        /* pulled a byte of data out, prime the transmitter */
        DL_UART_transmitData(hwAttrs->regs, txData);
        callbackObj->bytesWritten++;
        
    } while (DL_UART_isTXFIFOFull(hwAttrs->regs) == false); 
        
}
/*
 * ======== UARTMSP_interruptHandler ========
 */
void UARTMSP_interruptHandler(UARTMSP_HWAttrs *hwAttrs)
{
    UART_Buffers_Object *buffersObject = &hwAttrs->buffersObject;
    UART_Callback_Object *callbackObj  = &hwAttrs->callbackObject;
    static uint16_t count = 0;
    

    DL_UART_IIDX status = DL_UART_getPendingInterrupt(hwAttrs->regs);
    bool rxPost         = false;
    bool txPost         = false;

    // receive characters as long as we can
    while (DL_UART_isRXFIFOEmpty(hwAttrs->regs) == false) 
    {
        /* data in the RX FIFO, pull it out of the hardware */
        uint8_t rxData;
        rxData = DL_UART_receiveData(hwAttrs->regs);
        /* try to push the data into the software RX buffer */
        if (RingBuf_put(&buffersObject->rxBuf, rxData) == -1) 
        {
            /* no space left in RX buffer, overrun */
        }

        if (callbackObj->readCallback != NULL)
        {
            //get the data from ring buffer to the application provided buffer
            count += RingBuf_getn(&buffersObject->rxBuf, callbackObj->readBuf + count, callbackObj->readSize - count);
            if(callbackObj->readSize == count)
            {
                rxPost = true; //release the semaphore
                count = 0; //reset the counter
                callbackObj->readInUse = false;
                callbackObj->readCallback(&hwAttrs->object,callbackObj->readBuf, callbackObj->readSize,NULL, 0);
            }
        }
        //if not in the callback mode then post sema 
        else
        {
            rxPost = true;
        }
    }
    /* transmit a character if we have pending TX data*/
    if (status == DL_UART_IIDX_TX) 
    {
        if (callbackObj->writeCallback != NULL)
        {
            UARTMSP_TxCallback(hwAttrs);
        }
        else
        {
            /* because we had an active interrupt flag, we should always have
            * room for at least one byte of transmit data
            */
            do 
            {
                uint8_t txData;
                if (RingBuf_get(&buffersObject->txBuf, &txData) == -1) 
                {
                    /* no more data left to transmit, disable TX interrupt, enable
                    * end of transmission interrupt for low power support.
                    */
                    DL_UART_disableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_TX);
                    DL_UART_enableInterrupt(
                        hwAttrs->regs, DL_UART_INTERRUPT_EOT_DONE);
                    break;
                }
                /* pulled a byte of data out, prime the transmitter */
                DL_UART_transmitData(hwAttrs->regs, txData);
                txPost = true;
            } while (DL_UART_isTXFIFOFull(hwAttrs->regs) == false);
        }
    } 
    else if (status == DL_UART_IIDX_EOT_DONE) 
    {
        /* transmission complete, disable interrupt and remove low power
         * inhibit
         */
        DL_UART_disableInterrupt(hwAttrs->regs, DL_UART_INTERRUPT_EOT_DONE);
    }

    if (rxPost) 
    {
        SemaphoreBinaryP_postFromISR(&buffersObject->rxSem);
    }
    if (txPost) 
    {
        SemaphoreBinaryP_postFromISR(&buffersObject->txSem);
    }
}
