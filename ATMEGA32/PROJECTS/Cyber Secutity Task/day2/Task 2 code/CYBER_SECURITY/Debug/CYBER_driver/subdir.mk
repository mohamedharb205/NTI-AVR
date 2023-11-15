################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CYBER_driver/DIO_program.c \
../CYBER_driver/LCD_program.c \
../CYBER_driver/TIMER0_program.c \
../CYBER_driver/USART_program.c 

OBJS += \
./CYBER_driver/DIO_program.o \
./CYBER_driver/LCD_program.o \
./CYBER_driver/TIMER0_program.o \
./CYBER_driver/USART_program.o 

C_DEPS += \
./CYBER_driver/DIO_program.d \
./CYBER_driver/LCD_program.d \
./CYBER_driver/TIMER0_program.d \
./CYBER_driver/USART_program.d 


# Each subdirectory must supply rules for building sources it contributes
CYBER_driver/%.o: ../CYBER_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


