################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/GPIO_Driver.c 

OBJS += \
./GPIO/GPIO_Driver.o 

C_DEPS += \
./GPIO/GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/GPIO_Driver.o: ../GPIO/GPIO_Driver.c
	arm-none-eabi-gcc -dwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/STM32F103C6_Drivers/GPIO/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO/GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

