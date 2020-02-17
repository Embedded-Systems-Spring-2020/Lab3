#include <esos.h>
#include "esos_pic24.h"
#include "esos_pic24_rs232.h"
#include <p33EP512GP806.h>
#include <stdio.h>
#include <stdlib.h>
#include "pic24_util.h"
#include "pic24_serial.h"
#include "esos_comm.h"
#include <string.h>

#include "esos_f14ui.h"


char buffer[8];

ESOS_USER_TASK(drawDisplay) {
    ESOS_TASK_BEGIN();
		while(1){

			ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
			if (esos_uiF14_isSW1Pressed()){ESOS_TASK_WAIT_ON_SEND_STRING("\nSw1 is Pushed  ");}
			if (esos_uiF14_isSW1Released()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw1 is Released");}
			if (esos_uiF14_isSW1DoublePressed()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw1 is Double Pressed\n");
			} else {ESOS_TASK_WAIT_ON_SEND_STRING("Sw1 is NOT Double Pressed\n");}
			if (esos_uiF14_isSW2Pressed()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw2 is Pushed  ");}
			if (esos_uiF14_isSW2Released()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw2 is Released");}
			if (esos_uiF14_isSW2DoublePressed()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw2 is Double Pressed\n");
			} else {ESOS_TASK_WAIT_ON_SEND_STRING("Sw2 is NOT Double Pressed\n");}
			if (esos_uiF14_isSW3Pressed()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw3 is Pushed  ");}
			if (esos_uiF14_isSW3Released()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw3 is Released");}
			if (esos_uiF14_isSW3DoublePressed()){ESOS_TASK_WAIT_ON_SEND_STRING("Sw3 is Double Pressed\n\n");
			} else {ESOS_TASK_WAIT_ON_SEND_STRING("Sw3 is NOT Double Pressed\n\n");}

			if (esos_uiF14_isRPGTurning()) {
				ESOS_TASK_WAIT_ON_SEND_STRING("RPG is Turning ");
				if (esos_uiF14_isRPGTurningCW()) { 
					ESOS_TASK_WAIT_ON_SEND_STRING("CW ");
				} else {
					ESOS_TASK_WAIT_ON_SEND_STRING("CCW");
				}
				if (esos_uiF14_isRPGTurningSlow()) {
					ESOS_TASK_WAIT_ON_SEND_STRING(" Slowly\n");
				} else if (esos_uiF14_isRPGTurningMedium()) {
					ESOS_TASK_WAIT_ON_SEND_STRING(" Mediumly\n");
				} else { 
					ESOS_TASK_WAIT_ON_SEND_STRING(" Fastly\n");
				}
			} else {
				ESOS_TASK_WAIT_ON_SEND_STRING("RPG is Not Turning");
			}
			ESOS_TASK_WAIT_ON_SEND_STRING("\n\n\n\n\n\n");

			ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();
			ESOS_TASK_YIELD();
		}
	ESOS_TASK_END();
}

 
ESOS_USER_TASK(demoLEDsAndSwitches) {
    ESOS_TASK_BEGIN();
	  while(1){
    	esos_uiF14_flashLED3(500);

		// RPG controls LED2
		if (esos_uiF14_isRPGTurning()){
			esos_uiF14_turnLED2Off();
		}
		if (esos_uiF14_isRPGTurningSlow()){
			esos_uiF14_turnLED2On();
		}
		if (esos_uiF14_isRPGTurningMedium()){
			esos_uiF14_flashLED2(500);
		}
		if (esos_uiF14_isRPGTurningFast()){
			esos_uiF14_flashLED2(100);
		}
		//switch on RPG (SW3) controls whether SW1 or SW2 controls LED1
		if (esos_uiF14_isSW3Released()){      
			if (esos_uiF14_isSW1Pressed()){
				esos_uiF14_turnLED1On();
			} else if (esos_uiF14_isSW1Released()){
				esos_uiF14_turnLED1Off();
			}
			if (esos_uiF14_isSW1DoublePressed()){
				int k;
				for (k = 0; k<3; k++){
					esos_uiF14_turnLED1On();
					ESOS_TASK_WAIT_TICKS(150);
					esos_uiF14_turnLED1Off();
					ESOS_TASK_WAIT_TICKS(150);
				}
			}
		}else if(esos_uiF14_isSW3Pressed()){
			if (esos_uiF14_isSW2Pressed()){
				esos_uiF14_turnLED1On();
			} else if (esos_uiF14_isSW2Released()){
				esos_uiF14_turnLED1Off();
			}
			if (esos_uiF14_isSW2DoublePressed()){
				int m;
				for (m = 0; m<3; m++){
					esos_uiF14_turnLED1On();
					ESOS_TASK_WAIT_TICKS(150);
					esos_uiF14_turnLED1Off();
					ESOS_TASK_WAIT_TICKS(150);
				}
			}
		}
		ESOS_TASK_YIELD();
	  }
	ESOS_TASK_END();
}	


ESOS_USER_TASK(menu) {
    ESOS_TASK_BEGIN();

    for (;;) {
        ledflashing:

        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING("Pick LED 2 flash period \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("1 -> 500 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("2 -> 1000 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("3 -> 3000 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("9 -> Configure switches \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("Choice:  ");
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

        ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
        ESOS_TASK_WAIT_ON_GET_STRING(buffer);
        ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING(buffer);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

        if (buffer[0] == '1') {
            esos_uiF14_flashLED2(500);
        } else if (buffer[0] == '2') {
            esos_uiF14_flashLED2(1000);
        } else if (buffer[0] == '3') {
            esos_uiF14_flashLED2(3000);
        } else if (buffer[0] == '9') {
            goto switchconfig;
        }

        goto ledflashing;

        switchconfig: 

        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING("Pick switch double press limit \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("1 -> 250 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("2 -> 400 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("3 -> 600 ms \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("9 -> Configure RPG \n");
        ESOS_TASK_WAIT_ON_SEND_STRING("Choice:  ");
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

        ESOS_TASK_WAIT_ON_AVAILABLE_IN_COMM();
        ESOS_TASK_WAIT_ON_GET_STRING(buffer);
        ESOS_TASK_SIGNAL_AVAILABLE_IN_COMM();

        ESOS_TASK_WAIT_ON_AVAILABLE_OUT_COMM();
        ESOS_TASK_WAIT_ON_SEND_STRING(buffer);
        ESOS_TASK_SIGNAL_AVAILABLE_OUT_COMM();

        if (buffer[0] == '1') {
            //We're not required to have functions which modify the
            //double press bound, so just set the value directly
            esos_uiF14_setDoublePressPeriod(250);
        } else if (buffer[0] == '2') {
            esos_uiF14_setDoublePressPeriod(400);
        } else if (buffer[0] == '3') {
            esos_uiF14_setDoublePressPeriod(600);
        } else if (buffer[0] == '9') {
            goto switchconfig;
        }

        goto switchconfig;

        // rpgconfig:

    }
    ESOS_TASK_END();
}

void user_init(void){
    config_esos_uiF14();
    // esos_RegisterTask(menu);
	esos_RegisterTask(demoLEDsAndSwitches);
	esos_RegisterTask(drawDisplay);

}
