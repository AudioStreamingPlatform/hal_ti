/*****************************************************************************

  Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

   Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#ifndef ti_devices_msp_peripherals_hw_flashctl__include
#define ti_devices_msp_peripherals_hw_flashctl__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp430ww/repos/f65mspnvmnw */
/* MMR revision: 8f145703eea3a7192a353390dcad10aab99c2c6a */
/* Generator revision: 3057c45469f13579bc424ee695ed585528401358
   (MInT: ec7ec7482a60c6871be32db8b378ec27aa4771f6) */

#ifndef __CORTEX_M
  #ifdef __cplusplus
    #define __I  volatile        /*!< Defines 'read only' permissions */
  #else
    #define __I  volatile const  /*!< Defines 'read only' permissions */
  #endif
  #define __O  volatile          /*!< Defines 'write only' permissions */
  #define __IO  volatile         /*!< Defines 'read / write' permissions */

  /* following defines should be used for structure members */
  #define __IM  volatile const   /*! Defines 'read only' structure member permissions */
  #define __OM  volatile         /*! Defines 'write only' structure member permissions */
  #define __IOM  volatile        /*! Defines 'read / write' structure member permissions */
#endif

/* Use standard integer types with explicit width */
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#if defined ( __CC_ARM )
#pragma anon_unions
#endif

/******************************************************************************
* FLASHCTL Registers
******************************************************************************/
#define FLASHCTL_LMGMT_DFT_ATONLY_OFS            ((uint32_t)0x00001500U)
#define FLASHCTL_GEN_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup FLASHCTL_LMGMT_DFT_ATONLY
  @{
*/

typedef struct {
  __IO uint32_t DFTEN;                             /* !< (@ 0x00001500) DFT Enable Register */
  __IO uint32_t DFTCMDCTL;                         /* !< (@ 0x00001504) DFT Command Control Register */
  __IO uint32_t DFTTIMERCTL;                       /* !< (@ 0x00001508) DFT Timer Control Register */
  __IO uint32_t DFTEXECZCTL;                       /* !< (@ 0x0000150C) Flash Wrapper State EXECUTEZ Control Register */
  __IO uint32_t DFTPCLKTESTCTL;                    /* !< (@ 0x00001510) DFT Pump Clock Test Control Register */
  __I  uint32_t DFTPCLKTESTSTAT;                   /* !< (@ 0x00001514) DFT Pump Clock Test Status Register */
       uint32_t RESERVED0[10];
  __IO uint32_t DFTDATARED0;                       /* !< (@ 0x00001540) DFT Data Register Redundant 0 */
  __IO uint32_t DFTDATARED1;                       /* !< (@ 0x00001544) DFT Data Register Redundant 1 */
  __IO uint32_t DFTDATARED2;                       /* !< (@ 0x00001548) DFT Data Register Redundant 2 */
  __IO uint32_t DFTDATARED3;                       /* !< (@ 0x0000154C) DFT Data Register Redundant 3 */
  __IO uint32_t DFTDATARED4;                       /* !< (@ 0x00001550) DFT Data Register Redundant 4 */
  __IO uint32_t DFTDATARED5;                       /* !< (@ 0x00001554) DFT Data Register Redundant 5 */
  __IO uint32_t DFTDATARED6;                       /* !< (@ 0x00001558) DFT Data Register Redundant 6 */
  __IO uint32_t DFTDATARED7;                       /* !< (@ 0x0000155C) DFT Data Register Redundant 7 */
  __IO uint32_t DFTPUMPCTL;                        /* !< (@ 0x00001560) DFT Pump Control Register */
  __IO uint32_t DFTBANKCTL;                        /* !< (@ 0x00001564) DFT Bank Control Register */
       uint32_t RESERVED1[38];
  __IO uint32_t TRIMCTL;                           /* !< (@ 0x00001600) Trim Control Register */
  __IO uint32_t TRIMLOCK;                          /* !< (@ 0x00001604) Trim Lock Register */
  __IO uint32_t TRIMCOMMIT;                        /* !< (@ 0x00001608) Trim Commit Register */
       uint32_t RESERVED2;
  __IO uint32_t PUMPTRIM0;                         /* !< (@ 0x00001610) Pump Trim 0 Register */
  __IO uint32_t PUMPTRIM1;                         /* !< (@ 0x00001614) Pump Trim 1 Register */
  __IO uint32_t PUMPTRIM2;                         /* !< (@ 0x00001618) Pump Trim 2 Register */
  __IO uint32_t PUMPTRIMREAD;                      /* !< (@ 0x0000161C) Pump Read Trim Register */
       uint32_t RESERVED3[4];
  __IO uint32_t BANK0TRIM0;                        /* !< (@ 0x00001630) Bank 0 Trim 0 Register */
  __IO uint32_t BANK0TRIMREAD;                     /* !< (@ 0x00001634) Bank 0 Read Trim Register */
       uint32_t RESERVED4[2];
  __IO uint32_t BANK1TRIM0;                        /* !< (@ 0x00001640) Bank 1 Trim 0 Register */
  __IO uint32_t BANK1TRIMREAD;                     /* !< (@ 0x00001644) Bank 1 Read Trim Register */
       uint32_t RESERVED5[2];
  __IO uint32_t BANK2TRIM0;                        /* !< (@ 0x00001650) Bank 2 Trim 0 Register */
  __IO uint32_t BANK2TRIMREAD;                     /* !< (@ 0x00001654) Bank 2 Read Trim Register */
       uint32_t RESERVED6[2];
  __IO uint32_t BANK3TRIM0;                        /* !< (@ 0x00001660) Bank 3 Trim 0 Register */
  __IO uint32_t BANK3TRIMREAD;                     /* !< (@ 0x00001664) Bank 3 Read Trim Register */
       uint32_t RESERVED7[2];
  __IO uint32_t BANK4TRIM0;                        /* !< (@ 0x00001670) Bank 4 Trim 0 Register */
  __IO uint32_t BANK4TRIMREAD;                     /* !< (@ 0x00001674) Bank 4 Read Trim Register */
} FLASHCTL_LMGMT_DFT_ATONLY_Regs;

/*@}*/ /* end of group FLASHCTL_LMGMT_DFT_ATONLY */

/** @addtogroup FLASHCTL_GEN
  @{
*/

typedef struct {
       uint32_t RESERVED0[1032];
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt Index Register */
       uint32_t RESERVED1;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) Interrupt Mask Register */
       uint32_t RESERVED2;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) Raw Interrupt Status Register */
       uint32_t RESERVED3;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) Masked Interrupt Status Register */
       uint32_t RESERVED4;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) Interrupt Set Register */
       uint32_t RESERVED5;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) Interrupt Clear Register */
       uint32_t RESERVED6[37];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED7[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Hardware Version Description Register */
  __IO uint32_t CMDEXEC;                           /* !< (@ 0x00001100) Command Execute Register */
  __IO uint32_t CMDTYPE;                           /* !< (@ 0x00001104) Command Type Register */
  __IO uint32_t CMDCTL;                            /* !< (@ 0x00001108) Command Control Register */
       uint32_t RESERVED8[5];
  __IO uint32_t CMDADDR;                           /* !< (@ 0x00001120) Command Address Register */
  __IO uint32_t CMDBYTEN;                          /* !< (@ 0x00001124) Command Program Byte Enable Register */
       uint32_t RESERVED9;
  __IO uint32_t CMDDATAINDEX;                      /* !< (@ 0x0000112C) Command Data Index Register */
  __IO uint32_t CMDDATA0;                          /* !< (@ 0x00001130) Command Data Register 0 */
  __IO uint32_t CMDDATA1;                          /* !< (@ 0x00001134) Command Data Register 1 */
  __IO uint32_t CMDDATA2;                          /* !< (@ 0x00001138) Command Data Register 2 */
  __IO uint32_t CMDDATA3;                          /* !< (@ 0x0000113C) Command Data Register Bits 127:96 */
  __IO uint32_t CMDDATA4;                          /* !< (@ 0x00001140) Command Data Register 4 */
  __IO uint32_t CMDDATA5;                          /* !< (@ 0x00001144) Command Data Register 5 */
  __IO uint32_t CMDDATA6;                          /* !< (@ 0x00001148) Command Data Register 6 */
  __IO uint32_t CMDDATA7;                          /* !< (@ 0x0000114C) Command Data Register 7 */
  __IO uint32_t CMDDATA8;                          /* !< (@ 0x00001150) Command Data Register 8 */
  __IO uint32_t CMDDATA9;                          /* !< (@ 0x00001154) Command Data Register 9 */
  __IO uint32_t CMDDATA10;                         /* !< (@ 0x00001158) Command Data Register 10 */
  __IO uint32_t CMDDATA11;                         /* !< (@ 0x0000115C) Command Data Register 11 */
  __IO uint32_t CMDDATA12;                         /* !< (@ 0x00001160) Command Data Register 12 */
  __IO uint32_t CMDDATA13;                         /* !< (@ 0x00001164) Command Data Register 13 */
  __IO uint32_t CMDDATA14;                         /* !< (@ 0x00001168) Command Data Register 14 */
  __IO uint32_t CMDDATA15;                         /* !< (@ 0x0000116C) Command Data Register 15 */
  __IO uint32_t CMDDATA16;                         /* !< (@ 0x00001170) Command Data Register 16 */
  __IO uint32_t CMDDATA17;                         /* !< (@ 0x00001174) Command Data Register 17 */
  __IO uint32_t CMDDATA18;                         /* !< (@ 0x00001178) Command Data Register 18 */
  __IO uint32_t CMDDATA19;                         /* !< (@ 0x0000117C) Command Data Register 19 */
  __IO uint32_t CMDDATA20;                         /* !< (@ 0x00001180) Command Data Register 20 */
  __IO uint32_t CMDDATA21;                         /* !< (@ 0x00001184) Command Data Register 21 */
  __IO uint32_t CMDDATA22;                         /* !< (@ 0x00001188) Command Data Register 22 */
  __IO uint32_t CMDDATA23;                         /* !< (@ 0x0000118C) Command Data Register 23 */
  __IO uint32_t CMDDATA24;                         /* !< (@ 0x00001190) Command Data Register 24 */
  __IO uint32_t CMDDATA25;                         /* !< (@ 0x00001194) Command Data Register 25 */
  __IO uint32_t CMDDATA26;                         /* !< (@ 0x00001198) Command Data Register 26 */
  __IO uint32_t CMDDATA27;                         /* !< (@ 0x0000119C) Command Data Register 27 */
  __IO uint32_t CMDDATA28;                         /* !< (@ 0x000011A0) Command Data Register 28 */
  __IO uint32_t CMDDATA29;                         /* !< (@ 0x000011A4) Command Data Register 29 */
  __IO uint32_t CMDDATA30;                         /* !< (@ 0x000011A8) Command Data Register 30 */
  __IO uint32_t CMDDATA31;                         /* !< (@ 0x000011AC) Command Data Register 31 */
  __IO uint32_t CMDDATAECC0;                       /* !< (@ 0x000011B0) Command Data Register ECC 0 */
  __IO uint32_t CMDDATAECC1;                       /* !< (@ 0x000011B4) Command Data Register ECC 1 */
  __IO uint32_t CMDDATAECC2;                       /* !< (@ 0x000011B8) Command Data Register ECC 2 */
  __IO uint32_t CMDDATAECC3;                       /* !< (@ 0x000011BC) Command Data Register ECC 3 */
  __IO uint32_t CMDDATAECC4;                       /* !< (@ 0x000011C0) Command Data Register ECC 4 */
  __IO uint32_t CMDDATAECC5;                       /* !< (@ 0x000011C4) Command Data Register ECC 5 */
  __IO uint32_t CMDDATAECC6;                       /* !< (@ 0x000011C8) Command Data Register ECC 6 */
  __IO uint32_t CMDDATAECC7;                       /* !< (@ 0x000011CC) Command Data Register ECC 7 */
  __IO uint32_t CMDWEPROTA;                        /* !< (@ 0x000011D0) Command Write Erase Protect A Register */
  __IO uint32_t CMDWEPROTB;                        /* !< (@ 0x000011D4) Command Write Erase Protect B Register */
  __IO uint32_t CMDWEPROTC;                        /* !< (@ 0x000011D8) Command Write Erase Protect C Register */
       uint32_t RESERVED10[13];
  __IO uint32_t CMDWEPROTNM;                       /* !< (@ 0x00001210) Command Write Erase Protect Non-Main Register */
  __IO uint32_t CMDWEPROTTR;                       /* !< (@ 0x00001214) Command Write Erase Protect Trim Register */
  __IO uint32_t CMDWEPROTEN;                       /* !< (@ 0x00001218) Command Write Erase Protect Engr Register */
       uint32_t RESERVED11[101];
  __IO uint32_t CFGCMD;                            /* !< (@ 0x000013B0) Command Configuration Register */
  __IO uint32_t CFGPCNT;                           /* !< (@ 0x000013B4) Pulse Counter Configuration Register */
       uint32_t RESERVED12[6];
  __I  uint32_t STATCMD;                           /* !< (@ 0x000013D0) Command Status Register */
  __I  uint32_t STATADDR;                          /* !< (@ 0x000013D4) Address Status Register */
  __I  uint32_t STATPCNT;                          /* !< (@ 0x000013D8) Pulse Count Status Register */
  __I  uint32_t STATMODE;                          /* !< (@ 0x000013DC) Mode Status Register */
       uint32_t RESERVED13[4];
  __I  uint32_t GBLINFO0;                          /* !< (@ 0x000013F0) Global Information Register 0 */
  __I  uint32_t GBLINFO1;                          /* !< (@ 0x000013F4) Global Information Register 1 */
  __I  uint32_t GBLINFO2;                          /* !< (@ 0x000013F8) Global Information Register 2 */
       uint32_t RESERVED14;
  __I  uint32_t BANK0INFO0;                        /* !< (@ 0x00001400) Bank Information Register 0 for Bank 0 */
  __I  uint32_t BANK0INFO1;                        /* !< (@ 0x00001404) Bank Information Register 1 for Bank 0 */
       uint32_t RESERVED15[2];
  __I  uint32_t BANK1INFO0;                        /* !< (@ 0x00001410) Bank Information Register 0 for Bank 1 */
  __I  uint32_t BANK1INFO1;                        /* !< (@ 0x00001414) Bank Information Register 1 for Bank 1 */
       uint32_t RESERVED16[2];
  __I  uint32_t BANK2INFO0;                        /* !< (@ 0x00001420) Bank Information Register 0 for Bank 2 */
  __I  uint32_t BANK2INFO1;                        /* !< (@ 0x00001424) Bank Information Register 1 for Bank 2 */
       uint32_t RESERVED17[2];
  __I  uint32_t BANK3INFO0;                        /* !< (@ 0x00001430) Bank Information Register 0 for Bank 3 */
  __I  uint32_t BANK3INFO1;                        /* !< (@ 0x00001434) Bank Information Register 1 for Bank 3 */
       uint32_t RESERVED18[2];
  __I  uint32_t BANK4INFO0;                        /* !< (@ 0x00001440) Bank Information Register 0 for Bank 4 */
  __I  uint32_t BANK4INFO1;                        /* !< (@ 0x00001444) Bank Information Register 1 for Bank 4 */
       uint32_t RESERVED19[46];
  FLASHCTL_LMGMT_DFT_ATONLY_Regs  LMGMT_DFT_ATONLY;                  /* !< (@ 0x00001500) */
} FLASHCTL_GEN_Regs;

/*@}*/ /* end of group FLASHCTL_GEN */

/** @addtogroup FLASHCTL
  @{
*/

typedef struct {
  FLASHCTL_GEN_Regs  GEN;                               /* !< (@ 0x00000000) */
} FLASHCTL_Regs;

/*@}*/ /* end of group FLASHCTL */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* FLASHCTL Register Control Bits
******************************************************************************/

/* FLASHCTL_DFTEN Bits */
/* FLASHCTL_DFTEN[ENABLE] Bits */
#define FLASHCTL_DFTEN_ENABLE_OFS                (0)                             /* !< ENABLE Offset */
#define FLASHCTL_DFTEN_ENABLE_MASK               ((uint32_t)0x00000001U)         /* !< Enable Test Features */
#define FLASHCTL_DFTEN_ENABLE_DISABLED           ((uint32_t)0x00000000U)         /* !< Command */
#define FLASHCTL_DFTEN_ENABLE_ENABLED            ((uint32_t)0x00000001U)         /* !< Command */

/* FLASHCTL_DFTCMDCTL Bits */
/* FLASHCTL_DFTCMDCTL[AMX2TDIS] Bits */
#define FLASHCTL_DFTCMDCTL_AMX2TDIS_OFS          (2)                             /* !< AMX2TDIS Offset */
#define FLASHCTL_DFTCMDCTL_AMX2TDIS_MASK         ((uint32_t)0x00000004U)         /* !< 2T address mux disable control.
                                                                                    When set to 1 2T address shifting is
                                                                                    disabled.  This bit should only be
                                                                                    enabled for reads.  Indeterminate
                                                                                    behavior will result if this bit is
                                                                                    set during program/erase.
                                                                                    Furthermore, only reads done via a
                                                                                    READVERIFY command will be guaranteed
                                                                                    to work properly.  Reads via the FBAP
                                                                                    port are not guaranteed to operate. */
#define FLASHCTL_DFTCMDCTL_AMX2TDIS_ENABLE       ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_AMX2TDIS_DISABLE      ((uint32_t)0x00000004U)         /* !< Disable */
/* FLASHCTL_DFTCMDCTL[REDMATCHDIS] Bits */
#define FLASHCTL_DFTCMDCTL_REDMATCHDIS_OFS       (4)                             /* !< REDMATCHDIS Offset */
#define FLASHCTL_DFTCMDCTL_REDMATCHDIS_MASK      ((uint32_t)0x00000010U)         /* !< Disable redundancy matching.  Any
                                                                                    repair configuration encoded into the
                                                                                    bank trim bits is disabled. */
#define FLASHCTL_DFTCMDCTL_REDMATCHDIS_ENABLE    ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_REDMATCHDIS_DISABLE   ((uint32_t)0x00000010U)         /* !< Disable */
/* FLASHCTL_DFTCMDCTL[REDMATCHFORCE] Bits */
#define FLASHCTL_DFTCMDCTL_REDMATCHFORCE_OFS     (5)                             /* !< REDMATCHFORCE Offset */
#define FLASHCTL_DFTCMDCTL_REDMATCHFORCE_MASK    ((uint32_t)0x00000020U)         /* !< Force redundancy match.  If set to
                                                                                    1, repair configuration encoded in
                                                                                    the flash bank trim will be forced
                                                                                    for every access. */
#define FLASHCTL_DFTCMDCTL_REDMATCHFORCE_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_REDMATCHFORCE_ENABLE  ((uint32_t)0x00000020U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[DTBMUXSEL] Bits */
#define FLASHCTL_DFTCMDCTL_DTBMUXSEL_OFS         (28)                            /* !< DTBMUXSEL Offset */
#define FLASHCTL_DFTCMDCTL_DTBMUXSEL_MASK        ((uint32_t)0xF0000000U)         /* !< DTB Mux Select This field will form
                                                                                    the select for the primary DTB mux.
                                                                                    This mux selects up to 16 sets of
                                                                                    32-bit fields of internal signals to
                                                                                    be present to the 32-bit DTB output. */
#define FLASHCTL_DFTCMDCTL_DTBMUXSEL_MINIMUM     ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_DFTCMDCTL_DTBMUXSEL_MAXIMUM     ((uint32_t)0xF0000000U)         /* !< Maximum value */
/* FLASHCTL_DFTCMDCTL[ADDRCNTLDDIS] Bits */
#define FLASHCTL_DFTCMDCTL_ADDRCNTLDDIS_OFS      (8)                             /* !< ADDRCNTLDDIS Offset */
#define FLASHCTL_DFTCMDCTL_ADDRCNTLDDIS_MASK     ((uint32_t)0x00000100U)         /* !< Override address counter enable.
                                                                                    When set, the state machine address
                                                                                    counter will not be loaded when a
                                                                                    command is initiated. */
#define FLASHCTL_DFTCMDCTL_ADDRCNTLDDIS_ENABLE   ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_ADDRCNTLDDIS_DISABLE  ((uint32_t)0x00000100U)         /* !< Disable */
/* FLASHCTL_DFTCMDCTL[PULSECNTLDDIS] Bits */
#define FLASHCTL_DFTCMDCTL_PULSECNTLDDIS_OFS     (9)                             /* !< PULSECNTLDDIS Offset */
#define FLASHCTL_DFTCMDCTL_PULSECNTLDDIS_MASK    ((uint32_t)0x00000200U)         /* !< Override pulse counter enable.
                                                                                    When set, the state machine pulse
                                                                                    counter will not be loaded when a
                                                                                    command is initiated. */
#define FLASHCTL_DFTCMDCTL_PULSECNTLDDIS_ENABLE  ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_PULSECNTLDDIS_DISABLE ((uint32_t)0x00000200U)         /* !< Disable */
/* FLASHCTL_DFTCMDCTL[FORCE1TEN] Bits */
#define FLASHCTL_DFTCMDCTL_FORCE1TEN_OFS         (0)                             /* !< FORCE1TEN Offset */
#define FLASHCTL_DFTCMDCTL_FORCE1TEN_MASK        ((uint32_t)0x00000001U)         /* !< Force 1T Enable - Force 1T access
                                                                                    to regions that are designated as 2T.
                                                                                    Regions designated as 1T will still
                                                                                    be accessed as 1T. */
#define FLASHCTL_DFTCMDCTL_FORCE1TEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_FORCE1TEN_ENABLE      ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[FORCE2TEN] Bits */
#define FLASHCTL_DFTCMDCTL_FORCE2TEN_OFS         (1)                             /* !< FORCE2TEN Offset */
#define FLASHCTL_DFTCMDCTL_FORCE2TEN_MASK        ((uint32_t)0x00000002U)         /* !< Force 2T Enable - Force 2T access
                                                                                    to regions that are designated as 1T.
                                                                                    Regions designated as 2T will still
                                                                                    be accessed as 2T. */
