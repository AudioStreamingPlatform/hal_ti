let Common = system.getScript("/ti/driverlib/Common.js");
// TODO: (H)
// let Pinmux   = system.getScript("/driverlib/pinmux.js");

/* Intro splash on GUI */
let longDescription = "MCAN";

var longDescriptionNomBitTimeParam = `
Below Parameters define the length of individual segments of Nominal Bit Time finally governing the nominal bit rate.\n
\n
NominalbitTime (Tq) = (NTSEG1 + 1) + (NTSEG2 + 1) + 1\n
NominalBRP =  (NBRP+1)\n
FinalNominalBaudRate = CANCLK/( NominalBRP * NominalbitTime)\n`

var longDescriptionDataBitTimeParam = `
Below Parameters define the length of individual segments of Data Bit Time finally governing the data bit rate.\n\n

DatabitTime = (DTSEG1 + 1) + (DTSEG2 + 1) + 1\n
DataBRP =  (DBRP+1)\n
FinalDataBaudRate = CANCLK/( DataBRP * DatabitTime)\n
`
var FileDescription = `\n ![Nominal Bit Length](../docs/english/sysconfig/images/mcanNomBitDiagram.png "Nominal Bit Length")\n
`

var Line0IntName = "DL_MCAN_INTR_LINE_NUM_0";
var Line1IntName = "DL_MCAN_INTR_LINE_NUM_1";

/* DL_MCAN_INTERRUPTS */
let interruptOptions = [
    {name: "DL_MCAN_MSP_INTERRUPT_WAKEUP", displayName: "Clock Stop Wake Up interrupt"},
    {name: "DL_MCAN_MSP_INTERRUPT_TIMESTAMP_OVERFLOW", displayName: "External Timestamp Counter Overflow interrupt"},
    {name: "DL_MCAN_MSP_INTERRUPT_DOUBLE_ERROR_DETECTION", displayName: "Message RAM Double Error Detection interrupt"},
    {name: "DL_MCAN_MSP_INTERRUPT_SINGLE_ERROR_CORRECTION ", displayName: "Message RAM Single Error Detection interrupt"},
    {name: "DL_MCAN_MSP_INTERRUPT_LINE1", displayName: "MCAN Interrupt Line 1"},
    {name: "DL_MCAN_MSP_INTERRUPT_LINE0", displayName: "MCAN Interrupt Line 0"},
]

let mcanClk = 0;

function onChangeUseTdc(inst, ui)
{
    if (inst.tdcEnable) {
        ui.tdcConfig_tdcf.hidden = false;
        ui.tdcConfig_tdco.hidden = false;
    }
    else {
        ui.tdcConfig_tdcf.hidden = true;
        ui.tdcConfig_tdco.hidden = true;
    }
}
function onChangeEnableInterrupt(inst, ui)
{
    if (inst.enableInterrupt) {
        ui.interruptFlags.hidden = false;
        ui.interruptLine.hidden = false;
        ui.interruptLine0Flag.hidden = false;
        ui.interruptLine1Flag.hidden = false;
        ui.m0interrupts.hidden = false;
    }
    else {
        ui.interruptFlags.hidden = true;
        ui.interruptLine.hidden = true;
        ui.interruptLine0Flag.hidden = true;
        ui.interruptLine1Flag.hidden = true;
        ui.m0interrupts.hidden = true;

    }
}
function onChangeUseAddCon(inst, ui)
{
    if (inst.additionalCoreConfig) {
        ui.monEnable.hidden = false;
        ui.asmEnable.hidden = false;
        ui.tsPrescalar.hidden = false;
        ui.tsSelect.hidden = false;
        ui.timeoutSelect.hidden = false;
        ui.timeoutPreload.hidden = false;
        ui.timeoutCntEnable.hidden = false;
        ui.rrfs.hidden = false;
        ui.rrfe.hidden = false;
        ui.anfe.hidden = false;
        ui.anfs.hidden = false;
    }
    else {
        ui.monEnable.hidden = true;
        ui.asmEnable.hidden = true;
        ui.tsPrescalar.hidden = true;
        ui.tsSelect.hidden = true;
        ui.timeoutSelect.hidden = true;
        ui.timeoutPreload.hidden = true;
        ui.timeoutCntEnable.hidden = true;
        ui.rrfs.hidden = true;
        ui.rrfe.hidden = true;
        ui.anfe.hidden = true;
        ui.anfs.hidden = true;
    }
}
function onChangeMsgRamConfig(inst, ui)
{
    if (inst.msgRamConfig) {
        ui.flssa.hidden = false;
        ui.lss.hidden = false;
        ui.flesa.hidden = false;
        ui.lse.hidden = false;
        ui.txStartAddr.hidden = false;
        ui.txBufNum.hidden = false;
        ui.txFIFOSize.hidden = false;
        ui.txBufMode.hidden = false;
        ui.txBufElemSize.hidden = false;
        ui.txEventFIFOStartAddr.hidden = false;
        ui.txEventFIFOWaterMark.hidden = false;
        ui.rxFIFO0startAddr.hidden = false;
        ui.rxFIFO0size.hidden = false;
        ui.rxFIFO0waterMark.hidden = false;
        ui.rxFIFO0OpMode.hidden = false;
        ui.rxFIFO1startAddr.hidden = false;
        ui.rxFIFO1size.hidden = false;
        ui.rxFIFO1waterMark.hidden = false;
        ui.rxFIFO1OpMode.hidden = false;
        ui.rxBufStartAddr.hidden = false;
        ui.rxBufElemSize.hidden = false;
        ui.rxFIFO0ElemSize.hidden = false;
        ui.rxFIFO1ElemSize.hidden = false;
    }
    else {
        ui.flssa.hidden = true;
        ui.lss.hidden = true;
        // ui.flesa.hidden = true;
        ui.lse.hidden = true;
        ui.txStartAddr.hidden = true;
        ui.txBufNum.hidden = true;
        ui.txFIFOSize.hidden = true;
        ui.txBufMode.hidden = true;
        ui.txBufElemSize.hidden = true;
        ui.txEventFIFOStartAddr.hidden = true;
        ui.txEventFIFOWaterMark.hidden = true;
        ui.rxFIFO0startAddr.hidden = true;
        ui.rxFIFO0size.hidden = true;
        ui.rxFIFO0waterMark.hidden = true;
        ui.rxFIFO0OpMode.hidden = true;
        ui.rxFIFO1startAddr.hidden = true;
        ui.rxFIFO1size.hidden = true;
        ui.rxFIFO1waterMark.hidden = true;
        ui.rxFIFO1OpMode.hidden = true;
        ui.rxBufStartAddr.hidden = true;
        ui.rxBufElemSize.hidden = true;
        ui.rxFIFO0ElemSize.hidden = true;
        ui.rxFIFO1ElemSize.hidden = true;
    }
}

function onChangeStdFilterElem(inst,ui)
{
    ui.stdFiltType.hidden = (inst.stdFiltElem == "000");
}

function onChangeStdFilterType(inst,ui)
{
    let state = (inst.stdFiltType == "11");
    ui.stdFiltID1.hidden = state;
    ui.stdFiltID2.hidden = state;
}

function onChangeExtFilterElem(inst,ui)
{
    ui.extFiltType.hidden = (inst.extFiltElem == "000");
}

function onChangeExtFilterType(inst,ui)
{
    let state = (inst.extFiltType == "11");
    ui.extFiltID1.hidden = state;
    ui.extFiltID2.hidden = state;
}

function getNomRatePrescale(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcNomBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }

    return (config[0] - 1);
}

function getNomTimeSeg1(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcNomBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[2] + config[4] - 1)
}

function getNomTimeSeg2(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcNomBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[3] - 1)
}

function getNomDataSynchJumpWidth(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcNomBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[5] - 1)
}

function getNomSamplePoint(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcNomBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (parseFloat((((1 + config[2] + config[4]) / (1 + config[2] + config[4] + config[3]))*100).toFixed(2)))
}

function getDataRatePrescale(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcDataBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }

    return (config[0] - 1);
}

function getDataTimeSeg1(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcDataBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[2] + config[4] - 1)
}

function getDataTimeSeg2(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcDataBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[3] - 1)
}

function getDataDataSynchJumpWidth(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcDataBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (config[5] - 1)
}

function getDataSamplePoint(inst)
{
    let mcan_freq = inst.mcan_freq;

    let config = calcDataBitTim(inst, mcan_freq)

    if(config == null){
        return -1
    }
    return (parseFloat(((1 + config[2] + config[4]) / (1 + config[2] + config[4] + config[3])*100).toFixed(2)))
}


