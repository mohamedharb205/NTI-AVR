################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SSD_driver/DIO_program.c \
../SSD_driver/SEVEN_SEGMENT_program.c 

OBJS += \
./SSD_driver/DIO_program.o \
./SSD_driver/SEVEN_SEGMENT_program.o 

C_DEPS += \
./SSD_driver/DIO_program.d \
./SSD_driver/SEVEN_SEGMENT_program.d 


# Each subdirectory must supply rules for building sources it contributes
SSD_driver/%.o: ../SSD_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