#define FLASHCTL_DFTCMDCTL_FORCE2TEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_FORCE2TEN_ENABLE      ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[DATAPATEN] Bits */
#define FLASHCTL_DFTCMDCTL_DATAPATEN_OFS         (12)                            /* !< DATAPATEN Offset */
#define FLASHCTL_DFTCMDCTL_DATAPATEN_MASK        ((uint32_t)0x00001000U)         /* !< Enable data pattern.  Data pattern
                                                                                    select in DATAPATSEL field will
                                                                                    override data from CMDDATA registers
                                                                                    for use as program or verify data. */
#define FLASHCTL_DFTCMDCTL_DATAPATEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_DATAPATEN_ENABLE      ((uint32_t)0x00001000U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[DATAPATSEL] Bits */
#define FLASHCTL_DFTCMDCTL_DATAPATSEL_OFS        (13)                            /* !< DATAPATSEL Offset */
#define FLASHCTL_DFTCMDCTL_DATAPATSEL_MASK       ((uint32_t)0x0000E000U)         /* !< Select data pattern.  Valid when
                                                                                    DATAPATEN bit is set to 1.  Overrides
                                                                                    CMDDATA registers for program or
                                                                                    verify. */
#define FLASHCTL_DFTCMDCTL_DATAPATSEL_ALL0       ((uint32_t)0x00000000U)         /* !< Set to all 0 */
#define FLASHCTL_DFTCMDCTL_DATAPATSEL_ALL1       ((uint32_t)0x00002000U)         /* !< Set to all 1 */
#define FLASHCTL_DFTCMDCTL_DATAPATSEL_LOGCHKBRD  ((uint32_t)0x00004000U)         /* !< Set to logical checkerboard
                                                                                    (0x01010101...) */
/* FLASHCTL_DFTCMDCTL[ALWAYSINVDATA] Bits */
#define FLASHCTL_DFTCMDCTL_ALWAYSINVDATA_OFS     (16)                            /* !< ALWAYSINVDATA Offset */
#define FLASHCTL_DFTCMDCTL_ALWAYSINVDATA_MASK    ((uint32_t)0x00010000U)         /* !< Invert data always for program or
                                                                                    verify.  This bit only applies when
                                                                                    pattern data is used; i.e. the
                                                                                    DATAPATEN bit is set.  It will have
                                                                                    no effect if CMDDATA is used. */
#define FLASHCTL_DFTCMDCTL_ALWAYSINVDATA_TRUE    ((uint32_t)0x00000000U)         /* !< Use true data */
#define FLASHCTL_DFTCMDCTL_ALWAYSINVDATA_INVERT  ((uint32_t)0x00010000U)         /* !< Use inverted data */
/* FLASHCTL_DFTCMDCTL[ODDWORDINVDATA] Bits */
#define FLASHCTL_DFTCMDCTL_ODDWORDINVDATA_OFS    (17)                            /* !< ODDWORDINVDATA Offset */
#define FLASHCTL_DFTCMDCTL_ODDWORDINVDATA_MASK   ((uint32_t)0x00020000U)         /* !< Invert data at odd bank addresses
                                                                                    for program or verify. This bit only
                                                                                    applies  when pattern data is used;
                                                                                    i.e. the DATAPATEN bit is set.  It
                                                                                    will have no effect if CMDDATA is
                                                                                    used. */
#define FLASHCTL_DFTCMDCTL_ODDWORDINVDATA_TRUE   ((uint32_t)0x00000000U)         /* !< Use true data */
#define FLASHCTL_DFTCMDCTL_ODDWORDINVDATA_INVERT ((uint32_t)0x00020000U)         /* !< Use inverted data */
/* FLASHCTL_DFTCMDCTL[ODDROWINVDATA] Bits */
#define FLASHCTL_DFTCMDCTL_ODDROWINVDATA_OFS     (18)                            /* !< ODDROWINVDATA Offset */
#define FLASHCTL_DFTCMDCTL_ODDROWINVDATA_MASK    ((uint32_t)0x00040000U)         /* !< Invert data at odd row addresses
                                                                                    for program or verify.  The LSB of
                                                                                    the row address is bit [4] of the
                                                                                    bank address.  This bit only applies
                                                                                    when pattern data is used; i.e. the
                                                                                    DATAPATEN bit is set.  It will have
                                                                                    no effect if CMDDATA is used. */
#define FLASHCTL_DFTCMDCTL_ODDROWINVDATA_TRUE    ((uint32_t)0x00000000U)         /* !< Use true data */
#define FLASHCTL_DFTCMDCTL_ODDROWINVDATA_INVERT  ((uint32_t)0x00040000U)         /* !< Use inverted data */
/* FLASHCTL_DFTCMDCTL[STOPVERONFAIL] Bits */
#define FLASHCTL_DFTCMDCTL_STOPVERONFAIL_OFS     (20)                            /* !< STOPVERONFAIL Offset */
#define FLASHCTL_DFTCMDCTL_STOPVERONFAIL_MASK    ((uint32_t)0x00100000U)         /* !< Stop read verify on fail.  If this
                                                                                    bit is set, read verify will halt
                                                                                    when the first verify fail is
                                                                                    detected.  If command is program or
                                                                                    erase, another program or erase pulse
                                                                                    will be executed.  If command is read
                                                                                    verify, comand will terminate. */
#define FLASHCTL_DFTCMDCTL_STOPVERONFAIL_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_STOPVERONFAIL_ENABLE  ((uint32_t)0x00100000U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[PREVEREN] Bits */
#define FLASHCTL_DFTCMDCTL_PREVEREN_OFS          (21)                            /* !< PREVEREN Offset */
#define FLASHCTL_DFTCMDCTL_PREVEREN_MASK         ((uint32_t)0x00200000U)         /* !< Enable verify before program or
                                                                                    erase.  For program, bits already
                                                                                    programmed to the requested value
                                                                                    will be masked.  For erase, sectors
                                                                                    already erased will be masked. */
#define FLASHCTL_DFTCMDCTL_PREVEREN_DISABLE      ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_PREVEREN_ENABLE       ((uint32_t)0x00200000U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[POSTVEREN] Bits */
#define FLASHCTL_DFTCMDCTL_POSTVEREN_OFS         (22)                            /* !< POSTVEREN Offset */
#define FLASHCTL_DFTCMDCTL_POSTVEREN_MASK        ((uint32_t)0x00400000U)         /* !< Enable verify after program or
                                                                                    erase */
#define FLASHCTL_DFTCMDCTL_POSTVEREN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTCMDCTL_POSTVEREN_ENABLE      ((uint32_t)0x00400000U)         /* !< Enable */
/* FLASHCTL_DFTCMDCTL[PROGMASKDIS] Bits */
#define FLASHCTL_DFTCMDCTL_PROGMASKDIS_OFS       (23)                            /* !< PROGMASKDIS Offset */
#define FLASHCTL_DFTCMDCTL_PROGMASKDIS_MASK      ((uint32_t)0x00800000U)         /* !< Disable use of program mask for
                                                                                    programming. Bit masking will not be
                                                                                    used during program verify.  If any
                                                                                    bits fail the verify either before
                                                                                    (prever) or after (postver) the
                                                                                    operation, then all specified flash
                                                                                    entries will receive subsequent
                                                                                    program pulse. */
#define FLASHCTL_DFTCMDCTL_PROGMASKDIS_ENABLE    ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_PROGMASKDIS_DISABLE   ((uint32_t)0x00800000U)         /* !< Disable */
/* FLASHCTL_DFTCMDCTL[ERASEMASKDIS] Bits */
#define FLASHCTL_DFTCMDCTL_ERASEMASKDIS_OFS      (24)                            /* !< ERASEMASKDIS Offset */
#define FLASHCTL_DFTCMDCTL_ERASEMASKDIS_MASK     ((uint32_t)0x01000000U)         /* !< Disable use of erase mask for erase
                                                                                    Bit masking will not be used during
                                                                                    erase verify.  If any sectors fail
                                                                                    the verify either before (prever) or
                                                                                    after (postver) the operation, then
                                                                                    all specified flash sectors will
                                                                                    receive subsequent erase pulse. */
#define FLASHCTL_DFTCMDCTL_ERASEMASKDIS_ENABLE   ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_DFTCMDCTL_ERASEMASKDIS_DISABLE  ((uint32_t)0x01000000U)         /* !< Disable */

/* FLASHCTL_DFTTIMERCTL Bits */
/* FLASHCTL_DFTTIMERCTL[PESETUPTIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PESETUPTIME_OFS     (0)                             /* !< PESETUPTIME Offset */
#define FLASHCTL_DFTTIMERCTL_PESETUPTIME_MASK    ((uint32_t)0x00000001U)         /* !< Program/Erase Setup Time */
#define FLASHCTL_DFTTIMERCTL_PESETUPTIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PESETUPTIME_TWOXFUNCTIONAL ((uint32_t)0x00000001U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PVHVSETUPTIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PVHVSETUPTIME_OFS   (1)                             /* !< PVHVSETUPTIME Offset */
#define FLASHCTL_DFTTIMERCTL_PVHVSETUPTIME_MASK  ((uint32_t)0x00000002U)         /* !< Program VHV Setup Time */
#define FLASHCTL_DFTTIMERCTL_PVHVSETUPTIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PVHVSETUPTIME_TWOXFUNCTIONAL ((uint32_t)0x00000002U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PPVWORDLINETIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PPVWORDLINETIME_OFS (2)                             /* !< PPVWORDLINETIME Offset */
#define FLASHCTL_DFTTIMERCTL_PPVWORDLINETIME_MASK ((uint32_t)0x00000004U)         /* !< Program and Program Verify Wordline
                                                                                    Switching Time */
#define FLASHCTL_DFTTIMERCTL_PPVWORDLINETIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PPVWORDLINETIME_TWOXFUNCTIONAL ((uint32_t)0x00000004U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PEHOLDTIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PEHOLDTIME_OFS      (3)                             /* !< PEHOLDTIME Offset */
#define FLASHCTL_DFTTIMERCTL_PEHOLDTIME_MASK     ((uint32_t)0x00000008U)         /* !< Program/Erase Hold Time */
#define FLASHCTL_DFTTIMERCTL_PEHOLDTIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PEHOLDTIME_TWOXFUNCTIONAL ((uint32_t)0x00000008U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PEVSETUPTIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PEVSETUPTIME_OFS    (5)                             /* !< PEVSETUPTIME Offset */
#define FLASHCTL_DFTTIMERCTL_PEVSETUPTIME_MASK   ((uint32_t)0x00000020U)         /* !< Program/Erase Verify Setup Time */
#define FLASHCTL_DFTTIMERCTL_PEVSETUPTIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PEVSETUPTIME_TWOXFUNCTIONAL ((uint32_t)0x00000020U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PEVMODETIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PEVMODETIME_OFS     (4)                             /* !< PEVMODETIME Offset */
#define FLASHCTL_DFTTIMERCTL_PEVMODETIME_MASK    ((uint32_t)0x00000010U)         /* !< Program/Erase Verify Mode Change
                                                                                    Time */
#define FLASHCTL_DFTTIMERCTL_PEVMODETIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PEVMODETIME_TWOXFUNCTIONAL ((uint32_t)0x00000010U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PEVHOLDTIME] Bits */
#define FLASHCTL_DFTTIMERCTL_PEVHOLDTIME_OFS     (6)                             /* !< PEVHOLDTIME Offset */
#define FLASHCTL_DFTTIMERCTL_PEVHOLDTIME_MASK    ((uint32_t)0x00000040U)         /* !< Program/Erase Verify Hold Time */
#define FLASHCTL_DFTTIMERCTL_PEVHOLDTIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PEVHOLDTIME_TWOXFUNCTIONAL ((uint32_t)0x00000040U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[READMODETIME] Bits */
#define FLASHCTL_DFTTIMERCTL_READMODETIME_OFS    (7)                             /* !< READMODETIME Offset */
#define FLASHCTL_DFTTIMERCTL_READMODETIME_MASK   ((uint32_t)0x00000080U)         /* !< Read Mode Change Time */
#define FLASHCTL_DFTTIMERCTL_READMODETIME_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_READMODETIME_TWOXFUNCTIONAL ((uint32_t)0x00000080U)         /* !< Use 2x the hard-wired (functional)
                                                                                    time value */
/* FLASHCTL_DFTTIMERCTL[PEPULSETIMEOVR] Bits */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEOVR_OFS  (8)                             /* !< PEPULSETIMEOVR Offset */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEOVR_MASK ((uint32_t)0x00000100U)         /* !< Override Program/Erase Pulse Time
                                                                                    If set, this will force the program
                                                                                    or erase pulse time to be overridden
                                                                                    with the value in the PEPULSETIMEVAL
                                                                                    field.  If not set, then a hard-coded
                                                                                    value will be used for this pulse
                                                                                    time. */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEOVR_FUNCTIONAL ((uint32_t)0x00000000U)         /* !< Use hard-wired (Functional) timer
                                                                                    value */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEOVR_OVERRIDE ((uint32_t)0x00000100U)         /* !< Use value from the PE_PULSE_TIME
                                                                                    field for time value */
/* FLASHCTL_DFTTIMERCTL[PEPULSETIMEVAL] Bits */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEVAL_OFS  (12)                            /* !< PEPULSETIMEVAL Offset */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEVAL_MASK ((uint32_t)0x0FFFF000U)         /* !< Program/Erase Pulse Time Value If
                                                                                    operation is a program, this value
                                                                                    gets loaded into bits [15:0] of the
                                                                                    timer when the PEPULSETIMEVALOVR
                                                                                    field is set to 1. If operation is an
                                                                                    erase, this value gets loaded into
                                                                                    bits [19:4] of the timer when the
                                                                                    PEPULSETIMEVALOVR field is set to 1. */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEVAL_MINIMUM ((uint32_t)0x00001000U)         /* !< Minimum value */
#define FLASHCTL_DFTTIMERCTL_PEPULSETIMEVAL_MAXIMUM ((uint32_t)0x0FFFF000U)         /* !< Maximum value */
/* FLASHCTL_DFTTIMERCTL[TIMERCLOCKOVR] Bits */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_OFS   (28)                            /* !< TIMERCLOCKOVR Offset */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_MASK  ((uint32_t)0x70000000U)         /* !< Override Timer clock frequency
                                                                                    using an ICG-based clock divide
                                                                                    mechanism.  To divide the timer
                                                                                    clock, pulses can be skipped based on
                                                                                    settings in this field. By default,
                                                                                    this field is 0, which corresponds to
                                                                                    no division on the timer clock. */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_NODIVIDE ((uint32_t)0x00000000U)         /* !< No divide on timer clock. */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY2 ((uint32_t)0x10000000U)         /* !< Divide timer clock by 2 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY3 ((uint32_t)0x20000000U)         /* !< Divide timer clock by 3 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY4 ((uint32_t)0x30000000U)         /* !< Divide timer clock by 4 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY5 ((uint32_t)0x40000000U)         /* !< Divide timer clock by 5 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY6 ((uint32_t)0x50000000U)         /* !< Divide timer clock by 6 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY7 ((uint32_t)0x60000000U)         /* !< Divide timer clock by 7 */
#define FLASHCTL_DFTTIMERCTL_TIMERCLOCKOVR_DIVIDEBY8 ((uint32_t)0x70000000U)         /* !< Divide timer clock by 8 */

/* FLASHCTL_DFTEXECZCTL Bits */
/* FLASHCTL_DFTEXECZCTL[EXEZOVREN] Bits */
#define FLASHCTL_DFTEXECZCTL_EXEZOVREN_OFS       (0)                             /* !< EXEZOVREN Offset */
#define FLASHCTL_DFTEXECZCTL_EXEZOVREN_MASK      ((uint32_t)0x00000001U)         /* !< Enable override of EXECUTEZ Note
                                                                                    that when this bit is set, NoWrapper
                                                                                    has control of the bank pins. */
#define FLASHCTL_DFTEXECZCTL_EXEZOVREN_DISABLE   ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTEXECZCTL_EXEZOVREN_ENABLE    ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_DFTEXECZCTL[EXEZ_OVR] Bits */
#define FLASHCTL_DFTEXECZCTL_EXEZ_OVR_OFS        (1)                             /* !< EXEZ_OVR Offset */
#define FLASHCTL_DFTEXECZCTL_EXEZ_OVR_MASK       ((uint32_t)0x00000002U)         /* !< Override value to be applied to
                                                                                    EXECUTEZ */
#define FLASHCTL_DFTEXECZCTL_EXEZ_OVR_ZERO       ((uint32_t)0x00000000U)         /* !< Set EXECUTEZ to 0 */
#define FLASHCTL_DFTEXECZCTL_EXEZ_OVR_ONE        ((uint32_t)0x00000002U)         /* !< Set EXECUTEZ to 1 */

/* FLASHCTL_DFTPCLKTESTCTL Bits */
/* FLASHCTL_DFTPCLKTESTCTL[ENABLE] Bits */
#define FLASHCTL_DFTPCLKTESTCTL_ENABLE_OFS       (0)                             /* !< ENABLE Offset */
#define FLASHCTL_DFTPCLKTESTCTL_ENABLE_MASK      ((uint32_t)0x00000001U)         /* !< Enable the state machine which
                                                                                    sequences measurement of pump clock
                                                                                    frequency. */
#define FLASHCTL_DFTPCLKTESTCTL_ENABLE_DISABLE   ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTPCLKTESTCTL_ENABLE_ENABLE    ((uint32_t)0x00000001U)         /* !< Enable */

/* FLASHCTL_DFTPCLKTESTSTAT Bits */
/* FLASHCTL_DFTPCLKTESTSTAT[BUSY] Bits */
#define FLASHCTL_DFTPCLKTESTSTAT_BUSY_OFS        (0)                             /* !< BUSY Offset */
#define FLASHCTL_DFTPCLKTESTSTAT_BUSY_MASK       ((uint32_t)0x00000001U)         /* !< Indicates that a pump clock
                                                                                    measurement is in progress. */
#define FLASHCTL_DFTPCLKTESTSTAT_BUSY_COMPLETE   ((uint32_t)0x00000000U)         /* !< Indicates test complete */
#define FLASHCTL_DFTPCLKTESTSTAT_BUSY_INPROGRESS ((uint32_t)0x00000001U)         /* !< Indicates test in progress */
/* FLASHCTL_DFTPCLKTESTSTAT[CLOCKCNT] Bits */
#define FLASHCTL_DFTPCLKTESTSTAT_CLOCKCNT_OFS    (4)                             /* !< CLOCKCNT Offset */
#define FLASHCTL_DFTPCLKTESTSTAT_CLOCKCNT_MASK   ((uint32_t)0x0000FFF0U)         /* !< Indicates the core clock count
                                                                                    captured during the pump clock
                                                                                    measurement. */
#define FLASHCTL_DFTPCLKTESTSTAT_CLOCKCNT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum count value */
#define FLASHCTL_DFTPCLKTESTSTAT_CLOCKCNT_MAXIMUM ((uint32_t)0x0000FFF0U)         /* !< Maximum count value */

/* FLASHCTL_DFTDATARED0 Bits */
/* FLASHCTL_DFTDATARED0[VAL] Bits */
#define FLASHCTL_DFTDATARED0_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED0_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED1 Bits */
/* FLASHCTL_DFTDATARED1[VAL] Bits */
#define FLASHCTL_DFTDATARED1_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED1_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED2 Bits */
/* FLASHCTL_DFTDATARED2[VAL] Bits */
#define FLASHCTL_DFTDATARED2_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED2_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED3 Bits */
/* FLASHCTL_DFTDATARED3[VAL] Bits */
#define FLASHCTL_DFTDATARED3_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED3_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED4 Bits */
/* FLASHCTL_DFTDATARED4[VAL] Bits */
#define FLASHCTL_DFTDATARED4_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED4_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED5 Bits */
/* FLASHCTL_DFTDATARED5[VAL] Bits */
#define FLASHCTL_DFTDATARED5_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED5_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED6 Bits */
/* FLASHCTL_DFTDATARED6[VAL] Bits */
#define FLASHCTL_DFTDATARED6_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED6_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTDATARED7 Bits */
/* FLASHCTL_DFTDATARED7[VAL] Bits */
#define FLASHCTL_DFTDATARED7_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_DFTDATARED7_VAL_MASK            ((uint32_t)0x0000000FU)         /* !< Data for redundant bits */

/* FLASHCTL_DFTPUMPCTL Bits */
/* FLASHCTL_DFTPUMPCTL[PUMPCLKEN] Bits */
#define FLASHCTL_DFTPUMPCTL_PUMPCLKEN_OFS        (8)                             /* !< PUMPCLKEN Offset */
#define FLASHCTL_DFTPUMPCTL_PUMPCLKEN_MASK       ((uint32_t)0x00000100U)         /* !< Allows direct control of the pump
                                                                                    oscillator which is used to generate
                                                                                    pumpclk. Normally, enable/disable of
                                                                                    pumpclk is under NoWrapper state
                                                                                    machine control.  This bit allows
                                                                                    system to enable the clock
                                                                                    independently. */
#define FLASHCTL_DFTPUMPCTL_PUMPCLKEN_HWCTL      ((uint32_t)0x00000000U)         /* !< Allow pump clock oscillator to be
                                                                                    controlled by hardware. */
#define FLASHCTL_DFTPUMPCTL_PUMPCLKEN_ENABLE     ((uint32_t)0x00000100U)         /* !< Force pump clock oscillator to be
                                                                                    enabled. */
/* FLASHCTL_DFTPUMPCTL[CONFIGPMP] Bits */
#define FLASHCTL_DFTPUMPCTL_CONFIGPMP_OFS        (12)                            /* !< CONFIGPMP Offset */
#define FLASHCTL_DFTPUMPCTL_CONFIGPMP_MASK       ((uint32_t)0x0000F000U)         /* !< Pump configuration control. LP, HP
                                                                                    operation */
