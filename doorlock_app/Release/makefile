################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
doorlock_app.lss \

FLASH_IMAGE += \
doorlock_app.hex \

EEPROM_IMAGE += \
doorlock_app.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: doorlock_app.elf secondary-outputs

# Tool invocations
doorlock_app.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,doorlock_app.map -mmcu=atmega16 -o "doorlock_app.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

doorlock_app.lss: doorlock_app.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S doorlock_app.elf  >"doorlock_app.lss"
	@echo 'Finished building: $@'
	@echo ' '

doorlock_app.hex: doorlock_app.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex doorlock_app.elf  "doorlock_app.hex"
	@echo 'Finished building: $@'
	@echo ' '

doorlock_app.eep: doorlock_app.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex doorlock_app.elf  "doorlock_app.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: doorlock_app.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 doorlock_app.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) doorlock_app.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