function calcNomBitTim(inst, mcan_freq)
{
    // TODO update
    // let clock = inst.mcan_freq;
    let clock_mhz = (mcan_freq / 1000000);
    let nomBitRate_kbits_sec = inst.desiredNomRate;
    let busLenght_m = inst.bus_lenght;
    let extraProp_us = inst.extra_prop_delay;

    // Bit calculation
    let bitTime_us = 1000/nomBitRate_kbits_sec;
    let cycles_bit = (clock_mhz * bitTime_us);
    let propagation_time_us = (2 * ((0.005 * busLenght_m) + extraProp_us))
    let propation_frac = propagation_time_us / bitTime_us;

    const tq_bit_min = 8
    const tq_bit_max = 25
    // Create a Map
    const params = new Map();

    for (let tq_bit = tq_bit_min; tq_bit < tq_bit_max; tq_bit++) {
        let brp = Math.round(cycles_bit/ tq_bit);
        let error = Math.abs((((tq_bit*brp)-cycles_bit)/cycles_bit).toFixed(4));
        let prop_tq = Math.ceil(propation_frac*tq_bit)
        let seg2 = Math.ceil((tq_bit-(1+prop_tq))/2)
        let seg1 = tq_bit - (1 + prop_tq + seg2)
        let maxsjw = Math.min(seg1,seg2);
        let df1 = maxsjw/(((2*((13*tq_bit) - seg2))));
        let df2 = maxsjw/(20*tq_bit);
        let osctol = Math.min(df1,df2);

        let total_tol;

        if((seg1 > 0) && (seg2 > 0) && (prop_tq <=15) && (seg1 <= 15) && (seg2 <= 15) && ((1+prop_tq+seg1+seg2)== tq_bit)){
            total_tol = (osctol - error)
        }else{
            total_tol = -1.0
        }
        let array = [];

        array.push(brp);
        array.push(error);
        array.push(prop_tq);
        array.push(seg2);
        array.push(seg1);
        array.push(maxsjw);
        array.push(df1);
        array.push(df2);
        array.push(osctol);
        array.push(total_tol);

        params.set(tq_bit,array);
    }

    let max_tol = 0;
    let keyVal = null;
    for (let [key, value] of params) {
        let array = params.get(key);
        let new_tol = array[9];
        max_tol = Math.max(max_tol,new_tol);
        if(max_tol == new_tol){
            keyVal = key;
        }
    }

    if(keyVal == null){
        return null;
    }

    return params.get(keyVal);

}

function calcDataBitTim(inst, mcan_freq)
{
    // TODO update
    // let clock = inst.mcan_freq;
    let clock_mhz = (mcan_freq / 1000000);
    let bitRate_mbits_sec = inst.desiredDataRate;
    let busLenght_m = inst.bus_lenght;
    let extraProp_us = inst.extra_prop_delay;

    // Bit calculation
    let bitTime_ns = 1000/bitRate_mbits_sec;
    let cycles_bit = (clock_mhz / bitRate_mbits_sec);
    let propagation_time_us = (2 * ((1 * busLenght_m) + extraProp_us))
    let propation_frac = propagation_time_us / bitTime_ns;

    const tq_bit_min = 8
    const tq_bit_max = 25
    // Create a Map
    const params = new Map();

    for (let tq_bit = tq_bit_min; tq_bit < tq_bit_max; tq_bit++) {
        let brp = Math.round(cycles_bit/ tq_bit);
        let error = Math.abs((((tq_bit*brp)-cycles_bit)/cycles_bit).toFixed(4));
        let prop_tq = Math.ceil(propation_frac*tq_bit)
        let seg2 = Math.ceil((tq_bit-(1+prop_tq))/2)
        let seg1 = tq_bit - (1 + prop_tq + seg2)
        let maxsjw = Math.min(seg1,seg2);
        let df1 = maxsjw/(((2*((13*tq_bit) - seg2))));
        let df2 = maxsjw/(20*tq_bit);
        let osctol = Math.min(df1,df2);

        let total_tol;

        if((seg1 > 0) && (seg2 > 0) && (prop_tq <=15) && (seg1 <= 15) && (seg2 <= 15) && ((1+prop_tq+seg1+seg2)== tq_bit)){
            total_tol = (osctol - error)
        }else{
            total_tol = -1.0
        }
        let array = [];

        array.push(brp);
        array.push(error);
        array.push(prop_tq);
        array.push(seg2);
        array.push(seg1);
        array.push(maxsjw);
        array.push(df1);
        array.push(df2);
        array.push(osctol);
        array.push(total_tol);

        params.set(tq_bit,array);
    }

    let max_tol = 0;
    let keyVal = null;
    for (let [key, value] of params) {
        let array = params.get(key);
        let new_tol = array[9];
        max_tol = Math.max(max_tol,new_tol);
        if(max_tol == new_tol){
            keyVal = key;
        }
    }

    if(keyVal == null){
        return null;
    }

    return params.get(keyVal);

}

function onChangeUpdateNomBitFields(inst, ui)
{
    let state = inst.useCalcNomVal
    ui.nomRatePrescalar_calc.hidden = !state;
    ui.nomRatePrescalar_manual.hidden = state;
    ui.nomTimeSeg1_calc.hidden = !state;
    ui.nomTimeSeg1_manual.hidden = state;
    ui.nomTimeSeg2_calc.hidden = !state;
    ui.nomTimeSeg2_manual.hidden = state;
    ui.nomSynchJumpWidth_calc.hidden = !state;
    ui.nomSynchJumpWidth_manual.hidden = state;
    ui.nomSamplePoint.hidden = !state;

}

function onChangeUpdateDataBitFields(inst, ui)
{
    let state = inst.useCalcDataVal
    ui.dataRatePrescalar_calc.hidden = !state;
    ui.dataRatePrescalar_manual.hidden = state;
    ui.dataTimeSeg1_calc.hidden = !state;
    ui.dataTimeSeg1_manual.hidden = state;
    ui.dataTimeSeg2_calc.hidden = !state;
    ui.dataTimeSeg2_manual.hidden = state;
    ui.dataSynchJumpWidth_calc.hidden = !state;
    ui.dataSynchJumpWidth_manual.hidden = state;
    ui.dataSamplePoint.hidden = !state;
}

let MCAN_InterruptFlags = [
        {name: "DL_MCAN_INTR_MASK_ALL", displayName : "Enable All Interrupts "},
        {name: "DL_MCAN_INTERRUPT_RF0N", displayName : "Rx FIFO 0 New Message interrupt "},
        {name: "DL_MCAN_INTERRUPT_RF0W", displayName : "Rx FIFO 0 Watermark Reached interrupt"},
        {name: "DL_MCAN_INTERRUPT_RF0F", displayName : "Rx FIFO 0 Full interrupt"},
        {name: "DL_MCAN_INTERRUPT_RF0L", displayName : "Rx FIFO 0 Message Lost interrupt"},
        {name: "DL_MCAN_INTERRUPT_RF1N", displayName : "Rx FIFO 1 New Message interrupt "},
        {name: "DL_MCAN_INTERRUPT_RF1W", displayName : "Rx FIFO 1 Watermark Reached interrupt"},
        {name: "DL_MCAN_INTERRUPT_RF1F", displayName : "Rx FIFO 1 Full interrupt"},
        {name: "DL_MCAN_INTERRUPT_RF1L", displayName : "Rx FIFO 1 Message Lost interrupt"},
        {name: "DL_MCAN_INTERRUPT_HPM", displayName : "High Priority Message interrupt "},
        {name: "DL_MCAN_INTERRUPT_TC", displayName : "Transmission Completed interrupt"},
        {name: "DL_MCAN_INTERRUPT_TCF", displayName : "Transmission Cancellation Finished interrupt"},
        {name: "DL_MCAN_INTERRUPT_TFE", displayName : "Tx FIFO Empty interrupt"},
        {name: "DL_MCAN_INTERRUPT_TEFN", displayName : "Tx Event FIFO New Entry interrupt "},
        {name: "DL_MCAN_INTERRUPT_TEFW", displayName : "Tx Event FIFO Watermark Reached interrupt"},
        {name: "DL_MCAN_INTERRUPT_TEFF", displayName : "Tx Event FIFO Full interrupt"},
        {name: "DL_MCAN_INTERRUPT_TEFL", displayName : "Tx Event FIFO Element Lost interrupt"},
        {name: "DL_MCAN_INTERRUPT_TSW", displayName : "Timestamp Wraparound interrupt"},
        {name: "DL_MCAN_INTERRUPT_MRAF", displayName : "Message RAM Access Failure interrupt"},
        {name: "DL_MCAN_INTERRUPT_TOO", displayName : "Timeout Occurred interrupt"},
        {name: "DL_MCAN_INTERRUPT_DRX", displayName : "Message stored to Dedicated Rx Buffer interrupt "},
        {name: "DL_MCAN_INTERRUPT_BEC", displayName : "Bit Error Corrected interrupt"},
        {name: "DL_MCAN_INTERRUPT_BEU", displayName : "Bit Error Uncorrected interrupt"},
        {name: "DL_MCAN_INTERRUPT_ELO", displayName : "Error Logging Overflow interrupt"},
        {name: "DL_MCAN_INTERRUPT_EP", displayName : "Error Passive interrupt"},
        {name: "DL_MCAN_INTERRUPT_EW", displayName : "Warning Status interrupt"},
        {name: "DL_MCAN_INTERRUPT_BO", displayName : "Bus_Off Status interrupt "},
        {name: "DL_MCAN_INTERRUPT_WDI", displayName : "Watchdog Interrupt interrupt"},
        {name: "DL_MCAN_INTERRUPT_PEA", displayName : "Protocol Error in Arbitration Phase interrupt"},
        {name: "DL_MCAN_INTERRUPT_PED", displayName : "Protocol Error in Data Phase interrupt"},
        {name: "DL_MCAN_INTERRUPT_ARA", displayName : "Access to Reserved Address interrupt"},
];
MCAN_InterruptFlags
let MCAN_elemSize = [
        {name: "DL_MCAN_ELEM_SIZE_8BYTES", displayName : "8 byte data field "},
        {name: "DL_MCAN_ELEM_SIZE_12BYTES", displayName : "12 byte data field "},
        {name: "DL_MCAN_ELEM_SIZE_16BYTES", displayName : "16 byte data field"},
        {name: "DL_MCAN_ELEM_SIZE_20BYTES", displayName : "20 byte data field"},
        {name: "DL_MCAN_ELEM_SIZE_24BYTES", displayName : "24 byte data field "},
        {name: "DL_MCAN_ELEM_SIZE_32BYTES", displayName : "32 byte data field "},
        {name: "DL_MCAN_ELEM_SIZE_48BYTES", displayName : "48 byte data field "},
        {name: "DL_MCAN_ELEM_SIZE_64BYTES", displayName : "64 byte data field"},
];