/* FLASHCTL_DFTPUMPCTL[SSEN] Bits */
#define FLASHCTL_DFTPUMPCTL_SSEN_OFS             (9)                             /* !< SSEN Offset */
#define FLASHCTL_DFTPUMPCTL_SSEN_MASK            ((uint32_t)0x00000200U)         /* !< Dither control for oscillator
                                                                                    Enumeration: 0: Disable Dither 1:
                                                                                    Enable Dither */
#define FLASHCTL_DFTPUMPCTL_SSEN_DISABLE         ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_DFTPUMPCTL_SSEN_ENABLE          ((uint32_t)0x00000200U)         /* !< Enable */
/* FLASHCTL_DFTPUMPCTL[IREFEVCTL] Bits */
#define FLASHCTL_DFTPUMPCTL_IREFEVCTL_OFS        (16)                            /* !< IREFEVCTL Offset */
#define FLASHCTL_DFTPUMPCTL_IREFEVCTL_MASK       ((uint32_t)0x00070000U)         /* !< IREFEV control IREFVRD, REFTC,
                                                                                    IREFCONST, IREFCCOR blocks in IREFEV */
/* FLASHCTL_DFTPUMPCTL[TCR] Bits */
#define FLASHCTL_DFTPUMPCTL_TCR_OFS              (0)                             /* !< TCR Offset */
#define FLASHCTL_DFTPUMPCTL_TCR_MASK             ((uint32_t)0x0000007FU)         /* !< TCR test mode to be applied to the
                                                                                    pump */
#define FLASHCTL_DFTPUMPCTL_TCR_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_DFTPUMPCTL_TCR_MAXIMUM          ((uint32_t)0x0000007FU)         /* !< Maximum value */

/* FLASHCTL_DFTBANKCTL Bits */
/* FLASHCTL_DFTBANKCTL[TCR] Bits */
#define FLASHCTL_DFTBANKCTL_TCR_OFS              (0)                             /* !< TCR Offset */
#define FLASHCTL_DFTBANKCTL_TCR_MASK             ((uint32_t)0x0000007FU)         /* !< TCR test mode to be applied to the
                                                                                    bank */
#define FLASHCTL_DFTBANKCTL_TCR_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_DFTBANKCTL_TCR_MAXIMUM          ((uint32_t)0x0000007FU)         /* !< Maximum value */
/* FLASHCTL_DFTBANKCTL[TEZ] Bits */
#define FLASHCTL_DFTBANKCTL_TEZ_OFS              (8)                             /* !< TEZ Offset */
#define FLASHCTL_DFTBANKCTL_TEZ_MASK             ((uint32_t)0x00000100U)         /* !< When set, TEZ is asserted to the
                                                                                    flash banks.  Which banks get the
                                                                                    asserted  signal is determined by the
                                                                                    BANKSELECT field in CMDCTL. 0x0 Do no
                                                                                    assert TEZ 0x1 Assert TEZ */
#define FLASHCTL_DFTBANKCTL_TEZ_ASSERT           ((uint32_t)0x00000000U)         /* !< Assert TEZ */
#define FLASHCTL_DFTBANKCTL_TEZ_NEGATE           ((uint32_t)0x00000100U)         /* !< Do not assert TEZ */

/* FLASHCTL_TRIMCTL Bits */
/* FLASHCTL_TRIMCTL[ENABLE] Bits */
#define FLASHCTL_TRIMCTL_ENABLE_OFS              (0)                             /* !< ENABLE Offset */
#define FLASHCTL_TRIMCTL_ENABLE_MASK             ((uint32_t)0x00000001U)         /* !< Indicate that Bank and Pump trim
                                                                                    values are valid. */
#define FLASHCTL_TRIMCTL_ENABLE_INVALID          ((uint32_t)0x00000000U)         /* !< Trim data is not valid */
#define FLASHCTL_TRIMCTL_ENABLE_VALID            ((uint32_t)0x00000001U)         /* !< Trim data is valid */

/* FLASHCTL_TRIMLOCK Bits */
/* FLASHCTL_TRIMLOCK[TRIMLOCKREAD] Bits */
#define FLASHCTL_TRIMLOCK_TRIMLOCKREAD_OFS       (0)                             /* !< TRIMLOCKREAD Offset */
#define FLASHCTL_TRIMLOCK_TRIMLOCKREAD_MASK      ((uint32_t)0x00000001U)         /* !< This bit controls the PUMPTRIMREAD
                                                                                    and BANK*TRIMREAD registers. */
#define FLASHCTL_TRIMLOCK_TRIMLOCKREAD_UNLOCKED  ((uint32_t)0x00000000U)         /* !< *TRIMREAD registers are open for
                                                                                    write. */
#define FLASHCTL_TRIMLOCK_TRIMLOCKREAD_LOCKED    ((uint32_t)0x00000001U)         /* !< *TRIMREAD registers are locked from
                                                                                    write */
/* FLASHCTL_TRIMLOCK[TRIMLOCKOTHER] Bits */
#define FLASHCTL_TRIMLOCK_TRIMLOCKOTHER_OFS      (1)                             /* !< TRIMLOCKOTHER Offset */
#define FLASHCTL_TRIMLOCK_TRIMLOCKOTHER_MASK     ((uint32_t)0x00000002U)         /* !< This bit controls the PUMPTRIM and
                                                                                    BANK*TRIM registers. */
#define FLASHCTL_TRIMLOCK_TRIMLOCKOTHER_UNLOCKED ((uint32_t)0x00000000U)         /* !< *TRIM registers are open for write. */
#define FLASHCTL_TRIMLOCK_TRIMLOCKOTHER_LOCKED   ((uint32_t)0x00000002U)         /* !< *TRIM registers are locked from
                                                                                    write */

/* FLASHCTL_TRIMCOMMIT Bits */
/* FLASHCTL_TRIMCOMMIT[TRIMCOMMITREAD] Bits */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITREAD_OFS   (0)                             /* !< TRIMCOMMITREAD Offset */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITREAD_MASK  ((uint32_t)0x00000001U)         /* !< This bit controls the PUMPTRIMREAD
                                                                                    and BANK*TRIMREAD registers. */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITREAD_UNCOMMITTED ((uint32_t)0x00000000U)         /* !< *TRIMREAD registers are not
                                                                                    committed. */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITREAD_COMMITTED ((uint32_t)0x00000001U)         /* !< *TRIMREAD registers are committed */
/* FLASHCTL_TRIMCOMMIT[TRIMCOMMITOTHER] Bits */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITOTHER_OFS  (1)                             /* !< TRIMCOMMITOTHER Offset */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITOTHER_MASK ((uint32_t)0x00000002U)         /* !< This bit controls the PUMPTRIM and
                                                                                    BANK*TRIM registers. */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITOTHER_UNCOMMITTED ((uint32_t)0x00000000U)         /* !< *TRIM registers are not committed. */
#define FLASHCTL_TRIMCOMMIT_TRIMCOMMITOTHER_COMMITTED ((uint32_t)0x00000002U)         /* !< *TRIM registers are committed */

/* FLASHCTL_PUMPTRIM0 Bits */
/* FLASHCTL_PUMPTRIM0[PUMPVHVCTERS] Bits */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTERS_OFS      (0)                             /* !< PUMPVHVCTERS Offset */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTERS_MASK     ((uint32_t)0x000003FFU)         /* !< VHVCT pump trim value for erase */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTERS_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVHVCTERS] */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTERS_MAXIMUM  ((uint32_t)0x000003FFU)         /* !< Maximum value of [PUMPVHVCTERS] */
/* FLASHCTL_PUMPTRIM0[PUMPVHVCTPV] Bits */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTPV_OFS       (16)                            /* !< PUMPVHVCTPV Offset */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTPV_MASK      ((uint32_t)0x03FF0000U)         /* !< VHVCT pump trim value for program
                                                                                    verify */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTPV_MINIMUM   ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVHVCTPV] */
#define FLASHCTL_PUMPTRIM0_PUMPVHVCTPV_MAXIMUM   ((uint32_t)0x03FF0000U)         /* !< Maximum value of [PUMPVHVCTPV] */

/* FLASHCTL_PUMPTRIM1 Bits */
/* FLASHCTL_PUMPTRIM1[PUMPVHVCTPGM] Bits */
#define FLASHCTL_PUMPTRIM1_PUMPVHVCTPGM_OFS      (0)                             /* !< PUMPVHVCTPGM Offset */
#define FLASHCTL_PUMPTRIM1_PUMPVHVCTPGM_MASK     ((uint32_t)0x000003FFU)         /* !< VHVCT pump trim value for program */
#define FLASHCTL_PUMPTRIM1_PUMPVHVCTPGM_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVHVCTPGM] */
#define FLASHCTL_PUMPTRIM1_PUMPVHVCTPGM_MAXIMUM  ((uint32_t)0x000003FFU)         /* !< Maximum value of [PUMPVHVCTPGM] */
/* FLASHCTL_PUMPTRIM1[PUMPIREFTCCT] Bits */
#define FLASHCTL_PUMPTRIM1_PUMPIREFTCCT_OFS      (10)                            /* !< PUMPIREFTCCT Offset */
#define FLASHCTL_PUMPTRIM1_PUMPIREFTCCT_MASK     ((uint32_t)0x00007C00U)         /* !< IREFTCCT pump trim value */
#define FLASHCTL_PUMPTRIM1_PUMPIREFTCCT_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPIREFTCCT] */
#define FLASHCTL_PUMPTRIM1_PUMPIREFTCCT_MAXIMUM  ((uint32_t)0x00007C00U)         /* !< Maximum value of [PUMPIREFTCCT] */
/* FLASHCTL_PUMPTRIM1[PUMPIREFVRDCT] Bits */
#define FLASHCTL_PUMPTRIM1_PUMPIREFVRDCT_OFS     (16)                            /* !< PUMPIREFVRDCT Offset */
#define FLASHCTL_PUMPTRIM1_PUMPIREFVRDCT_MASK    ((uint32_t)0x001F0000U)         /* !< IREFVRDCT pump trim value */
#define FLASHCTL_PUMPTRIM1_PUMPIREFVRDCT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPIREFVRDCT] */
#define FLASHCTL_PUMPTRIM1_PUMPIREFVRDCT_MAXIMUM ((uint32_t)0x001F0000U)         /* !< Maximum value of [PUMPIREFVRDCT] */
/* FLASHCTL_PUMPTRIM1[PUMPVINHCT] Bits */
#define FLASHCTL_PUMPTRIM1_PUMPVINHCT_OFS        (21)                            /* !< PUMPVINHCT Offset */
#define FLASHCTL_PUMPTRIM1_PUMPVINHCT_MASK       ((uint32_t)0x07E00000U)         /* !< VINHCT pump trim value */
#define FLASHCTL_PUMPTRIM1_PUMPVINHCT_MINIMUM    ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVINHCT] */
#define FLASHCTL_PUMPTRIM1_PUMPVINHCT_MAXIMUM    ((uint32_t)0x07E00000U)         /* !< Maximum value of [PUMPVINHCT] */

/* FLASHCTL_PUMPTRIM2 Bits */
/* FLASHCTL_PUMPTRIM2[PUMPVINHHICCORCT] Bits */
#define FLASHCTL_PUMPTRIM2_PUMPVINHHICCORCT_OFS  (0)                             /* !< PUMPVINHHICCORCT Offset */
#define FLASHCTL_PUMPTRIM2_PUMPVINHHICCORCT_MASK ((uint32_t)0x0000001FU)         /* !< VINHHICCORCT pump trim value */
#define FLASHCTL_PUMPTRIM2_PUMPVINHHICCORCT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVINHHICCORCT] */
#define FLASHCTL_PUMPTRIM2_PUMPVINHHICCORCT_MAXIMUM ((uint32_t)0x0000001FU)         /* !< Maximum value of [PUMPVINHHICCORCT] */
/* FLASHCTL_PUMPTRIM2[PUMPVINLOWCCORCT] Bits */
#define FLASHCTL_PUMPTRIM2_PUMPVINLOWCCORCT_OFS  (5)                             /* !< PUMPVINLOWCCORCT Offset */
#define FLASHCTL_PUMPTRIM2_PUMPVINLOWCCORCT_MASK ((uint32_t)0x000003E0U)         /* !< VINLOWCCORCT pump trim value */
#define FLASHCTL_PUMPTRIM2_PUMPVINLOWCCORCT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVINLOWCCORCT] */
#define FLASHCTL_PUMPTRIM2_PUMPVINLOWCCORCT_MAXIMUM ((uint32_t)0x000003E0U)         /* !< Maximum value of [PUMPVINLOWCCORCT] */
/* FLASHCTL_PUMPTRIM2[PUMPVSLCT] Bits */
#define FLASHCTL_PUMPTRIM2_PUMPVSLCT_OFS         (10)                            /* !< PUMPVSLCT Offset */
#define FLASHCTL_PUMPTRIM2_PUMPVSLCT_MASK        ((uint32_t)0x0000FC00U)         /* !< VSLCT pump trim value */
#define FLASHCTL_PUMPTRIM2_PUMPVSLCT_MINIMUM     ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVSLCT] */
#define FLASHCTL_PUMPTRIM2_PUMPVSLCT_MAXIMUM     ((uint32_t)0x0000FC00U)         /* !< Maximum value of [PUMPVSLCT] */
/* FLASHCTL_PUMPTRIM2[PUMPVWLCT] Bits */
#define FLASHCTL_PUMPTRIM2_PUMPVWLCT_OFS         (16)                            /* !< PUMPVWLCT Offset */
#define FLASHCTL_PUMPTRIM2_PUMPVWLCT_MASK        ((uint32_t)0x003F0000U)         /* !< VWLCT pump trim value */
#define FLASHCTL_PUMPTRIM2_PUMPVWLCT_MINIMUM     ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVWLCT] */
#define FLASHCTL_PUMPTRIM2_PUMPVWLCT_MAXIMUM     ((uint32_t)0x003F0000U)         /* !< Maximum value of [PUMPVWLCT] */
/* FLASHCTL_PUMPTRIM2[PUMPFOSCCT] Bits */
#define FLASHCTL_PUMPTRIM2_PUMPFOSCCT_OFS        (22)                            /* !< PUMPFOSCCT Offset */
#define FLASHCTL_PUMPTRIM2_PUMPFOSCCT_MASK       ((uint32_t)0x0FC00000U)         /* !< FOSCCT pump trim value */
#define FLASHCTL_PUMPTRIM2_PUMPFOSCCT_MINIMUM    ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPFOSCCT] */
#define FLASHCTL_PUMPTRIM2_PUMPFOSCCT_MAXIMUM    ((uint32_t)0x0FC00000U)         /* !< Maximum value of [PUMPFOSCCT] */

/* FLASHCTL_PUMPTRIMREAD Bits */
/* FLASHCTL_PUMPTRIMREAD[PUMPIREFCT] Bits */
#define FLASHCTL_PUMPTRIMREAD_PUMPIREFCT_OFS     (0)                             /* !< PUMPIREFCT Offset */
#define FLASHCTL_PUMPTRIMREAD_PUMPIREFCT_MASK    ((uint32_t)0x0000000FU)         /* !< IREFCT pump trim value */
#define FLASHCTL_PUMPTRIMREAD_PUMPIREFCT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPIREFCT] */
#define FLASHCTL_PUMPTRIMREAD_PUMPIREFCT_MAXIMUM ((uint32_t)0x0000000FU)         /* !< Maximum value of [PUMPIREFCT] */
/* FLASHCTL_PUMPTRIMREAD[PUMPVREADCT] Bits */
#define FLASHCTL_PUMPTRIMREAD_PUMPVREADCT_OFS    (4)                             /* !< PUMPVREADCT Offset */
#define FLASHCTL_PUMPTRIMREAD_PUMPVREADCT_MASK   ((uint32_t)0x000001F0U)         /* !< VREADCT pump trim value */
#define FLASHCTL_PUMPTRIMREAD_PUMPVREADCT_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVREADCT] */
#define FLASHCTL_PUMPTRIMREAD_PUMPVREADCT_MAXIMUM ((uint32_t)0x000001F0U)         /* !< Maximum value of [PUMPVREADCT] */
/* FLASHCTL_PUMPTRIMREAD[PUMPVCGCT] Bits */
#define FLASHCTL_PUMPTRIMREAD_PUMPVCGCT_OFS      (9)                             /* !< PUMPVCGCT Offset */
#define FLASHCTL_PUMPTRIMREAD_PUMPVCGCT_MASK     ((uint32_t)0x00003E00U)         /* !< VCGCT pump trim value */
#define FLASHCTL_PUMPTRIMREAD_PUMPVCGCT_MINIMUM  ((uint32_t)0x00000000U)         /* !< Minimum value of [PUMPVCGCT] */
#define FLASHCTL_PUMPTRIMREAD_PUMPVCGCT_MAXIMUM  ((uint32_t)0x00003E00U)         /* !< Maximum value of [PUMPVCGCT] */

/* FLASHCTL_BANK0TRIM0 Bits */
/* FLASHCTL_BANK0TRIM0[ODDWLSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_ODDWLSTRESSEN_OFS    (12)                            /* !< ODDWLSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_ODDWLSTRESSEN_MASK   ((uint32_t)0x00001000U)         /* !< Odd word line stress enable */
#define FLASHCTL_BANK0TRIM0_ODDWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_ODDWLSTRESSEN_ENABLED ((uint32_t)0x00001000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[EVENWLSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_EVENWLSTRESSEN_OFS   (13)                            /* !< EVENWLSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_EVENWLSTRESSEN_MASK  ((uint32_t)0x00002000U)         /* !< Even word line stress enable */
#define FLASHCTL_BANK0TRIM0_EVENWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_EVENWLSTRESSEN_ENABLED ((uint32_t)0x00002000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[ODDBLSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_ODDBLSTRESSEN_OFS    (14)                            /* !< ODDBLSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_ODDBLSTRESSEN_MASK   ((uint32_t)0x00004000U)         /* !< Odd bit line stress enable */
#define FLASHCTL_BANK0TRIM0_ODDBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_ODDBLSTRESSEN_ENABLED ((uint32_t)0x00004000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[EVENBLSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_EVENBLSTRESSEN_OFS   (15)                            /* !< EVENBLSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_EVENBLSTRESSEN_MASK  ((uint32_t)0x00008000U)         /* !< Even bit line stress enable */
#define FLASHCTL_BANK0TRIM0_EVENBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_EVENBLSTRESSEN_ENABLED ((uint32_t)0x00008000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[ODDCGSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_ODDCGSTRESSEN_OFS    (16)                            /* !< ODDCGSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_ODDCGSTRESSEN_MASK   ((uint32_t)0x00010000U)         /* !< Odd control gate stress enable */
#define FLASHCTL_BANK0TRIM0_ODDCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_ODDCGSTRESSEN_ENABLED ((uint32_t)0x00010000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[EVENCGSTRESSEN] Bits */
#define FLASHCTL_BANK0TRIM0_EVENCGSTRESSEN_OFS   (17)                            /* !< EVENCGSTRESSEN Offset */
#define FLASHCTL_BANK0TRIM0_EVENCGSTRESSEN_MASK  ((uint32_t)0x00020000U)         /* !< Even control gate stress enable */
#define FLASHCTL_BANK0TRIM0_EVENCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_EVENCGSTRESSEN_ENABLED ((uint32_t)0x00020000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[RDERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK0TRIM0_RDERSPOSTVERIFY_OFS  (18)                            /* !< RDERSPOSTVERIFY Offset */
#define FLASHCTL_BANK0TRIM0_RDERSPOSTVERIFY_MASK ((uint32_t)0x00040000U)         /* !< Use READ mode for erase verify
                                                                                    operations. */
#define FLASHCTL_BANK0TRIM0_RDERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_RDERSPOSTVERIFY_ENABLED ((uint32_t)0x00040000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[NOERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK0TRIM0_NOERSPOSTVERIFY_OFS  (19)                            /* !< NOERSPOSTVERIFY Offset */
#define FLASHCTL_BANK0TRIM0_NOERSPOSTVERIFY_MASK ((uint32_t)0x00080000U)         /* !< Do not do a post verify after
                                                                                    erase. */
#define FLASHCTL_BANK0TRIM0_NOERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_NOERSPOSTVERIFY_ENABLED ((uint32_t)0x00080000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[IREFCFG] Bits */
#define FLASHCTL_BANK0TRIM0_IREFCFG_OFS          (20)                            /* !< IREFCFG Offset */
#define FLASHCTL_BANK0TRIM0_IREFCFG_MASK         ((uint32_t)0x01F00000U)         /* !< Configures IREF used for read
                                                                                    operation */
#define FLASHCTL_BANK0TRIM0_IREFCFG_DEFAULTIREF  ((uint32_t)0x00000000U)         /* !< Uses default IREF on the reference
                                                                                    side */
#define FLASHCTL_BANK0TRIM0_IREFCFG_USE0P25XIREF ((uint32_t)0x00100000U)         /* !< Adds 0.25*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK0TRIM0_IREFCFG_USE0P5XIREF  ((uint32_t)0x00200000U)         /* !< Adds 0.50*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK0TRIM0_IREFCFG_USE1XIREF    ((uint32_t)0x00400000U)         /* !< Adds 1.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK0TRIM0_IREFCFG_USE2XIREF    ((uint32_t)0x00800000U)         /* !< Adds 2.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK0TRIM0_IREFCFG_USE3XIREF    ((uint32_t)0x01000000U)         /* !< Adds 3.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
/* FLASHCTL_BANK0TRIM0[IREFCFGEN] Bits */
#define FLASHCTL_BANK0TRIM0_IREFCFGEN_OFS        (25)                            /* !< IREFCFGEN Offset */
#define FLASHCTL_BANK0TRIM0_IREFCFGEN_MASK       ((uint32_t)0x02000000U)         /* !< Enables override of IREF
                                                                                    configuration.  By default, this is
                                                                                    controlled by the mode setting in the
                                                                                    bank.  If this bit is set, the mode
                                                                                    setting will be ignored, and the
                                                                                    value encoded into the IREFCFG field
                                                                                    will be used to configure the IREF on
                                                                                    the reference side. */
