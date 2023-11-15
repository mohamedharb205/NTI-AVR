################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TIMER0_driver/DIO_program.c \
../TIMER0_driver/TIMER0_program.c 

OBJS += \
./TIMER0_driver/DIO_program.o \
./TIMER0_driver/TIMER0_program.o 

C_DEPS += \
./TIMER0_driver/DIO_program.d \
./TIMER0_driver/TIMER0_program.d 


# Each subdirectory must supply rules for building sources it contributes
TIMER0_driver/%.o: ../TIMER0_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


