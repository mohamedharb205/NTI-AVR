################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_driver/DIO_program.c \
../LCD_driver/LCD_program.c 

OBJS += \
./LCD_driver/DIO_program.o \
./LCD_driver/LCD_program.o 

C_DEPS += \
./LCD_driver/DIO_program.d \
./LCD_driver/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_driver/%.o: ../LCD_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


