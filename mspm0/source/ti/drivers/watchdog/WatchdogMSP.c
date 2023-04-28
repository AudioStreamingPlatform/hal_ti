/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
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
 *  ======== WatchdogMSP.c ========
 */

#include <stdbool.h>

#ifdef DRIVERS_NORTOS
#include <ti/drivers/Watchdog_nortos.h>
#include <ti/drivers/watchdog/WatchdogMSP_nortos.h>
#else
#include <ti/drivers/Watchdog.h>
#include <ti/drivers/watchdog/WatchdogMSP.h>
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_wwdt.h>
#include <ti/drivers/dpl/HwiP.h>

/* Default Watchdog parameters structure */
const Watchdog_Params Watchdog_defaultParams = {
    NULL,                    /* callbackFxn */
    Watchdog_RESET_ON,       /* resetMode */
    Watchdog_DEBUG_STALL_ON, /* debugStallMode */
    NULL                     /* custom */
};

extern const Watchdog_Config Watchdog_config[];
extern const uint_least8_t Watchdog_count;

/*
 *  ======== Watchdog_clear ========
 */
void Watchdog_clear(Watchdog_Handle handle)
{
    WatchdogMSP_HWAttrs const *hwAttrs = handle->hwAttrs;
    DL_WWDT_restart(hwAttrs->wwdt);
}

/*
 *  ======== Watchdog_close ========
 */
void Watchdog_close(Watchdog_Handle handle)
{
    /* Not needed in MSP, nothing to close */
}

/*
 *  ======== Watchdog_init ========
 */
void Watchdog_init(void)
{
    /* Not needed in MSP, nothing to initialize */
}

/*
 *  ======== Watchdog_setReload ========
 */
int_fast16_t Watchdog_setReload(Watchdog_Handle handle, uint32_t ticks)
{
    /* Not supported for MSP, can only set reload value in open */
    return (Watchdog_STATUS_UNSUPPORTED);
}

/*
 *  ======== Watchdog_control ========
 */
int_fast16_t Watchdog_control(
    Watchdog_Handle handle, uint_fast16_t cmd, void *arg)
{
    WatchdogMSP_HWAttrs const *hwAttrs = handle->hwAttrs;
    DL_WWDT_WINDOW *window;

    switch (cmd) {
        case (WatchdogMSP_CMD_CHANGEWINDOW):
            window = arg;
            DL_WWDT_setActiveWindow(hwAttrs->wwdt, *window);
            return (Watchdog_STATUS_SUCCESS);
        default:
            return (Watchdog_STATUS_UNDEFINEDCMD);
    }
}

/*
 *  ======== Watchdog_open ========
 */
Watchdog_Handle Watchdog_open(uint_least8_t index, Watchdog_Params *params)
{
    uintptr_t key;
    Watchdog_Handle handle = NULL;

    if (index < Watchdog_count) {
        if (params == NULL) {
            params = (Watchdog_Params *) &Watchdog_defaultParams;
        }

        handle = (Watchdog_Handle) & (Watchdog_config[index]);
        WatchdogMSP_Object *object         = handle->object;
        WatchdogMSP_HWAttrs const *hwAttrs = handle->hwAttrs;

        key = HwiP_disable();

        /* Check if the Watchdog is open already with the HWAttrs */
        if (object->isOpen) {
            HwiP_restore(key);
            return (NULL);
        }
        object->isOpen = true;
        HwiP_restore(key);

        // TODO: Need to set up group interrupt here for WWDT?
        DL_WWDT_enableInterrupt(hwAttrs->wwdt);
        NVIC_EnableIRQ(hwAttrs->intNum);
        NVIC_SetPriority(hwAttrs->intNum, hwAttrs->intPriority);
        if (params->callbackFxn) {
            object->callbackFxn = params->callbackFxn;
        }

        DL_WWDT_setActiveWindow(hwAttrs->wwdt, hwAttrs->initialWindow);
        if (params->resetMode == Watchdog_RESET_ON) {
            DL_WWDT_initWatchdogMode(hwAttrs->wwdt, hwAttrs->divider,
                hwAttrs->period, hwAttrs->sleepMode,
                hwAttrs->window0ClosedPeriod, hwAttrs->window1ClosedPeriod);
        } else {
            DL_WWDT_initIntervalTimerMode(hwAttrs->wwdt, hwAttrs->divider,
                hwAttrs->period, hwAttrs->sleepMode);
        }
    }

    return handle;
}

/*
 *  ======== Watchdog_Params_init ========
 */
void Watchdog_Params_init(Watchdog_Params *params)
{
    *params = Watchdog_defaultParams;
}

/*
 *  ======== Watchdog_convertMsToTicks ========
 */
uint32_t Watchdog_convertMsToTicks(
    Watchdog_Handle handle, uint32_t milliseconds)
{
    // TODO: Not sure if we can implement this on M0
    return 0;
}

#ifdef DRIVERS_NORTOS
/*
 *  ======== Watchdog_processIRQ ========
 */
void Watchdog_processIRQ(Watchdog_Handle handle)
{
    WatchdogMSP_Object const *object   = handle->object;
    WatchdogMSP_HWAttrs const *hwAttrs = handle->hwAttrs;

    if (object->callbackFxn) {
        object->callbackFxn((uintptr_t) handle);
    }
    DL_WWDT_clearInterruptStatus(hwAttrs->wwdt);
}
#endif
