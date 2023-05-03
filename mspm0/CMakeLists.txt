zephyr_include_directories(
    source
)

zephyr_library_sources(
    source/ti/driverlib/dl_uart.c
    source/ti/driverlib/dl_common.c

    source/ti/drivers/UART.c
    source/ti/drivers/uart/UARTMSP.c

    source/ti/drivers/utils/RingBuf.c

    kernel/zephyr/dpl/HwiP_zephyr.c
    kernel/zephyr/dpl/ClockP_zephyr.c
    kernel/zephyr/dpl/SemaphoreBinaryP_zephyr.c
)

