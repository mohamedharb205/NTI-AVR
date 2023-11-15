################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SSD_apps/00-main.c \
../SSD_apps/01-Four_BCD_Seven_Segment.c 

OBJS += \
./SSD_apps/00-main.o \
./SSD_apps/01-Four_BCD_Seven_Segment.o 

C_DEPS += \
./SSD_apps/00-main.d \
./SSD_apps/01-Four_BCD_Seven_Segment.d 


# Each subdirectory must supply rules for building sources it contributes
SSD_apps/%.o: ../SSD_apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