#define FLASHCTL_BANK0TRIM0_IREFCFGEN_DISABLED   ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_IREFCFGEN_ENABLED    ((uint32_t)0x02000000U)         /* !< Feature enabled */
/* FLASHCTL_BANK0TRIM0[PROGPULSECFG] Bits */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_OFS     (26)                            /* !< PROGPULSECFG Offset */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_MASK    ((uint32_t)0x1C000000U)         /* !< Configures the length of the
                                                                                    program pulse.  By default, the
                                                                                    program pulse time is fixed.  When
                                                                                    the SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the program pulse length. */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE1P5XDEFAULT ((uint32_t)0x00000000U)         /* !< Use 1.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE2XDEFAULT ((uint32_t)0x04000000U)         /* !< Use 2.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE2P5XDEFAULT ((uint32_t)0x08000000U)         /* !< Use 2.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE3XDEFAULT ((uint32_t)0x0C000000U)         /* !< Use 3.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE4XDEFAULT ((uint32_t)0x10000000U)         /* !< Use 4.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE5XDEFAULT ((uint32_t)0x14000000U)         /* !< Use 5.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE0P5XDEFAULT ((uint32_t)0x18000000U)         /* !< Use 0.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK0TRIM0_PROGPULSECFG_USE1XDEFAULT ((uint32_t)0x1C000000U)         /* !< Use 1.0 X the default, fixed
                                                                                    program pulse time */
/* FLASHCTL_BANK0TRIM0[ERASEGPULSECFG] Bits */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_OFS   (29)                            /* !< ERASEGPULSECFG Offset */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_MASK  ((uint32_t)0xE0000000U)         /* !< Configures the length of the erase
                                                                                    pulse.  By default, the erase pulse
                                                                                    time is fixed.  When the
                                                                                    SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the erase pulse length. */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE100MS ((uint32_t)0x00000000U)         /* !< Use 100ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE200MS ((uint32_t)0x20000000U)         /* !< Use 200ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE300MS ((uint32_t)0x40000000U)         /* !< Use 300ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE400MS ((uint32_t)0x60000000U)         /* !< Use 400ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE500MS ((uint32_t)0x80000000U)         /* !< Use 500ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE700MS ((uint32_t)0xA0000000U)         /* !< Use 700ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE25MS ((uint32_t)0xC0000000U)         /* !< Use 25ms for the erase pulse time */
#define FLASHCTL_BANK0TRIM0_ERASEGPULSECFG_USE50MS ((uint32_t)0xE0000000U)         /* !< Use 50ms for the erase pulse time */
/* FLASHCTL_BANK0TRIM0[NOPRGPOSTVERIFY] Bits */
#define FLASHCTL_BANK0TRIM0_NOPRGPOSTVERIFY_OFS  (11)                            /* !< NOPRGPOSTVERIFY Offset */
#define FLASHCTL_BANK0TRIM0_NOPRGPOSTVERIFY_MASK ((uint32_t)0x00000800U)         /* !< Do not do a post verify after
                                                                                    program. */
#define FLASHCTL_BANK0TRIM0_NOPRGPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK0TRIM0_NOPRGPOSTVERIFY_ENABLED ((uint32_t)0x00000800U)         /* !< Feature enabled */

/* FLASHCTL_BANK0TRIMREAD Bits */
/* FLASHCTL_BANK0TRIMREAD[REPAIREN0] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN0_OFS     (0)                             /* !< REPAIREN0 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN0_MASK    ((uint32_t)0x00000001U)         /* !< Repair Enable 0 Enables repair for
                                                                                    bank data bits 35:0 (if ecc) or 31:0
                                                                                    (if no ecc) */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN0_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN0_ENABLE  ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_BANK0TRIMREAD[REPAIREN1] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN1_OFS     (1)                             /* !< REPAIREN1 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN1_MASK    ((uint32_t)0x00000002U)         /* !< Repair Enable 1 Enables repair for
                                                                                    bank data bits 71:36 (if ecc) or
                                                                                    63:32 (if no ecc) */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN1_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN1_ENABLE  ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_BANK0TRIMREAD[REPAIREN2] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN2_OFS     (2)                             /* !< REPAIREN2 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN2_MASK    ((uint32_t)0x00000004U)         /* !< Repair Enable 2 Enables repair for
                                                                                    bank data bits 107:72 (if ecc) or
                                                                                    95:64 (if no ecc) */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN2_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN2_ENABLE  ((uint32_t)0x00000004U)         /* !< Enable */
/* FLASHCTL_BANK0TRIMREAD[REPAIREN3] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN3_OFS     (3)                             /* !< REPAIREN3 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN3_MASK    ((uint32_t)0x00000008U)         /* !< Repair Enable 3 Enables repair for
                                                                                    bank data bits 143:108 (if ecc) or
                                                                                    127:96 (if no ecc) */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN3_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK0TRIMREAD_REPAIREN3_ENABLE  ((uint32_t)0x00000008U)         /* !< Enable */
/* FLASHCTL_BANK0TRIMREAD[REPAIRCFG0] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG0_OFS    (4)                             /* !< REPAIRCFG0 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG0_MASK   ((uint32_t)0x000003F0U)         /* !< Repair Configure 0 Configures
                                                                                    repair for bank data bits 35:0 (if
                                                                                    ecc) or 31:0 (if no ecc).  This field
                                                                                    indicates which of the 36 (if ecc)
                                                                                    or 32 (if no ecc) bits in the bank
                                                                                    data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG0_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG0] */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG0_MAXIMUM ((uint32_t)0x00000230U)         /* !< Maximum value of [REPAIRCFG0] */
/* FLASHCTL_BANK0TRIMREAD[REPAIRCFG1] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG1_OFS    (10)                            /* !< REPAIRCFG1 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG1_MASK   ((uint32_t)0x0000FC00U)         /* !< Repair Configure 1 Configures
                                                                                    repair for bank data bits 71:36 (if
                                                                                    ecc) or 63:32 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG1_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG1] */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG1_MAXIMUM ((uint32_t)0x00008C00U)         /* !< Maximum value of [REPAIRCFG1] */
/* FLASHCTL_BANK0TRIMREAD[REPAIRCFG2] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG2_OFS    (16)                            /* !< REPAIRCFG2 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG2_MASK   ((uint32_t)0x003F0000U)         /* !< Repair Configure 2 Configures
                                                                                    repair for bank data bits 107:72 (if
                                                                                    ecc) or 95:64 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG2_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG2] */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG2_MAXIMUM ((uint32_t)0x00230000U)         /* !< Maximum value of [REPAIRCFG2] */
/* FLASHCTL_BANK0TRIMREAD[REPAIRCFG3] Bits */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG3_OFS    (22)                            /* !< REPAIRCFG3 Offset */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG3_MASK   ((uint32_t)0x0FC00000U)         /* !< Repair Configure 3 Configures
                                                                                    repair for bank data bits 143:108 (if
                                                                                    ecc) or 127:96 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG3_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG3] */
#define FLASHCTL_BANK0TRIMREAD_REPAIRCFG3_MAXIMUM ((uint32_t)0x08C00000U)         /* !< Maximum value of [REPAIRCFG3] */

/* FLASHCTL_BANK1TRIM0 Bits */
/* FLASHCTL_BANK1TRIM0[ODDWLSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_ODDWLSTRESSEN_OFS    (12)                            /* !< ODDWLSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_ODDWLSTRESSEN_MASK   ((uint32_t)0x00001000U)         /* !< Odd word line stress enable */
#define FLASHCTL_BANK1TRIM0_ODDWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_ODDWLSTRESSEN_ENABLED ((uint32_t)0x00001000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[EVENWLSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_EVENWLSTRESSEN_OFS   (13)                            /* !< EVENWLSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_EVENWLSTRESSEN_MASK  ((uint32_t)0x00002000U)         /* !< Even word line stress enable */
#define FLASHCTL_BANK1TRIM0_EVENWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_EVENWLSTRESSEN_ENABLED ((uint32_t)0x00002000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[ODDBLSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_ODDBLSTRESSEN_OFS    (14)                            /* !< ODDBLSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_ODDBLSTRESSEN_MASK   ((uint32_t)0x00004000U)         /* !< Odd bit line stress enable */
#define FLASHCTL_BANK1TRIM0_ODDBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_ODDBLSTRESSEN_ENABLED ((uint32_t)0x00004000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[EVENBLSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_EVENBLSTRESSEN_OFS   (15)                            /* !< EVENBLSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_EVENBLSTRESSEN_MASK  ((uint32_t)0x00008000U)         /* !< Even bit line stress enable */
#define FLASHCTL_BANK1TRIM0_EVENBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_EVENBLSTRESSEN_ENABLED ((uint32_t)0x00008000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[ODDCGSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_ODDCGSTRESSEN_OFS    (16)                            /* !< ODDCGSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_ODDCGSTRESSEN_MASK   ((uint32_t)0x00010000U)         /* !< Odd control gate stress enable */
#define FLASHCTL_BANK1TRIM0_ODDCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_ODDCGSTRESSEN_ENABLED ((uint32_t)0x00010000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[EVENCGSTRESSEN] Bits */
#define FLASHCTL_BANK1TRIM0_EVENCGSTRESSEN_OFS   (17)                            /* !< EVENCGSTRESSEN Offset */
#define FLASHCTL_BANK1TRIM0_EVENCGSTRESSEN_MASK  ((uint32_t)0x00020000U)         /* !< Even control gate stress enable */
#define FLASHCTL_BANK1TRIM0_EVENCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_EVENCGSTRESSEN_ENABLED ((uint32_t)0x00020000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[RDERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK1TRIM0_RDERSPOSTVERIFY_OFS  (18)                            /* !< RDERSPOSTVERIFY Offset */
#define FLASHCTL_BANK1TRIM0_RDERSPOSTVERIFY_MASK ((uint32_t)0x00040000U)         /* !< Use READ mode for erase verify
                                                                                    operations. */
#define FLASHCTL_BANK1TRIM0_RDERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_RDERSPOSTVERIFY_ENABLED ((uint32_t)0x00040000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[NOERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK1TRIM0_NOERSPOSTVERIFY_OFS  (19)                            /* !< NOERSPOSTVERIFY Offset */
#define FLASHCTL_BANK1TRIM0_NOERSPOSTVERIFY_MASK ((uint32_t)0x00080000U)         /* !< Do not do a post verify after
                                                                                    erase. */
#define FLASHCTL_BANK1TRIM0_NOERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_NOERSPOSTVERIFY_ENABLED ((uint32_t)0x00080000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[IREFCFG] Bits */
#define FLASHCTL_BANK1TRIM0_IREFCFG_OFS          (20)                            /* !< IREFCFG Offset */
#define FLASHCTL_BANK1TRIM0_IREFCFG_MASK         ((uint32_t)0x01F00000U)         /* !< Configures IREF used for read
                                                                                    operation */
#define FLASHCTL_BANK1TRIM0_IREFCFG_DEFAULTIREF  ((uint32_t)0x00000000U)         /* !< Uses default IREF on the reference
                                                                                    side */
#define FLASHCTL_BANK1TRIM0_IREFCFG_USE0P25XIREF ((uint32_t)0x00100000U)         /* !< Adds 0.25*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK1TRIM0_IREFCFG_USE0P5XIREF  ((uint32_t)0x00200000U)         /* !< Adds 0.50*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK1TRIM0_IREFCFG_USE1XIREF    ((uint32_t)0x00400000U)         /* !< Adds 1.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK1TRIM0_IREFCFG_USE2XIREF    ((uint32_t)0x00800000U)         /* !< Adds 2.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK1TRIM0_IREFCFG_USE3XIREF    ((uint32_t)0x01000000U)         /* !< Adds 3.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
/* FLASHCTL_BANK1TRIM0[IREFCFGEN] Bits */
#define FLASHCTL_BANK1TRIM0_IREFCFGEN_OFS        (25)                            /* !< IREFCFGEN Offset */
#define FLASHCTL_BANK1TRIM0_IREFCFGEN_MASK       ((uint32_t)0x02000000U)         /* !< Enables override of IREF
                                                                                    configuration.  By default, this is
                                                                                    controlled by the mode setting in the
                                                                                    bank.  If this bit is set, the mode
                                                                                    setting will be ignored, and the
                                                                                    value encoded into the IREFCFG field
                                                                                    will be used to configure the IREF on
                                                                                    the reference side. */
#define FLASHCTL_BANK1TRIM0_IREFCFGEN_DISABLED   ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_IREFCFGEN_ENABLED    ((uint32_t)0x02000000U)         /* !< Feature enabled */
/* FLASHCTL_BANK1TRIM0[PROGPULSECFG] Bits */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_OFS     (26)                            /* !< PROGPULSECFG Offset */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_MASK    ((uint32_t)0x1C000000U)         /* !< Configures the length of the
                                                                                    program pulse.  By default, the
                                                                                    program pulse time is fixed.  When
                                                                                    the SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the program pulse length. */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE1P5XDEFAULT ((uint32_t)0x00000000U)         /* !< Use 1.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE2XDEFAULT ((uint32_t)0x04000000U)         /* !< Use 2.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE2P5XDEFAULT ((uint32_t)0x08000000U)         /* !< Use 2.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE3XDEFAULT ((uint32_t)0x0C000000U)         /* !< Use 3.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE4XDEFAULT ((uint32_t)0x10000000U)         /* !< Use 4.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE5XDEFAULT ((uint32_t)0x14000000U)         /* !< Use 5.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE0P5XDEFAULT ((uint32_t)0x18000000U)         /* !< Use 0.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK1TRIM0_PROGPULSECFG_USE1XDEFAULT ((uint32_t)0x1C000000U)         /* !< Use 1.0 X the default, fixed
                                                                                    program pulse time */
/* FLASHCTL_BANK1TRIM0[ERASEGPULSECFG] Bits */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_OFS   (29)                            /* !< ERASEGPULSECFG Offset */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_MASK  ((uint32_t)0xE0000000U)         /* !< Configures the length of the erase
                                                                                    pulse.  By default, the erase pulse
                                                                                    time is fixed.  When the
                                                                                    SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the erase pulse length. */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE100MS ((uint32_t)0x00000000U)         /* !< Use 100ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE200MS ((uint32_t)0x20000000U)         /* !< Use 200ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE300MS ((uint32_t)0x40000000U)         /* !< Use 300ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE400MS ((uint32_t)0x60000000U)         /* !< Use 400ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE500MS ((uint32_t)0x80000000U)         /* !< Use 500ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE700MS ((uint32_t)0xA0000000U)         /* !< Use 700ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE25MS ((uint32_t)0xC0000000U)         /* !< Use 25ms for the erase pulse time */
#define FLASHCTL_BANK1TRIM0_ERASEGPULSECFG_USE50MS ((uint32_t)0xE0000000U)         /* !< Use 50ms for the erase pulse time */
/* FLASHCTL_BANK1TRIM0[NOPRGPOSTVERIFY] Bits */
#define FLASHCTL_BANK1TRIM0_NOPRGPOSTVERIFY_OFS  (11)                            /* !< NOPRGPOSTVERIFY Offset */
#define FLASHCTL_BANK1TRIM0_NOPRGPOSTVERIFY_MASK ((uint32_t)0x00000800U)         /* !< Do not do a post verify after
                                                                                    program. */
#define FLASHCTL_BANK1TRIM0_NOPRGPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK1TRIM0_NOPRGPOSTVERIFY_ENABLED ((uint32_t)0x00000800U)         /* !< Feature enabled */

/* FLASHCTL_BANK1TRIMREAD Bits */
/* FLASHCTL_BANK1TRIMREAD[REPAIREN0] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN0_OFS     (0)                             /* !< REPAIREN0 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN0_MASK    ((uint32_t)0x00000001U)         /* !< Repair Enable 0 Enables repair for
                                                                                    bank data bits 35:0 (if ecc) or 31:0
                                                                                    (if no ecc) */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN0_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN0_ENABLE  ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_BANK1TRIMREAD[REPAIREN1] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN1_OFS     (1)                             /* !< REPAIREN1 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN1_MASK    ((uint32_t)0x00000002U)         /* !< Repair Enable 1 Enables repair for
                                                                                    bank data bits 71:36 (if ecc) or
                                                                                    63:32 (if no ecc) */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN1_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN1_ENABLE  ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_BANK1TRIMREAD[REPAIREN2] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN2_OFS     (2)                             /* !< REPAIREN2 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN2_MASK    ((uint32_t)0x00000004U)         /* !< Repair Enable 2 Enables repair for
                                                                                    bank data bits 107:72 (if ecc) or
                                                                                    95:64 (if no ecc) */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN2_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN2_ENABLE  ((uint32_t)0x00000004U)         /* !< Enable */
/* FLASHCTL_BANK1TRIMREAD[REPAIREN3] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN3_OFS     (3)                             /* !< REPAIREN3 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN3_MASK    ((uint32_t)0x00000008U)         /* !< Repair Enable 3 Enables repair for
                                                                                    bank data bits 143:108 (if ecc) or
                                                                                    127:96 (if no ecc) */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN3_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK1TRIMREAD_REPAIREN3_ENABLE  ((uint32_t)0x00000008U)         /* !< Enable */
/* FLASHCTL_BANK1TRIMREAD[REPAIRCFG0] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG0_OFS    (4)                             /* !< REPAIRCFG0 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG0_MASK   ((uint32_t)0x000003F0U)         /* !< Repair Configure 0 Configures
                                                                                    repair for bank data bits 35:0 (if
                                                                                    ecc) or 31:0 (if no ecc).  This field
                                                                                    indicates which of the 36 (if ecc)
                                                                                    or 32 (if no ecc) bits in the bank
                                                                                    data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG0_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG0] */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG0_MAXIMUM ((uint32_t)0x00000230U)         /* !< Maximum value of [REPAIRCFG0] */
/* FLASHCTL_BANK1TRIMREAD[REPAIRCFG1] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG1_OFS    (10)                            /* !< REPAIRCFG1 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG1_MASK   ((uint32_t)0x0000FC00U)         /* !< Repair Configure 1 Configures
                                                                                    repair for bank data bits 71:36 (if
                                                                                    ecc) or 63:32 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG1_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG1] */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG1_MAXIMUM ((uint32_t)0x00008C00U)         /* !< Maximum value of [REPAIRCFG1] */
/* FLASHCTL_BANK1TRIMREAD[REPAIRCFG2] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG2_OFS    (16)                            /* !< REPAIRCFG2 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG2_MASK   ((uint32_t)0x003F0000U)         /* !< Repair Configure 2 Configures
                                                                                    repair for bank data bits 107:72 (if
                                                                                    ecc) or 95:64 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG2_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG2] */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG2_MAXIMUM ((uint32_t)0x00230000U)         /* !< Maximum value of [REPAIRCFG2] */
/* FLASHCTL_BANK1TRIMREAD[REPAIRCFG3] Bits */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG3_OFS    (22)                            /* !< REPAIRCFG3 Offset */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG3_MASK   ((uint32_t)0x0FC00000U)         /* !< Repair Configure 3 Configures
                                                                                    repair for bank data bits 143:108 (if
                                                                                    ecc) or 127:96 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG3_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG3] */
#define FLASHCTL_BANK1TRIMREAD_REPAIRCFG3_MAXIMUM ((uint32_t)0x08C00000U)         /* !< Maximum value of [REPAIRCFG3] */

/* FLASHCTL_BANK2TRIM0 Bits */
/* FLASHCTL_BANK2TRIM0[EVENWLSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_EVENWLSTRESSEN_OFS   (13)                            /* !< EVENWLSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_EVENWLSTRESSEN_MASK  ((uint32_t)0x00002000U)         /* !< Even word line stress enable */
#define FLASHCTL_BANK2TRIM0_EVENWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_EVENWLSTRESSEN_ENABLED ((uint32_t)0x00002000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[ODDBLSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_ODDBLSTRESSEN_OFS    (14)                            /* !< ODDBLSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_ODDBLSTRESSEN_MASK   ((uint32_t)0x00004000U)         /* !< Odd bit line stress enable */
#define FLASHCTL_BANK2TRIM0_ODDBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_ODDBLSTRESSEN_ENABLED ((uint32_t)0x00004000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[EVENBLSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_EVENBLSTRESSEN_OFS   (15)                            /* !< EVENBLSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_EVENBLSTRESSEN_MASK  ((uint32_t)0x00008000U)         /* !< Even bit line stress enable */
#define FLASHCTL_BANK2TRIM0_EVENBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_EVENBLSTRESSEN_ENABLED ((uint32_t)0x00008000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[ODDCGSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_ODDCGSTRESSEN_OFS    (16)                            /* !< ODDCGSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_ODDCGSTRESSEN_MASK   ((uint32_t)0x00010000U)         /* !< Odd control gate stress enable */
#define FLASHCTL_BANK2TRIM0_ODDCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_ODDCGSTRESSEN_ENABLED ((uint32_t)0x00010000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[EVENCGSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_EVENCGSTRESSEN_OFS   (17)                            /* !< EVENCGSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_EVENCGSTRESSEN_MASK  ((uint32_t)0x00020000U)         /* !< Even control gate stress enable */
#define FLASHCTL_BANK2TRIM0_EVENCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_EVENCGSTRESSEN_ENABLED ((uint32_t)0x00020000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[RDERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK2TRIM0_RDERSPOSTVERIFY_OFS  (18)                            /* !< RDERSPOSTVERIFY Offset */
#define FLASHCTL_BANK2TRIM0_RDERSPOSTVERIFY_MASK ((uint32_t)0x00040000U)         /* !< Use READ mode for erase verify
                                                                                    operations. */
#define FLASHCTL_BANK2TRIM0_RDERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_RDERSPOSTVERIFY_ENABLED ((uint32_t)0x00040000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[NOERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK2TRIM0_NOERSPOSTVERIFY_OFS  (19)                            /* !< NOERSPOSTVERIFY Offset */
#define FLASHCTL_BANK2TRIM0_NOERSPOSTVERIFY_MASK ((uint32_t)0x00080000U)         /* !< Do not do a post verify after
                                                                                    erase. */
