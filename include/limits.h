#ifndef _NB_LIMITS_H
#define _NB_LIMITS_H

#include <stdint.h>
#include_next <limits.h>

#define SIZE_T_MAX SIZE_MAX
#ifndef __GLIBC__
#define NL_TEXTMAX 2048
#endif
#endif
