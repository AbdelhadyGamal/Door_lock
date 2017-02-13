/*
 * main.c
 *
 *  Created on: Jan 28, 2017
 *      Author: Abdelhady
 *
 */

#include "uart.h"
#define M1_READY 0x10
#include "i2c.h"
#include "external_eeprom.h"
#include "app.h"

int main(void) {

	/**
	 * Initialization
	 */

	uint8 command;
	uint8 LastCommand;
	EEPROM_Init();
	APP_alarmInit();
	LCD_init();
	APP_pwmTimer0Init(250);
	UART_init(); // initialize UART
	LastCommand=0xFF;

	/**
	 * Sync with MCU1
	 */
	while (UART_recieveByte() != M1_READY) {
	} // wait until MC2 is ready
	LCD_clearScreen();
	LCD_displayString("Welecome");
	UART_sendString("Micro2 ready#"); // send the required string to MC2



	for (;;) {

		command = UART_recieveByte();
		if (command != LastCommand) {
			LCD_clearScreen();
			LCD_displayString("command match");
			switch (command) {

			case PASSWORDISSETQUARYCOMMMAND:
				LCD_clearScreen();
				LCD_displayString("D_ISSETQUARYCOMMMAND");

				APP_passwordIsSetQuary();

				LastCommand =command;
				break;

			case PASSWORDSTOREQUARYCOMMMAND:
				LCD_clearScreen();
				LCD_displayString("D_STOREQUARYCOMMMAND");
				APP_storePassword();
				LastCommand =command;
				break;
			case PASSWORDSETFLAGQUARYCOMMMAND:
				LCD_clearScreen();
				LCD_displayString("D_SETFLAGQUARYCOMMMAND");
				PasswordSetFlag();
				LastCommand =command;
				break;
			case GETCURRENTPASSQUARYCOMMMAND:
				LCD_clearScreen();
				LCD_displayString("GETCURRENTPASSQUARYCOMMMAND");
				APP_getCurrentPassword();
				LastCommand =command;
				break;
			case ALARMTURNONCOMAND:
				LCD_clearScreen();
				LCD_displayString("ALARMTURNONCOMAND");
				APP_alarmTurnOn();
				LastCommand =command;
				break;
			case OPENDOORCOMAND:
				LCD_clearScreen();
				LCD_displayString("OPENDOORCOMAND");
				APP_openTheDoor();
				LastCommand =command;
				break;
			case CLOSEDOORCOMAND:
				LCD_clearScreen();
				LCD_displayString("CLOSEDOORCOMAND");
				APP_closeTheDoor();
				LastCommand =command;
				break;
			default:
				LCD_clearScreen();
							LCD_displayString("in defult");
				break;
			}
		}
		else{	LCD_clearScreen();
		LCD_displayString("command domatch");}


	}
}

