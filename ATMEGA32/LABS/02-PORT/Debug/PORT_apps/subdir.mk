################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PORT_apps/00-main.c \
../PORT_apps/01-LED_ON.c 

OBJS += \
./PORT_apps/00-main.o \
./PORT_apps/01-LED_ON.o 

C_DEPS += \
./PORT_apps/00-main.d \
./PORT_apps/01-LED_ON.d 


# Each subdirectory must supply rules for building sources it contributes
PORT_apps/%.o: ../PORT_apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


