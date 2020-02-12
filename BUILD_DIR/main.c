

#include <esos.h>
#include "esos_pic24.h"
//#include "esos_pic24_rs232.h"
#include <p33EP512GP806.h>
#include <pic24_all.h>
#include "esos_f14ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "pic24_util.h"
#include "pic24_serial.h"
#include "revF14.h"
#include <dataXfer.h> //this is the library that uses the uc/pc variable on the bootloader

 enum { u16_DOUBLE_PRESS_UPPER_MS_NDX, // the variables that will be displayed on uc/pc variable tab
		u16_RPG_SLOW_MS_NDX,
		u16_RPG_MEDIUM_MS_NDX, 
		u16_RPG_FAST_MS_NDX,
		u16_RPG_PERIOD_NDX,
		U16_RPG_VALUE_NDX};  

ESOS_USER_TASK(drawDisplay) {
    ESOS_TASK_BEGIN();
		initDataXfer(); 
		//format for below... var name from enum above, actual var name, T/F changeable, label
		SPECIFY_VAR(u16_DOUBLE_PRESS_UPPER_MS_NDX, _st_esos_uiF14Data.u16_doublePressUpperMs, TRUE, "%u", "Upper double press time limit");
		SPECIFY_VAR(u16_RPG_SLOW_MS_NDX, _st_esos_uiF14Data.u16_RPGNotMovingToSlowPeriodMs, TRUE, "%u", "Time in ms between RPG clicks -not moving to slow");
		SPECIFY_VAR(u16_RPG_MEDIUM_MS_NDX, _st_esos_uiF14Data.u16_RPGSlowToMediumPeriodMs, TRUE, "%u", "Time in ms between RPG clicks -slow to medium");
		SPECIFY_VAR(u16_RPG_FAST_MS_NDX, _st_esos_uiF14Data.u16_RPGMediumToFastPeriodMs, TRUE, "%u", "Time in ms between RPG clicks -medium to fast");
		SPECIFY_VAR(u16_RPG_PERIOD_NDX, _st_esos_uiF14Data.u16_RPGPeriodMs, FALSE, "%u", "Time between clicks in ms");
		SPECIFY_VAR(U16_RPG_VALUE_NDX, _st_esos_uiF14Data.i16_RPGCounter, FALSE, "%u", "Current RPG Counter");	
		while(1){
			if (esos_uiF14_isSW1Pressed()){outString("\nSw1 is Pushed  ");}
			if (esos_uiF14_isSW1Released()){outString("Sw1 is Released");}
			if (esos_uiF14_isSW1DoublePressed()){outString("Sw1 is Double Pressed\n");
				ESOS_TASK_WAIT_TICKS(300);
			} else {outString("Sw1 is NOT Double Pressed\n");}
			if (esos_uiF14_isSW2Pressed()){outString("Sw2 is Pushed  ");}
			if (esos_uiF14_isSW2Released()){outString("Sw2 is Released");}
			if (esos_uiF14_isSW2DoublePressed()){outString("Sw2 is Double Pressed\n");
				ESOS_TASK_WAIT_TICKS(300);
			} else {outString("Sw2 is NOT Double Pressed\n");}
			if (esos_uiF14_isSW3Pressed()){outString("Sw3 is Pushed  ");}
			if (esos_uiF14_isSW3Released()){outString("Sw3 is Released");}
			if (esos_uiF14_isSW3DoublePressed()){outString("Sw3 is Double Pressed\n\n");
				ESOS_TASK_WAIT_TICKS(300);
			} else {outString("Sw3 is NOT Double Pressed\n\n");}

			if (esos_uiF14_isRPGTurning()) {
				
				outString("RPG is Turning ");
				if (esos_uiF14_isRPGTurningCW()) { 
					outString("CW ");
				} else {
					outString("CCW");
				}
				if (esos_uiF14_isRPGTurningSlow()) {
					outString(" Slowly\n");
				} else if (esos_uiF14_isRPGTurningMedium()) {
					outString(" Mediumly\n");
				} else { 
					outString(" Fastly\n");
				}
			} else {
				outString("RPG is Not Turning");
			}
			ESOS_TASK_WAIT_TICKS(50);
			outString("\n\n\n\n\n\n\n\n");
		}
	ESOS_TASK_END();
}
void user_init(){
	
	esos_RegisterTask(drawDisplay);
	
		
}