#define FLASHCTL_BANK2TRIM0_NOERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_NOERSPOSTVERIFY_ENABLED ((uint32_t)0x00080000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[IREFCFG] Bits */
#define FLASHCTL_BANK2TRIM0_IREFCFG_OFS          (20)                            /* !< IREFCFG Offset */
#define FLASHCTL_BANK2TRIM0_IREFCFG_MASK         ((uint32_t)0x01F00000U)         /* !< Configures IREF used for read
                                                                                    operation */
#define FLASHCTL_BANK2TRIM0_IREFCFG_DEFAULTIREF  ((uint32_t)0x00000000U)         /* !< Uses default IREF on the reference
                                                                                    side */
#define FLASHCTL_BANK2TRIM0_IREFCFG_USE0P25XIREF ((uint32_t)0x00100000U)         /* !< Adds 0.25*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK2TRIM0_IREFCFG_USE0P5XIREF  ((uint32_t)0x00200000U)         /* !< Adds 0.50*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK2TRIM0_IREFCFG_USE1XIREF    ((uint32_t)0x00400000U)         /* !< Adds 1.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK2TRIM0_IREFCFG_USE2XIREF    ((uint32_t)0x00800000U)         /* !< Adds 2.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK2TRIM0_IREFCFG_USE3XIREF    ((uint32_t)0x01000000U)         /* !< Adds 3.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
/* FLASHCTL_BANK2TRIM0[IREFCFGEN] Bits */
#define FLASHCTL_BANK2TRIM0_IREFCFGEN_OFS        (25)                            /* !< IREFCFGEN Offset */
#define FLASHCTL_BANK2TRIM0_IREFCFGEN_MASK       ((uint32_t)0x02000000U)         /* !< Enables override of IREF
                                                                                    configuration.  By default, this is
                                                                                    controlled by the mode setting in the
                                                                                    bank.  If this bit is set, the mode
                                                                                    setting will be ignored, and the
                                                                                    value encoded into the IREFCFG field
                                                                                    will be used to configure the IREF on
                                                                                    the reference side. */
#define FLASHCTL_BANK2TRIM0_IREFCFGEN_DISABLED   ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_IREFCFGEN_ENABLED    ((uint32_t)0x02000000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[PROGPULSECFG] Bits */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_OFS     (26)                            /* !< PROGPULSECFG Offset */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_MASK    ((uint32_t)0x1C000000U)         /* !< Configures the length of the
                                                                                    program pulse.  By default, the
                                                                                    program pulse time is fixed.  When
                                                                                    the SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the program pulse length. */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE1P5XDEFAULT ((uint32_t)0x00000000U)         /* !< Use 1.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE2XDEFAULT ((uint32_t)0x04000000U)         /* !< Use 2.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE2P5XDEFAULT ((uint32_t)0x08000000U)         /* !< Use 2.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE3XDEFAULT ((uint32_t)0x0C000000U)         /* !< Use 3.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE4XDEFAULT ((uint32_t)0x10000000U)         /* !< Use 4.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE5XDEFAULT ((uint32_t)0x14000000U)         /* !< Use 5.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE0P5XDEFAULT ((uint32_t)0x18000000U)         /* !< Use 0.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK2TRIM0_PROGPULSECFG_USE1XDEFAULT ((uint32_t)0x1C000000U)         /* !< Use 1.0 X the default, fixed
                                                                                    program pulse time */
/* FLASHCTL_BANK2TRIM0[ERASEGPULSECFG] Bits */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_OFS   (29)                            /* !< ERASEGPULSECFG Offset */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_MASK  ((uint32_t)0xE0000000U)         /* !< Configures the length of the erase
                                                                                    pulse.  By default, the erase pulse
                                                                                    time is fixed.  When the
                                                                                    SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the erase pulse length. */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE100MS ((uint32_t)0x00000000U)         /* !< Use 100ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE200MS ((uint32_t)0x20000000U)         /* !< Use 200ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE300MS ((uint32_t)0x40000000U)         /* !< Use 300ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE400MS ((uint32_t)0x60000000U)         /* !< Use 400ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE500MS ((uint32_t)0x80000000U)         /* !< Use 500ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE700MS ((uint32_t)0xA0000000U)         /* !< Use 700ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE25MS ((uint32_t)0xC0000000U)         /* !< Use 25ms for the erase pulse time */
#define FLASHCTL_BANK2TRIM0_ERASEGPULSECFG_USE50MS ((uint32_t)0xE0000000U)         /* !< Use 50ms for the erase pulse time */
/* FLASHCTL_BANK2TRIM0[ODDWLSTRESSEN] Bits */
#define FLASHCTL_BANK2TRIM0_ODDWLSTRESSEN_OFS    (12)                            /* !< ODDWLSTRESSEN Offset */
#define FLASHCTL_BANK2TRIM0_ODDWLSTRESSEN_MASK   ((uint32_t)0x00001000U)         /* !< Odd word line stress enable */
#define FLASHCTL_BANK2TRIM0_ODDWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_ODDWLSTRESSEN_ENABLED ((uint32_t)0x00001000U)         /* !< Feature enabled */
/* FLASHCTL_BANK2TRIM0[NOPRGPOSTVERIFY] Bits */
#define FLASHCTL_BANK2TRIM0_NOPRGPOSTVERIFY_OFS  (11)                            /* !< NOPRGPOSTVERIFY Offset */
#define FLASHCTL_BANK2TRIM0_NOPRGPOSTVERIFY_MASK ((uint32_t)0x00000800U)         /* !< Do not do a post verify after
                                                                                    program. */
#define FLASHCTL_BANK2TRIM0_NOPRGPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK2TRIM0_NOPRGPOSTVERIFY_ENABLED ((uint32_t)0x00000800U)         /* !< Feature enabled */

/* FLASHCTL_BANK2TRIMREAD Bits */
/* FLASHCTL_BANK2TRIMREAD[REPAIREN0] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN0_OFS     (0)                             /* !< REPAIREN0 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN0_MASK    ((uint32_t)0x00000001U)         /* !< Repair Enable 0 Enables repair for
                                                                                    bank data bits 35:0 (if ecc) or 31:0
                                                                                    (if no ecc) */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN0_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN0_ENABLE  ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_BANK2TRIMREAD[REPAIREN1] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN1_OFS     (1)                             /* !< REPAIREN1 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN1_MASK    ((uint32_t)0x00000002U)         /* !< Repair Enable 1 Enables repair for
                                                                                    bank data bits 71:36 (if ecc) or
                                                                                    63:32 (if no ecc) */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN1_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN1_ENABLE  ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_BANK2TRIMREAD[REPAIREN2] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN2_OFS     (2)                             /* !< REPAIREN2 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN2_MASK    ((uint32_t)0x00000004U)         /* !< Repair Enable 2 Enables repair for
                                                                                    bank data bits 107:72 (if ecc) or
                                                                                    95:64 (if no ecc) */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN2_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN2_ENABLE  ((uint32_t)0x00000004U)         /* !< Enable */
/* FLASHCTL_BANK2TRIMREAD[REPAIREN3] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN3_OFS     (3)                             /* !< REPAIREN3 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN3_MASK    ((uint32_t)0x00000008U)         /* !< Repair Enable 3 Enables repair for
                                                                                    bank data bits 143:108 (if ecc) or
                                                                                    127:96 (if no ecc) */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN3_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK2TRIMREAD_REPAIREN3_ENABLE  ((uint32_t)0x00000008U)         /* !< Enable */
/* FLASHCTL_BANK2TRIMREAD[REPAIRCFG0] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG0_OFS    (4)                             /* !< REPAIRCFG0 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG0_MASK   ((uint32_t)0x000003F0U)         /* !< Repair Configure 0 Configures
                                                                                    repair for bank data bits 35:0 (if
                                                                                    ecc) or 31:0 (if no ecc).  This field
                                                                                    indicates which of the 36 (if ecc)
                                                                                    or 32 (if no ecc) bits in the bank
                                                                                    data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG0_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG0] */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG0_MAXIMUM ((uint32_t)0x00000230U)         /* !< Maximum value of [REPAIRCFG0] */
/* FLASHCTL_BANK2TRIMREAD[REPAIRCFG1] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG1_OFS    (10)                            /* !< REPAIRCFG1 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG1_MASK   ((uint32_t)0x0000FC00U)         /* !< Repair Configure 1 Configures
                                                                                    repair for bank data bits 71:36 (if
                                                                                    ecc) or 63:32 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG1_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG1] */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG1_MAXIMUM ((uint32_t)0x00008C00U)         /* !< Maximum value of [REPAIRCFG1] */
/* FLASHCTL_BANK2TRIMREAD[REPAIRCFG2] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG2_OFS    (16)                            /* !< REPAIRCFG2 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG2_MASK   ((uint32_t)0x003F0000U)         /* !< Repair Configure 2 Configures
                                                                                    repair for bank data bits 107:72 (if
                                                                                    ecc) or 95:64 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG2_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG2] */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG2_MAXIMUM ((uint32_t)0x00230000U)         /* !< Maximum value of [REPAIRCFG2] */
/* FLASHCTL_BANK2TRIMREAD[REPAIRCFG3] Bits */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG3_OFS    (22)                            /* !< REPAIRCFG3 Offset */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG3_MASK   ((uint32_t)0x0FC00000U)         /* !< Repair Configure 3 Configures
                                                                                    repair for bank data bits 143:108 (if
                                                                                    ecc) or 127:96 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG3_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG3] */
#define FLASHCTL_BANK2TRIMREAD_REPAIRCFG3_MAXIMUM ((uint32_t)0x08C00000U)         /* !< Maximum value of [REPAIRCFG3] */

/* FLASHCTL_BANK3TRIM0 Bits */
/* FLASHCTL_BANK3TRIM0[EVENWLSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_EVENWLSTRESSEN_OFS   (13)                            /* !< EVENWLSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_EVENWLSTRESSEN_MASK  ((uint32_t)0x00002000U)         /* !< Even word line stress enable */
#define FLASHCTL_BANK3TRIM0_EVENWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_EVENWLSTRESSEN_ENABLED ((uint32_t)0x00002000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[ODDBLSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_ODDBLSTRESSEN_OFS    (14)                            /* !< ODDBLSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_ODDBLSTRESSEN_MASK   ((uint32_t)0x00004000U)         /* !< Odd bit line stress enable */
#define FLASHCTL_BANK3TRIM0_ODDBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_ODDBLSTRESSEN_ENABLED ((uint32_t)0x00004000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[EVENBLSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_EVENBLSTRESSEN_OFS   (15)                            /* !< EVENBLSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_EVENBLSTRESSEN_MASK  ((uint32_t)0x00008000U)         /* !< Even bit line stress enable */
#define FLASHCTL_BANK3TRIM0_EVENBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_EVENBLSTRESSEN_ENABLED ((uint32_t)0x00008000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[ODDCGSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_ODDCGSTRESSEN_OFS    (16)                            /* !< ODDCGSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_ODDCGSTRESSEN_MASK   ((uint32_t)0x00010000U)         /* !< Odd control gate stress enable */
#define FLASHCTL_BANK3TRIM0_ODDCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_ODDCGSTRESSEN_ENABLED ((uint32_t)0x00010000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[EVENCGSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_EVENCGSTRESSEN_OFS   (17)                            /* !< EVENCGSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_EVENCGSTRESSEN_MASK  ((uint32_t)0x00020000U)         /* !< Even control gate stress enable */
#define FLASHCTL_BANK3TRIM0_EVENCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_EVENCGSTRESSEN_ENABLED ((uint32_t)0x00020000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[RDERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK3TRIM0_RDERSPOSTVERIFY_OFS  (18)                            /* !< RDERSPOSTVERIFY Offset */
#define FLASHCTL_BANK3TRIM0_RDERSPOSTVERIFY_MASK ((uint32_t)0x00040000U)         /* !< Use READ mode for erase verify
                                                                                    operations. */
#define FLASHCTL_BANK3TRIM0_RDERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_RDERSPOSTVERIFY_ENABLED ((uint32_t)0x00040000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[NOERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK3TRIM0_NOERSPOSTVERIFY_OFS  (19)                            /* !< NOERSPOSTVERIFY Offset */
#define FLASHCTL_BANK3TRIM0_NOERSPOSTVERIFY_MASK ((uint32_t)0x00080000U)         /* !< Do not do a post verify after
                                                                                    erase. */
#define FLASHCTL_BANK3TRIM0_NOERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_NOERSPOSTVERIFY_ENABLED ((uint32_t)0x00080000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[IREFCFG] Bits */
#define FLASHCTL_BANK3TRIM0_IREFCFG_OFS          (20)                            /* !< IREFCFG Offset */
#define FLASHCTL_BANK3TRIM0_IREFCFG_MASK         ((uint32_t)0x01F00000U)         /* !< Configures IREF used for read
                                                                                    operation */
#define FLASHCTL_BANK3TRIM0_IREFCFG_DEFAULTIREF  ((uint32_t)0x00000000U)         /* !< Uses default IREF on the reference
                                                                                    side */
#define FLASHCTL_BANK3TRIM0_IREFCFG_USE0P25XIREF ((uint32_t)0x00100000U)         /* !< Adds 0.25*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK3TRIM0_IREFCFG_USE0P5XIREF  ((uint32_t)0x00200000U)         /* !< Adds 0.50*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK3TRIM0_IREFCFG_USE1XIREF    ((uint32_t)0x00400000U)         /* !< Adds 1.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK3TRIM0_IREFCFG_USE2XIREF    ((uint32_t)0x00800000U)         /* !< Adds 2.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK3TRIM0_IREFCFG_USE3XIREF    ((uint32_t)0x01000000U)         /* !< Adds 3.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
/* FLASHCTL_BANK3TRIM0[IREFCFGEN] Bits */
#define FLASHCTL_BANK3TRIM0_IREFCFGEN_OFS        (25)                            /* !< IREFCFGEN Offset */
#define FLASHCTL_BANK3TRIM0_IREFCFGEN_MASK       ((uint32_t)0x02000000U)         /* !< Enables override of IREF
                                                                                    configuration.  By default, this is
                                                                                    controlled by the mode setting in the
                                                                                    bank.  If this bit is set, the mode
                                                                                    setting will be ignored, and the
                                                                                    value encoded into the IREFCFG field
                                                                                    will be used to configure the IREF on
                                                                                    the reference side. */
#define FLASHCTL_BANK3TRIM0_IREFCFGEN_DISABLED   ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_IREFCFGEN_ENABLED    ((uint32_t)0x02000000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[PROGPULSECFG] Bits */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_OFS     (26)                            /* !< PROGPULSECFG Offset */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_MASK    ((uint32_t)0x1C000000U)         /* !< Configures the length of the
                                                                                    program pulse.  By default, the
                                                                                    program pulse time is fixed.  When
                                                                                    the SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the program pulse length. */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE1P5XDEFAULT ((uint32_t)0x00000000U)         /* !< Use 1.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE2XDEFAULT ((uint32_t)0x04000000U)         /* !< Use 2.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE2P5XDEFAULT ((uint32_t)0x08000000U)         /* !< Use 2.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE3XDEFAULT ((uint32_t)0x0C000000U)         /* !< Use 3.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE4XDEFAULT ((uint32_t)0x10000000U)         /* !< Use 4.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE5XDEFAULT ((uint32_t)0x14000000U)         /* !< Use 5.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE0P5XDEFAULT ((uint32_t)0x18000000U)         /* !< Use 0.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK3TRIM0_PROGPULSECFG_USE1XDEFAULT ((uint32_t)0x1C000000U)         /* !< Use 1.0 X the default, fixed
                                                                                    program pulse time */
/* FLASHCTL_BANK3TRIM0[ERASEGPULSECFG] Bits */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_OFS   (29)                            /* !< ERASEGPULSECFG Offset */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_MASK  ((uint32_t)0xE0000000U)         /* !< Configures the length of the erase
                                                                                    pulse.  By default, the erase pulse
                                                                                    time is fixed.  When the
                                                                                    SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the erase pulse length. */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE100MS ((uint32_t)0x00000000U)         /* !< Use 100ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE200MS ((uint32_t)0x20000000U)         /* !< Use 200ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE300MS ((uint32_t)0x40000000U)         /* !< Use 300ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE400MS ((uint32_t)0x60000000U)         /* !< Use 400ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE500MS ((uint32_t)0x80000000U)         /* !< Use 500ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE700MS ((uint32_t)0xA0000000U)         /* !< Use 700ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE25MS ((uint32_t)0xC0000000U)         /* !< Use 25ms for the erase pulse time */
#define FLASHCTL_BANK3TRIM0_ERASEGPULSECFG_USE50MS ((uint32_t)0xE0000000U)         /* !< Use 50ms for the erase pulse time */
/* FLASHCTL_BANK3TRIM0[ODDWLSTRESSEN] Bits */
#define FLASHCTL_BANK3TRIM0_ODDWLSTRESSEN_OFS    (12)                            /* !< ODDWLSTRESSEN Offset */
#define FLASHCTL_BANK3TRIM0_ODDWLSTRESSEN_MASK   ((uint32_t)0x00001000U)         /* !< Odd word line stress enable */
#define FLASHCTL_BANK3TRIM0_ODDWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_ODDWLSTRESSEN_ENABLED ((uint32_t)0x00001000U)         /* !< Feature enabled */
/* FLASHCTL_BANK3TRIM0[NOPRGPOSTVERIFY] Bits */
#define FLASHCTL_BANK3TRIM0_NOPRGPOSTVERIFY_OFS  (11)                            /* !< NOPRGPOSTVERIFY Offset */
#define FLASHCTL_BANK3TRIM0_NOPRGPOSTVERIFY_MASK ((uint32_t)0x00000800U)         /* !< Do not do a post verify after
                                                                                    program. */
#define FLASHCTL_BANK3TRIM0_NOPRGPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK3TRIM0_NOPRGPOSTVERIFY_ENABLED ((uint32_t)0x00000800U)         /* !< Feature enabled */

/* FLASHCTL_BANK3TRIMREAD Bits */
/* FLASHCTL_BANK3TRIMREAD[REPAIREN0] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN0_OFS     (0)                             /* !< REPAIREN0 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN0_MASK    ((uint32_t)0x00000001U)         /* !< Repair Enable 0 Enables repair for
                                                                                    bank data bits 35:0 (if ecc) or 31:0
                                                                                    (if no ecc) */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN0_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN0_ENABLE  ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_BANK3TRIMREAD[REPAIREN1] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN1_OFS     (1)                             /* !< REPAIREN1 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN1_MASK    ((uint32_t)0x00000002U)         /* !< Repair Enable 1 Enables repair for
                                                                                    bank data bits 71:36 (if ecc) or
                                                                                    63:32 (if no ecc) */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN1_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN1_ENABLE  ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_BANK3TRIMREAD[REPAIREN2] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN2_OFS     (2)                             /* !< REPAIREN2 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN2_MASK    ((uint32_t)0x00000004U)         /* !< Repair Enable 2 Enables repair for
                                                                                    bank data bits 107:72 (if ecc) or
                                                                                    95:64 (if no ecc) */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN2_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN2_ENABLE  ((uint32_t)0x00000004U)         /* !< Enable */
/* FLASHCTL_BANK3TRIMREAD[REPAIREN3] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN3_OFS     (3)                             /* !< REPAIREN3 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN3_MASK    ((uint32_t)0x00000008U)         /* !< Repair Enable 3 Enables repair for
                                                                                    bank data bits 143:108 (if ecc) or
                                                                                    127:96 (if no ecc) */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN3_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK3TRIMREAD_REPAIREN3_ENABLE  ((uint32_t)0x00000008U)         /* !< Enable */
/* FLASHCTL_BANK3TRIMREAD[REPAIRCFG0] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG0_OFS    (4)                             /* !< REPAIRCFG0 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG0_MASK   ((uint32_t)0x000003F0U)         /* !< Repair Configure 0 Configures
                                                                                    repair for bank data bits 35:0 (if
                                                                                    ecc) or 31:0 (if no ecc).  This field
                                                                                    indicates which of the 36 (if ecc)
                                                                                    or 32 (if no ecc) bits in the bank
                                                                                    data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG0_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG0] */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG0_MAXIMUM ((uint32_t)0x00000230U)         /* !< Maximum value of [REPAIRCFG0] */
/* FLASHCTL_BANK3TRIMREAD[REPAIRCFG1] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG1_OFS    (10)                            /* !< REPAIRCFG1 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG1_MASK   ((uint32_t)0x0000FC00U)         /* !< Repair Configure 1 Configures
                                                                                    repair for bank data bits 71:36 (if
                                                                                    ecc) or 63:32 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG1_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG1] */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG1_MAXIMUM ((uint32_t)0x00008C00U)         /* !< Maximum value of [REPAIRCFG1] */
/* FLASHCTL_BANK3TRIMREAD[REPAIRCFG2] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG2_OFS    (16)                            /* !< REPAIRCFG2 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG2_MASK   ((uint32_t)0x003F0000U)         /* !< Repair Configure 2 Configures
                                                                                    repair for bank data bits 107:72 (if
                                                                                    ecc) or 95:64 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG2_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG2] */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG2_MAXIMUM ((uint32_t)0x00230000U)         /* !< Maximum value of [REPAIRCFG2] */
/* FLASHCTL_BANK3TRIMREAD[REPAIRCFG3] Bits */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG3_OFS    (22)                            /* !< REPAIRCFG3 Offset */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG3_MASK   ((uint32_t)0x0FC00000U)         /* !< Repair Configure 3 Configures
                                                                                    repair for bank data bits 143:108 (if
                                                                                    ecc) or 127:96 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG3_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG3] */
#define FLASHCTL_BANK3TRIMREAD_REPAIRCFG3_MAXIMUM ((uint32_t)0x08C00000U)         /* !< Maximum value of [REPAIRCFG3] */

