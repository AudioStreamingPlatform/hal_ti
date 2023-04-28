
let Common = system.getScript("/ti/driverlib/Common.js");

const LFCLKSourceOptions = {
    "M0G": [
        { name: "LFOSC" },
        { name: "LFXT", displayName: "LF External XTAL" },
        { name: "LFCLK_IN", displayName: "LFCLK Digital In" }
    ],
    "M0L": [
        { name: "LFOSC" }
    ]
};

const MCLKSourceOptions = {
    "M0G": [
        { name: "SYSOSC" },
        { name: "LFCLK" },
        { name: "HSCLK" },
    ],
    "M0L": [
        { name: "SYSOSC" },
        { name: "LFCLK" },
    ]
};

const HFCLKSourceOptions = {
    "M0G": [
        {name: "HFXT", displayName: "HF External XTAL"},
        {name: "HFCLK_IN", displayName: "HFCLK Digital In"}
    ],
    "M0L": [
        {name: "HFCLK_IN", displayName: "HFCLK Digital In"}
    ]
};

const EXCLKSourceOptions = {
    "M0G": [
        { name: "SYSOSC" },
        { name: "ULPCLK" },
        { name: "LFCLK" },
        { name: "MFPCLK" },
        { name: "HFCLK" },
        { name: "SYSPLLOUT1", displayName: "SYSPLL Clock 1" },
    ],
    "M0L": [
        { name: "SYSOSC" },
        { name: "ULPCLK" },
        { name: "LFCLK" },
        { name: "MFPCLK" },
    ]
};

let index = "M0L";
if(Common.isDeviceM0G()){
    index = "M0G";
}


exports = {
    LFCLKSource: LFCLKSourceOptions[index],
    MCLKSource : MCLKSourceOptions[index],
    HFCLKSource : HFCLKSourceOptions[index],
    EXCLKSource : EXCLKSourceOptions[index],
}
