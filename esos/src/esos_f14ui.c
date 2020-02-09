/*******************************************************************
 * 
 * C code framework for ESOS user-interface (UI) service
 * 
 *    requires the EMBEDDED SYSTEMS target rev. F14
 * 
 * ****************************************************************/
# include <esos_f14ui.h>
# include <revF14.h>

// PRIVATE FUNCTIONS
inline void _esos_uiF14_setRPGCounter (uint16_t newValue) {
    _st_esos_uiF14Data.u16_RPGCounter = newValue;
    return;
}

inline void _esos_uiF14_setLastRPGCounter (uint16_t newValue) {
    _st_esos_uiF14Data.u16_lastRPGCounter = newValue;
    return;
}

// PUBLIC SWITCH FUNCTIONS
inline BOOL esos_uiF14_isSW1Pressed (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW1Released (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW1DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW1DoublePressed==TRUE);
}

inline BOOL esos_uiF14_isSW2Pressed (void) {
    return (_st_esos_uiF14Data.b_SW2Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW2Released (void) {
    return (_st_esos_uiF14Data.b_SW2Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW2DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW2DoublePressed==TRUE);
}

inline BOOL esos_uiF14_isSW3Pressed (void) {
    return (_st_esos_uiF14Data.b_SW3Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW3Released (void) {
    return (_st_esos_uiF14Data.b_SW3Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW3DoublePressed (void) {
    return (_st_esos_uiF14Data.b_SW3DoublePressed==TRUE);
}


// PUBLIC LED FUNCTIONS

inline BOOL esos_uiF14_isLED1On (void) {
    return (_st_esos_uiF14Data.b_LED1On==TRUE);
}

inline BOOL esos_uiF14_isLED1Off (void) {
    return (_st_esos_uiF14Data.b_LED1On==FALSE);
}

inline void esos_uiF14_turnLED1On (void) {
    LED1 = 1; //turning on LED1
    _st_esos_uiF14Data.b_LED1On = TRUE;
    return;
}

inline void esos_uiF14_turnLED1Off (void) {
     LED1=0; //turning off LED1
    _st_esos_uiF14Data.b_LED1On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED1 (void) {
     LED1=!LED1; //toggles LED1
    _st_esos_uiF14Data.b_LED1On ^= 1;
    return;
}

inline void esos_uiF14_flashLED1( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED1FlashPeriod = u16_period;
    return
}

inline BOOL esos_uiF14_isLED2On (void) {
    return (_st_esos_uiF14Data.b_LED2On==TRUE);
}

inline BOOL esos_uiF14_isLED2Off (void) {
    return (_st_esos_uiF14Data.b_LED2On==FALSE);
}

inline void esos_uiF14_turnLED2On (void) {
     LED2=1; //turn on LED2
    _st_esos_uiF14Data.b_LED2On = TRUE;
    return;
}

inline void esos_uiF14_turnLED2Off (void) {
     LED2=0; //turn off LED2
    _st_esos_uiF14Data.b_LED2On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED2 (void) {
     LED2=!LED2;
    _st_esos_uiF14Data.b_LED2On ^= 1;
    return;
}

inline void esos_uiF14_flashLED2( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED2FlashPeriod = u16_period;
    return
}

inline BOOL esos_uiF14_isLED3On (void) {
    return (_st_esos_uiF14Data.b_LED3On==TRUE);
}

inline BOOL esos_uiF14_isLED3Off (void) {
    return (_st_esos_uiF14Data.b_LED3On==FALSE);
}

inline void esos_uiF14_turnLED3On (void) {
    LED3=1; //turn on LED3
    _st_esos_uiF14Data.b_LED3On = TRUE;
    return;
}

inline void esos_uiF14_turnLED3Off (void) {
    LED3=0; //turn off LED3
    _st_esos_uiF14Data.b_LED3On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED3 (void) {
    LED3=!LED3; //toggle LED3
    _st_esos_uiF14Data.b_LED3On ^= 1;
    return;
}

inline void esos_uiF14_flashLED3( uint16_t u16_period) {
    _st_esos_uiF14Data.u16_LED3FlashPeriod = u16_period;
    return
}

/****** RED, GREEN, and YELLOW functions *******/

inline void esos_uiF14_turnRedLEDOn (void) {
    //Red LED is LED1
    esos_uiF14_turnLED1On();
}

inline void esos_uiF14_turnRedLEDOff (void) {
    esos_uiF14_turnLED1Off();
}

inline void esos_uiF14_turnGreenLEDOn (void) {
    //Green LED is LED3
    esos_uiF14_turnLED3On();
}

inline void esos_uiF14_turnGreenLEDOff (void) {
    esos_uiF14_turnLED3Off();
}

inline void esos_uiF14_turnYellowLEDOn (void) {
    //Yellow LED is LED2
    esos_uiF14_turnLED2On();
}

inline void esos_uiF14_turnYellowLEDOff (void) {
    esos_uiF14_turnLED2Off();
}

// PUBLIC RPG FUNCTIONS

inline uint16_t esos_uiF14_getRpgValue_u16(void) {
	return _st_esos_uiF14Data.u16_RPGCounter;
}

inline BOOL esos_uiF14_isRpgTurning(void) {
	return (esos_uiF14_getRpgVelocity_i16() != 0);
}

inline BOOL esos_uiF14_isRpgTurningSlow(void) {
	uint16_t vel = ABS(_st_esos_uiF14Data.i16_RPGVelocity);
	return esos_uiF14_getRPGSlowThreshold() <= vel && vel < esos_uiF14_getRPGMediumThreshold();

}

inline BOOL esos_uiF14_isRpgTurningMedium(void) {
	uint16_t vel = ABS(_st_esos_uiF14Data.i16_RPGVelocity);
	return esos_uiF14_getRPGMediumThreshold() <= vel && vel < esos_uiF14_getRPGFastThreshold();
}

inline BOOL esos_uiF14_isRpgTurningFast(void) {
	return esos_uiF14_getRPGFastThreshold() < ABS(_st_esos_uiF14Data.u16_RPGVelocity);
}

inline BOOL esos_uiF14_isRpgTurningCW(void) {
	uint16_t vel = _st_esos_uiF14Data.i16_RPGVelocity;
	return (vel > 0) && (esos_uiF14_getRPGSlowThreshold() <= ABS(vel));
}

inline BOOL esos_uiF14_isRpgTurningCCW(void) {
	uint16_t vel = _st_esos_uiF14Data.i16_RPGVelocity;
	return (vel < 0) && (esos_uiF14_getRPGSlowThreshold() <= ABS(vel));
}

inline int16_t esos_uiF14_getRpgVelocity_i16(void) {
	return _st_esos_uiF14Data.i16_RPGVelocity;
}


// UIF14 INITIALIZATION FUNCTION

void config_esos_uiF14() {
  // setup your UI implementation

  //Step 1: setup LEDs
  //
  CONFIG_LED1();
  CONFIG_LED2();
  CONFIG_LED3();

  //Step 2: setup switches
  CONFIG_SW1();
  CONFIG_SW2();
  CONFIG_SW3();

  //Step 3: setup RPG

  __RPG_UI_CONFIG();


  esos_RegisterTask( __uiF14_task );
}

////if the LED is turned off at the time of the flash we want to turn it on...
//can add an else condition to turn the LED off if it is on during the flash..however 
//will that be necessary?

ESOS_USER_TIMER(swTimerLED1)
{
     if (esos_uiF14_isLED1Off() == true)
        {
            //turn led on
            esos_uiF14_turnLED1On(); //LED1 = 1;
            esos_uiF14_turnLED1Off();
        }
}
ESOS_USER_TIMER(swTimerLED2)
{
	if (esos_uiF14_isLED2Off() == true) 
        {
            esos_uiF14_turnLED2On();  //LED2 = 1;
            esos_uiF14_turnLED2Off();
        }
}
ESOS_USER_TIMER(swTimerLED3)
{
	if(esos_uiF14_isLED3Off() == true)
        {
            esos_uiF14_turnLED3On(); //LED3 = 1;
            esos_uiF14_turnLED3Off();
        }
}
    //if LEDS are already on...should we turn it off and then back on as a "flash".

   // if (esos_uiF14_isLED1On() == true) {
   //     
   //     esos_uif14_turnLED1Off(); //LED1 = 0;
   //     esos_uiF14_turnLED1On();
   // }
   // 
   // if (esos_uiF14_isLED2On() == true) {
   //     esos_uiF14_turnLED2Off()   //LED2 = 0;
   //     esos_uiF14_turnLED2On();
   // }

   //  if (esos_uiF14_isLED3On() == true) {
   //     esos_uiF14_turnLED3Off()  //LED3 = 0;
   //     esos_uiF14_turnLED3On();
   // }

}


// UIF14 task to manage user-interface
ESOS_USER_TASK( __esos_uiF14_task ){
  
  ESOS_TASK_BEGIN();
  while(TRUE) {
    // do your UI stuff here
    ESOS_TASK_WAIT_TICKS( __ESOS_UIF14_UI_PERIOD );
	  
   //flashes the LED lights...I HOPE. Based on the LED flash period given. 
	esos_RegisterTimer(swTimerLED1, st_esos_uiF14Data.u16_LED1FlashPeriod);
        esos_RegisterTimer(swTimerLED2, st_esos_uiF14Data.u16_LED2FlashPeriod);
        esos_RegisterTimer(swTimerLED3, st_esos_uiF14Data.u16_LED3FlashPeriod);
  }
  ESOS_TASK_END();
}

//-------------------------INITIAL THOUGHTS--------------------------------------//

    //not sure how to implement but I will figure it out :)
    //we need a delay to actually flash the led....

    //ESOS_TASK_BEGIN();

    //while (TRUE)
    //{
    //    //we need to know what the flash period is....flash period is in ms
    //    //...then we can determine how long we can flash the leds per flash period..

    //    //------------IDEA---------------------IDEA----------//
    //    // uint_16 pd = _st_esos_uiF14Data.u16_LED1FlashPeriod; 
    //    // LED1 = 1;
    //    // ESOS_TASK_WAIT_TICKS(pd);
    //    //turn LED1 off

    //    // uint_16 pd2 = _st_esos_uiF14Data.u16_LED2FlashPeriod; 
    //    // LED2 = 1;
    //    // ESOS_TASK_WAIT_TICKS(pd2);
    //    //turn LED2 off

    //    //uint_16 pd3 = _st_esos_uiF14Data.u16_LED3FlashPeriod;
    //    // LED3 = 1;
    //    // ESOS_TASK_WAIT_TICKS(pd3);
    //    //turn LED3 off
    //    //------------END------------------------END-----------//


    //    return FALSE
    //}

    //ESOS_TASK_END();
