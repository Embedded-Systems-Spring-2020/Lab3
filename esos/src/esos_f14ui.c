/*******************************************************************
 * 
 * C code framework for ESOS user-interface (UI) service
 * 
 *    requires the EMBEDDED SYSTEMS target rev. F14
 * 
 * ****************************************************************/
# include <esos_f14ui.h>
# include <revF14.h>

#define MINIMUM_LED_FLASH_PERIOD 100



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


inline BOOL esos_uiF14_isLED1On (void) {
    return (_st_esos_uiF14Data.b_LED1On);
}

inline BOOL esos_uiF14_isLED1Off (void) {
    return (_st_esos_uiF14Data.b_LED1On);
}

inline void esos_uiF14_turnLED1On (void) {
    _st_esos_uiF14Data.b_LED1On = TRUE;
    return;
}

inline void esos_uiF14_turnLED1Off (void) {
    _st_esos_uiF14Data.b_LED1On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED1 (void) {
    _st_esos_uiF14Data.b_LED1On ^= 1;
    return;
}

inline void esos_uiF14_flashLED1( uint16_t u16_period1) {
	//Choose a reasonable minimum period
	if (u16_period1 < MINIMUM_LED_FLASH_PERIOD) {
		u16_period1 = MINIMUM_LED_FLASH_PERIOD;
	} 
    _st_esos_uiF14Data.u16_LED1FlashPeriod = u16_period1;
    return
}

inline uint16_t esos_uiF14_getLED1Period(void) {
	return _st_esos_uiF14Data.u16_LED1FlashPeriod;
}

inline BOOL esos_uiF14_isLED2On (void) {
    return (_st_esos_uiF14Data.b_LED2On);
}

inline BOOL esos_uiF14_isLED2Off (void) {
    return (_st_esos_uiF14Data.b_LED2On);
}

inline void esos_uiF14_turnLED2On (void) {
    _st_esos_uiF14Data.b_LED2On = TRUE;
    return;
}

inline void esos_uiF14_turnLED2Off (void) {
    _st_esos_uiF14Data.b_LED2On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED2 (void) {
    _st_esos_uiF14Data.b_LED2On ^= 1;
    return;
}

inline void esos_uiF14_flashLED2( uint16_t u16_period2) {
	//Choose a reasonable minimum period
	if (u16_period2 < MINIMUM_LED_FLASH_PERIOD) {
		u16_period2 = MINIMUM_LED_FLASH_PERIOD;
	} 
    _st_esos_uiF14Data.u16_LED2FlashPeriod = u16_period2;
    return
}

inline uint16_t esos_uiF14_getLED2Period(void) {
	return _st_esos_uiF14Data.u16_LED2FlashPeriod;
}

inline BOOL esos_uiF14_isLED3On (void) {
    return (_st_esos_uiF14Data.b_LED3On);
}

inline BOOL esos_uiF14_isLED3Off (void) {
    return (_st_esos_uiF14Data.b_LED3On);
}

inline void esos_uiF14_turnLED3On (void) {
    //LED3 is low active
    _st_esos_uiF14Data.b_LED3On = TRUE;
    return;
}

inline void esos_uiF14_turnLED3Off (void) {
    _st_esos_uiF14Data.b_LED3On = FALSE;
    return;
}

inline void esos_uiF14_toggleLED3 (void) {
    _st_esos_uiF14Data.b_LED3On ^= 1;
    return;
}

inline void esos_uiF14_flashLED3( uint16_t u16_period3) {
	//Choose a reasonable minimum period
	if (u16_period3 < MINIMUM_LED_FLASH_PERIOD) {
		u16_period3 = MINIMUM_LED_FLASH_PERIOD;
	} 
    _st_esos_uiF14Data.u16_LED3FlashPeriod = u16_period3;
    return
}

inline uint16_t esos_uiF14_getLED3Period(void) {
	return _st_esos_uiF14Data.u16_LED3FlashPeriod;
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

inline int16_t esos_uiF14_getRPGCounter_i16 ( void ) {
    return _st_esos_uiF14Data.i16_RPGCounter;
}

inline BOOL esos_uiF14_isRPGTurning ( void ) {
    return !(_st_esos_uiF14Data.b_RPGNotMoving);
}

inline BOOL esos_uiF14_isRPGTurningSlow( void ) {
	return _st_esos_uiF14Data.b_RPGSlow;
}

inline BOOL esos_uiF14_isRPGTurningMedium( void ) {
	return _st_esos_uiF14Data.b_RPGMedium;
}

inline BOOL esos_uiF14_isRPGTurningFast( void ) {
	return _st_esos_uiF14Data.b_RPGFast;
}

inline BOOL esos_uiF14_isRPGTurningCW( void ) {
	return _st_esos_uiF14Data.b_RPGCW;
}

inline BOOL esos_uiF14_isRPGTurningCCW( void ) {
	return _st_esos_uiF14Data.b_RPGCCW;
}

inline uint16_t esos_uiF14_getRPGPeriod( void ) {
	return _st_esos_uiF14Data.u16_RPGPeriodMs;
}

// UIF14 INITIALIZATION FUNCTION

void config_esos_uiF14() {
	
    _st_esos_uiF14Data.b_SW1Pressed = FALSE;
    _st_esos_uiF14Data.b_SW1DoublePressed = FALSE;
    _st_esos_uiF14Data.b_SW2Pressed = FALSE;
    _st_esos_uiF14Data.b_SW2DoublePressed = FALSE;    
    _st_esos_uiF14Data.b_SW3Pressed = FALSE;
    _st_esos_uiF14Data.b_SW3DoublePressed = FALSE;
	_st_esos_uiF14Data.u16_doublePressUpperMs = 250;
    
    _st_esos_uiF14Data.b_RPGALast;  // compared to current RPGA, used to detect rotation
	_st_esos_uiF14Data.b_RPGFast = FALSE;
	_st_esos_uiF14Data.b_RPGMedium = FALSE;
	_st_esos_uiF14Data.b_RPGSlow = FALSE;
	_st_esos_uiF14Data.b_RPGNotMoving = TRUE;
	_st_esos_uiF14Data.u16_RPGLastChangeMs = 0;  //time of last RPGA change
	_st_esos_uiF14Data.u16_RPGPeriodMs = 0;      // time SINCE last RPGA change
	_st_esos_uiF14Data.u16_RPGNotMovingToSlowPeriodMs = 300;  //border between not moving and slow
	_st_esos_uiF14Data.u16_RPGSlowToMediumPeriodMs = 200;
	_st_esos_uiF14Data.u16_RPGMediumToFastPeriodMs = 100;
	_st_esos_uiF14Data.b_RPGCW = FALSE;
    _st_esos_uiF14Data.b_RPGCCW = FALSE;
	_st_esos_uiF14Data.i16_RPGCounter = 0;      // notice signed int for couting CCW from start
    _st_esos_uiF14Data.i16_lastRPGCounter = 0;
	_st_esos_uiF14Data.b_RPGCWRev = FALSE;
	_st_esos_uiF14Data.b_RPGCCWRev = FALSE;
	
    _st_esos_uiF14Data.b_LED1On = FALSE;
    _st_esos_uiF14Data.b_LED1Flashing = FALSE;
    _st_esos_uiF14Data.u16_LED1FlashPeriod = FALSE; 
      
    _st_esos_uiF14Data.b_LED2On = FALSE;
    _st_esos_uiF14Data.b_LED2Flashing = FALSE;
    _st_esos_uiF14Data.u16_LED2FlashPeriod = FALSE;   
     
    _st_esos_uiF14Data.b_LED3On = FALSE;
    _st_esos_uiF14Data.b_LED3Flashing = FALSE;
    _st_esos_uiF14Data.u16_LED3FlashPeriod = FALSE;

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
  static LED1_counter = 0;
  static LED2_counter = 0;
  static LED3_counter = 0;

  // init to -1 to disable counters by default
  static SW1_doublepress_counter = -1;
  static SW2_doublepress_counter = -1;
  static SW3_doublepress_counter = -1;

  ESOS_TASK_BEGIN();
  while(TRUE) {

	//-------- LED Initial States
	// LED1 (Red) 
	LED1 = _st_esos_uiF14Data.b_LED1On;

	// LED2 (Yellow) 
	LED2 = _st_esos_uiF14Data.b_LED2On;

	// LED3 (Green)    
	LED3 = _st_esos_uiF14Data.b_LED3On;


	//-------- LED flashing ---------
	// For some reason the lab stipulates that the flashing functionality
	// be defined WHOLLY in this task, hence the ugly stuff which follows.
	// This operates on the assumption that this ESOS task is called
	// approximately every 10 ms

	//LEDs should not flash when their flashing period is 0
	if (esos_uiF14_getLED1Period() == 0) {
		LED1_counter = 0;
	} else if (LED1_counter < esos_uiF14_getLED1Period() / 2) { //Count up to half period
		LED1_counter += __ESOS_UIF14_UI_PERIOD_MS;
	} else if (LED1_counter > esos_uiF14_getLED1Period() / 2) { //Toggle when greater than half period
		esos_uiF14_toggleLED1();
		LED1_counter = 0;
	}

	if (esos_uiF14_getLED2Period() == 0) {
		LED2_counter = 0;
	} else if (LED2_counter < esos_uiF14_getLED2Period() /2) {
		LED2_counter += __ESOS_UIF14_UI_PERIOD_MS;
	} else if (LED2_counter > esos_uiF14_getLED2Period() / 2) {
		esos_uiF14_toggleLED2();
		LED2_counter = 0;
	}

	if (esos_uiF14_getLED3Period() == 0) {
		LED3_counter = 0;
	} else if (LED3_counter < esos_uiF14_getLED3Period() / 2) {
		LED3_counter += __ESOS_UIF14_UI_PERIOD_MS;
	} else if (LED3_counter > esos_uiF14_getLED3Period() / 2) {
		esos_uiF14_toggleLED3();
		LED3_counter = 0;
	}

	/* SWITCH STATE LOGIC */
	if (SW1_PRESSED || SW1_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {
		if (SW1_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {						
			SW1_doublepress_counter = -1;		// Counter expired, no double press event, disable counter
			_st_esos_uiF14Data.b_SW1DoublePressed = FALSE;
			_st_esos_uiF14Data.b_SW1Pressed = TRUE;
		// Switch was pressed while counter was running and not expired
		} else if (SW1_doublepress_counter < _st_esos_uiF14Data.u16_doublePressUpperMs && SW1_doublepress_counter != -1) {
			_st_esos_uiF14Data.b_SW1DoublePressed = TRUE;
			_st_esos_uiF14Data.b_SW1Pressed = FALSE;
		// Otherwise, the switch was pressed, start the timer
		} else {
			SW1_doublepress_counter = 0;		// Start the timer
		}
	}

	if (SW2_PRESSED || SW2_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {
		if (SW2_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {						
			SW2_doublepress_counter = -1;		// Counter expired, no double press event, disable counter
			_st_esos_uiF14Data.b_SW2DoublePressed = FALSE;
			_st_esos_uiF14Data.b_SW2Pressed = TRUE;
		// Switch was pressed while counter was running and not expired
		} else if (SW2_doublepress_counter < _st_esos_uiF14Data.u16_doublePressUpperMs && SW2_doublepress_counter != -1) {
			_st_esos_uiF14Data.b_SW2DoublePressed = TRUE;
			_st_esos_uiF14Data.b_SW2Pressed = FALSE;
		// Otherwise, the switch was pressed, start the timer
		} else {
			SW2_doublepress_counter = 0;		// Start the timer
		}
	}

	if (SW3_PRESSED || SW3_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {
		if (SW3_doublepress_counter >= _st_esos_uiF14Data.u16_doublePressUpperMs) {						
			SW3_doublepress_counter = -1;		// Counter expired, no double press event, disable counter
			_st_esos_uiF14Data.b_SW3DoublePressed = FALSE;
			_st_esos_uiF14Data.b_SW3Pressed = TRUE;
		// Switch was pressed while counter was running and not expired
		} else if (SW3_doublepress_counter < _st_esos_uiF14Data.u16_doublePressUpperMs && SW3_doublepress_counter != -1) {
			_st_esos_uiF14Data.b_SW3DoublePressed = TRUE;
			_st_esos_uiF14Data.b_SW3Pressed = FALSE;
		// Otherwise, the switch was pressed, start the timer
		} else {
			SW3_doublepress_counter = 0;		// Start the timer
		}
	}

	/* SWITCH COUNTER LOGIC */
	if (SW1_doublepress_counter != -1) {SW1_doublepress_counter++}
	if (SW2_doublepress_counter != -1) {SW2_doublepress_counter++}
	if (SW3_doublepress_counter != -1) {SW3_doublepress_counter++}
	
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
