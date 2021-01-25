################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/src/adc_light.c \
../hardware/src/bsp_debug_usart.c \
../hardware/src/buzzer.c \
../hardware/src/dht11.c \
../hardware/src/infrared.c \
../hardware/src/infrared_reflective.c \
../hardware/src/key.c \
../hardware/src/led.c \
../hardware/src/my9291_led_rbg.c \
../hardware/src/oled.c \
../hardware/src/relay.c \
../hardware/src/timer_base.c 

OBJS += \
./hardware/src/adc_light.o \
./hardware/src/bsp_debug_usart.o \
./hardware/src/buzzer.o \
./hardware/src/dht11.o \
./hardware/src/infrared.o \
./hardware/src/infrared_reflective.o \
./hardware/src/key.o \
./hardware/src/led.o \
./hardware/src/my9291_led_rbg.o \
./hardware/src/oled.o \
./hardware/src/relay.o \
./hardware/src/timer_base.o 

C_DEPS += \
./hardware/src/adc_light.d \
./hardware/src/bsp_debug_usart.d \
./hardware/src/buzzer.d \
./hardware/src/dht11.d \
./hardware/src/infrared.d \
./hardware/src/infrared_reflective.d \
./hardware/src/key.d \
./hardware/src/led.d \
./hardware/src/my9291_led_rbg.d \
./hardware/src/oled.d \
./hardware/src/relay.d \
./hardware/src/timer_base.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/src/adc_light.o: ../hardware/src/adc_light.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/adc_light.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/bsp_debug_usart.o: ../hardware/src/bsp_debug_usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/bsp_debug_usart.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/buzzer.o: ../hardware/src/buzzer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/buzzer.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/dht11.o: ../hardware/src/dht11.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/dht11.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/infrared.o: ../hardware/src/infrared.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/infrared.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/infrared_reflective.o: ../hardware/src/infrared_reflective.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/infrared_reflective.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/key.o: ../hardware/src/key.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/key.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/led.o: ../hardware/src/led.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/led.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/my9291_led_rbg.o: ../hardware/src/my9291_led_rbg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/my9291_led_rbg.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/oled.o: ../hardware/src/oled.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/oled.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/relay.o: ../hardware/src/relay.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/relay.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
hardware/src/timer_base.o: ../hardware/src/timer_base.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DDEBUG -DSTM32F103RETx -DSTM32F103xE -c -I../Inc -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/hardware/inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Inc" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/CMSIS/Include" -I"E:/Study/Hoc_STM/STM32_Course/stm32_advance_online1/Rabbit_Kit/Drivers/STM32F1xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hardware/src/timer_base.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

