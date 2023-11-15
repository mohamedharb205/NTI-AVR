################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USART_driver/DIO_program.c \
../USART_driver/LCD_program.c \
../USART_driver/USART_program.c 

OBJS += \
./USART_driver/DIO_program.o \
./USART_driver/LCD_program.o \
./USART_driver/USART_program.o 

C_DEPS += \
./USART_driver/DIO_program.d \
./USART_driver/LCD_program.d \
./USART_driver/USART_program.d 


# Each subdirectory must supply rules for building sources it contributes
USART_driver/%.o: ../USART_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


