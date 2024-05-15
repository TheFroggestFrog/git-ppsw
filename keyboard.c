#include <LPC21xx.H>
#include "keyboard.h"

#define S0_bm (1<<4)
#define S1_bm (1<<6)	//Buttons S1 and S2 are swapped on pcb
#define S2_bm (1<<5)
#define S3_bm (1<<7)

void KeyboardInit() {
	IO0DIR &= ~(S0_bm | S1_bm | S2_bm | S3_bm);
}

enum eButtonState eKeyboardRead() {	
	if ( (IO0PIN & S0_bm) == 0) {		//buttons have a pullup, hence ~IO0PIN
		return(BUTTON_0);
	}
	else if( (IO0PIN & S1_bm) == 0) {
		return (BUTTON_1);
	}
	else if( (IO0PIN & S2_bm) == 0) {
		return (BUTTON_2);
	}
	else if( (IO0PIN & S3_bm) == 0) {
		return (BUTTON_3);
	}	
	else {
		return(RELEASED);
	}
}
