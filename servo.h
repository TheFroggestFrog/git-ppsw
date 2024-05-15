#ifndef SERVO_H
#define SERVO_H

void ServoInit(unsigned int uiServoFrequency);
void ServoCalib(void);
void ServoGoTo(unsigned int uiPosition);

#endif
