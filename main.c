#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

int main (){
	ServoInit(10);
	
	while(1){
		switch(eKeyboardRead()) {
			case BUTTON_0:
				ServoCalib();
			break;
			
			case BUTTON_1:
				ServoGoTo(12);
			break;
			
			case BUTTON_2:
				ServoGoTo(24);
			break;
			
			case BUTTON_3:
				ServoGoTo(36);
			break;
			
			case RELEASED:
			break;
		}
	}
}
