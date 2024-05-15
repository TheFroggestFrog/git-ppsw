#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_RESET_bm (1<<1)
#define COUNTER_ENABLE_bm (1<<0)
#define INTERRUPT_ON_MR0 (1<<0)
#define RESET_ON_MR0 (1<<1)
#define MR0_INTERRUPT (1<<0)


void InitTimer0Match0(unsigned int uiDelayTime) {
	T0MCR = (T0MCR | INTERRUPT_ON_MR0 | RESET_ON_MR0);
	T0MR0 = (15 * uiDelayTime);
	T0TCR = T0TCR | COUNTER_RESET_bm;
	T0TCR = T0TCR & ~(COUNTER_RESET_bm);
	T0TCR = T0TCR | COUNTER_ENABLE_bm;
}

void WaitOnTimer0Match0(void) {
	while((T0IR & MR0_INTERRUPT) == 0) {
	}
	T0IR = MR0_INTERRUPT;
}
