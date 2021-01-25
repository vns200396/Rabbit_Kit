################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include hardware/src/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/Legacy/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Rabbit_Kit.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Rabbit_Kit.list \

OBJCOPY_BIN += \
Rabbit_Kit.bin \


# All Target
all: Rabbit_Kit.elf secondary-outputs

# Tool invocations
Rabbit_Kit.elf: $(OBJS) $(USER_OBJS) E:\Study\Hoc_STM\STM32_Course\stm32_advance_online1\Rabbit_Kit\STM32F103RETX_FLASH.ld
	arm-none-eabi-gcc -o "Rabbit_Kit.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Study\Hoc_STM\STM32_Course\stm32_advance_online1\Rabbit_Kit\STM32F103RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Rabbit_Kit.map" -Wl,--gc-sections -static -specs=nano.specs -u _printf_float  -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Rabbit_Kit.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Rabbit_Kit.list"
	@echo 'Finished building: $@'
	@echo ' '

Rabbit_Kit.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Rabbit_Kit.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
