/*******************************************************************
 * 
 * C code framework for ESOS user-interface (UI) service
 * 
 *    requires the EMBEDDED SYSTEMS target rev. F14
 * 
 * ****************************************************************/
# include <esos_f14ui.h>
# include <revF14.h>

#define DOUBLEPRESS_SW1_TIMER_EXPIRED ESOS_USER_FLAG_1
#define DOUBLEPRESS_SW2_TIMER_EXPIRED ESOS_USER_FLAG_2
#define DOUBLEPRESS_SW3_TIMER_EXPIRED ESOS_USER_FLAG_3

#define DOUBLE_PRESS_LOWER_BOUND_MS 120
#define DOUBLE_PRESS_UPPER_BOUND_MS 300

// PRIVATE FUNCTIONS
inline void _esos_uiF14_setRPGCounter (int16_t i16_newValue) {
    _st_esos_uiF14Data.i16_RPGCounter = i16_newValue;
}
inline int16_t _esos_uiF14_getLastRPGCounter (void){
	return(_st_esos_uiF14Data.i16_lastRPGCounter);
}
inline void _esos_uiF14_setLastRPGCounter (int16_t i16_newRPGCounter){
	_st_esos_uiF14Data.i16_lastRPGCounter = i16_newRPGCounter;
}
inline uint16_t _esos_uiF14_getRPGPeriod (void){
	return(_st_esos_uiF14Data.u16_RPGPeriodMs);
}

