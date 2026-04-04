#ifndef NB_TERMIOS_H
#define NB_TERMIOS_H

#include_next <termios.h>

#define	TTLINEDNAMELEN	32
typedef char linedn_t[TTLINEDNAMELEN];

#define CDTRCTS		0
#define ALTWERASE VWERASE
#define TIOCGLINED TIOCGWINSZ
#define TIOCGQSIZE FIONREAD

#endif
