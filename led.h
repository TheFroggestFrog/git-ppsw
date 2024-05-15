#ifndef LED_H
#define LED_H

enum LedStepDirection {LEFT, RIGHT};

void LedInit(void);
void LedStepLeft(void);
void LedStepRight(void);
void LedOn(unsigned char ucLedIndex);

#endif