/* FLASHCTL_BANK4TRIM0 Bits */
/* FLASHCTL_BANK4TRIM0[EVENWLSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_EVENWLSTRESSEN_OFS   (13)                            /* !< EVENWLSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_EVENWLSTRESSEN_MASK  ((uint32_t)0x00002000U)         /* !< Even word line stress enable */
#define FLASHCTL_BANK4TRIM0_EVENWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_EVENWLSTRESSEN_ENABLED ((uint32_t)0x00002000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[ODDBLSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_ODDBLSTRESSEN_OFS    (14)                            /* !< ODDBLSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_ODDBLSTRESSEN_MASK   ((uint32_t)0x00004000U)         /* !< Odd bit line stress enable */
#define FLASHCTL_BANK4TRIM0_ODDBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_ODDBLSTRESSEN_ENABLED ((uint32_t)0x00004000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[EVENBLSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_EVENBLSTRESSEN_OFS   (15)                            /* !< EVENBLSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_EVENBLSTRESSEN_MASK  ((uint32_t)0x00008000U)         /* !< Even bit line stress enable */
#define FLASHCTL_BANK4TRIM0_EVENBLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_EVENBLSTRESSEN_ENABLED ((uint32_t)0x00008000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[ODDCGSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_ODDCGSTRESSEN_OFS    (16)                            /* !< ODDCGSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_ODDCGSTRESSEN_MASK   ((uint32_t)0x00010000U)         /* !< Odd control gate stress enable */
#define FLASHCTL_BANK4TRIM0_ODDCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_ODDCGSTRESSEN_ENABLED ((uint32_t)0x00010000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[EVENCGSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_EVENCGSTRESSEN_OFS   (17)                            /* !< EVENCGSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_EVENCGSTRESSEN_MASK  ((uint32_t)0x00020000U)         /* !< Even control gate stress enable */
#define FLASHCTL_BANK4TRIM0_EVENCGSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_EVENCGSTRESSEN_ENABLED ((uint32_t)0x00020000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[RDERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK4TRIM0_RDERSPOSTVERIFY_OFS  (18)                            /* !< RDERSPOSTVERIFY Offset */
#define FLASHCTL_BANK4TRIM0_RDERSPOSTVERIFY_MASK ((uint32_t)0x00040000U)         /* !< Use READ mode for erase verify
                                                                                    operations. */
#define FLASHCTL_BANK4TRIM0_RDERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_RDERSPOSTVERIFY_ENABLED ((uint32_t)0x00040000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[NOERSPOSTVERIFY] Bits */
#define FLASHCTL_BANK4TRIM0_NOERSPOSTVERIFY_OFS  (19)                            /* !< NOERSPOSTVERIFY Offset */
#define FLASHCTL_BANK4TRIM0_NOERSPOSTVERIFY_MASK ((uint32_t)0x00080000U)         /* !< Do not do a post verify after
                                                                                    erase. */
#define FLASHCTL_BANK4TRIM0_NOERSPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_NOERSPOSTVERIFY_ENABLED ((uint32_t)0x00080000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[IREFCFG] Bits */
#define FLASHCTL_BANK4TRIM0_IREFCFG_OFS          (20)                            /* !< IREFCFG Offset */
#define FLASHCTL_BANK4TRIM0_IREFCFG_MASK         ((uint32_t)0x01F00000U)         /* !< Configures IREF used for read
                                                                                    operation */
#define FLASHCTL_BANK4TRIM0_IREFCFG_DEFAULTIREF  ((uint32_t)0x00000000U)         /* !< Uses default IREF on the reference
                                                                                    side */
#define FLASHCTL_BANK4TRIM0_IREFCFG_USE0P25XIREF ((uint32_t)0x00100000U)         /* !< Adds 0.25*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK4TRIM0_IREFCFG_USE0P5XIREF  ((uint32_t)0x00200000U)         /* !< Adds 0.50*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK4TRIM0_IREFCFG_USE1XIREF    ((uint32_t)0x00400000U)         /* !< Adds 1.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK4TRIM0_IREFCFG_USE2XIREF    ((uint32_t)0x00800000U)         /* !< Adds 2.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
#define FLASHCTL_BANK4TRIM0_IREFCFG_USE3XIREF    ((uint32_t)0x01000000U)         /* !< Adds 3.00*IREF (nominally 4uA to
                                                                                    bank) to the IREF current on the
                                                                                    reference side */
/* FLASHCTL_BANK4TRIM0[IREFCFGEN] Bits */
#define FLASHCTL_BANK4TRIM0_IREFCFGEN_OFS        (25)                            /* !< IREFCFGEN Offset */
#define FLASHCTL_BANK4TRIM0_IREFCFGEN_MASK       ((uint32_t)0x02000000U)         /* !< Enables override of IREF
                                                                                    configuration.  By default, this is
                                                                                    controlled by the mode setting in the
                                                                                    bank.  If this bit is set, the mode
                                                                                    setting will be ignored, and the
                                                                                    value encoded into the IREFCFG field
                                                                                    will be used to configure the IREF on
                                                                                    the reference side. */
#define FLASHCTL_BANK4TRIM0_IREFCFGEN_DISABLED   ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_IREFCFGEN_ENABLED    ((uint32_t)0x02000000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[PROGPULSECFG] Bits */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_OFS     (26)                            /* !< PROGPULSECFG Offset */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_MASK    ((uint32_t)0x1C000000U)         /* !< Configures the length of the
                                                                                    program pulse.  By default, the
                                                                                    program pulse time is fixed.  When
                                                                                    the SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the program pulse length. */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE1P5XDEFAULT ((uint32_t)0x00000000U)         /* !< Use 1.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE2XDEFAULT ((uint32_t)0x04000000U)         /* !< Use 2.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE2P5XDEFAULT ((uint32_t)0x08000000U)         /* !< Use 2.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE3XDEFAULT ((uint32_t)0x0C000000U)         /* !< Use 3.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE4XDEFAULT ((uint32_t)0x10000000U)         /* !< Use 4.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE5XDEFAULT ((uint32_t)0x14000000U)         /* !< Use 5.0 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE0P5XDEFAULT ((uint32_t)0x18000000U)         /* !< Use 0.5 X the default, fixed
                                                                                    program pulse time */
#define FLASHCTL_BANK4TRIM0_PROGPULSECFG_USE1XDEFAULT ((uint32_t)0x1C000000U)         /* !< Use 1.0 X the default, fixed
                                                                                    program pulse time */
/* FLASHCTL_BANK4TRIM0[ERASEGPULSECFG] Bits */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_OFS   (29)                            /* !< ERASEGPULSECFG Offset */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_MASK  ((uint32_t)0xE0000000U)         /* !< Configures the length of the erase
                                                                                    pulse.  By default, the erase pulse
                                                                                    time is fixed.  When the
                                                                                    SKIPPOSTVERIFY bit is set, the
                                                                                    configuration in this field is used
                                                                                    for the erase pulse length. */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE100MS ((uint32_t)0x00000000U)         /* !< Use 100ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE200MS ((uint32_t)0x20000000U)         /* !< Use 200ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE300MS ((uint32_t)0x40000000U)         /* !< Use 300ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE400MS ((uint32_t)0x60000000U)         /* !< Use 400ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE500MS ((uint32_t)0x80000000U)         /* !< Use 500ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE700MS ((uint32_t)0xA0000000U)         /* !< Use 700ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE25MS ((uint32_t)0xC0000000U)         /* !< Use 25ms for the erase pulse time */
#define FLASHCTL_BANK4TRIM0_ERASEGPULSECFG_USE50MS ((uint32_t)0xE0000000U)         /* !< Use 50ms for the erase pulse time */
/* FLASHCTL_BANK4TRIM0[ODDWLSTRESSEN] Bits */
#define FLASHCTL_BANK4TRIM0_ODDWLSTRESSEN_OFS    (12)                            /* !< ODDWLSTRESSEN Offset */
#define FLASHCTL_BANK4TRIM0_ODDWLSTRESSEN_MASK   ((uint32_t)0x00001000U)         /* !< Odd word line stress enable */
#define FLASHCTL_BANK4TRIM0_ODDWLSTRESSEN_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_ODDWLSTRESSEN_ENABLED ((uint32_t)0x00001000U)         /* !< Feature enabled */
/* FLASHCTL_BANK4TRIM0[NOPRGPOSTVERIFY] Bits */
#define FLASHCTL_BANK4TRIM0_NOPRGPOSTVERIFY_OFS  (11)                            /* !< NOPRGPOSTVERIFY Offset */
#define FLASHCTL_BANK4TRIM0_NOPRGPOSTVERIFY_MASK ((uint32_t)0x00000800U)         /* !< Do not do a post verify after
                                                                                    program. */
#define FLASHCTL_BANK4TRIM0_NOPRGPOSTVERIFY_DISABLED ((uint32_t)0x00000000U)         /* !< Feature disabled */
#define FLASHCTL_BANK4TRIM0_NOPRGPOSTVERIFY_ENABLED ((uint32_t)0x00000800U)         /* !< Feature enabled */

/* FLASHCTL_BANK4TRIMREAD Bits */
/* FLASHCTL_BANK4TRIMREAD[REPAIREN0] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN0_OFS     (0)                             /* !< REPAIREN0 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN0_MASK    ((uint32_t)0x00000001U)         /* !< Repair Enable 0 Enables repair for
                                                                                    bank data bits 35:0 (if ecc) or 31:0
                                                                                    (if no ecc) */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN0_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN0_ENABLE  ((uint32_t)0x00000001U)         /* !< Enable */
/* FLASHCTL_BANK4TRIMREAD[REPAIREN1] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN1_OFS     (1)                             /* !< REPAIREN1 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN1_MASK    ((uint32_t)0x00000002U)         /* !< Repair Enable 1 Enables repair for
                                                                                    bank data bits 71:36 (if ecc) or
                                                                                    63:32 (if no ecc) */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN1_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN1_ENABLE  ((uint32_t)0x00000002U)         /* !< Enable */
/* FLASHCTL_BANK4TRIMREAD[REPAIREN2] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN2_OFS     (2)                             /* !< REPAIREN2 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN2_MASK    ((uint32_t)0x00000004U)         /* !< Repair Enable 2 Enables repair for
                                                                                    bank data bits 107:72 (if ecc) or
                                                                                    95:64 (if no ecc) */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN2_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN2_ENABLE  ((uint32_t)0x00000004U)         /* !< Enable */
/* FLASHCTL_BANK4TRIMREAD[REPAIREN3] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN3_OFS     (3)                             /* !< REPAIREN3 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN3_MASK    ((uint32_t)0x00000008U)         /* !< Repair Enable 3 Enables repair for
                                                                                    bank data bits 143:108 (if ecc) or
                                                                                    127:96 (if no ecc) */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN3_DISABLE ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_BANK4TRIMREAD_REPAIREN3_ENABLE  ((uint32_t)0x00000008U)         /* !< Enable */
/* FLASHCTL_BANK4TRIMREAD[REPAIRCFG0] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG0_OFS    (4)                             /* !< REPAIRCFG0 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG0_MASK   ((uint32_t)0x000003F0U)         /* !< Repair Configure 0 Configures
                                                                                    repair for bank data bits 35:0 (if
                                                                                    ecc) or 31:0 (if no ecc).  This field
                                                                                    indicates which of the 36 (if ecc)
                                                                                    or 32 (if no ecc) bits in the bank
                                                                                    data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG0_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG0] */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG0_MAXIMUM ((uint32_t)0x00000230U)         /* !< Maximum value of [REPAIRCFG0] */
/* FLASHCTL_BANK4TRIMREAD[REPAIRCFG1] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG1_OFS    (10)                            /* !< REPAIRCFG1 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG1_MASK   ((uint32_t)0x0000FC00U)         /* !< Repair Configure 1 Configures
                                                                                    repair for bank data bits 71:36 (if
                                                                                    ecc) or 63:32 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG1_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG1] */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG1_MAXIMUM ((uint32_t)0x00008C00U)         /* !< Maximum value of [REPAIRCFG1] */
/* FLASHCTL_BANK4TRIMREAD[REPAIRCFG2] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG2_OFS    (16)                            /* !< REPAIRCFG2 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG2_MASK   ((uint32_t)0x003F0000U)         /* !< Repair Configure 2 Configures
                                                                                    repair for bank data bits 107:72 (if
                                                                                    ecc) or 95:64 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG2_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG2] */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG2_MAXIMUM ((uint32_t)0x00230000U)         /* !< Maximum value of [REPAIRCFG2] */
/* FLASHCTL_BANK4TRIMREAD[REPAIRCFG3] Bits */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG3_OFS    (22)                            /* !< REPAIRCFG3 Offset */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG3_MASK   ((uint32_t)0x0FC00000U)         /* !< Repair Configure 3 Configures
                                                                                    repair for bank data bits 143:108 (if
                                                                                    ecc) or 127:96 (if no ecc).  This
                                                                                    field  indicates which of the 36 (if
                                                                                    ecc) or 32 (if no ecc) bits in the
                                                                                    bank data word is replaced with a
                                                                                    redundant bit for repair. */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG3_MINIMUM ((uint32_t)0x00000000U)         /* !< Minimum value of [REPAIRCFG3] */
#define FLASHCTL_BANK4TRIMREAD_REPAIRCFG3_MAXIMUM ((uint32_t)0x08C00000U)         /* !< Maximum value of [REPAIRCFG3] */

/* FLASHCTL_IIDX Bits */
/* FLASHCTL_IIDX[STAT] Bits */
#define FLASHCTL_IIDX_STAT_OFS                   (0)                             /* !< STAT Offset */
#define FLASHCTL_IIDX_STAT_MASK                  ((uint32_t)0x00000001U)         /* !< Indicates which interrupt has
                                                                                    fired. 0x0 means no event pending.
                                                                                    The priority order is fixed. On each
                                                                                    read, only one interrupt is
                                                                                    indicated. On a read, the current
                                                                                    interrupt (highest priority) is
                                                                                    automatically cleared by the hardware
                                                                                    and the corresponding interrupt flags
                                                                                    in the RIS and MIS are cleared as
                                                                                    well. After a read from the CPU (not
                                                                                    from the debug interface), the
                                                                                    register must be updated with the
                                                                                    next highest priority interrupt. */
#define FLASHCTL_IIDX_STAT_NO_INTR               ((uint32_t)0x00000000U)         /* !< No Interrupt Pending */
#define FLASHCTL_IIDX_STAT_DONE                  ((uint32_t)0x00000001U)         /* !< DONE Interrupt Pending */

/* FLASHCTL_IMASK Bits */
/* FLASHCTL_IMASK[DONE] Bits */
#define FLASHCTL_IMASK_DONE_OFS                  (0)                             /* !< DONE Offset */
#define FLASHCTL_IMASK_DONE_MASK                 ((uint32_t)0x00000001U)         /* !< Interrupt mask for DONE: 0:
                                                                                    Interrupt is disabled in MIS register
                                                                                    1: Interrupt is enabled in MIS
                                                                                    register */
#define FLASHCTL_IMASK_DONE_DISABLED             ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define FLASHCTL_IMASK_DONE_ENABLED              ((uint32_t)0x00000001U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in [IPSTANDARD.MIS] will be set */

/* FLASHCTL_RIS Bits */
/* FLASHCTL_RIS[DONE] Bits */
#define FLASHCTL_RIS_DONE_OFS                    (0)                             /* !< DONE Offset */
#define FLASHCTL_RIS_DONE_MASK                   ((uint32_t)0x00000001U)         /* !< NoWrapper operation completed. This
                                                                                    interrupt bit is set by firmware or
                                                                                    the corresponding bit in the ISET
                                                                                    register. It is cleared by the
                                                                                    corresponding bit in in the ICLR
                                                                                    register or reading the IIDX register
                                                                                    when this interrupt is the highest
                                                                                    priority. */
#define FLASHCTL_RIS_DONE_CLR                    ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define FLASHCTL_RIS_DONE_SET                    ((uint32_t)0x00000001U)         /* !< Interrupt occurred */

/* FLASHCTL_MIS Bits */
/* FLASHCTL_MIS[DONE] Bits */
#define FLASHCTL_MIS_DONE_OFS                    (0)                             /* !< DONE Offset */
#define FLASHCTL_MIS_DONE_MASK                   ((uint32_t)0x00000001U)         /* !< NoWrapper operation completed. This
                                                                                    masked interrupt bit reflects the
                                                                                    bitwise AND of the corresponding RIS
                                                                                    and IMASK bits. */
#define FLASHCTL_MIS_DONE_CLR                    ((uint32_t)0x00000000U)         /* !< Masked interrupt did not occur */
#define FLASHCTL_MIS_DONE_SET                    ((uint32_t)0x00000001U)         /* !< Masked interrupt occurred */

/* FLASHCTL_ISET Bits */
/* FLASHCTL_ISET[DONE] Bits */
#define FLASHCTL_ISET_DONE_OFS                   (0)                             /* !< DONE Offset */
#define FLASHCTL_ISET_DONE_MASK                  ((uint32_t)0x00000001U)         /* !< 0: No effect 1: Set the DONE
                                                                                    interrupt in the RIS register */
#define FLASHCTL_ISET_DONE_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define FLASHCTL_ISET_DONE_SET                   ((uint32_t)0x00000001U)         /* !< Set [IPSTANDARD.RIS] bit */

/* FLASHCTL_ICLR Bits */
/* FLASHCTL_ICLR[DONE] Bits */
#define FLASHCTL_ICLR_DONE_OFS                   (0)                             /* !< DONE Offset */
#define FLASHCTL_ICLR_DONE_MASK                  ((uint32_t)0x00000001U)         /* !< 0: No effect 1: Clear the DONE
                                                                                    interrupt in the RIS register */
#define FLASHCTL_ICLR_DONE_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define FLASHCTL_ICLR_DONE_CLR                   ((uint32_t)0x00000001U)         /* !< Clear [IPSTANDARD.RIS] bit */

/* FLASHCTL_EVT_MODE Bits */
/* FLASHCTL_EVT_MODE[INT0_CFG] Bits */
#define FLASHCTL_EVT_MODE_INT0_CFG_OFS           (0)                             /* !< INT0_CFG Offset */
#define FLASHCTL_EVT_MODE_INT0_CFG_MASK          ((uint32_t)0x00000003U)         /* !< Event line mode select for
                                                                                    peripheral event */
#define FLASHCTL_EVT_MODE_INT0_CFG_DISABLE       ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define FLASHCTL_EVT_MODE_INT0_CFG_SOFTWARE      ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define FLASHCTL_EVT_MODE_INT0_CFG_HARDWARE      ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. Hardware should clear
                                                                                    the RIS. */

/* FLASHCTL_DESC Bits */
/* FLASHCTL_DESC[MINREV] Bits */
#define FLASHCTL_DESC_MINREV_OFS                 (0)                             /* !< MINREV Offset */
#define FLASHCTL_DESC_MINREV_MASK                ((uint32_t)0x0000000FU)         /* !< Minor Revision */
#define FLASHCTL_DESC_MINREV_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MINREV_MAXIMUM             ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* FLASHCTL_DESC[MAJREV] Bits */
#define FLASHCTL_DESC_MAJREV_OFS                 (4)                             /* !< MAJREV Offset */
#define FLASHCTL_DESC_MAJREV_MASK                ((uint32_t)0x000000F0U)         /* !< Major Revision */
#define FLASHCTL_DESC_MAJREV_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MAJREV_MAXIMUM             ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* FLASHCTL_DESC[INSTNUM] Bits */
#define FLASHCTL_DESC_INSTNUM_OFS                (8)                             /* !< INSTNUM Offset */
#define FLASHCTL_DESC_INSTNUM_MASK               ((uint32_t)0x00000F00U)         /* !< Instance number */
#define FLASHCTL_DESC_INSTNUM_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_INSTNUM_MAXIMUM            ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* FLASHCTL_DESC[FEATUREVER] Bits */
#define FLASHCTL_DESC_FEATUREVER_OFS             (12)                            /* !< FEATUREVER Offset */
#define FLASHCTL_DESC_FEATUREVER_MASK            ((uint32_t)0x0000F000U)         /* !< Feature set */
#define FLASHCTL_DESC_FEATUREVER_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define FLASHCTL_DESC_FEATUREVER_MAXIMUM         ((uint32_t)0x0000F000U)         /* !< Maximum Value */
/* FLASHCTL_DESC[MODULEID] Bits */
#define FLASHCTL_DESC_MODULEID_OFS               (16)                            /* !< MODULEID Offset */
#define FLASHCTL_DESC_MODULEID_MASK              ((uint32_t)0xFFFF0000U)         /* !< Module ID */
#define FLASHCTL_DESC_MODULEID_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MODULEID_MAXIMUM           ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* FLASHCTL_CMDEXEC Bits */
/* FLASHCTL_CMDEXEC[VAL] Bits */
#define FLASHCTL_CMDEXEC_VAL_OFS                 (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDEXEC_VAL_MASK                ((uint32_t)0x00000001U)         /* !< Command Execute value Initiates
                                                                                    execution of the command specified in
                                                                                    the CMDTYPE register. */
#define FLASHCTL_CMDEXEC_VAL_NOEXECUTE           ((uint32_t)0x00000000U)         /* !< Command will not execute or is not
                                                                                    executing in NoWrapper */
#define FLASHCTL_CMDEXEC_VAL_EXECUTE             ((uint32_t)0x00000001U)         /* !< Command will execute or is
                                                                                    executing in NoWrapper */

/* FLASHCTL_CMDTYPE Bits */
/* FLASHCTL_CMDTYPE[COMMAND] Bits */
#define FLASHCTL_CMDTYPE_COMMAND_OFS             (0)                             /* !< COMMAND Offset */
#define FLASHCTL_CMDTYPE_COMMAND_MASK            ((uint32_t)0x00000007U)         /* !< Command type */
#define FLASHCTL_CMDTYPE_COMMAND_NOOP            ((uint32_t)0x00000000U)         /* !< No Operation */
#define FLASHCTL_CMDTYPE_COMMAND_PROGRAM         ((uint32_t)0x00000001U)         /* !< Program */
#define FLASHCTL_CMDTYPE_COMMAND_ERASE           ((uint32_t)0x00000002U)         /* !< Erase */
#define FLASHCTL_CMDTYPE_COMMAND_READVERIFY      ((uint32_t)0x00000003U)         /* !< Read Verify - Perform a standalone
                                                                                    read verify operation. */
