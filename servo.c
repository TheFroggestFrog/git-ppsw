#include <LPC21xx.H>
#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"

#define detector_bm (1<<10)

enum ServoState {CALIB, IDLE, IN_PROGRESS};
struct Servo {
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
}; 
struct Servo sServo;

enum eDetectorState {INACTIVE , ACTIVE};
enum eDetectorState eDetectorRead() {
	if( (IO0PIN & detector_bm) == 0) {
		return ACTIVE;
	}
	else {
		return INACTIVE;
	}
}

void ServoAutomat(){
	
	switch(sServo.eState) {
			case CALIB:
				if(eDetectorRead() == ACTIVE) {
					sServo.uiCurrentPosition = 0;
					sServo.uiDesiredPosition = 0;
					sServo.eState = IDLE;
				}
				else {
					LedStepLeft();		//zgodnie z zegarem dopytac o to prowadzacego
				}
				break;
				
			case IDLE:
				if(sServo.uiCurrentPosition != sServo.uiDesiredPosition) {
					sServo.eState = IN_PROGRESS;
				}
				break;
				
			case IN_PROGRESS:
				if(sServo.uiCurrentPosition < sServo.uiDesiredPosition) {
					sServo.uiCurrentPosition++;
					LedStepRight();			//przeciwnie do zegara
				}
				else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition) {
					sServo.uiCurrentPosition--;
					LedStepLeft();
				}
				else {
					sServo.eState = IDLE;
				}
				break;			
		}
}

void ServoInit(unsigned int uiServoFrequency) {
	LedInit();
	IO0DIR &= ~detector_bm;		//DetectorInit
	sServo.eState = CALIB;
	Timer0Interrupts_Init((1000000 / uiServoFrequency), &ServoAutomat);
}

void ServoCalib() {
	sServo.eState = CALIB;
}

void ServoGoTo(unsigned int uiPosition) {
	sServo.uiDesiredPosition = uiPosition;
}