// PUBLIC SWITCH FUNCTIONS
inline BOOL esos_uiF14_isSW1Pressed (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW1Released (void) {
    return (_st_esos_uiF14Data.b_SW1Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW1DoublePressed (void) {
	if (_st_esos_uiF14Data.b_SW1DoublePressed==TRUE) {
		_st_esos_uiF14Data.b_SW1DoublePressed = FALSE;
		return TRUE;
	} else {
		return FALSE;
	}
}

inline BOOL esos_uiF14_isSW2Pressed (void) {
    return (_st_esos_uiF14Data.b_SW2Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW2Released (void) {
    return (_st_esos_uiF14Data.b_SW2Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW2DoublePressed (void) {
	if (_st_esos_uiF14Data.b_SW2DoublePressed==TRUE) {
		_st_esos_uiF14Data.b_SW2DoublePressed = FALSE;
		return TRUE;
	} else {
		return FALSE;
	}
}

inline BOOL esos_uiF14_isSW3Pressed (void) {
    return (_st_esos_uiF14Data.b_SW3Pressed==TRUE);
}

inline BOOL esos_uiF14_isSW3Released (void) {
    return (_st_esos_uiF14Data.b_SW3Pressed==FALSE);
}

inline BOOL esos_uiF14_isSW3DoublePressed (void) {
	if (_st_esos_uiF14Data.b_SW3DoublePressed==TRUE) {
		_st_esos_uiF14Data.b_SW3DoublePressed = FALSE;
		return TRUE;
	} else {
		return FALSE;
	}
}

// PUBLIC LED FUNCTIONS

//Ryan: I think some of these functions are intended to actually
//trigger LED changes, so I'm updating the LED register

inline BOOL esos_uiF14_isLED1On (void) {
    return (_st_esos_uiF14Data.b_LED1On);
}

inline BOOL esos_uiF14_isLED1Off (void) {
    return (_st_esos_uiF14Data.b_LED1On);
}

inline void esos_uiF14_turnLED1On (void) {
    LED1 = 1;
    _st_esos_uiF14Data.b_LED1On = TRUE;
    return;
}

inline void esos_uiF14_turnLED1Off (void) {
    LED1 = 0;
    _st_esos_uiF14Data.b_LED1On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED1 (void) {
    LED1 = !LED1;
    _st_esos_uiF14Data.b_LED1On ^= 1;
    return;
}

inline void esos_uiF14_flashLED1( uint16_t u16_period1) {
    _st_esos_uiF14Data.u16_LED1FlashPeriod = u16_period1;
	_st_esos_uiF14Data.b_LED1Flashing = TRUE;
    return
}

inline BOOL esos_uiF14_isLED2On (void) {
    return (_st_esos_uiF14Data.b_LED2On);
}

inline BOOL esos_uiF14_isLED2Off (void) {
    return (_st_esos_uiF14Data.b_LED2On);
}

inline void esos_uiF14_turnLED2On (void) {
    LED2 = 1;
    _st_esos_uiF14Data.b_LED2On = TRUE;
    return;
}

inline void esos_uiF14_turnLED2Off (void) {
    LED2 = 0;
    _st_esos_uiF14Data.b_LED2On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED2 (void) {
    LED2 = !LED2;
    _st_esos_uiF14Data.b_LED2On ^= 1;
    return;
}

inline void esos_uiF14_flashLED2( uint16_t u16_period2) {
    _st_esos_uiF14Data.u16_LED2FlashPeriod = u16_period2;
	_st_esos_uiF14Data.b_LED2Flashing = TRUE;
    return
}

inline BOOL esos_uiF14_isLED3On (void) {
    return (_st_esos_uiF14Data.b_LED3On);
}

inline BOOL esos_uiF14_isLED3Off (void) {
    return (_st_esos_uiF14Data.b_LED3On);
}

inline void esos_uiF14_turnLED3On (void) {
    //LED3 is low active
    LED3 = 0;
    _st_esos_uiF14Data.b_LED3On = TRUE;
    return;
}

inline void esos_uiF14_turnLED3Off (void) {
    LED3 = 1;
    _st_esos_uiF14Data.b_LED3On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED3 (void) {
    LED3 = !LED3;
    _st_esos_uiF14Data.b_LED3On ^= 1;
    return;
}

inline void esos_uiF14_flashLED3( uint16_t u16_period3) {
    _st_esos_uiF14Data.u16_LED3FlashPeriod = u16_period3;
	_st_esos_uiF14Data.b_LED3Flashing = TRUE;
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

inline int16_t esos_uiF14_getRpgCounter_i16 ( void ) {
    return _st_esos_uiF14Data.i16_RPGCounter;
}

inline BOOL esos_uiF14_isRpgTurning ( void ) {
    return !(_st_esos_uiF14Data.b_RPGNotMoving);
}

inline BOOL esos_uiF14_isRpgTurningSlow( void ) {
	return _st_esos_uiF14Data.b_RPGSlow;
}

inline BOOL esos_uiF14_isRpgTurningMedium( void ) {
	return _st_esos_uiF14Data.b_RPGMedium;
}

inline BOOL esos_uiF14_isRpgTurningFast( void ) {
	return _st_esos_uiF14Data.b_RPGFast;
}

inline BOOL esos_uiF14_isRpgTurningCW( void ) {
	return _st_esos_uiF14Data.b_RPGCW;
}

inline BOOL esos_uiF14_isRpgTurningCCW( void ) {
	return _st_esos_uiF14Data.b_RPGCCW;
}

inline uint16_t esos_uiF14_getRpgPeriod( void ) {
	return _st_esos_uiF14Data.u16_RPGPeriodMs;
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
  CONFIG_RPG();

  esos_RegisterTask( __uiF14_task );
}

ESOS_USER_TIMER(__doublepress_SW1_timer) {
	esos_SetUserFlag(DOUBLEPRESS_SW1_TIMER_EXPIRED);
}

ESOS_USER_TIMER(__doublepress_SW2_timer) {
	esos_SetUserFlag(DOUBLEPRESS_SW2_TIMER_EXPIRED);
}

ESOS_USER_TIMER(__doublepress_SW3_timer) {
	esos_SetUserFlag(DOUBLEPRESS_SW3_TIMER_EXPIRED);
}

// UIF14 task to manage user-interface
ESOS_USER_TASK( __esos_uiF14_task ){
  
  ESOS_TASK_BEGIN();
  while(TRUE) {
    /* THOUGHTS ON THIS SOLUTION FOR PUSHBUTTON DOUBLE-PRESSES
		Pros:
			Dead simple
			Easy to read
			Maybe easy to maintain?? we will se
		Cons:
			MIGHT introduce latency to our main loop, which is bad (probably not
				significant doe)
	*/

	//-------- LED flashing ---------
	//This operates on the assumption that this ESOS task is called
	//approximately every 10 ms
	  
	
	  																			// yeah im commenting past 80 chars 
	// SW1_PRESSED																// what are you gonna do about it
	if (SW1_PRESSED) {															//	hopefully not dock points uhhh
		ESOS_TASK_WAIT_TICKS(DOUBLE_PRESS_LOWER_BOUND_MS);						// Wait a small amount of time
		esos_RegisterTimer(__doublepress_SW1_timer, DOUBLE_PRESS_UPPER_BOUND_MS);	// start timer
		ESOS_TASK_WAIT_UNTIL(													
			esos_IsUserFlagSet(DOUBLEPRESS_SW1_TIMER_EXPIRED) || 					// Funky identation to keep code 
			SW1_PRESSED															// under 80 chars but mostly readable
		);				
		if (!esos_IsUserFlagSet(DOUBLEPRESS_SW1_TIMER_EXPIRED)) {					// If we branch here, the switch was not
			_st_esos_uiF14Data.b_SW1DoublePressed = TRUE;						// pressed again in time; single press
			_st_esos_uiF14Data.b_SW1Pressed = FALSE;
		} else {
			_st_esos_uiF14Data.b_SW1Pressed = TRUE;								// If we branch here, the switch must
			_st_esos_uiF14Data.b_SW1DoublePressed = FALSE;						// have been pressed; double press
			esos_ClearUserFlag(DOUBLEPRESS_SW1_TIMER_EXPIRED);						// Reset the flag for next time
		}
		esos_UnregisterTimer(__doublepress_SW1_timer);								// Disable the timer until we need it 
	}																			//again

	// SW2_PRESSED
	if (SW2_PRESSED) {															
		ESOS_TASK_WAIT_TICKS(DOUBLE_PRESS_LOWER_BOUND_MS);						
		esos_RegisterTimer(__doublepress_SW2_timer, DOUBLE_PRESS_UPPER_BOUND_MS);
		ESOS_TASK_WAIT_UNTIL(													
			esos_IsUserFlagSet(DOUBLEPRESS_SW2_TIMER_EXPIRED) || 				
			SW2_PRESSED															
		);				
		if (!esos_IsUserFlagSet(DOUBLEPRESS_SW1_TIMER_EXPIRED)) {				
			_st_esos_uiF14Data.b_SW2DoublePressed = TRUE;						
			_st_esos_uiF14Data.b_SW2Pressed = FALSE;
		} else {
			_st_esos_uiF14Data.b_SW2Pressed = TRUE;								
			_st_esos_uiF14Data.b_SW2DoublePressed = FALSE;						
			esos_ClearUserFlag(DOUBLEPRESS_SW2_TIMER_EXPIRED);						
		}
		esos_UnregisterTimer(__doublepress_SW2_timer);								
	}	

	// SW3_PRESSED
	if (SW3_PRESSED) {															
		ESOS_TASK_WAIT_TICKS(DOUBLE_PRESS_LOWER_BOUND_MS);						
		esos_RegisterTimer(__doublepress_SW3_timer, DOUBLE_PRESS_UPPER_BOUND_MS);
		ESOS_TASK_WAIT_UNTIL(													
			esos_IsUserFlagSet(DOUBLEPRESS_SW3_TIMER_EXPIRED) || 				
			SW2_PRESSED															
		);				
		if (!esos_IsUserFlagSet(DOUBLEPRESS_SW3_TIMER_EXPIRED)) {				
			_st_esos_uiF14Data.b_SW2DoublePressed = TRUE;						
			_st_esos_uiF14Data.b_SW2Pressed = FALSE;
		} else {
			_st_esos_uiF14Data.b_SW3nbPressed = TRUE;								
			_st_esos_uiF14Data.b_SW3DoublePressed = FALSE;						
			esos_ClearUserFlag(DOUBLEPRESS_SW3_TIMER_EXPIRED);						
		}
		esos_UnregisterTimer(__doublepress_SW3_timer);								
	}	
		
	// LED1 (Red) 
	LED1 = _st_esos_uiF14Data.b_LED1On;
	//_st_esos_uiF14Data.u16_LED1FlashPeriod;    

	// LED2 (Yellow) 
	LED2 = _st_esos_uiF14Data.b_LED2On;
	//_st_esos_uiF14Data.u16_LED2FlashPeriod;    

	// LED3 (Green)    
	LED3 = _st_esos_uiF14Data.b_LED3On;
	//_st_esos_uiF14Data.u16_LED3FlashPeriod;        
	
	//+++++++++++++++RPG++++++++++++++++++++
	//determines if RPG is moving
	if (RPGA != _st_esos_uiF14Data.b_RPGALast){ 
		//determines time since last change, used for speed calc
		_st_esos_uiF14Data.RPGPeriodMs = (esos_GetSystemTick()) - 
										 (_st_esos_uiF14Data.u16_RPGLastChangeMs); 
		_st_esos_uiF14Data.b_RPGNotMoving = false;
		
		// compare time since last RPGA change to slow/med/fast cutoffs
		if (_st_esos_uiF14Data.RPGPeriodMs >= _st_esos_uiF14Data.u16_RPGMediumToFastPeriodMs){
			_st_esos_uiF14Data.b_RPGFast = TRUE;
		}	
		else if (_st_esos_uiF14Data.RPGPeriodMs >= _st_esos_uiF14Data.u16_RPGSlowToMediumPeriodMs){
		  _st_esos_uiF14Data.b_RPGMedium = TRUE;
		}
		else {
			st_esos_uiF14Data.b_RPGSlow = TRUE;
		}
		
		//determine CW or CCW; remember RPGA just changed
		if ((RPGA == 0 && RPGB == 1) || (RPGA == 1 && RPGB == 0){
			_st_esos_uiF14Data.b_RPGCW = TRUE;
			_st_esos_uiF14Data.b_RPGCCW = FALSE;
		}
		else{
			_st_esos_uiF14Data.b_RPGCW = FALSE;
			_st_esos_uiF14Data.b_RPGCCW = TRUE;
		}
		
		//update the counter for later use in revolution calculations 
		if (_st_esos_uiF14Data.b_RPGCW){
			_st_esos_uiF14Data.i16_RPGCounter +=1;
		}
		if (_st_esos_uiF14Data.b_RPGCCW){
			_st_esos_uiF14Data.i16_RPGCounter -=1;
		}
		if (_st_esos_uiF14Data.i16_RPGCounter == _st_esos_uiF14Data.i16_lastRPGCounter +
												__RPGCountsPerRev){
			_st_esos_uiF14Data.b_RPGCWRev = TRUE;
			_st_esos_uiF14Data.i16_lastRPGCounter = _st_esos_uiF14Data.i16_RPGCounter;
		}
		else if (_st_esos_uiF14Data.i16_RPGCounter == _st_esos_uiF14Data.i16_lastRPGCounter -
												__RPGCountsPerRev){
			_st_esos_uiF14Data.b_RPGCCWRev = TRUE;
			_st_esos_uiF14Data.i16_lastRPGCounter = _st_esos_uiF14Data.i16_RPGCounter;
		}
		else {
			  _st_esos_uiF14Data.b_RPGCWRev = FALSE;
			  _st_esos_uiF14Data.b_RPGCCWRev = FALSE;
		}
	}
	else {  //reset flags after short delay to show no RPG motion
		ESOS_USER_TASK_WAIT_TICKS(_st_esos_uiF14Data.u16_RPGNotMovingToSlowPeriodMs);
		_st_esos_uiF14Data.b_RPGNotMoving = TRUE;
		_st_esos_uiF14Data.b_RPGFast = FALSE;
		_st_esos_uiF14Data.b_RPGMedium = FALSE;
		_st_esos_uiF14Data.b_RPGSlow = FALSE;
		_st_esos_uiF14Data.b_RPGCW = FALSE;
		_st_esos_uiF14Data.b_RPGCCW = FALSE;
	}
	
	
	
    ESOS_TASK_WAIT_TICKS( __ESOS_UIF14_UI_PERIOD_MS );
  }
  ESOS_TASK_END();
}
