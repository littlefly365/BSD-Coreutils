#ifndef _COMPAT_H
#define _COMPAT_H

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <grp.h>

#include <sys/vfs.h>
#include <sys/types.h>
#include <sys/acl.h>

int compat_mkostemp(char *path, int oflags);
int compat_mkstemp(char *path);
char *compat_mkdtemp(char *path);

#define fcpxattr
#define setproctitle             
#define  O_EXLOCK  	0

#ifndef REG_STARTEND
#define REG_STARTEND  0x0080
#endif
#ifndef NL_TEXTMAX
#define NL_TEXTMAX          2048
#endif

#ifndef sigmask
#define sigmask(x) (1 << ((x)-1))
#endif

#ifndef S_BLKSIZE
#define S_BLKSIZE 512
#endif

static inline const char *
getbsize(int *h, long *b)
{
    (void)h;
    if (b) *b = 512;
    return "512";
}


static inline long
lpathconf(const char *path, int name)
{
    (void)path;
    (void)name;
    return -1;
}

#define _PC_ACL_EXTENDED	0
#define ACL_TYPE_NFS4		0
#define _PC_ACL_NFS4		0

typedef struct __acl_ext *acl_t;

static inline acl_t
acl_get_link_np(const char *path, acl_type_t type)
{
    (void)path;
    (void)type;
    return NULL;
}

static inline int
acl_set_link_np(const char *path, acl_type_t type, acl_t name)
{
    (void)path;
    (void)type;
    (void)name;
    return 0;
}

static inline acl_t
acl_get_fd_np(int type, int name)
{
    (void)type;
    (void)name;
    return 0;
}

static inline acl_t
acl_set_fd_np(int path, acl_t acl, int name)
{
    (void)path;
    (void)acl;
    (void)name;
    return NULL;
}

static inline int
acl_is_trivial_np(acl_t acl, int *trivial)
{
    (void)acl;
    if (trivial)
        *trivial = 1;
    return 0;
}

#define st_flags st_mode

#ifndef AT_FDCWD
#define     AT_FDCWD                -100
#endif

#ifndef NODEV
#define NODEV ((dev_t)-1)
#endif

#ifndef _EXT
#define _EXT(fp) ((struct __sfileext *)(void *)((fp)->_ext._base))
#endif
static int debug;

// fstypes.h
#define     MNT_LOCAL       0x00001000
#define      MNT_RDONLY      0x00000001

// fnmatch.h
#ifndef FNM_CASEFOLD
#define      FNM_CASEFOLD    0x08
#endif

int signalnumber(const char *name);
int signalnext(int sig);

#define	F_MAXFD		11

#endif