let MCAN_fifoOPMode = [
        {name: "0", displayName : "FIFO blocking mode "},
        {name: "1", displayName : "FIFO overwrite mode"},
];

/* Retention configurable */
let retentionConfig = [];
if(Common.isDeviceM0G()){
    retentionConfig = retentionConfig.concat(
        {
            name        : "enableRetention",
            default     : false,
            hidden      : true,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/CANFD/.test(inst.peripheral.$solution.peripheralName));
                }catch (e) {
                    // do nothing
                }
                return solution;
            }
        },
        {
            name        : "enableRetentionUI",
            displayName : "Low-Power Register Retention",
            default     : "",
            longDescription: `
Some MSPM0G peripherals residing in PD1 domain do not retain register contents when
entering STOP or STANDBY modes.\n
Please view the datasheet for more details.\n
Developers can decide to re-initialize the peripheral using the default
initialization from SysConfig in their application. This approach is more
memory-efficient.\n
Alternatively, the user may also call the provided DriverLib APIs to save and
restore the register configuration of the peripheral before and after entering
low-power mode. This approach is recommended if the peripheral configuration is
modified at runtime.
            `,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/CANFD/.test(inst.peripheral.$solution.peripheralName)) && !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
                }catch (e) {
                    // do nothing
                }
                return (solution?"Registers not retained":"Registers retained");
            }
        },
        {
            name        : "overrideRetention",
            displayName : "Disable Retention APIs",
            longDescription: `
When selected, the retention APIs will not be generated regardless of selected peripheral.`,
            default     : false,
            hidden      : false,
        },
    );
}






