# Standard things
sp              := $(sp).x
dirstack_$(sp)  := $(d)
d               := $(dir)
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/libmaple
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/libmaple/stm32f1
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/libmaple/usb
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/libmaple/usb/usb_lib
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/stm32utils
BUILDDIRS       += $(BUILD_PATH)/$(d)/stm32/port

LIBMAPLE_INCLUDES := \
	-I$(PLATFORM_PATH)/stm32/libmaple \
	-I$(PLATFORM_PATH)/stm32/libmaple/usb \
	-I$(PLATFORM_PATH)/stm32/libmaple/usb/usb_lib

# Local flags
CFLAGS_$(d) = -I$(d) -I$(d)/$(TARGET_PLATFORM) -I$(INCLUDE_PATH) $(LIBMAPLE_INCLUDES) -Wall -Werror

# Local rules and targets
# porting
cSRCS_$(d) := \
	stm32/port/ousia_port.c
# libmaple
cSRCS_$(d) += \
	stm32/libmaple/adc.c \
	stm32/libmaple/bkp.c \
	stm32/libmaple/dac.c \
	stm32/libmaple/dma.c \
	stm32/libmaple/exti.c \
	stm32/libmaple/flash.c \
	stm32/libmaple/fsmc.c \
	stm32/libmaple/gpio.c \
	stm32/libmaple/iwdg.c \
	stm32/libmaple/nvic.c \
	stm32/libmaple/pwr.c \
	stm32/libmaple/i2c.c \
	stm32/libmaple/rcc.c \
	stm32/libmaple/spi.c \
	stm32/libmaple/start_c.c \
	stm32/libmaple/syscalls.c \
	stm32/libmaple/systick.c \
	stm32/libmaple/timer.c \
	stm32/libmaple/usart.c \
	stm32/libmaple/util.c \
	stm32/libmaple/usb/usb.c \
	stm32/libmaple/usb/usb_reg_map.c \
	stm32/libmaple/usb/usb_cdcacm.c \
	stm32/libmaple/usb/usb_lib/usb_core.c \
	stm32/libmaple/usb/usb_lib/usb_init.c \
	stm32/libmaple/usb/usb_lib/usb_mem.c \
	stm32/libmaple/usb/usb_lib/usb_regs.c
sSRCS_$(d) := stm32/libmaple/exc.S
sSRCS_$(d) += \
	stm32/libmaple/start.S \
	stm32/libmaple/stm32f1/isrs_performance.S \
	stm32/libmaple/stm32f1/vector_table_performance.S

# stm32utils
cSRCS_$(d) += stm32/stm32utils/stm32utils.c

cFILES_$(d) := $(cSRCS_$(d):%=$(d)/%)
sFILES_$(d) := $(sSRCS_$(d):%=$(d)/%)

OBJS_$(d) := $(sFILES_$(d):%.S=$(BUILD_PATH)/%.o) $(cFILES_$(d):%.c=$(BUILD_PATH)/%.o)
DEPS_$(d) := $(OBJS_$(d):%.o=%.d)

$(OBJS_$(d)): TGT_CFLAGS := $(CFLAGS_$(d))
$(OBJS_$(d)): TGT_ASFLAGS :=

TGT_BIN += $(OBJS_$(d))

# Standard things
-include $(DEPS_$(d))
d := $(dirstack_$(sp))
sp := $(basename $(sp))
