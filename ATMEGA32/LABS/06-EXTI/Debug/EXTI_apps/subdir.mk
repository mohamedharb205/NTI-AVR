################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI_apps/00-main.c \
../EXTI_apps/01-EXTI_test.c \
../EXTI_apps/02-EXTI_nesting.c 

OBJS += \
./EXTI_apps/00-main.o \
./EXTI_apps/01-EXTI_test.o \
./EXTI_apps/02-EXTI_nesting.o 

C_DEPS += \
./EXTI_apps/00-main.d \
./EXTI_apps/01-EXTI_test.d \
./EXTI_apps/02-EXTI_nesting.d 


# Each subdirectory must supply rules for building sources it contributes
EXTI_apps/%.o: ../EXTI_apps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


