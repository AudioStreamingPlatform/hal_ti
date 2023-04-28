/*
 * Copyright (c) 2017-2020, Texas Instruments Incorporated
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
/*!****************************************************************************
 *  @file       WatchdogMSP.h
 *
 *  @brief      Watchdog driver NoRTOS implementation for MSP
 *
 *  The Watchdog header file for MSP should be included in an application
 *  as follows:
 *  @code
 *  #include <ti/drivers/Watchdog_nortos.h>
 *  #include <ti/drivers/watchdog/WatchdogMSP_nortos.h>
 *  @endcode
 *
 *  Refer to @ref Watchdog_nortos.h for a complete description of APIs.
 *
 *  ## Overview #
 *  This Watchdog driver implementation is designed to operate on a MSP
 *  device. Once opened, MSP Watchdog will count down from the reload
 *  value specified in the WatchdogMSP_HWAttrs. If it times out, the
 *  Watchdog interrupt flag will be set, and a user-provided callback function
 *  will be called. If resets have been enabled in the #Watchdog_Params and
 *  the Watchdog Timer is allowed to timeout again while the interrupt flag is
 *  still pending, a reset signal will be generated. To prevent a reset,
 *  Watchdog_clear() must be called to clear the interrupt flag.
 *
 *  @warning The watchdog peripheral does not support a Non-Maskable Interrupt (NMI).
 *
 *  Watchdog_close() is <b>not</b> supported by this driver implementation.
 *
 *  By default the Watchdog driver has resets turned on. However, they may be
 *  turned off in the #Watchdog_Params which allows the Watchdog Timer to be
 *  used like another timer interrupt.
 *
 *  To have a user-defined function run at the warning interrupt, first define
 *  a void-type function that takes a Watchdog_Handle cast to a uintptr_t as an
 *  argument such as the one shown below.
 *
 *  Watchdog_init() and Watchdog_close() do not need to be called in the MSP
 *  implementation, empty APIs are provided for compatibility.
 *
 *  @code
 *  void callback(uintptr_t handle);
 *
 *  Watchdog_Handle handle;
 *  Watchdog_Params params;
 *
 *  Watchdog_Params_init(&params);
 *  params.callbackFxn = callback;
 *  handle = Watchdog_open(CONFIG_WATCHDOG0, &params);
 *  @endcode
 ******************************************************************************
 */
#ifndef ti_drivers_watchdog_WatchdogMSP_nortos__include
#define ti_drivers_watchdog_WatchdogMSP_nortos__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/devices/msp/peripherals/hw_wwdt.h>
#include <ti/driverlib/dl_wwdt.h>
#include <ti/drivers/Watchdog.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 *  @brief  Command code used by Watchdog_control() to change active window
 *
 *  This command is used to change which window is currently actively in the
 *  hardware. With this command code, @b arg is a pointer to an uint32_t to
 *  choose the new active window. The value should be DL_WWDT_WINDOW0 or
 *  DL_WWDT_WINDOW1 found in dl/dl_wwdt.h */
#define WatchdogMSP_CMD_CHANGEWINDOW                                        (0)

/* clang-format on */

/*!
 *  @brief  Watchdog hardware attributes for MSP
 *
 *  Watchdog hardware attributes for the WatchdogMSP driver's
 *  specific hardware configurations and interrupt priority settings.
 *
 *  The fields: divider, sleepMode, window0ClosedPeriod, window1ClosedPeriod,
 *  period and initialWindow are used by DL APIs and therefore must be
 *  populated by DL macro definitions. These definitions are found under the
 *  device family in dl/dl_wwdt.h.
 *
 *  The window periods are used to specific the percentage of the total period
 *  that should cause a reset if the WWDT is restarted in that window.
 *
 *  A sample structure is shown below:
 *  @code
 *  const WatchdogMSP_HWAttrs watchdogMSPHWAttrs[] =
 *  {
 *      {
 *          .baseAddr = WWDT0,
 *          TODO: Update once we have interrupt definitions
 *          .intNum = INT_WATCHDOG,
 *          .intPriority = ~0,
 *          .period = DL_WWDT_TIMER_PERIOD_25_BITS,
 *          .divider = DL_WWDT_CLOCK_DIVIDE_BY_15,
 *          .sleepMode = DL_WWDT_RUN_IN_SLEEP,
 *          .window0ClosedPeriod = DL_WWDT_WINDOW_PERIOD_0,
 *          .window1ClosedPeriod = DL_WWDT_WINDOW_PERIOD_50,
 *          .initialWindow = DL_WWDT_WINDOW0,
 *      },
 *  };
 *  @endcode
 */
typedef struct {
    WWDT_Regs *wwdt;              /*!< Base address for Watchdog */
    IRQn_Type intNum;             /*!< WDT interrupt number */
    uint32_t intPriority;         /*!< WDT interrupt priority */
    DL_WWDT_TIMER_PERIOD period;  /*!< Period of timer */
    DL_WWDT_CLOCK_DIVIDE divider; /*!< Clock divider */
    DL_WWDT_SLEEP_MODE sleepMode; /*!< Enable/disable the timer in sleep mode*/
    DL_WWDT_WINDOW_PERIOD
    window0ClosedPeriod; /*!< Window 0 period percentage */
    DL_WWDT_WINDOW_PERIOD
    window1ClosedPeriod;          /*!< Window 1 period percentage */
    DL_WWDT_WINDOW initialWindow; /*!< Initial window */
} WatchdogMSP_HWAttrs;

/*!
 *  @brief  Watchdog Object for MSP
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct {
    bool isOpen; /* Flag for open/close status */
    Watchdog_Callback
        callbackFxn; /* Callback function when Watchdog expires */
} WatchdogMSP_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_watchdog_WatchdogMSP__include */
