/*
	keyboard.c

	Contains defines for every 
	key on the Ben NanoNote.

	Data collected and compiled 
	by xdpirate of #qi-hardware
	on irc.freenode.net
*/

/* Function keys */
#define NNKEY_F1 282
#define NNKEY_F2 283
#define NNKEY_F3 284
#define NNKEY_F4 285
#define NNKEY_F5 286
#define NNKEY_F6 287
#define NNKEY_F7 288
#define NNKEY_F8 289

/* First (top) keyboard row */
#define NNKEY_Q 113
#define NNKEY_W 119
#define NNKEY_E 101
#define NNKEY_R 114
#define NNKEY_T 116
#define NNKEY_Y 121
#define NNKEY_U 117
#define NNKEY_I 105
#define NNKEY_O 111
#define NNKEY_P 112

/* Second keyboard row */
#define NNKEY_A 97
#define NNKEY_S 115
#define NNKEY_D 100
#define NNKEY_F 102
#define NNKEY_G 103
#define NNKEY_H 104
#define NNKEY_J 106
#define NNKEY_K 107
#define NNKEY_L 108
#define NNKEY_BACKSPACE 8

/* Third keyboard row */
#define NNKEY_ESCAPE 27
#define NNKEY_Z 122
#define NNKEY_X 120
#define NNKEY_C 99
#define NNKEY_V 118
#define NNKEY_B 98
#define NNKEY_N 110
#define NNKEY_M 109
#define NNKEY_EQUALS 61
#define NNKEY_ENTER 13  // Enter and Return are very often used interchangeably, so since there's
#define NNKEY_RETURN 13 // only one Enter key on the NN, they're both defined to the same key

/* Fourth keyboard row, not including arrows/volume */
#define NNKEY_TAB 9
#define NNKEY_CAPSLOCK 301 // Same key, two constants
#define NNKEY_CAPS 301     // for simplicity
#define NNKEY_BACKSLASH 92 
#define NNKEY_APOSTROPHE 180
#define NNKEY_COMMA 44
#define NNKEY_PERIOD 46
#define NNKEY_SLASH 47

/* Fifth (bottom) keyboard row, not including arrows/volume */
#define NNKEY_SHIFT 304
#define NNKEY_ALT 308
#define NNKEY_FUNCTION 306 // Same
#define NNKEY_FN 306       // key
#define NNKEY_RED 307   // Same
#define NNKEY_ALTGR 307 // key
#define NNKEY_SPACE 32
#define NNKEY_QI 0 // Yes, the Qi-button actually returns 0!
#define NNKEY_CTRL 305    // Same
#define NNKEY_CONTROL 305 // key

/* Arrow keys and Volume keys */
#define NNKEY_UP 273
#define NNKEY_DOWN 274
#define NNKEY_LEFT 276
#define NNKEY_RIGHT 275
#define NNKEY_VOLUP 292
#define NNKEY_VOLUMEUP 292
#define NNKEY_VOLDOWN 293
#define NNKEY_VOLUMEDOWN 293

#define NNKEY_POWER 0 // NOTE: This key is only here for completeness' sake,
                      // the NanoNote will automatically turn off after
                      // pressing this key. It shares a key code with the 
                      // Qi-button (Line 77).
