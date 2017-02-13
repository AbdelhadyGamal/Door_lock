################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External_EEPROM.c \
../Keypad.c \
../appl_services_states.c \
../i2c.c \
../lcd.c \
../main.c \
../uart.c 

OBJS += \
./External_EEPROM.o \
./Keypad.o \
./appl_services_states.o \
./i2c.o \
./lcd.o \
./main.o \
./uart.o 

C_DEPS += \
./External_EEPROM.d \
./Keypad.d \
./appl_services_states.d \
./i2c.d \
./lcd.d \
./main.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


