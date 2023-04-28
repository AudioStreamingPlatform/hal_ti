let ADC12_internalSignals = {
    MSPM0G: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH12: "DAC12_OUT",
            CH13: "OPA0 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        },
        ADC1: {
            CH12: "Temperature Sensor",
            CH13: "OPA1 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        }
    },
    // TODO: confirm Lord Business # of instances
    MSPM0L: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH12: "OPA0 output",
            CH13: "OPA1 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        },
    }
}

exports = {
    ADC12_internalSignals: ADC12_internalSignals,
}
