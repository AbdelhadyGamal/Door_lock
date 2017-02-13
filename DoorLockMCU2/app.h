/*
 * appl_services_states.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Abdelhady
 */

#ifndef APP_H_
#define APP_H_

#include "common_macros.h"
#include "std_types.h"
#include "hwal_includes.h"

#define ALARM_PORT_DIRECTION DDRB
#define PASSWORD_FLAG_LOCATION  0x0211
#define PASSWORD_LOCATION  0x0311
#define PASSWORD_IS_SET 0x0F
#define PASSWORD_IS_CLEARED 0x00
#define PASSWORD_LENGTH 0x08
#define ALARMPORT PORTB
#define ALARMPORTDIRECTION DDRB
#define PASSWORDISSETQUARYCOMMMAND 0x00
#define PASSWORDSTOREQUARYCOMMMAND 0x01
#define PASSWORDSETFLAGQUARYCOMMMAND 0x02
#define GETCURRENTPASSQUARYCOMMMAND 0x03
#define ALARMTURNONCOMAND 0x04
#define OPENDOORCOMAND 0x05
#define CLOSEDOORCOMAND 0x06

void APP_alarmInit();
void APP_alarmTurnOn();
 void APP_setPassword() ;
 void APP_getCurrentPassword();
uint8 APP_twoArrayMatch(uint8 *pass1,uint8 *pass2);
void APP_pwmTimer0Init(unsigned char set_duty_cycle);
void PasswordSetFlag();
void APP_openTheDoor();
void APP_closeTheDoor();
void APP_storePassword() ;
void APP_getPasswordFromUser(uint8 *a);
void APP_passwordIsSetQuary();

#endif /* APP_H_ */