/* Array of CAN configurables that are common across device families */
let config = [
    /* DL_ADC12_setClockConfig */
    {
        name: "GROUP_CAN_CLOCK",
        displayName: "MCAN Clock Frequency",
        description: "",
        longDescription: "MCAN clock frequency is configured in SYSCTL Module (CANCLK)",
        collapsed: false,
        config: [
            {
                name: "can_clk_freq",
                hidden: true,
                default: 0,
                getValue: (inst) => {
                    return system.modules["/ti/driverlib/SYSCTL"].$static.CANCLK_Freq;
                }

            },
            {
                name: "can_clk_freq_src",
                hidden: true,
                default: "",
                getValue: (inst) => {
                    return system.modules["/ti/driverlib/SYSCTL"].$static.CANCLKSource;
                }

            },
            {
                name: "can_clk_freq_disp",
                displayName: "CAN_CLK Frequency",
                description: "CAN_CLK Frequency",
                longDescription: ``,
                default: "0Hz",
                hidden: false,
                getValue: (inst) => {
                    return (Common.getUnitPrefix(inst.can_clk_freq)).str + "Hz";
                }
            },
            {
                name: "can_clk_freq_div",
                displayName: "CAN_CLK Frequency Divider",
                description: "Frequency divicer applied after CAN_CLK",
                hidden: false,
                default: "1",
                options     : [
                    {name: "1", displayName : "Divide by 1"},
                    {name: "2", displayName : "Divide by 2"},
                    {name: "4", displayName : "Divide by 4"},
                ],
            },
            {
                name: "mcan_freq",
                hidden: true,
                default: 0,
                getValue: (inst) => {
                    let tempDiv  = parseInt((inst.can_clk_freq_div));
                    let tempFreq = (inst.can_clk_freq / tempDiv);
                    mcanClk = tempFreq;
                    return tempFreq;
                },
            },
            {
                name: "mcan_freq_disp",
                displayName: "MCAN Frequency",
                description: "MCAN Frequency",
                longDescription: `MCAN Frequency = CAN_CLK Frequency / CAN_CLK Frequency Divider`,
                default: "0Hz",
                hidden: false,
                getValue: (inst) => {
                    return (Common.getUnitPrefix(inst.mcan_freq)).str + "Hz";
                }
            },
        ]
    },
    {
        name: "BASIC_CONFIG",
        displayName: "MCAN Basic Configuration",
        description: "",
        longDescription: "Basic Configuration for  MCAN ",
        collapsed: false,
        config: [
        {
            name        : "fdMode",
            displayName : "Enable CAN FD Mode",
            description : 'Whether CAN flexible data mode to be enabled.',
            hidden      : false,
            default     : true,
        },
        {
            name        : "brsEnable",
            displayName : "Enable Bit Rate Switching",
            description : 'Whether Bit Rate Switching to be enabled.',
            longDescription: "Send Data at higher rate instead of arbitration rate",
            hidden      : false,
            default     : true,
        },
        {
            name        : "loopbackMode",
            displayName : "Enable Loopback Mode",
            description : 'Enable Loopback Mode.',
            longDescription: "Transmitted messages become received messages",
            hidden      : false,
            default     : "disabled",
            options : [
                {name:"disabled", displayName:"Disable filter element"},
                {name:"external", displayName:"Enabled and external"},
                {name:"internal", displayName:"Enabled and internal"},
        ]
        },
        {
            name        : "txpEnable",
            displayName : "Enable Transmit Pause",
            description : 'Enable Transmit Pause.',
            longDescription : "Pause for 2 CAN bit times before next transmission",
            hidden      : false,
            default     : false,
        },
        {
            name        : "efbi",
            displayName : "Enable Edge Filtering",
            description : 'Enable Edge Filtering.',
            longDescription : "Two consecutive dominant time quanta required to detect an edge for hard synchronization",
            hidden      : false,
            default     : false,
        },
        {
            name        : "pxhddisable",
            displayName : "Enable Protocol Exception Handling",
            description : 'Enable Protocol Exception Handling',
            longDescription : "Detection of bits that are reserved for future protocol expansion",
            hidden      : false,
            default     : false,
        },
        {
            name        : "darEnable",
            displayName : "Messages Will Only Be Sent Once",
            description : 'Disable Automatic retransmission of message.',
            longDescription : "If automatic retransmission is disabled, the MCAN module will no longer retransmit when there is a transmission error, NACK, or the MCAN module loses arbitration.",
            hidden      : false,
            default     : false,
        },
        {
            name        : "wkupReqEnable",
            displayName : "Enable Wakeup Request",
            description : 'Enable Wakeup request.',
            hidden      : false,
            default     : false,
        },
        {
            name        : "autoWkupEnable",
            displayName : "Enable Auto-Wakeup",
            description : 'Enable Auto-Wakeup.',
            hidden      : false,
            default     : false,
        },
        {
            name        : "emulationEnable",
            displayName : "Enable Emulation/Debug Suspend",
            description : 'Enable Emulation/Debug Suspend.',
            hidden      : false,
            default     : false,
        },
        {
            name: "GROUP_TDC",
            displayName: "Transmitter Delay Compensation (TDC)",
            config: [
                {
                    name        : "tdcEnable",
                    displayName : "Enable TDC",
                    description : 'Enable Transmitter Delay Compensation.',
                    longDescription : 'Enable Transmitter Delay Compensation.',
                    hidden      : false,
                    onChange    : onChangeUseTdc,
                    default     : false,
                },
                {
                    name        : "tdcConfig_tdcf",
                    displayName : "TDC Filter Window Length (Cycles)",
                    description : 'Transmitter Delay Compensation Filter Window Length (MCAN_CLK Cycles).',
                    hidden      : true,
                    default     : 0xA,
                },
                {
                    name        : "tdcConfig_tdco",
                    displayName : "TDC Offset (Cycles)",
                    description : 'Transmitter Delay Compensation Offset (MCAN_CLK Cycles).',
                    hidden      : true,
                    default     : 0x6,
                },
            ]
        },
        {
            name        : "wdcPreload",
            displayName : "Message RAM Watchdog Preload Value",
            description : 'Message RAM Watchdog Counter Preload Value.',
            hidden      : false,
            isInteger   : true,
            range       : [0,255],
            default     : 0xFF,
        },
        {
            name: "Bit Timing Parameters",
            displayName: "Bit Timing Parameters",
            longDescription : FileDescription,
            config: [
            {
                name: "bus_lenght",
                displayName: "Bus Length (m)",
                range: [0.0, 1000.0],
                default: 1.0,
            },
            {
                name: "extra_prop_delay",
                displayName: "Extra Propagation Delay (us)",
                range: [0.0, 10000.0],
                default: 0.0,
            },
            { config:
                [
                    {
                        name: "Nominal Bit Rate",
                        displayName: "Nominal Bit Rate",
                        collapsed : false,
                        config: [
                            {
                                name : "desiredNomRate",
                                displayName : "Desired Nominal Rate (kbits/sec)",
                                default: 500,
                                range : [1,999],
                            },
                            {
                                name : "useCalcNomVal",
                                displayName : "Use Calculated Nominal Bit Timing",
                                description : "Use Calculated Nominal Bit Timing Parameters",
                                default: true,
                                onChange: onChangeUpdateNomBitFields,
                            },
                            {

                                name: "Nominal Bit Timing Parameters",
                                displayName: "Nominal Bit Timing Parameters",
                                longDescription : longDescriptionNomBitTimeParam,
                                config: [
                                    {
                                        name        : "nomRatePrescalar_calc",
                                        displayName : "Nominal Baud Rate Pre-Scaler (NBRP)",
                                        description : 'Nominal Baud Rate Pre-Scaler (NBRP)',
                                        hidden      : false,
                                        readOnly    : true,
                                        default     : 0x7,
                                        getValue: (inst) => {
                                            return getNomRatePrescale(inst);
                                        }
                                    },
                                    {
                                        name        : "nomRatePrescalar_manual",
                                        displayName : "Nominal Baud Rate Pre-Scaler (NBRP)",
                                        description : 'Nominal Baud Rate Pre-Scaler (NBRP)',
                                        hidden      : true,
                                        readOnly    : false,
                                        range       : [0,511],
                                        default     : 0x0,
                                    },
                                    {
                                        name        : "nomTimeSeg1_calc",
                                        displayName : "Time Before Sample Pt (NTSEG1 Tq)",
                                        description : 'Nominal Time Segment Before Sample Point (NTSEG1 Tq)',
                                        longDescription : 'Nominal Time Segment Before sample point (NTSEG1 Tq)',
                                        hidden      : false,
                                        readOnly    : true,
                                        default     : 0x4,
                                        getValue: (inst) => {
                                            return getNomTimeSeg1(inst);
                                        }
                                    },
                                    {
                                        name        : "nomTimeSeg1_manual",
                                        displayName : "Time Before Sample Pt (NTSEG1 Tq)",
                                        description : 'Nominal Time Segment Before sample point (NTSEG1 Tq)',
                                        longDescription : 'Nominal Time Segment Before sample point (NTSEG1 Tq)',
                                        hidden      : true,
                                        readOnly    : false,
                                        range : [0,255],
                                        default     : 0x0,
                                    },
                                    {
                                        name        : "nomTimeSeg2_calc",
                                        displayName : "Time After Sample Pt (NTSEG2 Tq)",
                                        description : 'Nominal Time segment after sample point (NTSEG2 Tq)',
                                        longDescription : 'Nominal Time segment after sample point (NTSEG2 Tq)',
                                        hidden      : false,
                                        readOnly    : true,
                                        default     : 0x3,
                                        getValue: (inst) => {
                                            return getNomTimeSeg2(inst);
                                        }
                                    },
                                    {
                                        name        : "nomTimeSeg2_manual",
                                        displayName : "Time After Sample Pt (NTSEG2 Tq)",
                                        description : 'Nominal Time segment after sample point (NTSEG2 Tq)',
                                        longDescription : 'Nominal Time segment after sample point (NTSEG2 Tq)',
                                        hidden      : true,
                                        readOnly    : false,
                                        range : [0,127],
                                        default     : 0x0,
                                    },
                                    {
                                        name        : "nomSynchJumpWidth_calc",
                                        displayName : "(Re)Synch Jump Width Range (NSJW Tq)",
                                        description : 'Nominal (Re)Synchronization Jump Width Range (NSJW Tq)',
                                        longDescription : 'Nominal (Re)Synchronization Jump Width Range (NSJW Tq)',
                                        hidden      : false,
                                        readOnly    : true,
                                        default     : 0x3,
                                        getValue: (inst) => {
                                            return getNomDataSynchJumpWidth(inst);
                                        }
                                    },
                                    {
                                        name        : "nomSynchJumpWidth_manual",
                                        displayName : "(Re)Synch Jump Width Range (NSJW Tq)",
                                        description : 'Nominal (Re)Synchronization Jump Width Range (NSJW Tq)',
                                        longDescription : 'Nominal (Re)Synchronization Jump Width Range (NSJW Tq)',
                                        hidden      : true,
                                        readOnly    : false,
                                        range : [0,127],
                                        default     : 0x0,
                                    },
                                    {
                                        name        : "nomSamplePoint",
                                        displayName : "Nominal Sampling Point (%)",
                                        hidden      : false,
                                        readOnly    : true,
                                        default     : 0.0,
                                        getValue: (inst) => {
                                            return getNomSamplePoint(inst);
                                        }
                                    }
                                ]

                            },
                        ]
                    },
            ]
            },
                {
                    name: "Data Bit Rate",
                    displayName: "Data Bit Rate",
                    collapsed : false,
                    config: [
                        {
                            name : "desiredDataRate",
                            displayName : "Desired Data Rate (Mbits/sec)",
                            default: 1.0,
                            range : [0.0,8.0],
                        },
                        {
                            name : "useCalcDataVal",
                            displayName : "Use Calculated Data Bit Timing",
                            description : "Use Calculated Data Bit Timing Parameters",
                            default: true,
                            onChange: onChangeUpdateDataBitFields,
                        },
                    ]
                },
                {
                    name: "Data Bit Timing Parameters",
                    displayName: "Data Bit Timing Parameters",
                    longDescription : longDescriptionDataBitTimeParam,
                    config: [
                        {
                            name        : "dataRatePrescalar_calc",
                            displayName : "Data Baud Rate Pre-scaler (DBRP)",
                            description : 'Data Baud Rate Pre-scaler (DBRP)',
                            hidden      : false,
                            readOnly    : true,
                            default     : 0x3,
                            getValue: (inst) => {
                                return getDataRatePrescale(inst);
                            }
                        },
                        {
                            name        : "dataRatePrescalar_manual",
                            displayName : "Data Baud Rate Pre-scaler (DBRP)",
                            description : 'Data Baud Rate Pre-scaler (DBRP)',
                            hidden      : true,
                            default     : 0,
                            range : [0,31],
                        },
                        {
                            name        : "dataTimeSeg1_calc",
                            displayName : "Time Before Sample Pt (DTSEG1 Tq)",
                            description : 'Data Time segment before sample point (DTSEG1 Tq)',
                            longDescription : 'Data Time segment before sample point (DTSEG1 Tq)',
                            hidden      : false,
                            readOnly    : true,
                            default     : 0x4,
                            getValue: (inst) => {
                                return getDataTimeSeg1(inst);
                            }
                        },
                        {
                            name        : "dataTimeSeg1_manual",
                            displayName : "Time Before Sample Pt (DTSEG1 Tq)",
                            description : 'Data Time segment before sample point (DTSEG1 Tq)',
                            longDescription : 'Data Time segment before sample point (DTSEG1 Tq)',
                            hidden      : true,
                            default     : 0,
                            range : [0,31],
                        },
                        {
                            name        : "dataTimeSeg2_calc",
                            displayName : "Time After Sample Pt (DTSEG2 Tq)",
                            description : 'Data Time segment after sample point (DTSEG2 Tq)',
                            longDescription : 'Data Time segment after sample point (DTSEG2 Tq)',
                            hidden      : false,
                            readOnly    : true,
                            default     : 0x3,
                            getValue: (inst) => {
                                return getDataTimeSeg2(inst);
                            }
                        },
                        {
                            name        : "dataTimeSeg2_manual",
                            displayName : "Time After Sample Pt (DTSEG2 Tq)",
                            description : 'Data Time segment after sample point (DTSEG2 Tq)',
                            longDescription : 'Data Time segment after sample point (DTSEG2 Tq)',
                            hidden      : true,
                            default     : 0,
                            range : [0,15],
                        },
                        {
                            name        : "dataSynchJumpWidth_calc",
                            displayName : "(Re)Synch Jump Width (DSJW Tq)",
                            description : 'Data (Re)Synchronization Jump Width (DSJW Tq)',
                            longDescription : 'Data (Re)Synchronization Jump Width (DSJW Tq)',
                            hidden      : false,
                            readOnly    : true,
                            default     : 0x3,
                            getValue: (inst) => {
                                return getDataDataSynchJumpWidth(inst);
                            }
                        },
                        {
                            name        : "dataSynchJumpWidth_manual",
                            displayName : "(Re)Synch Jump Width (DSJW Tq)",
                            description : 'Data (Re)Synchronization Jump Width (DSJW Tq)',
                            longDescription : 'Data (Re)Synchronization Jump Width (DSJW Tq)',
                            hidden      : true,
                            default     : 0,
                            range : [0,15],
                        },
                        {
                            name        : "dataSamplePoint",
                            displayName : "Data Sampling Point (%)",
                            hidden      : false,
                            readOnly    : true,
                            default     : 0.0,
                            getValue: (inst) => {
                                return getDataSamplePoint(inst);
                            }
                        }
                    ]
                },
            ]
        },
        {
            name: "GROUP_MSGRAMCONFIG",
            displayName: "Message RAM Configuration",
            longDescription: "These parameters configure the MCAN Message RAM for multiple sections. Make sure that none of the sections are overlapping by comparing their start address and end address with each other.",
            config: [
                {
                    name        : "msgRamConfig",
                    displayName : "Enable Message RAM Configuration",
                    description : 'Enable Message RAM Configuration.',
                    hidden      : true,
                    onChange    : onChangeMsgRamConfig,

                    default     : true,
                },
                {
                    name: "GROUP_STD_FILTER",
                    displayName : "Standard ID Filter configuration",
                    config:[
                        {
                            name        : "flssa",
                            displayName : "Std ID Filter List Start Address",
                            description : 'Standard ID Filter List Start Address.',
                            hidden      : false,
                            default     : 0x0,
                            isInteger   : true,
                        },
                        {
                            name        : "lss",
                            displayName : "No of Standard ID Filters",
                            description : 'No of Standard ID Filters.',
                            hidden      : false,
                            default     : 0x1,
                            isInteger   : true,
                        },
                        {
                            name: "GROUP_STD_FILTER_CONFIG",
                            displayName : "Standard ID Filter configuration",
                            collapsed      : true,
                            config:[
                                {
                                    name:"stdFiltElem",
                                    displayName: "Filter Element Configuration",
                                    hidden      : false,
                                    default: "000",
                                    options:[
                                        {name:"000", displayName:"Disable filter element"},
                                        {name:"001", displayName:"Store in Rx FIFO 0 if filter matches"},
                                        {name:"010", displayName:"Store in Rx FIFO 1 if filter matches"},
                                        {name:"011", displayName:"Reject ID if filter matches"},
                                        {name:"100", displayName:"Set priority if filter matches"},
                                        {name:"101", displayName:"Set priority and store in FIFO 0 if filter matches"},
                                        {name:"110", displayName:"Set priority and store in FIFO 1 if filter matches"},
                                        {name:"111", displayName:"Store into Rx Buffer or as debug message"},
                                    ],
                                    onChange: onChangeStdFilterElem,
                                },
                                {
                                    name:"stdFiltType",
                                    displayName: "Filter Type",
                                    hidden      : true,
                                    default: "11",
                                    options:[
                                        {name:"00", displayName:"Range filter from SFID1 to SFID2"},
                                        {name:"01", displayName:"Dual ID filter for SFID1 or SFID2"},
                                        {name:"10", displayName:"Classic filter: SFID1 = filter, SFID2 = mask"},
                                        {name:"11", displayName:"Filter element disabled"},
                                    ],
                                    onChange: onChangeStdFilterType,
                                },
                                {
                                    name:"stdFiltID1",
                                    displayName: "Filter ID 1 (SFID1)",
                                    hidden      : true,
                                    default: 0,
                                    isInteger   : true,
                                    range: [0,2047]
                                },
                                {
                                    name:"stdFiltID2",
                                    displayName: "Filter ID 2 (SFID2)",
                                    hidden      : true,
                                    default: 0,
                                    isInteger   : true,
                                    range: [0,2047]
                                },
                            ]
                        },
                    ]
                },
                {
                    name: "GROUP_EXT_FILTER",
                    displayName :"Extended ID Filter configuration",
                    collapsed: true,
                    config:[
                        {
                            name        : "flesa",
                            displayName : "Extd ID Filter List Start Address",
                            description : 'Extended ID Filter List Start Address.',
                            hidden      : false,
                            default     : 48,
                            isInteger   : true,
                        },
                        {
                            name        : "lse",
                            displayName : "No of Extended ID Filters",
                            description : 'No of Extended ID Filters.',
                            hidden      : false,
                            default     : 1,
                            isInteger   : true,
                        },
                        {
                            name: "GROUP_STD_FILTER_COPNFIG",
                            displayName : "Extended ID Filter configuration",
                            collapsed      : true,
                            config:[
                                {
                                    name:"extFiltElem",
                                    displayName: "Filter Element Configuration",
                                    hidden      : false,
                                    default: "000",
                                    options:[
                                        {name:"000", displayName:"Disable filter element"},
                                        {name:"001", displayName:"Store in Rx FIFO 0 if filter matches"},
                                        {name:"010", displayName:"Store in Rx FIFO 1 if filter matches"},
                                        {name:"011", displayName:"Reject ID if filter matches"},
                                        {name:"100", displayName:"Set priority if filter matches"},
                                        {name:"101", displayName:"Set priority and store in FIFO 0 if filter matches"},
                                        {name:"110", displayName:"Set priority and store in FIFO 1 if filter matches"},
                                        {name:"111", displayName:"Store into Rx Buffer or as debug message"},
                                    ],
                                    onChange: onChangeExtFilterElem,
                                },
                                {
                                    name:"extFiltType",
                                    displayName: "Filter Type",
                                    hidden      : true,
                                    default: "11",
                                    options:[
                                        {name:"00", displayName:"Range filter from EFID1 to EFID2"},
                                        {name:"01", displayName:"Dual ID filter for EFID1 or EFID2"},
                                        {name:"10", displayName:"Classic filter: EFID1 = filter, EFID2 = mask"},
                                        {name:"11", displayName:"Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1), XIDAM mask not applied"},
                                    ],
                                    onChange: onChangeExtFilterType,
                                },
                                {
                                    name:"extFiltID1",
                                    displayName: "Filter ID 1 (EFID1)",
                                    hidden      : true,
                                    default: 0,
                                    range: [0, 536870911],
                                    isInteger   : true,
                                },
                                {
                                    name:"extFiltID2",
                                    displayName: "Filter ID 2 (EFID2)",
                                    hidden      : true,
                                    default: 0,
                                    range: [0, 536870911],
                                    isInteger   : true,
                                },
                            ]
                        },
                    ]
                },
                {
                    name: "GROUP_MSGRAMCONFIG_TX",
                    displayName: "TX MSG RAM",
                    config : [
                        {
                            name        : "txStartAddr",
                            displayName : "TX Buffers Start Address",
                            description : 'TX Buffers Start Address.',
                            hidden      : false,
                            default     : 148,
                            isInteger   : true,
                        },
                        {
                            name        : "txBufNum",
                            displayName : "Number of Dedicated Transmit Buffers",
                            description : 'Number of Dedicated Transmit Buffers.',
                            hidden      : false,
                            default     : 10,
                            isInteger   : true,
                        },
                        {
                            name        : "txFIFOSize",
                            displayName : "No of TX FIFO Elements",
                            description : 'No of TX FIFO Elements.',
                            hidden      : false,
                            default     : 0,
                            isInteger   : true,
                        },
                        {
                            name        : "txBufMode",
                            displayName : "TX FIFO Operation Mode",
                            description : 'TX FIFO Operation Mode.',
                            hidden      : false,
                            default     : "0",
                            options     : [
                                {name: "0", displayName : "TX FIFO operation"},
                                {name: "1", displayName : "TX Queue operation"},
                            ],
                        },
                        {
                            name        : "txBufElemSize",
                            displayName : "TX Buffer Element Size",
                            description : 'TX Buffer Element Size.',
                            hidden      : false,
                            default     : MCAN_elemSize[7].name,
                            options     : MCAN_elemSize,
                        },
                        {
                            name        : "txEventFIFOStartAddr",
                            displayName : "TX Event FIFO Start Address",
                            description : 'TX Event FIFO Start Address.',
                            hidden      : false,
                            default     : 0xFF,
                            isInteger   : true,
                        },
                        {
                            name        : "txEventFIFOSize",
                            displayName : "TX Event FIFO Size",
                            description : 'TX Event FIFO Size.',
                            hidden      : false,
                            default     : 10,
                            isInteger   : true,
                        },
                        {
                            name        : "txEventFIFOWaterMark",
                            displayName : "TX Event FIFO Watermark INT Level",
                            description : 'Level For TX Event FIFO Watermark Interrupt.',
                            hidden      : false,
                            default     : 3,
                            isInteger   : true,
                        },
                    ]
                },
                {
                    name: "GROUP_MSGRAMCONFIG_RX",
                    displayName: "RX MSG RAM",
                    config : [
                        {
                            name        : "rxFIFO0startAddr",
                            displayName : "RX FIFO0 Start Address",
                            description : 'RX FIFO0 Start Address.',
                            hidden      : false,
                            default     : 548,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO0size",
                            displayName : "Number of RX FIFO0 Elements",
                            description : 'Number of RX FIFO0 Elements.',
                            hidden      : false,
                            default     : 10,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO0waterMark",
                            displayName : "RX FIFO0 Watermark",
                            description : 'RX FIFO0 Watermark.',
                            hidden      : false,
                            default     : 3,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO0OpMode",
                            displayName : "RX FIFO0 Operation Mode",
                            description : 'RX FIFO0 Operation Mode.',
                            hidden      : false,
                            default     : MCAN_fifoOPMode[0].name,
                            options     : MCAN_fifoOPMode,
                        },
                        {
                            name        : "rxFIFO1startAddr",
                            displayName : "RX FIFO1 Start Address",
                            description : 'RX FIFO1 Start Address.',
                            hidden      : false,
                            default     : 748,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO1size",
                            displayName : "Number of RX FIFO1 Elements",
                            description : 'Number of RX FIFO1 Elements.',
                            hidden      : false,
                            default     : 10,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO1waterMark",
                            displayName : "RX FIFO1 Watermark",
                            description : 'RX FIFO1 Watermark.',
                            hidden      : false,
                            default     : 3,
                            isInteger   : true,
                        },
                        {
                            name        : "rxFIFO1OpMode",
                            displayName : "RX FIFO1 Operation Mode",
                            description : 'RX FIFO1 Operation Mode.',
                            hidden      : false,
                            default     : MCAN_fifoOPMode[0].name,
                            options     : MCAN_fifoOPMode,
                        },
                        {
                            name        : "rxBufStartAddr",
                            displayName : "RX Buffer Start Address",
                            description : 'RX Buffer Start Address.',
                            hidden      : false,
                            default     : 948,
                            isInteger   : true,
                        },
                        {
                            name        : "rxBufElemSize",
                            displayName : "RX Buffer Element Size",
                            description : 'RX Buffer Element Size.',
                            hidden      : false,
                            default     : MCAN_elemSize[7].name,
                            options     : MCAN_elemSize,
                        },
                        {
                            name        : "rxFIFO0ElemSize",
                            displayName : "RX FIFO0 Element Size",
                            description : 'RX FIFO0 Element Size.',
                            hidden      : false,
                            default     : MCAN_elemSize[7].name,
                            options     : MCAN_elemSize,
                        },
                        {
                            name        : "rxFIFO1ElemSize",
                            displayName : "RX FIFO1 Element Size",
                            description : 'RX FIFO1 Element Size.',
                            hidden      : false,
                            default     : MCAN_elemSize[7].name,
                            options     : MCAN_elemSize,
                        },
                    ]
                },

            ]
        },
        ]
    },
    {
        name: "GROUP_CORECONFIG",
        displayName: "Advanced Configuration",
        config: [
            {
                name        : "additionalCoreConfig",
                displayName : "Enable Additional Core Configuration",
                description : 'Enable Additional Core Configuration.',
                hidden      : false,
                onChange    : onChangeUseAddCon,
                default     : false,
            },
            {
                name        : "monEnable",
                displayName : "Enable Bus Monitoring Mode",
                description : 'Enable Bus Monitoring Mode.',
                hidden      : true,
                default     : false,
            },
            {
                name        : "asmEnable",
                displayName : "Enable Normal CAN Operation",
                description : 'Enable Normal CAN Operation',
                hidden      : true,
                default     : false,
            },
            {
                name        : "tsPrescalar",
                displayName : "Time Stamp Prescaler Value",
                description : 'Time Stamp Prescaler Value.',
                hidden      : true,
                default     : 0xF,
            },
            {
                name        : "tsSelect",
                displayName : "Timestamp Counter Value",
                description : 'Timestamp Counter Value.',
                hidden      : true,
                default     : "0",
                options     : [
                    {name: "0", displayName : "Timestamp counter value always 0x0000"},
                    {name: "1", displayName : "Timestamp counter value incremented according to tsPrescalar"},
                    {name: "2", displayName : "External timestamp counter value used"},
                ],
            },
            {
                name        : "timeoutSelect",
                displayName : "Time-out Counter Source Select",
                description : 'Time-out Counter Source Select.',
                hidden      : true,
                default     : "DL_MCAN_TIMEOUT_SELECT_CONT",
                options     : [
                    {name: "DL_MCAN_TIMEOUT_SELECT_CONT", displayName : "Continuous operation Mode"},
                    {name: "DL_MCAN_TIMEOUT_SELECT_TX_EVENT_FIFO", displayName : "Timeout controlled by Tx Event FIFO"},
                    {name: "DL_MCAN_TIMEOUT_SELECT_RX_FIFO0", displayName : "Timeout controlled by Rx FIFO 0"},
                    {name: "DL_MCAN_TIMEOUT_SELECT_RX_FIFO1", displayName : "Timeout controlled by Rx FIFO 1"},
                ],
            },
            {
                name        : "timeoutPreload",
                displayName : "Start Value Of The Timeout Counter",
                description : 'Start Value Of The Timeout Counter.',
                hidden      : true,
                default     : 0xFFFF,
            },
            {
                name        : "timeoutCntEnable",
                displayName : "Enable Time-out Counter",
                description : 'Enable Time-out Counter.',
                hidden      : true,
                default     : false,
            },
            {
                name        : "rrfe",
                displayName : "Reject Remote Frames Extended",
                description : 'Reject Remote Frames Extended.',
                hidden      : true,
                default     : false,
            },
            {
                name        : "rrfs",
                displayName : "Reject Remote Frames Standard",
                description : 'Reject Remote Frames Standard.',
                hidden      : true,
                default     : false,
            },
            {
                name        : "anfe",
                displayName : "Accept Non-matching Frames Extended",
                description : 'Accept Non-matching Frames Extended.',
                hidden      : true,
                default     : "0",
                options     : [
                    {name: "0", displayName : "Accept in Rx FIFO 0"},
                    {name: "1", displayName : "Accept in Rx FIFO 1"},
                    {name: "2", displayName : "Reject"},
                ],
            },
            {
                name        : "anfs",
                displayName : "Accept Non-matching Frames Standard",
                description : 'Accept Non-matching Frames Standard.',
                hidden      : true,
                default     : "0",
                options     : [
                    {name: "0", displayName : "Accept in Rx FIFO 0"},
                    {name: "1", displayName : "Accept in Rx FIFO 1"},
                    {name: "2", displayName : "Reject"},
                ],
            },
        ]
    },
    {
        name: "GROUP_RETENTION",
        displayName: "Retention Configuration",
        description: "",
        longDescription: ``,
        collapsed: true,
        config: retentionConfig,
    },
    {
        name: "GROUP_INT",
        displayName: "Interrupts",
        config: [
            {
                name        : "enableInterrupt",
                displayName : "Enable Interrupt",
                description : 'To Enable CAN Interrupts.',
                hidden      : false,
                onChange    : onChangeEnableInterrupt,
                default     : false,
            },
            {
                name: "mcanInt",
                displayName: "MCAN Interrupts",
                config: [
                    {
                        name        : "interruptFlags",
                        displayName : "Enable MCAN Interrupts",
                        description : 'Which Interrupts to enable.',
                        hidden      : true,
                        minSelections : 0,
                        default     : [],
                        options     : MCAN_InterruptFlags,
                    },
                    {
                        name        : "interruptLine",
                        displayName : "Enable MCAN Line Interrupts",
                        description : 'Which MCAN Line Interrupts to enable',
                        hidden      : true,
                        minSelections : 0,
                        default     : [],
                        options     : [
                            {name: "DL_MCAN_INTR_LINE_NUM_1", displayName : "Enable MCAN interrupt line 1"},
                            {name: "DL_MCAN_INTR_LINE_NUM_0", displayName : "Enable MCAN interrupt line 0"},
                        ],
                    },
                    {
                        name        : "interruptLine0Flag",
                        displayName : "Interrupts To Trigger In Line0",
                        description : 'Interrupts To Trigger In Line0.',
                        hidden      : true,
                        minSelections : 0,
                        default     : [],
                        options     : MCAN_InterruptFlags,

                    },
                    {
                        name        : "interruptLine1Flag",
                        displayName : "Interrupts To Trigger In Line1",
                        description : 'Interrupts To Trigger In Line1.',
                        hidden      : true,
                        minSelections : 0,
                        default     : [],
                        options     : MCAN_InterruptFlags,

                    },
                ]
            },
            {
                name: "m0Int",
                displayName: "MSPM0 Interrupts",
                config: [
                    {
                        name        : "m0interrupts",
                        displayName : "Enable MSPM0 MCAN Interrupts",
                        description : 'Which Interrupts to enable.',
                        hidden      : true,
                        minSelections : 0,
                        default     : [],
                        options     : interruptOptions,
                    },
                ]
            }
        ]
    },
    // TODO: (H) -> from Pinmux file. doesnt exist for us. do we need this?
    // {
    //     name: "useCase",
    //     displayName : "PinMux Use Case",
    //     description : 'Peripheral use case',
    //     hidden      : false,
    //     default     : 'ALL',
    //     options     : Pinmux.getPeripheralUseCaseNames("MCAN"),
    //     onChange    : Pinmux.useCaseChanged,

    // },
];