#define FLASHCTL_CMDTYPE_COMMAND_MODECHANGE      ((uint32_t)0x00000004U)         /* !< Mode Change - Perform a mode change
                                                                                    only, no other operation. */
#define FLASHCTL_CMDTYPE_COMMAND_CLEARSTATUS     ((uint32_t)0x00000005U)         /* !< Clear Status - Clear status bits in
                                                                                    FW_SMSTAT only. */
#define FLASHCTL_CMDTYPE_COMMAND_BLANKVERIFY     ((uint32_t)0x00000006U)         /* !< Blank Verify - Check whether a
                                                                                    flash word is in the erased state.
                                                                                    This command may only be used with
                                                                                    CMDTYPE.SIZE = ONEWORD */
/* FLASHCTL_CMDTYPE[SIZE] Bits */
#define FLASHCTL_CMDTYPE_SIZE_OFS                (4)                             /* !< SIZE Offset */
#define FLASHCTL_CMDTYPE_SIZE_MASK               ((uint32_t)0x00000070U)         /* !< Command size */
#define FLASHCTL_CMDTYPE_SIZE_ONEWORD            ((uint32_t)0x00000000U)         /* !< Operate on 1 flash word */
#define FLASHCTL_CMDTYPE_SIZE_TWOWORD            ((uint32_t)0x00000010U)         /* !< Operate on 2 flash words */
#define FLASHCTL_CMDTYPE_SIZE_FOURWORD           ((uint32_t)0x00000020U)         /* !< Operate on 4 flash words */
#define FLASHCTL_CMDTYPE_SIZE_EIGHTWORD          ((uint32_t)0x00000030U)         /* !< Operate on 8 flash words */
#define FLASHCTL_CMDTYPE_SIZE_SECTOR             ((uint32_t)0x00000040U)         /* !< Operate on a flash sector */
#define FLASHCTL_CMDTYPE_SIZE_BANK               ((uint32_t)0x00000050U)         /* !< Operate on an entire flash bank */

/* FLASHCTL_CMDCTL Bits */
/* FLASHCTL_CMDCTL[MODESEL] Bits */
#define FLASHCTL_CMDCTL_MODESEL_OFS              (0)                             /* !< MODESEL Offset */
#define FLASHCTL_CMDCTL_MODESEL_MASK             ((uint32_t)0x0000000FU)         /* !< Mode This field is only used for
                                                                                    the Mode Change command type.
                                                                                    Otherwise, bank and pump modes are
                                                                                    set automaticlly via the NW hardware. */
#define FLASHCTL_CMDCTL_MODESEL_READ             ((uint32_t)0x00000000U)         /* !< Read Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG0          ((uint32_t)0x00000002U)         /* !< Read Margin 0 Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG1          ((uint32_t)0x00000004U)         /* !< Read Margin 1 Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG0B         ((uint32_t)0x00000006U)         /* !< Read Margin 0B Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG1B         ((uint32_t)0x00000007U)         /* !< Read Margin 1B Mode */
#define FLASHCTL_CMDCTL_MODESEL_PGMVER           ((uint32_t)0x00000009U)         /* !< Program Verify Mode */
#define FLASHCTL_CMDCTL_MODESEL_PGMSW            ((uint32_t)0x0000000AU)         /* !< Program Single Word */
#define FLASHCTL_CMDCTL_MODESEL_ERASEVER         ((uint32_t)0x0000000BU)         /* !< Erase Verify Mode */
#define FLASHCTL_CMDCTL_MODESEL_ERASESECT        ((uint32_t)0x0000000CU)         /* !< Erase Sector */
#define FLASHCTL_CMDCTL_MODESEL_PGMMW            ((uint32_t)0x0000000EU)         /* !< Program Multiple Word */
#define FLASHCTL_CMDCTL_MODESEL_ERASEBNK         ((uint32_t)0x0000000FU)         /* !< Erase Bank */
/* FLASHCTL_CMDCTL[BANKSEL] Bits */
#define FLASHCTL_CMDCTL_BANKSEL_OFS              (4)                             /* !< BANKSEL Offset */
#define FLASHCTL_CMDCTL_BANKSEL_MASK             ((uint32_t)0x000001F0U)         /* !< Bank Select A specific Bank ID can
                                                                                    be written to this field to indicate
                                                                                    to which bank an  operation should be
                                                                                    applied if CMDCTL.ADDRXLATEOVR is
                                                                                    set. */
#define FLASHCTL_CMDCTL_BANKSEL_BANK0            ((uint32_t)0x00000010U)         /* !< Bank 0 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK1            ((uint32_t)0x00000020U)         /* !< Bank 1 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK2            ((uint32_t)0x00000040U)         /* !< Bank 2 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK3            ((uint32_t)0x00000080U)         /* !< Bank 3 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK4            ((uint32_t)0x00000100U)         /* !< Bank 4 */
/* FLASHCTL_CMDCTL[REGIONSEL] Bits */
#define FLASHCTL_CMDCTL_REGIONSEL_OFS            (9)                             /* !< REGIONSEL Offset */
#define FLASHCTL_CMDCTL_REGIONSEL_MASK           ((uint32_t)0x00001E00U)         /* !< Bank Region A specific region ID
                                                                                    can be written to this field to
                                                                                    indicate to which region an
                                                                                    operation should be applied if
                                                                                    CMDCTL.ADDRXLATEOVR is set. */
#define FLASHCTL_CMDCTL_REGIONSEL_MAIN           ((uint32_t)0x00000200U)         /* !< Main Region */
#define FLASHCTL_CMDCTL_REGIONSEL_NONMAIN        ((uint32_t)0x00000400U)         /* !< Non-Main Region */
#define FLASHCTL_CMDCTL_REGIONSEL_TRIM           ((uint32_t)0x00000800U)         /* !< Trim Region */
#define FLASHCTL_CMDCTL_REGIONSEL_ENGR           ((uint32_t)0x00001000U)         /* !< Engr Region */
/* FLASHCTL_CMDCTL[ECCGENOVR] Bits */
#define FLASHCTL_CMDCTL_ECCGENOVR_OFS            (17)                            /* !< ECCGENOVR Offset */
#define FLASHCTL_CMDCTL_ECCGENOVR_MASK           ((uint32_t)0x00020000U)         /* !< Override hardware generation of ECC
                                                                                    data for program.  Use data written
                                                                                    to  CMDDATAECC*. */
#define FLASHCTL_CMDCTL_ECCGENOVR_NOOVERRIDE     ((uint32_t)0x00000000U)         /* !< Do not override */
#define FLASHCTL_CMDCTL_ECCGENOVR_OVERRIDE       ((uint32_t)0x00020000U)         /* !< Override */
/* FLASHCTL_CMDCTL[ADDRXLATEOVR] Bits */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_OFS         (16)                            /* !< ADDRXLATEOVR Offset */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_MASK        ((uint32_t)0x00010000U)         /* !< Override hardware address
                                                                                    translation of address in CMDADDR
                                                                                    from a  system address to a bank
                                                                                    address and bank ID.  Use data
                                                                                    written to  CMDADDR directly as the
                                                                                    bank address.  Use the value written
                                                                                    to  CMDCTL.BANKSEL directly as the
                                                                                    bank ID.  Use the value written to
                                                                                    CMDCTL.REGIONSEL directly as the
                                                                                    region ID. */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_NOOVERRIDE  ((uint32_t)0x00000000U)         /* !< Do not override */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_OVERRIDE    ((uint32_t)0x00010000U)         /* !< Override */
/* FLASHCTL_CMDCTL[SSERASEDIS] Bits */
#define FLASHCTL_CMDCTL_SSERASEDIS_OFS           (20)                            /* !< SSERASEDIS Offset */
#define FLASHCTL_CMDCTL_SSERASEDIS_MASK          ((uint32_t)0x00100000U)         /* !< Disable Stair-Step Erase.  If set,
                                                                                    the default VHV trim voltage setting
                                                                                    will be used for all erase pulses. By
                                                                                    default, this bit is reset, meaning
                                                                                    that the VHV voltage will be stepped
                                                                                    during successive erase pulses.  The
                                                                                    step count, step voltage, begin and
                                                                                    end voltages are all hard-wired. */
#define FLASHCTL_CMDCTL_SSERASEDIS_ENABLE        ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_CMDCTL_SSERASEDIS_DISABLE       ((uint32_t)0x00100000U)         /* !< Disable */
/* FLASHCTL_CMDCTL[DATAVEREN] Bits */
#define FLASHCTL_CMDCTL_DATAVEREN_OFS            (21)                            /* !< DATAVEREN Offset */
#define FLASHCTL_CMDCTL_DATAVEREN_MASK           ((uint32_t)0x00200000U)         /* !< Enable invalid data verify.   This
                                                                                    checks for 0->1 transitions in the
                                                                                    memory when a program operation is
                                                                                    initiated.  If such a transition is
                                                                                    found, the program will fail with an
                                                                                    error without doing any programming. */
#define FLASHCTL_CMDCTL_DATAVEREN_DISABLE        ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_CMDCTL_DATAVEREN_ENABLE         ((uint32_t)0x00200000U)         /* !< Enable */

/* FLASHCTL_CMDADDR Bits */
/* FLASHCTL_CMDADDR[VAL] Bits */
#define FLASHCTL_CMDADDR_VAL_OFS                 (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDADDR_VAL_MASK                ((uint32_t)0xFFFFFFFFU)         /* !< Address value */
#define FLASHCTL_CMDADDR_VAL_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDADDR_VAL_MAXIMUM             ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDBYTEN Bits */
/* FLASHCTL_CMDBYTEN[VAL] Bits */
#define FLASHCTL_CMDBYTEN_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDBYTEN_VAL_MASK               ((uint32_t)0x0003FFFFU)         /* !< Command Byte Enable value. A 1-bit
                                                                                    per flash word byte value is placed
                                                                                    in this register. */
#define FLASHCTL_CMDBYTEN_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDBYTEN_VAL_MAXIMUM            ((uint32_t)0x0003FFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATAINDEX Bits */
/* FLASHCTL_CMDDATAINDEX[VAL] Bits */
#define FLASHCTL_CMDDATAINDEX_VAL_OFS            (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATAINDEX_VAL_MASK           ((uint32_t)0x00000007U)         /* !< Data register index */
#define FLASHCTL_CMDDATAINDEX_VAL_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATAINDEX_VAL_MAXIMUM        ((uint32_t)0x00000007U)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA0 Bits */
/* FLASHCTL_CMDDATA0[VAL] Bits */
#define FLASHCTL_CMDDATA0_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA0_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA0_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA0_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA1 Bits */
/* FLASHCTL_CMDDATA1[VAL] Bits */
#define FLASHCTL_CMDDATA1_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA1_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA1_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA1_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA2 Bits */
/* FLASHCTL_CMDDATA2[VAL] Bits */
#define FLASHCTL_CMDDATA2_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA2_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA2_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA2_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA3 Bits */
/* FLASHCTL_CMDDATA3[VAL] Bits */
#define FLASHCTL_CMDDATA3_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA3_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA3_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA3_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA4 Bits */
/* FLASHCTL_CMDDATA4[VAL] Bits */
#define FLASHCTL_CMDDATA4_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA4_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. T */
#define FLASHCTL_CMDDATA4_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA4_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA5 Bits */
/* FLASHCTL_CMDDATA5[VAL] Bits */
#define FLASHCTL_CMDDATA5_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA5_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA5_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA5_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA6 Bits */
/* FLASHCTL_CMDDATA6[VAL] Bits */
#define FLASHCTL_CMDDATA6_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA6_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA6_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA6_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA7 Bits */
/* FLASHCTL_CMDDATA7[VAL] Bits */
#define FLASHCTL_CMDDATA7_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA7_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA7_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA7_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA8 Bits */
/* FLASHCTL_CMDDATA8[VAL] Bits */
#define FLASHCTL_CMDDATA8_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA8_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA8_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA8_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA9 Bits */
/* FLASHCTL_CMDDATA9[VAL] Bits */
#define FLASHCTL_CMDDATA9_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA9_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA9_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA9_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA10 Bits */
/* FLASHCTL_CMDDATA10[VAL] Bits */
#define FLASHCTL_CMDDATA10_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA10_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA10_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA10_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA11 Bits */
/* FLASHCTL_CMDDATA11[VAL] Bits */
#define FLASHCTL_CMDDATA11_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA11_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA11_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA11_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA12 Bits */
/* FLASHCTL_CMDDATA12[VAL] Bits */
#define FLASHCTL_CMDDATA12_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA12_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA12_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA12_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA13 Bits */
/* FLASHCTL_CMDDATA13[VAL] Bits */
#define FLASHCTL_CMDDATA13_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA13_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA13_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA13_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA14 Bits */
/* FLASHCTL_CMDDATA14[VAL] Bits */
#define FLASHCTL_CMDDATA14_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA14_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA14_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA14_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA15 Bits */
/* FLASHCTL_CMDDATA15[VAL] Bits */
#define FLASHCTL_CMDDATA15_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA15_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA15_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA15_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA16 Bits */
/* FLASHCTL_CMDDATA16[VAL] Bits */
#define FLASHCTL_CMDDATA16_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA16_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA16_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA16_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA17 Bits */
/* FLASHCTL_CMDDATA17[VAL] Bits */
#define FLASHCTL_CMDDATA17_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA17_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA17_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA17_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA18 Bits */
/* FLASHCTL_CMDDATA18[VAL] Bits */
#define FLASHCTL_CMDDATA18_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA18_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA18_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA18_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA19 Bits */
/* FLASHCTL_CMDDATA19[VAL] Bits */
#define FLASHCTL_CMDDATA19_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA19_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA19_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA19_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA20 Bits */
/* FLASHCTL_CMDDATA20[VAL] Bits */
#define FLASHCTL_CMDDATA20_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA20_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA20_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA20_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA21 Bits */
/* FLASHCTL_CMDDATA21[VAL] Bits */
#define FLASHCTL_CMDDATA21_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA21_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA21_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA21_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA22 Bits */
/* FLASHCTL_CMDDATA22[VAL] Bits */
#define FLASHCTL_CMDDATA22_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA22_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA22_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA22_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA23 Bits */
/* FLASHCTL_CMDDATA23[VAL] Bits */
#define FLASHCTL_CMDDATA23_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA23_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA23_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA23_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA24 Bits */
/* FLASHCTL_CMDDATA24[VAL] Bits */
#define FLASHCTL_CMDDATA24_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA24_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA24_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA24_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA25 Bits */
/* FLASHCTL_CMDDATA25[VAL] Bits */
#define FLASHCTL_CMDDATA25_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA25_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA25_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA25_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA26 Bits */
/* FLASHCTL_CMDDATA26[VAL] Bits */
#define FLASHCTL_CMDDATA26_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA26_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA26_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA26_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA27 Bits */
/* FLASHCTL_CMDDATA27[VAL] Bits */
#define FLASHCTL_CMDDATA27_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA27_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA27_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA27_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA28 Bits */
/* FLASHCTL_CMDDATA28[VAL] Bits */
#define FLASHCTL_CMDDATA28_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA28_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA28_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA28_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA29 Bits */
/* FLASHCTL_CMDDATA29[VAL] Bits */
#define FLASHCTL_CMDDATA29_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA29_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA29_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA29_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA30 Bits */
/* FLASHCTL_CMDDATA30[VAL] Bits */
#define FLASHCTL_CMDDATA30_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA30_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA30_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA30_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA31 Bits */
/* FLASHCTL_CMDDATA31[VAL] Bits */
#define FLASHCTL_CMDDATA31_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA31_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA31_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA31_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATAECC0 Bits */
/* FLASHCTL_CMDDATAECC0[VAL0] Bits */
#define FLASHCTL_CMDDATAECC0_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC0_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC0_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC0_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC0[VAL1] Bits */
#define FLASHCTL_CMDDATAECC0_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC0_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC0_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC0_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC1 Bits */
/* FLASHCTL_CMDDATAECC1[VAL0] Bits */
#define FLASHCTL_CMDDATAECC1_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC1_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC1_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC1_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC1[VAL1] Bits */
#define FLASHCTL_CMDDATAECC1_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC1_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC1_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC1_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC2 Bits */
/* FLASHCTL_CMDDATAECC2[VAL0] Bits */
#define FLASHCTL_CMDDATAECC2_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC2_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC2_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC2_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC2[VAL1] Bits */
#define FLASHCTL_CMDDATAECC2_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC2_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC2_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC2_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC3 Bits */
/* FLASHCTL_CMDDATAECC3[VAL0] Bits */
#define FLASHCTL_CMDDATAECC3_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC3_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC3_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC3_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC3[VAL1] Bits */
#define FLASHCTL_CMDDATAECC3_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC3_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC3_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC3_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC4 Bits */
/* FLASHCTL_CMDDATAECC4[VAL0] Bits */
#define FLASHCTL_CMDDATAECC4_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC4_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC4_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC4_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC4[VAL1] Bits */
#define FLASHCTL_CMDDATAECC4_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC4_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC4_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC4_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC5 Bits */
/* FLASHCTL_CMDDATAECC5[VAL0] Bits */
#define FLASHCTL_CMDDATAECC5_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC5_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC5_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC5_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC5[VAL1] Bits */
#define FLASHCTL_CMDDATAECC5_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC5_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC5_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC5_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC6 Bits */
/* FLASHCTL_CMDDATAECC6[VAL0] Bits */
#define FLASHCTL_CMDDATAECC6_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC6_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC6_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC6_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC6[VAL1] Bits */
#define FLASHCTL_CMDDATAECC6_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC6_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC6_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC6_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC7 Bits */
/* FLASHCTL_CMDDATAECC7[VAL0] Bits */
#define FLASHCTL_CMDDATAECC7_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC7_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC7_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC7_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC7[VAL1] Bits */
#define FLASHCTL_CMDDATAECC7_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC7_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC7_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC7_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDWEPROTA Bits */
/* FLASHCTL_CMDWEPROTA[VAL] Bits */
#define FLASHCTL_CMDWEPROTA_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTA_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the flash
                                                                                    memory will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the flash memory will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the flash memory will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTA_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTA_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTB Bits */
/* FLASHCTL_CMDWEPROTB[VAL] Bits */
#define FLASHCTL_CMDWEPROTB_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTB_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects a group of 8
                                                                                    sectors.  When a bit is 1, the
                                                                                    associated 8 sectors in the flash
                                                                                    will be protected from program and
                                                                                    erase.  A maximum of 256 sectors can
                                                                                    be protected with this register. */
#define FLASHCTL_CMDWEPROTB_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTB_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTC Bits */
/* FLASHCTL_CMDWEPROTC[VAL] Bits */
#define FLASHCTL_CMDWEPROTC_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTC_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects a group of 8
                                                                                    sectors.  When a bit is 1, the
                                                                                    associated 8 sectors in the flash
                                                                                    will be protected from program and
                                                                                    erase.  Note that the sectors
                                                                                    protected with this register start at
                                                                                    sector 256 in the flash, where the
                                                                                    sectors protected by the CMDWEPROTB
                                                                                    register end. */
#define FLASHCTL_CMDWEPROTC_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTC_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTNM Bits */
/* FLASHCTL_CMDWEPROTNM[VAL] Bits */
#define FLASHCTL_CMDWEPROTNM_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTNM_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the non-main
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the non-main region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the non-main will be protected from
                                                                                    program 		and erase. */
#define FLASHCTL_CMDWEPROTNM_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTTR Bits */
/* FLASHCTL_CMDWEPROTTR[VAL] Bits */
#define FLASHCTL_CMDWEPROTTR_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTTR_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the engr
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the engr region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the engr region will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTTR_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTTR_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTEN Bits */
/* FLASHCTL_CMDWEPROTEN[VAL] Bits */
#define FLASHCTL_CMDWEPROTEN_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTEN_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the engr
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the engr region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the engr region will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTEN_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTEN_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CFGCMD Bits */
/* FLASHCTL_CFGCMD[WAITSTATE] Bits */
#define FLASHCTL_CFGCMD_WAITSTATE_OFS            (0)                             /* !< WAITSTATE Offset */
#define FLASHCTL_CFGCMD_WAITSTATE_MASK           ((uint32_t)0x0000000FU)         /* !< Wait State setting for program
                                                                                    verify, erase verify and read verify */
#define FLASHCTL_CFGCMD_WAITSTATE_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CFGCMD_WAITSTATE_MAXIMUM        ((uint32_t)0x0000000FU)         /* !< Maximum value */
/* FLASHCTL_CFGCMD[RDCLKSTREN] Bits */
#define FLASHCTL_CFGCMD_RDCLKSTREN_OFS           (4)                             /* !< RDCLKSTREN Offset */
#define FLASHCTL_CFGCMD_RDCLKSTREN_MASK          ((uint32_t)0x00000010U)         /* !< Enable pulse stretching when
                                                                                    generating a read clock to the flash
                                                                                    bank from the NoWrapper.  This
                                                                                    effectively divides the read clock
                                                                                    driven to the bank in order to avoid
                                                                                    minimum pulse width requirements at
                                                                                    the bank. */
#define FLASHCTL_CFGCMD_RDCLKSTREN_DISABLE       ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_CFGCMD_RDCLKSTREN_ENABLE        ((uint32_t)0x00000010U)         /* !< Enable */
/* FLASHCTL_CFGCMD[CTRLCLKSTREN] Bits */
#define FLASHCTL_CFGCMD_CTRLCLKSTREN_OFS         (5)                             /* !< CTRLCLKSTREN Offset */
#define FLASHCTL_CFGCMD_CTRLCLKSTREN_MASK        ((uint32_t)0x00000020U)         /* !< Enable pulse stretching when
                                                                                    generating a control clock to the
                                                                                    flash bank from the NoWrapper.  This
                                                                                    effectively divides the control clock
                                                                                    driven to the bank in order to avoid
                                                                                    minimum pulse width requirements at
                                                                                    the bank. */
