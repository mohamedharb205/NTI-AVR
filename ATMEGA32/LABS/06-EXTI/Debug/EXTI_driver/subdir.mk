################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI_driver/DIO_program.c \
../EXTI_driver/EXTI_program.c \
../EXTI_driver/GIE_program.c 

OBJS += \
./EXTI_driver/DIO_program.o \
./EXTI_driver/EXTI_program.o \
./EXTI_driver/GIE_program.o 

C_DEPS += \
./EXTI_driver/DIO_program.d \
./EXTI_driver/EXTI_program.d \
./EXTI_driver/GIE_program.d 


# Each subdirectory must supply rules for building sources it contributes
EXTI_driver/%.o: ../EXTI_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


