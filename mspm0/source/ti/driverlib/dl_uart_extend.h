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
/*!****************************************************************************
 *  @file       dl_uart_extend.h
 *  @brief      UART Driver Library
 *  @defgroup   UARTEXT UART Extend (UART-Extend)
 *
 *  @anchor ti_dl_dl_uart_ext_Overview
 *  # Overview
 *
 *  The UART Extend Driver Library enables configuration of UART-Extend, which
 *  provides extended UART functionality for LIN, DALI, IrDA, ISO7816 and
 *  Manchester codec.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup UARTEXT
 * @{
 */
#ifndef ti_dl_dl_uart_extend__include
#define ti_dl_dl_uart_extend__include

#include <ti/driverlib/dl_uart.h>

#ifdef __MSPM0_HAS_UART_EXTD__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/**
 * @brief Redirects to common @ref DL_UART_Config
 *
 */
typedef DL_UART_Config                                   DL_UART_Extend_Config;

/**
 * @brief Redirects to common @ref DL_UART_ClockConfig
 *
 */
typedef DL_UART_ClockConfig                         DL_UART_Extend_ClockConfig;

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_DMA_DONE_TX
 */
#define DL_UART_EXTEND_INTERRUPT_DMA_DONE_TX    (DL_UART_INTERRUPT_DMA_DONE_TX)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_DMA_DONE_RX
 */
#define DL_UART_EXTEND_INTERRUPT_DMA_DONE_RX    (DL_UART_INTERRUPT_DMA_DONE_RX)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_CTS_DONE
 */
#define DL_UART_EXTEND_INTERRUPT_CTS_DONE          (DL_UART_INTERRUPT_CTS_DONE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LINC0_MATCH
 */
#define DL_UART_EXTEND_INTERRUPT_LINC0_MATCH    (DL_UART_INTERRUPT_LINC0_MATCH)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_EOT_DONE
 */
#define DL_UART_EXTEND_INTERRUPT_EOT_DONE          (DL_UART_INTERRUPT_EOT_DONE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_TX
 */
#define DL_UART_EXTEND_INTERRUPT_TX                      (DL_UART_INTERRUPT_TX)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_RX
 */
