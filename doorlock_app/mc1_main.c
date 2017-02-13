/*
 * main.c
 *
 *  Created on: Jan 28, 2017
 *      Author: Abdelhady
 *
 */

#include "uart.h"
#include "Keypad.h"
#define M1_READY 0x10

#include "app.h"

int main(void) {

	/**
	 * Initialization
	 */
	uint8 selection;
	uint8 Str[20];
	UART_init(); // initialize UART driver
	LCD_init(); // initialize LCD driver
	LCD_clearScreen();
	LCD_displayString("Welcome");

	/**
	 * Sync with MCU1
	 */
	UART_sendByte(M1_READY); // MC1 is ready
	UART_receiveString(Str); // receive the string
	LCD_clearScreen();
	LCD_displayString(Str);
	_delay_ms(500);
	LCD_clearScreen();
	LCD_displayString("System Ready #");
	_delay_ms(500);






	APP_setPassword();


	for (;;) {

		selection = APP_showOptionMenuGetAnswer();

		_delay_ms(500);
		if (APP_doesTheUserHaveThePassword()) {
			/**
			 * the user have the password
			 * Look at his selection
			 */

			if (selection == 1) {
				/**Change password */

				APP_setPassword();

			}
			if (selection == 2) {
				/** Open the door */
				APP_openTheDoor();
				_delay_ms(2000);
				APP_closeTheDoor();
				_delay_ms(2000);

			}
		} else {
			/**The user doesn't have the password*/

			APP_alarmTurnOn();

		}

	}
}

