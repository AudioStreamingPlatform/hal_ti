/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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
/*
 *  ======== HwiPMSPM0_nortos.c ========
 */

#include <stdbool.h>
#include <stdio.h>

#include <ti/devices/msp/msp.h>

int HwiP_swiPIntNum = PendSV_VECn;

/*
 *  ======== HwiP_enable ========
 */
void HwiP_enable(void)
{
    __enable_irq();
}

/*
 *  ======== HwiP_disable ========
 */
uintptr_t HwiP_disable(void)
{
    uint32_t status;
    status = __get_PRIMASK();
    __disable_irq();
    return status;
}

/*
 *  ======== HwiP_restore ========
 */
void HwiP_restore(uintptr_t alreadyDisabled)
{
    if (!alreadyDisabled) {
        __enable_irq();
    }
}

/*
 *  ======== HwiP_post ========
 */
void HwiP_post(int interruptNum)
{
    NVIC_SetPendingIRQ((IRQn_Type) interruptNum);
}

/*
 *  ======== HwiP_clearInterrupt ========
 */
void HwiP_clearInterrupt(int interruptNum)
{
    NVIC_ClearPendingIRQ((IRQn_Type) interruptNum);
}

/*
 * ======== HwiP_setPri ========
 */
void HwiP_setPriority(int interruptNum, uint32_t priority)
{
    NVIC_SetPriority((IRQn_Type) interruptNum, priority);
}

/*
 *  ======== HwiP_disableInterrupt ========
 */
void HwiP_disableInterrupt(int interruptNum)
{
    NVIC_DisableIRQ((IRQn_Type) interruptNum);
}

/*
 *  ======== HwiP_enableInterrupt ========
 */
void HwiP_enableInterrupt(int interruptNum)
{
    NVIC_EnableIRQ((IRQn_Type) interruptNum);
}

/*
 *  ======== HwiP_interruptsEnabled ========
 */
bool HwiP_interruptsEnabled(void)
{
    uint32_t priMask;

    priMask = __get_PRIMASK();

    return (priMask == 0);
}

/*
 *  ======== HwiP_inISR ========
 */
bool HwiP_inISR(void)
{
    bool stat;

    if (__get_IPSR() == 0) {
        /* IPSR value of 0 indicates we are in thread mode, not handling an
           interrupt */
        stat = false;
    } else {
        stat = true;
    }

    return stat;
}

/*
 *  ======== HwiP_inSwi ========
 */
bool HwiP_inSwi(void)
{
    bool stat;

    if (__get_IPSR() == HwiP_swiPIntNum) {
        stat = true;
    } else {
        stat = false;
    }

    return stat;
}
