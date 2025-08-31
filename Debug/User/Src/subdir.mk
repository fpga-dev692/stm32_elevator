################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/button.c \
../User/Src/delay.c \
../User/Src/external_int.c \
../User/Src/fnd.c \
../User/Src/led.c \
../User/Src/stepper.c \
../User/Src/uart.c 

OBJS += \
./User/Src/button.o \
./User/Src/delay.o \
./User/Src/external_int.o \
./User/Src/fnd.o \
./User/Src/led.o \
./User/Src/stepper.o \
./User/Src/uart.o 

C_DEPS += \
./User/Src/button.d \
./User/Src/delay.d \
./User/Src/external_int.d \
./User/Src/fnd.d \
./User/Src/led.d \
./User/Src/stepper.d \
./User/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/STM32CubeIDE/workspace_1.16.0/Elevator 5.3/User" -I"D:/Projects/STM32CubeIDE/workspace_1.16.0/Elevator 5.3/User/Inc" -I"D:/Projects/STM32CubeIDE/workspace_1.16.0/Elevator 5.3/User/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/button.cyclo ./User/Src/button.d ./User/Src/button.o ./User/Src/button.su ./User/Src/delay.cyclo ./User/Src/delay.d ./User/Src/delay.o ./User/Src/delay.su ./User/Src/external_int.cyclo ./User/Src/external_int.d ./User/Src/external_int.o ./User/Src/external_int.su ./User/Src/fnd.cyclo ./User/Src/fnd.d ./User/Src/fnd.o ./User/Src/fnd.su ./User/Src/led.cyclo ./User/Src/led.d ./User/Src/led.o ./User/Src/led.su ./User/Src/stepper.cyclo ./User/Src/stepper.d ./User/Src/stepper.o ./User/Src/stepper.su ./User/Src/uart.cyclo ./User/Src/uart.d ./User/Src/uart.o ./User/Src/uart.su

.PHONY: clean-User-2f-Src