function onValidate(inst, validation) {
    if(inst.can_clk_freq == 0){
        validation.logError(
            "CANCLK must be properly initialized in SYSCTL module",
            inst, "can_clk_freq_disp");
    }
    if (inst.tdcConfig_tdcf < 0 || inst.tdcConfig_tdcf > 0x7F)
    {
        validation.logError(
            "The TDC Filter Window Length must be between 0x0-0x7F",
            inst, "tdcConfig_tdcf");
    }
    if (inst.tdcConfig_tdco < 0 || inst.tdcConfig_tdco > 0x7F)
    {
        validation.logError(
            "The TDC Offset must be between 0x0-0x7F",
            inst, "tdcConfig_tdco");
    }
    if (inst.wdcPreload < 0 || inst.wdcPreload > 0xFF)
    {
        validation.logError(
            "Message RAM Watchdog Counter preload Value must be between 0x0-0xFF",
            inst, "wdcPreload");
    }
    if(inst.useCalcNomVal) {
        if (inst.nomRatePrescalar_calc < 0 || inst.nomRatePrescalar_calc > 0x1FF)
        {
            validation.logError(
                "Nominal Baud Rate Pre-scaler must be between 0x0-0x1FF. Lower Desired Nominal Rate",
                inst, ["nomRatePrescalar_calc","desiredNomRate"]);
        }
        if (inst.nomTimeSeg1_calc < 0 || inst.nomTimeSeg1_calc > 0xFF)
        {
            validation.logError(
                "Nominal Time segment before sample point must be between 0x0-0xFF. Lower Desired Nominal Rate",
                inst, ["nomTimeSeg1_calc","desiredNomRate"]);
        }
        if (inst.nomTimeSeg2_calc < 0 || inst.nomTimeSeg2_calc > 0x7F)
        {
            validation.logError(
                "Nominal Time segment after sample point must be between 0x0-0x7F. Lower Desired Nominal Rate",
                inst, ["nomTimeSeg2_calc","desiredNomRate"]);
        }
        if (inst.nomSynchJumpWidth_calc < 0 || inst.nomSynchJumpWidth_calc > 0x7F)
        {
            validation.logError(
                "Nominal (Re)Synchronization Jump Width Range must be between 0x0-0x7F. Lower Desired Nominal Rate",
                inst, ["nomSynchJumpWidth_calc","desiredNomRate"]);
        }
    }
    if(inst.useCalcDataVal) {
        if (inst.dataRatePrescalar_calc < 0 || inst.dataRatePrescalar_calc > 0x1F)
        {
            validation.logError(
                "Data Baud Rate Pre-scaler must be between 0x0-0x1F. Lower Desired Data Rate",
                inst, ["dataRatePrescalar_calc","desiredDataRate"]);
        }
        if (inst.dataTimeSeg1_calc < 0 || inst.dataTimeSeg1_calc > 0x1F)
        {
            validation.logError(
                "Data Time segment before sample point must be between 0x0-0x1F. Lower Desired Data Rate",
                inst, ["dataTimeSeg1_calc","desiredDataRate"]);
        }
        if (inst.dataTimeSeg2_calc < 0 || inst.dataTimeSeg2_calc > 0xF)
        {
            validation.logError(
                "Data Time segment after sample point must be between 0x0-0xF. Lower Desired Data Rate",
                inst, ["dataTimeSeg2_calc","desiredDataRate"]);
        }
        if (inst.dataSynchJumpWidth_calc < 0 || inst.dataSynchJumpWidth_calc > 0xF)
        {
            validation.logError(
                "Data (Re)Synchronization Jump Width must be between 0x0-0xF. Lower Desired Data Rate",
                inst, ["dataSynchJumpWidth_calc","desiredDataRate"]);
        }
    }
    if (inst.tsPrescalar < 0 || inst.tsPrescalar > 0xF)
    {
        validation.logError(
            "Time stamp Prescaler Value must be between 0x0-0xF",
            inst, "tsPrescalar");
    }
    if (inst.timeoutPreload < 0 || inst.timeoutPreload > 0xFFFF)
    {
        validation.logError(
            "Start value of the Timeout Counter must be between 0x0-0xFFFF",
            inst, "timeoutPreload");
    }
    if (String(inst.interruptFlags).includes("DL_MCAN_INTR_MASK_ALL"))
    {
        if(inst.interruptFlags.length > 1)
        {
            validation.logWarning(
            "Enable All Interrupts is marked, other flags are redundant",
            inst, "interruptFlags");
        }
    }
    if (String(inst.interruptLine0Flag).includes("DL_MCAN_INTR_MASK_ALL"))
    {
        if(inst.interruptLine0Flag.length > 1)
        {
            validation.logWarning(
            "Enable All Interrupts is marked, other flags are redundant",
            inst, "interruptLine0Flag");
        }
    }
    if (String(inst.interruptLine1Flag).includes("DL_MCAN_INTR_MASK_ALL"))
    {
        if(inst.interruptLine1Flag.length > 1)
        {
            validation.logWarning(
            "Enable All Interrupts is marked, other flags are redundant",
            inst, "interruptLine1Flag");
        }
    }

    if (inst.flssa < 0 || inst.flssa > 16384)
    {
        validation.logError(
            "Standard ID Filter List Start Address must be between 0 and 16384",
            inst, "flssa");
    }
    if (inst.lss < 0 || inst.lss > 128)
    {
        validation.logError(
            "No of Standard ID Filters must be between 0 and 128",
            inst, "lss");
    }
    if (inst.flesa < 0 || inst.flesa > 16384)
    {
        validation.logError(
            "Extended ID Filter List Start Address must be between 0 and 4352",
            inst, "flesa");
    }
    if (inst.lse < 0 || inst.lse > 128)
    {
        validation.logError(
            "No of Extended ID Filters must be between 0 and 64",
            inst, "lse");
    }
    if (inst.txStartAddr < 0 || inst.txStartAddr > 4352)
    {
        validation.logError(
            "Tx Buffers Start Address must be between 0 and 4352",
            inst, "txStartAddr");
    }
    if (inst.txBufNum < 0 || inst.txBufNum > 32)
    {
        validation.logError(
            "Number of Dedicated Transmit Buffers must be between 0 and 32",
            inst, "txBufNum");
    }
    if (inst.txFIFOSize < 0 || inst.txFIFOSize > 64)
    {
        validation.logError(
            "No of Tx FIFO Elements must be between 0 and 32",
            inst, "txFIFOSize");
    }
    if (inst.txEventFIFOSize < 0 || inst.txEventFIFOSize > 32)
    {
        validation.logError(
            "Tx Event FIFO Size must be between 0 and 32",
            inst, "txEventFIFOSize");
    }
    if (inst.rxFIFO0startAddr < 0 || inst.rxFIFO0startAddr > 4352)
    {
        validation.logError(
            "Rx FIFO0 Start Address must be between 0 and 4352",
            inst, "rxFIFO0startAddr");
    }
    if (inst.rxFIFO0size < 0 || inst.rxFIFO0size > 64)
    {
        validation.logError(
            "Number of Rx FIFO0 elements must be between 0 and 64",
            inst, "rxFIFO0size");
    }
    if (inst.rxFIFO1startAddr < 0 || inst.rxFIFO1startAddr > 4352)
    {
        validation.logError(
            "Rx FIFO1 Start Address must be between 0 and 4352",
            inst, "rxFIFO1startAddr");
    }
    if (inst.rxFIFO1size < 0 || inst.rxFIFO1size > 64)
    {
        validation.logError(
            "Number of Rx FIFO1 elements must be between 0 and 64",
            inst, "rxFIFO1size");
    }
    if (inst.rxFIFO0waterMark < 0 || inst.rxFIFO0waterMark > 64)
    {
        validation.logError(
            "Rx FIFO0 Watermark must be between 0 and 64",
            inst, "rxFIFO0waterMark");
    }
    if (inst.rxFIFO1waterMark < 0 || inst.rxFIFO1waterMark > 64)
    {
        validation.logError(
            "Rx FIFO1 Watermark must be between 0 and 64",
            inst, "rxFIFO1waterMark");
    }
    if (inst.rxBufStartAddr < 0 || inst.rxBufStartAddr > 4352)
    {
        validation.logError(
            "Rx Buffer Start Address must be between 0 and 4352",
            inst, "rxBufStartAddr");
    }
    let rxBufEndAddr = inst.rxBufStartAddr + (64)*6;
    let rxFIFO0EndAddr = inst.rxFIFO0startAddr + inst.rxFIFO0size*6;
    let rxFIFO1EndAddr = inst.rxFIFO1startAddr + inst.rxFIFO1size*6;
    let txBufEndAddr = inst.txStartAddr + (inst.txBufNum+inst.txFIFOSize)*6;
    let txEventFIFOEndAddr = inst.txEventFIFOStartAddr + inst.txEventFIFOSize*2;
    let stdIDEndAddr = inst.flssa + inst.lss*1;
    let extIDEndAddr = inst.flesa + inst.lse*2;
    // TODO Revied if this need to be displayed or not
    validation.logInfo("RX Buffer Start Address "+ String(inst.rxBufStartAddr) + " End Address " + String(rxBufEndAddr), inst, "rxBufStartAddr");
    validation.logInfo("RX FIFO 0 Start Address "+ String(inst.rxFIFO0startAddr) + " End Address " + String(rxFIFO0EndAddr), inst, "rxFIFO0startAddr");
    validation.logInfo("RX FIFO 1 Start Address "+ String(inst.rxFIFO1startAddr) + " End Address " + String(rxFIFO1EndAddr), inst, "rxFIFO1startAddr");
    validation.logInfo("TX Buffer Start Address "+ String(inst.txStartAddr) + " End Address " + String(txBufEndAddr), inst, "txStartAddr");
    validation.logInfo("TX Event FIFO Start Address "+ String(inst.txEventFIFOStartAddr) + " End Address " + String(txEventFIFOEndAddr), inst, "txEventFIFOStartAddr");
    validation.logInfo("Standard ID Filter List Start Address "+ String(inst.flssa) + " End Address " + String(stdIDEndAddr), inst, "flssa");
    validation.logInfo("Extended ID Filter List Start Address "+ String(inst.flesa) + " End Address " + String(extIDEndAddr), inst, "flesa");

    if(inst.txBufNum + inst.txFIFOSize > 32)
    {
        validation.logError(
            "Sum of TX Buffers and TX FIFO size must be between 0 and 32",
            inst, "txFIFOSize");
    }
}

