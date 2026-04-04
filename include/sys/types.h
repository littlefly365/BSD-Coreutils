#ifndef SYS_NB_TYPES_H
#define SYS_NB_TYPES_H

#include_next <sys/types.h>

typedef unsigned int u_int;
typedef unsigned char u_char;
typedef unsigned long u_long;

typedef int32_t __devmajor_t, __devminor_t;
#define devmajor_t __devmajor_t
#define devminor_t __devminor_t
#define NODEVMAJOR (-1)
#define major(x)        ((devmajor_t)(((uint32_t)(x) & 0x000fff00) >>  8))
#define minor(x)        ((devminor_t)((((uint32_t)(x) & 0xfff00000) >> 12) | \
                                   (((uint32_t)(x) & 0x000000ff) >>  0)))
#endif
