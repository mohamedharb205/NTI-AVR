################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KPD_apps/00-main.c \
../KPD_apps/01-KEYPAD_test.c 

OBJS += \
./KPD_apps/00-main.o \
./KPD_apps/01-KEYPAD_test.o 

C_DEPS += \
./KPD_apps/00-main.d \
./KPD_apps/01-KEYPAD_test.d 


# Each subdirectory must supply rules for building sources it contributes
KPD_apps/%.o: ../KPD_apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