/*
 *  ======== filterHardware ========
 *  Control RX, TX Pin usage by the user specified dataDirection.
 *
 *  param component - hardware object describing signals and
 *                     resources they're attached to
 *
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    return (Common.typeMatches(component.type, ["MCAN"]));
}


// TODO: (H) ->  this part as added for M0
/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let tx = {
        name              : "txPin",  /* config script name */
        displayName       : "TX Pin", /* GUI name */
        interfaceNames    : ["CANTX"]   /* pinmux tool name */
    };

    let rx = {
        name              : "rxPin",
        displayName       : "RX Pin",
        interfaceNames    : ["CANRX"]
    };

    let resources = [];

    resources.push(rx);
    resources.push(tx);

    let mcan = {
        name          : "peripheral",
        displayName   : "MCAN Peripheral",
        interfaceName : "MCAN",
        resources     : resources,
        signalTypes   : {
            txPin     : ['CANTX'],
            rxPin     : ['CANRX'],
        }
    };
    return [mcan];
}
var mcanModule = {
    peripheralName: "MCAN",
    displayName: "MCAN",
    maxInstances: Common.peripheralCount("MCAN"),
    defaultInstanceName: "MCAN",
    description: "MCAN Peripheral",
    longDescription: `
The **MCAN module** allows you to configure the Controller Area Network
serial communications protocol. The MCAN module supports both classic CAN
and CAN FD (CAN with flexible data-rate) protocols.

Under *MCAN Basic Configuration* users can:
- Enable different CAN options (FD mode, bit rate switching, loopback mode, etc.)
- Enable and configure transmitter delay compensation
- Configure bit timing paramters:
    - Desired nominal bit rate and timing parameters
    - Desired data bit rate and timing parameters
- Configure TX/RX message RAM

Under *MCAN Advanced Configuration* users can configure:
- Additional core configurations such as:
    - Bus monitoring mode
    - Timestamp counter value
    - Time-out counter
    - Accept/Reject Remote or non-matching frames

Check the datasheet of your selected device for more detailed information.
    `,
    filterHardware : filterHardware,
    config: config,
    modules: Common.autoForceModules(["SYSCTL", "Board"]),
    validate: onValidate,
    moduleInstances: (inst) => {
        var interrupts = []

        // TODO: (H)
        // var pinmuxQualMods = Pinmux.getGpioQualificationModInstDefinitions("MCAN", inst)
        var pinmuxQualMods =[]; // TODO: (H)
        for (var pinmuxQualMod of pinmuxQualMods)
        {
            pinmuxQualMod.requiredArgs = {
               qualMode : "GPIO_QUAL_ASYNC",
            }
        }
        interrupts = interrupts.concat(pinmuxQualMods)

        if (inst.registerInterruptLine0)
        {
            interrupts.push(
                {
                    name: "mcanInt0",
                    displayName: "MCAN Interrupt0",
                    moduleName: "/driverlib/interrupt.js",
                    collapsed: true,
                    args: {
                        $name : inst.$name + "_INT0",
                        int : "INT_" + inst.$name + "_0",
                        pinmuxPeripheralModule : "mcan",
                        driverlibInt: Line0IntName
                    }
                }
            )
        }
        if (inst.registerInterruptLine1)
        {
            interrupts.push(
                {
                    name: "mcanInt1",
                    displayName: "MCAN Interrupt1",
                    moduleName: "/driverlib/interrupt.js",
                    collapsed: true,
                    args: {
                        $name : inst.$name + "_INT1",
                        int : "INT_" + inst.$name + "_1",
                        pinmuxPeripheralModule : "mcan",
                        driverlibInt: Line1IntName
                    }
                }
            )
        }
        return interrupts;
    },
    validate    : onValidate,
    templates: {
        boardc : "/ti/driverlib/mcan/MCAN.Board.c.xdt",
        boardh : "/ti/driverlib/mcan/MCAN.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
        Retention: Common.isDeviceM0G(),
    },
    // TODO: (H) -> need pinmux requirements specific to MCAN M0
    // pinmuxRequirements    : Pinmux.mcanPinmuxRequirements
    // TODO: (H) -> this is the new call
    pinmuxRequirements : pinmuxRequirements,
};


// if (mcanModule.maxInstances <= 0)
// {
//     delete mcanModule.pinmuxRequirements;
// }
// else
// {
//     // TODO: (H) Pinmux changes
//     // Pinmux.addCustomPinmuxEnumToConfig(mcanModule)
//     // Pinmux.addPinMuxQualGroupToConfig(mcanModule)
// }

exports = mcanModule;
