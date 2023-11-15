################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SSD/00-main.c \
../SSD/01-Four_BCD_Seven_Segment.c \
../SSD/DIO_program.c \
../SSD/SEVEN_SEGMENT_program.c 

OBJS += \
./SSD/00-main.o \
./SSD/01-Four_BCD_Seven_Segment.o \
./SSD/DIO_program.o \
./SSD/SEVEN_SEGMENT_program.o 

C_DEPS += \
./SSD/00-main.d \
./SSD/01-Four_BCD_Seven_Segment.d \
./SSD/DIO_program.d \
./SSD/SEVEN_SEGMENT_program.d 


# Each subdirectory must supply rules for building sources it contributes
SSD/%.o: ../SSD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


