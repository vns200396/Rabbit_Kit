################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/dwt_stm32_delay.c \
../Src/main.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system.c \
../Src/system_stm32f1xx.c 

OBJS += \
./Src/dwt_stm32_delay.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system.o \
./Src/system_stm32f1xx.o 

C_DEPS += \
./Src/dwt_stm32_delay.d \
./Src/main.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system.d \
./Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/dwt_stm32_delay.o: ../Src/dwt_stm32_delay.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/dwt_stm32_delay.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f1xx_hal_msp.o: ../Src/stm32f1xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f1xx_hal_msp.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f1xx_it.o: ../Src/stm32f1xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f1xx_it.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/system.o: ../Src/system.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
Src/system_stm32f1xx.o: ../Src/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system_stm32f1xx.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

