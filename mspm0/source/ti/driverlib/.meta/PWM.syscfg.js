/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated - http://www.ti.com
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
 *
 */

/*
 *  ======== PWM.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for PWM instances */
let pwmConfig = []; /* nothing (yet) beyond generic driver configs */

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - PWM instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    Common.validateNames(inst, validation);
}

/*
 *  ======== _getPinResources ========
 */
/* istanbul ignore next */
function _getPinResources(inst)
{
    return;
}

/*
 *  ======== getLongDescription ========
 */
function getLongDescription()
{
    var deviceName;
    var tableString;
    /* Return string with table for correct device (default M0G) */
    if (Common.isDeviceM0L()) {
        deviceName = 'MSPM0L130x';
        tableString = `
| TIM Name | Power Domain | Resolution | Prescaler | CC Ch | Phase Load | Shadow Load | Shadow CC |
| :------: | :----------: | :--------: | :-------: | :----:| :--------: | :---------: | :-------: |
| TIMG0 | PD0 | 16-bit | 8-bit | 2 | - | - | - |
| TIMG1 | PD0 | 16-bit | 8-bit | 2 | - | - | - |
| TIMG2 | PD0 | 16-bit | 8-bit | 2 | - | - | - |
| TIMG4 | PD0 | 16-bit | 8-bit | 2 | - | Y | Y |
`
    } else {
        deviceName = 'MSPM0G350x';
        tableString = `
| TIM Name | Power Domain | Resolution | Prescaler | Repeat | CC Ch | Phase Load | Shadow Load | Shadow CC | Deadband | Fault | QEI |
| :------: | :----------: | :--------: | :-------: | :-----:| :---: | :--------: | :---------: | :-------: | :------: | :---: | :-: |
| TIMG0 | PD0 | 16-bit | 8-bit | - | 2 | - | - | - | - | - | - |
| TIMG6 | PD1 | 16-bit | 8-bit | - | 2 | - | - | - | - | - | - |
| TIMG7 | PD1 | 16-bit | 8-bit | - | 2 | - | Y | Y | - | - | - |
| TIMG8 | PD0 | 16-bit | 8-bit | - | 2 | - | - | - | - | - | Y |
| TIMG12 | PD1 | 32-bit | - | - | 2 | - | - | Y | - | - | - |
| TIMA0 | PD1 | 16-bit | 8-bit | 8-bit | 4 | Y | Y | Y | Y | Y | - |
| TIMA1 | PD1 | 16-bit | 8-bit | 8-bit | 2 | Y | Y | Y | Y | Y | - |
`
    }
    return `
The **Pulse Width Modulation (PWM) Driver module** allows you generate edge-aligned
output waveforms.

Under *Basic Configuration* users can:
- Configure clock source
- Configure timer settings
- Configure PWM:
    - Select PWM mode
    - Configure PWM Channels (compare values, duty cycle, etc.)

Under *Advanced Configuration* users can:
    - Configure cross trigger

This module supports the different types of Timers included in MSPM0 including *TIMGx*, *TIMAx*.
The following table includes a description of the features included in **${deviceName}**.
Check the datasheet of your selected device for more detailed information.
${tableString}
TIMG Block Diagram:
![TIMG Block Diagram](../docs/english/sysconfig/images/timgBlockDiagram.png "TIMG Block Diagram")
See the MSPM0 Technical Reference Manual for block diagrams of TIMA and more information about all Timers.
`
}

/*
 *  ======== base ========
 *  Define the base PWM properties and methods
 */
let base = {
    displayName: "TIMER - PWM",
    description: "Pulse Width Modulation (PWM) Output Driver",
    longDescription: getLongDescription(),
    defaultInstanceName: "PWM_",
    config:         Common.addNameConfig(pwmConfig, "/ti/driverlib/PWM", "CONFIG_PWM_"),
    validate:       validate,

    initPriority:   5,
    modules:        Common.autoForceModules(["SYSCTL","Board","EVENT"]),

    _getPinResources: _getPinResources
};

let devicePWM = system.getScript("/ti/driverlib/pwm/PWMTimerMSPM0");

exports = devicePWM.extend(base);
