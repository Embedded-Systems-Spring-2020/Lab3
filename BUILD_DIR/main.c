
#include <esos.h>
#include "esos_pic24.h"
#include "esos_pic24_rs232.h"
#include <p33EP512GP806.h>
#include <pic24_all.h>

#include <stdio.h>
#include <stdlib.h>
#include "revF14.h"

void user_init(){
	config_esos_uiF14();
	uint16_t u16_period3 = 500;
	uint16_t u16_period1 = 250;
	uint16_t u16_period2 = 100;
	
	esos_RegisterTask(buttonsAndLights);
	esos_RegisterTask(drawDisplay);
	
	char ac_onAndOff["      "];
	
}

ESOS_USER_TASK(buttonsAndLights) {
    ESOS_TASK_BEGIN();
    esos_uiF14_flashLED3(u16_period3); //green LED heartbeat flash forever
    if (esos_uiF14_isSW2Pressed() && esos_uiF14_isSW3Released() || esos_uiF14_isSW1Pressed() && esos_uiF14_isSW3Pressed()){
		esos_uiF14_turnLED1On();
	}
	elseif {esos_uiF14_isSW1DoublePressed() || esos_uiF14_isSW2DoublePressed()){
		for(int i = 0; i < 3; i += 1 ){
			esos_uiF14_turnLED2On ();
			ESOS_TASK_WAIT_TICKS(150);
			esos_uiF14_turnLED2Off ();
			ESOS_TASK_WAIT_TICKS(150);
		}
	}
	if (esos_uiF14_isRPGTurningSlow(){
		esos_uiF14_turnLED2On();
	}
	elseif (esos_uiF14_isRPGTurningMedium();{
		esos_uiF14_flashLED2(u16_period3);
	}
	elseif (esos_uiF14_isRPGTurningFast(){
		esos_uiF14_flashLED3(u16_period2);
	}
	ESOS_TASK_END();
}
ESOS_USER_TASK(drawDisplay) {
    ESOS_TASK_BEGIN();
		ac_onAndOff["      "];
		if (esos_uiF14_isSW1Pressed()){
			ac_onAndOff[0] = "X";
		}
		if(esos_uiF14_isSW1DoublePressed()){
			ac_onAndOff[1] = "X";
		}
		if (esos_uiF14_isSW2Pressed()){
			ac_onAndOff[2] = "X";
		}
		if(esos_uiF14_isSW2DoublePressed()){
			ac_onAndOff[3] = "X";
		}
		if (esos_uiF14_isSW3Pressed()){
			ac_onAndOff[4] = "X";
		}
		if(esos_uiF14_isSW3DoublePressed()){
			ac_onAndOff[5] = "X";
		}
		for(int i = 0; i < 60; i += 1 ){println("\b");}  //clear the screen with backspaces
		println("Sw1 is On %c   Sw1 is Double Pressed %c\n", ac_onAndOff[0], ac_onAndOff[1]);
		println("Sw2 is On %c   Sw2 is Double Pressed %c\n", ac_onAndOff[2], ac_onAndOff[3]);
		println("Sw3 is On %c   Sw3 is Double Pressed %c\n", ac_onAndOff[4], ac_onAndOff[5]);
	ESOS_TASK_END();
}