#define FLASHCTL_CFGCMD_CTRLCLKSTREN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_CFGCMD_CTRLCLKSTREN_ENABLE      ((uint32_t)0x00000020U)         /* !< Enable */
/* FLASHCTL_CFGCMD[HOLDCLKSTREN] Bits */
#define FLASHCTL_CFGCMD_HOLDCLKSTREN_OFS         (6)                             /* !< HOLDCLKSTREN Offset */
#define FLASHCTL_CFGCMD_HOLDCLKSTREN_MASK        ((uint32_t)0x00000040U)         /* !< Enable pulse stretching for the
                                                                                    clocking of the hold latches for
                                                                                    inputs to the flash bank.  This
                                                                                    effectively divides the flash
                                                                                    controller internal clock in order to
                                                                                    create a 50/50 duty cycle clock for
                                                                                    hold latching. */
#define FLASHCTL_CFGCMD_HOLDCLKSTREN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_CFGCMD_HOLDCLKSTREN_ENABLE      ((uint32_t)0x00000040U)         /* !< Enable */

/* FLASHCTL_CFGPCNT Bits */
/* FLASHCTL_CFGPCNT[MAXPCNTOVR] Bits */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_OFS          (0)                             /* !< MAXPCNTOVR Offset */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_MASK         ((uint32_t)0x00000001U)         /* !< Override hard-wired maximum pulse
                                                                                    count.  If MAXERSPCNTOVR is not set,
                                                                                    then setting this value alone will
                                                                                    override the max pulse count for both
                                                                                    program and erase.  If MAXERSPCNTOVR
                                                                                    is set, then this bit will only
                                                                                    control the max pulse count setting
                                                                                    for program. By default, this bit is
                                                                                    0, and a hard-wired max pulse count
                                                                                    is used. */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_DEFAULT      ((uint32_t)0x00000000U)         /* !< Use hard-wired (default) value for
                                                                                    maximum pulse count */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_OVERRIDE     ((uint32_t)0x00000001U)         /* !< Use value from MAXPCNTVAL field as
                                                                                    maximum puse count */
/* FLASHCTL_CFGPCNT[MAXPCNTVAL] Bits */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_OFS          (4)                             /* !< MAXPCNTVAL Offset */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MASK         ((uint32_t)0x00000FF0U)         /* !< Override maximum pulse counter with
                                                                                    this value.   If MAXPCNTOVR = 0, then
                                                                                    this field is ignored. If MAXPCNTOVR
                                                                                    = 1 and MAXERSPCNTOVR = 0, then this
                                                                                    value will be used  to override the
                                                                                    max pulse count for both program and
                                                                                    erase.  Full max value will be {4'h0,
                                                                                    MAXPCNTVAL} . If MAXPCNTOVR = 1 and
                                                                                    MAXERSPCNTOVR = 1, then this value
                                                                                    will be used to override the max
                                                                                    pulse count for program only.  Full
                                                                                    max value will be {4'h0, MAXPCNTVAL}. */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MINIMUM      ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MAXIMUM      ((uint32_t)0x00000FF0U)         /* !< Maximum value */
/* FLASHCTL_CFGPCNT[MAXERSPCNTOVR] Bits */
#define FLASHCTL_CFGPCNT_MAXERSPCNTOVR_OFS       (16)                            /* !< MAXERSPCNTOVR Offset */
#define FLASHCTL_CFGPCNT_MAXERSPCNTOVR_MASK      ((uint32_t)0x00010000U)         /* !< Override hard-wired maximum pulse
                                                                                    count for erase.  If set, then the
                                                                                    value in MAXERSPCNTVAL will be used
                                                                                    as the max pulse count for erase
                                                                                    operations. By default, this bit is
                                                                                    0, and a hard-wired max pulse count
                                                                                    is used. */
#define FLASHCTL_CFGPCNT_MAXERSPCNTOVR_DEFAULT   ((uint32_t)0x00000000U)         /* !< Use hard-wired (default) value for
                                                                                    maximum pulse count */
#define FLASHCTL_CFGPCNT_MAXERSPCNTOVR_OVERRIDE  ((uint32_t)0x00010000U)         /* !< Use value from MAXERSPCNTVAL field
                                                                                    as maximum erase pulse count */
/* FLASHCTL_CFGPCNT[MAXERSPCNTVAL] Bits */
#define FLASHCTL_CFGPCNT_MAXERSPCNTVAL_OFS       (20)                            /* !< MAXERSPCNTVAL Offset */
#define FLASHCTL_CFGPCNT_MAXERSPCNTVAL_MASK      ((uint32_t)0xFFF00000U)         /* !< Override maximum pulse count for
                                                                                    erase with this value.   If
                                                                                    MAXERSPCNTOVR = 0, then this field is
                                                                                    ignored. If MAXERSPCNTOVR = 1, then
                                                                                    this value will be used  to override
                                                                                    the max pulse count for erase. */
#define FLASHCTL_CFGPCNT_MAXERSPCNTVAL_MINIMUM   ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CFGPCNT_MAXERSPCNTVAL_MAXIMUM   ((uint32_t)0xFFF00000U)         /* !< Maximum value */

/* FLASHCTL_STATCMD Bits */
/* FLASHCTL_STATCMD[CMDDONE] Bits */
#define FLASHCTL_STATCMD_CMDDONE_OFS             (0)                             /* !< CMDDONE Offset */
#define FLASHCTL_STATCMD_CMDDONE_MASK            ((uint32_t)0x00000001U)         /* !< Command Done */
#define FLASHCTL_STATCMD_CMDDONE_STATNOTDONE     ((uint32_t)0x00000000U)         /* !< Not Done */
#define FLASHCTL_STATCMD_CMDDONE_STATDONE        ((uint32_t)0x00000001U)         /* !< Done */
/* FLASHCTL_STATCMD[CMDPASS] Bits */
#define FLASHCTL_STATCMD_CMDPASS_OFS             (1)                             /* !< CMDPASS Offset */
#define FLASHCTL_STATCMD_CMDPASS_MASK            ((uint32_t)0x00000002U)         /* !< Command Pass - valid when CMD_DONE
                                                                                    field is 1 */
#define FLASHCTL_STATCMD_CMDPASS_STATFAIL        ((uint32_t)0x00000000U)         /* !< Fail */
#define FLASHCTL_STATCMD_CMDPASS_STATPASS        ((uint32_t)0x00000002U)         /* !< Pass */
/* FLASHCTL_STATCMD[CMDINPROGRESS] Bits */
#define FLASHCTL_STATCMD_CMDINPROGRESS_OFS       (2)                             /* !< CMDINPROGRESS Offset */
#define FLASHCTL_STATCMD_CMDINPROGRESS_MASK      ((uint32_t)0x00000004U)         /* !< Command In Progress */
#define FLASHCTL_STATCMD_CMDINPROGRESS_STATCOMPLETE ((uint32_t)0x00000000U)         /* !< Complete */
#define FLASHCTL_STATCMD_CMDINPROGRESS_STATINPROGRESS ((uint32_t)0x00000004U)         /* !< In Progress */
/* FLASHCTL_STATCMD[FAILWEPROT] Bits */
#define FLASHCTL_STATCMD_FAILWEPROT_OFS          (4)                             /* !< FAILWEPROT Offset */
#define FLASHCTL_STATCMD_FAILWEPROT_MASK         ((uint32_t)0x00000010U)         /* !< Command failed due to Write/Erase
                                                                                    Protect Sector Violation */
#define FLASHCTL_STATCMD_FAILWEPROT_STATNOFAIL   ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILWEPROT_STATFAIL     ((uint32_t)0x00000010U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILVERIFY] Bits */
#define FLASHCTL_STATCMD_FAILVERIFY_OFS          (5)                             /* !< FAILVERIFY Offset */
#define FLASHCTL_STATCMD_FAILVERIFY_MASK         ((uint32_t)0x00000020U)         /* !< Command failed due to verify error */
#define FLASHCTL_STATCMD_FAILVERIFY_STATNOFAIL   ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILVERIFY_STATFAIL     ((uint32_t)0x00000020U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILMISC] Bits */
#define FLASHCTL_STATCMD_FAILMISC_OFS            (12)                            /* !< FAILMISC Offset */
#define FLASHCTL_STATCMD_FAILMISC_MASK           ((uint32_t)0x00001000U)         /* !< Command failed due to error other
                                                                                    than write/erase protect violation or
                                                                                    verify error.  This is an extra bit
                                                                                    in case a new failure mechanism is
                                                                                    added which requires a status bit. */
#define FLASHCTL_STATCMD_FAILMISC_STATNOFAIL     ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILMISC_STATFAIL       ((uint32_t)0x00001000U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILILLADDR] Bits */
#define FLASHCTL_STATCMD_FAILILLADDR_OFS         (6)                             /* !< FAILILLADDR Offset */
#define FLASHCTL_STATCMD_FAILILLADDR_MASK        ((uint32_t)0x00000040U)         /* !< Command failed due to the use of an
                                                                                    illegal address */
#define FLASHCTL_STATCMD_FAILILLADDR_STATNOFAIL  ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILILLADDR_STATFAIL    ((uint32_t)0x00000040U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILMODE] Bits */
#define FLASHCTL_STATCMD_FAILMODE_OFS            (7)                             /* !< FAILMODE Offset */
#define FLASHCTL_STATCMD_FAILMODE_MASK           ((uint32_t)0x00000080U)         /* !< Command failed because a bank has
                                                                                    been set to a mode other than READ.
                                                                                    Program and Erase commands cannot be
                                                                                    initiated unless all banks are in
                                                                                    READ mode. */
#define FLASHCTL_STATCMD_FAILMODE_STATNOFAIL     ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILMODE_STATFAIL       ((uint32_t)0x00000080U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILINVDATA] Bits */
#define FLASHCTL_STATCMD_FAILINVDATA_OFS         (8)                             /* !< FAILINVDATA Offset */
#define FLASHCTL_STATCMD_FAILINVDATA_MASK        ((uint32_t)0x00000100U)         /* !< Program command failed because an
                                                                                    attempt was made to program a stored
                                                                                    0 value to a 1. */
#define FLASHCTL_STATCMD_FAILINVDATA_STATNOFAIL  ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILINVDATA_STATFAIL    ((uint32_t)0x00000100U)         /* !< Fail */

/* FLASHCTL_STATADDR Bits */
/* FLASHCTL_STATADDR[BANKADDR] Bits */
#define FLASHCTL_STATADDR_BANKADDR_OFS           (0)                             /* !< BANKADDR Offset */
#define FLASHCTL_STATADDR_BANKADDR_MASK          ((uint32_t)0x0000FFFFU)         /* !< Current Bank Address A bank offset
                                                                                    address is stored in this register. */
#define FLASHCTL_STATADDR_BANKADDR_MINIMUM       ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_STATADDR_BANKADDR_MAXIMUM       ((uint32_t)0x0000FFFFU)         /* !< Maximum value */
/* FLASHCTL_STATADDR[BANKID] Bits */
#define FLASHCTL_STATADDR_BANKID_OFS             (21)                            /* !< BANKID Offset */
#define FLASHCTL_STATADDR_BANKID_MASK            ((uint32_t)0x03E00000U)         /* !< Current Bank ID A bank indicator is
                                                                                    stored in this register which
                                                                                    represents the current bank on which
                                                                                    the state  machine is operating.
                                                                                    There is 1 bit per bank. */
#define FLASHCTL_STATADDR_BANKID_BANK0           ((uint32_t)0x00200000U)         /* !< Bank 0 */
#define FLASHCTL_STATADDR_BANKID_BANK1           ((uint32_t)0x00400000U)         /* !< Bank 1 */
#define FLASHCTL_STATADDR_BANKID_BANK2           ((uint32_t)0x00800000U)         /* !< Bank 2 */
#define FLASHCTL_STATADDR_BANKID_BANK3           ((uint32_t)0x01000000U)         /* !< Bank 3 */
#define FLASHCTL_STATADDR_BANKID_BANK4           ((uint32_t)0x02000000U)         /* !< Bank 4 */
/* FLASHCTL_STATADDR[REGIONID] Bits */
#define FLASHCTL_STATADDR_REGIONID_OFS           (16)                            /* !< REGIONID Offset */
#define FLASHCTL_STATADDR_REGIONID_MASK          ((uint32_t)0x001F0000U)         /* !< Current Region ID A region
                                                                                    indicator is stored in this register
                                                                                    which represents the current flash
                                                                                    region on which the state  machine is
                                                                                    operating. */
#define FLASHCTL_STATADDR_REGIONID_MAIN          ((uint32_t)0x00010000U)         /* !< Main Region */
#define FLASHCTL_STATADDR_REGIONID_NONMAIN       ((uint32_t)0x00020000U)         /* !< Non-Main Region */
#define FLASHCTL_STATADDR_REGIONID_TRIM          ((uint32_t)0x00040000U)         /* !< Trim Region */
#define FLASHCTL_STATADDR_REGIONID_ENGR          ((uint32_t)0x00080000U)         /* !< Engr Region */

/* FLASHCTL_STATPCNT Bits */
/* FLASHCTL_STATPCNT[PULSECNT] Bits */
#define FLASHCTL_STATPCNT_PULSECNT_OFS           (0)                             /* !< PULSECNT Offset */
#define FLASHCTL_STATPCNT_PULSECNT_MASK          ((uint32_t)0x00000FFFU)         /* !< Current Pulse Counter Value */
#define FLASHCTL_STATPCNT_PULSECNT_MINIMUM       ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_STATPCNT_PULSECNT_MAXIMUM       ((uint32_t)0x00000FFFU)         /* !< Maximum value */

/* FLASHCTL_STATMODE Bits */
/* FLASHCTL_STATMODE[BANKNOTINRD] Bits */
#define FLASHCTL_STATMODE_BANKNOTINRD_OFS        (0)                             /* !< BANKNOTINRD Offset */
#define FLASHCTL_STATMODE_BANKNOTINRD_MASK       ((uint32_t)0x0000001FU)         /* !< Bank not in read mode. Indicates
                                                                                    which banks are not in READ mode.
                                                                                    There is 1 bit per bank. */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK0      ((uint32_t)0x00000001U)         /* !< Bank 0 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK1      ((uint32_t)0x00000002U)         /* !< Bank 1 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK2      ((uint32_t)0x00000004U)         /* !< Bank 2 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK3      ((uint32_t)0x00000008U)         /* !< Bank 3 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK4      ((uint32_t)0x00000010U)         /* !< Bank 4 */
/* FLASHCTL_STATMODE[BANKMODE] Bits */
#define FLASHCTL_STATMODE_BANKMODE_OFS           (8)                             /* !< BANKMODE Offset */
#define FLASHCTL_STATMODE_BANKMODE_MASK          ((uint32_t)0x00000F00U)         /* !< Indicates mode of bank(s) that are
                                                                                    not in READ mode */
#define FLASHCTL_STATMODE_BANKMODE_READ          ((uint32_t)0x00000000U)         /* !< Read Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG0       ((uint32_t)0x00000200U)         /* !< Read Margin 0 Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG1       ((uint32_t)0x00000400U)         /* !< Read Margin 1 Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG0B      ((uint32_t)0x00000600U)         /* !< Read Margin 0B Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG1B      ((uint32_t)0x00000700U)         /* !< Read Margin 1B Mode */
#define FLASHCTL_STATMODE_BANKMODE_PGMVER        ((uint32_t)0x00000900U)         /* !< Program Verify Mode */
#define FLASHCTL_STATMODE_BANKMODE_PGMSW         ((uint32_t)0x00000A00U)         /* !< Program Single Word */
#define FLASHCTL_STATMODE_BANKMODE_ERASEVER      ((uint32_t)0x00000B00U)         /* !< Erase Verify Mode */
#define FLASHCTL_STATMODE_BANKMODE_ERASESECT     ((uint32_t)0x00000C00U)         /* !< Erase Sector */
#define FLASHCTL_STATMODE_BANKMODE_PGMMW         ((uint32_t)0x00000E00U)         /* !< Program Multiple Word */
#define FLASHCTL_STATMODE_BANKMODE_ERASEBNK      ((uint32_t)0x00000F00U)         /* !< Erase Bank */
/* FLASHCTL_STATMODE[BANK2TRDY] Bits */
#define FLASHCTL_STATMODE_BANK2TRDY_OFS          (16)                            /* !< BANK2TRDY Offset */
#define FLASHCTL_STATMODE_BANK2TRDY_MASK         ((uint32_t)0x00010000U)         /* !< Bank 2T Ready. Bank(s) are ready
                                                                                    for 2T access.  This is accomplished
                                                                                    when the pump has fully driven power
                                                                                    rails to the bank(s). */
#define FLASHCTL_STATMODE_BANK2TRDY_FALSE        ((uint32_t)0x00000000U)         /* !< Not ready */
#define FLASHCTL_STATMODE_BANK2TRDY_TRUE         ((uint32_t)0x00010000U)         /* !< Ready */
/* FLASHCTL_STATMODE[BANK1TRDY] Bits */
#define FLASHCTL_STATMODE_BANK1TRDY_OFS          (17)                            /* !< BANK1TRDY Offset */
#define FLASHCTL_STATMODE_BANK1TRDY_MASK         ((uint32_t)0x00020000U)         /* !< Bank 1T Ready. Bank(s) are ready
                                                                                    for 1T access.  This is accomplished
                                                                                    when the bank and pump have been
                                                                                    trimmed. */
#define FLASHCTL_STATMODE_BANK1TRDY_FALSE        ((uint32_t)0x00000000U)         /* !< Not ready */
#define FLASHCTL_STATMODE_BANK1TRDY_TRUE         ((uint32_t)0x00020000U)         /* !< Ready */

/* FLASHCTL_GBLINFO0 Bits */
/* FLASHCTL_GBLINFO0[SECTORSIZE] Bits */
#define FLASHCTL_GBLINFO0_SECTORSIZE_OFS         (0)                             /* !< SECTORSIZE Offset */
#define FLASHCTL_GBLINFO0_SECTORSIZE_MASK        ((uint32_t)0x0000FFFFU)         /* !< Sector size in bytes */
#define FLASHCTL_GBLINFO0_SECTORSIZE_ONEKB       ((uint32_t)0x00000400U)         /* !< Sector size is ONEKB */
#define FLASHCTL_GBLINFO0_SECTORSIZE_TWOKB       ((uint32_t)0x00000800U)         /* !< Sector size is TWOKB */
/* FLASHCTL_GBLINFO0[NUMBANKS] Bits */
#define FLASHCTL_GBLINFO0_NUMBANKS_OFS           (16)                            /* !< NUMBANKS Offset */
#define FLASHCTL_GBLINFO0_NUMBANKS_MASK          ((uint32_t)0x00070000U)         /* !< Number of banks instantiated
                                                                                    Minimum:	1 Maximum:	5 */
#define FLASHCTL_GBLINFO0_NUMBANKS_MINIMUM       ((uint32_t)0x00010000U)         /* !< Minimum value */
#define FLASHCTL_GBLINFO0_NUMBANKS_MAXIMUM       ((uint32_t)0x00050000U)         /* !< Maximum value */

/* FLASHCTL_GBLINFO1 Bits */
/* FLASHCTL_GBLINFO1[DATAWIDTH] Bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_OFS          (0)                             /* !< DATAWIDTH Offset */
#define FLASHCTL_GBLINFO1_DATAWIDTH_MASK         ((uint32_t)0x000000FFU)         /* !< Data width in bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_W64BIT       ((uint32_t)0x00000040U)         /* !< Data width is 64 bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_W128BIT      ((uint32_t)0x00000080U)         /* !< Data width is 128 bits */
/* FLASHCTL_GBLINFO1[ECCWIDTH] Bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_OFS           (8)                             /* !< ECCWIDTH Offset */
#define FLASHCTL_GBLINFO1_ECCWIDTH_MASK          ((uint32_t)0x00001F00U)         /* !< ECC data width in bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W0BIT         ((uint32_t)0x00000000U)         /* !< ECC data width is 0.  ECC not used. */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W8BIT         ((uint32_t)0x00000800U)         /* !< ECC data width is 8 bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W16BIT        ((uint32_t)0x00001000U)         /* !< ECC data width is 16 bits */
/* FLASHCTL_GBLINFO1[REDWIDTH] Bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_OFS           (16)                            /* !< REDWIDTH Offset */
#define FLASHCTL_GBLINFO1_REDWIDTH_MASK          ((uint32_t)0x00070000U)         /* !< Redundant data width in bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_W0BIT         ((uint32_t)0x00000000U)         /* !< Redundant data width is 0.
                                                                                    Redundancy/Repair not present. */
#define FLASHCTL_GBLINFO1_REDWIDTH_W2BIT         ((uint32_t)0x00020000U)         /* !< Redundant data width is 2 bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_W4BIT         ((uint32_t)0x00040000U)         /* !< Redundant data width is 4 bits */

/* FLASHCTL_GBLINFO2 Bits */
/* FLASHCTL_GBLINFO2[DATAREGISTERS] Bits */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_OFS      (0)                             /* !< DATAREGISTERS Offset */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MASK     ((uint32_t)0x0000000FU)         /* !< Number of data registers present. */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MINIMUM  ((uint32_t)0x00000001U)         /* !< Minimum value of [DATAREGISTERS] */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MAXIMUM  ((uint32_t)0x00000008U)         /* !< Maximum value of [DATAREGISTERS] */

/* FLASHCTL_BANK0INFO0 Bits */
/* FLASHCTL_BANK0INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK0INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK0INFO1 Bits */
/* FLASHCTL_BANK0INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK0INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK0INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK1INFO0 Bits */
/* FLASHCTL_BANK1INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK1INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK1INFO1 Bits */
/* FLASHCTL_BANK1INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK1INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK1INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK2INFO0 Bits */
/* FLASHCTL_BANK2INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK2INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK2INFO1 Bits */
/* FLASHCTL_BANK2INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK2INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK2INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK3INFO0 Bits */
/* FLASHCTL_BANK3INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK3INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK3INFO1 Bits */
/* FLASHCTL_BANK3INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK3INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK3INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK4INFO0 Bits */
/* FLASHCTL_BANK4INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK4INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK4INFO1 Bits */
/* FLASHCTL_BANK4INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK4INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK4INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_flashctl__include */