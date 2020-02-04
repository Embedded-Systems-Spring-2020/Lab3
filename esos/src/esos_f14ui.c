/*******************************************************************
 * 
 * C code framework for ESOS user-interface (UI) service
 * 
 *    requires the EMBEDDED SYSTEMS target rev. F14
 * 
 * ****************************************************************/
# include <esos_f14ui.h>
# include <revF14.h>

#define DOUBLE_PRESS_LOWER_BOUND_MS 120
#define DOUBLE_PRESS_UPPER_BOUND_MS 300

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
	return (_st_esos_uiF14Data.b_LED1On==TRUE);
}

inline BOOL esos_uiF14_isLED1Off (void) {
	return (_st_esos_uiF14Data.b_LED1On==FALSE);
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

inline uint16_t esos_uiF14_getRpgValue_u16 ( void ) {
	return _st_esos_uiF14Data.u16_RPGCounter;
}

inline BOOL esos_uiF14_isRpgTurning ( void ) {
	return (esos_uiF14_getRpgVelocity_i16() != 0);
}

inline BOOL esos_uiF14_isRpgTurningSlow( void ) {
  // not yet implemented
}

inline BOOL esos_uiF14_isRpgTurningMedium( void ) {
  // not yet implemented
}

inline BOOL esos_uiF14_isRpgTurningFast( void ) {
  // not yet implemented
}

inline BOOL esos_uiF14_isRpgTurningCW( void ) {
  // not yet implemented
}

inline BOOL esos_uiF14_isRpgTurningCCW( void ) {
  // not yet implemented
}

int16_t esos_uiF14_getRpgVelocity_i16( void ) {
  // not yet implemented
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

  //TODO


  esos_RegisterTask( __uiF14_task );
}


ESOS_USER_TIMER()

// UIF14 task to manage user-interface
ESOS_USER_TASK( __esos_uiF14_task ){
  
  ESOS_TASK_BEGIN();
  while(TRUE) {
 
    // idea:
	// Press button once: clear SW1DoublePressed if it's already TRUE
	// else, start a timer to enable set a user flag signaling that we should
	// look out for another press after DOUBLE_PRESS_LOWER_BOUND_MS and a second timer
	// to disable that flag after DOUBLE_PRESS_UPPER_BOUND_MS.
	// During that period, check for a second press on every tickand set DoublePressed to TRUE
	// if detected
    
	// Switch 1 
	_st_esos_uiF14Data.b_SW1Pressed = SW1_PRESSED;
	_st_esos_uiF14Data.b_SW1DoublePressed;

	// Switch 2 
	_st_esos_uiF14Data.b_SW2Pressed = SW2_PRESSED;
	//_st_esos_uiF14Data.b_SW2DoublePressed;    

	// Switch 3 
	_st_esos_uiF14Data.b_SW3Pressed = SW3_PRESSED;
	//_st_esos_uiF14Data.b_SW3DoublePressed;    
	
	//_st_esos_uiF14Data.b_RPGAHigh;
	//_st_esos_uiF14Data.b_RPGBHigh;
	
	// LED1 (Red) 
	LED1 = _st_esos_uiF14Data.b_LED1On;
	//_st_esos_uiF14Data.u16_LED1FlashPeriod;    

	// LED2 (Yellow) 
	LED2 = _st_esos_uiF14Data.b_LED2On;
	//_st_esos_uiF14Data.u16_LED2FlashPeriod;    

	// LED3 (Green)    
	LED3 = _st_esos_uiF14Data.b_LED3On;
	//_st_esos_uiF14Data.u16_LED3FlashPeriod;        
	
	//_st_esos_uiF14Data.u16_RPGCounter;
	//_st_esos_uiF14Data.u16_lastRPGCounter;


	ESOS_TASK_WAIT_TICKS( __ESOS_UIF14_UI_PERIOD );
  }
  ESOS_TASK_END();
}
