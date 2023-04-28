SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC  = "$(IAR_ARMCOMPILER)/bin/iccarm"
ASM = "$(IAR_ARMCOMPILER)/bin/iasmarm"
AR  = "$(IAR_ARMCOMPILER)/bin/iarchive"

NAME = drivers_mspm0l110x_l130x_nortos

OBJ_DIR = ../../../obj/iar/m0p/drivers_mspm0l110x_l130x_nortos
SRC_DIR = ../../..

CFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" --cpu Cortex-M0+ -DDeviceFamily_MSPM0L110X_L130X -DDRIVERS_NORTOS -D__MSPM0G3507__ --aeabi --guard_calls --endian=little --thumb --silent -e --use_unix_directory_separators --diag_suppress=Pa050,Go005 -Ohs --debug
AFLAGS = 
ASMFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" 

OBJECTS = $(OBJ_DIR)/List.o $(OBJ_DIR)/RingBuf.o $(OBJ_DIR)/StructRingBuf.o $(OBJ_DIR)/ClockPSysTick_nortos.o $(OBJ_DIR)/DebugP_nortos.o $(OBJ_DIR)/HwiPMSPM0_nortos.o $(OBJ_DIR)/MutexP_nortos.o $(OBJ_DIR)/SemaphoreBinaryP_nortos.o $(OBJ_DIR)/SemaphoreP_nortos.o $(OBJ_DIR)/SystemP_nortos.o $(OBJ_DIR)/UART.o $(OBJ_DIR)/UARTMSP.o $(OBJ_DIR)/WatchdogMSP.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/List.o: $(SRC_DIR)/utils/List.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/RingBuf.o: $(SRC_DIR)/utils/RingBuf.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/StructRingBuf.o: $(SRC_DIR)/utils/StructRingBuf.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/ClockPSysTick_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/ClockPSysTick_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/DebugP_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/DebugP_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/HwiPMSPM0_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/HwiPMSPM0_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/MutexP_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/MutexP_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/SemaphoreBinaryP_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/SemaphoreBinaryP_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/SemaphoreP_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/SemaphoreP_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/SystemP_nortos.o: $(SRC_DIR)/../../../kernel/nortos/dpl/SystemP_nortos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/UART.o: $(SRC_DIR)/UART.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/UARTMSP.o: $(SRC_DIR)/uart/UARTMSP.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/WatchdogMSP.o: $(SRC_DIR)/watchdog/WatchdogMSP.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
