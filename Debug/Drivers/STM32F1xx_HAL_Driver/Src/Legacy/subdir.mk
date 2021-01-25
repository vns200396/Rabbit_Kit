################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.c 

OBJS += \
./Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.o 

C_DEPS += \
./Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.o: ../Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

