

#include <esos.h>
#include "esos_pic24.h"
#include "esos_pic24_rs232.h"
#include <p33EP512GP806.h>
#include <pic24_all.h>
#include "esos_f14ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "revF14.h"
#include "dataXfer.h"

 enum { u16_DOUBLE_PRESS_LOWER_MS_NDX, 
		u16_DOUBLE_PRESS_UPPER_MS_NDX, 
		u16_RPG_MEDIUM_MS_NDX, 
		u16_RPG_FAST_MS_NDX,
		u16_RPG_PERIOD_NDX,
		U16_RPG_VALUE_NDX};  

ESOS_USER_TASK(drawDisplay) {
    ESOS_TASK_BEGIN();
		initDataXfer(); 
		SPECIFY_VAR(u16_DOUBLE_PRESS_LOWER_MS_NDX, _st_esos_uiF14Data.u16_doublePressLowerMs, TRUE, "%u", "Lower double press time limit");
		SPECIFY_VAR(u16_DOUBLE_PRESS_UPPER_MS_NDX, _st_esos_uiF14Data.u16_doublePressUpperMs, TRUE, "%u", "Upper double press time limit");
		SPECIFY_VAR(u16_RPG_MEDIUM_MS_NDX, _st_esos_uiF14Data.u16_RPGMediumMs, TRUE, "%u", "Time in ms between RPG clicks -slow to medium");
		SPECIFY_VAR(u16_RPG_FAST_MS_NDX, _st_esos_uiF14Data.u16_RPGFastMs, TRUE, "%u", "Time in ms between RPG clicks -medium to fast");
		SPECIFY_VAR(u16_RPG_PERIOD_NDX, _st_esos_uiF14Data.u16_RPGPeriodMs, FALSE, %u, "Time between clicks in ms")
		SPECIFY_VAR(U16_RPG_VALUE_NDX, _st_esos_uiF14Data.u16_RPGCounter, FALSE, %u, "Current RPG Counter")		
		while(1){
			if (esos_uiF14_isSW1Pressed()){outString("\nSw1 is Pushed  ")}
			if (esos_uiF14_isSW1Released()){outString("Sw1 is Released")}
			if (esos_uiF14_isSW1DoublePressed()){outString("Sw1 is Double Pressed\n")
				ESOS_TASK_WAIT_TICKS(750)
			}else {outString("Sw1 is NOT Double Pressed\n")}
			if (esos_uiF14_isSW2Pressed()){outString("Sw2 is Pushed  ")}
			if (esos_uiF14_isSW2Released()){outString("Sw2 is Released")}
			if (esos_uiF14_isSW2DoublePressed()){outString("Sw2 is Double Pressed\n")
				ESOS_TASK_WAIT_TICKS(750)
			}else {outString("Sw2 is NOT Double Pressed\n")}
			if (esos_uiF14_isSW3Pressed()){outString("Sw3 is Pushed  ")}
			if (esos_uiF14_isSW3Released()){outString("Sw3 is Released")}
			if (esos_uiF14_isSW3DoublePressed()){outString("Sw3 is Double Pressed\n\n")
				ESOS_TASK_WAIT_TICKS(750)
			}else {outString("Sw3 is NOT Double Pressed\n\n")}
			if (esos_uiF14_isRpgTurning()){outString("RPG is Turning ")
				if (esos_uiF14_isRpgTurningCW()){outString("CW ")}
				else {outString("CCW")}
				if esos_uiF14_isRpgTurningSlow()){outString("Slowly\n")}
				else if (esos_uiF14_isRpgTurningMedium()){outString("Mediumly\n")}
				else (esos_uiF14_isRpgTurningFast()){outString("Fastly\n")}
			else {outString("RPG is Not Turning")}
			ESOS_TASK_WAIT_TICKS(50)
			outString("\n\n\n\n");
		}
	ESOS_TASK_END();
}
void user_init(){
	
	esos_RegisterTask(drawDisplay);
		
}