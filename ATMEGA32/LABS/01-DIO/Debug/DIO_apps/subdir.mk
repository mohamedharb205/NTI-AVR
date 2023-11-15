################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_apps/00-main.c \
../DIO_apps/01-LED_BLINKING.c \
../DIO_apps/02-TOGGLE_LEDS.c \
../DIO_apps/03-PUSH_BUTTON.c 

OBJS += \
./DIO_apps/00-main.o \
./DIO_apps/01-LED_BLINKING.o \
./DIO_apps/02-TOGGLE_LEDS.o \
./DIO_apps/03-PUSH_BUTTON.o 

C_DEPS += \
./DIO_apps/00-main.d \
./DIO_apps/01-LED_BLINKING.d \
./DIO_apps/02-TOGGLE_LEDS.d \
./DIO_apps/03-PUSH_BUTTON.d 


# Each subdirectory must supply rules for building sources it contributes
DIO_apps/%.o: ../DIO_apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


