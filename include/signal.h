#ifndef _NB_SIGNALS_H
#define _NB_SIGNALS_H

#include_next <signal.h>

#define signalname	strsignal
#define sys_nsig	NSIG

int signalnumber(const char *name);
int signalnext(int sig);

#endif
