#ifndef KEYBOARD_H
#define KEYBOARD_H

enum eButtonState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

void KeyboardInit(void);
enum eButtonState eKeyboardRead(void);

#endif