#define DL_UART_EXTEND_INTERRUPT_RX                      (DL_UART_INTERRUPT_RX)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LIN_RISING_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_LIN_RISING_EDGE                              \
                                            (DL_UART_INTERRUPT_LIN_RISING_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LIN_FALLING_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_LIN_FALLING_EDGE                             \
                                           (DL_UART_INTERRUPT_LIN_FALLING_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_RXD_POS_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_RXD_POS_EDGE  (DL_UART_INTERRUPT_RXD_POS_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_RXD_NEG_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_RXD_NEG_EDGE  (DL_UART_INTERRUPT_RXD_NEG_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_OVERRUN_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_OVERRUN_ERROR  DL_UART_INTERRUPT_OVERRUN_ERROR

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_BREAK_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_BREAK_ERROR      DL_UART_INTERRUPT_BREAK_ERROR

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_PARITY_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_PARITY_ERROR    DL_UART_INTERRUPT_PARITY_ERROR

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_FRAMING_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_FRAMING_ERROR  DL_UART_INTERRUPT_FRAMING_ERROR

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_RX_TIMEOUT_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_RX_TIMEOUT_ERROR                             \
                                             DL_UART_INTERRUPT_RX_TIMEOUT_ERROR

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_NOISE_ERROR
 */
#define DL_UART_EXTEND_INTERRUPT_NOISE_ERROR                                  \
                                                  DL_UART_INTERRUPT_NOISE_ERROR

/*!
 * @brief UART interrupt index for DMA done on transmit
 */
#define DL_UART_EXTEND_IIDX_DMA_DONE_TX                DL_UART_IIDX_DMA_DONE_TX

/*!
 * @brief UART interrupt index for DMA done on receive
 */
#define DL_UART_EXTEND_IIDX_DMA_DONE_RX                DL_UART_IIDX_DMA_DONE_RX

/*!
 * @brief UART interrupt index for clear to send
 */
#define DL_UART_EXTEND_IIDX_CTS_DONE                      DL_UART_IIDX_CTS_DONE

/*!
 * @brief UART interrupt index for 9-bit mode address match
 */
#define DL_UART_EXTEND_IIDX_ADDRESS_MATCH            DL_UART_IIDX_ADDRESS_MATCH

/*!
 * @brief UART interrupt index for end of transmission
 */
#define DL_UART_EXTEND_IIDX_EOT_DONE                      DL_UART_IIDX_EOT_DONE

/*!
 * @brief UART interrupt index for UART transmit
 */
#define DL_UART_EXTEND_IIDX_TX                                  DL_UART_IIDX_TX

/*!
 * @brief UART interrupt index for UART receive
 */
#define DL_UART_EXTEND_IIDX_RX                                  DL_UART_IIDX_RX

 /*!
 * @brief UART interrupt index for LIN hardware counter overflow
 */
#define DL_UART_EXTEND_IIDX_LIN_COUNTER_OVERFLOW                              \
                                              DL_UART_IIDX_LIN_COUNTER_OVERFLOW

/*!
 * @brief UART interrupt index for LIN rising edge LINC1
 */
#define DL_UART_EXTEND_IIDX_LIN_RISING_EDGE        DL_UART_IIDX_LIN_RISING_EDGE

/*!
 * @brief UART interrupt index for LIN falling edge LINC0
 */
#define DL_UART_EXTEND_IIDX_LIN_FALLING_EDGE      DL_UART_IIDX_LIN_FALLING_EDGE

/*!
 * @brief UART interrupt index for positive edge on UARTxRXD
 */
#define DL_UART_EXTEND_IIDX_RXD_POS_EDGE              DL_UART_IIDX_RXD_POS_EDGE

/*!
 * @brief UART interrupt index for negative edge on UARTxRXD
 */
#define DL_UART_EXTEND_IIDX_RXD_NEG_EDGE              DL_UART_IIDX_RXD_NEG_EDGE

/*!
 * @brief UART interrupt index for overrun error
 */
#define DL_UART_EXTEND_IIDX_OVERRUN_ERROR            DL_UART_IIDX_OVERRUN_ERROR

/*!
 * @brief UART interrupt index for break error
 */
#define DL_UART_EXTEND_IIDX_BREAK_ERROR                DL_UART_IIDX_BREAK_ERROR

/*!
 * @brief UART interrupt index for parity error
 */
#define DL_UART_EXTEND_IIDX_PARITY_ERROR              DL_UART_IIDX_PARITY_ERROR

/*!
 * @brief UART interrupt index for framing error
 */
#define DL_UART_EXTEND_IIDX_FRAMING_ERROR            DL_UART_IIDX_FRAMING_ERROR

/*!
 * @brief UART interrupt index for receive timeout
 */
#define DL_UART_EXTEND_IIDX_RX_TIMEOUT_ERROR      DL_UART_IIDX_RX_TIMEOUT_ERROR

/*!
 * @brief UART interrupt index for noise error
 */
#define DL_UART_EXTEND_IIDX_NOISE_ERROR                DL_UART_IIDX_NOISE_ERROR

/*!
 * @brief UART interrupt index for no interrupt
 */
#define DL_UART_EXTEND_IIDX_NO_INTERRUPT              DL_UART_IIDX_NO_INTERRUPT

/*!
 * @brief Redirects to common @ref DL_UART_DMA_IIDX_RX_TRIGGER
 */
#define DL_UART_EXTEND_DMA_IIDX_RX_TRIGGER          DL_UART_DMA_IIDX_RX_TRIGGER

/*!
 * @brief Redirects to common @ref DL_UART_DMA_IIDX_RX_TIMEOUT_TRIGGER
 */
#define DL_UART_EXTEND_DMA_IIDX_RX_TIMEOUT_TRIGGER                            \
                                            DL_UART_DMA_IIDX_RX_TIMEOUT_TRIGGER

/*!
 * @brief Redirects to common @ref DL_UART_DMA_IIDX_TX_TRIGGER
 */
#define DL_UART_EXTEND_DMA_IIDX_TX_TRIGGER          DL_UART_DMA_IIDX_TX_TRIGGER

/*!
 * @brief Redirects to common @ref DL_UART_DMA_INTERRUPT_RX
 */
#define DL_UART_EXTEND_DMA_INTERRUPT_RX                DL_UART_DMA_INTERRUPT_RX

/*!
 * @brief Redirects to common @ref DL_UART_DMA_INTERRUPT_RX_TIMEOUT
 */
#define DL_UART_EXTEND_DMA_INTERRUPT_RX_TIMEOUT                               \
                                               DL_UART_DMA_INTERRUPT_RX_TIMEOUT

/*!
 * @brief Redirects to common @ref DL_UART_DMA_INTERRUPT_TX
 */
#define DL_UART_EXTEND_DMA_INTERRUPT_TX               DL_UART_DMA_INTERRUPT_TX

/*!
 * @brief Redirects to common @ref DL_UART_ERROR_OVERRUN
 */
#define DL_UART_EXTEND_ERROR_OVERRUN                      DL_UART_ERROR_OVERRUN

/*!
 * @brief Redirects to common @ref DL_UART_ERROR_BREAK
 */
#define DL_UART_EXTEND_ERROR_BREAK                          DL_UART_ERROR_BREAK

/*!
 * @brief Redirects to common @ref DL_UART_ERROR_PARITY
 */
#define DL_UART_EXTEND_ERROR_PARITY                        DL_UART_ERROR_PARITY

/*!
 * @brief Redirects to common @ref DL_UART_ERROR_FRAMING
 */
#define DL_UART_EXTEND_ERROR_FRAMING                      DL_UART_ERROR_FRAMING

/*!
 * @brief Redirects to common @ref DL_UART_PULSE_WIDTH_5_NS
 */
#define DL_UART_EXTEND_PULSE_WIDTH_5_NS                DL_UART_PULSE_WIDTH_5_NS

/*!
 * @brief Redirects to common @ref DL_UART_PULSE_WIDTH_10_NS
 */
#define DL_UART_EXTEND_PULSE_WIDTH_10_NS              DL_UART_PULSE_WIDTH_10_NS

/*!
 * @brief Redirects to common @ref DL_UART_PULSE_WIDTH_25_NS
 */
#define DL_UART_EXTEND_PULSE_WIDTH_25_NS              DL_UART_PULSE_WIDTH_25_NS

/*!
 * @brief Redirects to common @ref DL_UART_PULSE_WIDTH_50_NS
 */
#define DL_UART_EXTEND_PULSE_WIDTH_50_NS              DL_UART_PULSE_WIDTH_50_NS

/*!
 * @brief Redirects to common @ref DL_UART_OVERSAMPLING_RATE_16X
 */
#define DL_UART_EXTEND_OVERSAMPLING_RATE_16X      DL_UART_OVERSAMPLING_RATE_16X

/*!
 * @brief Redirects to common @ref DL_UART_OVERSAMPLING_RATE_8X
 */
#define DL_UART_EXTEND_OVERSAMPLING_RATE_8X        DL_UART_OVERSAMPLING_RATE_8X

/*!
 * @brief Redirects to common @ref DL_UART_OVERSAMPLING_RATE_3X
 */
#define DL_UART_EXTEND_OVERSAMPLING_RATE_3X        DL_UART_OVERSAMPLING_RATE_3X

/*!
 * @brief Redirects to common @ref DL_UART_PARITY_EVEN
 */
#define DL_UART_EXTEND_PARITY_EVEN                          DL_UART_PARITY_EVEN

/*!
 * @brief Redirects to common @ref DL_UART_PARITY_ODD
 */
#define DL_UART_EXTEND_PARITY_ODD                            DL_UART_PARITY_ODD

/*!
 * @brief Redirects to common @ref DL_UART_PARITY_STICK_ONE
 */
#define DL_UART_EXTEND_PARITY_STICK_ONE                DL_UART_PARITY_STICK_ONE

/*!
 * @brief Redirects to common @ref DL_UART_PARITY_STICK_ZERO
 */
#define DL_UART_EXTEND_PARITY_STICK_ZERO              DL_UART_PARITY_STICK_ZERO

/*!
 * @brief Redirects to common @ref DL_UART_PARITY_NONE
 */
#define DL_UART_EXTEND_PARITY_NONE                          DL_UART_PARITY_NONE

/*!
 * @brief Redirects to common @ref DL_UART_WORD_LENGTH_5_BITS
 */
#define DL_UART_EXTEND_WORD_LENGTH_5_BITS            DL_UART_WORD_LENGTH_5_BITS

/*!
 * @brief Redirects to common @ref DL_UART_WORD_LENGTH_6_BITS
 */
#define DL_UART_EXTEND_WORD_LENGTH_6_BITS            DL_UART_WORD_LENGTH_6_BITS

/*!
 * @brief Redirects to common @ref DL_UART_WORD_LENGTH_7_BITS
 */
#define DL_UART_EXTEND_WORD_LENGTH_7_BITS            DL_UART_WORD_LENGTH_7_BITS

/*!
 * @brief Redirects to common @ref DL_UART_WORD_LENGTH_8_BITS
 */
#define DL_UART_EXTEND_WORD_LENGTH_8_BITS            DL_UART_WORD_LENGTH_8_BITS

/*!
 * @brief Redirects to common @ref DL_UART_MODE_NORMAL
 */
#define DL_UART_EXTEND_MODE_NORMAL                          DL_UART_MODE_NORMAL

/*!
 * @brief Redirects to common @ref DL_UART_MODE_RS485
 */
#define DL_UART_EXTEND_MODE_RS485                            DL_UART_MODE_RS485

/*!
 * @brief Redirects to common @ref DL_UART_MODE_IDLE_LINE
 */
#define DL_UART_EXTEND_MODE_IDLE_LINE                    DL_UART_MODE_IDLE_LINE

/*!
 * @brief Redirects to common @ref DL_UART_MODE_ADDR_9_BIT
 */
#define DL_UART_EXTEND_MODE_ADDR_9_BIT                  DL_UART_MODE_ADDR_9_BIT

/*!
 * @brief Redirects to common @ref DL_UART_MODE_SMART_CARD
 */
#define DL_UART_EXTEND_MODE_SMART_CARD                  DL_UART_MODE_SMART_CARD

/*!
 * @brief Redirects to common @ref DL_UART_MODE_DALI
 */
#define DL_UART_EXTEND_MODE_DALI                              DL_UART_MODE_DALI

/*!
 * @brief Redirects to common @ref DL_UART_DIRECTION_TX
 */
#define DL_UART_EXTEND_DIRECTION_TX                        DL_UART_DIRECTION_TX

/*!
 * @brief Redirects to common @ref DL_UART_DIRECTION_RX
 */
#define DL_UART_EXTEND_DIRECTION_RX                        DL_UART_DIRECTION_RX

/*!
 * @brief Redirects to common @ref DL_UART_DIRECTION_TX_RX
 */
#define DL_UART_EXTEND_DIRECTION_TX_RX                  DL_UART_DIRECTION_TX_RX

/*!
 * @brief Redirects to common @ref DL_UART_DIRECTION_NONE
 */
#define DL_UART_EXTEND_DIRECTION_NONE                    DL_UART_DIRECTION_NONE

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_BUSCLK
 */
#define DL_UART_EXTEND_CLOCK_BUSCLK                        DL_UART_CLOCK_BUSCLK

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_MFCLK
 */
#define DL_UART_EXTEND_CLOCK_MFCLK                          DL_UART_CLOCK_MFCLK

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_LFCLK
 */
#define DL_UART_EXTEND_CLOCK_LFCLK                          DL_UART_CLOCK_LFCLK

/*!
 * @brief Redirects to common @ref DL_UART_FLOW_CONTROL_RTS
 */
#define DL_UART_EXTEND_FLOW_CONTROL_RTS                DL_UART_FLOW_CONTROL_RTS

/*!
 * @brief Redirects to common @ref DL_UART_FLOW_CONTROL_CTS
 */
#define DL_UART_EXTEND_FLOW_CONTROL_CTS                DL_UART_FLOW_CONTROL_CTS

/*!
 * @brief Redirects to common @ref DL_UART_FLOW_CONTROL_RTS_CTS
 */
#define DL_UART_EXTEND_FLOW_CONTROL_RTS_CTS        DL_UART_FLOW_CONTROL_RTS_CTS

/*!
 * @brief Redirects to common @ref DL_UART_FLOW_CONTROL_NONE
 */
#define DL_UART_EXTEND_FLOW_CONTROL_NONE              DL_UART_FLOW_CONTROL_NONE

/*!
 * @brief Redirects to common @ref DL_UART_RTS_ASSERT
 */
#define DL_UART_EXTEND_RTS_ASSERT                            DL_UART_RTS_ASSERT

/*!
 * @brief Redirects to common @ref DL_UART_RTS_DEASSERT
 */
#define DL_UART_EXTEND_RTS_DEASSERT                        DL_UART_RTS_DEASSERT

/*!
 * @brief Redirects to common @ref DL_UART_STOP_BITS_ONE
 */
#define DL_UART_EXTEND_STOP_BITS_ONE                      DL_UART_STOP_BITS_ONE

/*!
 * @brief Redirects to common @ref DL_UART_STOP_BITS_TWO
 */
#define DL_UART_EXTEND_STOP_BITS_TWO                      DL_UART_STOP_BITS_TWO

/*!
 * @brief Redirects to common @ref DL_UART_TXD_OUT_LOW
 */
#define DL_UART_EXTEND_TXD_OUT_LOW                          DL_UART_TXD_OUT_LOW

/*!
 * @brief Redirects to common @ref DL_UART_TXD_OUT_HIGH
 */
#define DL_UART_EXTEND_TXD_OUT_HIGH                        DL_UART_TXD_OUT_HIGH

/*!
 * @brief Redirects to common @ref DL_UART_TX_FIFO_LEVEL_3_4_EMPTY
 */
#define DL_UART_EXTEND_TX_FIFO_LEVEL_3_4_EMPTY  DL_UART_TX_FIFO_LEVEL_3_4_EMPTY

/*!
 * @brief Redirects to common @ref DL_UART_TX_FIFO_LEVEL_1_4_EMPTY
 */
#define DL_UART_EXTEND_TX_FIFO_LEVEL_1_4_EMPTY  DL_UART_TX_FIFO_LEVEL_1_4_EMPTY

/*!
 * @brief Redirects to common @ref DL_UART_TX_FIFO_LEVEL_EMPTY
 */
#define DL_UART_EXTEND_TX_FIFO_LEVEL_EMPTY          DL_UART_TX_FIFO_LEVEL_EMPTY

/*!
 * @brief Redirects to common @ref DL_UART_TX_FIFO_LEVEL_ONE_ENTRY
 */
#define DL_UART_EXTEND_TX_FIFO_LEVEL_ONE_ENTRY  DL_UART_TX_FIFO_LEVEL_ONE_ENTRY

/*!
 * @brief Redirects to common @ref DL_UART_RX_FIFO_LEVEL_ONE_ENTRY
 */
#define DL_UART_EXTEND_RX_FIFO_LEVEL_ONE_ENTRY  DL_UART_RX_FIFO_LEVEL_ONE_ENTRY

/*!
 * @brief Redirects to common @ref DL_UART_RX_FIFO_LEVEL_FULL
 */
#define DL_UART_EXTEND_RX_FIFO_LEVEL_FULL            DL_UART_RX_FIFO_LEVEL_FULL

/*!
 * @brief Redirects to common @ref DL_UART_RX_FIFO_LEVEL_3_4_FULL
 */
#define DL_UART_EXTEND_RX_FIFO_LEVEL_3_4_FULL    DL_UART_RX_FIFO_LEVEL_3_4_FULL

/*!
 * @brief Redirects to common @ref DL_UART_RX_FIFO_LEVEL_1_2_FULL
 */
#define DL_UART_EXTEND_RX_FIFO_LEVEL_1_2_FULL    DL_UART_RX_FIFO_LEVEL_1_2_FULL

/*!
 * @brief Redirects to common @ref DL_UART_RX_FIFO_LEVEL_1_4_FULL
 */
#define DL_UART_EXTEND_RX_FIFO_LEVEL_1_4_FULL    DL_UART_RX_FIFO_LEVEL_1_4_FULL

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_1
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_1        DL_UART_CLOCK_DIVIDE_RATIO_1

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_2
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_2        DL_UART_CLOCK_DIVIDE_RATIO_2

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_3
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_3        DL_UART_CLOCK_DIVIDE_RATIO_3

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_4
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_4        DL_UART_CLOCK_DIVIDE_RATIO_4

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_5
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_5        DL_UART_CLOCK_DIVIDE_RATIO_5

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_6
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_6        DL_UART_CLOCK_DIVIDE_RATIO_6

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_7
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_7        DL_UART_CLOCK_DIVIDE_RATIO_7

/*!
 * @brief Redirects to common @ref DL_UART_CLOCK_DIVIDE_RATIO_8
 */
#define DL_UART_EXTEND_CLOCK_DIVIDE_RATIO_8         DL_UART_CLOCK_DIVIDE_RATIO_8

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LIN_COUNTER_OVERFLOW
 */
#define DL_UART_EXTEND_INTERRUPT_LIN_COUNTER_OVERFLOW                         \
                                       (DL_UART_INTERRUPT_LIN_COUNTER_OVERFLOW)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LIN_RISING_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_LIN_RISING_EDGE                              \
                                            (DL_UART_INTERRUPT_LIN_RISING_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_INTERRUPT_LIN_FALLING_EDGE
 */
#define DL_UART_EXTEND_INTERRUPT_LIN_FALLING_EDGE                             \
                                           (DL_UART_INTERRUPT_LIN_FALLING_EDGE)

/*!
 * @brief Redirects to common @ref DL_UART_IRDA_CLOCK_BAUD_RATE
 */
#define DL_UART_EXTEND_IRDA_CLOCK_BAUD_RATE      (DL_UART_IRDA_CLOCK_BAUD_RATE)

/*!
 * @brief Redirects to common @ref DL_UART_IRDA_CLOCK_FUNCTIONAL
 */
#define DL_UART_EXTEND_IRDA_CLOCK_FUNCTIONAL    (DL_UART_IRDA_CLOCK_FUNCTIONAL)

/*!
 * @brief Redirects to common @ref DL_UART_IRDA_POLARITY_LOW
 */
#define DL_UART_EXTEND_IRDA_POLARITY_LOW            (DL_UART_IRDA_POLARITY_LOW)

/*!
 * @brief Redirects to common @ref DL_UART_IRDA_POLARITY_HIGH
 */
#define DL_UART_EXTEND_IRDA_POLARITY_HIGH          (DL_UART_IRDA_POLARITY_HIGH)

/*!
 * @brief Redirects to common @ref DL_UART_PULSE_WIDTH_3_16_BIT_PERIOD
 */
#define DL_UART_EXTEND_PULSE_WIDTH_3_16_BIT_PERIOD                            \
                                          (DL_UART_PULSE_WIDTH_3_16_BIT_PERIOD)

/*!
 * @brief Redirects to common @ref DL_UART_init
 */
#define DL_UART_Extend_init                                        DL_UART_init

/*!
 * @brief Redirects to common @ref DL_UART_enablePower
 */
#define DL_UART_Extend_enablePower                          DL_UART_enablePower

/*!
 * @brief Redirects to common @ref DL_UART_disablePower
 */
#define DL_UART_Extend_disablePower                        DL_UART_disablePower

/*!
 * @brief Redirects to common @ref DL_UART_isPowerEnabled
 */
#define DL_UART_Extend_isPowerEnabled                    DL_UART_isPowerEnabled

/*!
 * @brief Redirects to common @ref DL_UART_reset
 */
#define DL_UART_Extend_reset                                      DL_UART_reset

/*!
 * @brief Redirects to common @ref DL_UART_enable
 */
#define DL_UART_Extend_enable                                    DL_UART_enable

/*!
 * @brief Redirects to common @ref DL_UART_isEnabled
 */
#define DL_UART_Extend_isEnabled                              DL_UART_isEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disable
 */
#define DL_UART_Extend_disable                                  DL_UART_disable

/*!
 * @brief Redirects to common @ref DL_UART_setClockConfig
 */
#define DL_UART_Extend_setClockConfig                    DL_UART_setClockConfig

/*!
 * @brief Redirects to common @ref DL_UART_getClockConfig
 */
#define DL_UART_Extend_getClockConfig                    DL_UART_getClockConfig

/*!
 * @brief Redirects to common @ref DL_UART_configBaudRate
 */
#define DL_UART_Extend_configBaudRate                    DL_UART_configBaudRate

/*!
 * @brief Redirects to common @ref DL_UART_setOversampling
 */
#define DL_UART_Extend_setOversampling                  DL_UART_setOversampling

/*!
 * @brief Redirects to common @ref DL_UART_getOversampling
 */
#define DL_UART_Extend_getOversampling                  DL_UART_getOversampling

/*!
 * @brief Redirects to common @ref DL_UART_enableLoopbackMode
 */
#define DL_UART_Extend_enableLoopbackMode            DL_UART_enableLoopbackMode

/*!
 * @brief Redirects to common @ref DL_UART_isLoopbackModeEnabled
 */
#define DL_UART_Extend_isLoopbackModeEnabled      DL_UART_isLoopbackModeEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLoopbackMode
 */
#define DL_UART_Extend_disableLoopbackMode          DL_UART_disableLoopbackMode

/*!
 * @brief Redirects to common @ref DL_UART_setDirection
 */
#define DL_UART_Extend_setDirection                        DL_UART_setDirection

/*!
 * @brief Redirects to common @ref DL_UART_getDirection
 */
#define DL_UART_Extend_getDirection                        DL_UART_getDirection

/*!
 * @brief Redirects to common @ref DL_UART_enableMajorityVoting
 */
#define DL_UART_Extend_enableMajorityVoting        DL_UART_enableMajorityVoting

/*!
 * @brief Redirects to common @ref DL_UART_isMajorityVotingEnabled
 */
#define DL_UART_Extend_isMajorityVotingEnabled  DL_UART_isMajorityVotingEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableMajorityVoting
 */
#define DL_UART_Extend_disableMajorityVoting      DL_UART_disableMajorityVoting

/*!
 * @brief Redirects to common @ref DL_UART_enableMSBFirst
 */
#define DL_UART_Extend_enableMSBFirst                    DL_UART_enableMSBFirst

/*!
 * @brief Redirects to common @ref DL_UART_isMSBFirstEnabled
 */
#define DL_UART_Extend_isMSBFirstEnabled              DL_UART_isMSBFirstEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableMSBFirst
 */
#define DL_UART_Extend_disableMSBFirst                  DL_UART_disableMSBFirst

/*!
 * @brief Redirects to common @ref DL_UART_enableTransmitPinManualControl
 */
#define DL_UART_Extend_enableTransmitPinManualControl                         \
                                         DL_UART_enableTransmitPinManualControl

/*!
 * @brief Redirects to common @ref DL_UART_isTransmitPinManualControlEnabled
 */
#define DL_UART_Extend_isTransmitPinManualControlEnabled                      \
                                      DL_UART_isTransmitPinManualControlEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableTransmitPinManualControl
 */
#define DL_UART_Extend_disableTransmitPinManualControl                        \
                                        DL_UART_disableTransmitPinManualControl

/*!
 * @brief Redirects to common @ref DL_UART_setTransmitPinManualOutput
 */
#define DL_UART_Extend_setTransmitPinManualOutput                             \
                                             DL_UART_setTransmitPinManualOutput

/*!
 * @brief Redirects to common @ref DL_UART_getTransmitPinManualOutput
 */
#define DL_UART_Extend_getTransmitPinManualOutput                             \
                                             DL_UART_getTransmitPinManualOutput

/*!
 * @brief Redirects to common @ref DL_UART_setCommunicationMode
 */
#define DL_UART_Extend_setCommunicationMode        DL_UART_setCommunicationMode

/*!
 * @brief Redirects to common @ref DL_UART_getCommunicationMode
 */
#define DL_UART_Extend_getCommunicationMode        DL_UART_getCommunicationMode

/*!
 * @brief Redirects to common @ref DL_UART_setFlowControl
 */
#define DL_UART_Extend_setFlowControl                    DL_UART_setFlowControl

/*!
 * @brief Redirects to common @ref DL_UART_getFlowControl
 */
#define DL_UART_Extend_getFlowControl                    DL_UART_getFlowControl

/*!
 * @brief Redirects to common @ref DL_UART_setRTSOutput
 */
#define DL_UART_Extend_setRTSOutput                        DL_UART_setRTSOutput

/*!
 * @brief Redirects to common @ref DL_UART_enableFIFOs
 */
#define DL_UART_Extend_enableFIFOs                          DL_UART_enableFIFOs

/*!
 * @brief Redirects to common @ref DL_UART_disableFIFOs
 */
#define DL_UART_Extend_disableFIFOs                        DL_UART_disableFIFOs

/*!
 * @brief Redirects to common @ref DL_UART_isFIFOsEnabled
 */
#define DL_UART_Extend_isFIFOsEnabled                    DL_UART_isFIFOsEnabled

/*!
 * @brief Redirects to common @ref DL_UART_isParityEnabled
 */
#define DL_UART_Extend_isParityEnabled                  DL_UART_isParityEnabled

/*!
 * @brief Redirects to common @ref DL_UART_setParityMode
 */
#define DL_UART_Extend_setParityMode                      DL_UART_setParityMode

/*!
 * @brief Redirects to common @ref DL_UART_getParityMode
 */
#define DL_UART_Extend_getParityMode                      DL_UART_getParityMode

/*!
 * @brief Redirects to common @ref DL_UART_setStopBits
 */
#define DL_UART_Extend_setStopBits                          DL_UART_setStopBits

/*!
 * @brief Redirects to common @ref DL_UART_getStopBits
 */
#define DL_UART_Extend_getStopBits                          DL_UART_getStopBits

/*!
 * @brief Redirects to common @ref DL_UART_setWordLength
 */
#define DL_UART_Extend_setWordLength                      DL_UART_setWordLength

/*!
 * @brief Redirects to common @ref DL_UART_getWordLength
 */
#define DL_UART_Extend_getWordLength                      DL_UART_getWordLength

/*!
 * @brief Redirects to common @ref DL_UART_enableSendIdlePattern
 */
#define DL_UART_Extend_enableSendIdlePattern      DL_UART_enableSendIdlePattern

/*!
 * @brief Redirects to common @ref DL_UART_disableSendIdlePattern
 */
#define DL_UART_Extend_disableSendIdlePattern    DL_UART_disableSendIdlePattern

/*!
 * @brief Redirects to common @ref DL_UART_isSendIdlePatternEnabled
 */
#define DL_UART_Extend_isSendIdlePatternEnabled                               \
                                               DL_UART_isSendIdlePatternEnabled

/*!
 * @brief Redirects to common @ref DL_UART_setExternalDriverSetup
 */
#define DL_UART_Extend_setExternalDriverSetup    DL_UART_setExternalDriverSetup

/*!
 * @brief Redirects to common @ref DL_UART_getExternalDriverSetup
 */
#define DL_UART_Extend_getExternalDriverSetup    DL_UART_getExternalDriverSetup

/*!
 * @brief Redirects to common @ref DL_UART_setExternalDriverHold
 */
#define DL_UART_Extend_setExternalDriverHold      DL_UART_setExternalDriverHold

/*!
 * @brief Redirects to common @ref DL_UART_getExternalDriverHold
 */
#define DL_UART_Extend_getExternalDriverHold      DL_UART_getExternalDriverHold

/*!
 * @brief Redirects to common @ref DL_UART_isBusy
 */
#define DL_UART_Extend_isBusy                                    DL_UART_isBusy

/*!
 * @brief Redirects to common @ref DL_UART_isRXFIFOEmpty
 */
#define DL_UART_Extend_isRXFIFOEmpty                      DL_UART_isRXFIFOEmpty

/*!
 * @brief Redirects to common @ref DL_UART_isRXFIFOFull
 */
#define DL_UART_Extend_isRXFIFOFull                        DL_UART_isRXFIFOFull

/*!
 * @brief Redirects to common @ref DL_UART_isTXFIFOEmpty
 */
#define DL_UART_Extend_isTXFIFOEmpty                      DL_UART_isTXFIFOEmpty

/*!
 * @brief Redirects to common @ref DL_UART_isTXFIFOFull
 */
#define DL_UART_Extend_isTXFIFOFull                        DL_UART_isTXFIFOFull

/*!
 * @brief Redirects to common @ref DL_UART_isClearToSend
 */
#define DL_UART_Extend_isClearToSend                      DL_UART_isClearToSend

/*!
 * @brief Redirects to common @ref DL_UART_isIdleModeDetected
 */
#define DL_UART_Extend_isIdleModeDetected            DL_UART_isIdleModeDetected

/*!
 * @brief Redirects to common @ref DL_UART_setTXFIFOThreshold
 */
#define DL_UART_Extend_setTXFIFOThreshold            DL_UART_setTXFIFOThreshold

/*!
 * @brief Redirects to common @ref DL_UART_getTXFIFOThreshold
 */
#define DL_UART_Extend_getTXFIFOThreshold            DL_UART_getTXFIFOThreshold

/*!
 * @brief Redirects to common @ref DL_UART_setRXFIFOThreshold
 */
#define DL_UART_Extend_setRXFIFOThreshold            DL_UART_setRXFIFOThreshold

/*!
 * @brief Redirects to common @ref DL_UART_getRXFIFOThreshold
 */
#define DL_UART_Extend_getRXFIFOThreshold            DL_UART_getRXFIFOThreshold

/*!
 * @brief Redirects to common @ref DL_UART_setRXInterruptTimeout
 */
#define DL_UART_Extend_setRXInterruptTimeout      DL_UART_setRXInterruptTimeout

/*!
 * @brief Redirects to common @ref DL_UART_getRXInterruptTimeout
 */
#define DL_UART_Extend_getRXInterruptTimeout      DL_UART_getRXInterruptTimeout

/*!
 * @brief Redirects to common @ref DL_UART_getIntegerBaudRateDivisor
 */
#define DL_UART_Extend_getIntegerBaudRateDivisor                              \
                                              DL_UART_getIntegerBaudRateDivisor

/*!
 * @brief Redirects to common @ref DL_UART_getFractionalBaudRateDivisor
 */
#define DL_UART_Extend_getFractionalBaudRateDivisor                           \
                                           DL_UART_getFractionalBaudRateDivisor

/*!
 * @brief Redirects to common @ref DL_UART_setBaudRateDivisor
 */
#define DL_UART_Extend_setBaudRateDivisor            DL_UART_setBaudRateDivisor

/*!
 * @brief Redirects to common @ref DL_UART_transmitData
 */
#define DL_UART_Extend_transmitData                        DL_UART_transmitData

/*!
 * @brief Redirects to common @ref DL_UART_receiveData
 */
#define DL_UART_Extend_receiveData                          DL_UART_receiveData

/*!
 * @brief Redirects to common @ref DL_UART_getErrorStatus
 */
#define DL_UART_Extend_getErrorStatus                    DL_UART_getErrorStatus

/*!
 * @brief Redirects to common @ref DL_UART_enableInterrupt
 */
#define DL_UART_Extend_enableInterrupt                  DL_UART_enableInterrupt

/*!
 * @brief Redirects to common @ref DL_UART_disableInterrupt
 */
#define DL_UART_Extend_disableInterrupt                DL_UART_disableInterrupt

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledInterrupts
 */
#define DL_UART_Extend_getEnabledInterrupts        DL_UART_getEnabledInterrupts

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledInterruptStatus
 */
#define DL_UART_Extend_getEnabledInterruptStatus                              \
                                              DL_UART_getEnabledInterruptStatus

/*!
 * @brief Redirects to common @ref DL_UART_getRawInterruptStatus
 */
#define DL_UART_Extend_getRawInterruptStatus      DL_UART_getRawInterruptStatus

/*!
 * @brief Redirects to common @ref DL_UART_getPendingInterrupt
 */
#define DL_UART_Extend_getPendingInterrupt          DL_UART_getPendingInterrupt

/*!
 * @brief Redirects to common @ref DL_UART_clearInterruptStatus
 */
#define DL_UART_Extend_clearInterruptStatus        DL_UART_clearInterruptStatus

/*!
 * @brief Redirects to common @ref DL_UART_changeConfig
 */
#define DL_UART_Extend_changeConfig                        DL_UART_changeConfig

/*!
 * @brief Redirects to common @ref DL_UART_enableAnalogGlitchFilter
 */
#define DL_UART_Extend_enableAnalogGlitchFilter                               \
                                               DL_UART_enableAnalogGlitchFilter

/*!
 * @brief Redirects to common @ref DL_UART_disableAnalogGlitchFilter
 */
#define DL_UART_Extend_disableAnalogGlitchFilter                              \
                                              DL_UART_disableAnalogGlitchFilter

/*!
 * @brief Redirects to common @ref DL_UART_isAnalogGlitchFilterEnabled
 */
#define DL_UART_Extend_isAnalogGlitchFilterEnabled                            \
                                            DL_UART_isAnalogGlitchFilterEnabled

/*!
 * @brief Redirects to common @ref DL_UART_enableGlitchFilterChaining
 */
#define DL_UART_Extend_enableGlitchFilterChaining                             \
                                            DL_UART_enableGlitchFilterChaining

/*!
 * @brief Redirects to common @ref DL_UART_disableGlitchFilterChaining
 */
#define DL_UART_Extend_disableGlitchFilterChaining                            \
                                            DL_UART_disableGlitchFilterChaining

/*!
 * @brief Redirects to common @ref DL_UART_isGlitchFilterChainingEnabled
 */
#define DL_UART_Extend_isGlitchFilterChainingEnabled                          \
                                          DL_UART_isGlitchFilterChainingEnabled

/*!
 * @brief Redirects to common @ref DL_UART_setAnalogPulseWidth
 */
#define DL_UART_Extend_setAnalogPulseWidth          DL_UART_setAnalogPulseWidth

/*!
 * @brief Redirects to common @ref DL_UART_getAnalogPulseWidth
 */
#define DL_UART_Extend_getAnalogPulseWidth          DL_UART_getAnalogPulseWidth

/*!
 * @brief Redirects to common @ref DL_UART_transmitDataBlocking
 */
#define DL_UART_Extend_transmitDataBlocking        DL_UART_transmitDataBlocking

/*!
 * @brief Redirects to common @ref DL_UART_receiveDataBlocking
 */
#define DL_UART_Extend_receiveDataBlocking          DL_UART_receiveDataBlocking

/*!
 * @brief Redirects to common @ref DL_UART_transmitDataCheck
 */
#define DL_UART_Extend_transmitDataCheck              DL_UART_transmitDataCheck

/*!
 * @brief Redirects to common @ref DL_UART_receiveDataCheck
 */
#define DL_UART_Extend_receiveDataCheck                DL_UART_receiveDataCheck

/*!
 * @brief Redirects to common @ref DL_UART_drainRXFIFO
 */
#define DL_UART_Extend_drainRXFIFO                          DL_UART_drainRXFIFO

/*!
 * @brief Redirects to common @ref DL_UART_fillTXFIFO
 */
#define DL_UART_Extend_fillTXFIFO                            DL_UART_fillTXFIFO

/*!
 * @brief Redirects to common @ref DL_UART_enableDMAReceiveEvent
 */
#define DL_UART_Extend_enableDMAReceiveEvent      DL_UART_enableDMAReceiveEvent

/*!
 * @brief Redirects to common @ref DL_UART_enableDMATransmitEvent
 */
#define DL_UART_Extend_enableDMATransmitEvent    DL_UART_enableDMATransmitEvent

/*!
 * @brief Redirects to common @ref DL_UART_disableDMAReceiveEvent
 */
#define DL_UART_Extend_disableDMAReceiveEvent    DL_UART_disableDMAReceiveEvent

/*!
 * @brief Redirects to common @ref DL_UART_disableDMATransmitEvent
 */
#define DL_UART_Extend_disableDMATransmitEvent  DL_UART_disableDMATransmitEvent

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledDMAReceiveEvent
 */
#define DL_UART_Extend_getEnabledDMAReceiveEvent                              \
                                              DL_UART_getEnabledDMAReceiveEvent

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledDMATransmitEvent
 */
#define DL_UART_Extend_getEnabledDMATransmitEvent                             \
                                             DL_UART_getEnabledDMATransmitEvent

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledDMAReceiveEventStatus
 */
#define DL_UART_Extend_getEnabledDMAReceiveEventStatus                        \
                                        DL_UART_getEnabledDMAReceiveEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_getEnabledDMATransmitEventStatus
 */
#define DL_UART_Extend_getEnabledDMATransmitEventStatus                       \
                                       DL_UART_getEnabledDMATransmitEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_getRawDMAReceiveEventStatus
 */
#define DL_UART_Extend_getRawDMAReceiveEventStatus                            \
                                            DL_UART_getRawDMAReceiveEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_getRawDMATransmitEventStatus
 */
#define DL_UART_Extend_getRawDMATransmitEventStatus                           \
                                           DL_UART_getRawDMATransmitEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_getPendingDMAReceiveEvent
 */
#define DL_UART_Extend_getPendingDMAReceiveEvent                              \
                                              DL_UART_getPendingDMAReceiveEvent

/*!
 * @brief Redirects to common @ref DL_UART_getPendingDMATransmitEvent
 */
#define DL_UART_Extend_getPendingDMATransmitEvent                             \
                                             DL_UART_getPendingDMATransmitEvent

/*!
 * @brief Redirects to common @ref DL_UART_clearDMAReceiveEventStatus
 */
#define DL_UART_Extend_clearDMAReceiveEventStatus                             \
                                             DL_UART_clearDMAReceiveEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_clearDMATransmitEventStatus
 */
#define DL_UART_Extend_clearDMATransmitEventStatus                            \
                                            DL_UART_clearDMATransmitEventStatus

/*!
 * @brief Redirects to common @ref DL_UART_setLINCounterValue
 */
#define DL_UART_Extend_setLINCounterValue            DL_UART_setLINCounterValue

/*!
 * @brief Redirects to common @ref DL_UART_getLINCounterValue
 */
#define DL_UART_Extend_getLINCounterValue            DL_UART_getLINCounterValue

/*!
 * @brief Redirects to common @ref DL_UART_enableLINCounter
 */
#define DL_UART_Extend_enableLINCounter                DL_UART_enableLINCounter

/*!
 * @brief Redirects to common @ref DL_UART_isLINCounterEnabled
 */
#define DL_UART_Extend_isLINCounterEnabled          DL_UART_isLINCounterEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLINCounter
 */
#define DL_UART_Extend_disableLINCounter              DL_UART_disableLINCounter

/*!
 * @brief Redirects to common @ref DL_UART_enableLINCounterClearOnFallingEdge
 */
#define DL_UART_Extend_enableLINCounterClearOnFallingEdge                     \
                                     DL_UART_enableLINCounterClearOnFallingEdge

/*!
 * @brief Redirects to common @ref DL_UART_isLINCounterClearOnFallingEdge
 */
#define DL_UART_Extend_isLINCounterClearOnFallingEdge                         \
                                         DL_UART_isLINCounterClearOnFallingEdge

/*!
 * @brief Redirects to common @ref DL_UART_disableLINCounterClearOnFallingEdge
 */
#define DL_UART_Extend_disableLINCounterClearOnFallingEdge                    \
                                    DL_UART_disableLINCounterClearOnFallingEdge

/*!
 * @brief Redirects to common @ref DL_UART_enableLINCountWhileLow
 */
#define DL_UART_Extend_enableLINCountWhileLow    DL_UART_enableLINCountWhileLow

/*!
 * @brief Redirects to common @ref DL_UART_isLINCountWhileLowEnabled
 */
#define DL_UART_Extend_isLINCountWhileLowEnabled                              \
                                              DL_UART_isLINCountWhileLowEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLINCountWhileLow
 */
#define DL_UART_Extend_disableLINCountWhileLow  DL_UART_disableLINCountWhileLow

/*!
 * @brief Redirects to common @ref DL_UART_enableLINFallingEdgeCapture
 */
#define DL_UART_Extend_enableLINFallingEdgeCapture                            \
                                            DL_UART_enableLINFallingEdgeCapture

/*!
 * @brief Redirects to common @ref DL_UART_isLINFallingEdgeCaptureEnabled
 */
#define DL_UART_Extend_isLINFallingEdgeCaptureEnabled                         \
                                         DL_UART_isLINFallingEdgeCaptureEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLINFallingEdgeCapture
 */
#define DL_UART_Extend_disableLINFallingEdgeCapture                           \
                                           DL_UART_disableLINFallingEdgeCapture

/*!
 * @brief Redirects to common @ref DL_UART_enableLINRisingEdgeCapture
 */
#define DL_UART_Extend_enableLINRisingEdgeCapture                             \
                                             DL_UART_enableLINRisingEdgeCapture

/*!
 * @brief Redirects to common @ref DL_UART_isLINRisingEdgeCaptureEnabled
 */
#define DL_UART_Extend_isLINRisingEdgeCaptureEnabled                          \
                                          DL_UART_isLINRisingEdgeCaptureEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLINRisingEdgeCapture
 */
#define DL_UART_Extend_disableLINRisingEdgeCapture                            \
                                            DL_UART_disableLINRisingEdgeCapture

/*!
 * @brief Redirects to common @ref DL_UART_enableLINCounterCompareMatch
 */
#define DL_UART_Extend_enableLINCounterCompareMatch                           \
                                           DL_UART_enableLINCounterCompareMatch

/*!
 * @brief Redirects to common
 * @ref DL_UART_enableLINSyncFieldValidationCounterControl
 */
#define DL_UART_Extend_enableLINSyncFieldValidationCounterControl             \
                             DL_UART_enableLINSyncFieldValidationCounterControl

/*!
 * @brief Redirects to common @ref DL_UART_Extend_enableLINReceptionCountControl
 */
#define DL_UART_Extend_enableLINReceptionCountControl                         \
                                         DL_UART_enableLINReceptionCountControl

/*!
 * @brief Redirects to common @ref DL_UART_isLINCounterCompareMatchEnabled
 */
#define DL_UART_Extend_isLINCounterCompareMatchEnabled                        \
                                        DL_UART_isLINCounterCompareMatchEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableLINCounterCompareMatch
 */
#define DL_UART_Extend_disableLINCounterCompareMatch                          \
                                          DL_UART_disableLINCounterCompareMatch

/*!
 * @brief Redirects to common @ref DL_UART_setLINCounterCompareValue
 */
#define DL_UART_Extend_setLINCounterCompareValue                              \
                                              DL_UART_setLINCounterCompareValue

/*!
 * @brief Redirects to common @ref DL_UART_getLINFallingEdgeCaptureValue
 */
#define DL_UART_Extend_getLINFallingEdgeCaptureValue                          \
                                          DL_UART_getLINFallingEdgeCaptureValue

/*!
 * @brief Redirects to common @ref DL_UART_getLINRisingEdgeCaptureValue
 */
#define DL_UART_Extend_getLINRisingEdgeCaptureValue                           \
                                           DL_UART_getLINRisingEdgeCaptureValue

/*!
 * @brief Redirects to common @ref DL_UART_enableLINSendBreak
 */
#define DL_UART_Extend_enableLINSendBreak            DL_UART_enableLINSendBreak

/*!
 * @brief Redirects to common @ref DL_UART_disableLINSendBreak
 */
#define DL_UART_Extend_disableLINSendBreak          DL_UART_disableLINSendBreak

/*!
 * @brief Redirects to common @ref DL_UART_isLINSendBreakEnabled
 */
#define DL_UART_Extend_isLINSendBreakEnabled      DL_UART_isLINSendBreakEnabled

/*!
 * @brief Redirects to common @ref DL_UART_enableIrDAMode
 */
#define DL_UART_Extend_enableIrDAMode                    DL_UART_enableIrDAMode

/*!
 * @brief Redirects to common @ref DL_UART_isIrDAModeEnabled
 */
#define DL_UART_Extend_isIrDAModeEnabled              DL_UART_isIrDAModeEnabled

/*!
 * @brief Redirects to common @ref DL_UART_disableIrDAMode
 */
#define DL_UART_Extend_disableIrDAMode                  DL_UART_disableIrDAMode

/*!
 * @brief Redirects to common @ref DL_UART_setIrDATXPulseClockSelect
 */
#define DL_UART_Extend_setIrDATXPulseClockSelect                              \
                                              DL_UART_setIrDATXPulseClockSelect

/*!
 * @brief Redirects to common @ref DL_UART_getIrDATXPulseClockSelect
 */
#define DL_UART_Extend_getIrDATXPulseClockSelect                              \
                                              DL_UART_getIrDATXPulseClockSelect

/*!
 * @brief Redirects to common @ref DL_UART_configIrDAMode
 */
#define DL_UART_Extend_configIrDAMode                    DL_UART_configIrDAMode

/*!
 * @brief Redirects to common @ref DL_UART_setIrDAPulseLength
 */
#define DL_UART_Extend_setIrDAPulseLength            DL_UART_setIrDAPulseLength

/*!
 * @brief Redirects to common @ref DL_UART_getIrDATXPulseLength
 */
#define DL_UART_Extend_getIrDATXPulseLength        DL_UART_getIrDATXPulseLength

/*!
 * @brief Redirects to common @ref DL_UART_setIrDARXPulsePolarity
 */
#define DL_UART_Extend_setIrDARXPulsePolarity    DL_UART_setIrDARXPulsePolarity

/*!
 * @brief Redirects to common @ref DL_UART_getIrDARXPulsePolarity
 */
#define DL_UART_Extend_getIrDARXPulsePolarity    DL_UART_getIrDARXPulsePolarity

/*!
 * @brief Redirects to common @ref DL_UART_setDigitalPulseWidth
 */
#define DL_UART_Extend_setDigitalPulseWidth        DL_UART_setDigitalPulseWidth

/*!
 * @brief Redirects to common @ref DL_UART_getDigitalPulseWidth
 */
#define DL_UART_Extend_getDigitalPulseWidth        DL_UART_getDigitalPulseWidth

/*!
 * @brief Redirects to common @ref DL_UART_setAddressMask
 */
#define DL_UART_Extend_setAddressMask                    DL_UART_setAddressMask

/*!
 * @brief Redirects to common @ref DL_UART_getAddressMask
 */
#define DL_UART_Extend_getAddressMask                    DL_UART_getAddressMask

/*!
 * @brief Redirects to common @ref DL_UART_setAddress
 */
#define DL_UART_Extend_setAddress                            DL_UART_setAddress

/*!
 * @brief Redirects to common @ref DL_UART_getAddress
 */
#define DL_UART_Extend_getAddress                            DL_UART_getAddress

/*!
 * @brief Redirects to common @ref DL_UART_enableManchesterEncoding
 */
#define DL_UART_Extend_enableManchesterEncoding                               \
                                               DL_UART_enableManchesterEncoding

/*!
 * @brief Redirects to common @ref DL_UART_disableManchesterEncoding
 */
#define DL_UART_Extend_disableManchesterEncoding                              \
                                              DL_UART_disableManchesterEncoding

/*!
 * @brief Redirects to common @ref DL_UART_isManchesterEncodingEnabled
 */
#define DL_UART_Extend_isManchesterEncodingEnabled                            \
                                            DL_UART_isManchesterEncodingEnabled

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_UART_EXTD__ */

#endif /* ti_dl_dl_uart_extend__include */
/** @}*/
