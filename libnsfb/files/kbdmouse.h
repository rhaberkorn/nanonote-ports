/*
 *
 * Keyboard Mouse Emulation Config
 *
 */

#include "keyboard.c"

#define KBDMOUSE_TOGGLE			NNKEY_QI

#define KBDMOUSE_LEFT_CLICK		NNKEY_VOLUMEDOWN
#define KBDMOUSE_RIGHT_CLICK		NNKEY_VOLUMEUP

#define KBDMOUSE_UP			NNKEY_UP
#define KBDMOUSE_DOWN			NNKEY_DOWN
#define KBDMOUSE_LEFT			NNKEY_LEFT
#define KBDMOUSE_RIGHT			NNKEY_RIGHT

#define KBDMOUSE_QUIT_HACK		NNKEY_ESCAPE

#define KBDMOUSE_STEP			5

#define KBDMOUSE_REPEAT_DELAY		SDL_DEFAULT_REPEAT_DELAY
#define KBDMOUSE_REPEAT_INTERVAL	(SDL_DEFAULT_REPEAT_INTERVAL/2)