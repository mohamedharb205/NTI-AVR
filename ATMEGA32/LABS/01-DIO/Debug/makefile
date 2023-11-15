################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include DIO_driver/subdir.mk
-include DIO_apps/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
01-DIO.lss \

FLASH_IMAGE += \
01-DIO.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 01-DIO.elf secondary-outputs

# Tool invocations
01-DIO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,01-DIO.map -mmcu=atmega32 -o "01-DIO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

01-DIO.lss: 01-DIO.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 01-DIO.elf  >"01-DIO.lss"
	@echo 'Finished building: $@'
	@echo ' '

01-DIO.hex: 01-DIO.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 01-DIO.elf  "01-DIO.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 01-DIO.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 01-DIO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 01-DIO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
